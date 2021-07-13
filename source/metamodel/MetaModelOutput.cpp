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

   if (e == nullptr) {
      return; // shound not be null (ie. functions), to do !!!
   }

   Log.debug(">>> write_expression " + e->getClass());
   Log.incNestLevel();

   if (e->getClass() == "Constant") {
      /* struct Constant : public Factor {
      public:
         string Value;
         enum {Undefined, Numeric, Text, Enumeration} Kind;
      */
      Constant *c = dynamic_cast<Constant *>(e);
      switch (c->Kind) {
         case Constant::Undefined:
            break;
         case Constant::Numeric:
            break;
         case Constant::Text:
            tw->write(0,"\"");
            break;
         case Constant::Enumeration:
            tw->write(0,"#");
            break;
         default:
            Log.internal_error("write_constantexpression(): unknown Kind id " + to_string(c->Kind));
            break;
      }
      tw->write(0,c->Value);
      if (c->Kind == Constant::Text) {
         tw->write(0,"\"");
      }
   }
   else if (e->getClass() == "PathOrInspFactor") {
      /* ExistenceDef : public PathOrInspFactor {
      public:
         Class *Viewable = nullptr;
      */
      PathOrInspFactor *f = dynamic_cast<PathOrInspFactor *>(e);
      tw->write(0,e->getClass()); // to do !!!
   }
   else if (e->getClass() == "EnumMapping") {
      /* struct EnumMapping : public Factor {
      public:
         PathOrInspFactor *EnumValue = nullptr;
         list <EnumAssignment *> Cases; // LIST
      */
      EnumMapping *m = dynamic_cast<EnumMapping *>(e);
      tw->write(0,e->getClass()); // to do !!!
   }
   else if (e->getClass() == "FunctionCall") {
      /* struct FunctionCall : public Factor {
      public:
         FunctionDef *Function = nullptr;
         list <ActualArgument *> Arguments; // LIST
      */
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
      /* struct RuntimeParamRef : public Factor {
      public:
         AttrOrParam *RuntimeParam = nullptr;
      */
      RuntimeParamRef *r = dynamic_cast<RuntimeParamRef *>(e);
      tw->write(0,r->RuntimeParam->Name);
   }
   else if (e->getClass() == "ClassConst") {
      /* struct ClassConst : public Factor {
      public:
         Class *Class = nullptr;
      */
      ClassConst *c = dynamic_cast<ClassConst *>(e);
      tw->write(0, "#"); // ???
      tw->write(0,c->Class->Name);
   }
   else if (e->getClass() == "AttributeConst") {
      /* struct AttributeConst : public Factor {
      public:
         AttrOrParam *Attribute = nullptr;
      */
      AttributeConst *c = dynamic_cast<AttributeConst *>(e);
      tw->write(0, "#"); // ???
      tw->write(0,c->Attribute->Name);
   }
   else if (e->getClass() == "UnitRef") {
      /* struct UnitRef : public Factor {
      public:
         Unit *Unit = nullptr;
      */
      UnitRef *r = dynamic_cast<UnitRef *>(e);
      tw->write(0,r->Unit->Name);
   }
   else if (e->getClass() == "UnitFunction") {
      /* struct UnitFunction : public Factor {
      public:
         string Explanation;
      */
      UnitFunction *f = dynamic_cast<UnitFunction *>(e);
      tw->write(0,f->getClass()); // to do !!
      if (f->Explanation != "") {
         tw->write(0," // " + f->Explanation + " //");
      }
   }
   else if (e->getClass() == "UnaryExpr") {
      /*
      struct UnaryExpr : public Expression {
      public:
         enum {Not, Defined} Operation;
         Expression *SubExpression = nullptr;
      */
      UnaryExpr *e = dynamic_cast<UnaryExpr *>(e);
      switch (e->Operation) {
         case UnaryExpr::Not:
            tw->write(0,"not(");
            break;
         case UnaryExpr::Defined:
            tw->write(0,"defined(");
            break;
         default:
            Log.internal_error("write_unaryexpression(): unknown Operation id " + to_string(e->Operation));
            break;
      }
      if (e->SubExpression != nullptr) {
         write_expression(tw,e->SubExpression);
      }
      tw->write(0,")");
   }
   else if (e->getClass() == "CompoundExpr") {
      /* enum CompoundExpr_OperationType {
         Implication, And, Or, Mult, Div, // 2.4
         Relation_Equal, Relation_NotEqual,
         Relation_LessOrEqual, Relation_GreaterOrEqual,
         Relation_Less, Relation_Greater
      */
      /* struct CompoundExpr : public Expression {
      public:
         CompoundExpr_OperationType Operation = Relation_Equal;
         list <Expression *> SubExpressions; // LIST
      */
      CompoundExpr *c = dynamic_cast<CompoundExpr *>(e);
      bool first = true;
      for (auto s : c->SubExpressions) {
         if (!first) {
            switch (c->Operation) {
               case CompoundExpr_OperationType::Implication:
                  tw->write(0," -> ");
                  break;
               case CompoundExpr_OperationType::And:
                  tw->write(0," and ");
                  break;
               case CompoundExpr_OperationType::Or:
                  tw->write(0," or ");
                  break;
               case CompoundExpr_OperationType::Mult:
                  tw->write(0," * ");
                  break;
               case CompoundExpr_OperationType::Div:
                  tw->write(0," / ");
                  break;
               case CompoundExpr_OperationType::Relation_Equal:
                  tw->write(0," == ");
                  break;
               case CompoundExpr_OperationType::Relation_NotEqual:
                  tw->write(0," != ");
                  break;
               case CompoundExpr_OperationType::Relation_LessOrEqual:
                  tw->write(0," <= ");
                  break;
               case CompoundExpr_OperationType::Relation_GreaterOrEqual:
                  tw->write(0," >= ");
                  break;
               case CompoundExpr_OperationType::Relation_Less:
                  tw->write(0," < ");
                  break;
               case CompoundExpr_OperationType::Relation_Greater:
                  tw->write(0," > ");
                  break;
               default:
                  Log.internal_error("write_compoundexpr(): unknowwn Operation id " + to_string(c->Operation));
            }
         }
         write_expression(tw,s);
         first = false;
      }
   }
   else {
      Log.internal_error("write_expression: " + e->getClass() + " unknown",1);
   }

   Log.decNestLevel();
   Log.debug("<<< write_expression " + e->getClass());

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
      tw->writeln(0,"");
      tw->write(")");
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

