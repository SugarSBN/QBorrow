
// Generated from /Users/subonan/subonan_THU/QDirty/src/grammar/QBorrow.g4 by ANTLR 4.13.2


#include "QBorrowListener.h"
#include "QBorrowVisitor.h"

#include "QBorrowParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct QBorrowParserStaticData final {
  QBorrowParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  QBorrowParserStaticData(const QBorrowParserStaticData&) = delete;
  QBorrowParserStaticData(QBorrowParserStaticData&&) = delete;
  QBorrowParserStaticData& operator=(const QBorrowParserStaticData&) = delete;
  QBorrowParserStaticData& operator=(QBorrowParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag qborrowParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<QBorrowParserStaticData> qborrowParserStaticData = nullptr;

void qborrowParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (qborrowParserStaticData != nullptr) {
    return;
  }
#else
  assert(qborrowParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<QBorrowParserStaticData>(
    std::vector<std::string>{
      "program", "statement", "expr", "term", "factor"
    },
    std::vector<std::string>{
      "", "'let'", "'='", "';'", "'borrow'", "'['", "']'", "'('", "')'", 
      "'+'", "'-'", "'*'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "ADD", "SUB", "MUL", "ID", "NUMBER", 
      "WS", "LINE_COMMENT", "BLOCK_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,16,72,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,1,0,4,0,12,8,0,11,0,
  	12,0,13,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,3,1,32,8,1,1,2,1,2,1,2,1,2,1,2,1,2,3,2,40,8,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,5,2,48,8,2,10,2,12,2,51,9,2,1,3,1,3,1,3,1,3,1,3,1,3,5,3,59,8,3,10,3,
  	12,3,62,9,3,1,4,1,4,1,4,1,4,1,4,1,4,3,4,70,8,4,1,4,0,2,4,6,5,0,2,4,6,
  	8,0,0,76,0,11,1,0,0,0,2,31,1,0,0,0,4,39,1,0,0,0,6,52,1,0,0,0,8,69,1,0,
  	0,0,10,12,3,2,1,0,11,10,1,0,0,0,12,13,1,0,0,0,13,11,1,0,0,0,13,14,1,0,
  	0,0,14,1,1,0,0,0,15,16,5,1,0,0,16,17,5,12,0,0,17,18,5,2,0,0,18,19,3,4,
  	2,0,19,20,5,3,0,0,20,32,1,0,0,0,21,22,5,4,0,0,22,23,5,12,0,0,23,32,5,
  	3,0,0,24,25,5,4,0,0,25,26,5,12,0,0,26,27,5,5,0,0,27,28,3,4,2,0,28,29,
  	5,6,0,0,29,30,5,3,0,0,30,32,1,0,0,0,31,15,1,0,0,0,31,21,1,0,0,0,31,24,
  	1,0,0,0,32,3,1,0,0,0,33,34,6,2,-1,0,34,35,5,10,0,0,35,40,3,6,3,0,36,37,
  	5,9,0,0,37,40,3,6,3,0,38,40,3,6,3,0,39,33,1,0,0,0,39,36,1,0,0,0,39,38,
  	1,0,0,0,40,49,1,0,0,0,41,42,10,5,0,0,42,43,5,9,0,0,43,48,3,6,3,0,44,45,
  	10,4,0,0,45,46,5,10,0,0,46,48,3,6,3,0,47,41,1,0,0,0,47,44,1,0,0,0,48,
  	51,1,0,0,0,49,47,1,0,0,0,49,50,1,0,0,0,50,5,1,0,0,0,51,49,1,0,0,0,52,
  	53,6,3,-1,0,53,54,3,8,4,0,54,60,1,0,0,0,55,56,10,2,0,0,56,57,5,11,0,0,
  	57,59,3,8,4,0,58,55,1,0,0,0,59,62,1,0,0,0,60,58,1,0,0,0,60,61,1,0,0,0,
  	61,7,1,0,0,0,62,60,1,0,0,0,63,70,5,13,0,0,64,70,5,12,0,0,65,66,5,7,0,
  	0,66,67,3,4,2,0,67,68,5,8,0,0,68,70,1,0,0,0,69,63,1,0,0,0,69,64,1,0,0,
  	0,69,65,1,0,0,0,70,9,1,0,0,0,7,13,31,39,47,49,60,69
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  qborrowParserStaticData = std::move(staticData);
}

}

QBorrowParser::QBorrowParser(TokenStream *input) : QBorrowParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

QBorrowParser::QBorrowParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  QBorrowParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *qborrowParserStaticData->atn, qborrowParserStaticData->decisionToDFA, qborrowParserStaticData->sharedContextCache, options);
}

