
// Generated from /Users/subonan/subonan_THU/QDirty/src/grammar/QBorrow.g4 by ANTLR 4.13.2


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
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "ADD", 
      "SUB", "MUL", "ID", "NUMBER", "WS", "LINE_COMMENT", "BLOCK_COMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,16,106,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,1,0,1,0,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,
  	1,11,5,11,65,8,11,10,11,12,11,68,9,11,1,12,4,12,71,8,12,11,12,12,12,72,
  	1,13,4,13,76,8,13,11,13,12,13,77,1,13,1,13,1,14,1,14,1,14,1,14,5,14,86,
  	8,14,10,14,12,14,89,9,14,1,14,1,14,1,15,1,15,1,15,1,15,5,15,97,8,15,10,
  	15,12,15,100,9,15,1,15,1,15,1,15,1,15,1,15,1,98,0,16,1,1,3,2,5,3,7,4,
  	9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,1,0,
  	5,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,1,0,48,57,3,0,9,
  	10,13,13,32,32,2,0,10,10,13,13,110,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,
  	0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,
  	1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,
  	0,0,0,29,1,0,0,0,0,31,1,0,0,0,1,33,1,0,0,0,3,37,1,0,0,0,5,39,1,0,0,0,
  	7,41,1,0,0,0,9,48,1,0,0,0,11,50,1,0,0,0,13,52,1,0,0,0,15,54,1,0,0,0,17,
  	56,1,0,0,0,19,58,1,0,0,0,21,60,1,0,0,0,23,62,1,0,0,0,25,70,1,0,0,0,27,
  	75,1,0,0,0,29,81,1,0,0,0,31,92,1,0,0,0,33,34,5,108,0,0,34,35,5,101,0,
  	0,35,36,5,116,0,0,36,2,1,0,0,0,37,38,5,61,0,0,38,4,1,0,0,0,39,40,5,59,
  	0,0,40,6,1,0,0,0,41,42,5,98,0,0,42,43,5,111,0,0,43,44,5,114,0,0,44,45,
  	5,114,0,0,45,46,5,111,0,0,46,47,5,119,0,0,47,8,1,0,0,0,48,49,5,91,0,0,
  	49,10,1,0,0,0,50,51,5,93,0,0,51,12,1,0,0,0,52,53,5,40,0,0,53,14,1,0,0,
  	0,54,55,5,41,0,0,55,16,1,0,0,0,56,57,5,43,0,0,57,18,1,0,0,0,58,59,5,45,
  	0,0,59,20,1,0,0,0,60,61,5,42,0,0,61,22,1,0,0,0,62,66,7,0,0,0,63,65,7,
  	1,0,0,64,63,1,0,0,0,65,68,1,0,0,0,66,64,1,0,0,0,66,67,1,0,0,0,67,24,1,
  	0,0,0,68,66,1,0,0,0,69,71,7,2,0,0,70,69,1,0,0,0,71,72,1,0,0,0,72,70,1,
  	0,0,0,72,73,1,0,0,0,73,26,1,0,0,0,74,76,7,3,0,0,75,74,1,0,0,0,76,77,1,
  	0,0,0,77,75,1,0,0,0,77,78,1,0,0,0,78,79,1,0,0,0,79,80,6,13,0,0,80,28,
  	1,0,0,0,81,82,5,47,0,0,82,83,5,47,0,0,83,87,1,0,0,0,84,86,8,4,0,0,85,
  	84,1,0,0,0,86,89,1,0,0,0,87,85,1,0,0,0,87,88,1,0,0,0,88,90,1,0,0,0,89,
  	87,1,0,0,0,90,91,6,14,0,0,91,30,1,0,0,0,92,93,5,47,0,0,93,94,5,42,0,0,
  	94,98,1,0,0,0,95,97,9,0,0,0,96,95,1,0,0,0,97,100,1,0,0,0,98,99,1,0,0,
  	0,98,96,1,0,0,0,99,101,1,0,0,0,100,98,1,0,0,0,101,102,5,42,0,0,102,103,
  	5,47,0,0,103,104,1,0,0,0,104,105,6,15,0,0,105,32,1,0,0,0,6,0,66,72,77,
  	87,98,1,6,0,0
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
