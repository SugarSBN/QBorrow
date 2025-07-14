
// Generated from /Users/subonan/subonan_THU/QBorrow/src/grammar/QBorrow.g4 by ANTLR 4.13.2


#include "QBorrowLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct QBorrowLexerStaticData final {
  QBorrowLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  QBorrowLexerStaticData(const QBorrowLexerStaticData&) = delete;
  QBorrowLexerStaticData(QBorrowLexerStaticData&&) = delete;
  QBorrowLexerStaticData& operator=(const QBorrowLexerStaticData&) = delete;
  QBorrowLexerStaticData& operator=(QBorrowLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag qborrowlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<QBorrowLexerStaticData> qborrowlexerLexerStaticData = nullptr;

void qborrowlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (qborrowlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(qborrowlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<QBorrowLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "T__15", "T__16", 
      "ADD", "SUB", "MUL", "ID", "NUMBER", "WS", "LINE_COMMENT", "BLOCK_COMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,25,156,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,1,0,1,0,1,0,1,0,1,1,1,1,1,2,1,2,1,
  	3,1,3,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,6,1,6,1,7,
  	1,7,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,
  	11,1,11,1,11,1,12,1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,15,1,16,1,16,1,
  	17,1,17,1,18,1,18,1,19,1,19,1,20,1,20,5,20,115,8,20,10,20,12,20,118,9,
  	20,1,21,4,21,121,8,21,11,21,12,21,122,1,22,4,22,126,8,22,11,22,12,22,
  	127,1,22,1,22,1,23,1,23,1,23,1,23,5,23,136,8,23,10,23,12,23,139,9,23,
  	1,23,1,23,1,24,1,24,1,24,1,24,5,24,147,8,24,10,24,12,24,150,9,24,1,24,
  	1,24,1,24,1,24,1,24,1,148,0,25,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,
  	9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,
  	21,43,22,45,23,47,24,49,25,1,0,5,3,0,65,90,95,95,97,122,4,0,48,57,65,
  	90,95,95,97,122,1,0,48,57,3,0,9,10,13,13,32,32,2,0,10,10,13,13,160,0,
  	1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,
  	0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,
  	23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,
  	0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,
  	0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,1,51,1,0,0,0,3,55,1,0,0,0,5,
  	57,1,0,0,0,7,59,1,0,0,0,9,66,1,0,0,0,11,72,1,0,0,0,13,74,1,0,0,0,15,76,
  	1,0,0,0,17,78,1,0,0,0,19,83,1,0,0,0,21,85,1,0,0,0,23,91,1,0,0,0,25,95,
  	1,0,0,0,27,98,1,0,0,0,29,100,1,0,0,0,31,102,1,0,0,0,33,104,1,0,0,0,35,
  	106,1,0,0,0,37,108,1,0,0,0,39,110,1,0,0,0,41,112,1,0,0,0,43,120,1,0,0,
  	0,45,125,1,0,0,0,47,131,1,0,0,0,49,142,1,0,0,0,51,52,5,108,0,0,52,53,
  	5,101,0,0,53,54,5,116,0,0,54,2,1,0,0,0,55,56,5,61,0,0,56,4,1,0,0,0,57,
  	58,5,59,0,0,58,6,1,0,0,0,59,60,5,98,0,0,60,61,5,111,0,0,61,62,5,114,0,
  	0,62,63,5,114,0,0,63,64,5,111,0,0,64,65,5,119,0,0,65,8,1,0,0,0,66,67,
  	5,97,0,0,67,68,5,108,0,0,68,69,5,108,0,0,69,70,5,111,0,0,70,71,5,99,0,
  	0,71,10,1,0,0,0,72,73,5,88,0,0,73,12,1,0,0,0,74,75,5,91,0,0,75,14,1,0,
  	0,0,76,77,5,93,0,0,77,16,1,0,0,0,78,79,5,67,0,0,79,80,5,78,0,0,80,81,
  	5,79,0,0,81,82,5,84,0,0,82,18,1,0,0,0,83,84,5,44,0,0,84,20,1,0,0,0,85,
  	86,5,67,0,0,86,87,5,67,0,0,87,88,5,78,0,0,88,89,5,79,0,0,89,90,5,84,0,
  	0,90,22,1,0,0,0,91,92,5,102,0,0,92,93,5,111,0,0,93,94,5,114,0,0,94,24,
  	1,0,0,0,95,96,5,116,0,0,96,97,5,111,0,0,97,26,1,0,0,0,98,99,5,123,0,0,
  	99,28,1,0,0,0,100,101,5,125,0,0,101,30,1,0,0,0,102,103,5,40,0,0,103,32,
  	1,0,0,0,104,105,5,41,0,0,105,34,1,0,0,0,106,107,5,43,0,0,107,36,1,0,0,
  	0,108,109,5,45,0,0,109,38,1,0,0,0,110,111,5,42,0,0,111,40,1,0,0,0,112,
  	116,7,0,0,0,113,115,7,1,0,0,114,113,1,0,0,0,115,118,1,0,0,0,116,114,1,
  	0,0,0,116,117,1,0,0,0,117,42,1,0,0,0,118,116,1,0,0,0,119,121,7,2,0,0,
  	120,119,1,0,0,0,121,122,1,0,0,0,122,120,1,0,0,0,122,123,1,0,0,0,123,44,
  	1,0,0,0,124,126,7,3,0,0,125,124,1,0,0,0,126,127,1,0,0,0,127,125,1,0,0,
  	0,127,128,1,0,0,0,128,129,1,0,0,0,129,130,6,22,0,0,130,46,1,0,0,0,131,
  	132,5,47,0,0,132,133,5,47,0,0,133,137,1,0,0,0,134,136,8,4,0,0,135,134,
  	1,0,0,0,136,139,1,0,0,0,137,135,1,0,0,0,137,138,1,0,0,0,138,140,1,0,0,
  	0,139,137,1,0,0,0,140,141,6,23,0,0,141,48,1,0,0,0,142,143,5,47,0,0,143,
  	144,5,42,0,0,144,148,1,0,0,0,145,147,9,0,0,0,146,145,1,0,0,0,147,150,
  	1,0,0,0,148,149,1,0,0,0,148,146,1,0,0,0,149,151,1,0,0,0,150,148,1,0,0,
  	0,151,152,5,42,0,0,152,153,5,47,0,0,153,154,1,0,0,0,154,155,6,24,0,0,
  	155,50,1,0,0,0,6,0,116,122,127,137,148,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  qborrowlexerLexerStaticData = std::move(staticData);
}

}

QBorrowLexer::QBorrowLexer(CharStream *input) : Lexer(input) {
  QBorrowLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *qborrowlexerLexerStaticData->atn, qborrowlexerLexerStaticData->decisionToDFA, qborrowlexerLexerStaticData->sharedContextCache);
}

QBorrowLexer::~QBorrowLexer() {
  delete _interpreter;
}

std::string QBorrowLexer::getGrammarFileName() const {
  return "QBorrow.g4";
}

const std::vector<std::string>& QBorrowLexer::getRuleNames() const {
  return qborrowlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& QBorrowLexer::getChannelNames() const {
  return qborrowlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& QBorrowLexer::getModeNames() const {
  return qborrowlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& QBorrowLexer::getVocabulary() const {
  return qborrowlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView QBorrowLexer::getSerializedATN() const {
  return qborrowlexerLexerStaticData->serializedATN;
}

const atn::ATN& QBorrowLexer::getATN() const {
  return *qborrowlexerLexerStaticData->atn;
}




void QBorrowLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  qborrowlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(qborrowlexerLexerOnceFlag, qborrowlexerLexerInitialize);
#endif
}
