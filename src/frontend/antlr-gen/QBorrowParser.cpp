
// Generated from /Users/subonan/subonan_THU/QBorrow/grammar/QBorrow.g4 by ANTLR 4.13.2


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
      "", "'let'", "'='", "';'", "'borrow'", "'borrow@'", "'alloc'", "'release'", 
      "'X'", "'['", "']'", "'CNOT'", "','", "'CCNOT'", "'for'", "'to'", 
      "'{'", "'}'", "'('", "')'", "'+'", "'-'", "'*'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "ADD", "SUB", "MUL", "ID", "NUMBER", "WS", "LINE_COMMENT", 
      "BLOCK_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,27,128,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,1,0,4,0,14,
  	8,0,11,0,12,0,15,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,73,8,1,10,1,12,1,76,9,1,1,1,1,1,3,1,80,
  	8,1,1,2,1,2,1,2,1,2,1,2,1,2,3,2,88,8,2,1,3,1,3,1,3,1,3,1,3,1,3,3,3,96,
  	8,3,1,3,1,3,1,3,1,3,1,3,1,3,5,3,104,8,3,10,3,12,3,107,9,3,1,4,1,4,1,4,
  	1,4,1,4,1,4,5,4,115,8,4,10,4,12,4,118,9,4,1,5,1,5,1,5,1,5,1,5,1,5,3,5,
  	126,8,5,1,5,0,2,6,8,6,0,2,4,6,8,10,0,0,139,0,13,1,0,0,0,2,79,1,0,0,0,
  	4,87,1,0,0,0,6,95,1,0,0,0,8,108,1,0,0,0,10,125,1,0,0,0,12,14,3,2,1,0,
  	13,12,1,0,0,0,14,15,1,0,0,0,15,13,1,0,0,0,15,16,1,0,0,0,16,17,1,0,0,0,
  	17,18,5,0,0,1,18,1,1,0,0,0,19,20,5,1,0,0,20,21,5,23,0,0,21,22,5,2,0,0,
  	22,23,3,6,3,0,23,24,5,3,0,0,24,80,1,0,0,0,25,26,5,4,0,0,26,27,3,4,2,0,
  	27,28,5,3,0,0,28,80,1,0,0,0,29,30,5,5,0,0,30,31,3,4,2,0,31,32,5,3,0,0,
  	32,80,1,0,0,0,33,34,5,6,0,0,34,35,3,4,2,0,35,36,5,3,0,0,36,80,1,0,0,0,
  	37,38,5,7,0,0,38,39,5,23,0,0,39,80,5,3,0,0,40,41,5,8,0,0,41,42,5,9,0,
  	0,42,43,3,4,2,0,43,44,5,10,0,0,44,45,5,3,0,0,45,80,1,0,0,0,46,47,5,11,
  	0,0,47,48,5,9,0,0,48,49,3,4,2,0,49,50,5,12,0,0,50,51,3,4,2,0,51,52,5,
  	10,0,0,52,53,5,3,0,0,53,80,1,0,0,0,54,55,5,13,0,0,55,56,5,9,0,0,56,57,
  	3,4,2,0,57,58,5,12,0,0,58,59,3,4,2,0,59,60,5,12,0,0,60,61,3,4,2,0,61,
  	62,5,10,0,0,62,63,5,3,0,0,63,80,1,0,0,0,64,65,5,14,0,0,65,66,5,23,0,0,
  	66,67,5,2,0,0,67,68,3,6,3,0,68,69,5,15,0,0,69,70,3,6,3,0,70,74,5,16,0,
  	0,71,73,3,2,1,0,72,71,1,0,0,0,73,76,1,0,0,0,74,72,1,0,0,0,74,75,1,0,0,
  	0,75,77,1,0,0,0,76,74,1,0,0,0,77,78,5,17,0,0,78,80,1,0,0,0,79,19,1,0,
  	0,0,79,25,1,0,0,0,79,29,1,0,0,0,79,33,1,0,0,0,79,37,1,0,0,0,79,40,1,0,
  	0,0,79,46,1,0,0,0,79,54,1,0,0,0,79,64,1,0,0,0,80,3,1,0,0,0,81,82,5,23,
  	0,0,82,83,5,9,0,0,83,84,3,6,3,0,84,85,5,10,0,0,85,88,1,0,0,0,86,88,5,
  	23,0,0,87,81,1,0,0,0,87,86,1,0,0,0,88,5,1,0,0,0,89,90,6,3,-1,0,90,91,
  	5,21,0,0,91,96,3,8,4,0,92,93,5,20,0,0,93,96,3,8,4,0,94,96,3,8,4,0,95,
  	89,1,0,0,0,95,92,1,0,0,0,95,94,1,0,0,0,96,105,1,0,0,0,97,98,10,5,0,0,
  	98,99,5,20,0,0,99,104,3,8,4,0,100,101,10,4,0,0,101,102,5,21,0,0,102,104,
  	3,8,4,0,103,97,1,0,0,0,103,100,1,0,0,0,104,107,1,0,0,0,105,103,1,0,0,
  	0,105,106,1,0,0,0,106,7,1,0,0,0,107,105,1,0,0,0,108,109,6,4,-1,0,109,
  	110,3,10,5,0,110,116,1,0,0,0,111,112,10,2,0,0,112,113,5,22,0,0,113,115,
  	3,10,5,0,114,111,1,0,0,0,115,118,1,0,0,0,116,114,1,0,0,0,116,117,1,0,
  	0,0,117,9,1,0,0,0,118,116,1,0,0,0,119,126,5,24,0,0,120,126,5,23,0,0,121,
  	122,5,18,0,0,122,123,3,6,3,0,123,124,5,19,0,0,124,126,1,0,0,0,125,119,
  	1,0,0,0,125,120,1,0,0,0,125,121,1,0,0,0,126,11,1,0,0,0,9,15,74,79,87,
  	95,103,105,116,125
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

