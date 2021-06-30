
// Generated from ..\..\..\..\source\c\ilic\input\parser\generated\Ili1Lexer.l4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace lexer {


class  Ili1Lexer : public antlr4::Lexer {
public:
  enum {
    WS = 1, SL_COMMENT = 2, ILI_DOC = 3, ILI_OPTION = 4, ILI_BLOCKCOMMENT = 5, 
    INTERLIS = 6, ILI23 = 7, ILI24 = 8, CONTRACTED = 9, REFSYSTEM = 10, 
    SYMBOLOGY = 11, TYPE = 12, MODEL = 13, END = 14, VERSION = 15, NOINCREMENTALTRANSFER = 16, 
    TRANSLATION = 17, OF = 18, ATT = 19, CHARSET = 20, XMLNS = 21, IMPORTS = 22, 
    UNQUALIFIED = 23, TOPIC = 24, DEPENDS = 25, ON = 26, AS = 27, VIEW = 28, 
    EXTENDS = 29, DATE = 30, BASKET = 31, OID = 32, CLASS = 33, ABSTRACT = 34, 
    EXTENDED = 35, FINAL = 36, TRANSIENT = 37, CONTINUOUS = 38, SUBDIVISION = 39, 
    NO = 40, ATTRIBUTE = 41, TEXT = 42, LPAREN = 43, RPAREN = 44, LBRACE = 45, 
    RBRACE = 46, LCURLY = 47, RCURLY = 48, STAR = 49, SLASH = 50, BACKSLASH = 51, 
    PERCENT = 52, AT = 53, HASH = 54, TILDE = 55, LESS = 56, LESSEQUAL = 57, 
    GREATERGREATER = 58, GREATER = 59, GREATEREQUAL = 60, SEMI = 61, EQUAL = 62, 
    EQUALEQUAL = 63, LESSGREATER = 64, NOTEQUAL = 65, COLONEQUAL = 66, DOT = 67, 
    DOTDOT = 68, COLON = 69, COMMA = 70, LARROW = 71, RARROW = 72, PLUS = 73, 
    MINUS = 74, AGGREGATE = 75, ASSOCIATE = 76, COMPOSITE = 77, STRUCTURE = 78, 
    PARAMETER = 79, MANDATORY = 80, BAG = 81, LIST = 82, REFERENCE = 83, 
    TO = 84, ANYCLASS = 85, RESTRICTION = 86, ASSOCIATION = 87, DERIVED = 88, 
    HALIGNMENT = 89, VALIGNMENT = 90, EXTERNAL = 91, FROM = 92, UNDEFINED = 93, 
    MTEXT = 94, URI = 95, ALL = 96, CIRCULAR = 97, OTHERS = 98, BOOLEAN = 99, 
    NUMERIC = 100, CLOCKWISE = 101, COUNTERCLOCKWISE = 102, CARDINALITY = 103, 
    OR = 104, HIDING = 105, ORDERED = 106, ILIDOMAIN = 107, PI = 108, LNBASE = 109, 
    FORMAT = 110, INHERIT = 111, COORD = 112, ROTATION = 113, ANY = 114, 
    BLACKBOX = 115, XML = 116, BINARY = 117, DIRECTED = 118, POLYLINE = 119, 
    SURFACE = 120, AREA = 121, WITH = 122, STRAIGHTS = 123, ARCS = 124, 
    VERTEX = 125, WITHOUT = 126, OVERLAPS = 127, LINE = 128, ATTRIBUTES = 129, 
    FORM = 130, UNIT = 131, FUNCTION = 132, SIGN = 133, OBJECTS = 134, METAOBJECT = 135, 
    CONSTRAINT = 136, CONSTRAINTS = 137, EXISTENCE = 138, REQUIRED = 139, 
    IN = 140, UNIQUE = 141, WHERE = 142, LOCAL = 143, SET = 144, AND = 145, 
    NOT = 146, BASED = 147, BASE = 148, INHERITANCE = 149, DEFINED = 150, 
    INSPECTION = 151, THIS = 152, THISAREA = 153, THATAREA = 154, PARENT = 155, 
    FIRST = 156, LAST = 157, AGGREGATES = 158, OBJECT = 159, ENUMVAL = 160, 
    ENUMTREEVAL = 161, PROJECTION = 162, JOIN = 163, ILINULL = 164, UNION = 165, 
    AGGREGATION = 166, BY = 167, GRAPHIC = 168, ACCORDING = 169, WHEN = 170, 
    ANYSTRUCTURE = 171, TRANSFER = 172, EQUALS = 173, OPTIONAL = 174, TABLE = 175, 
    IDENT = 176, COORD2 = 177, COORD3 = 178, DIM1 = 179, DIM2 = 180, RADIANS = 181, 
    DEGREES = 182, GRADS = 183, LINEATTR = 184, DERIVATIVES = 185, VERTEXINFO = 186, 
    PERIPHERY = 187, CONTOUR = 188, FREE = 189, FIX = 190, LINESIZE = 191, 
    TIDSIZE = 192, CODE = 193, FONT = 194, BLANK = 195, DEFAULT = 196, CONTINUE = 197, 
    TID = 198, I16 = 199, I32 = 200, EXPLANATION = 201, ESC = 202, STRING = 203, 
    POSNUMBER = 204, NUMBER = 205, DEC = 206, SCALING = 207, DECIMAL = 208, 
    HEXNUMBER = 209, NAME = 210
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
