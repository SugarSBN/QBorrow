
// Generated from /Users/subonan/subonan_THU/QBorrow/src/grammar/QBorrow.g4 by ANTLR 4.13.2


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
      "program", "statement", "reg", "expr", "term", "factor"
    },
    std::vector<std::string>{
      "", "'let'", "'='", "';'", "'borrow'", "'alloc'", "'X'", "'['", "']'", 
      "'CNOT'", "','", "'CCNOT'", "'for'", "'to'", "'{'", "'}'", "'('", 
      "')'", "'+'", "'-'", "'*'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "ADD", "SUB", "MUL", "ID", "NUMBER", "WS", "LINE_COMMENT", "BLOCK_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,25,118,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,1,0,4,0,14,
  	8,0,11,0,12,0,15,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,1,64,
  	8,1,11,1,12,1,65,1,1,1,1,3,1,70,8,1,1,2,1,2,1,2,1,2,1,2,1,2,3,2,78,8,
  	2,1,3,1,3,1,3,1,3,1,3,1,3,3,3,86,8,3,1,3,1,3,1,3,1,3,1,3,1,3,5,3,94,8,
  	3,10,3,12,3,97,9,3,1,4,1,4,1,4,1,4,1,4,1,4,5,4,105,8,4,10,4,12,4,108,
  	9,4,1,5,1,5,1,5,1,5,1,5,1,5,3,5,116,8,5,1,5,0,2,6,8,6,0,2,4,6,8,10,0,
  	0,127,0,13,1,0,0,0,2,69,1,0,0,0,4,77,1,0,0,0,6,85,1,0,0,0,8,98,1,0,0,
  	0,10,115,1,0,0,0,12,14,3,2,1,0,13,12,1,0,0,0,14,15,1,0,0,0,15,13,1,0,
  	0,0,15,16,1,0,0,0,16,1,1,0,0,0,17,18,5,1,0,0,18,19,5,21,0,0,19,20,5,2,
  	0,0,20,21,3,6,3,0,21,22,5,3,0,0,22,70,1,0,0,0,23,24,5,4,0,0,24,25,3,4,
  	2,0,25,26,5,3,0,0,26,70,1,0,0,0,27,28,5,5,0,0,28,29,3,4,2,0,29,30,5,3,
  	0,0,30,70,1,0,0,0,31,32,5,6,0,0,32,33,5,7,0,0,33,34,3,4,2,0,34,35,5,8,
  	0,0,35,36,5,3,0,0,36,70,1,0,0,0,37,38,5,9,0,0,38,39,5,7,0,0,39,40,3,4,
  	2,0,40,41,5,10,0,0,41,42,3,4,2,0,42,43,5,8,0,0,43,44,5,3,0,0,44,70,1,
  	0,0,0,45,46,5,11,0,0,46,47,5,7,0,0,47,48,3,4,2,0,48,49,5,10,0,0,49,50,
  	3,4,2,0,50,51,5,10,0,0,51,52,3,4,2,0,52,53,5,8,0,0,53,54,5,3,0,0,54,70,
  	1,0,0,0,55,56,5,12,0,0,56,57,5,21,0,0,57,58,5,2,0,0,58,59,3,6,3,0,59,
  	60,5,13,0,0,60,61,3,6,3,0,61,63,5,14,0,0,62,64,3,2,1,0,63,62,1,0,0,0,
  	64,65,1,0,0,0,65,63,1,0,0,0,65,66,1,0,0,0,66,67,1,0,0,0,67,68,5,15,0,
  	0,68,70,1,0,0,0,69,17,1,0,0,0,69,23,1,0,0,0,69,27,1,0,0,0,69,31,1,0,0,
  	0,69,37,1,0,0,0,69,45,1,0,0,0,69,55,1,0,0,0,70,3,1,0,0,0,71,72,5,21,0,
  	0,72,73,5,7,0,0,73,74,3,6,3,0,74,75,5,8,0,0,75,78,1,0,0,0,76,78,5,21,
  	0,0,77,71,1,0,0,0,77,76,1,0,0,0,78,5,1,0,0,0,79,80,6,3,-1,0,80,81,5,19,
  	0,0,81,86,3,8,4,0,82,83,5,18,0,0,83,86,3,8,4,0,84,86,3,8,4,0,85,79,1,
  	0,0,0,85,82,1,0,0,0,85,84,1,0,0,0,86,95,1,0,0,0,87,88,10,5,0,0,88,89,
  	5,18,0,0,89,94,3,8,4,0,90,91,10,4,0,0,91,92,5,19,0,0,92,94,3,8,4,0,93,
  	87,1,0,0,0,93,90,1,0,0,0,94,97,1,0,0,0,95,93,1,0,0,0,95,96,1,0,0,0,96,
  	7,1,0,0,0,97,95,1,0,0,0,98,99,6,4,-1,0,99,100,3,10,5,0,100,106,1,0,0,
  	0,101,102,10,2,0,0,102,103,5,20,0,0,103,105,3,10,5,0,104,101,1,0,0,0,
  	105,108,1,0,0,0,106,104,1,0,0,0,106,107,1,0,0,0,107,9,1,0,0,0,108,106,
  	1,0,0,0,109,116,5,22,0,0,110,116,5,21,0,0,111,112,5,16,0,0,112,113,3,
  	6,3,0,113,114,5,17,0,0,114,116,1,0,0,0,115,109,1,0,0,0,115,110,1,0,0,
  	0,115,111,1,0,0,0,116,11,1,0,0,0,9,15,65,69,77,85,93,95,106,115
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
      ((1ULL << _la) & 6770) != 0));
   
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

