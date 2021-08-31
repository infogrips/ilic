#pragma once

#include "Ili1Input.h"
#include "../../metamodel/MetaModelInput.h"
#include "../../util/Logger.h"

using namespace input;
using namespace parser;
using namespace metamodel;

antlrcpp::Any Ili1Input::visitDomainDefs(parser::Ili1Parser::DomainDefsContext *ctx)
{

   /* domainDefs
   : ILIDOMAIN domainDef+
   */
  
   debug(ctx,">>> visitDomainDefs()");
   Log.incNestLevel();
   
   for (auto dctx : ctx->domainDef()) {
      Type *t = visitDomainDef(dctx);
      t->ElementInPackage = get_package_context();
      get_package_context()->Element.push_back(t);
   }
   
   Log.decNestLevel();
   debug(ctx,"<<< visitDomainDefs()");

   return nullptr;
   
}

antlrcpp::Any Ili1Input::visitDomainDef(parser::Ili1Parser::DomainDefContext *ctx)
{

   /* domainDef
   : domainname=NAME EQUAL type SEMI
   */
   
   string domainname = ctx->domainname->getText();
   debug(ctx,">>> visitDomainDef(" + domainname + ")");
   Log.incNestLevel();

   // init DomainType
   Type *t = visitType(ctx->type());
   if (t != nullptr) {
      t->Name = domainname;
      add_type(t);
   }
         
   Log.decNestLevel();
   debug(ctx,"<<< visitDomainDef(" + domainname + ")");
   
   return t;

}

antlrcpp::Any Ili1Input::visitType(parser::Ili1Parser::TypeContext *ctx)
{
   
   /* type
   : baseType
   | lineType
   | areaType
   | name=NAME
   */

   debug(ctx,">>> visitType()");
   Log.incNestLevel();
   
   Type *t = nullptr;

   if (ctx->baseType() != nullptr) {
      t = visitBaseType(ctx->baseType());
   }
   else if (ctx->lineType() != nullptr) {
      LineType *l = visitLineType(ctx->lineType());
      t = l;
   }
   else if (ctx->areaType() != nullptr) {
      LineType *l = visitAreaType(ctx->areaType());
      t = l;
   }
   else {
      t = find_type(ctx->name->getText(),ctx->start->getLine()); // clone, to do !!!
   }
   
   Log.decNestLevel();
   debug(ctx,"<<< visitType()");

   return t;

}

antlrcpp::Any Ili1Input::visitBaseType(parser::Ili1Parser::BaseTypeContext *ctx)
{

   /* baseType
   : coord2
   | coord3
   | dim1Type
   | dim2Type
   | angleType
   | numericRange
   | textType
   | dateType
   | enumerationType
   | horizAlignment
   | vertAlignment
   */
   
   debug(ctx,">>> visitBaseType()");
   Log.incNestLevel();
   
   Type *t = nullptr;

   if (ctx->coord2() != nullptr) {
      CoordType *c = visitCoord2(ctx->coord2());
      t = c;
   }
   else if (ctx->coord3() != nullptr) {
      CoordType *c = visitCoord3(ctx->coord3());
      t = c;
   }
   else if (ctx->dim1Type() != nullptr) {
      NumType *n = visitDim1Type(ctx->dim1Type());
      t = n;
   }
   else if (ctx->dim2Type() != nullptr) {
      NumType *n = visitDim2Type(ctx->dim2Type());
      t = n;
   }
   else if (ctx->angleType() != nullptr) {
      NumType *n = visitAngleType(ctx->angleType());
      t = n;
   }
   else if (ctx->numericRange() != nullptr) {
      NumType *n = visitNumericRange(ctx->numericRange());
      t = n;
   }
   else if (ctx->textType() != nullptr) {
      TextType *tt = visitTextType(ctx->textType());
      t = tt;
   }
   else if (ctx->dateType() != nullptr) {
      NumType *n = visitDateType(ctx->dateType());
      t = n;
   }
   else if (ctx->enumerationType() != nullptr) {
      EnumType *e = visitEnumerationType(ctx->enumerationType());
      t = e;
   }
   else if (ctx->horizAlignment() != nullptr) {
      EnumType *e = visitHorizAlignment(ctx->horizAlignment());
      t = e;
   }
   else {
      EnumType *e = visitVertAlignment(ctx->vertAlignment());
      t = e;
   }
   
   Log.decNestLevel();
   debug(ctx,"<<< visitBaseType()");

   return t;

}

antlrcpp::Any Ili1Input::visitCoord2(parser::Ili1Parser::Coord2Context *ctx)
{
   
   /* class CoordType : public DomainType {
      public:
      int NullAxis;
      int PiHalfAxis;
      // role from ASSOCIATION LineCoord
      list <LineType *> LineType;
   */
   
   /* coord2
   : COORD2 
     emin=decimal nmin=decimal
     emax=decimal nmax=decimal
   */
   
   debug(ctx,">>> visitCoord2()");
   
   CoordType *t = new CoordType();
   init_domaintype(t,ctx->start->getLine());

   // to do !!!
   
   debug(ctx,"<<< visitCoord2()");
   
   return t;
   
}

