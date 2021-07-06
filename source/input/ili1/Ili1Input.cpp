#include "Ili1Input.h"
#include "../parser/IliParserErrorListener.h"
#include "../parser/generated/Ili1Lexer.cpp"
#include "../parser/generated/Ili1Parser.cpp"
#include "../../metamodel/MetaModelInput.h"
#include "../../util/Logger.h"

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
   
   Log.debug("visitDecimal()");

   if (ctx->DEC() != nullptr) {
      return ctx->DEC()->getText();
   }
   else if (ctx->POSNUMBER() != nullptr) {
      return ctx->POSNUMBER()->getText();
   }
   else {
      return ctx->NUMBER()->getText();
   }

   return nullptr;

}

void input::parseIli1(string input)
{

   // open input
   ifstream stream;
   stream.open(input);
   antlr4::ANTLRInputStream inputstream(stream);

   Log.debug("creating ili1 lexer ...");
   lexer::Ili1Lexer ili1lexer(&inputstream);
   antlr4::CommonTokenStream tokens(&ili1lexer);

   Log.debug("creating ili1 parser ...");
   parser::Ili1Parser ili1parser(&tokens);
   ili1parser.removeErrorListeners();
   ili1parser.addErrorListener(new parser::IliParserErrorListener());
   parser::Ili1Parser::Interlis1DefContext *ili1d = ili1parser.interlis1Def();

   Log.debug("ili1 building meta model ...");
   input::Ili1Input ili1input;
   ili1input.visit(ili1d);

   stream.close();

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
  
   Log.debug("visitInterlis1Def()");

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
   Log.debug("visitDerivatives(" + name1 + ")");
   
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
   
   return nullptr; // ???, to do !!!

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
   Log.debug("visitView(" + name1 + ")");
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

   Log.debug("visitViewDef()");

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
   
   Log.debug("visitFormat()");
   
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

   if (ctx->blankcode != nullptr) {
      f->blankCode = visitCode(ctx->blankcode);
   }
   if (ctx->undefinedcode != nullptr) {
      f->undefinedCode = visitCode(ctx->undefinedcode);
   }
   if (ctx->continuecode != nullptr) {
      f->continueCode = visitCode(ctx->continuecode);
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
   
   return f;

}

antlrcpp::Any Ili1Input::visitFont(Ili1Parser::FontContext *ctx)
{

   /* font
   : FONT EQUAL expl=EXPLANATION SEMI
   */
   
   Log.debug("visitFont()");
   
   return ctx->expl->getText();

}

antlrcpp::Any Ili1Input::visitCode(Ili1Parser::CodeContext *ctx)
{

   /* code
   : POSNUMBER
   | HEXNUMBER
   */

   Log.debug("visitCode()");

   if (ctx->POSNUMBER() != nullptr) {
      return atoi(ctx->POSNUMBER()->getSymbol()->getText().c_str());
   }
   else {
      return 99; // to do !!!
      //return (char)hextoi(ctx->HEXNUMBER()->getSymbol()->getText().c_str());
   }

   return nullptr;

}
