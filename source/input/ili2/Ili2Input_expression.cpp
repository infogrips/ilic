#pragma once

#include "Ili2Input.h"
#include "Ili2Input_helper.h"
#include "../../metamodel/MetaModelInput.h"
#include "../../util/Logger.h"

using namespace input;
using namespace parser;
using namespace metamodel;

/*

   class Expression : public MMObject { // ABSTRACT
   };

   struct UnaryExpr : public Expression {
   public:
      enum {Not, Defined} Operation;
      Expression *SubExpression;
   };

   struct CompoundExpr : public Expression {
   public:
      enum {And, Or, Mult, Div,
            Relation_Equal, Relation_NotEqual,
            Relation_LessOrEqual, Relation_GreaterOrEqual,
            Relation_Less, Relation_Greater} Operation;
      list <Expression *> SubExpressions;
   };

   struct Factor : public Expression { // ABSTRACT
   };

   struct PathEl : public MMObject {
   public:
      enum {This, ThisArea, ThatArea, Parent,
            ReferenceAttr, AssocPath, Role, ViewBase,
            Attribute, MetaObject} Kind;
      MetaElement *Ref;
      int NumIndex;
      enum {First, Last} SpecIndex;
      virtual string getClass() { return "PathEl"; }
   };

   struct PathOrInspFactor : public Factor {
   public:
      list <PathEl *> PathEls;
      View *Inspection;
      virtual string getClass() { return "PathOrInspFactor"; }
   };

   struct EnumAssignment : public MMObject {
   public:
      Expression *ValueToAssign;
      EnumNode *MinEnumValue;
      EnumNode *MaxEnumValue;
      virtual string getClass() { return "EnumAssignment"; }
   };

   struct EnumMapping : public Factor {
   public:
      PathOrInspFactor *EnumValue;
      list <EnumAssignment *> Cases;
      virtual string getClass() { return "EnumMapping"; }
   };

*/

antlrcpp::Any Ili2Input::visitExpression(parser::Ili2Parser::ExpressionContext *ctx)
{

   /* expression
   : orTerm
   */

   debug(ctx,">>> visitExpression()");
   Log.incNestLevel();

   Expression *e = visitOrTerm(ctx->orTerm());

   Log.decNestLevel();
   debug(ctx, "<<< visitExpression()");
   
   return e;

}

antlrcpp::Any Ili2Input::visitOrTerm(parser::Ili2Parser::OrTermContext *ctx)
{

   /* orTerm
   : andTerm (OR andTerm)*
   */

   /* struct CompoundExpr : public Expression {
   public:
      enum {
         Implication, And, Or, Mult, Div, // 2.4 Implication
         Relation_Equal, Relation_NotEqual,
         Relation_LessOrEqual, Relation_GreaterOrEqual,
         Relation_Less, Relation_Greater
      } Operation;
      list <Expression*> SubExpressions;
   */

   debug(ctx,">>> visitOrTerm()");
   Log.incNestLevel();
   
   Expression *e = nullptr;

   if (ctx->andTerm().size() == 1) {
      e = visitAndTerm(ctx->andTerm().front());
   }
   else {
      CompoundExpr *ot = new CompoundExpr();
      ot->Operation = CompoundExpr_OperationType::Or;
      ot->_type = "BooleanType";
      for (auto t : ctx->andTerm()) {
         Expression *at = visitAndTerm(t);
         ot->SubExpressions.push_back(at);
      }
      e = ot;
   }
      
   if (e->_type != "BooleanType") {
      Log.error("term is not of boolean type", e->_line);
   }

   Log.decNestLevel();
   debug(ctx, "<<< visitOrTerm()");
   return e;
   
}

antlrcpp::Any Ili2Input::visitAndTerm(parser::Ili2Parser::AndTermContext *ctx)
{

   /* andTerm
   : otherTerm ((AND | {ili24}? STAR | {ili24}? SLASH) otherTerm)*
   */

   debug(ctx,">>> visitAndTerm()");
   Log.incNestLevel();

   Expression *e = nullptr;

   if (ctx->otherTerm().size() == 1) {
      e = visitOtherTerm(ctx->otherTerm().front());
   }
   else {
      CompoundExpr *at = new CompoundExpr();
      at->Operation = CompoundExpr_OperationType::And;
      at->_type = "BooleanType";
      for (auto t : ctx->otherTerm()) {
         Expression *pt = visitOtherTerm(t);
         at->SubExpressions.push_back(pt);
      }
      e = at;
   }

   if (e->_type != "BooleanType") {
      Log.error("term is not of boolean type", e->_line);
   }

   Log.decNestLevel();
   debug(ctx, "<<< visitAndTerm()");
   return e;
   
}

