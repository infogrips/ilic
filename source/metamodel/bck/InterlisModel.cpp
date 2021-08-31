#include "InterlisModel.h"
#include "../util/Logger.h"

using namespace metamodel;

namespace metamodel {
   Class *ANYCLASS;
   Class *ANYSTRUCTURE;
}

/*{
std::string str = "\"this is a string\"";
std::ifstream ifs( str.c_str() );
}*/

static Package *context;

// static helper functions

MetaElement* createMetaElement(MetaElement *e, string name)
{
   e->Name = name;
   e->ElementInPackage = context;
   context->Element.push_back(e);
   return e;
}

ExtendableME* createExtendableME(ExtendableME *e, string name, bool abstract)
{
   createMetaElement(e, name);
   e->Abstract = abstract;
   e->Final = false;
   return e;
}

LineForm* createLineForm(LineForm *l, string name)
{
   createMetaElement(l, name);
   return l;
}

void createLineForms()
{
   createLineForm(new LineForm(), "STRAIGHTS");
   createLineForm(new LineForm(), "ARCS");
}

Unit* createUnit(string name, string shortname, bool abstract)
{
   Unit *u = new Unit();
   createExtendableME(u, name, true);
   u->Kind = Unit::BaseU;
   // shortname ???
   return u;
}

void createUnits()
{
   createUnit("ANYUNIT", "ANYUNIT", false);
   createUnit("DIMENSIONLESS", "DIMENSIONLESS", false);
   createUnit("LENGTH", "LENGTH", false);
   createUnit("MASS", "MASS", false);
   createUnit("TIME", "TIME", false);
   createUnit("ELECTRIC_CURRENT", "ELECTRIC_CURRENT", false);
   createUnit("TEMPERATURE", "TEMPERATURE", false);
   createUnit("AMOUNT_OF_MATTER", "AMOUNT_OF_MATTER", false);
   createUnit("ANGLE", "ANGLE", false);
   createUnit("SOLID_ANGLE", "SOLID_ANGLE", false);
   createUnit("LUMINOUS_INTENSITY", "LUMINOUS_INTENSITY", false);
   createUnit("MONEY", "MONEY", false);
   createUnit("METER", "m", false);
   createUnit("KILOGRAM", "kg", false);
   createUnit("SECOND", "s", false);
   createUnit("AMPERE", "A", false);
   createUnit("DEGREE_KELVIN", "K", false);
   createUnit("MOLE", "mol", false);
   createUnit("RADIAN", "rad", false);
   createUnit("STERADIAN", "sr", false);
   createUnit("CANDELA", "cd", false);
}

DomainType* createDomainType(string name,string basetype,bool abstract)
{
   DomainType *d = new DomainType();
   createExtendableME(d, name, abstract);
   return d;
}

void createDomainTypes()
{
   createDomainType("URI","TextType",false);
   createDomainType("NAME","TextType",false);
   createDomainType("INERLIS_1_DATE","TextType",false);
   createDomainType("BOOLEAN","EnumType",false);
   createDomainType("HALIGNMENT","EnumType",false);
   createDomainType("VALIGNMENT","EnumType",false);
   createDomainType("ANYOID","TextType",true);
   createDomainType("I32OID","NumType",false);
   createDomainType("STANDARDOID","TextType",false);
   createDomainType("UUIDOID","TextType",false);
   createDomainType("LineCoord","CoordType",true);
}

FunctionDef* createFunctionDef(string name)
{
   FunctionDef *f = new FunctionDef();
   createMetaElement(f, name);
   return f;
}

void createFunctionDefs()
{
   createFunctionDef("myClass");
   createFunctionDef("isSubClass");
   createFunctionDef("isOfClass");
   createFunctionDef("elementCount");
   createFunctionDef("objectCount");
   createFunctionDef("len");
   createFunctionDef("lenM");
   createFunctionDef("trim");
   createFunctionDef("trimM");
   createFunctionDef("isEnumSubVal");
   createFunctionDef("isEnumRange");
   createFunctionDef("convertUnit");
   createFunctionDef("areAreas");
}

Class* createClass(string name)
{
   Class *c = new Class();
   createExtendableME(c, name, true);
   c->Kind = Class::ClassVal;
   return c;
}

Class* createStructure(string name)
{
   Class *s = createClass(name);
   s->Kind = Class::Structure;
   return s;
}

void createClasses()
{
   metamodel::ANYCLASS = createClass("ANYCLASS");
   metamodel::ANYSTRUCTURE = createClass("ANYSTRUCTURE");
   createClass("METAOBJECT");
   createClass("METAOBJECT_TRANSLATION");
   createStructure("AXIS");
   createClass("REFSYSTEM");
   createClass("COORDSYSTEM");
   createClass("SCALSYSTEM");
   createClass("SIGN");
}

void createTopicTIMESYSTEMS()
{

   SubModel *topic = new SubModel();
   topic->Name = "TIMESYSTEMS";
   topic->ElementInPackage = context;
   context->Element.push_back(topic);

   context = topic;

   createUnit("Minute", "min", false);
   createUnit("Hour", "h", false);
   createUnit("Day", "d", false);
   createUnit("Month", "M", false);
   createUnit("Year", "Y", false);

   // public final MetaDataUseDef BaseTimeSystems = new MetaDataUseDef(); to do !!!

   createStructure("TimeOfDay");
   createStructure("UTC");
   createStructure("GreogrianDate");
   createStructure("GregorianDateTime");

   createDomainType("GregorianYear","FormattedType",false);
   createDomainType("XMLTime","FormattedType",false);
   createDomainType("XMLDate","FormattedType",false);
   createDomainType("XMLDateTime","FormattedType",false);

   createStructure("LineSegment");
   createStructure("StartSegment");
   createStructure("StraightSegement");
   createStructure("ArcSegement");
   createStructure("SurfaceEdge");
   createStructure("SurfaceBoundary");
   createStructure("LineGeometry");

}

// public interface

InterlisModel::InterlisModel(string iliversion)
{

   this->Name = "INTERLIS";
   this->iliVersion = "2.3";
   this->Contracted = false;
   this->Kind = NormalM;
   this->Language = "en";
   this->At = "http://www.interlis.ch/models";
   this->iliVersion = iliversion;
   this->Version = "1.0";
   this->NoIncrementalTransfer = true;
   this->CharSetIANAName = "ISO-8859-1";
   this->xmlns = "ili";
   this->ili1Transfername = "";
   this->ili1Format = nullptr;
   this->ElementInPackage = nullptr;

   context = this;
   createLineForms();
   createUnits();
   createDomainTypes();
   createFunctionDefs();
   createClasses();

//   createTopicTIMESYSTEMS();

}
