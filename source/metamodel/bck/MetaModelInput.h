#pragma once

#include <string>
#include <vector>
#include <map>
#include "antlr4-runtime.h"
#include "MetaModel.h"

using namespace std;

namespace metamodel {

   // helper functions for interlis 1 / 2 input modules
   extern string iliversion;

   // mmobject helpers
   void init_mmobject(MMObject *o, int line);
   
   // metaelement helpers
   void init_metaelement(MetaElement *e, int line);
   void init_extendableme(ExtendableME *e, int line);

   // package helpers
   void init_package(Package *p, int line);

   // Model helpers
   Model *find_model(string name);

   // Topic / DataUnit helpers
   void add_dataunit(DataUnit *u);
   DataUnit* find_dataunit(MMObject *o,string name);

   // Unit helpers

   void add_unit(Unit *u);
   Unit* find_unit(MMObject *context,string name);
   
   // Type helpers
   void init_type(Type *t, int line);

   // DomainType helpers
   void init_domaintype(Type *t, int line);
   void add_domain_type(DomainType *domaintype);
   DomainType* find_domain_type(MMObject *o,string name);
   
   // model helpers
   void add_model(Model *model);
   list <Model *> get_all_models();
   void add_import(Import *import);
   list <Import *> get_all_imports();

   // context helpers
   void push_package_context(Package *p);
   Package* get_package_context();
   void pop_package_context();
   void set_class_context(Class *c);
   Class* get_class_context();
   void set_attrorparam_context(AttrOrParam *a);
   AttrOrParam* get_attrorparam_context();

   // Class helpers
   void init_class(Class *c,int line);
   void add_class(Class *c);
   Class* find_class(MMObject *o, string name);
   Class* find_structure(MMObject *o, string name);
   Class* find_association(MMObject *o, string name);
   
   // DomainType helpers
   void init_function(FunctionDef *f, int line);
   void add_function(FunctionDef *function);
   FunctionDef* find_function(MMObject *o,string name);

   // Expression helpers
   void init_expression(Expression *e, int line);
   void init_factor(Factor *f, int line);
   
   // other helpers
   DomainType* any_to_domaintype(antlrcpp::Any any);
 
}