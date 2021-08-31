#include "MetaModelInput.h"
#include "InterlisModel.h"
#include "../util/Logger.h"

using namespace util;
using namespace metamodel;

namespace metamodel {

   // golbal variables
   
   string iliversion;

   static list <DataUnit *> AllDataUnits;
   static list <Class *> AllClasses;
   static list <Unit *> AllUnits;
   static list <DomainType *> AllDomainTypes;
   static list <Import *> AllImports;
   static list <FunctionDef *> AllFunctions;

   static list <Package *> package_context;
   static Class *class_context;
   
   // model helpers
   
   void add_model(Model *model)
   {
      if (model == nullptr) {
         return;
      }
      for (Package *m : get_all_models()) {
         if (m->Name == model->Name) {
            // add model only once
            return;
         }
      }
      get_all_models().push_back(model);
   }

   void add_import(Import *import)
   {
      if (import == nullptr) {
         return;
      }
      get_all_imports().push_back(import);
   }
   
   // context helpers

   void push_package_context(Package *p)
   {
      package_context.push_back(p);
   }

   Package* get_package_context()
   {
      return package_context.back();
   }

   void pop_package_context()
   {
      package_context.pop_back();
   }

   void set_class_context(Class *c)
   {
      class_context = c;
   }

   Class* get_class_context()
   {
      return class_context;
   }
   
   // mmobject helpers

   void init_mmobject(MMObject *o, int line)
   {
      o->_line = line;
   }
   
   // metaelement helpers

   void init_metaelement(MetaElement *e, int line)
   {
      // list <DocText> Documentation;
      // ROLE from ASSOCIATION MetaAttributes
      // list <MetaAttribute *> MetaAttribute;
      init_mmobject(e,line);
   }

   void init_extendableme(ExtendableME *e, int line)
   {
      init_metaelement(e,line);
      // bool Abstract;
      // bool Final;
      // ROLE from ASSOCIATION Inheritance
      // ExtendableME *Super;
      // ROLE from ASSOCIATION Inheritance
      // list <ExtendableME *> Sub;
   }

   // package helpers

   void init_package(Package *p, int line)
   {
      init_metaelement(p,line);
      // ROLE from ASSOCIATION PackageElements
      // list <MetaElement *> Element;
   }

   // Model helpers

   Model *find_model(string name)
   {

      if (name == "INTERLIS") {
         return metamodel::INTERLIS;
      }

      for (Model *m : get_all_models()) {
         if (m->Name == name) {
            return m;
         }
      }

      Log.error("model " + name + " not found.");
      return nullptr;

   }

   // Topic / DataUnit helpers
   
   void add_dataunit(DataUnit *u)
   {
      if (u == nullptr) {
         return;
      }
      for (DataUnit *uu : AllDataUnits) {
         if (uu->Name == u->ElementInPackage->Name) {
            Log.error("multiple declaration of topic " + u->ElementInPackage->Name,u->_line);
            return;
         }
      }
		Log.debug(">>> add_dataunit " + u->Name + " (" + get_path(u) + ")");
      AllDataUnits.push_back(u);
   }
   
   DataUnit* find_dataunit(MMObject *o,string name)
   {
		Log.debug(">>> find_dataunit " + name);
      for (DataUnit *u : AllDataUnits) {
         if (get_path(u) == (name + ".BASKET")) {
            return u;
         }
      }
      Log.error("unknown topic " + name,o->_line);
      return nullptr;
   }

   // Unit helpers

   void add_unit(Unit *u) 
   {
      if (u == nullptr) {
         return;
      }
      for (Unit *uu : AllUnits) {
         if (uu->Name == u->Name) {
            Log.error("multiple declaration of unit " + u->Name,u->_line);
            return;
         }
      }
      AllUnits.push_back(u);
   }

   Unit* find_unit(MMObject *context,string name)
   {
      for (Unit *u : AllUnits) {
         if (u->Name == name) {
            return u;
         }
      }
      Log.error("unknown unit " + name,context->_line);
      return nullptr;
   }
   
   // Type helpers

   void init_type(Type *t, int line)
   {
      init_extendableme(t, line);
      // FunctionDef *LFTParent;
   }

   // DomainType helpers

   void init_domaintype(Type *t, int line)
   {
      init_type(t,line);
      // FunctionDef *LFTParent;
   }

