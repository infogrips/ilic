#pragma once

#include "Ili2Input.h"
#include "Ili2Input_helper.h"
#include "../../metamodel/MetaModelInput.h"
#include "../../util/Logger.h"

using namespace input;
using namespace parser;
using namespace metamodel;

antlrcpp::Any Ili2Input::visitFunctionDef(parser::Ili2Parser::FunctionDefContext *ctx)
{

   /*
   class FunctionDef : public MetaElement {
      // MetaElement.Name := FunctionName as defined in the INTERLIS-Model
   public:
      string Explanation;
      // role from ASSOCIATION LocalFType
      Type *LocalType; // ???, to do !!!
      Type *ResultType;
      // role from ASSOCIATION FormalArgument
      list <Argument *> Argument;
   };
   
   class Argument : public MetaElement {
      // MetaElement.Name := ArgumentName as defined in the INTERLIS-Model
   public:
      enum {TypeVal, EnumVal, EnumTreeVal} Kind;
      // role from ASSOCIATION FormalArgument =
      FunctionDef *Function;
      // role from ASSOCIATION ArgumentType
      Type *Type;
   };
   */

   /* functionDef
   : FUNCTION functioname=NAME
     LPAREN functionDefParam (SEMI functionDefParam)* RPAREN
     COLON result=argumentType 
     EXPLANATION? 
     SEMI
   */

   /* functionDefParam
   : argumentname=NAME COLON argumentType
   */

   /* functionArgument
   : argumentname=NAME COLON argumentType
   */
   
   string name = ctx->functioname->getText();
   debug(ctx,">>> visitFunctionDef(" + name + ")");
   Log.incNestLevel();

   FunctionDef *f = new FunctionDef;
   init_metaelement(f,ctx->start->getLine());

   // MetaElement attributes
   f->Name = name;
   add_function(f);
   
   if (ili23 && !get_model_context()->Contracted) {
      Log.error("functions can only be defined in contracted models");
   }
   
   // FunctionDef attributes
   if (ctx->EXPLANATION() != nullptr) {
      f->Explanation = ctx->EXPLANATION()->getText();
   }
   
   push_context(f);

   for (auto pctx : ctx->functionDefParam()) {
      Argument *a = new Argument();
      init_metaelement(a,ctx->start->getLine());
      a->Name = pctx->NAME()->getText();
      debug(ctx,">>> visitArgument " + a->Name);
      Log.incNestLevel();
      a->Kind = Argument::TypeVal; // to do !!!
      a->Type = visitArgumentType(pctx->argumentType());
      if (a->Type != nullptr) {
         a->Type->LFTParent = f;
      }
      a->Function = f;
      f->Argument.push_back(a);
      Log.decNestLevel();
      debug(ctx,"<<< visitArgument " + a->Name);
   }

   // f->LocalType ???
   debug(ctx,">>> visitResultType");
   Log.incNestLevel();
   Type *t = visitArgumentType(ctx->result);
   f->ResultType = t;
   Log.decNestLevel();
   debug(ctx,"<<< visitResultType");

   pop_context();

   Log.decNestLevel();
   debug(ctx,"<<< visitFunctionDef(" + name + ")");
   return f;

}

antlrcpp::Any Ili2Input::visitFunctionCall(parser::Ili2Parser::FunctionCallContext *ctx)
{

   /*
   struct FunctionCall : public Factor {
   public:
      FunctionDef *Function;
      list <ActualArgument *> Arguments;
   };
   */

   /* functionCall
   : functionname=path LPAREN functionCallArgument (COMMA functionCallArgument)* RPAREN
   */

   string functionname = visitPath(ctx->path());
   debug(ctx,">>> visitFunctionCall(" + functionname + ")");

   FunctionCall *c = new FunctionCall();
   init_factor(c,get_line(ctx));
   
   c->Function = find_function(functionname,get_line(ctx));
   if (c->Function != nullptr && c->Function->ResultType != nullptr) {
      c->_type = get_type_string(c->Function->ResultType);
   }
   else {
      c->_type = "???";
   }
   
   for (auto actx : ctx->functionCallArgument()) {
      c->Arguments.push_back(visitFunctionCallArgument(actx));
   }

   debug(ctx,"<<< visitFunctionCall(" + functionname + ":" + c->_type + ")");
   return c;

}

antlrcpp::Any Ili2Input::visitFunctionCallArgument(parser::Ili2Parser::FunctionCallArgumentContext *ctx)
{

   /*struct ActualArgument : public MMObject {
   public:
      Argument *FormalArgument;
      enum {ExpressionVal, AllOf} Kind;
      list <Expression *> Expression;
      list <ClassRef *> ObjectClasses;
   };
   */

   /* functionCallArgument
   : (expression
     | ALL (LPAREN restrictedRef | path RPAREN)* )
   */

   debug(ctx,"visitFunctionCallArgument()");

   ActualArgument *a = new ActualArgument();
   init_mmobject(a,ctx->start->getLine());

   if (ctx->expression() != nullptr) {
      a->Kind = ActualArgument::ExpressionVal;
      a->Expression = visitExpression(ctx->expression());
   }
   else {
      a->Kind = ActualArgument::AllOf;
      // a->ObjectClasses, to do !!!
   }

   return a;

}

antlrcpp::Any Ili2Input::visitArgumentType(parser::Ili2Parser::ArgumentTypeContext *ctx)
{

   /* argumentType
   : attrTypeDef
   | (OBJECT | OBJECTS) OF (restrictedRef | viewref=path)
   | ENUMVAL 
	| ENUMTREEVAL
   */

   debug(ctx,">>> visitArgumentType()");
   Log.incNestLevel();
   
   Type *t = nullptr;

   if (ctx->attrTypeDef() != nullptr) {
      t = visitAttrTypeDef(ctx->attrTypeDef());
   }
   else if (ctx->OBJECT() != nullptr) {
      if (ctx->restrictedRef() != nullptr) {
         RestrictedRef *r = visitRestrictedRef(ctx->restrictedRef());
         t = r->BaseType; // restrictions, to do !!!
      }
      else {
         // viewRef, to do !!!
         Log.internal_error("visitArgumentType(): viewRef not implemented",1);
      }
   }
   else if (ctx->OBJECTS() != nullptr) {
      MultiValue *tt = new MultiValue();
      tt->Name = "Type";
      if (ctx->restrictedRef() != nullptr) {
         RestrictedRef *r = visitRestrictedRef(ctx->restrictedRef());
         tt->BaseType = r->BaseType;
      }
      else {
         // viewRef, to do !!!
         Log.internal_error("visitArgumentType(): viewRef not implemented",1);
      }
      t = tt;
   }
   else if (ctx->ENUMVAL() != nullptr) {
      EnumTreeValueType *tt = new EnumTreeValueType();
      // tt->ET = find_enumtreevalue(); to do !!!
      t = tt;
   }
   else if (ctx->ENUMTREEVAL() != nullptr) {
      EnumTreeValueType *tt = new EnumTreeValueType();
      // tt->ET = find_enumtreevalue(); to do !!!
      t = tt;
   }
   
   //t->LFTParent = dynamic_cast<FunctionDef *>(get_context());

   Log.decNestLevel();
   debug(ctx,"<<< visitArgumentType()");
   return t;

}