antlrcpp::Any Ili1Input::visitCoord3(parser::Ili1Parser::Coord3Context *ctx)
{
   
   /* coord3
   : COORD3 
     emin=decimal nmin=decimal hmin = decimal
     emax=decimal nmax=decimal hmax=decimal
   */

   debug(ctx,">>> visitCoord3()");
   CoordType *t = new CoordType();
   init_domaintype(t,ctx->start->getLine());

   // to do !!!
   
   debug(ctx,"<<< visitCoord3()");

   return t;
      
}

antlrcpp::Any Ili1Input::visitNumericRange(parser::Ili1Parser::NumericRangeContext *ctx)
{

   /*
   class NumType : public DomainType {
   public:
      string Min;
      string Max;
      bool Circular = false;
      bool Clockwise = false;
      // frole from ASSOCIATION NumUnit
      Unit *Unit;
   */
   
   /* numericRange
   : LBRACE
     min = decimal
     DOTDOT
     max = decimal
     RBRACE
   */

   debug(ctx,">>> visitNumericRange()");
   
   NumType *t = new NumType();
   init_domaintype(t,ctx->start->getLine());
   
   t->Min = ctx->min->getText();
   t->Max = ctx->max->getText();
   
   debug(ctx,"<<< visitNumericRange()");
   
   return t;
   
}

antlrcpp::Any Ili1Input::visitDim1Type(parser::Ili1Parser::Dim1TypeContext *ctx)
{
   
   /*
   class NumType : public DomainType {
   public:
      string Min;
      string Max;
      bool Circular = false;
      bool Clockwise = false;
      // frole from ASSOCIATION NumUnit
      Unit *Unit;
   */
   
   /* dim1Type
   : DIM1 min=decimal max=decimal
   */

   debug(ctx,">>> visitDim1Context()");

   NumType *t = new NumType();
   init_domaintype(t,ctx->start->getLine());
   
   t->Min = ctx->min->getText();
   t->Max = ctx->max->getText();
   // t->Unit ???, to do !!!
   
   debug(ctx,"<<< visitDim1Context()");

   return t;
   
}

antlrcpp::Any Ili1Input::visitDim2Type(parser::Ili1Parser::Dim2TypeContext *ctx)
{
   
   /*
   class NumType : public DomainType {
   public:
      string Min;
      string Max;
      bool Circular = false;
      bool Clockwise = false;
      // frole from ASSOCIATION NumUnit
      Unit *Unit;
   */
   
   /* dim2Type
   : DIM2 min = decimal max=decimal
   */
   
   debug(ctx,">>> visitDim2Type()");

   NumType *t = new NumType();
   init_domaintype(t,ctx->start->getLine());
   
   t->Min = ctx->min->getText();
   t->Max = ctx->max->getText();
   // t->Unit ???, to do !!!
   
   debug(ctx,"<<< visitDim2Type()");

   return t;
      
}

antlrcpp::Any Ili1Input::visitAngleType(parser::Ili1Parser::AngleTypeContext *ctx)
{
   
   /*
   class NumType : public DomainType {
   public:
      string Min;
      string Max;
      bool Circular = false;
      bool Clockwise = false;
      // frole from ASSOCIATION NumUnit
      Unit *Unit;
   */
      
   /* angleType 
   : (RADIANS | DEGREES | GRADS) min=decimal max=decimal
   */
   
   debug(ctx,">>> visitAngleType()");

   NumType *t = new NumType();
   init_domaintype(t,ctx->start->getLine());
   
   t->Min = ctx->min->getText();
   t->Max = ctx->max->getText();

   if (ctx->RADIANS() != nullptr) {
      // t->Unit ???, to do !!!
   }
   else if (ctx->DEGREES() != nullptr) {
      // t->Unit ???, to do !!!
   }
   else if (ctx->GRADS() != nullptr) {
      // t->Unit ???, to do !!!
   }
   
   debug(ctx,"<<< visitAngleType()");

   return t;
   
}

antlrcpp::Any Ili1Input::visitTextType(parser::Ili1Parser::TextTypeContext *ctx)
{
   
   /* class TextType : public DomainType {
   public:
      enum { MText, Text, Name, Uri } Kind;
      int MaxLength = 0;
   */

   /* textType
   : TEXT STAR numchars=POSNUMBER
   */

   debug(ctx,">>> visitTextType()");
   
   TextType *t = new TextType();
   init_domaintype(t,ctx->start->getLine());
   
   t->MaxLength = atoi(ctx->numchars->getText().c_str());
   
   debug(ctx,"<<< visitAngleType()");

   return t;
   
}

