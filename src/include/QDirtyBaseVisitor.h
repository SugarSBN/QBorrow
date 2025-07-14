
// Generated from /Users/subonan/subonan_THU/QDirty/src/grammar/QDirty.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "QDirtyVisitor.h"


/**
 * This class provides an empty implementation of QDirtyVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  QDirtyBaseVisitor : public QDirtyVisitor {
public:

  virtual std::any visitProgram(QDirtyParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(QDirtyParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRegister(QDirtyParser::RegisterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(QDirtyParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTerm(QDirtyParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor(QDirtyParser::FactorContext *ctx) override {
    return visitChildren(ctx);
  }


};