std::vector<QBorrowParser::ExprContext *> QBorrowParser::StatementContext::expr() {
  return getRuleContexts<QBorrowParser::ExprContext>();
}

QBorrowParser::ExprContext* QBorrowParser::StatementContext::expr(size_t i) {
  return getRuleContext<QBorrowParser::ExprContext>(i);
}

std::vector<QBorrowParser::RegContext *> QBorrowParser::StatementContext::reg() {
  return getRuleContexts<QBorrowParser::RegContext>();
}

QBorrowParser::RegContext* QBorrowParser::StatementContext::reg(size_t i) {
  return getRuleContext<QBorrowParser::RegContext>(i);
}

std::vector<QBorrowParser::StatementContext *> QBorrowParser::StatementContext::statement() {
  return getRuleContexts<QBorrowParser::StatementContext>();
}

QBorrowParser::StatementContext* QBorrowParser::StatementContext::statement(size_t i) {
  return getRuleContext<QBorrowParser::StatementContext>(i);
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
  size_t _la = 0;

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
      case QBorrowParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(17);
        match(QBorrowParser::T__0);
        setState(18);
        match(QBorrowParser::ID);
        setState(19);
        match(QBorrowParser::T__1);
        setState(20);
        expr(0);
        setState(21);
        match(QBorrowParser::T__2);
        break;
      }

      case QBorrowParser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(23);
        match(QBorrowParser::T__3);
        setState(24);
        reg();
        setState(25);
        match(QBorrowParser::T__2);
        break;
      }

      case QBorrowParser::T__4: {
        enterOuterAlt(_localctx, 3);
        setState(27);
        match(QBorrowParser::T__4);
        setState(28);
        reg();
        setState(29);
        match(QBorrowParser::T__2);
        break;
      }

      case QBorrowParser::T__5: {
        enterOuterAlt(_localctx, 4);
        setState(31);
        match(QBorrowParser::T__5);
        setState(32);
        match(QBorrowParser::T__6);
        setState(33);
        reg();
        setState(34);
        match(QBorrowParser::T__7);
        setState(35);
        match(QBorrowParser::T__2);
        break;
      }

      case QBorrowParser::T__8: {
        enterOuterAlt(_localctx, 5);
        setState(37);
        match(QBorrowParser::T__8);
        setState(38);
        match(QBorrowParser::T__6);
        setState(39);
        reg();
        setState(40);
        match(QBorrowParser::T__9);
        setState(41);
        reg();
        setState(42);
        match(QBorrowParser::T__7);
        setState(43);
        match(QBorrowParser::T__2);
        break;
      }

      case QBorrowParser::T__10: {
        enterOuterAlt(_localctx, 6);
        setState(45);
        match(QBorrowParser::T__10);
        setState(46);
        match(QBorrowParser::T__6);
        setState(47);
        reg();
        setState(48);
        match(QBorrowParser::T__9);
        setState(49);
        reg();
        setState(50);
        match(QBorrowParser::T__9);
        setState(51);
        reg();
        setState(52);
        match(QBorrowParser::T__7);
        setState(53);
        match(QBorrowParser::T__2);
        break;
      }

      case QBorrowParser::T__11: {
        enterOuterAlt(_localctx, 7);
        setState(55);
        match(QBorrowParser::T__11);
        setState(56);
        match(QBorrowParser::ID);
        setState(57);
        match(QBorrowParser::T__1);
        setState(58);
        expr(0);
        setState(59);
        match(QBorrowParser::T__12);
        setState(60);
        expr(0);
        setState(61);
        match(QBorrowParser::T__13);
        setState(63); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(62);
          statement();
          setState(65); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 6770) != 0));
        setState(67);
        match(QBorrowParser::T__14);
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

