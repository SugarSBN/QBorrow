
// Generated from /Users/subonan/subonan_THU/QBorrow/grammar/QBorrow.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "QBorrowParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by QBorrowParser.
 */
class  QBorrowVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by QBorrowParser.
   */
    virtual std::any visitProgram(QBorrowParser::ProgramContext *context) = 0;

    virtual std::any visitStatement(QBorrowParser::StatementContext *context) = 0;

    virtual std::any visitFunction(QBorrowParser::FunctionContext *context) = 0;

    virtual std::any visitReg(QBorrowParser::RegContext *context) = 0;

    virtual std::any visitExpr(QBorrowParser::ExprContext *context) = 0;

    virtual std::any visitTerm(QBorrowParser::TermContext *context) = 0;

    virtual std::any visitFactor(QBorrowParser::FactorContext *context) = 0;


};

