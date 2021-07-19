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
   static list <Type*> AllTypes;
   static list <Unit*> AllUnits;
   static list <Import*> AllImports;
   static list <FunctionDef*> AllFunctions;
   static list <LineForm*> AllLineForms;

   // mmobject helpers

   void init_mmobject(MMObject* o, int line)
   {
      o->_line = line;
   }

   // metaelement helpers

   void init_metaelement(MetaElement* e, int line)
   {

      // list <DocText> Documentation;
      // ROLE from ASSOCIATION MetaAttributes
      // list <MetaAttribute *> MetaAttribute;

      init_mmobject(e, line);
      MMObject *ctx = get_context();
      if (ctx == nullptr) {
         return;
      }

      string context = ctx->getClass();
      if (context == "Model" || context == "SubModel") {
         e->ElementInPackage = static_cast<Package *>(ctx);
         e->ElementInPackage->Element.push_back(e);
      }
      else if (context == "Class") {
         if (e->getClass() == "AttrOrParam") {
            e->ElementInPackage = nullptr;
            AttrOrParam* t = static_cast<AttrOrParam*>(e);
            t->AttrParent = static_cast<Class *>(ctx); // reverse Role, to do !!!
         }
         else if (e->isSubClassOf("Constraint")) {
            e->ElementInPackage = nullptr;
            Constraint* c = static_cast<Constraint*>(e);
            c->ToClass = static_cast<Class *>(ctx); // reverse Role, to do !!!
         }
         else if (e->getClass() == "Role") {
            e->ElementInPackage = nullptr;
            Role* r = static_cast<Role*>(e);
            r->Association = static_cast<Class *>(ctx); // reverse Role, to do !!!
         }
      }
      else if (context == "FunctionDef") {
         e->ElementInPackage = nullptr;
         Type *t = static_cast<Type *>(e);
         FunctionDef *f = static_cast<FunctionDef *>(ctx);
         t->LFTParent = f;
      }
      else if (context == "AttrOrParam") {
         e->ElementInPackage = nullptr;
         Type *t = static_cast<Type *>(e);
         AttrOrParam *a = static_cast<AttrOrParam *>(ctx);
         t->_attr = a;
         a->Type = t; // loaltype ???, to do !!!
      }

   }

   void init_extendableme(ExtendableME* e, int line)
   {
      init_metaelement(e, line);
      // bool Abstract;
      // bool Final;
      // ROLE from ASSOCIATION Inheritance
      // ExtendableME *Super;
      // ROLE from ASSOCIATION Inheritance
      // list <ExtendableME *> Sub;
   }

   // package helpers

   void init_package(Package* p, int line)
   {
      init_metaelement(p, line);
      // ROLE from ASSOCIATION PackageElements
      // list <MetaElement *> Element;
   }

   // Model helpers

   Model* find_model(string name, int line)
   {

      Log.debug("find_model " + name);

      for (Model* m : get_all_models()) {
         if (m->Name == name) {
            return m;
         }
      }

      Log.error("model " + name + " not found.", line);
      return nullptr;

   }

   // Topic / DataUnit helpers

   void add_dataunit(DataUnit* u)
   {
      if (u == nullptr) {
         return;
      }
      for (DataUnit* uu : AllDataUnits) {
         if (uu->Name == u->ElementInPackage->Name) {
            Log.error("multiple declaration of topic " + u->ElementInPackage->Name, u->_line);
            return;
         }
      }
      AllDataUnits.push_back(u);
   }

   DataUnit* find_dataunit(string name, int line)
   {
      Log.debug("find_dataunit " + name);
      for (DataUnit* u : AllDataUnits) {
         if (get_path(u) == (get_path(get_model_context()) + "." + name + ".BASKET")) {
            return u;
         }
         else if (get_path(u) == (name + ".BASKET")) {
            return u;
         }
      }
      Log.error("unknown topic " + name, line);
      return nullptr;
   }

   void add_package(Package* p)
   {
      if (p == nullptr) {
         return;
      }
      AllPackages.push_back(p);
   }

   Package* find_package(string name, int line)
   {
      Log.debug("find_package " + name);
      for (Package* p : AllPackages) {
         if (get_path(p) == name) {
            return p;
         }
         else if (p->Name == name) {
            return p;
         }
      }
      Log.error("unknown package " + name, line);
      return nullptr;
   }

   SubModel* find_topic(string name, int line)
   {
      Log.debug("find_topic " + name);
      Package *p = find_package(name,line);
      if (p->getClass() == "SubModel") {
         return static_cast<SubModel *>(p);
      }
      else {
         Log.error(name + " is not a topic");
         return nullptr;
      }         
   }

   // Unit helpers

   void add_unit(Unit* u)
   {
      if (u == nullptr) {
         return;
      }
      for (Unit* uu : AllUnits) {
         if (get_path(uu) == get_path(u)) {
            Log.error("multiple declaration of unit " + u->Name, u->_line);
            return;
         }
      }
      AllUnits.push_back(u);
   }

   Unit* find_unit(string name, int line)
   {
      Log.debug("find_unit " + name);
      for (Unit* u : AllUnits) {
         if (get_path(u) == name) {
            return u;
         }
         else if (u->Name == name) {
            return u;
         }
         else if (u->_unitname == name) {
            return u;
         }
      }
      Log.error("unknown unit " + name, line);
      return nullptr;
   }

   // Type helpers

   void init_type(Type* t, int line)
   {
      init_extendableme(t, line);
      // FunctionDef *LFTParent;
   }

   void add_type(Type* t)
   {
      if (t == nullptr) {
         return;
      }
      Log.debug(">>> add_type " + get_path(t));
      if (util::starts_with(t->Name, "ILIC_")) {
         t->Name = t->Name.substr(5);
      }
      for (Type* tt : AllTypes) {
         if (get_path(tt) == get_path(t)) {
            Log.error("multiple declarations of " + get_path(t),t->_line);
            return;
         }
      }
      Log.debug("<<< add_type " + get_path(t));
      AllTypes.push_back(t);
   }

   static Type* find_type(string name, int line, bool error)
   {
      
      string search;
      if (util::starts_with(name, "ILIC_")) {
         search = name.substr(5);
      }
      else {
         search = name;
      }

      Log.debug("find_type <" + search + ">");

      for (Type* t : AllTypes) {
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

      if (error) {
         Log.error("type " + search + " not found.", line);
      }

      return nullptr;

   }

   Type* find_type(string name, int line)
   {
      return find_type(name, line, true);
   }

   string get_type_string(Type *t)
   {
      if (t == nullptr) {
         return "???";
      }
      if (t->Name == "BOOLEAN") {
         return "BooleanType";
      }
      else {
         return t->getClass();
      }
   }

   void init_domaintype(DomainType* t, int line)
   {
      init_type(t, line);
   }

   DomainType* find_domaintype(string name, int line)
   {
      Type* t = find_type(name, line);
      if (t == nullptr) {
         return nullptr;
      }
      if (t->isSubClassOf("DomainType")) {
         return static_cast<DomainType*>(t);
      }
      else {
         return nullptr;
      }
   }

   // Class helpers

   void init_class(Class* c, int line)
   {
      init_type(c, line);
   }

   void add_class(Class* c)
   {
      add_type(c);
   }

   Class* find_class_object(string name,string restriction, int line)
   {

      Type* t = find_type(name, line, false);
      if (t == nullptr) {
         Log.error(restriction + " " + name + " not found",line);
         return nullptr;
      }

      if (t->getClass() != "Class") {
         Log.error(name + " is no " + restriction,line);
         return nullptr;
      }

      return static_cast<Class*>(t);

   }

   Class* find_class(string name, int line)
   {
      Log.debug("find_class " + name);
      Class* c;
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
         c = find_class_object(name,"class", line);
         if (c != nullptr && c->Kind != Class::ClassVal) {
            Log.error(name + " is no class");
            c = nullptr;
         }
      }
      return c;
   }

   Class* find_class(Package* p, string name, int line)
   {
      Log.debug("find_class " + name);
      if (p == nullptr) {
         return nullptr;
      }
      for (auto e : p->Element) {
         if (e->Name == name && e->getClass() == "Class") {
            Class* c = static_cast<Class*>(e);
            if (c->Kind == Class::ClassVal) {
               return c;
            }
         }
      }
      Log.error("class " + name + " not found", line);
      return nullptr;
   }

   Class* find_structure(string name, int line)
   {
      Log.debug("find_structure " + name);
      Class* c = find_class_object(name,"structure", line);
      if (c != nullptr && c->Kind != Class::Structure) {
         Log.error(name + " is no structure");
         c = nullptr;
      }
      return c;
   }

   Class* find_structure(Package* p, string name, int line)
   {
      Log.debug("find_structure " + name);
      if (p == nullptr) {
         return nullptr;
      }
      for (auto e : p->Element) {
         if (e->Name == name && e->getClass() == "Class") {
            Class* c = static_cast<Class*>(e);
            if (c->Kind == Class::Structure) {
               return c;
            }
         }
      }
      Log.error("structure " + name + " not found", line);
      return nullptr;
   }

   Class* find_association(string name, int line)
   {
      Log.debug("find_association " + name);
      Class* c = find_class_object(name,"association", line);
      if (c != nullptr && c->Kind != Class::Association) {
         Log.error(name + " is no association");
         c = nullptr;
      }
      return c;
   }

   Class* find_association(Package* p, string name, int line)
   {
      if (p == nullptr) {
         return nullptr;
      }
      Log.debug("find_association " + name);
      for (auto e : p->Element) {
         if (e->Name == name && e->getClass() == "Class") {
            Class* c = static_cast<Class*>(e);
            if (c->Kind == Class::Association) {
               return c;
            }
         }
      }
      Log.error("association " + name + " not found", line);
      return nullptr;
   }

   View* find_view(string name, int line)
   {
      Log.debug("find_view " + name);
      Class *v = find_class_object(name,"view",line);
      if (v != nullptr && v->Kind != Class::ViewVal) {
         Log.error(name + " is no view");
         v = nullptr;
      }
      return static_cast<View *>(v);
   }

   AttrOrParam* find_attribute(Class* c,string name,int line)
   {
      Log.debug("find_attribute " + name);
      if (c == nullptr) {
         return nullptr;
      }
      for (auto a : c->ClassAttribute) {
         if (a->Name == name) {
            return a;
         }
      }
      if (c->Super != nullptr) {
         Class* s = static_cast<Class*>(c->Super);
         return find_attribute(s,name,line);
      }
      else {
         Log.error("attribute " + name + " not found", line);
         return nullptr;
      }
   }

   // expression helpers

   void init_expression(Expression* e, int line)
   {
      init_mmobject(e, line);
   }

   void init_factor(Factor* f, int line)
   {
      init_expression(f, line);
   }

   // function helpers

   void init_function(FunctionDef* f, int line)
   {
      init_metaelement(f, line);
   }

   void add_function(FunctionDef* function)
   {
      if (function == nullptr) {
         return;
      }
      Log.debug("add_function " + function->Name + "(" + get_path(function) + ")");
      for (FunctionDef* f : AllFunctions) {
         if (f->Name == function->Name) {
            // add domain type only once
            return;
         }
      }
      AllFunctions.push_back(function);
   }

   FunctionDef* find_function(string name, int line)
   {

      Log.debug("find_function " + name);

      for (FunctionDef* f : AllFunctions) {
         if (get_path(f) == name) {
            return f;
         }
         else if (get_path(f) == get_parent_path(f) + "." + name) {
            return f;
         }
      }

      Log.error("function " + name + " not found", line);
      return nullptr;

   }

   // lineform helpers

   void init_lineform(LineForm* f, int line)
   {
      init_metaelement(f, line);
   }

   void add_lineform(LineForm* lineform)
   {
      if (lineform == nullptr) {
         return;
      }
      Log.debug("add_lineform " + lineform->Name + "(" + get_path(lineform) + ")");
      for (LineForm* f : AllLineForms) {
         if (f->Name == lineform->Name) {
            // add domain type only once
            return;
         }
      }
      AllLineForms.push_back(lineform);
   }

   LineForm* find_lineform(string name, int line)
   {

      Log.debug("find_lineform " + name);

      for (LineForm* f : AllLineForms) {
         if (get_path(f) == name) {
            return f;
         }
         else if (get_path(f) == get_parent_path(f) + "." + name) {
            return f;
         }
      }

      Log.error("lineform " + name + " not found.", line);
      return nullptr;

   }

   // constraint helpers

   void init_constraint(Constraint* c, int line)
   {
      init_metaelement(c, line);
   }

   // context helpers

   static list<MetaElement*> context;
   
   static string get_context_string()
   {
      string cstring = "";
      for (auto c : context) {
         cstring += ">>>" + c->getClass() + ":" + c->Name;
      }
      return cstring;
   }

   void push_context(MetaElement* m)
   {
      context.push_back(m);
      Log.debug(">>> push_context " + get_context_string());
   }

   void pop_context()
   {
      MetaElement* m = context.back();
      Log.debug("<<< pop_context " + get_context_string());
      context.pop_back();
   }

   MetaElement* get_context()
   {
      if (context.size() > 0) {
         return context.back();
      }
      else {
         return nullptr;
      }
   }

   MetaElement* get_context(string classname)
   {
      list<MetaElement*> c;
      c = context;
      while (true) {
         if (c.empty()) {
            break;
         }
         MetaElement* m = c.back();
         if (m->isSubClassOf(classname)) {
            return m;
         }
         c.pop_back();
      }
      return nullptr;
   }

   Class* get_class_context()
   {
      return dynamic_cast<Class*>(get_context("Class"));
   }

   Package* get_package_context()
   {
      return dynamic_cast<Package*>(get_context("Package"));
   }

   SubModel* get_topic_context()
   {
      return dynamic_cast<SubModel*>(get_context("SubModel"));
   }

   Model* get_model_context()
   {
      return dynamic_cast<Model*>(get_context("Model"));
   }

   // other helpers

   Type* any_to_type(antlrcpp::Any any)
   {

      Log.debug(">>> any_to_type()");
      Type* t;

      try {
         t = any.as<TypeRelatedType*>();
         Log.debug(">>> class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }

      try {
         t = any.as<ClassRelatedType*>();
         Log.debug(">>> class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }

      try {
         t = any.as<BooleanType*>();
         Log.debug(">>> class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }

      try {
         t = any.as<TextType*>();
         Log.debug(">>> class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }

      try {
         t = any.as<BlackboxType*>();
         Log.debug(">>> class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }

      try {
         t = any.as<NumType*>();
         Log.debug(">>> class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }

      try {
         t = any.as<CoordType*>();
         Log.debug(">>> class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }

      try {
         AnyOIDType* t = any.as<AnyOIDType*>();
         Log.debug(">>> class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }

      try {
         AttributeRefType* t = any.as<AttributeRefType*>();
         Log.debug(">>> class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }

      try {
         t = any.as<EnumType*>();
         Log.debug(">>> class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }

      try {
         t = any.as<EnumTreeValueType*>();
         Log.debug(">>> class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }

      try {
         t = any.as<LineType*>();
         Log.debug(">>> class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }

      try {
         t = any.as<Class*>();
         Log.debug(">>> class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }

      try {
         t = any.as<DomainType*>();
         Log.debug(">>> DomainType class=" + t->getClass());
         return t;
      }
      catch (exception e) {
      }

      Log.internal_error("any_to_type: unsupported type", 1);
      return nullptr;

   }

   DomainType* any_to_domaintype(antlrcpp::Any any)
   {
      Type* t = any_to_type(any);
      try {
         return static_cast<DomainType*>(t);
      }
      catch (exception e) {
         Log.internal_error("unable to cast " + t->getClass() + " to DomainType (" + e.what(), 1);
         return nullptr;
      }
   }

   int get_line(antlr4::ParserRuleContext *ctx)
   {
      return ctx->start->getLine();
   }

   int get_line(antlr4::Token *token)
   {
      return token->getLine();
   }
   
   int get_line(antlr4::tree::TerminalNode* node)
   {
      return node->getSymbol()->getLine();
   }

}
