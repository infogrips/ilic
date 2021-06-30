#include "MetaModelOutput.h"
#include "../util/Logger.h"

using namespace util;
using namespace metamodel;

namespace metamodel {

int count_metaelement(list <MetaElement*> l, string class_name)
{
   int count = 0;
   for (auto e : l) {
      if (e->isSubClassOf(class_name)) {
         count++;
      }
   }
   return count;
}

void write_expression(TextWriter *tw,Expression *e)
{

   if (e->getClass() == "Constant") {
      Constant *c = dynamic_cast<Constant *>(e);
      tw->write(0,c->Value);
   }
   else if (e->getClass() == "PathOrInspFactor") {
      PathOrInspFactor *f = dynamic_cast<PathOrInspFactor *>(e);
      tw->write(0,e->getClass()); // to do !!!
   }
   else if (e->getClass() == "EnumMapping") {
      EnumMapping *m = dynamic_cast<EnumMapping *>(e);
      tw->write(0,e->getClass()); // to do !!!
   }
   else if (e->getClass() == "FunctionCall") {
      FunctionCall *c = dynamic_cast<FunctionCall *>(e);
      tw->write(0, c->Function->Name);
      tw->write(0, "(");
      bool comma = false;
      for (auto a : c->Arguments) {
         if (comma) {
            tw->write(0, ",");
         }
         if (a->Expression != nullptr) {
            write_expression(tw,a->Expression);
         }
         comma = true;
      }
      tw->write(0, ")");
   }
   else if (e->getClass() == "RuntimeParamRef") {
      RuntimeParamRef *r = dynamic_cast<RuntimeParamRef *>(e);
      tw->write(0,r->RuntimeParam->Name);
   }
   else if (e->getClass() == "ClassConst") {
      ClassConst *c = dynamic_cast<ClassConst *>(e);
      tw->write(0, "#"); // ???
      tw->write(0,c->Class->Name);
   }
   else if (e->getClass() == "AttributeConst") {
      AttributeConst *c = dynamic_cast<AttributeConst *>(e);
      tw->write(0, "#"); // ???
      tw->write(0,c->Attribute->Name);
   }
   else if (e->getClass() == "UnitRef") {
      UnitRef *r = dynamic_cast<UnitRef *>(e);
      tw->write(0,r->Unit->Name);
   }
   else if (e->getClass() == "UnitFunction") {
      UnitFunction *f = dynamic_cast<UnitFunction *>(e);
      tw->write(0,e->getClass()); // to do !!!
   }
   else if (e->getClass() == "UnaryExpr") {
      UnaryExpr *e = dynamic_cast<UnaryExpr *>(e);
      write_expression(tw,e->SubExpression);
   }
   else if (e->getClass() == "CompoundExpr") {
      CompoundExpr *c = dynamic_cast<CompoundExpr *>(e);
      bool first = true;
      for (auto s : c->SubExpressions) {
         if (!first) {
            if (c->Operation == CompoundExpr_OperationType::Mult) {
               tw->write(0,"*");
            }
            else {
               tw->write(0,"/");
            }
         }
         write_expression(tw,s);
         first = false;
      }
   }
   else {
      Log.internal_error("write_expression: " + e->getClass() + " unknown",1);
   }

}

static void write_enumnode(TextWriter* tw, EnumNode* n)
{
   tw->write(n->Name);
   tw->incNestLevel();
   bool comma = false;
   for (auto nn : n->Node) {
      if (comma) {
         tw->writeln(0, ",");
      }
      else {
         tw->writeln(0, " (");
      }
      write_enumnode(tw,nn);
      comma = true;
   }
   tw->decNestLevel();
   if (comma) {
      tw->writeln(")");
   }
}

void write_enumtype(TextWriter *tw,EnumType *t) 
{
   tw->writeln(0, "(");
   tw->incNestLevel();
   bool comma = false;
   for (auto n : t->TopNode) {
      if (comma) {
         tw->writeln(0, ",");
      }
      write_enumnode(tw,n);
      comma = true;
   }
   tw->writeln(0,"");
   tw->decNestLevel();
   tw->write(")");
}

} // namespace metamodel

