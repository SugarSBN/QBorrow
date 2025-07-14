
// Generated from /Users/subonan/subonan_THU/antlr-playground/dirty/src/grammar/QDirty.g4 by ANTLR 4.13.2


#include "QDirtyLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct QDirtyLexerStaticData final {
  QDirtyLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  QDirtyLexerStaticData(const QDirtyLexerStaticData&) = delete;
  QDirtyLexerStaticData(QDirtyLexerStaticData&&) = delete;
  QDirtyLexerStaticData& operator=(const QDirtyLexerStaticData&) = delete;
  QDirtyLexerStaticData& operator=(QDirtyLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag qdirtylexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<QDirtyLexerStaticData> qdirtylexerLexerStaticData = nullptr;

void qdirtylexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (qdirtylexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(qdirtylexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<QDirtyLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "ADD", "SUB", "MUL", "ID", "NUMBER", "WS", "LINE_COMMENT", "BLOCK_COMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,17,114,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,1,0,1,0,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,
  	8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,5,12,73,8,12,10,12,12,12,76,9,
  	12,1,13,4,13,79,8,13,11,13,12,13,80,1,14,4,14,84,8,14,11,14,12,14,85,
  	1,14,1,14,1,15,1,15,1,15,1,15,5,15,94,8,15,10,15,12,15,97,9,15,1,15,1,
  	15,1,16,1,16,1,16,1,16,5,16,105,8,16,10,16,12,16,108,9,16,1,16,1,16,1,
  	16,1,16,1,16,1,106,0,17,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,
  	21,11,23,12,25,13,27,14,29,15,31,16,33,17,1,0,5,3,0,65,90,95,95,97,122,
  	4,0,48,57,65,90,95,95,97,122,1,0,48,57,3,0,9,10,13,13,32,32,2,0,10,10,
  	13,13,118,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,
  	0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,
  	1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,
  	0,0,0,33,1,0,0,0,1,35,1,0,0,0,3,39,1,0,0,0,5,41,1,0,0,0,7,43,1,0,0,0,
  	9,50,1,0,0,0,11,56,1,0,0,0,13,58,1,0,0,0,15,60,1,0,0,0,17,62,1,0,0,0,
  	19,64,1,0,0,0,21,66,1,0,0,0,23,68,1,0,0,0,25,70,1,0,0,0,27,78,1,0,0,0,
  	29,83,1,0,0,0,31,89,1,0,0,0,33,100,1,0,0,0,35,36,5,108,0,0,36,37,5,101,
  	0,0,37,38,5,116,0,0,38,2,1,0,0,0,39,40,5,61,0,0,40,4,1,0,0,0,41,42,5,
  	59,0,0,42,6,1,0,0,0,43,44,5,98,0,0,44,45,5,111,0,0,45,46,5,114,0,0,46,
  	47,5,114,0,0,47,48,5,111,0,0,48,49,5,119,0,0,49,8,1,0,0,0,50,51,5,97,
  	0,0,51,52,5,108,0,0,52,53,5,108,0,0,53,54,5,111,0,0,54,55,5,99,0,0,55,
  	10,1,0,0,0,56,57,5,91,0,0,57,12,1,0,0,0,58,59,5,93,0,0,59,14,1,0,0,0,
  	60,61,5,40,0,0,61,16,1,0,0,0,62,63,5,41,0,0,63,18,1,0,0,0,64,65,5,43,
  	0,0,65,20,1,0,0,0,66,67,5,45,0,0,67,22,1,0,0,0,68,69,5,42,0,0,69,24,1,
  	0,0,0,70,74,7,0,0,0,71,73,7,1,0,0,72,71,1,0,0,0,73,76,1,0,0,0,74,72,1,
  	0,0,0,74,75,1,0,0,0,75,26,1,0,0,0,76,74,1,0,0,0,77,79,7,2,0,0,78,77,1,
  	0,0,0,79,80,1,0,0,0,80,78,1,0,0,0,80,81,1,0,0,0,81,28,1,0,0,0,82,84,7,
  	3,0,0,83,82,1,0,0,0,84,85,1,0,0,0,85,83,1,0,0,0,85,86,1,0,0,0,86,87,1,
  	0,0,0,87,88,6,14,0,0,88,30,1,0,0,0,89,90,5,47,0,0,90,91,5,47,0,0,91,95,
  	1,0,0,0,92,94,8,4,0,0,93,92,1,0,0,0,94,97,1,0,0,0,95,93,1,0,0,0,95,96,
  	1,0,0,0,96,98,1,0,0,0,97,95,1,0,0,0,98,99,6,15,0,0,99,32,1,0,0,0,100,
  	101,5,47,0,0,101,102,5,42,0,0,102,106,1,0,0,0,103,105,9,0,0,0,104,103,
  	1,0,0,0,105,108,1,0,0,0,106,107,1,0,0,0,106,104,1,0,0,0,107,109,1,0,0,
  	0,108,106,1,0,0,0,109,110,5,42,0,0,110,111,5,47,0,0,111,112,1,0,0,0,112,
  	113,6,16,0,0,113,34,1,0,0,0,6,0,74,80,85,95,106,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  qdirtylexerLexerStaticData = std::move(staticData);
}

}

QDirtyLexer::QDirtyLexer(CharStream *input) : Lexer(input) {
  QDirtyLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *qdirtylexerLexerStaticData->atn, qdirtylexerLexerStaticData->decisionToDFA, qdirtylexerLexerStaticData->sharedContextCache);
}

QDirtyLexer::~QDirtyLexer() {
  delete _interpreter;
}

std::string QDirtyLexer::getGrammarFileName() const {
  return "QDirty.g4";
}

const std::vector<std::string>& QDirtyLexer::getRuleNames() const {
  return qdirtylexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& QDirtyLexer::getChannelNames() const {
  return qdirtylexerLexerStaticData->channelNames;
}

const std::vector<std::string>& QDirtyLexer::getModeNames() const {
  return qdirtylexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& QDirtyLexer::getVocabulary() const {
  return qdirtylexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView QDirtyLexer::getSerializedATN() const {
  return qdirtylexerLexerStaticData->serializedATN;
}

const atn::ATN& QDirtyLexer::getATN() const {
  return *qdirtylexerLexerStaticData->atn;
}




void QDirtyLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  qdirtylexerLexerInitialize();
#else
  ::antlr4::internal::call_once(qdirtylexerLexerOnceFlag, qdirtylexerLexerInitialize);
#endif
}
