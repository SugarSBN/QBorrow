#include "Parser.h"
#include "antlr4-runtime.h"

#define RED     "\033[1;31m"
#define RESET   "\033[0m"


void Custom_Error_Listener::syntaxError(antlr4::Recognizer*,
                                        antlr4::Token* offendingSymbol,
                                        size_t line, size_t charPositionInLine,
                                        const std::string& msg,
                                        std::exception_ptr /*e*/) {
    error_occurred_ = true;
    error_output_ << RED
                  << "[QBorrow Error] Lexical or syntax error at line " << line << ", column " << charPositionInLine << ": " << msg 
                  << RESET << std::endl;

    if (offendingSymbol) {
        error_output_ << RED << "[QBorrow Error] Offending symbol: " << offendingSymbol -> getText() << std::endl;
    }
}

bool Custom_Error_Listener::has_error() const {
    return error_occurred_;
}


Parser::Parser(std::ostream& error_output) 
    : error_output_(error_output), custom_error_listener_(Custom_Error_Listener(error_output)) {
}

std::shared_ptr<Parser> Parser::make_parser(std::ostream& error_output) {
    return std::make_shared<Parser>(Parser(error_output));
}



bool Parser::parse_string(const std::string& input_string) {

    antlr4::ANTLRInputStream input(input_string);
    QBorrowLexer lexer(&input);

    lexer.removeErrorListeners();
    lexer.addErrorListener(&custom_error_listener_);

    antlr4::CommonTokenStream tokens(&lexer);
    tokens.fill(); 

    if (custom_error_listener_.has_error()) {
        error_output_ << RED << "Lexing failed. Parsing aborted." << RESET << std::endl;
        return false;
    }


    QBorrowParser parser(&tokens);
    parser.removeErrorListeners();
    parser.addErrorListener(&custom_error_listener_);

    try {
        // entry of *.g4 is named "program" 
        antlr4::tree::ParseTree* tree = parser.program();

        if (custom_error_listener_.has_error()) 
            return false;

        build_parse_tree(tree);
        
        return true;

    } catch (const std::exception& ex) {
        error_output_ << RED 
                      << "[Parse failed] " << ex.what() 
                      << RESET << std::endl;
        return false;
    }

    return true;
}

std::shared_ptr<Program> Parser::get_program() const {
    return program_;
}

void Parser::build_parse_tree(antlr4::tree::ParseTree* tree) {

    if (tree == nullptr) return;

    auto* program_ctx = dynamic_cast<QBorrowParser::ProgramContext*>(tree);
    if (!program_ctx || program_ctx -> statement().empty()) {
        throw std::runtime_error("Empty or invalid program.");
    }

    program_ = Program::make_program(visit_statements(program_ctx -> statement()));
}

std::vector<std::shared_ptr<Stmt> > Parser::visit_statements(const std::vector<QBorrowParser::StatementContext*>& stmts){
    std::vector<std::shared_ptr<Stmt> > results;

    for (auto* s : stmts) {

        results.push_back(visit_statement(s));
        
    }
    return results;
}



std::shared_ptr<Stmt> Parser::visit_statement(QBorrowParser::StatementContext* ctx) {

    int lineno = ctx -> start -> getLine();
    if (ctx -> getStart() -> getText() == "let") {
        
        std::string id = ctx -> ID() -> getText();
        auto expr = visit_expr(ctx -> expr(0));

        return Stmt::make_let(id, expr, lineno);

    } else if (ctx -> getStart() -> getText() == "borrow") {

       return Stmt::make_borrow(visit_register(ctx -> reg(0)), lineno);

    } else if (ctx->getStart()->getText() == "alloc") {

        return Stmt::make_alloc(visit_register(ctx -> reg(0)), lineno);

    } else if (ctx -> getStart() -> getText() == "release") {

        return Stmt::make_rel(ctx -> ID() -> getText(), lineno);

    } else if (ctx -> getStart() -> getText() == "X") {

        return Stmt::make_x(visit_register(ctx -> reg(0)), lineno);

    } else if (ctx -> getStart() -> getText() == "CNOT") {

        return Stmt::make_cnot(visit_register(ctx -> reg(0)), visit_register(ctx -> reg(1)), lineno);

    } else if (ctx -> getStart() -> getText() == "CCNOT") {

        return Stmt::make_ccnot(visit_register(ctx -> reg(0)), 
                                visit_register(ctx -> reg(1)), 
                                visit_register(ctx -> reg(2)),
                                lineno);

    } else if (ctx -> getStart() -> getText() == "for") {

        std::string id = ctx -> ID() -> getText();
        auto start = visit_expr(ctx -> expr(0));
        auto end = visit_expr(ctx -> expr(1));
        std::vector<std::shared_ptr<Stmt> > body = visit_statements(ctx -> statement());

        return Stmt::make_for(id, start, end, body, lineno);

    }

    throw std::runtime_error("Line " + std::to_string(lineno) + "Unknown statement type");
}


std::shared_ptr<Register> Parser::visit_register(QBorrowParser::RegContext* ctx) {
    return 
    ctx -> expr() == nullptr ? 
    Register::make_register(ctx -> ID() -> getText(), Expr::make_number(1)) :
    Register::make_register(ctx -> ID() -> getText(), visit_expr(ctx -> expr()));
}



std::shared_ptr<Expr> Parser::visit_expr(QBorrowParser::ExprContext* ctx) {
    
    if (ctx == nullptr) return nullptr;
    
    // binary operatior
    if (ctx -> expr() != nullptr && ctx -> term() != nullptr) {

        std::shared_ptr<Expr> left = visit_expr(ctx -> expr()); 
        std::shared_ptr<Expr> right = visit_term(ctx -> term());   

        if (ctx -> ADD() != nullptr) {

            return Expr::make_binary_op(Expr::Binary_Op::ADD, left, right);

        } else 
        if (ctx -> SUB() != nullptr) {

            return Expr::make_binary_op(Expr::Binary_Op::SUB, left, right);

        }
    }
    else 
    // unary operator
    if (ctx -> term() != nullptr && ctx -> expr() == nullptr) {

        std::shared_ptr<Expr> operand = visit_term(ctx -> term());

        if (ctx -> SUB() != nullptr) {

            return Expr::make_unary_op(Expr::Unary_Op::NEGATE, operand);

        } else {

            return visit_term(ctx->term());
            
        }

    }

    return nullptr;
}


std::shared_ptr<Expr> Parser::visit_term(QBorrowParser::TermContext* ctx) {
    if (ctx -> term()) {

        auto left = visit_term(ctx -> term());
        auto right = visit_factor(ctx -> factor());
        return Expr::make_binary_op(Expr::Binary_Op::MUL, left, right);

    }
    return visit_factor(ctx -> factor());
}

std::shared_ptr<Expr> Parser::visit_factor(QBorrowParser::FactorContext* ctx) {
    if (ctx -> NUMBER()) {

        return Expr::make_number(std::stoi(ctx -> NUMBER() -> getText()));

    } else if (ctx -> ID()) {

        return Expr::make_variable(ctx -> ID() -> getText());

    } else if (ctx -> expr()) {

        return visit_expr(ctx -> expr());

    }
}