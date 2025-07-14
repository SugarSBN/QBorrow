
// Generated from /Users/subonan/subonan_THU/antlr-playground/dirty/src/grammar/QDirty.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "QDirtyParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by QDirtyParser.
 */
class  QDirtyVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by QDirtyParser.
   */
    virtual std::any visitProgram(QDirtyParser::ProgramContext *context) = 0;

    virtual std::any visitStatement(QDirtyParser::StatementContext *context) = 0;

    virtual std::any visitRegister(QDirtyParser::RegisterContext *context) = 0;

    virtual std::any visitExpr(QDirtyParser::ExprContext *context) = 0;

    virtual std::any visitTerm(QDirtyParser::TermContext *context) = 0;

    virtual std::any visitFactor(QDirtyParser::FactorContext *context) = 0;


};