QBorrowParser::~QBorrowParser() {
  delete _interpreter;
}

const atn::ATN& QBorrowParser::getATN() const {
  return *qborrowParserStaticData->atn;
}

std::string QBorrowParser::getGrammarFileName() const {
  return "QBorrow.g4";
}

const std::vector<std::string>& QBorrowParser::getRuleNames() const {
  return qborrowParserStaticData->ruleNames;
}

const dfa::Vocabulary& QBorrowParser::getVocabulary() const {
  return qborrowParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView QBorrowParser::getSerializedATN() const {
  return qborrowParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

QBorrowParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<QBorrowParser::StatementContext *> QBorrowParser::ProgramContext::statement() {
  return getRuleContexts<QBorrowParser::StatementContext>();
}

QBorrowParser::StatementContext* QBorrowParser::ProgramContext::statement(size_t i) {
  return getRuleContext<QBorrowParser::StatementContext>(i);
}


size_t QBorrowParser::ProgramContext::getRuleIndex() const {
  return QBorrowParser::RuleProgram;
}

void QBorrowParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QBorrowListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void QBorrowParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QBorrowListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any QBorrowParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QBorrowVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

QBorrowParser::ProgramContext* QBorrowParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, QBorrowParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(11); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(10);
      statement();
      setState(13); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == QBorrowParser::T__0

    || _la == QBorrowParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

QBorrowParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QBorrowParser::StatementContext::ID() {
  return getToken(QBorrowParser::ID, 0);
}

QBorrowParser::ExprContext* QBorrowParser::StatementContext::expr() {
  return getRuleContext<QBorrowParser::ExprContext>(0);
}


size_t QBorrowParser::StatementContext::getRuleIndex() const {
  return QBorrowParser::RuleStatement;
}

void QBorrowParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QBorrowListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void QBorrowParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QBorrowListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any QBorrowParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QBorrowVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

QBorrowParser::StatementContext* QBorrowParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, QBorrowParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(31);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(15);
      match(QBorrowParser::T__0);
      setState(16);
      match(QBorrowParser::ID);
      setState(17);
      match(QBorrowParser::T__1);
      setState(18);
      expr(0);
      setState(19);
      match(QBorrowParser::T__2);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(21);
      match(QBorrowParser::T__3);
      setState(22);
      match(QBorrowParser::ID);
      setState(23);
      match(QBorrowParser::T__2);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(24);
      match(QBorrowParser::T__3);
      setState(25);
      match(QBorrowParser::ID);
      setState(26);
      match(QBorrowParser::T__4);
      setState(27);
      expr(0);
      setState(28);
      match(QBorrowParser::T__5);
      setState(29);
      match(QBorrowParser::T__2);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

QBorrowParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QBorrowParser::ExprContext::SUB() {
  return getToken(QBorrowParser::SUB, 0);
}

QBorrowParser::TermContext* QBorrowParser::ExprContext::term() {
  return getRuleContext<QBorrowParser::TermContext>(0);
}

tree::TerminalNode* QBorrowParser::ExprContext::ADD() {
  return getToken(QBorrowParser::ADD, 0);
}

QBorrowParser::ExprContext* QBorrowParser::ExprContext::expr() {
  return getRuleContext<QBorrowParser::ExprContext>(0);
}


size_t QBorrowParser::ExprContext::getRuleIndex() const {
  return QBorrowParser::RuleExpr;
}

void QBorrowParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QBorrowListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void QBorrowParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QBorrowListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


std::any QBorrowParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QBorrowVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


QBorrowParser::ExprContext* QBorrowParser::expr() {
   return expr(0);
}

QBorrowParser::ExprContext* QBorrowParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  QBorrowParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  QBorrowParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, QBorrowParser::RuleExpr, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(39);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QBorrowParser::SUB: {
        setState(34);
        match(QBorrowParser::SUB);
        setState(35);
        term(0);
        break;
      }

      case QBorrowParser::ADD: {
        setState(36);
        match(QBorrowParser::ADD);
        setState(37);
        term(0);
        break;
      }

      case QBorrowParser::T__6:
      case QBorrowParser::ID:
      case QBorrowParser::NUMBER: {
        setState(38);
        term(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(49);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(47);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(41);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(42);
          match(QBorrowParser::ADD);
          setState(43);
          term(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(44);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(45);
          match(QBorrowParser::SUB);
          setState(46);
          term(0);
          break;
        }

        default:
          break;
        } 
      }
      setState(51);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

QBorrowParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QBorrowParser::FactorContext* QBorrowParser::TermContext::factor() {
  return getRuleContext<QBorrowParser::FactorContext>(0);
}

QBorrowParser::TermContext* QBorrowParser::TermContext::term() {
  return getRuleContext<QBorrowParser::TermContext>(0);
}

tree::TerminalNode* QBorrowParser::TermContext::MUL() {
  return getToken(QBorrowParser::MUL, 0);
}


size_t QBorrowParser::TermContext::getRuleIndex() const {
  return QBorrowParser::RuleTerm;
}

void QBorrowParser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QBorrowListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void QBorrowParser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QBorrowListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


std::any QBorrowParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QBorrowVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}


QBorrowParser::TermContext* QBorrowParser::term() {
   return term(0);
}

QBorrowParser::TermContext* QBorrowParser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  QBorrowParser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  QBorrowParser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, QBorrowParser::RuleTerm, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(53);
    factor();
    _ctx->stop = _input->LT(-1);
    setState(60);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(55);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(56);
        match(QBorrowParser::MUL);
        setState(57);
        factor(); 
      }
      setState(62);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

QBorrowParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QBorrowParser::FactorContext::NUMBER() {
  return getToken(QBorrowParser::NUMBER, 0);
}

tree::TerminalNode* QBorrowParser::FactorContext::ID() {
  return getToken(QBorrowParser::ID, 0);
}

QBorrowParser::ExprContext* QBorrowParser::FactorContext::expr() {
  return getRuleContext<QBorrowParser::ExprContext>(0);
}


size_t QBorrowParser::FactorContext::getRuleIndex() const {
  return QBorrowParser::RuleFactor;
}

void QBorrowParser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QBorrowListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void QBorrowParser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QBorrowListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}


std::any QBorrowParser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QBorrowVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

QBorrowParser::FactorContext* QBorrowParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 8, QBorrowParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(69);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QBorrowParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(63);
        match(QBorrowParser::NUMBER);
        break;
      }

      case QBorrowParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(64);
        match(QBorrowParser::ID);
        break;
      }

      case QBorrowParser::T__6: {
        enterOuterAlt(_localctx, 3);
        setState(65);
        match(QBorrowParser::T__6);
        setState(66);
        expr(0);
        setState(67);
        match(QBorrowParser::T__7);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool QBorrowParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);
    case 3: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool QBorrowParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 5);
    case 1: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

bool QBorrowParser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void QBorrowParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  qborrowParserInitialize();
#else
  ::antlr4::internal::call_once(qborrowParserOnceFlag, qborrowParserInitialize);
#endif
}
