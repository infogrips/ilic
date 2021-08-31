
// Generated from ..\..\..\..\source\c\ilic\input\parser\generated\Ili2Lexer.l4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace lexer {


class  Ili2Lexer : public antlr4::Lexer {
public:
  enum {
    WS = 1, NL = 2, SL_COMMENT = 3, ILI_DOC = 4, ILI_OPTION = 5, ILI_BLOCKCOMMENT = 6, 
    INTERLIS = 7, ILI23 = 8, ILI24 = 9, CONTRACTED = 10, REFSYSTEM = 11, 
    SYMBOLOGY = 12, TYPE = 13, MODEL = 14, END = 15, VERSION = 16, NOINCREMENTALTRANSFER = 17, 
    TRANSLATION = 18, OF = 19, ATT = 20, CHARSET = 21, XMLNS = 22, IMPORTS = 23, 
    UNQUALIFIED = 24, TOPIC = 25, DEPENDS = 26, ON = 27, AS = 28, VIEW = 29, 
    EXTENDS = 30, BASKET = 31, OID = 32, BOOLEAN = 33, HALIGNMENT = 34, 
    VALIGNMENT = 35, CLASS = 36, ABSTRACT = 37, EXTENDED = 38, FINAL = 39, 
    TRANSIENT = 40, CONTINUOUS = 41, SUBDIVISION = 42, NO = 43, ATTRIBUTE = 44, 
    TEXT = 45, DATE = 46, TIMEOFDAY = 47, DATETIME = 48, LPAREN = 49, RPAREN = 50, 
    LBRACE = 51, RBRACE = 52, LCURLY = 53, RCURLY = 54, STAR = 55, SLASH = 56, 
    BACKSLASH = 57, PERCENT = 58, AT = 59, HASH = 60, TILDE = 61, LESS = 62, 
    LESSEQUAL = 63, IMPL = 64, GREATERGREATER = 65, GREATER = 66, GREATEREQUAL = 67, 
    SEMI = 68, EQUAL = 69, EQUALEQUAL = 70, LESSGREATER = 71, NOTEQUAL = 72, 
    COLONEQUAL = 73, DOT = 74, DOTDOT = 75, COLON = 76, COMMA = 77, LARROW = 78, 
    RARROW = 79, PLUS = 80, MINUS = 81, AGGREGATE = 82, ASSOCIATE = 83, 
    COMPOSITE = 84, STRUCTURE = 85, PARAMETER = 86, MANDATORY = 87, GENERICS = 88, 
    DEFERRED = 89, CONTEXT = 90, MULTICOORD = 91, MULTIPOLYLINE = 92, MULTISURFACE = 93, 
    MULTIAREA = 94, BAG = 95, LIST = 96, REFERENCE = 97, TO = 98, ANYCLASS = 99, 
    RESTRICTION = 100, ASSOCIATION = 101, DERIVED = 102, EXTERNAL = 103, 
    FROM = 104, UNDEFINED = 105, MTEXT = 106, NAME_CONST = 107, URI = 108, 
    ALL = 109, CIRCULAR = 110, OTHERS = 111, NUMERIC = 112, CLOCKWISE = 113, 
    COUNTERCLOCKWISE = 114, CARDINALITY = 115, OR = 116, HIDING = 117, ORDERED = 118, 
    ILIDOMAIN = 119, PI = 120, LNBASE = 121, FORMAT = 122, INHERIT = 123, 
    COORD = 124, ROTATION = 125, ANY = 126, BLACKBOX = 127, XML = 128, BINARY = 129, 
    DIRECTED = 130, POLYLINE = 131, SURFACE = 132, AREA = 133, WITH = 134, 
    STRAIGHTS = 135, ARCS = 136, VERTEX = 137, WITHOUT = 138, OVERLAPS = 139, 
    LINE = 140, ATTRIBUTES = 141, FORM = 142, UNIT = 143, FUNCTION = 144, 
    SIGN = 145, OBJECTS = 146, METAOBJECT = 147, CONSTRAINT = 148, CONSTRAINTS = 149, 
    EXISTENCE = 150, REQUIRED = 151, IN = 152, UNIQUE = 153, WHERE = 154, 
    LOCAL = 155, SET = 156, AND = 157, NOT = 158, BASED = 159, BASE = 160, 
    INHERITANCE = 161, DEFINED = 162, INSPECTION = 163, THIS = 164, THISAREA = 165, 
    THATAREA = 166, PARENT = 167, FIRST = 168, LAST = 169, AGGREGATES = 170, 
    OBJECT = 171, ENUMVAL = 172, ENUMTREEVAL = 173, PROJECTION = 174, JOIN = 175, 
    ILINULL = 176, UNION = 177, AGGREGATION = 178, BY = 179, GRAPHIC = 180, 
    ACCORDING = 181, WHEN = 182, ANYSTRUCTURE = 183, TRANSFER = 184, EXPLANATION = 185, 
    ESC = 186, STRING = 187, POSNUMBER = 188, NUMBER = 189, DEC = 190, SCALING = 191, 
    DECIMAL = 192, HEXNUMBER = 193, NAME = 194
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
