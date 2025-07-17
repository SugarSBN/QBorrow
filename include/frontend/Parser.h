
#pragma once

#include <exception> // for std::exception_ptr
#include "antlr4-runtime.h"

#include "Program.h"
#include "QBorrowLexer.h"
#include "QBorrowParser.h"
#include "QBorrowBaseListener.h"


class Custom_Error_Listener : public antlr4::BaseErrorListener {

public:

    explicit Custom_Error_Listener(std::ostream& error_stream)
        : error_output_(error_stream), 
        error_occurred_(false) {}

    void syntaxError(antlr4::Recognizer* recognizer,
                     antlr4::Token* offendingSymbol,
                     size_t line, size_t charPositionInLine,
                     const std::string& msg,
                     std::exception_ptr e) override;

    bool has_error() const;

private:
    std::ostream& error_output_;

    bool error_occurred_;

};



class Parser {

public:
    /*
        factory method
    */
    static std::shared_ptr<Parser> make_parser(std::ostream& error_output);

    /*
        parse the input string
        returns true if parsing is successful, false otherwise
        automatically builds the parse tree
    */
    bool parse_string(const std::string& input_string);

    /*
        get the parsed functions and statements
    */
    const std::shared_ptr<Program>& get_program() const;

private:

    /*
        constructor
    */
    explicit Parser(std::ostream& error_output);

    /*
        build the parse tree, store results in statements_
    */
    void build_parse_tree(antlr4::tree::ParseTree* tree);

    std::ostream& error_output_;

    Custom_Error_Listener custom_error_listener_;

    /*
        parse results
    */
    std::shared_ptr<Program> program_;


    /* 
        Visitors
    */

    std::vector<std::shared_ptr<Stmt> > visit_statements(const std::vector<QBorrowParser::StatementContext*>& stmts);
    
    std::shared_ptr<Stmt> visit_statement(QBorrowParser::StatementContext* ctx);

    std::shared_ptr<Register> visit_register(QBorrowParser::RegContext* ctx);

    std::shared_ptr<Expr> visit_expr(QBorrowParser::ExprContext* ctx);
    std::shared_ptr<Expr> visit_term(QBorrowParser::TermContext* ctx);
    std::shared_ptr<Expr> visit_factor(QBorrowParser::FactorContext* ctx);
};

