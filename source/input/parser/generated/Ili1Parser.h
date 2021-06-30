
// Generated from ..\..\..\..\source\c\ilic\input\parser\generated\Ili1Parser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace parser {


class  Ili1Parser : public antlr4::Parser {
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

  enum {
    RuleInterlis1Def = 0, RuleModelDef = 1, RuleDomainDefs = 2, RuleDomainDef = 3, 
    RuleTopicDef = 4, RuleTableDef = 5, RuleAttribute = 6, RuleIdentifications = 7, 
    RuleIdentification = 8, RuleType = 9, RuleAttributeType = 10, RuleBaseType = 11, 
    RuleCoord2 = 12, RuleCoord3 = 13, RuleNumericRange = 14, RuleDim1Type = 15, 
    RuleDim2Type = 16, RuleAngleType = 17, RuleTextType = 18, RuleDateType = 19, 
    RuleEnumerationType = 20, RuleEnumElement = 21, RuleHorizAlignment = 22, 
    RuleVertAlignment = 23, RuleLineType = 24, RuleAreaType = 25, RuleForm = 26, 
    RuleLineForm = 27, RuleIntersectionDef = 28, RuleControlPoints = 29, 
    RuleLineAttributes = 30, RuleDerivatives = 31, RuleView = 32, RuleViewDef = 33, 
    RuleFormatEncoding = 34, RuleFont = 35, RuleCode = 36, RuleDecimal = 37
  };

  Ili1Parser(antlr4::TokenStream *input);
  ~Ili1Parser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class Interlis1DefContext;
  class ModelDefContext;
  class DomainDefsContext;
  class DomainDefContext;
  class TopicDefContext;
  class TableDefContext;
  class AttributeContext;
  class IdentificationsContext;
  class IdentificationContext;
  class TypeContext;
  class AttributeTypeContext;
  class BaseTypeContext;
  class Coord2Context;
  class Coord3Context;
  class NumericRangeContext;
  class Dim1TypeContext;
  class Dim2TypeContext;
  class AngleTypeContext;
  class TextTypeContext;
  class DateTypeContext;
  class EnumerationTypeContext;
  class EnumElementContext;
  class HorizAlignmentContext;
  class VertAlignmentContext;
  class LineTypeContext;
  class AreaTypeContext;
  class FormContext;
  class LineFormContext;
  class IntersectionDefContext;
  class ControlPointsContext;
  class LineAttributesContext;
  class DerivativesContext;
  class ViewContext;
  class ViewDefContext;
  class FormatEncodingContext;
  class FontContext;
  class CodeContext;
  class DecimalContext; 

