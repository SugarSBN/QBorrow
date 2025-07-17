
// Generated from /Users/subonan/subonan_THU/QBorrow-1/grammar/QBorrow.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "QBorrowListener.h"


/**
 * This class provides an empty implementation of QBorrowListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  QBorrowBaseListener : public QBorrowListener {
public:

  virtual void enterProgram(QBorrowParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(QBorrowParser::ProgramContext * /*ctx*/) override { }

  virtual void enterStatement(QBorrowParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(QBorrowParser::StatementContext * /*ctx*/) override { }

  virtual void enterReg(QBorrowParser::RegContext * /*ctx*/) override { }
  virtual void exitReg(QBorrowParser::RegContext * /*ctx*/) override { }

  virtual void enterExpr(QBorrowParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(QBorrowParser::ExprContext * /*ctx*/) override { }

  virtual void enterTerm(QBorrowParser::TermContext * /*ctx*/) override { }
  virtual void exitTerm(QBorrowParser::TermContext * /*ctx*/) override { }

  virtual void enterFactor(QBorrowParser::FactorContext * /*ctx*/) override { }
  virtual void exitFactor(QBorrowParser::FactorContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

