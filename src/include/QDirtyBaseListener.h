
// Generated from /Users/subonan/subonan_THU/QDirty/src/grammar/QDirty.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "QDirtyListener.h"


/**
 * This class provides an empty implementation of QDirtyListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  QDirtyBaseListener : public QDirtyListener {
public:

  virtual void enterProgram(QDirtyParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(QDirtyParser::ProgramContext * /*ctx*/) override { }

  virtual void enterStatement(QDirtyParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(QDirtyParser::StatementContext * /*ctx*/) override { }

  virtual void enterRegister(QDirtyParser::RegisterContext * /*ctx*/) override { }
  virtual void exitRegister(QDirtyParser::RegisterContext * /*ctx*/) override { }

  virtual void enterExpr(QDirtyParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(QDirtyParser::ExprContext * /*ctx*/) override { }

  virtual void enterTerm(QDirtyParser::TermContext * /*ctx*/) override { }
  virtual void exitTerm(QDirtyParser::TermContext * /*ctx*/) override { }

  virtual void enterFactor(QDirtyParser::FactorContext * /*ctx*/) override { }
  virtual void exitFactor(QDirtyParser::FactorContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

