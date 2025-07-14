
// Generated from /Users/subonan/subonan_THU/antlr-playground/dirty/src/grammar/QDirty.g4 by ANTLR 4.13.2


#include "QDirtyListener.h"
#include "QDirtyVisitor.h"

#include "QDirtyParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct QDirtyParserStaticData final {
  QDirtyParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  QDirtyParserStaticData(const QDirtyParserStaticData&) = delete;
  QDirtyParserStaticData(QDirtyParserStaticData&&) = delete;
  QDirtyParserStaticData& operator=(const QDirtyParserStaticData&) = delete;
  QDirtyParserStaticData& operator=(QDirtyParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag qdirtyParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<QDirtyParserStaticData> qdirtyParserStaticData = nullptr;

void qdirtyParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (qdirtyParserStaticData != nullptr) {
    return;
  }
#else
  assert(qdirtyParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<QDirtyParserStaticData>(
    std::vector<std::string>{
      "program", "statement", "register", "expr", "term", "factor"
    },
    std::vector<std::string>{
      "", "'let'", "'='", "';'", "'borrow'", "'alloc'", "'['", "']'", "'('", 
      "')'", "'+'", "'-'", "'*'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "ADD", "SUB", "MUL", "ID", 
      "NUMBER", "WS", "LINE_COMMENT", "BLOCK_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,17,80,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,1,0,4,0,14,
  	8,0,11,0,12,0,15,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,3,1,32,8,1,1,2,1,2,1,2,1,2,1,2,1,2,3,2,40,8,2,1,3,1,3,1,3,1,3,1,3,
  	1,3,3,3,48,8,3,1,3,1,3,1,3,1,3,1,3,1,3,5,3,56,8,3,10,3,12,3,59,9,3,1,
  	4,1,4,1,4,1,4,1,4,1,4,5,4,67,8,4,10,4,12,4,70,9,4,1,5,1,5,1,5,1,5,1,5,
  	1,5,3,5,78,8,5,1,5,0,2,6,8,6,0,2,4,6,8,10,0,0,84,0,13,1,0,0,0,2,31,1,
  	0,0,0,4,39,1,0,0,0,6,47,1,0,0,0,8,60,1,0,0,0,10,77,1,0,0,0,12,14,3,2,
  	1,0,13,12,1,0,0,0,14,15,1,0,0,0,15,13,1,0,0,0,15,16,1,0,0,0,16,1,1,0,
  	0,0,17,18,5,1,0,0,18,19,5,13,0,0,19,20,5,2,0,0,20,21,3,6,3,0,21,22,5,
  	3,0,0,22,32,1,0,0,0,23,24,5,4,0,0,24,25,3,4,2,0,25,26,5,3,0,0,26,32,1,
  	0,0,0,27,28,5,5,0,0,28,29,3,4,2,0,29,30,5,3,0,0,30,32,1,0,0,0,31,17,1,
  	0,0,0,31,23,1,0,0,0,31,27,1,0,0,0,32,3,1,0,0,0,33,40,5,13,0,0,34,35,5,
  	13,0,0,35,36,5,6,0,0,36,37,3,6,3,0,37,38,5,7,0,0,38,40,1,0,0,0,39,33,
  	1,0,0,0,39,34,1,0,0,0,40,5,1,0,0,0,41,42,6,3,-1,0,42,43,5,11,0,0,43,48,
  	3,8,4,0,44,45,5,10,0,0,45,48,3,8,4,0,46,48,3,8,4,0,47,41,1,0,0,0,47,44,
  	1,0,0,0,47,46,1,0,0,0,48,57,1,0,0,0,49,50,10,5,0,0,50,51,5,10,0,0,51,
  	56,3,8,4,0,52,53,10,4,0,0,53,54,5,11,0,0,54,56,3,8,4,0,55,49,1,0,0,0,
  	55,52,1,0,0,0,56,59,1,0,0,0,57,55,1,0,0,0,57,58,1,0,0,0,58,7,1,0,0,0,
  	59,57,1,0,0,0,60,61,6,4,-1,0,61,62,3,10,5,0,62,68,1,0,0,0,63,64,10,2,
  	0,0,64,65,5,12,0,0,65,67,3,10,5,0,66,63,1,0,0,0,67,70,1,0,0,0,68,66,1,
  	0,0,0,68,69,1,0,0,0,69,9,1,0,0,0,70,68,1,0,0,0,71,78,5,14,0,0,72,78,5,
  	13,0,0,73,74,5,8,0,0,74,75,3,6,3,0,75,76,5,9,0,0,76,78,1,0,0,0,77,71,
  	1,0,0,0,77,72,1,0,0,0,77,73,1,0,0,0,78,11,1,0,0,0,8,15,31,39,47,55,57,
  	68,77
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  qdirtyParserStaticData = std::move(staticData);
}

}

QDirtyParser::QDirtyParser(TokenStream *input) : QDirtyParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

QDirtyParser::QDirtyParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  QDirtyParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *qdirtyParserStaticData->atn, qdirtyParserStaticData->decisionToDFA, qdirtyParserStaticData->sharedContextCache, options);
}