static string get_operation_type(int operation,Expression *e1,Expression *e2)
{

   /* enum {And, Or, Mult, Div,
            Relation_Equal, Relation_NotEqual,
            Relation_LessOrEqual, Relation_GreaterOrEqual,
            Relation_Less, Relation_Greater} Operation;
   */

   if (operation == CompoundExpr_OperationType::And) {
      if (e1->_type != "BooleanType") {
         Log.error("and: term is not of boolean type",e1->_line);
         return "???";
      }
      if (e2->_type != "BooleanType") {
         Log.error("and: term is not of boolean type",e1->_line);
         return "???";
      }
      return "BooleanType";
   }
   else if (operation == CompoundExpr_OperationType::Or) {
      if (e1->_type != "BooleanType") {
         Log.error("or: term is not of boolean type",e1->_line);
         return "???";
      }
      if (e2->_type != "BooleanType") {
         Log.error("or: term is not of boolean type",e1->_line);
         return "???";
      }
      return "BooleanType";
   }
   else if (operation == CompoundExpr_OperationType::Mult) {
      if (e1->_type != "NumericType") {
         Log.error("*: term is not of numeric type",e1->_line);
         return "???";
      }
      if (e2->_type != "NumericType") {
         Log.error("*: term is not of numeric type",e1->_line);
         return "???";
      }
      return "NumericType";
   }
   else if (operation == CompoundExpr_OperationType::Div) {
      if (e1->_type != "NumericType") {
         Log.error("/: term is not of numeric type",e1->_line);
         return "???";
      }
      if (e2->_type != "NumericType") {
         Log.error("/: term is not of numeric type",e1->_line);
         return "???";
      }
      return "NumericType";
   }
   else if (operation == CompoundExpr_OperationType::Relation_Equal) {
      if (e1->_type != e2->_type) {
         Log.error("==: term1 and term2 have not the same type",e1->_line);
         return "???";
      }
      return "BooleanType";
   }
   else if (operation == CompoundExpr_OperationType::Relation_NotEqual) {
      if (e1->_type != e2->_type) {
         Log.error("!=: term1 and term2 have not the same type",e1->_line);
         return "???";
      }
      return "BooleanType";
   }

   // other operations, to do !!!
   
   return "???";

}
   
antlrcpp::Any Ili2Input::visitOtherTerm(parser::Ili2Parser::OtherTermContext *ctx)
{

   /* otherTerm
   : term1=term (relation term2=term)?
   */

   debug(ctx,">>> visitOtherTerm()");
   Log.incNestLevel();

   Expression *e = nullptr;

   if (ctx->term2 == nullptr) {
      /* struct UnaryExpr : public Expression {
      public:
         enum {Not, Defined} Operation;
         Expression *SubExpression = nullptr;
      */
      UnaryExpr *u = new UnaryExpr();
      init_mmobject(u,ctx->start->getLine());
      u->SubExpression = visitTerm(ctx->term1);
      e = u;
   }
   else {
      /*
      struct CompoundExpr : public Expression {
      public:
         enum {And, Or, Mult, Div,
               Relation_Equal, Relation_NotEqual,
               Relation_LessOrEqual, Relation_GreaterOrEqual,
               Relation_Less, Relation_Greater} Operation;
         list <Expression *> SubExpressions;
         virtual string getClass() { return "CompoundExpr"; }
      };
      */
      CompoundExpr *c = new CompoundExpr();
      init_mmobject(c,ctx->start->getLine());
      c->Operation = static_cast<CompoundExpr_OperationType>(visitRelation(ctx->relation()));
      Expression *e1 = visitTerm(ctx->term1);
      c->SubExpressions.push_back(e1);
      Expression *e2 = visitTerm(ctx->term2);
      c->SubExpressions.push_back(e2);
      c->_type = get_operation_type(c->Operation,e1,e2);
      e = c;
   }

   Log.decNestLevel();
   debug(ctx, "<<< visitOtherTerm()");
   return e;
   
}
   
antlrcpp::Any Ili2Input::visitTerm(parser::Ili2Parser::TermContext *ctx)
{

   /* term
   : factor                       
   | NOT? LPAREN expression RPAREN // predicate
   | DEFINED LPAREN factor RPAREN
   */
   
   debug(ctx,">>> visitTerm()");
   Log.incNestLevel();
   
   Expression *e = nullptr;;
   
   if (ctx->factor() != nullptr) {
      /* struct Factor : public Expression { // ABSTRACT
      public:
      */
      Factor *f = visitFactor(ctx->factor());
      e = f;
   }
   else {
      /* struct UnaryExpr : public Expression {
      public:
         enum {Not, Defined} Operation;
         Expression *SubExpression;
      };
      */
      UnaryExpr *u = new UnaryExpr();
      init_mmobject(u,ctx->start->getLine());
      if (ctx->NOT() != nullptr) {
         u->Operation = UnaryExpr::Not;
      }
      else {
         u->Operation = UnaryExpr::Defined;
      }
      u->_type = "BooleanType";
      e = u;
   }

   Log.decNestLevel();
   debug(ctx, "<<< visitTerm(" + e->_type + ")");
   return e;
   
}
   