  class  Interlis1DefContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *transfername = nullptr;;
    Interlis1DefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRANSFER();
    antlr4::tree::TerminalNode *SEMI();
    ModelDefContext *modelDef();
    FormatEncodingContext *formatEncoding();
    antlr4::tree::TerminalNode *EOF();
    antlr4::tree::TerminalNode *NAME();
    DomainDefsContext *domainDefs();
    DerivativesContext *derivatives();
    std::vector<ViewContext *> view();
    ViewContext* view(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interlis1DefContext* interlis1Def();

  class  ModelDefContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *modelname1 = nullptr;;
    antlr4::Token *modelname2 = nullptr;;
    ModelDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MODEL();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *DOT();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    DomainDefsContext *domainDefs();
    std::vector<TopicDefContext *> topicDef();
    TopicDefContext* topicDef(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModelDefContext* modelDef();

  class  DomainDefsContext : public antlr4::ParserRuleContext {
  public:
    DomainDefsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ILIDOMAIN();
    std::vector<DomainDefContext *> domainDef();
    DomainDefContext* domainDef(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DomainDefsContext* domainDefs();

  class  DomainDefContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *domainname = nullptr;;
    DomainDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUAL();
    AttributeTypeContext *attributeType();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *NAME();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DomainDefContext* domainDef();

  class  TopicDefContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *topicname1 = nullptr;;
    antlr4::Token *topicname2 = nullptr;;
    TopicDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOPIC();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *DOT();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    std::vector<TableDefContext *> tableDef();
    TableDefContext* tableDef(size_t i);
    std::vector<DomainDefsContext *> domainDefs();
    DomainDefsContext* domainDefs(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TopicDefContext* topicDef();

  class  TableDefContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *tablename1 = nullptr;;
    antlr4::Token *tablename2 = nullptr;;
    TableDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TABLE();
    antlr4::tree::TerminalNode *EQUAL();
    IdentificationsContext *identifications();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *OPTIONAL();
    std::vector<AttributeContext *> attribute();
    AttributeContext* attribute(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TableDefContext* tableDef();

  class  AttributeContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *attributename = nullptr;;
    antlr4::Token *tablename = nullptr;;
    antlr4::Token *explanation = nullptr;;
    AttributeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    TypeContext *type();
    antlr4::tree::TerminalNode *RARROW();
    antlr4::tree::TerminalNode *OPTIONAL();
    antlr4::tree::TerminalNode *EXPLANATION();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AttributeContext* attribute();

  class  IdentificationsContext : public antlr4::ParserRuleContext {
  public:
    IdentificationsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NO();
    antlr4::tree::TerminalNode *IDENT();
    std::vector<IdentificationContext *> identification();
    IdentificationContext* identification(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentificationsContext* identifications();

  class  IdentificationContext : public antlr4::ParserRuleContext {
  public:
    IdentificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *SEMI();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentificationContext* identification();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *name = nullptr;;
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AttributeTypeContext *attributeType();
    antlr4::tree::TerminalNode *NAME();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  AttributeTypeContext : public antlr4::ParserRuleContext {
  public:
    AttributeTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BaseTypeContext *baseType();
    LineTypeContext *lineType();
    AreaTypeContext *areaType();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AttributeTypeContext* attributeType();

  class  BaseTypeContext : public antlr4::ParserRuleContext {
  public:
    BaseTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Coord2Context *coord2();
    Coord3Context *coord3();
    Dim1TypeContext *dim1Type();
    Dim2TypeContext *dim2Type();
    AngleTypeContext *angleType();
    NumericRangeContext *numericRange();
    TextTypeContext *textType();
    DateTypeContext *dateType();
    EnumerationTypeContext *enumerationType();
    HorizAlignmentContext *horizAlignment();
    VertAlignmentContext *vertAlignment();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BaseTypeContext* baseType();

  class  Coord2Context : public antlr4::ParserRuleContext {
  public:
    Ili1Parser::DecimalContext *emin = nullptr;;
    Ili1Parser::DecimalContext *nmin = nullptr;;
    Ili1Parser::DecimalContext *emax = nullptr;;
    Ili1Parser::DecimalContext *nmax = nullptr;;
    Coord2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COORD2();
    std::vector<DecimalContext *> decimal();
    DecimalContext* decimal(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Coord2Context* coord2();

  class  Coord3Context : public antlr4::ParserRuleContext {
  public:
    Ili1Parser::DecimalContext *emin = nullptr;;
    Ili1Parser::DecimalContext *nmin = nullptr;;
    Ili1Parser::DecimalContext *hmin = nullptr;;
    Ili1Parser::DecimalContext *emax = nullptr;;
    Ili1Parser::DecimalContext *nmax = nullptr;;
    Ili1Parser::DecimalContext *hmax = nullptr;;
    Coord3Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COORD3();
    std::vector<DecimalContext *> decimal();
    DecimalContext* decimal(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Coord3Context* coord3();

  class  NumericRangeContext : public antlr4::ParserRuleContext {
  public:
    Ili1Parser::DecimalContext *min = nullptr;;
    Ili1Parser::DecimalContext *max = nullptr;;
    NumericRangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *DOTDOT();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<DecimalContext *> decimal();
    DecimalContext* decimal(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumericRangeContext* numericRange();

  class  Dim1TypeContext : public antlr4::ParserRuleContext {
  public:
    Ili1Parser::DecimalContext *min = nullptr;;
    Ili1Parser::DecimalContext *max = nullptr;;
    Dim1TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DIM1();
    std::vector<DecimalContext *> decimal();
    DecimalContext* decimal(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dim1TypeContext* dim1Type();

  class  Dim2TypeContext : public antlr4::ParserRuleContext {
  public:
    Ili1Parser::DecimalContext *min = nullptr;;
    Ili1Parser::DecimalContext *max = nullptr;;
    Dim2TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DIM2();
    std::vector<DecimalContext *> decimal();
    DecimalContext* decimal(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dim2TypeContext* dim2Type();

  class  AngleTypeContext : public antlr4::ParserRuleContext {
  public:
    Ili1Parser::DecimalContext *min = nullptr;;
    Ili1Parser::DecimalContext *max = nullptr;;
    AngleTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RADIANS();
    antlr4::tree::TerminalNode *DEGREES();
    antlr4::tree::TerminalNode *GRADS();
    std::vector<DecimalContext *> decimal();
    DecimalContext* decimal(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AngleTypeContext* angleType();

  class  TextTypeContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *numchars = nullptr;;
    TextTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TEXT();
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *POSNUMBER();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TextTypeContext* textType();

  class  DateTypeContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *date = nullptr;;
    DateTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DATE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DateTypeContext* dateType();

  class  EnumerationTypeContext : public antlr4::ParserRuleContext {
  public:
    EnumerationTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<EnumElementContext *> enumElement();
    EnumElementContext* enumElement(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumerationTypeContext* enumerationType();

  class  EnumElementContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *enumelement = nullptr;;
    EnumElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);
    EnumerationTypeContext *enumerationType();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumElementContext* enumElement();

  class  HorizAlignmentContext : public antlr4::ParserRuleContext {
  public:
    HorizAlignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HALIGNMENT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  HorizAlignmentContext* horizAlignment();

  class  VertAlignmentContext : public antlr4::ParserRuleContext {
  public:
    VertAlignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VALIGNMENT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VertAlignmentContext* vertAlignment();

  class  LineTypeContext : public antlr4::ParserRuleContext {
  public:
    LineTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *POLYLINE();
    FormContext *form();
    ControlPointsContext *controlPoints();
    IntersectionDefContext *intersectionDef();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LineTypeContext* lineType();

  class  AreaTypeContext : public antlr4::ParserRuleContext {
  public:
    AreaTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SURFACE();
    FormContext *form();
    ControlPointsContext *controlPoints();
    antlr4::tree::TerminalNode *AREA();
    IntersectionDefContext *intersectionDef();
    LineAttributesContext *lineAttributes();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AreaTypeContext* areaType();

  class  FormContext : public antlr4::ParserRuleContext {
  public:
    FormContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<LineFormContext *> lineForm();
    LineFormContext* lineForm(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormContext* form();

  class  LineFormContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *explanation = nullptr;;
    LineFormContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRAIGHTS();
    antlr4::tree::TerminalNode *ARCS();
    antlr4::tree::TerminalNode *EXPLANATION();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LineFormContext* lineForm();

  class  IntersectionDefContext : public antlr4::ParserRuleContext {
  public:
    Ili1Parser::DecimalContext *maxoverlap = nullptr;;
    IntersectionDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WITHOUT();
    antlr4::tree::TerminalNode *OVERLAPS();
    antlr4::tree::TerminalNode *GREATER();
    DecimalContext *decimal();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IntersectionDefContext* intersectionDef();

  class  ControlPointsContext : public antlr4::ParserRuleContext {
  public:
    ControlPointsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VERTEX();
    Coord2Context *coord2();
    Coord3Context *coord3();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *BASE();
    antlr4::tree::TerminalNode *EXPLANATION();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ControlPointsContext* controlPoints();

  class  LineAttributesContext : public antlr4::ParserRuleContext {
  public:
    LineAttributesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LINEATTR();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *END();
    std::vector<AttributeContext *> attribute();
    AttributeContext* attribute(size_t i);
    IdentificationsContext *identifications();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LineAttributesContext* lineAttributes();

  class  DerivativesContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *derivativename1 = nullptr;;
    antlr4::Token *derivativename2 = nullptr;;
    DerivativesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DERIVATIVES();
    antlr4::tree::TerminalNode *END();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    DomainDefsContext *domainDefs();
    std::vector<TopicDefContext *> topicDef();
    TopicDefContext* topicDef(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DerivativesContext* derivatives();

  class  ViewContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *modelname1 = nullptr;;
    antlr4::Token *topicname = nullptr;;
    antlr4::Token *tablename = nullptr;;
    antlr4::Token *modelname2 = nullptr;;
    ViewContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VIEW();
    antlr4::tree::TerminalNode *END();
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<ViewDefContext *> viewDef();
    ViewDefContext* viewDef(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ViewContext* view();

  class  ViewDefContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *vertexinfo = nullptr;;
    antlr4::Token *explanation = nullptr;;
    antlr4::Token *periphery = nullptr;;
    antlr4::Token *contour = nullptr;;
    antlr4::Token *table = nullptr;;
    antlr4::Token *attr = nullptr;;
    ViewDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VERTEXINFO();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *EXPLANATION();
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *PERIPHERY();
    antlr4::tree::TerminalNode *CONTOUR();
    antlr4::tree::TerminalNode *LARROW();
    antlr4::tree::TerminalNode *DOT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ViewDefContext* viewDef();

  class  FormatEncodingContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *lineSize = nullptr;;
    antlr4::Token *tidSize = nullptr;;
    Ili1Parser::CodeContext *blankcode = nullptr;;
    Ili1Parser::CodeContext *undefinedcode = nullptr;;
    Ili1Parser::CodeContext *continuecode = nullptr;;
    FormatEncodingContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FORMAT();
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);
    antlr4::tree::TerminalNode *BLANK();
    std::vector<antlr4::tree::TerminalNode *> EQUAL();
    antlr4::tree::TerminalNode* EQUAL(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *UNDEFINED();
    antlr4::tree::TerminalNode *CONTINUE();
    antlr4::tree::TerminalNode *TID();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *I16();
    antlr4::tree::TerminalNode *I32();
    antlr4::tree::TerminalNode *ANY();
    antlr4::tree::TerminalNode *EXPLANATION();
    antlr4::tree::TerminalNode *FREE();
    antlr4::tree::TerminalNode *FIX();
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *LINESIZE();
    antlr4::tree::TerminalNode *TIDSIZE();
    std::vector<antlr4::tree::TerminalNode *> DEFAULT();
    antlr4::tree::TerminalNode* DEFAULT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> POSNUMBER();
    antlr4::tree::TerminalNode* POSNUMBER(size_t i);
    FontContext *font();
    std::vector<CodeContext *> code();
    CodeContext* code(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormatEncodingContext* formatEncoding();

  class  FontContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *expl = nullptr;;
    FontContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FONT();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *EXPLANATION();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FontContext* font();

  class  CodeContext : public antlr4::ParserRuleContext {
  public:
    CodeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *POSNUMBER();
    antlr4::tree::TerminalNode *HEXNUMBER();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CodeContext* code();

  class  DecimalContext : public antlr4::ParserRuleContext {
  public:
    DecimalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEC();
    antlr4::tree::TerminalNode *POSNUMBER();
    antlr4::tree::TerminalNode *NUMBER();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DecimalContext* decimal();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace parser
