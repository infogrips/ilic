#pragma once

#include <string>
#include <vector>
#include <map>
#include "antlr4-runtime.h"
#include "MetaModel.h"

using namespace std;

namespace metamodel {

   // helper functions for interlis 1 / 2 input modules
   extern bool ili23;
   extern bool ili24;
   extern string iliversion;

   // mmobject helpers
   void init_mmobject(MMObject *o, int line);
   
   // metaelement helpers
   void init_metaelement(MetaElement *e, int line);
   void init_extendableme(ExtendableME *e, int line);

   // context helpers
   void push_context(MetaElement *p);
   MetaElement* get_context();
   Class* get_class_context();
   Package* get_package_context();
   void pop_context();

   // package helpers
   void init_package(Package *p, int line);

   // Model helpers
   Model *find_model(string name,int line);

   // Topic / DataUnit helpers
   void add_dataunit(DataUnit* u);
   DataUnit* find_dataunit(string name,int line);
   void add_package(Package* p);
   Package* find_package(string name,int line);

   // Unit helpers
   void add_unit(Unit *u);
   Unit* find_unit(string name,int line);
   
   // Type helpers
   void init_type(Type *t, int line);
   void add_type(Type *t);
   Type* find_type(string name,int line);
   void init_domaintype(DomainType *t, int line);
   DomainType* find_domaintype(string name,int line);
   
   // Class helpers
   void init_class(Class *c,int line);
   void add_class(Class *c);
   Class* find_class(string name,int line);
   Class* find_class(Package *p,string name,int line);
   Class* find_structure(string name,int line );
   Class* find_structure(Package *p,string name,int line);
   View* find_view(string name, int line);
   Class* find_association(string name,int line);
   Class* find_association(Package *p,string name,int line);
   AttrOrParam* find_attribute(Class *c,string name,int line);
   
   // Function helpers
   void init_function(FunctionDef *f, int line);
   void add_function(FunctionDef *function);
   FunctionDef* find_function(string name,int line);

   // Expression helpers
   void init_expression(Expression *e, int line);
   void init_factor(Factor *f, int line);
   
   // Constraint helpers
   void init_constraint(Constraint *c, int line);
   
   // other helpers
   Type* any_to_type(antlrcpp::Any any);
   DomainType* any_to_domaintype(antlrcpp::Any any);
   int get_line(antlr4::ParserRuleContext *ctx);
   int get_line(antlr4::Token *token);
   int get_line(antlr4::tree::TerminalNode* node);

}