   void add_domain_type(DomainType *domaintype)
   {
      if (domaintype == nullptr) {
         return;
      }
		Log.debug(">>> add_domain_type " + domaintype->Name + "(" + get_path(domaintype) + ")");
      for (DomainType *t : AllDomainTypes) {
         if (t->Name == domaintype->Name) {
            // add domain type only once
            return;
         }
      }
      AllDomainTypes.push_back(domaintype);
   }

   DomainType* find_domain_type(MMObject *o,string name)
   {

		Log.debug(">>> find_domain_type " + name);

      for (DomainType *t : AllDomainTypes) {
			Log.debug(get_path(t));
         if (get_path(t) == name) {
            return t;
         }
         else if (get_path(t) == get_parent_path(t) + "." + name) {
            return t;
         }
      }

      Log.error("domaintype " + name + " not found.",o->_line);
      return nullptr;

   }
   
   // Class helpers

   void init_class(Class *c,int line)
   {
      init_type(c, line);
   }

   void add_class(Class *c)
   {
      if (c == nullptr) {
         return;
      }
      for (Class *cc : AllClasses) {
         if (get_path(cc) == get_path(c)) {
            Log.error("multiple declaration of class " + c->Name,c->_line);
            return;
         }
      }
      AllClasses.push_back(c);
   }

   static Class* find_class_object(MMObject *o, string name, int kind)
   {
      for (Class *c : AllClasses) {
         if (c->Kind != kind) {
            continue;
         }
         if (get_path(c) == name) {
            return c;
         }
         else if (get_path(c) == get_parent_path(c) + "." + name) {
            return c;
         }
      }
      return nullptr;
   }

   Class* find_class(MMObject *o, string name)
   {
      Class *c = find_class_object(o,name,Class::ClassVal);
      if (c == nullptr) {
         Log.error("class " + name + " not found",o->_line);
      }
      return c;
   }
   
   Class* find_structure(MMObject *o, string name)
   {
      Class *s = find_class_object(o,name,Class::Structure);
      if (s == nullptr) {
         Log.error("structure " + name + " not found",o->_line);
      }
      return s;
   }

   Class* find_association(MMObject *o, string name)
   {
      Class *a = find_class_object(o,name,Class::Association);
      if (a == nullptr) {
         Log.error("association " + name + "not found",o->_line);
      }
      return a;
   }

   // expression helpers

   void init_expression(Expression *e, int line)
   {
      init_mmobject(e,line);
   }

   void init_factor(Factor *f, int line)
   {
      init_expression(f,line);
   }

   // function helpers

   void init_function(FunctionDef *f, int line)
   {
      init_metaelement(f,line);
   }

   void add_function(FunctionDef *function)
   {
      if (function == nullptr) {
         return;
      }
		Log.debug(">>> add_function " + function->Name + "(" + get_path(function) + ")");
      for (FunctionDef *f : AllFunctions) {
         if (f->Name == function->Name) {
            // add domain type only once
            return;
         }
      }
      AllFunctions.push_back(function);
   }

   FunctionDef* find_function(MMObject *o,string name)
   {

		Log.debug(">>> find_function " + name);

      for (FunctionDef *f : AllFunctions) {
         if (get_path(f) == name) {
            return f;
         }
         else if (get_path(f) == get_parent_path(f) + "." + name) {
            return f;
         }
      }

      Log.error("function " + name + " not found.",o->_line);
      return nullptr;

   }
   
   // other helpers
   
   DomainType* any_to_domaintype(antlrcpp::Any any) 
   {
      
      Log.debug(">>> any_to_domaintype()");
      DomainType *t;

      try {
         t = any.as<TextType *>();
         Log.debug(">>> class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }
      
      try {
         t = any.as<NumType *>();
         Log.debug(">>> class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }
      
      try {
         t = any.as<BooleanType *>();
         Log.debug(">>> class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }

      try {
         t = any.as<EnumType *>();
         Log.debug(">>> class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }

      try {
         t = any.as<CoordType *>();
         Log.debug(">>> class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }

      try {
         t = any.as<BlackboxType *>();
         Log.debug(">>> class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }

      try {
         t = any.as<AnyOIDType *>();
         Log.debug(">>> class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }

      try {
         t = any.as<LineType *>();
         Log.debug(">>> class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }

      try {
         t = any.as<DomainType *>();
         Log.debug(">>> class=" + t->getClass());
         return nullptr;
      }
      catch (exception e) {
      }

      Log.error("any_to_type: unsupported type");
      return nullptr;

   }
      
}
