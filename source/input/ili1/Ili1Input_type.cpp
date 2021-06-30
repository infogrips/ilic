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
  
   Log.debug("visitDomainDefs()");
   
   for (auto dctx : ctx->domainDef()) {
      DomainType *t = visitDomainDef(dctx);
      t->ElementInPackage = get_package_context();
      get_package_context()->Element.push_back(t);
   }
   
   return nullptr;
   
}

antlrcpp::Any Ili1Input::visitDomainDef(parser::Ili1Parser::DomainDefContext *ctx)
{

   /* domainDef
   : domainname=NAME EQUAL attributeType SEMI
   */
   
   string domainname = ctx->domainname->getText();
   Log.debug("visitDomainDef(" + domainname + ")");

   // init DomainType
   DomainType *t = any_to_domaintype(visitAttributeType(ctx->attributeType()));
   Log.debug("visitDomainDef(" + domainname + ") DomainType is " + t->getClass());
         
   // ExtendableME Attributes
   t->Name = domainname;
   add_type(t);

   Log.debug("return " + t->getClass());
   
   return t;

}

antlrcpp::Any Ili1Input::visitAttributeType(parser::Ili1Parser::AttributeTypeContext *ctx)
{
   
   /* attributeType
   : baseType
   | lineType
   | areaType
   */

   Log.debug("visitAttributeType()");

   if (ctx->baseType() != nullptr) {
      return visitBaseType(ctx->baseType());
   }
   else if (ctx->lineType() != nullptr) {
      return visitLineType(ctx->lineType());
   }
   else {
      return visitAreaType(ctx->areaType());
   }
   
   return nullptr;

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
   
   Log.debug("visitBaseType()");

   if (ctx->coord2() != nullptr) {
      return visitCoord2(ctx->coord2());
   }
   else if (ctx->coord3() != nullptr) {
      return visitCoord3(ctx->coord3());
   }
   else if (ctx->dim1Type() != nullptr) {
      return visitDim1Type(ctx->dim1Type());
   }
   else if (ctx->dim2Type() != nullptr) {
      return visitDim2Type(ctx->dim2Type());
   }
   else if (ctx->angleType() != nullptr) {
      return visitAngleType(ctx->angleType());
   }
   else if (ctx->numericRange() != nullptr) {
      return visitNumericRange(ctx->numericRange());
   }
   else if (ctx->textType() != nullptr) {
      return visitTextType(ctx->textType());
   }
   else if (ctx->dateType() != nullptr) {
      return visitDateType(ctx->dateType());
   }
   else if (ctx->enumerationType() != nullptr) {
      return visitEnumerationType(ctx->enumerationType());
   }
   else if (ctx->horizAlignment() != nullptr) {
      return visitHorizAlignment(ctx->horizAlignment());
   }
   else {
      return visitVertAlignment(ctx->vertAlignment());
   }
   
   return nullptr;

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
   
   Log.debug("visitCoord2()");
   
   CoordType *t = new CoordType();
   init_domaintype(t,ctx->start->getLine());

   // to do !!!
   
   return t;
   
}

antlrcpp::Any Ili1Input::visitCoord3(parser::Ili1Parser::Coord3Context *ctx)
{
   
   /* coord3
   : COORD3 
     emin=decimal nmin=decimal hmin = decimal
     emax=decimal nmax=decimal hmax=decimal
   */

   Log.debug("visitCoord3()");
   CoordType *t = new CoordType();
   init_domaintype(t,ctx->start->getLine());

   // to do !!!
   
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

   Log.debug("visitNumericRange()");
   
   NumType *t = new NumType();
   init_domaintype(t,ctx->start->getLine());
   
   t->Min = ctx->min->getText();
   t->Max = ctx->max->getText();
   
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

   Log.debug("visitDim1Context()");

   NumType *t = new NumType();
   init_domaintype(t,ctx->start->getLine());
   
   t->Min = ctx->min->getText();
   t->Max = ctx->max->getText();
   // t->Unit ???, to do !!!
   
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
   
   Log.debug("visitDim2Type()");

   NumType *t = new NumType();
   init_domaintype(t,ctx->start->getLine());
   
   t->Min = ctx->min->getText();
   t->Max = ctx->max->getText();
   // t->Unit ???, to do !!!
   
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
   
   Log.debug("visitAngleType()");

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

   Log.debug("visitTextType()");
   
   TextType *t = new TextType();
   init_domaintype(t,ctx->start->getLine());
   
   t->MaxLength = atoi(ctx->numchars->getText().c_str());
   
   return t;
   
}

