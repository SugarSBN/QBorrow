
#pragma once

#include <exception> // for std::exception_ptr
#include "antlr4-runtime.h"

// 根据你提供的语法生成的头文件
#include "AST.h"
#include "QDirtyLexer.h"
#include "QDirtyParser.h"
#include "QDirtyBaseListener.h"

// 自定义错误监听器：在终端打印红色错误信息
class Custom_Error_Listener : public antlr4 :: BaseErrorListener {

public:
    explicit Custom_Error_Listener(std :: ostream& err_stream);

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



// 主解析器类
class Parser {

public:
    explicit Parser(std :: ostream& err_output);

    bool parse_string(const std :: string& input_string);

    /*
        get the parsed statements
    */
    std :: vector<std :: shared_ptr<Stmt> > get_statements() const;

private:
    void build_parse_tree(antlr4 :: tree :: ParseTree* tree);

    std :: ostream& error_output_;

    Custom_Error_Listener custom_error_listener_;

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

