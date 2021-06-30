#include "MetaModelInput.h"
#include "../util/StringUtil.h"
#include "../util/Logger.h"

using namespace util;
using namespace metamodel;

namespace metamodel {

   // golbal variables
   
   bool ili23 = true;
   bool ili24 = true;
   string iliversion;

   static list <DataUnit*> AllDataUnits;
   static list <Package*> AllPackages;
   static list <Type *> AllTypes;
   static list <Unit *> AllUnits;
   static list <Import *> AllImports;
   static list <FunctionDef *> AllFunctions;
   
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
      /* to do !!!
      e->ElementInPackage = get_package_context();
      if (e->ElementInPackage != nullptr) {
         e->ElementInPackage->Element.push_back(e);
      } */
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
      AllDataUnits.push_back(u);
   }
   
   DataUnit* find_dataunit(string name)
   {
      for (DataUnit *u : AllDataUnits) {
         if (get_path(u) == (name + ".BASKET")) {
            return u;
         }
      }
      Log.error("unknown topic " + name,get_package_context()->_line);
      return nullptr;
   }

   void add_package(Package* p)
   {
      if (p == nullptr) {
         return;
      }
      AllPackages.push_back(p);
   }

   Package* find_package(string name)
   {
      for (Package* p : AllPackages) {
         if (get_path(p) == name) {
            return p;
         }
      }
      Log.error("unknown package " + name, get_package_context()->_line);
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

   Unit* find_unit(string name)
   {
      for (Unit *u : AllUnits) {
         if (u->Name == name) {
            return u;
         }
         else if (u->_unitname == name) {
            return u;
         }
      }
      Log.error("unknown unit " + name,get_package_context()->_line);
      return nullptr;
   }
   
   // Type helpers

   void init_type(Type *t, int line)
   {
      init_extendableme(t, line);
      // FunctionDef *LFTParent;
   }

   void add_type(Type *t)
   {
      if (t == nullptr) {
         return;
      }
		Log.debug("add_type " + t->Name + "(" + get_path(t) + ")");
      for (Type *tt : AllTypes) {
         if (tt->Name == t->Name) {
            // to do !!!
            // Log.error("multiple declarations of " + t->Name,t->_line);
            return;
         }
      }
      AllTypes.push_back(t);
   }

   Type* find_type(string name)
   {

      string search;
      if (util::starts_with(name,"ILIC_")) {
         search = name.substr(5);
      }
      else {
         search = name;
      }

		Log.debug("find_type <" + search + ">");

      for (Type *t : AllTypes) {
         if (get_path(t) == search) {
            return t;
         }
         else if (get_path(t) == get_parent_path(t) + "." + search) {
            return t;
         }
         else if (get_path(t) == get_path(get_context()) + "." + search) {
            return t;
         }
      }

      Log.error("type " + search + " not found.",get_package_context()->_line);
      return nullptr;

   }
   
   void init_domaintype(DomainType *t, int line)
   {
      init_type(t, line);
   }

   DomainType* find_domaintype(string name)
   {
      Type *t = find_type(name);
      if (t == nullptr) {
         return nullptr;
      }
      if (t->isSubClassOf("DomainType")) {
         return static_cast<DomainType *>(t);
      }
      else {
         return nullptr;
      }
   }

   // Class helpers

   void init_class(Class *c,int line)
   {
      init_type(c, line);
   }

   void add_class(Class *c)
   {
      add_type(c);
   }

   Class* find_class_object(string name,int kind)
   {

      string kinds;
      if (kind == Class::ClassVal) {
         kinds = "class";
      }
      else if (kind == Class::Structure) {
         kinds = "structure";
      }
      else if (kind == Class::Association) {
         kinds = "association";
      }

      Type *t = find_type(name);
      if (t == nullptr) {
         Log.error(kinds + " " + name + " not found",get_package_context()->_line);
         return nullptr;
      }
      
      if (t->getClass() != "Class") {
         Log.error(name + " is no " + kinds);
         return nullptr;
      }

      Class *c = static_cast<Class *>(t);
      if (c->Kind != kind) {
         Log.error(name + " is no " + kinds);
         return nullptr;
      }

      return c;

   }
      
   Class* find_class(string name)
   {
      Class *c;
      if (name == "ANYCLASS" || name == "INTERLIS.ANYCLASS" || name == "CLASS" || name == "INTERLIS.CLASS") {
         // singelton, to do !!!
         c = new Class();
         c->Name = name;
         c->Kind = Class::ClassVal;
      }
      else if (name == "ANYSTRUCTURE" || name == "INTERLIS.ANYSTRUCTURE" || name == "STRUCTURE" || name == "INTERLIS.STRUCTURE") {
         // singelton, to do !!!
         c = new Class();
         c->Name = name;
         c->Kind = Class::Structure;
      }
      else {
         c = find_class_object(name,Class::ClassVal);
      }
      return c;
   }
   
   Class* find_class(Package *p,string name)
   {
      if (p == nullptr) {
         return nullptr;
      }
      for (auto e : p->Element) {
         if (e->Name == name && e->getClass() == "Class") {
            Class *c = static_cast<Class *>(e);
            if (c->Kind == Class::ClassVal) {
               return c;
            }
         }
      }
      return nullptr;
   }

   Class* find_structure(string name)
   {
      return find_class_object(name,Class::Structure);
   }

   Class* find_structure(Package *p,string name)
   {
      if (p == nullptr) {
         return nullptr;
      }
      for (auto e : p->Element) {
         if (e->Name == name && e->getClass() == "Class") {
            Class *c = static_cast<Class *>(e);
            if (c->Kind == Class::Structure) {
               return c;
            }
         }
      }
      return nullptr;
   }

   Class* find_association(string name)
   {
      return find_class_object(name,Class::Association);
   }

   Class* find_association(Package *p,string name)
   {
      if (p == nullptr) {
         return nullptr;
      }
      for (auto e : p->Element) {
         if (e->Name == name && e->getClass() == "Class") {
            Class *c = static_cast<Class *>(e);
            if (c->Kind == Class::Association) {
               return c;
            }
         }
      }
      return nullptr;
   }

   AttrOrParam* find_attribute(Class *c,string name)
   {
      if (c == nullptr) {
         return nullptr;
      }
      for (auto a : c->ClassAttribute) {
         if (a->Name == name) {
            return a;
         }
      }
      return nullptr;
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

   FunctionDef* find_function(string name)
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

      Log.error("function " + name + " not found.",get_package_context()->_line);
      return nullptr;

   }
   
   // constraint helpers
   
   void init_constraint(Constraint *c,int line)
   {
      init_metaelement(c,line);
   }
               
   // context helpers
   
   static list<MetaElement *> context;

   void push_context(MetaElement *m)
   {
      Log.debug(">>> push_context " + m->getClass() + ":" + m->Name);
      context.push_back(m);
   }

   MetaElement* get_context()
   {
      return context.back();
   }

   MetaElement * get_context(string classname)
   {
      list<MetaElement *> c;
      c = context;
      while (true) {
         if (c.empty()) {
            break;
         }
         MetaElement *m = c.back();
         if (m->isSubClassOf(classname)) {
            return m;
         }
         c.pop_back();
      }
      return nullptr;
   }

   Class* get_class_context()
   {
      return dynamic_cast<Class *>(get_context("Class"));
   }

   Package* get_package_context()
   {
      return dynamic_cast<Package*>(get_context("Package"));
   }

   void pop_context()
   {
      MetaElement *m = context.back();
      Log.debug("<<< pop_context " + m->getClass() + ":" + m->Name);
      context.pop_back();
   }
   
   // other helpers
   
   Type* any_to_type(antlrcpp::Any any) 
   {
      
      Log.debug(">>> any_to_type()");
      Type *t;

      try {
         t = any.as<TypeRelatedType *>();
         Log.debug(">>> class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }
      
      try {
         t = any.as<ClassRelatedType *>();
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
         t = any.as<TextType *>();
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
         t = any.as<NumType *>();
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
         AnyOIDType *t = any.as<AnyOIDType *>();
         Log.debug(">>> class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }

      try {
         AttributeRefType *t = any.as<AttributeRefType *>();
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
         t = any.as<EnumTreeValueType *>();
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
         t = any.as<Class *>();
         Log.debug(">>> class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }

      try {
         t = any.as<DomainType *>();
         Log.debug(">>> DomainType class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }

      Log.internal_error("any_to_type: unsupported type",1);
      return nullptr;

   }
      
   DomainType* any_to_domaintype(antlrcpp::Any any) 
   {
      Type *t = any_to_type(any);
      try {
         return static_cast<DomainType *>(t);
      }
      catch (exception e) {
         Log.internal_error("unable to cast " + t->getClass() + " to DomainType (" + e.what(),1);
         return nullptr;
      }
   }
      
}