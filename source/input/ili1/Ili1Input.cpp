#include "Ili1Input.h"
#include "../parser/IliParserErrorListener.h"
#include "../parser/generated/Ili1Lexer.cpp"
#include "../parser/generated/Ili1Parser.cpp"
#include "../../metamodel/MetaModelInput.h"
#include "../../util/Logger.h"
#include "../../util/StringUtil.h"

using namespace input;
using namespace parser;
using namespace metamodel;

antlrcpp::Any Ili1Input::visitDecimal(Ili1Parser::DecimalContext *ctx)
{

   /* decimal
	: DEC
	| POSNUMBER
	| NUMBER
	*/
   
   debug(ctx,">>> visitDecimal()");
   Log.incNestLevel();
   
   string value;

   if (ctx->DEC() != nullptr) {
      value = ctx->DEC()->getText();
   }
   else if (ctx->POSNUMBER() != nullptr) {
      value = ctx->POSNUMBER()->getText();
   }
   else {
      value = ctx->NUMBER()->getText();
   }

   Log.decNestLevel();
   debug(ctx,"<<< visitDecimal(" + value + ")");

   return value;

}

extern string input_file;

void input::parseIli1(string input)
{

   antlr4::ANTLRInputStream inputstream(util::load_filtered_string_from_file(input));
   input_file = input;

   Log.debug("creating ili1 lexer (1) ...");
   lexer::Ili1Lexer ili1lexer(&inputstream);
   Log.debug("creating ili1 lexer (2) ...");
   antlr4::CommonTokenStream tokens(&ili1lexer);

   Log.debug("creating ili1 parser ...");
   parser::Ili1Parser ili1parser(&tokens);
   ili1parser.removeErrorListeners();
   ili1parser.addErrorListener(new parser::IliParserErrorListener());
   parser::Ili1Parser::Interlis1DefContext *ili1d = ili1parser.interlis1Def();

   Log.debug("ili1 building meta model ...");
   input::Ili1Input ili1input;
   ili1input.visit(ili1d);

}

antlrcpp::Any Ili1Input::visitInterlis1Def(Ili1Parser::Interlis1DefContext *ctx)
{

   /*
   interlis1Def
   : TRANSFER transfername=NAME SEMI
     domainDefs?
     derivatives?
     modelDef
     view*
     formatEncoding
     EOF
   ;
   */
  
   debug(ctx,">>> visitInterlis1Def()");
   Log.incNestLevel();

   if (ctx->domainDefs() != nullptr) {      
      visitDomainDefs(ctx->domainDefs());
   }

   if (ctx->derivatives() != nullptr) {      
      visitDerivatives(ctx->derivatives());
   }

   Model *m = visitModelDef(ctx->modelDef());
   m->ili1Format = visitFormatEncoding(ctx->formatEncoding());
   m->ili1Transfername = ctx->transfername->getText();
   
   for (auto vctx : ctx->view()) {
      visitView(vctx); // to do !!!
   }
   
   Log.decNestLevel();
   debug(ctx,"<<< visitInterlis1Def()");

   return nullptr;
  
}

antlrcpp::Any Ili1Input::visitDerivatives(Ili1Parser::DerivativesContext *ctx)
{

   /* derivatives
   : DERIVATIVES derivativename1=NAME
     domainDefs?
     topicDef+
     END derivativename2=NAME
   */

   string name1 = ctx->derivativename1->getText();
   string name2 = ctx->derivativename2->getText();
   debug(ctx,">>> visitDerivatives(" + name1 + ")");
   Log.incNestLevel();
   
   if (name1 != name2) {
      Log.error(
         name2 + " must match " + name1,
         ctx->derivativename2->getLine()
      );
   }
   
   if (ctx->domainDefs() != nullptr) {
      visitDomainDefs(ctx->domainDefs());
   }
   
   for (auto tctx : ctx->topicDef()) {
      visitTopicDef(tctx);
   }      
   
   Log.decNestLevel();
   debug(ctx,"<<< visitDerivatives(" + name1 + ")");

   return nullptr;

}