QDirtyParser::~QDirtyParser() {
  delete _interpreter;
}

const atn::ATN& QDirtyParser::getATN() const {
  return *qdirtyParserStaticData->atn;
}

std::string QDirtyParser::getGrammarFileName() const {
  return "QDirty.g4";
}

const std::vector<std::string>& QDirtyParser::getRuleNames() const {
  return qdirtyParserStaticData->ruleNames;
}

const dfa::Vocabulary& QDirtyParser::getVocabulary() const {
  return qdirtyParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView QDirtyParser::getSerializedATN() const {
  return qdirtyParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

QDirtyParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<QDirtyParser::StatementContext *> QDirtyParser::ProgramContext::statement() {
  return getRuleContexts<QDirtyParser::StatementContext>();
}

QDirtyParser::StatementContext* QDirtyParser::ProgramContext::statement(size_t i) {
  return getRuleContext<QDirtyParser::StatementContext>(i);
}


size_t QDirtyParser::ProgramContext::getRuleIndex() const {
  return QDirtyParser::RuleProgram;
}

void QDirtyParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QDirtyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void QDirtyParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QDirtyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any QDirtyParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QDirtyVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

QDirtyParser::ProgramContext* QDirtyParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, QDirtyParser::RuleProgram);
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
    setState(13); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(12);
      statement();
      setState(15); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 50) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

QDirtyParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QDirtyParser::StatementContext::ID() {
  return getToken(QDirtyParser::ID, 0);
}

QDirtyParser::ExprContext* QDirtyParser::StatementContext::expr() {
  return getRuleContext<QDirtyParser::ExprContext>(0);
}

QDirtyParser::RegisterContext* QDirtyParser::StatementContext::register_() {
  return getRuleContext<QDirtyParser::RegisterContext>(0);
}


size_t QDirtyParser::StatementContext::getRuleIndex() const {
  return QDirtyParser::RuleStatement;
}

void QDirtyParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QDirtyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void QDirtyParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QDirtyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any QDirtyParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QDirtyVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

QDirtyParser::StatementContext* QDirtyParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, QDirtyParser::RuleStatement);

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
    switch (_input->LA(1)) {
      case QDirtyParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(17);
        match(QDirtyParser::T__0);
        setState(18);
        match(QDirtyParser::ID);
        setState(19);
        match(QDirtyParser::T__1);
        setState(20);
        expr(0);
        setState(21);
        match(QDirtyParser::T__2);
        break;
      }

      case QDirtyParser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(23);
        match(QDirtyParser::T__3);
        setState(24);
        register_();
        setState(25);
        match(QDirtyParser::T__2);
        break;
      }

      case QDirtyParser::T__4: {
        enterOuterAlt(_localctx, 3);
        setState(27);
        match(QDirtyParser::T__4);
        setState(28);
        register_();
        setState(29);
        match(QDirtyParser::T__2);
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

//----------------- RegisterContext ------------------------------------------------------------------

QDirtyParser::RegisterContext::RegisterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QDirtyParser::RegisterContext::ID() {
  return getToken(QDirtyParser::ID, 0);
}

QDirtyParser::ExprContext* QDirtyParser::RegisterContext::expr() {
  return getRuleContext<QDirtyParser::ExprContext>(0);
}


size_t QDirtyParser::RegisterContext::getRuleIndex() const {
  return QDirtyParser::RuleRegister;
}

void QDirtyParser::RegisterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QDirtyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRegister(this);
}

void QDirtyParser::RegisterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QDirtyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRegister(this);
}


std::any QDirtyParser::RegisterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QDirtyVisitor*>(visitor))
    return parserVisitor->visitRegister(this);
  else
    return visitor->visitChildren(this);
}

