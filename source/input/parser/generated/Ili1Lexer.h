
// Generated from ..\..\..\..\source\c\ilic\input\parser\generated\Ili1Lexer.l4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace lexer {


class  Ili1Lexer : public antlr4::Lexer {
public:
  enum {
    WS = 1, SL_COMMENT = 2, ILI_DOC = 3, ILI_OPTION = 4, ILI_BLOCKCOMMENT = 5, 
    MODEL = 6, END = 7, TOPIC = 8, VIEW = 9, DATE = 10, NO = 11, TEXT = 12, 
    LPAREN = 13, RPAREN = 14, LBRACE = 15, RBRACE = 16, STAR = 17, GREATER = 18, 
    SEMI = 19, EQUAL = 20, DOT = 21, DOTDOT = 22, COLON = 23, COMMA = 24, 
    LARROW = 25, RARROW = 26, HALIGNMENT = 27, VALIGNMENT = 28, UNDEFINED = 29, 
    BOOLEAN = 30, ILIDOMAIN = 31, FORMAT = 32, COORD = 33, ANY = 34, POLYLINE = 35, 
    SURFACE = 36, AREA = 37, WITH = 38, STRAIGHTS = 39, ARCS = 40, VERTEX = 41, 
    WITHOUT = 42, OVERLAPS = 43, FORM = 44, BASE = 45, TRANSFER = 46, OPTIONAL = 47, 
    TABLE = 48, IDENT = 49, COORD2 = 50, COORD3 = 51, DIM1 = 52, DIM2 = 53, 
    RADIANS = 54, DEGREES = 55, GRADS = 56, LINEATTR = 57, DERIVATIVES = 58, 
    VERTEXINFO = 59, PERIPHERY = 60, CONTOUR = 61, FREE = 62, FIX = 63, 
    LINESIZE = 64, TIDSIZE = 65, CODE = 66, FONT = 67, BLANK = 68, DEFAULT = 69, 
    CONTINUE = 70, TID = 71, I16 = 72, I32 = 73, EXPLANATION = 74, ESC = 75, 
    STRING = 76, POSNUMBER = 77, NUMBER = 78, DEC = 79, SCALING = 80, DECIMAL = 81, 
    HEXNUMBER = 82, NAME = 83, ERRORCHAR = 84
  };

  Ili1Lexer(antlr4::CharStream *input);
  ~Ili1Lexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace lexer