antlrcpp::Any Ili1Input::visitView(Ili1Parser::ViewContext *ctx)
{

   /*
   class View : public Class {
   public:
      enum {Projection, Join, Union,
            Aggregation_All, Aggregation_Equal,
            Inspection_Normal, Inspection_Area} FormationKind;

      list<Expression *> FormationParameter; // PathOrInspFactor only
                          // Aggr.Equal: UniqueEl
                          // Inspection: Attributepath
      Expression *Where;
      bool Transient = false;
      // role from ASSOCIATION BaseViewDef
      // list<RenamedBaseView *> RenamedBaseView;
      // role from ASSOCIATION DerivedAssoc
      list <Class *> DeriAssoc;
      virtual string getClass() { return "View"; }
   };
   */

   /* view
   : VIEW
     modelname1=NAME (
        topicname=NAME DOT tablename=NAME COLON
        viewDef (COMMA viewDef)* SEMI
     )*
     END
     modelname2=NAME
     DOT
   */

   string name1 = ctx->modelname1->getText();
   string name2 = ctx->modelname2->getText();
   debug(ctx,">>> visitView(" + name1 + ")");
   Log.incNestLevel();
   
   if (name1 != name2) {
      Log.error(
         name2 + " must match " + name1,
         ctx->modelname2->getLine()
      );
   }
   
   if (find_model(name1,get_line(ctx->modelname1)) == nullptr) {
      Log.error(
         "base model " + name1 + " unknown",
         ctx->modelname1->getLine()
      );
   }
   
   View *v = new View();
   init_class(v,ctx->start->getLine());
   string reftable = get_package_context()->Name + "." + ctx->topicname->getText() + "." + ctx->tablename->getText();
   Class *t = find_class(reftable,get_line(ctx));
   if (t == nullptr) {
      Log.error(
         "referenced table " + reftable + " not found",
         ctx->tablename->getLine()
      );
   }
   // assign t, to do !!!

   init_class(v,ctx->tablename->getLine());
   push_context(v);
   
   for (auto vctx : ctx->viewDef()) {
      visitViewDef(vctx);
   }
   
   Log.decNestLevel();
   debug(ctx,"<<< visitView(" + name1 + ")");
   
   return v;
   
}

antlrcpp::Any Ili1Input::visitViewDef(Ili1Parser::ViewDefContext *ctx)
{

   /* viewDef
   : VERTEXINFO vertexinfo=NAME explanation=EXPLANATION
   | WITH PERIPHERY periphery=NAME
   | CONTOUR contour=NAME ( WITH PERIPHERY )?
   | LARROW table=NAME DOT attr=NAME
   */

   debug(ctx,">>> visitViewDef()");
   Log.incNestLevel();

   if (ctx->VERTEXINFO() != nullptr) {
      string vertexinfo = ctx->vertexinfo->getText();
      string explanation = ctx->explanation->getText();
      // to do !!!
   }
   else if (ctx->CONTOUR() != nullptr) {
      string contour = ctx->periphery->getText();
      bool periphery = false;
      if (ctx->PERIPHERY() != nullptr) {
         periphery = true;
      }
      // to do !!!
   }
   else if (ctx->PERIPHERY() != nullptr) {
      string periphery = ctx->periphery->getText();
      // to do !!!
   }
   else { // LARROW
      string attrref = get_path(get_package_context()) + "." + ctx->table->getText() + "." + ctx->attr->getText();
      // to do !!!
   }

   Log.decNestLevel();
   debug(ctx,"<<< visitViewDef()");

   // to do !!!
   return nullptr;

}

