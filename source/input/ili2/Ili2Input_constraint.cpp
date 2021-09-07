#pragma once

#include "Ili2Input.h"
#include "Ili2Input_helper.h"
#include "../../metamodel/MetaModelInput.h"
#include "../../util/Logger.h"

using namespace input;
using namespace parser;
using namespace metamodel;

antlrcpp::Any Ili2Input::visitConstraintDef(parser::Ili2Parser::ConstraintDefContext *ctx)
{

   /* constraintDef
   : mandatoryConstraint
   | plausibilityConstraint
   | existenceConstraint
   | uniquenessConstraint
   | setConstraint 
   */

   /* class Constraint : public MetaElement { // ABSTRACT, 2.4
   public:
      // role from ASSOCIATION DomainConstraint
      DomainType *toDomain = nullptr; // 2.4
      // role from ASSOCIATION ClassConstraint
      Class *ToClass = nullptr; // 2.4
      virtual string getClass() { return "Constraint"; }
      virtual string getBaseClass() { return "MetaElement"; };
      virtual bool isAbstract() { return true; }
   */
   
   debug(ctx,">>> visitConstraintDef()");
   Log.incNestLevel();

   Constraint *c = nullptr;
   
   if (ctx->mandatoryConstraint() != nullptr) {
      SimpleConstraint *cc = visitMandatoryConstraint(ctx->mandatoryConstraint());
      c = cc;
   }
   else if (ctx->plausibilityConstraint() != nullptr) {
      SimpleConstraint *cc = visitPlausibilityConstraint(ctx->plausibilityConstraint());
      c = cc;
   }
   else if (ctx->existenceConstraint() != nullptr) {
      ExistenceConstraint *cc = visitExistenceConstraint(ctx->existenceConstraint());
      c = cc;
   }
   else if (ctx->uniquenessConstraint() != nullptr) {
      UniqueConstraint *cc = visitUniquenessConstraint(ctx->uniquenessConstraint());
      c = cc;
   }
   else if (ctx->setConstraint() != nullptr) {
      SetConstraint *cc = visitSetConstraint(ctx->setConstraint());
      c = cc;
   }

   Log.decNestLevel();
   debug(ctx,"<<< visitConstraintDef()");

   return c;

}

static bool is_boolean_expression(Expression *e)
{
   return e->_type == "BooleanType";
}

antlrcpp::Any Ili2Input::visitMandatoryConstraint(parser::Ili2Parser::MandatoryConstraintContext *ctx)
{

   /* mandatoryConstraint
   : MANDATORY CONSTRAINT booleanexp=expression SEMI
   */

   /* class SimpleConstraint : public Constraint { // 2.4 struct -> class
   public:
      enum {MandC, LowPercC, HighPercC} Kind;
      double Percentage = 100.0;
      Expression *LogicalExpression;
   */

   debug(ctx,">>> visitMandatoryConstraint()");
   Log.incNestLevel();
   
   SimpleConstraint *c = new SimpleConstraint();
   init_constraint(c,get_line(ctx));
   c->Kind = SimpleConstraint::MandC;
   c->LogicalExpression = visitExpression(ctx->expression());
   if (c->LogicalExpression != nullptr && !is_boolean_expression(c->LogicalExpression)) {
      Log.error("expression must return a boolean value", ctx->expression()->start->getLine());
   }
   
   Log.decNestLevel();
   debug(ctx,"<<< visitMandatoryConstraint()");

   return c;

}

antlrcpp::Any Ili2Input::visitPlausibilityConstraint(parser::Ili2Parser::PlausibilityConstraintContext *ctx)
{

   /* plausibilityConstraint
   : CONSTRAINT
     (LESSEQUAL | GREATEREQUAL) percentage=decimal PERCENT
     expression SEMI
   */

   /* class SimpleConstraint : public Constraint { // 2.4 struct -> class
   public:
      enum {MandC, LowPercC, HighPercC} Kind;
      double Percentage = 100.0;
      Expression *LogicalExpression;
   */

   debug(ctx,"visitPlausibilityConstraint()");

   SimpleConstraint *c = new SimpleConstraint();
   init_constraint(c,get_line(ctx));
   c->Kind = SimpleConstraint::MandC;
   c->LogicalExpression = visitExpression(ctx->expression());
   if (!is_boolean_expression(c->LogicalExpression)) {
      Log.error("expression must return a boolean value", ctx->expression()->start->getLine());
   }
   if (ctx->LESSEQUAL() != nullptr) {
      c->_percentage_operation = SimpleConstraint::LessEqual;
   }
   else if (ctx->GREATEREQUAL() != nullptr) {
      c->_percentage_operation = SimpleConstraint::GreaterEqual;
   }
   if (ctx->percentage != nullptr) {
      c->Percentage = stod(ctx->percentage->getText());
   }
      
   return c;

}

antlrcpp::Any Ili2Input::visitExistenceConstraint(parser::Ili2Parser::ExistenceConstraintContext *ctx)
{
   
   /* existenceConstraint
   : EXISTENCE CONSTRAINT attributePath REQUIRED IN
     path COLON attributePath
     (OR path COLON attributePath )* SEMI
   ;
   */

   /* struct PathOrInspFactor : public Factor {
   public:
      list <PathEl *> PathEls;
      View *Inspection = nullptr;
   };

   class ExistenceDef : public PathOrInspFactor { // 2.4 struct -> class
   public:
      Class *Viewable = nullptr;
   };

   class ExistenceConstraint : public Constraint { // 2.4 struct -> class
   public:
      PathOrInspFactor *Attr;
      list<ExistenceDef *> ExistsIn;
   */

   debug(ctx,">>> visitExistenceConstraint()");
   Log.incNestLevel();

   ExistenceConstraint *c = new ExistenceConstraint();
   init_constraint(c,get_line(ctx));

   /* to do !!!
   c->Attr = visitAttributePath(ctx->attributePath());
   for (auto p : ctx->attributepath()) {
      ExistenceDef *d = new ExistenceDef();
   }
   */

   Log.decNestLevel();
   debug(ctx,"<<< visitExistenceConstraint()");

   return c;

}

