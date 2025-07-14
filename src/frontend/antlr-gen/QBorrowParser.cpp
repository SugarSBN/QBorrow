
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
      "program", "statement", "function", "reg", "expr", "term", "factor"
    },
    std::vector<std::string>{
      "", "'let'", "'='", "';'", "'borrow'", "'alloc'", "'release'", "'X'", 
      "'['", "']'", "'CNOT'", "','", "'CCNOT'", "'for'", "'to'", "'{'", 
      "'}'", "'call'", "'('", "')'", "'function'", "'+'", "'-'", "'*'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "ADD", "SUB", "MUL", "ID", "NUMBER", "WS", "LINE_COMMENT", 
      "BLOCK_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,28,192,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,1,
  	0,5,0,16,8,0,10,0,12,0,19,9,0,1,0,4,0,22,8,0,11,0,12,0,23,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,75,8,1,10,1,12,1,78,9,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,88,8,1,10,1,12,1,91,9,1,3,1,93,
  	8,1,1,1,1,1,1,1,1,1,1,1,5,1,100,8,1,10,1,12,1,103,9,1,3,1,105,8,1,1,1,
  	1,1,3,1,109,8,1,1,2,1,2,1,2,1,2,1,2,1,2,5,2,117,8,2,10,2,12,2,120,9,2,
  	3,2,122,8,2,1,2,1,2,1,2,1,2,1,2,5,2,129,8,2,10,2,12,2,132,9,2,3,2,134,
  	8,2,1,2,1,2,1,2,5,2,139,8,2,10,2,12,2,142,9,2,1,2,1,2,1,3,1,3,1,3,1,3,
  	1,3,1,3,3,3,152,8,3,1,4,1,4,1,4,1,4,1,4,1,4,3,4,160,8,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,5,4,168,8,4,10,4,12,4,171,9,4,1,5,1,5,1,5,1,5,1,5,1,5,5,5,179,
  	8,5,10,5,12,5,182,9,5,1,6,1,6,1,6,1,6,1,6,1,6,3,6,190,8,6,1,6,0,2,8,10,
  	7,0,2,4,6,8,10,12,0,0,212,0,17,1,0,0,0,2,108,1,0,0,0,4,110,1,0,0,0,6,
  	151,1,0,0,0,8,159,1,0,0,0,10,172,1,0,0,0,12,189,1,0,0,0,14,16,3,4,2,0,
  	15,14,1,0,0,0,16,19,1,0,0,0,17,15,1,0,0,0,17,18,1,0,0,0,18,21,1,0,0,0,
  	19,17,1,0,0,0,20,22,3,2,1,0,21,20,1,0,0,0,22,23,1,0,0,0,23,21,1,0,0,0,
  	23,24,1,0,0,0,24,1,1,0,0,0,25,26,5,1,0,0,26,27,5,24,0,0,27,28,5,2,0,0,
  	28,29,3,8,4,0,29,30,5,3,0,0,30,109,1,0,0,0,31,32,5,4,0,0,32,33,3,6,3,
  	0,33,34,5,3,0,0,34,109,1,0,0,0,35,36,5,5,0,0,36,37,3,6,3,0,37,38,5,3,
  	0,0,38,109,1,0,0,0,39,40,5,6,0,0,40,41,5,24,0,0,41,109,5,3,0,0,42,43,
  	5,7,0,0,43,44,5,8,0,0,44,45,3,6,3,0,45,46,5,9,0,0,46,47,5,3,0,0,47,109,
  	1,0,0,0,48,49,5,10,0,0,49,50,5,8,0,0,50,51,3,6,3,0,51,52,5,11,0,0,52,
  	53,3,6,3,0,53,54,5,9,0,0,54,55,5,3,0,0,55,109,1,0,0,0,56,57,5,12,0,0,
  	57,58,5,8,0,0,58,59,3,6,3,0,59,60,5,11,0,0,60,61,3,6,3,0,61,62,5,11,0,
  	0,62,63,3,6,3,0,63,64,5,9,0,0,64,65,5,3,0,0,65,109,1,0,0,0,66,67,5,13,
  	0,0,67,68,5,24,0,0,68,69,5,2,0,0,69,70,3,8,4,0,70,71,5,14,0,0,71,72,3,
  	8,4,0,72,76,5,15,0,0,73,75,3,2,1,0,74,73,1,0,0,0,75,78,1,0,0,0,76,74,
  	1,0,0,0,76,77,1,0,0,0,77,79,1,0,0,0,78,76,1,0,0,0,79,80,5,16,0,0,80,109,
  	1,0,0,0,81,82,5,17,0,0,82,83,5,24,0,0,83,92,5,18,0,0,84,89,3,8,4,0,85,
  	86,5,11,0,0,86,88,3,8,4,0,87,85,1,0,0,0,88,91,1,0,0,0,89,87,1,0,0,0,89,
  	90,1,0,0,0,90,93,1,0,0,0,91,89,1,0,0,0,92,84,1,0,0,0,92,93,1,0,0,0,93,
  	94,1,0,0,0,94,95,5,19,0,0,95,104,5,8,0,0,96,101,3,6,3,0,97,98,5,11,0,
  	0,98,100,3,6,3,0,99,97,1,0,0,0,100,103,1,0,0,0,101,99,1,0,0,0,101,102,
  	1,0,0,0,102,105,1,0,0,0,103,101,1,0,0,0,104,96,1,0,0,0,104,105,1,0,0,
  	0,105,106,1,0,0,0,106,107,5,9,0,0,107,109,5,3,0,0,108,25,1,0,0,0,108,
  	31,1,0,0,0,108,35,1,0,0,0,108,39,1,0,0,0,108,42,1,0,0,0,108,48,1,0,0,
  	0,108,56,1,0,0,0,108,66,1,0,0,0,108,81,1,0,0,0,109,3,1,0,0,0,110,111,
  	5,20,0,0,111,112,5,24,0,0,112,121,5,18,0,0,113,118,5,24,0,0,114,115,5,
  	11,0,0,115,117,5,24,0,0,116,114,1,0,0,0,117,120,1,0,0,0,118,116,1,0,0,
  	0,118,119,1,0,0,0,119,122,1,0,0,0,120,118,1,0,0,0,121,113,1,0,0,0,121,
  	122,1,0,0,0,122,123,1,0,0,0,123,124,5,19,0,0,124,133,5,8,0,0,125,130,
  	3,6,3,0,126,127,5,11,0,0,127,129,3,6,3,0,128,126,1,0,0,0,129,132,1,0,
  	0,0,130,128,1,0,0,0,130,131,1,0,0,0,131,134,1,0,0,0,132,130,1,0,0,0,133,
  	125,1,0,0,0,133,134,1,0,0,0,134,135,1,0,0,0,135,136,5,9,0,0,136,140,5,
  	15,0,0,137,139,3,2,1,0,138,137,1,0,0,0,139,142,1,0,0,0,140,138,1,0,0,
  	0,140,141,1,0,0,0,141,143,1,0,0,0,142,140,1,0,0,0,143,144,5,16,0,0,144,
  	5,1,0,0,0,145,146,5,24,0,0,146,147,5,8,0,0,147,148,3,8,4,0,148,149,5,
  	9,0,0,149,152,1,0,0,0,150,152,5,24,0,0,151,145,1,0,0,0,151,150,1,0,0,
  	0,152,7,1,0,0,0,153,154,6,4,-1,0,154,155,5,22,0,0,155,160,3,10,5,0,156,
  	157,5,21,0,0,157,160,3,10,5,0,158,160,3,10,5,0,159,153,1,0,0,0,159,156,
  	1,0,0,0,159,158,1,0,0,0,160,169,1,0,0,0,161,162,10,5,0,0,162,163,5,21,
  	0,0,163,168,3,10,5,0,164,165,10,4,0,0,165,166,5,22,0,0,166,168,3,10,5,
  	0,167,161,1,0,0,0,167,164,1,0,0,0,168,171,1,0,0,0,169,167,1,0,0,0,169,
  	170,1,0,0,0,170,9,1,0,0,0,171,169,1,0,0,0,172,173,6,5,-1,0,173,174,3,
  	12,6,0,174,180,1,0,0,0,175,176,10,2,0,0,176,177,5,23,0,0,177,179,3,12,
  	6,0,178,175,1,0,0,0,179,182,1,0,0,0,180,178,1,0,0,0,180,181,1,0,0,0,181,
  	11,1,0,0,0,182,180,1,0,0,0,183,190,5,25,0,0,184,190,5,24,0,0,185,186,
  	5,18,0,0,186,187,3,8,4,0,187,188,5,19,0,0,188,190,1,0,0,0,189,183,1,0,
  	0,0,189,184,1,0,0,0,189,185,1,0,0,0,190,13,1,0,0,0,19,17,23,76,89,92,
  	101,104,108,118,121,130,133,140,151,159,167,169,180,189
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

std::vector<QBorrowParser::FunctionContext *> QBorrowParser::ProgramContext::function() {
  return getRuleContexts<QBorrowParser::FunctionContext>();
}

QBorrowParser::FunctionContext* QBorrowParser::ProgramContext::function(size_t i) {
  return getRuleContext<QBorrowParser::FunctionContext>(i);
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
    setState(17);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == QBorrowParser::T__19) {
      setState(14);
      function();
      setState(19);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(21); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(20);
      statement();
      setState(23); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 144626) != 0));
   
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
    setState(108);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QBorrowParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(25);
        match(QBorrowParser::T__0);
        setState(26);
        match(QBorrowParser::ID);
        setState(27);
        match(QBorrowParser::T__1);
        setState(28);
        expr(0);
        setState(29);
        match(QBorrowParser::T__2);
        break;
      }

      case QBorrowParser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(31);
        match(QBorrowParser::T__3);
        setState(32);
        reg();
        setState(33);
        match(QBorrowParser::T__2);
        break;
      }

      case QBorrowParser::T__4: {
        enterOuterAlt(_localctx, 3);
        setState(35);
        match(QBorrowParser::T__4);
        setState(36);
        reg();
        setState(37);
        match(QBorrowParser::T__2);
        break;
      }

      case QBorrowParser::T__5: {
        enterOuterAlt(_localctx, 4);
        setState(39);
        match(QBorrowParser::T__5);
        setState(40);
        match(QBorrowParser::ID);
        setState(41);
        match(QBorrowParser::T__2);
        break;
      }

      case QBorrowParser::T__6: {
        enterOuterAlt(_localctx, 5);
        setState(42);
        match(QBorrowParser::T__6);
        setState(43);
        match(QBorrowParser::T__7);
        setState(44);
        reg();
        setState(45);
        match(QBorrowParser::T__8);
        setState(46);
        match(QBorrowParser::T__2);
        break;
      }

      case QBorrowParser::T__9: {
        enterOuterAlt(_localctx, 6);
        setState(48);
        match(QBorrowParser::T__9);
        setState(49);
        match(QBorrowParser::T__7);
        setState(50);
        reg();
        setState(51);
        match(QBorrowParser::T__10);
        setState(52);
        reg();
        setState(53);
        match(QBorrowParser::T__8);
        setState(54);
        match(QBorrowParser::T__2);
        break;
      }

      case QBorrowParser::T__11: {
        enterOuterAlt(_localctx, 7);
        setState(56);
        match(QBorrowParser::T__11);
        setState(57);
        match(QBorrowParser::T__7);
        setState(58);
        reg();
        setState(59);
        match(QBorrowParser::T__10);
        setState(60);
        reg();
        setState(61);
        match(QBorrowParser::T__10);
        setState(62);
        reg();
        setState(63);
        match(QBorrowParser::T__8);
        setState(64);
        match(QBorrowParser::T__2);
        break;
      }

      case QBorrowParser::T__12: {
        enterOuterAlt(_localctx, 8);
        setState(66);
        match(QBorrowParser::T__12);
        setState(67);
        match(QBorrowParser::ID);
        setState(68);
        match(QBorrowParser::T__1);
        setState(69);
        expr(0);
        setState(70);
        match(QBorrowParser::T__13);
        setState(71);
        expr(0);
        setState(72);
        match(QBorrowParser::T__14);
        setState(76);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 144626) != 0)) {
          setState(73);
          statement();
          setState(78);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(79);
        match(QBorrowParser::T__15);
        break;
      }

      case QBorrowParser::T__16: {
        enterOuterAlt(_localctx, 9);
        setState(81);
        match(QBorrowParser::T__16);
        setState(82);
        match(QBorrowParser::ID);
        setState(83);
        match(QBorrowParser::T__17);
        setState(92);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 56885248) != 0)) {
          setState(84);
          expr(0);
          setState(89);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == QBorrowParser::T__10) {
            setState(85);
            match(QBorrowParser::T__10);
            setState(86);
            expr(0);
            setState(91);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(94);
        match(QBorrowParser::T__18);
        setState(95);
        match(QBorrowParser::T__7);
        setState(104);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == QBorrowParser::ID) {
          setState(96);
          reg();
          setState(101);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == QBorrowParser::T__10) {
            setState(97);
            match(QBorrowParser::T__10);
            setState(98);
            reg();
            setState(103);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(106);
        match(QBorrowParser::T__8);
        setState(107);
        match(QBorrowParser::T__2);
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

//----------------- FunctionContext ------------------------------------------------------------------

QBorrowParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> QBorrowParser::FunctionContext::ID() {
  return getTokens(QBorrowParser::ID);
}

tree::TerminalNode* QBorrowParser::FunctionContext::ID(size_t i) {
  return getToken(QBorrowParser::ID, i);
}

std::vector<QBorrowParser::RegContext *> QBorrowParser::FunctionContext::reg() {
  return getRuleContexts<QBorrowParser::RegContext>();
}

QBorrowParser::RegContext* QBorrowParser::FunctionContext::reg(size_t i) {
  return getRuleContext<QBorrowParser::RegContext>(i);
}

std::vector<QBorrowParser::StatementContext *> QBorrowParser::FunctionContext::statement() {
  return getRuleContexts<QBorrowParser::StatementContext>();
}

QBorrowParser::StatementContext* QBorrowParser::FunctionContext::statement(size_t i) {
  return getRuleContext<QBorrowParser::StatementContext>(i);
}


size_t QBorrowParser::FunctionContext::getRuleIndex() const {
  return QBorrowParser::RuleFunction;
}

void QBorrowParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QBorrowListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void QBorrowParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QBorrowListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}