antlrcpp::Any Ili1Input::visitFormatEncoding(Ili1Parser::FormatEncodingContext *ctx)
{

   /*
   struct Ili1Format : public MMObject {
   public:
      bool isFree = false;
      int LineSize = 80;
      int tidSize = 10;
      char blankCode = ' ';
      char undefinedCode = '@';
      char continueCode = '\\';
      string Font = "";
      enum { TID_I16, TID_I32, TID_ANY, TID_EXPLANATION } tidKind = TID_ANY;
      string tidExplanation = ""; // defined when tidKind == TID_EXPLANATION
   };
   */

   /* formatEncoding
   : FORMAT 
   (
     FREE
   | FIX WITH
     LINESIZE EQUAL lineSize = POSNUMBER COMMA
     TIDSIZE EQUAL tidSize = POSNUMBER
   )
   SEMI
   font?
   BLANK EQUAL ( DEFAULT | blankcode=code) COMMA
   UNDEFINED EQUAL (DEFAULT | undefinedcode=code) COMMA
   CONTINUE EQUAL (DEFAULT | continuecode=code) SEMI
   TID EQUAL (I16 | I32 | ANY | EXPLANATION) SEMI
   END DOT
   */
   
   debug(ctx,">>> visitFormatEncoding()");
   Log.incNestLevel();
   
   Ili1Format *f = new Ili1Format();
   
   if (ctx->FREE() != nullptr) {
      init_mmobject(f,ctx->FREE()->getSymbol()->getLine());
      f->isFree = true;
   }
   if (ctx->FIX() != nullptr) {
      init_mmobject(f,ctx->FIX()->getSymbol()->getLine());
      f->LineSize = atoi(ctx->lineSize->getText().c_str());
      f->tidSize = atoi(ctx->tidSize->getText().c_str());
   }

   // to do !!!
   //f->Font = visitFont(ctx->font());

   f->blankCode = 99; // DEFAULT
   if (ctx->blankcode != nullptr) {
      int code = visitCode(ctx->blankcode);
      f->blankCode = code;
   }
   f->undefinedCode = 99; // DEFAULT
   if (ctx->undefinedcode != nullptr) {
      int code = visitCode(ctx->undefinedcode);
      f->undefinedCode = code;
   }
   f->continueCode = 99; // DEFAULT
   if (ctx->continuecode != nullptr) {
      int code = visitCode(ctx->continuecode);
      f->continueCode = code;
   }

   if (ctx->I16() != nullptr) {
      f->tidKind = Ili1Format::TID_I16;
   }
   else if (ctx->I32() != nullptr) {
      f->tidKind = Ili1Format::TID_I32;
   }
   else if (ctx->ANY() != nullptr) {
      f->tidKind = Ili1Format::TID_ANY;
   }
   else { // EXPLANATION
      f->tidKind = Ili1Format::TID_EXPLANATION;
      f->tidExplanation = ctx->EXPLANATION()->getSymbol()->getText();
   }
   
   Log.decNestLevel();
   debug(ctx,"<<< visitFormatEncoding()");

   return f;

}

antlrcpp::Any Ili1Input::visitFont(Ili1Parser::FontContext *ctx)
{

   /* font
   : FONT EQUAL expl=EXPLANATION SEMI
   */
   
   debug(ctx,">>> visitFont()");
   string value = ctx->expl->getText();
   debug(ctx,"<<< visitFont(" + value + ")");

}

antlrcpp::Any Ili1Input::visitCode(Ili1Parser::CodeContext *ctx)
{

   /* code
   : POSNUMBER
   | HEXNUMBER
   */

   debug(ctx,">>> visitCode()");
   
   int code;

   if (ctx->POSNUMBER() != nullptr) {
      code = atoi(ctx->POSNUMBER()->getSymbol()->getText().c_str());
   }
   else {
      code = 99; // to do !!!
      //return (char)hextoi(ctx->HEXNUMBER()->getSymbol()->getText().c_str());
   }

   debug(ctx,"<<< visitCode(" + to_string(code) + ")");
   
   return code;

}