QDirtyParser::RegisterContext* QDirtyParser::register_() {
  RegisterContext *_localctx = _tracker.createInstance<RegisterContext>(_ctx, getState());
  enterRule(_localctx, 4, QDirtyParser::RuleRegister);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(39);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(33);
      match(QDirtyParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(34);
      match(QDirtyParser::ID);
      setState(35);
      match(QDirtyParser::T__5);
      setState(36);
      expr(0);
      setState(37);
      match(QDirtyParser::T__6);
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

QDirtyParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QDirtyParser::ExprContext::SUB() {
  return getToken(QDirtyParser::SUB, 0);
}

QDirtyParser::TermContext* QDirtyParser::ExprContext::term() {
  return getRuleContext<QDirtyParser::TermContext>(0);
}

tree::TerminalNode* QDirtyParser::ExprContext::ADD() {
  return getToken(QDirtyParser::ADD, 0);
}

QDirtyParser::ExprContext* QDirtyParser::ExprContext::expr() {
  return getRuleContext<QDirtyParser::ExprContext>(0);
}


size_t QDirtyParser::ExprContext::getRuleIndex() const {
  return QDirtyParser::RuleExpr;
}

void QDirtyParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QDirtyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void QDirtyParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QDirtyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


std::any QDirtyParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QDirtyVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


QDirtyParser::ExprContext* QDirtyParser::expr() {
   return expr(0);
}

QDirtyParser::ExprContext* QDirtyParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  QDirtyParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  QDirtyParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, QDirtyParser::RuleExpr, precedence);

    

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
    setState(47);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QDirtyParser::SUB: {
        setState(42);
        match(QDirtyParser::SUB);
        setState(43);
        term(0);
        break;
      }

      case QDirtyParser::ADD: {
        setState(44);
        match(QDirtyParser::ADD);
        setState(45);
        term(0);
        break;
      }

      case QDirtyParser::T__7:
      case QDirtyParser::ID:
      case QDirtyParser::NUMBER: {
        setState(46);
        term(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(57);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(55);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(49);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(50);
          match(QDirtyParser::ADD);
          setState(51);
          term(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(52);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(53);
          match(QDirtyParser::SUB);
          setState(54);
          term(0);
          break;
        }

        default:
          break;
        } 
      }
      setState(59);
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

//----------------- TermContext ------------------------------------------------------------------

QDirtyParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QDirtyParser::FactorContext* QDirtyParser::TermContext::factor() {
  return getRuleContext<QDirtyParser::FactorContext>(0);
}

QDirtyParser::TermContext* QDirtyParser::TermContext::term() {
  return getRuleContext<QDirtyParser::TermContext>(0);
}

tree::TerminalNode* QDirtyParser::TermContext::MUL() {
  return getToken(QDirtyParser::MUL, 0);
}


size_t QDirtyParser::TermContext::getRuleIndex() const {
  return QDirtyParser::RuleTerm;
}

void QDirtyParser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QDirtyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void QDirtyParser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QDirtyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


std::any QDirtyParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QDirtyVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}


QDirtyParser::TermContext* QDirtyParser::term() {
   return term(0);
}

QDirtyParser::TermContext* QDirtyParser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  QDirtyParser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  QDirtyParser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, QDirtyParser::RuleTerm, precedence);

    

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
    setState(61);
    factor();
    _ctx->stop = _input->LT(-1);
    setState(68);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(63);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(64);
        match(QDirtyParser::MUL);
        setState(65);
        factor(); 
      }
      setState(70);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
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

QDirtyParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QDirtyParser::FactorContext::NUMBER() {
  return getToken(QDirtyParser::NUMBER, 0);
}

tree::TerminalNode* QDirtyParser::FactorContext::ID() {
  return getToken(QDirtyParser::ID, 0);
}

QDirtyParser::ExprContext* QDirtyParser::FactorContext::expr() {
  return getRuleContext<QDirtyParser::ExprContext>(0);
}


size_t QDirtyParser::FactorContext::getRuleIndex() const {
  return QDirtyParser::RuleFactor;
}

void QDirtyParser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QDirtyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void QDirtyParser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QDirtyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}


std::any QDirtyParser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QDirtyVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

QDirtyParser::FactorContext* QDirtyParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 10, QDirtyParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(77);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QDirtyParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(71);
        match(QDirtyParser::NUMBER);
        break;
      }

      case QDirtyParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(72);
        match(QDirtyParser::ID);
        break;
      }

      case QDirtyParser::T__7: {
        enterOuterAlt(_localctx, 3);
        setState(73);
        match(QDirtyParser::T__7);
        setState(74);
        expr(0);
        setState(75);
        match(QDirtyParser::T__8);
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

bool QDirtyParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 3: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);
    case 4: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool QDirtyParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 5);
    case 1: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

bool QDirtyParser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void QDirtyParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  qdirtyParserInitialize();
#else
  ::antlr4::internal::call_once(qdirtyParserOnceFlag, qdirtyParserInitialize);
#endif
}