std::any QBorrowParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QBorrowVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

QBorrowParser::FunctionContext* QBorrowParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 4, QBorrowParser::RuleFunction);
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
    setState(110);
    match(QBorrowParser::T__19);
    setState(111);
    match(QBorrowParser::ID);
    setState(112);
    match(QBorrowParser::T__17);
    setState(121);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == QBorrowParser::ID) {
      setState(113);
      match(QBorrowParser::ID);
      setState(118);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == QBorrowParser::T__10) {
        setState(114);
        match(QBorrowParser::T__10);
        setState(115);
        match(QBorrowParser::ID);
        setState(120);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(123);
    match(QBorrowParser::T__18);
    setState(124);
    match(QBorrowParser::T__7);
    setState(133);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == QBorrowParser::ID) {
      setState(125);
      reg();
      setState(130);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == QBorrowParser::T__10) {
        setState(126);
        match(QBorrowParser::T__10);
        setState(127);
        reg();
        setState(132);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(135);
    match(QBorrowParser::T__8);
    setState(136);
    match(QBorrowParser::T__14);
    setState(140);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 144626) != 0)) {
      setState(137);
      statement();
      setState(142);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(143);
    match(QBorrowParser::T__15);
   
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
  enterRule(_localctx, 6, QBorrowParser::RuleReg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(151);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(145);
      match(QBorrowParser::ID);
      setState(146);
      match(QBorrowParser::T__7);
      setState(147);
      expr(0);
      setState(148);
      match(QBorrowParser::T__8);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(150);
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
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, QBorrowParser::RuleExpr, precedence);

    

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
    setState(159);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QBorrowParser::SUB: {
        setState(154);
        match(QBorrowParser::SUB);
        setState(155);
        term(0);
        break;
      }

      case QBorrowParser::ADD: {
        setState(156);
        match(QBorrowParser::ADD);
        setState(157);
        term(0);
        break;
      }

      case QBorrowParser::T__17:
      case QBorrowParser::ID:
      case QBorrowParser::NUMBER: {
        setState(158);
        term(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(169);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(167);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(161);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(162);
          match(QBorrowParser::ADD);
          setState(163);
          term(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(164);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(165);
          match(QBorrowParser::SUB);
          setState(166);
          term(0);
          break;
        }

        default:
          break;
        } 
      }
      setState(171);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
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
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, QBorrowParser::RuleTerm, precedence);

    

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
    setState(173);
    factor();
    _ctx->stop = _input->LT(-1);
    setState(180);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(175);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(176);
        match(QBorrowParser::MUL);
        setState(177);
        factor(); 
      }
      setState(182);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
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
  enterRule(_localctx, 12, QBorrowParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(189);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QBorrowParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(183);
        match(QBorrowParser::NUMBER);
        break;
      }

      case QBorrowParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(184);
        match(QBorrowParser::ID);
        break;
      }

      case QBorrowParser::T__17: {
        enterOuterAlt(_localctx, 3);
        setState(185);
        match(QBorrowParser::T__17);
        setState(186);
        expr(0);
        setState(187);
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
    case 4: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);
    case 5: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);

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
