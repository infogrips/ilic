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
   Model *find_model(string name);

   // Topic / DataUnit helpers
   void add_dataunit(DataUnit* u);
   DataUnit* find_dataunit(string name);
   void add_package(Package* p);
   Package* find_package(string name);

   // Unit helpers
   void add_unit(Unit *u);
   Unit* find_unit(string name);
   
   // Type helpers
   void init_type(Type *t, int line);
   void add_type(Type *t);
   Type* find_type(string name);
   void init_domaintype(DomainType *t, int line);
   DomainType* find_domaintype(string name);
   
   // Class helpers
   void init_class(Class *c,int line);
   void add_class(Class *c);
   Class* find_class(string name);
   Class* find_class(Package *p,string name);
   Class* find_structure(string name);
   Class* find_structure(Package *p,string name);
   Class* find_association(string name);
   Class* find_association(Package *p,string name);
   AttrOrParam* find_attribute(Class *c,string name);
   
   // Function helpers
   void init_function(FunctionDef *f, int line);
   void add_function(FunctionDef *function);
   FunctionDef* find_function(string name);

   // Expression helpers
   void init_expression(Expression *e, int line);
   void init_factor(Factor *f, int line);
   
   // Constraint helpers
   void init_constraint(Constraint *c, int line);
   
   // other helpers
   Type* any_to_type(antlrcpp::Any any);
   DomainType* any_to_domaintype(antlrcpp::Any any);
 
}