antlrcpp::Any Ili2Input::visitUniquenessConstraint(parser::Ili2Parser::UniquenessConstraintContext *ctx)
{

   /* uniquenessConstraint
   : UNIQUE 
     (WHERE expression COLON)?
     (globalUniqueness | localUniqueness) SEMI
   */

   /* class UniqueConstraint : public Constraint { // 2.4 struct -> class
   public:
      list<Expression *> Where;
      enum {GlobalU, LocalU} Kind;
      list<PathOrInspFactor *> UniqueDef;
   */

   debug(ctx,"visitUniquenessConstraint()");
   
   UniqueConstraint *c = new UniqueConstraint();
   init_constraint(c,get_line(ctx));
   
   if (ctx->WHERE() != nullptr) {
      //c->Where = visitExpression(ctx->expression());
      // to do !!!
   }
   
   if (ctx->globalUniqueness() != nullptr) {
      c->Kind = UniqueConstraint::GlobalU;
      // c->UniqueDef = visitGlobalUniqueness(ctx->globalUniqueness());
      // to do !!!
   }
   else {
      c->Kind = UniqueConstraint::LocalU;
      // c->UniqueDef = visitLocalUniqueness(ctx->localUniqueness());
      // to do !!!
   }
   
   return c;

}

antlrcpp::Any Ili2Input::visitGlobalUniqueness(parser::Ili2Parser::GlobalUniquenessContext *ctx)
{

   /* globalUniqueness
   : uniqueEl
   */

   /* uniqueEl
   : objectOrAttributePath (COMMA objectOrAttributePath)*
   */

   /* struct PathOrInspFactor : public Factor {
   public:
      list <PathEl *> PathEls; // LIST
      View *Inspection = nullptr;
      string _path = "";
   */

   debug(ctx,">>> visitGlobalUniqueness()");
   Log.incNestLevel();
   
   list<PathOrInspFactor *> result;
   // to do !!!

   Log.decNestLevel();
   debug(ctx,"<<< visitGlobalUniqueness()");
   
   return result;

}

antlrcpp::Any Ili2Input::visitUniqueEl(parser::Ili2Parser::UniqueElContext *ctx)
{

   /* uniqueEl
   : objectOrAttributePath (COMMA objectOrAttributePath)*
   */

   debug(ctx,"visitUniqueEl()");
   
   string path = "";
   for (auto p : ctx->objectOrAttributePath()) {
      /*string ps = visitPath(p);
      if (path == "") {
         path = ps;
      }
      else {
         path = path + "." + ps;
      }*/
   }
   
   return path;

}

antlrcpp::Any Ili2Input::visitLocalUniqueness(parser::Ili2Parser::LocalUniquenessContext *ctx)
{
   
   /* localUniqueness
   : LPAREN LOCAL RPAREN structureattributename=NAME
     (RARROW structureattributename=NAME)* COLON
     attributename=NAME (COMMA attributename=NAME)*
   */

   /* struct PathOrInspFactor : public Factor {
   public:
      list <PathEl *> PathEls; // LIST
      View *Inspection = nullptr;
      string _path = "";
   */

   debug(ctx,">>> visitLocalUniqueness()");
   Log.incNestLevel();
   
   list<PathOrInspFactor *> result;
   // to do !!!

   Log.decNestLevel();
   debug(ctx,"<<< visitLocalUniqueness()");
   
   return result;

}

antlrcpp::Any Ili2Input::visitSetConstraint(parser::Ili2Parser::SetConstraintContext *ctx)
{

   /* setConstraint
   : SET CONSTRAINT (WHERE logical=expression COLON)? expression SEMI
   */

   /* class Constraint : public MetaElement { // ABSTRACT, 2.4
   public:
      // role from ASSOCIATION DomainConstraint
      DomainType *toDomain = nullptr; // 2.4
      // role from ASSOCIATION ClassConstraint
      Class *ToClass = nullptr; // 2.4
   */

   /* class SetConstraint : public Constraint { // 2.4 struct -> class
   public:
      list<Expression *> Where;
      Expression *Constraint = nullptr;
   */

   debug(ctx,">>> visitSetConstraint()");
   Log.incNestLevel();
   
   SetConstraint *c = new SetConstraint();
   init_constraint(c,get_line(ctx));
   // to do !!!

   Log.decNestLevel();
   debug(ctx,"<<< visitSetConstraint()");
         
   return c;

}

antlrcpp::Any Ili2Input::visitConstraintsDef(parser::Ili2Parser::ConstraintsDefContext *ctx)
{

   /* constraintsDef
   : CONSTRAINTS OF path EQUAL
     (constraintDef)*
     END SEMI
   */

   debug(ctx,">>> visitConstraintsDef()");
   Log.incNestLevel();
   
   Class *c = find_class(visit(ctx->path()),get_line(ctx));
   if (c != nullptr) {
      for (auto cctx : ctx->constraintDef()) { // ???, to do !!!
         Constraint *cc = visitConstraintDef(cctx);
         c->Constraint.push_back(cc);
      }
   }

   Log.decNestLevel();
   debug(ctx,"<<< visitConstraintsDef()");
   
   return nullptr;

}