antlrcpp::Any Ili2Input::visitRelation(parser::Ili2Parser::RelationContext *ctx)
{

   /* CompoundExpr_OperationType::enum {
      And, Or, Mult, Div,
      Relation_Equal, Relation_NotEqual,
      Relation_LessOrEqual, Relation_GreaterOrEqual,
      Relation_Less, Relation_Greater
   */

   /* relation
   : EQUALEQUAL 
   | NOTEQUAL    
   | LESSGREATER
   | LESSEQUAL  
   | GREATEREQUAL
   | LESS        
   | GREATER 
   */
   
   debug(ctx,">>> visitRelation()");

   CompoundExpr_OperationType relation;

   if (ctx->EQUALEQUAL() != nullptr) {
      relation = Relation_Equal;
   }
   else if (ctx->NOTEQUAL() != nullptr) {
      relation = Relation_NotEqual;
   }
   else if (ctx->LESSGREATER() != nullptr) {
      relation = Relation_NotEqual; // ???
   }
   else if (ctx->LESSEQUAL() != nullptr) {
      relation = Relation_LessOrEqual;
   }
   else if (ctx->GREATEREQUAL() != nullptr) {
      relation = Relation_GreaterOrEqual;
   }
   else if (ctx->LESS() != nullptr) {
      relation = Relation_Less;
   }
   else { // greater
      relation = Relation_Greater;
   }
   
   debug(ctx, "<<< visitRelation() " + to_string(relation));
   return relation;
   
}

antlrcpp::Any Ili2Input::visitFactor(parser::Ili2Parser::FactorContext *ctx)
{

   /* factor
      : objectpath=objectOrAttributePath
      | (inspection | INSPECTION path) (OF inspectionpath = objectOrAttributePath)?
      | functionCall
      | PARAMETER (modelname=NAME DOT)* runtimeparametername = NAME
      | constant
   */

   /* struct Expression : public MMObject { // ABSTRACT
   public:
      string _type;
   */

   /* struct Factor : public Expression { // ABSTRACT
   */

   debug(ctx,">>> visitFactor()");
   Log.incNestLevel();
   
   Factor *f = nullptr;

   if (ctx->objectpath != nullptr) {
      PathOrInspFactor *pif = visitObjectOrAttributePath(ctx->objectpath);
      f = pif;
   }
   else if (ctx->inspection() != nullptr) {
      f = visitInspection(ctx->inspection());
   }
   else if (ctx->INSPECTION() != nullptr) {
      // to do !!!
   }
   else if (ctx->functionCall() != nullptr) {
      f = visitFunctionCall(ctx->functionCall());
   }
   else if (ctx->PARAMETER() != nullptr) {
      // to do !!!
   }
   else if (ctx->constant() != nullptr) {
      Constant *c = visitConstant(ctx->constant());
      f = c;
   }

   Log.decNestLevel();
   debug(ctx, "<<< visitFactor(" + f->_type + ")");
   return f;

}

antlrcpp::Any Ili2Input::visitConstant(parser::Ili2Parser::ConstantContext *ctx)
{

   /* struct Constant : public Factor {
   public:
      string Value;
      enum {Undefined, Numeric, Text, Enumeration} Kind;
   */

   /* constant
   : UNDEFINED
   | numericConst
   | textConst
   | formattedConst
   | enumConst
   | classConst
   | attributeConst
   */

   debug(ctx,">>> visitConstant()");
   Log.incNestLevel();
   
   Constant *c = nullptr;
   
   if (ctx->UNDEFINED() != nullptr) {
      c = new Constant();
      c->Kind = Constant::Undefined;
      c->_type = "UNDEFINED";
   }
   else if (ctx->numericConst() != nullptr) {
      c = visitNumericConst(ctx->numericConst());
   }
   else if (ctx->textConst() != nullptr) {
      c = visitTextConst(ctx->textConst());
   }
   else if (ctx->formattedConst() != nullptr) {
      c = visitFormattedConst(ctx->formattedConst());
   }
   else if (ctx->enumConst() != nullptr) {
      c = visitEnumConst(ctx->enumConst());
   }
   else if (ctx->classConst() != nullptr) {
      c = visitClassConst(ctx->classConst());
   }
   else if (ctx->attributeConst() != nullptr) {
      c = visitAttributeConst(ctx->attributeConst());
   }
   
   Log.decNestLevel();
   debug(ctx,"<<< visitConstant(" + c->_type + ")");
   
   return c;
   
}

