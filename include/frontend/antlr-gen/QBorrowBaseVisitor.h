
// Generated from /Users/subonan/subonan_THU/QBorrow/grammar/QBorrow.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "QBorrowVisitor.h"


/**
 * This class provides an empty implementation of QBorrowVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  QBorrowBaseVisitor : public QBorrowVisitor {
public:

  virtual std::any visitProgram(QBorrowParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(QBorrowParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReg(QBorrowParser::RegContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(QBorrowParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTerm(QBorrowParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor(QBorrowParser::FactorContext *ctx) override {
    return visitChildren(ctx);
  }


};

