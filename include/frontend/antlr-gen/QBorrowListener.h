
// Generated from /Users/subonan/subonan_THU/QBorrow-1/grammar/QBorrow.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "QBorrowParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by QBorrowParser.
 */
class  QBorrowListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(QBorrowParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(QBorrowParser::ProgramContext *ctx) = 0;

  virtual void enterStatement(QBorrowParser::StatementContext *ctx) = 0;
  virtual void exitStatement(QBorrowParser::StatementContext *ctx) = 0;

  virtual void enterReg(QBorrowParser::RegContext *ctx) = 0;
  virtual void exitReg(QBorrowParser::RegContext *ctx) = 0;

  virtual void enterExpr(QBorrowParser::ExprContext *ctx) = 0;
  virtual void exitExpr(QBorrowParser::ExprContext *ctx) = 0;

  virtual void enterTerm(QBorrowParser::TermContext *ctx) = 0;
  virtual void exitTerm(QBorrowParser::TermContext *ctx) = 0;

  virtual void enterFactor(QBorrowParser::FactorContext *ctx) = 0;
  virtual void exitFactor(QBorrowParser::FactorContext *ctx) = 0;


};

