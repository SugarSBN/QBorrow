
// Generated from /Users/subonan/subonan_THU/QDirty/src/grammar/QDirty.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "QDirtyParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by QDirtyParser.
 */
class  QDirtyListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(QDirtyParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(QDirtyParser::ProgramContext *ctx) = 0;

  virtual void enterStatement(QDirtyParser::StatementContext *ctx) = 0;
  virtual void exitStatement(QDirtyParser::StatementContext *ctx) = 0;

  virtual void enterRegister(QDirtyParser::RegisterContext *ctx) = 0;
  virtual void exitRegister(QDirtyParser::RegisterContext *ctx) = 0;

  virtual void enterExpr(QDirtyParser::ExprContext *ctx) = 0;
  virtual void exitExpr(QDirtyParser::ExprContext *ctx) = 0;

  virtual void enterTerm(QDirtyParser::TermContext *ctx) = 0;
  virtual void exitTerm(QDirtyParser::TermContext *ctx) = 0;

  virtual void enterFactor(QDirtyParser::FactorContext *ctx) = 0;
  virtual void exitFactor(QDirtyParser::FactorContext *ctx) = 0;


};