//----------------- RegContext ------------------------------------------------------------------

QBorrowParser::RegContext::RegContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QBorrowParser::RegContext::ID() {
  return getToken(QBorrowParser::ID, 0);
}

QBorrowParser::ExprContext* QBorrowParser::RegContext::expr() {
  return getRuleContext<QBorrowParser::ExprContext>(0);
}


size_t QBorrowParser::RegContext::getRuleIndex() const {
  return QBorrowParser::RuleReg;
}

void QBorrowParser::RegContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QBorrowListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReg(this);
}

void QBorrowParser::RegContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QBorrowListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReg(this);
}


std::any QBorrowParser::RegContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QBorrowVisitor*>(visitor))
    return parserVisitor->visitReg(this);
  else
    return visitor->visitChildren(this);
}

QBorrowParser::RegContext* QBorrowParser::reg() {
  RegContext *_localctx = _tracker.createInstance<RegContext>(_ctx, getState());
  enterRule(_localctx, 4, QBorrowParser::RuleReg);

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
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(71);
      match(QBorrowParser::ID);
      setState(72);
      match(QBorrowParser::T__6);
      setState(73);
      expr(0);
      setState(74);
      match(QBorrowParser::T__7);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(76);
      match(QBorrowParser::ID);
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
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, QBorrowParser::RuleExpr, precedence);

    

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
    setState(85);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QBorrowParser::SUB: {
        setState(80);
        match(QBorrowParser::SUB);
        setState(81);
        term(0);
        break;
      }

      case QBorrowParser::ADD: {
        setState(82);
        match(QBorrowParser::ADD);
        setState(83);
        term(0);
        break;
      }

      case QBorrowParser::T__15:
      case QBorrowParser::ID:
      case QBorrowParser::NUMBER: {
        setState(84);
        term(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(95);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(93);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(87);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(88);
          match(QBorrowParser::ADD);
          setState(89);
          term(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(90);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(91);
          match(QBorrowParser::SUB);
          setState(92);
          term(0);
          break;
        }

        default:
          break;
        } 
      }
      setState(97);
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
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, QBorrowParser::RuleTerm, precedence);

    

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
    setState(99);
    factor();
    _ctx->stop = _input->LT(-1);
    setState(106);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(101);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(102);
        match(QBorrowParser::MUL);
        setState(103);
        factor(); 
      }
      setState(108);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
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
  enterRule(_localctx, 10, QBorrowParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(115);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QBorrowParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(109);
        match(QBorrowParser::NUMBER);
        break;
      }

      case QBorrowParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(110);
        match(QBorrowParser::ID);
        break;
      }

      case QBorrowParser::T__15: {
        enterOuterAlt(_localctx, 3);
        setState(111);
        match(QBorrowParser::T__15);
        setState(112);
        expr(0);
        setState(113);
        match(QBorrowParser::T__16);
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
    case 3: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);
    case 4: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);

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
