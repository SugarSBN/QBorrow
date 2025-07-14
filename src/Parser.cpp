#include "Parser.h"
#include "AST.h"
#include "antlr4-runtime.h"

#define RED     "\033[1;31m"
#define RESET   "\033[0m"


void Custom_Error_Listener :: syntaxError(antlr4 :: Recognizer*,
                                        antlr4 :: Token* offendingSymbol,
                                        size_t line, size_t charPositionInLine,
                                        const std :: string& msg,
                                        std::exception_ptr /*e*/) {
    error_occurred_ = true;
    error_output_ << RED
                  << "[QBorrow Error] Lexical or syntax error at line " << line << ", column " << charPositionInLine << ": " << msg 
                  << RESET << std :: endl;

    if (offendingSymbol) {
        error_output_ << RED << "[QBorrow Error] Offending symbol: " << offendingSymbol -> getText() << std :: endl;
    }
}

bool Custom_Error_Listener :: has_error() const {
    return error_occurred_;
}






bool Parser :: parse_string(const std :: string& input_string) {

    antlr4 :: ANTLRInputStream input(input_string);
    QBorrowLexer lexer(&input);

    lexer.removeErrorListeners();
    lexer.addErrorListener(&custom_error_listener_);

    antlr4 :: CommonTokenStream tokens(&lexer);
    tokens.fill(); 

    if (custom_error_listener_.has_error()) {
        error_output_ << RED << "Lexing failed. Parsing aborted." << RESET << std :: endl;
        return false;
    }


    QBorrowParser parser(&tokens);
    parser.removeErrorListeners();
    parser.addErrorListener(&custom_error_listener_);

    try {
        // entry of *.g4 is named "program" 
        antlr4 :: tree :: ParseTree* tree = parser.program();

        if (custom_error_listener_.has_error()) 
            return false;

        build_parse_tree(tree);
        
        return true;

    } catch (const std :: exception& ex) {
        error_output_ << RED 
                      << "[QBorrow Error] Parse failed: " << ex.what() 
                      << RESET << std :: endl;
        return false;
    }

    return true;
}

std :: vector<std :: shared_ptr<Stmt> > Parser :: get_statements() const{
    return statements_;
}


void Parser :: build_parse_tree(antlr4 :: tree :: ParseTree* tree) {

    statements_.clear();
    if (tree == nullptr) return;

    auto* program_ctx = dynamic_cast<QBorrowParser :: ProgramContext*>(tree);
    if (!program_ctx || program_ctx -> statement().empty()) {
        throw std::runtime_error("Empty or invalid program.");
    }

    visit_statements(program_ctx -> statement());
}

void Parser :: visit_statements(const std::vector<QBorrowParser::StatementContext*>& stmts){

    for (auto* s : stmts) {

        statements_.push_back(visit_statement(s));
        
    }

    return;
}



std :: shared_ptr<Stmt> Parser :: visit_statement(QBorrowParser :: StatementContext* ctx) {

    if (ctx -> getStart() -> getText() == "let") {
        
        std :: string id = ctx -> ID() -> getText();
        auto expr = visit_expr(ctx -> expr());

        return Stmt :: make_let(id, expr);

    } else if (ctx -> getStart() -> getText() == "borrow") {

        std :: string id = ctx -> ID() -> getText();


        if (ctx -> expr() == nullptr) {

            return Stmt :: make_borrow(id, false, nullptr);

        } else {


            return Stmt :: make_borrow(id, true, visit_expr(ctx -> expr()));


        }

    } else if (ctx->getStart()->getText() == "alloc") {

        // return visit_borrow_alloc(ctx, /*is_alloc=*/true);

    }
    throw std::runtime_error("Unknown statement type");
}




std :: shared_ptr<Expr> Parser :: visit_expr(QBorrowParser :: ExprContext* ctx) {
    // binary operatior
    if (ctx -> expr() != nullptr && ctx -> term() != nullptr) {

        std :: shared_ptr<Expr> left = visit_expr(ctx -> expr()); 
        std :: shared_ptr<Expr> right = visit_term(ctx -> term());   

        if (ctx -> ADD() != nullptr) {

            return Expr :: make_binary_op(Expr :: Binary_Op :: ADD, left, right);

        } else 
        if (ctx -> SUB() != nullptr) {

            return Expr :: make_binary_op(Expr :: Binary_Op :: SUB, left, right);

        }
    }
    else 
    // unary operator
    if (ctx -> term() != nullptr && ctx -> expr() == nullptr) {

        std :: shared_ptr<Expr> operand = visit_term(ctx -> term());

        if (ctx -> SUB() != nullptr) {

            return Expr::make_unary_op(Expr::Unary_Op::NEGATE, operand);

        } else {

            return visit_term(ctx->term());
            
        }

    }

    return nullptr;
}


std :: shared_ptr<Expr> Parser :: visit_term(QBorrowParser :: TermContext* ctx) {
    if (ctx -> term()) {

        auto left = visit_term(ctx -> term());
        auto right = visit_factor(ctx -> factor());
        return Expr :: make_binary_op(Expr :: Binary_Op :: MUL, left, right);

    }
    return visit_factor(ctx -> factor());
}

std :: shared_ptr<Expr> Parser :: visit_factor(QBorrowParser :: FactorContext* ctx) {
    if (ctx -> NUMBER()) {

        return Expr :: make_number(std :: stoi(ctx -> NUMBER() -> getText()));

    } else if (ctx -> ID()) {

        return Expr :: make_variable(ctx -> ID() -> getText());

    } else if (ctx -> expr()) {

        return visit_expr(ctx -> expr());

    }
    throw std::runtime_error("Invalid factor");
}