antlrcpp::Any Ili1Input::visitDateType(parser::Ili1Parser::DateTypeContext *ctx)
{
   
   /* dateType
   : date=DATE
   */

   debug(ctx,">>> visitDateType()");

   NumType *n = new NumType();
   init_domaintype(n,ctx->start->getLine());

   debug(ctx,"<<< visitDateType()");

   return n;
   
}

antlrcpp::Any Ili1Input::visitEnumerationType(parser::Ili1Parser::EnumerationTypeContext *ctx)
{
   
   /* enumerationType
   : LPAREN enumElement (COMMA enumElement)* 
     RPAREN
   */
   
   debug(ctx,">>> visitEnumerationType()");
   EnumType *e = new EnumType();
   debug(ctx,"<<< visitEnumerationType()");
   return e;
   
}

antlrcpp::Any Ili1Input::visitEnumElement(parser::Ili1Parser::EnumElementContext *ctx)
{
   
   /* enumElement
   : enumelement=NAME (DOT enumelement=NAME)* enumerationType?
   */

   debug(ctx,">>> visitEnumElement()");
   debug(ctx,"<<< visitEnumElement()");
   return nullptr;
   
}

antlrcpp::Any Ili1Input::visitHorizAlignment(parser::Ili1Parser::HorizAlignmentContext *ctx)
{
   
   /* horizAlignment
   : HALIGNMENT
   */
   
   debug(ctx,">>> visitHorizAlignment()");
   EnumType *e = new EnumType();
   init_domaintype(e,ctx->start->getLine());
   debug(ctx,"<<< visitHorizAlignment()");
   return e;
   
}

antlrcpp::Any Ili1Input::visitVertAlignment(parser::Ili1Parser::VertAlignmentContext *ctx)
{
   
   /* vertAlignment
   : VALIGNMENT
   */

   debug(ctx,">>> visitVertAlignment()");
   EnumType *e = new EnumType();
   init_domaintype(e,ctx->start->getLine());
   debug(ctx,"<<< visitVertAlignment()");
   return e;
   
}

antlrcpp::Any Ili1Input::visitLineType(parser::Ili1Parser::LineTypeContext *ctx)
{
   
   /* lineType
   : POLYLINE
     form
     controlPoints
     intersectionDef?
   */
   
   debug(ctx,">>> visitLineType()");
   LineType *p = new LineType();
   init_domaintype(p,ctx->start->getLine());
   p->Kind = LineType::Polyline;
   debug(ctx,"<<< visitLineType()");
   return p;
   
}

antlrcpp::Any Ili1Input::visitAreaType(parser::Ili1Parser::AreaTypeContext *ctx)
{
   
   /* areaType
   : ( SURFACE form controlPoints intersectionDef?
     | AREA form controlPoints intersectionDef
     )
     lineAttributes?
   */

   debug(ctx,">>> visitAreaType()");
   LineType *a = new LineType();
   init_domaintype(a,ctx->start->getLine());
   a->Kind = LineType::Area;
   debug(ctx,"<<< visitAreaType() " + a->getClass());
   return a;
   
}

antlrcpp::Any Ili1Input::visitForm(parser::Ili1Parser::FormContext *ctx)
{
   
   /* form
   : WITH LPAREN
    lineForm (COMMA lineForm)*
    RPAREN
   */
   
   debug(ctx,">>> visitForm()");
   debug(ctx,"<<< visitForm()");
   return nullptr;
   
}

antlrcpp::Any Ili1Input::visitLineForm(parser::Ili1Parser::LineFormContext *ctx)
{
   
   /* lineForm
   : STRAIGHTS
   | ARCS
   | explanation=EXPLANATION
   */

   debug(ctx,">>> visitLineForm()");
   debug(ctx,"<<< visitLineForm()");
   return nullptr;
   
}

antlrcpp::Any Ili1Input::visitIntersectionDef(parser::Ili1Parser::IntersectionDefContext *ctx)
{
   
   /* intersectionDef
   : WITHOUT OVERLAPS GREATER maxoverlap=decimal
   */
   
   debug(ctx,">>> visitIntersectionDef()");
   debug(ctx,"<<< visitIntersectionDef()");
   return nullptr;
   
}

antlrcpp::Any Ili1Input::visitControlPoints(parser::Ili1Parser::ControlPointsContext *ctx)
{
   
   /* controlPoints
   : VERTEX
     (coord2 | coord3 | NAME)
     (BASE EXPLANATION)?
   */
   
   debug(ctx,">>> visitControlPoints()");
   debug(ctx,"<<< visitControlPoints()");
   return nullptr;
   
}

antlrcpp::Any Ili1Input::visitLineAttributes(parser::Ili1Parser::LineAttributesContext *ctx)
{
   
   /* lineAttributes
   : LINEATTR EQUAL
     attribute+
     identifications?
     END
   */

   debug(ctx,">>> visitLineAttributes()");
   debug(ctx,"<<< visitLineAttributes()");
   return nullptr;
   
}
