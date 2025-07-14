
#pragma once

#include <exception> // for std::exception_ptr
#include "antlr4-runtime.h"

// 根据你提供的语法生成的头文件
#include "AST.h"
#include "QDirtyLexer.h"
#include "QDirtyParser.h"
#include "QDirtyBaseListener.h"


class Custom_Error_Listener : public antlr4 :: BaseErrorListener {

public:

    explicit Custom_Error_Listener(std :: ostream& error_stream)
        : error_output_(error_stream), 
        error_occurred_(false) {}

    void syntaxError(antlr4 :: Recognizer* recognizer,
                     antlr4 :: Token* offendingSymbol,
                     size_t line, size_t charPositionInLine,
                     const std :: string& msg,
                     std :: exception_ptr e) override;

    bool has_error() const;

private:
    std :: ostream& error_output_;

    bool error_occurred_;

};



class Parser {

public:
    /*
        constructor, taking an error output stream
    */
    explicit Parser(std :: ostream& error_output)
        : error_output_(error_output), custom_error_listener_(error_output) {}

    /*
        parse the input string
        returns true if parsing is successful, false otherwise
        automatically builds the parse tree
    */
    bool parse_string(const std :: string& input_string);

    /*
        get the parsed statements
    */
    std :: vector<std :: shared_ptr<Stmt> > get_statements() const;

private:

    /*
        build the parse tree, store results in statements_
    */
    void build_parse_tree(antlr4 :: tree :: ParseTree* tree);

    std :: ostream& error_output_;

    Custom_Error_Listener custom_error_listener_;

    /*
        parse results
    */
    std :: vector<std :: shared_ptr<Stmt> > statements_;


    /* 
        Visitors, in particular, visit_statements() store results in statements_
    */
    void visit_statements(const std :: vector<QDirtyParser :: StatementContext*>& stmts);
    
    std :: shared_ptr<Stmt> visit_statement(QDirtyParser :: StatementContext* ctx);

    std :: shared_ptr<Expr> visit_expr(QDirtyParser :: ExprContext* ctx);
    std :: shared_ptr<Expr> visit_term(QDirtyParser :: TermContext* ctx);
    std :: shared_ptr<Expr> visit_factor(QDirtyParser :: FactorContext* ctx);
};