tree::TerminalNode* QBorrowParser::ProgramContext::EOF() {
  return getToken(QBorrowParser::EOF, 0);
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
      ((1ULL << _la) & 27122) != 0));
    setState(17);
    match(QBorrowParser::EOF);
   
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
    setState(79);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QBorrowParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(19);
        match(QBorrowParser::T__0);
        setState(20);
        match(QBorrowParser::ID);
        setState(21);
        match(QBorrowParser::T__1);
        setState(22);
        expr(0);
        setState(23);
        match(QBorrowParser::T__2);
        break;
      }

      case QBorrowParser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(25);
        match(QBorrowParser::T__3);
        setState(26);
        reg();
        setState(27);
        match(QBorrowParser::T__2);
        break;
      }

      case QBorrowParser::T__4: {
        enterOuterAlt(_localctx, 3);
        setState(29);
        match(QBorrowParser::T__4);
        setState(30);
        reg();
        setState(31);
        match(QBorrowParser::T__2);
        break;
      }

      case QBorrowParser::T__5: {
        enterOuterAlt(_localctx, 4);
        setState(33);
        match(QBorrowParser::T__5);
        setState(34);
        reg();
        setState(35);
        match(QBorrowParser::T__2);
        break;
      }

      case QBorrowParser::T__6: {
        enterOuterAlt(_localctx, 5);
        setState(37);
        match(QBorrowParser::T__6);
        setState(38);
        match(QBorrowParser::ID);
        setState(39);
        match(QBorrowParser::T__2);
        break;
      }

      case QBorrowParser::T__7: {
        enterOuterAlt(_localctx, 6);
        setState(40);
        match(QBorrowParser::T__7);
        setState(41);
        match(QBorrowParser::T__8);
        setState(42);
        reg();
        setState(43);
        match(QBorrowParser::T__9);
        setState(44);
        match(QBorrowParser::T__2);
        break;
      }

      case QBorrowParser::T__10: {
        enterOuterAlt(_localctx, 7);
        setState(46);
        match(QBorrowParser::T__10);
        setState(47);
        match(QBorrowParser::T__8);
        setState(48);
        reg();
        setState(49);
        match(QBorrowParser::T__11);
        setState(50);
        reg();
        setState(51);
        match(QBorrowParser::T__9);
        setState(52);
        match(QBorrowParser::T__2);
        break;
      }

      case QBorrowParser::T__12: {
        enterOuterAlt(_localctx, 8);
        setState(54);
        match(QBorrowParser::T__12);
        setState(55);
        match(QBorrowParser::T__8);
        setState(56);
        reg();
        setState(57);
        match(QBorrowParser::T__11);
        setState(58);
        reg();
        setState(59);
        match(QBorrowParser::T__11);
        setState(60);
        reg();
        setState(61);
        match(QBorrowParser::T__9);
        setState(62);
        match(QBorrowParser::T__2);
        break;
      }

      case QBorrowParser::T__13: {
        enterOuterAlt(_localctx, 9);
        setState(64);
        match(QBorrowParser::T__13);
        setState(65);
        match(QBorrowParser::ID);
        setState(66);
        match(QBorrowParser::T__1);
        setState(67);
        expr(0);
        setState(68);
        match(QBorrowParser::T__14);
        setState(69);
        expr(0);
        setState(70);
        match(QBorrowParser::T__15);
        setState(74);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 27122) != 0)) {
          setState(71);
          statement();
          setState(76);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(77);
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
    setState(87);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(81);
      match(QBorrowParser::ID);
      setState(82);
      match(QBorrowParser::T__8);
      setState(83);
      expr(0);
      setState(84);
      match(QBorrowParser::T__9);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(86);
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
    setState(95);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QBorrowParser::SUB: {
        setState(90);
        match(QBorrowParser::SUB);
        setState(91);
        term(0);
        break;
      }

      case QBorrowParser::ADD: {
        setState(92);
        match(QBorrowParser::ADD);
        setState(93);
        term(0);
        break;
      }

      case QBorrowParser::T__17:
      case QBorrowParser::ID:
      case QBorrowParser::NUMBER: {
        setState(94);
        term(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(105);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(103);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(97);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(98);
          match(QBorrowParser::ADD);
          setState(99);
          term(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(100);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(101);
          match(QBorrowParser::SUB);
          setState(102);
          term(0);
          break;
        }

        default:
          break;
        } 
      }
      setState(107);
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
    setState(109);
    factor();
    _ctx->stop = _input->LT(-1);
    setState(116);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(111);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(112);
        match(QBorrowParser::MUL);
        setState(113);
        factor(); 
      }
      setState(118);
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
    setState(125);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QBorrowParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(119);
        match(QBorrowParser::NUMBER);
        break;
      }

      case QBorrowParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(120);
        match(QBorrowParser::ID);
        break;
      }

      case QBorrowParser::T__17: {
        enterOuterAlt(_localctx, 3);
        setState(121);
        match(QBorrowParser::T__17);
        setState(122);
        expr(0);
        setState(123);
        match(QBorrowParser::T__18);
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