antlrcpp::Any Ili1Input::visitDateType(parser::Ili1Parser::DateTypeContext *ctx)
{
   
   /* dateType
   : date=DATE
   */

   Log.debug("visitDateType()");
   return nullptr;
   
}

antlrcpp::Any Ili1Input::visitEnumerationType(parser::Ili1Parser::EnumerationTypeContext *ctx)
{
   
   /* enumerationType
   : LPAREN enumElement (COMMA enumElement)* 
     RPAREN
   */
   
   Log.debug("visitEnumerationType()");
   return nullptr;
   
}

antlrcpp::Any Ili1Input::visitEnumElement(parser::Ili1Parser::EnumElementContext *ctx)
{
   
   /* enumElement
   : enumelement=NAME (DOT enumelement=NAME)* enumerationType?
   */

   Log.debug("visitEnumElement()");
   return nullptr;
   
}

antlrcpp::Any Ili1Input::visitHorizAlignment(parser::Ili1Parser::HorizAlignmentContext *ctx)
{
   
   /* horizAlignment
   : HALIGNMENT
   */
   
   Log.debug("visitHorizAlignment()");
   return nullptr;
   
}

antlrcpp::Any Ili1Input::visitVertAlignment(parser::Ili1Parser::VertAlignmentContext *ctx)
{
   
   /* vertAlignment
   : VALIGNMENT
   */

   Log.debug("visitVertAlignment()");
   return nullptr;
   
}

antlrcpp::Any Ili1Input::visitLineType(parser::Ili1Parser::LineTypeContext *ctx)
{
   
   /* lineType
   : POLYLINE
     form
     controlPoints
     intersectionDef?
   */
   
   Log.debug("visitLineType()");
   return nullptr;
   
}

antlrcpp::Any Ili1Input::visitAreaType(parser::Ili1Parser::AreaTypeContext *ctx)
{
   
   /* areaType
   : ( SURFACE form controlPoints intersectionDef?
     | AREA form controlPoints intersectionDef
     )
     lineAttributes?
   */

   Log.debug("visitAreaType()");
   return nullptr;
   
}

antlrcpp::Any Ili1Input::visitForm(parser::Ili1Parser::FormContext *ctx)
{
   
   /* form
   : WITH LPAREN
    lineForm (COMMA lineForm)*
    RPAREN
   */
   
   Log.debug("visitForm()");
   return nullptr;
   
}

antlrcpp::Any Ili1Input::visitLineForm(parser::Ili1Parser::LineFormContext *ctx)
{
   
   /* lineForm
   : STRAIGHTS
   | ARCS
   | explanation=EXPLANATION
   */

   Log.debug("visitLineForm()");
   return nullptr;
   
}

antlrcpp::Any Ili1Input::visitIntersectionDef(parser::Ili1Parser::IntersectionDefContext *ctx)
{
   
   /* intersectionDef
   : WITHOUT OVERLAPS GREATER maxoverlap=decimal
   */
   
   Log.debug("visitIntersectionDef()");
   return nullptr;
   
}

antlrcpp::Any Ili1Input::visitControlPoints(parser::Ili1Parser::ControlPointsContext *ctx)
{
   
   /* controlPoints
   : VERTEX
     (coord2 | coord3 | NAME)
     (BASE EXPLANATION)?
   */
   
   Log.debug("visitControlPoints()");
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

   Log.debug("visitLineAttributes()");
   return nullptr;
   
}
