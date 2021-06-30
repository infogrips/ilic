
// Generated from ..\..\..\..\source\c\ilic\input\parser\generated\Ili2Lexer.l4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace lexer {


class  Ili2Lexer : public antlr4::Lexer {
public:
  enum {
    WS = 1, SL_COMMENT = 2, ILI_DOC = 3, ILI_OPTION = 4, ILI_BLOCKCOMMENT = 5, 
    INTERLIS = 6, ILI23 = 7, ILI24 = 8, CONTRACTED = 9, REFSYSTEM = 10, 
    SYMBOLOGY = 11, TYPE = 12, MODEL = 13, END = 14, VERSION = 15, NOINCREMENTALTRANSFER = 16, 
    TRANSLATION = 17, OF = 18, ATT = 19, CHARSET = 20, XMLNS = 21, IMPORTS = 22, 
    UNQUALIFIED = 23, TOPIC = 24, DEPENDS = 25, ON = 26, AS = 27, VIEW = 28, 
    EXTENDS = 29, BASKET = 30, OID = 31, CLASS = 32, ABSTRACT = 33, EXTENDED = 34, 
    FINAL = 35, TRANSIENT = 36, CONTINUOUS = 37, SUBDIVISION = 38, NO = 39, 
    ATTRIBUTE = 40, TEXT = 41, DATE = 42, TIMEOFDAY = 43, DATETIME = 44, 
    LPAREN = 45, RPAREN = 46, LBRACE = 47, RBRACE = 48, LCURLY = 49, RCURLY = 50, 
    STAR = 51, SLASH = 52, BACKSLASH = 53, PERCENT = 54, AT = 55, HASH = 56, 
    TILDE = 57, LESS = 58, LESSEQUAL = 59, IMPL = 60, GREATERGREATER = 61, 
    GREATER = 62, GREATEREQUAL = 63, SEMI = 64, EQUAL = 65, EQUALEQUAL = 66, 
    LESSGREATER = 67, NOTEQUAL = 68, COLONEQUAL = 69, DOT = 70, DOTDOT = 71, 
    COLON = 72, COMMA = 73, LARROW = 74, RARROW = 75, PLUS = 76, MINUS = 77, 
    AGGREGATE = 78, ASSOCIATE = 79, COMPOSITE = 80, STRUCTURE = 81, PARAMETER = 82, 
    MANDATORY = 83, GENERICS = 84, DEFERRED = 85, CONTEXT = 86, MULTICOORD = 87, 
    MULTIPOLYLINE = 88, MULTISURFACE = 89, MULTIAREA = 90, BAG = 91, LIST = 92, 
    REFERENCE = 93, TO = 94, ANYCLASS = 95, RESTRICTION = 96, ASSOCIATION = 97, 
    DERIVED = 98, EXTERNAL = 99, FROM = 100, UNDEFINED = 101, MTEXT = 102, 
    ALL = 103, CIRCULAR = 104, OTHERS = 105, NUMERIC = 106, CLOCKWISE = 107, 
    COUNTERCLOCKWISE = 108, CARDINALITY = 109, OR = 110, HIDING = 111, ORDERED = 112, 
    ILIDOMAIN = 113, PI = 114, LNBASE = 115, FORMAT = 116, INHERIT = 117, 
    COORD = 118, ROTATION = 119, ANY = 120, BLACKBOX = 121, XML = 122, BINARY = 123, 
    DIRECTED = 124, POLYLINE = 125, SURFACE = 126, AREA = 127, WITH = 128, 
    STRAIGHTS = 129, ARCS = 130, VERTEX = 131, WITHOUT = 132, OVERLAPS = 133, 
    LINE = 134, ATTRIBUTES = 135, FORM = 136, UNIT = 137, FUNCTION = 138, 
    SIGN = 139, OBJECTS = 140, METAOBJECT = 141, CONSTRAINT = 142, CONSTRAINTS = 143, 
    EXISTENCE = 144, REQUIRED = 145, IN = 146, UNIQUE = 147, WHERE = 148, 
    LOCAL = 149, SET = 150, AND = 151, NOT = 152, BASED = 153, BASE = 154, 
    INHERITANCE = 155, DEFINED = 156, INSPECTION = 157, THIS = 158, THISAREA = 159, 
    THATAREA = 160, PARENT = 161, FIRST = 162, LAST = 163, AGGREGATES = 164, 
    OBJECT = 165, ENUMVAL = 166, ENUMTREEVAL = 167, PROJECTION = 168, JOIN = 169, 
    ILINULL = 170, UNION = 171, AGGREGATION = 172, BY = 173, GRAPHIC = 174, 
    ACCORDING = 175, WHEN = 176, ANYSTRUCTURE = 177, TRANSFER = 178, EXPLANATION = 179, 
    ESC = 180, STRING = 181, POSNUMBER = 182, NUMBER = 183, DEC = 184, SCALING = 185, 
    DECIMAL = 186, HEXNUMBER = 187, NAME = 188
  };

  Ili2Lexer(antlr4::CharStream *input);
  ~Ili2Lexer();

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