antlrcpp::Any Ili2Input::visitDecConst(parser::Ili2Parser::DecConstContext *ctx)
{

   /* decConst
   : dec=decimal
   | PI 
   | LNBASE
   */

   debug(ctx,">>> visitDecConst()");
   Log.incNestLevel();
   
   Constant *c = new Constant();
   c->Kind = Constant::Numeric;
   c->_type = "NumType";
   
   if (ctx->PI() != nullptr) {
      c->Value = "PI";
   }
   else if (ctx->LNBASE() != nullptr) {
      c->Value = "e";
   }
   else {
      // c->Value = visitDecimal(ctx->dec); does not compile, why?
      string val = visitDecimal(ctx->dec);
      c->Value = val;
   }

   Log.decNestLevel();
   debug(ctx,"<<< visitDecConst(" + c->Value + ")");
   return c;
   
}

antlrcpp::Any Ili2Input::visitNumericConst(parser::Ili2Parser::NumericConstContext *ctx)
{

   /* numericConst
   : decConst (LBRACE unitref=path RBRACE)?
   */

   debug(ctx,">>> visitNumericConst()");
   Log.incNestLevel();

   Constant *c = visitDecConst(ctx->decConst());
   
   if (ctx->path() != nullptr) {
      Unit *u = find_unit(ctx->unitref->getText());
      // unit assignment, to do !!!
   }
   
   Log.decNestLevel();
   debug(ctx,"<<< visitNumericConst(" + c->Value + ")");
   
   return c;
   
}

antlrcpp::Any Ili2Input::visitTextConst(parser::Ili2Parser::TextConstContext *ctx)
{

   /* textConst
   : textconst=STRING
   */

   debug(ctx,">>> visitTextConst()");
   Log.incNestLevel();

   Constant *c = new Constant();
   c->Kind = Constant::Text;
   c->_type = "TextType";
   c->Value = visitString(ctx->textconst);
   
   Log.decNestLevel();
   debug(ctx,"<<< visitTextConst(" + c->Value + ")");
   return c;
   
}

antlrcpp::Any Ili2Input::visitEnumConst(parser::Ili2Parser::EnumConstContext *ctx)
{

   /* enumConst
   : HASH (NAME (DOT NAME)* (DOT OTHERS)?
   | OTHERS)
   */
   
   debug(ctx,">>> visitEnumConst()");
   Log.incNestLevel();

   Constant *c = new Constant();
   c->Kind = Constant::Enumeration;
   c->_type = "EnumType";
   c->Value = "";
   for (auto n : ctx->NAME()) {
      if (c->Value == "") {
         c->Value = n->getText();
      }
      else {
         c->Value = c->Value + "." + n->getText();
      }
   }

   Log.decNestLevel();
   debug(ctx,"<<< visitEnumConst(" + c->Value + ")");
   return c;
   
}

antlrcpp::Any Ili2Input::visitClassConst(parser::Ili2Parser::ClassConstContext *ctx)
{

   /* classConst
   : GREATER classref=path
   */

   debug(ctx,">>> visitClassConst()");
   Log.incNestLevel();

   Constant *c = new Constant();
   c->Kind = Constant::Enumeration;
   c->_type = "EnumType";
   string val = visitPath(ctx->path());
   c->Value = val;
   
   if (find_class(c->Value) == nullptr) {
      Log.error("class " + c->Value + " not found",ctx->start->getLine());
   }

   Log.decNestLevel();
   debug(ctx,"<<< visitClassConst(" + c->Value + ")");
   return c;
   
}

antlrcpp::Any Ili2Input::visitAttributeConst(parser::Ili2Parser::AttributeConstContext *ctx)
{
   
   /* attributeConst
   : GREATERGREATER (classref=path DOT)? attribute=NAME
   */

   debug(ctx,">>> visitAttributeConst()");
   Log.incNestLevel();

   Constant *c = new Constant();
   c->Kind = Constant::Text; // ???
   c->_type = "TextType";
   if (ctx->path() != nullptr) {
      string path = visitPath(ctx->path());
      c->Value = path + "." + ctx->NAME()->getSymbol()->getText();
   }
   else {
      c->Value = ctx->NAME()->getText();
   }

   Log.decNestLevel();
   debug(ctx,"<<< visitAttributeConst(" + c->Value + ")");
   return c;
   
}

antlrcpp::Any Ili2Input::visitFormattedConst(parser::Ili2Parser::FormattedConstContext *ctx)
{

   /* formattedConst
   : formattedconst=STRING
   */

   debug(ctx,">>> visitFormattedConst()");
   Log.incNestLevel();

   Constant *c = new Constant();
   c->Kind = Constant::Text;
   c->_type = "TextType";
   c->Value = visitString(ctx->formattedconst);

   Log.decNestLevel();
   debug(ctx,"visitFormattedConst(" + c->Value + ")");
   return c;
   
}

