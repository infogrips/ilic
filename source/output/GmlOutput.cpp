#pragma once

#include "GmlOutput.h"
#include "../metamodel/MetaModelOutput.h"
#include "../util/StringMap.h"
#include "../util/Logger.h"

using namespace util;
using namespace metamodel;
using namespace output;

GmlOutput::GmlOutput(string gml_output_dir, string iliversion, string ilic_version)
{
   this->gml_output_dir = gml_output_dir;
   this->iliversion = iliversion;
   this->ilic_version = ilic_version;
}

void GmlOutput::writeType(metamodel::DomainType *t) {
   if (t->getClass() == "TextType") {
      TextType* textType = static_cast<TextType*>(t);

      if (textType->OIDType) {
         gml.writeln("<xsd:simpleType name=\"" + t->Name + "\">");
         gml.writelnIncNestLevel("<xsd:restriction base=\"xsd:token\"/>");
         gml.writelnDecNestLevel("</xsd:simpleType>");
      }
      else {
         write_texttype(textType);
      }
   }
   else if (t->getClass() == "ReferenceType") {
      write_referencetype(static_cast<ReferenceType*>(t));
   }
   else if (t->getClass() == "CoordType") {
      write_coordtype(static_cast<CoordType *>(t));
   }
   else if (t->getClass() == "AnyOIDType") {
      
   }
   else if (t->getClass() == "EnumType") {
      write_enumtype(static_cast<EnumType *>(t));
   }
   else if (t->getClass() == "NumType") {
      NumType* numType = static_cast<NumType*>(t);

      if (numType->OIDType) {
         gml.writeln("<xsd:simpleType name=\"" + t->Name + "\">");
         gml.writelnIncNestLevel("<xsd:restriction base=\"xsd:int\"/>");
         gml.writelnDecNestLevel("</xsd:simpleType>");
      }
      else {
         write_numtype(numType);
      }
   }
   else if (t->getClass() == "LineType") {
      write_linetype(static_cast<LineType *>(t));
   }
   else if (t->getClass() == "FormattedType") {
      write_formattedtype(static_cast<FormattedType *>(t));
   }
   else if (t->getClass() == "BlackboxType") {
      write_blackboxtype(static_cast<BlackboxType *>(t));
   }
   else if (t->getClass() == "MultiValue") {
      write_multivalue(static_cast<MultiValue*>(t));
   }
   else {
      gml.writeln("<xsd:complexType name=\"" + get_path(t) + "\">");
      gml.writelnIncNestLevel("<xsd:simpleContent>");
      gml.writelnIncNestLevel("<xsd:extension base=\"xsd:string\"/>");
      gml.writelnDecNestLevel("</xsd:simpleContent>");
      gml.writelnDecNestLevel("</xsd:complexType>");
   }
}

void GmlOutput::write_texttype(metamodel::TextType *t) {
   DomainType* domainType = static_cast<DomainType*>(t);
   string typeAttribute = "";

   if (domainType->Name != "" && domainType->Name != "TOP" && domainType->Name != "TYPE") {
      typeAttribute = " name=\"" + domainType->Name + "\"";
   }

   gml.writeln("<xsd:simpleType" + typeAttribute + ">");

   if (t->Kind == t->Text) {
      gml.writelnIncNestLevel("<xsd:restriction base=\"xsd:normalizedString\">");
   }
   else {
      gml.writelnIncNestLevel("<xsd:restriction base=\"xsd:string\">");
   }



   if (t->MaxLength > 0) {
      gml.writelnIncNestLevel("<xsd:maxLength value=\"" + to_string(t->MaxLength) + "\"/>");
      gml.decNestLevel();
   }


   gml.writeln("</xsd:restriction>");
   gml.writelnDecNestLevel("</xsd:simpleType>");
}

void GmlOutput::write_coordtype(metamodel::CoordType *t) {
   string typeAttribute = "";

   if (t->Name != "" && t->Name != "TOP" && t->Name != "TYPE") {
      typeAttribute = " name=\"" + t->Name + "\"";
   }

   gml.writeln("<xsd:complexType" + typeAttribute + ">");
   gml.writelnIncNestLevel("<xsd:complexContent>");

   string base = "gml:PointPropertyType";

   if (t->Super != nullptr) {
      get_path(t->Super);
   }

   gml.writelnIncNestLevel("<xsd:restriction base=\"" + base + "\">");
   gml.writelnIncNestLevel("<xsd:sequence>");
   gml.writelnIncNestLevel("<xsd:element ref=\"gml:Point\"/>");
   gml.writelnDecNestLevel("</xsd:sequence>");
   gml.writelnDecNestLevel("</xsd:restriction>");
   gml.writelnDecNestLevel("</xsd:complexContent>");
   gml.writelnDecNestLevel("</xsd:complexType>");
}

void GmlOutput::write_enumtype(metamodel::EnumType *t) {
   string typeAttribute = "";
   bool hasDomain = true;
   bool isFinal = t->Final;

   string baseClass = t->getBaseClass();

   if (t->Name != "" && t->Name != "TOP" && t->Name != "TYPE") {
      hasDomain = true;
      typeAttribute = " name=\"" + t->Name + "\"";
   }

   if (!isFinal) {
      string base = "gml:CodeWithAuthorityType";

      if (t->Super != nullptr) {
         base = t->Super->Name;
      }

      gml.writeln("<xsd:complexType" + typeAttribute + ">");
      gml.writelnIncNestLevel("<xsd:simpleContent>");
      gml.writelnIncNestLevel("<xsd:restriction base=\"" + base + "\">");
      gml.writelnIncNestLevel("<xsd:attribute name=\"codeSpace\" type=\"xsd:anyURI\" use=\"required\"/>");
      gml.writelnDecNestLevel("</xsd:restriction>");
      gml.writelnDecNestLevel("</xsd:simpleContent>");
      gml.writelnDecNestLevel("</xsd:complexType>");

      list<string> enums;

      for (auto node : t->TopNode) {
         buildEnum(&enums, "", node);
      }

      codelistKeys.push_back(t->Name);
      codelistValues.push_back(enums);
      //codelist.insert({ t->Name, enums });
   }
   else {
      gml.writeln("<xsd:simpleType" + typeAttribute + ">");
      gml.writelnIncNestLevel("<xsd:restriction base=\"xsd:normalizedString\">");

      gml.incNestLevel();

      list<string> enums;

      for (auto node : t->TopNode) {
         buildEnum(&enums, "", node);
      }

      for (auto entry : enums) {
         gml.writeln("<xsd:enumeration value=\"" + entry + "\"/>");
      }

      //for (auto v : t->ETVT) {
      //   xsd.writeln("<xsd:enumeration value=\"" + v->Name + "\"/>");
      //}

      gml.writelnDecNestLevel("</xsd:restriction>");
      gml.writelnDecNestLevel("</xsd:simpleType>");
   }
}

void GmlOutput::write_numtype(metamodel::NumType *t) {
   string typeAttribute = "";

   if (t->Name != "" && t->Name != "TOP" && t->Name != "TYPE") {
      typeAttribute = " name=\"" + t->Name + "\"";
   }

   gml.writeln("<xsd:simpleType" + typeAttribute + ">");

   if (t->Min.find(".") < t->Min.length()) {

      if (t->Min.find("S") < t->Min.length() ||
         t->Min.find("e") < t->Min.length() ||
         t->Min.find("E") < t->Min.length()) {
         gml.writelnIncNestLevel("<xsd:restriction base=\"xsd:double\">");
      }
      else {
         gml.writelnIncNestLevel("<xsd:restriction base=\"xsd:decimal\">");
      }
      
   }
   else {
      gml.writelnIncNestLevel("<xsd:restriction base=\"xsd:integer\">");
   }

   gml.writelnIncNestLevel("<xsd:minInclusive value=\"" + t->Min + "\"/>");
   gml.writeln("<xsd:maxInclusive value=\"" + t->Max + "\"/>");
   gml.writelnDecNestLevel("</xsd:restriction>");
   gml.writelnDecNestLevel("</xsd:simpleType>");
}

void GmlOutput::write_linetype(metamodel::LineType *t) {
   string typeAttribute = "";

   if (t->Name != "" && t->Name != "TOP" && t->Name != "TYPE") {
      typeAttribute = " name=\"" + t->Name + "\"";
   }

   if (t->Kind == t->Polyline || t->Kind == t->DirectedPolyline) {
      gml.writeln("<xsd:complexType" + typeAttribute + ">");
      gml.writelnIncNestLevel("<xsd:sequence>");
      gml.writelnIncNestLevel("<xsd:element name=\"POLYLINE\">");

      gml.writelnIncNestLevel("<xsd:complexType>");
      gml.writelnIncNestLevel("<xsd:choice minOccurs=\"2\" maxOccurs=\"unbounded\">");
      gml.writelnIncNestLevel("<xsd:element name=\"COORD\" type=\"CoordValue\"/>");

      for (auto *lf : t->LineForm) {
         if (lf->Name == "STRAIGHTS") {

         }
         else if (lf->Name == "ARCS") {
            gml.writeln("<xsd:element name=\"ARC\" type=\"ArcPoint\"/>");
         }
         else {
            gml.writeln("<xsd:element name=\"" + get_path(lf) + "\" type=\"" + get_path(lf->Structure) + "\"/>");
         }
      }

      gml.writelnDecNestLevel("</xsd:choice>");
      gml.writelnDecNestLevel("</xsd:complexType>");

      gml.writelnDecNestLevel("</xsd:element>");
      gml.writelnDecNestLevel("</xsd:sequence>");
      gml.writelnDecNestLevel("</xsd:complexType>");
   }
   else if (t->Kind == t->Area || t->Kind == t->Surface) {
      gml.writeln("<xsd:complexType" + typeAttribute + ">");
      gml.writelnIncNestLevel("<xsd:sequence>");
      gml.writelnIncNestLevel("<xsd:element name=\"SURFACE\">");
      gml.writelnIncNestLevel("<xsd:complexType>");
      gml.writelnIncNestLevel("<xsd:sequence>");
      gml.writelnIncNestLevel("<xsd:element name=\"BOUNDARY\" maxOccurs=\"unbounded\">");
      gml.writelnIncNestLevel("<xsd:complexType>");
      gml.writelnIncNestLevel("<xsd:sequence>");
      gml.writelnIncNestLevel("<xsd:element name=\"POLYLINE\" maxOccurs=\"unbounded\">");

      gml.writelnIncNestLevel("<xsd:complexType>");

      bool hasLineAttr = false;
      if (t->LAStructure != nullptr) {
         string laFullName = t->LAStructure->ElementInPackage->ElementInPackage->Name + "."
            + t->LAStructure->ElementInPackage->Name + "." + t->LAStructure->Name;
         hasLineAttr = true;
         gml.writelnIncNestLevel("<xsd:sequence>");
         gml.writelnIncNestLevel("<xsd:element name=\"LINEATTR\">");
         gml.writelnIncNestLevel("<xsd:complexType>");
         gml.writelnIncNestLevel("<xsd:sequence>");
         gml.writelnIncNestLevel("<xsd:element name=\"" + laFullName + "\" type=\"" + laFullName + "\"/>");
         gml.writelnDecNestLevel("</xsd:sequence>");
         gml.writelnDecNestLevel("</xsd:complexType>");
         gml.writelnDecNestLevel("</xsd:element>");
      }

      gml.writeln("<xsd:choice minOccurs=\"2\" maxOccurs=\"unbounded\">");
      gml.writelnIncNestLevel("<xsd:element name=\"COORD\" type=\"CoordValue\"/>");

      for (auto *lf : t->LineForm) {
         if (lf->Name == "STRAIGHTS") {

         }
         else if (lf->Name == "ARCS") {
            gml.writeln("< xsd:element name = \"ARC\" type=\"ArcPoint\"/>");
         }
         else {
            gml.writeln("< xsd:element name = \"ARC\" name=\"" + get_path(lf) + "\" type=\"" + get_path(lf->Structure) + "\"/>");
         }
      }

      gml.writelnDecNestLevel("</xsd:choice>");
      if (hasLineAttr) {
         gml.writelnDecNestLevel("</xsd:sequence>");
      }

      gml.writelnDecNestLevel("</xsd:complexType>");

      gml.writelnDecNestLevel("</xsd:element>");
      gml.writelnDecNestLevel("</xsd:sequence>");
      gml.writelnDecNestLevel("</xsd:complexType>");
      gml.writelnDecNestLevel("</xsd:element>");
      gml.writelnDecNestLevel("</xsd:sequence>");
      gml.writelnDecNestLevel("</xsd:complexType>");
      gml.writelnDecNestLevel("</xsd:element>");
      gml.writelnDecNestLevel("</xsd:sequence>");
      gml.writelnDecNestLevel("</xsd:complexType>");
   }
}

void GmlOutput::write_formattedtype(metamodel::FormattedType *t) {
   string typeAttribute = "";

   if (t->Name != "" && t->Name != "TOP" && t->Name != "TYPE") {
      typeAttribute = " name=\"" + t->Name + "\"";
   }

   string base = "";
   bool hasBaseDomain = true;

   if (t->Format == "INTERLIS.XMLDate") {
      base = "xsd:date";
   }
   else if (t->Format == "INTERLIS.XMLDateTime") {
      base = "xsd:dateTime";
   }
   else if (t->Format == "INTERLIS.XMLTime") {
      base = "xsd:time";
   }
   else {
      hasBaseDomain = false;
      base = "xsd:normalizedString";
   }

   gml.writeln("<xsd:simpleType" + typeAttribute + ">");
   gml.writelnIncNestLevel("<xsd:restriction base=\"" + base + "\">");

   if (!hasBaseDomain) {
      string regex = "([\\+\\-0-9\\.]+)-([\\+\\-0-9\\.]+)-([\\+\\-0-9\\.]+)";
      gml.writelnIncNestLevel("<xsd:pattern value=\"" + regex + "\"/>");
      gml.decNestLevel();
   }

   gml.writeln("</xsd:restriction>");
   gml.writelnDecNestLevel("</xsd:simpleType>");
}

void GmlOutput::write_blackboxtype(metamodel::BlackboxType *t) {
   string typeAttribute = "";

   if (t->Name != "" && t->Name != "TOP" && t->Name != "TYPE") {
      typeAttribute = " name=\"" + t->Name + "\"";
   }

   if (t->Kind == t->Xml) {
      gml.writeln("<xsd:complexType" + typeAttribute + ">");
      gml.writelnIncNestLevel("<xsd:sequence>");
      gml.writelnIncNestLevel("<xsd:any namespace=\"##any\" minOccurs=\"0\" maxOccurs=\"unbounded\" processContents=\"lax\"/>");
      gml.writelnDecNestLevel("</xsd:sequence>");
      gml.writelnDecNestLevel("</xsd:complexType>");
   }
   else {
      gml.writeln("<xsd:simpleType" + typeAttribute + ">");
      gml.writelnIncNestLevel("<xsd:restriction base=\"xsd:base64Binary\">");
      gml.writeln("</xsd:restriction>");
      gml.writelnDecNestLevel("</xsd:simpleType>");
   }
}

void GmlOutput::write_referencetype(metamodel::ReferenceType* t) {
   string typeAttribute = "";

   if (t->Name != "" && t->Name != "TOP" && t->Name != "TYPE") {
      typeAttribute = " name=\"" + get_path(t) + "\"";
   }

   gml.writeln("<xsd:annotation>");
   gml.writelnIncNestLevel("<xsd:appinfo>");
   gml.writelnIncNestLevel("<gml:targetElement>" + t->BaseClass->Name + "</gml:targetElement>");
   gml.writelnDecNestLevel("</xsd:appinfo>");
   gml.writelnDecNestLevel("</xsd:annotation>");
}

void GmlOutput::write_multivalue(metamodel::MultiValue* t) {
   string typeAttribute = "";

   if (t->Name != "" && t->Name != "TOP" && t->Name != "TYPE") {
      typeAttribute = " name=\"" + get_path(t) + "\"";
   }

   gml.writeln("<xsd:complexType" + typeAttribute + ">");
   gml.writelnIncNestLevel("<xsd:sequence>");

   gml.incNestLevel();

   gml.writeln("<xsd:element ref=\"" + t->BaseType->Name + "\"/>");

   gml.writelnDecNestLevel("</xsd:sequence>");
   gml.writelnDecNestLevel("</xsd:complexType>");
}

void GmlOutput::write_codelists(Model *m) {
   if (codelistKeys.empty()) {
      return;
   }

   gml.writeln("<xsd:annotation>");
   gml.writelnIncNestLevel("<xsd:appinfo source=\"http://www.interlis.ch/ili2c\">");

   gml.incNestLevel();

   int oid = 1;
   for (int i=0;i<codelistKeys.size();i++)
   {
      string key = codelistKeys[i];
      list<string> values = codelistValues[i];
      gml.writeln("<gml:Dictionary gml:id=\"o" + to_string(oid++) + "\">");
      gml.writelnIncNestLevel("<gml:identifier codeSpace=\"http://www.interlis.ch/INTERLIS2.3/GML32/" + m->Name + "\">" + key + "</gml:identifier>");

      string codeSpace = "http://www.interlis.ch/INTERLIS2.3/GML32/" + m->Name + "/" + key;

      for (auto const& value : values) {
         gml.writeln("<gml:dictionaryEntry>");
         gml.writelnIncNestLevel("<gml:Definition gml:id=\"o" + to_string(oid++) + "\">");
         gml.writelnIncNestLevel("<gml:identifier codeSpace=\"" + codeSpace + "\">" + value + "</gml:identifier>");
         gml.writelnDecNestLevel("</gml:Definition>");
         gml.writelnDecNestLevel("</gml:dictionaryEntry>");
      }

      gml.writelnDecNestLevel("</gml:Dictionary>");
   }

   gml.writelnDecNestLevel("</xsd:appinfo>");
   gml.writelnDecNestLevel("</xsd:annotation>");
}

void GmlOutput::write_linetables() {
   for (auto *a : areaAttributes) {
      string linetableName = a->AttrParent->Name + "." + a->Name;
      string baseElement = "gml:AbstractFeature";
      gml.writeln("<xsd:element name=\"" + linetableName + "\" type=\"" + linetableName + "Type\" substitutionGroup=\"" + baseElement + "\"/>");
      gml.writeln("<xsd:complexType  name=\"" + linetableName + "Type\">");
      gml.writelnIncNestLevel("<xsd:complexContent>");
      string baseXsdType = "gml:AbstractFeatureType";
      gml.writelnIncNestLevel("<xsd:extension base=\"" + baseXsdType + "\">");
      gml.writelnIncNestLevel("<xsd:sequence>");
      gml.writelnIncNestLevel("<xsd:element name=\"geometry\" type=\"gml:CurvePropertyType\"/>");

      LineType *lt = static_cast<LineType *>(a->Type);
      if (lt->LAStructure != nullptr) {
         gml.writeln("<xsd:element name=\"lineattr\">");
         gml.writelnIncNestLevel("<xsd:complexType>");
         gml.writelnIncNestLevel("<xsd:sequence>");
         gml.writelnIncNestLevel("<xsd:element ref=\"" + lt->LAStructure->Name + "\"/>");
         gml.writelnDecNestLevel("</xsd:sequence>");
         gml.writeln("<xsd:attributeGroup ref=\"gml:OwnershipAttributeGroup\"/>");
         gml.writelnDecNestLevel("</xsd:complexType>");
         gml.writelnDecNestLevel("</xsd:element>");
      }

      gml.writelnDecNestLevel("</xsd:sequence>");
      gml.writelnDecNestLevel("</xsd:extension>");
      gml.writelnDecNestLevel("</xsd:complexContent>");
      gml.writelnDecNestLevel("</xsd:complexType>");
   }
}
   
void GmlOutput::preVisit()
{
   Log.warning("gml generation not fully implemented yet");
}

void GmlOutput::preVisitModel(Model *m) {
   if (m->Name == "INTERLIS") {
      ignoreVisit();
   }

   gml.openFile(gml_output_dir + "/" + m->Name + ".xsd");

   gml.writeln("<?xml version=\"1.0\" encoding=\"UTF-8\" ?>");
   gml.writeln("<xsd:schema xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"");
   gml.incNestLevel();
   gml.write(" xmlns=\"http://www.interlis.ch/INTERLIS2.3/GML32/" + m->Name + "\"");
   gml.write(" targetNamespace=\"http://www.interlis.ch/INTERLIS2.3/GML32/" + m->Name + "\"");
   gml.writeln(" elementFormDefault=\"qualified\" attributeFormDefault=\"unqualified\"");
   gml.writeln("xmlns:gml=\"http://www.opengis.net/gml/3.2\"");
   gml.writeln("xmlns:INTERLIS=\"http://www.interlis.ch/INTERLIS2.3/GML32/INTERLIS\"");
   gml.writeln("xmlns:ili2c=\"http://www.interlis.ch/ili2c\"");

   for (Import *i : get_all_imports()) {
      if (m->Name != i->ImportingP->Name) {
         continue;
      }

      gml.writeln("xmlns:" + i->ImportedP->Name + "=\"http://www.interlis.ch/INTERLIS2.3/GML32/" + i->ImportedP->Name + "\"");
   }

   gml.writeln(">");
   gml.decNestLevel();

   gml.writeln("<xsd:annotation>");

   gml.writelnIncNestLevel("<xsd:appinfo source=\"http://www.interlis.ch/ili2c/ili2cversion\">"
      + ilic_version + "</xsd:appinfo>"
   );

   gml.writeln("<xsd:appinfo source=\"http://www.interlis.ch/ili2c\">");

   gml.writelnIncNestLevel("<ili2c:model>" + m->Name + "</ili2c:model>");
   gml.writeln("<ili2c:modelVersion>" + m->Version + "</ili2c:modelVersion>");

   if (!m->VersionExplanation.empty()) {
      gml.writeln("<ili2c:modelVersionExplanation>" + m->VersionExplanation + "</ili2c:modelVersionExplanation>");
   }

   gml.writeln("<ili2c:modelAt>" + m->At + "</ili2c:modelAt>");

   gml.writelnDecNestLevel("</xsd:appinfo>");
   gml.writelnDecNestLevel("</xsd:annotation>");

   // import of GML schema
   gml.writeln("<xsd:import namespace=\"http://www.opengis.net/gml/3.2\"/>");
   // import of base ILIGML schema
   gml.writeln("<xsd:import namespace=\"http://www.interlis.ch/INTERLIS2.3/GML32/INTERLIS\"/>");

   for (Import *i : get_all_imports()) {
      if (m->Name != i->ImportingP->Name) {
         continue;
      }

      gml.writeln("<xsd:import namespace=\"http://www.interlis.ch/INTERLIS2.3/GML32/"+i->ImportedP->Name+"\"/>");
   }
}

void GmlOutput::postVisitModel(Model *m) {

   write_linetables();
   write_codelists(m);

   gml.writeln("</xsd:schema>");
   gml.closeFile();
}

void GmlOutput::visitDomainType(metamodel::DomainType *t) {
   if (t->_attr != nullptr) {

   }
   else if (t->Name == "C1") {
   }
   else if (t->Name == "C2") {
   }
   else if (t->Name == "C3") {
   }
   else if (t->Name == "A1") {
   }
   else if (t->Name == "A2") {
   }
   else if (t->Name == "R") {
   }
   else if (t->Name == "TOP") {
   }
   else if (t->Name == "") {
   }
   else if (t->Name == "TYPE") {
   }
   else {
      writeType(t);
   }
}

void GmlOutput::preVisitClass(metamodel::Class *c) {
   /*if (c->Kind == c->Association) {
      //ignoreVisit();
      return;
   }*/

   string base = "gml:AbstractFeature";
   string baseXsd = "gml:AbstractFeatureType";

   if (c->Super != nullptr) {
      base = c->Super->Name;
      baseXsd = base + "Type";
   }

   gml.writeln("<xsd:element name=\"" + c->Name + "\" type=\"" + c->Name + "Type\" substitutionGroup=\"" + base + "\"/>");
   gml.writeln("<xsd:complexType  name=\"" + c->Name + "Type\">");
   gml.writelnIncNestLevel("<xsd:complexContent>");
   gml.writelnIncNestLevel("<xsd:extension base=\"" + baseXsd + "\">");
   gml.writelnIncNestLevel("<xsd:sequence>");

   gml.incNestLevel();
}

void GmlOutput::postVisitClass(metamodel::Class *c) {
   /*if (c->Kind == c->Association) {
      //ignoreVisit();
      return;
   }*/

   gml.writelnDecNestLevel("</xsd:sequence>");
   gml.writelnDecNestLevel("</xsd:extension>");
   gml.writelnDecNestLevel("</xsd:complexContent>");
   gml.writelnDecNestLevel("</xsd:complexType>");
}

void GmlOutput::visitAttrOrParam(metamodel::AttrOrParam *a) {
   DomainType *t = nullptr;

   try {
      t = dynamic_cast<DomainType *>(a->Type);
   }
   catch (exception e) {
      Log.error("unable to cast " + a->Type->getClass() + " to DomainType");
      return;
   }

   string minOccurs = "";
   if (t->Mandatory != true) {
      minOccurs = " minOccurs=\"0\"";
   }

   if (a->Type->Name != "TOP" && a->Type->Name != "" && a->Type->Name != "TYPE") {
      if (a->Type->Name == "BOOLEAN") {
         gml.writeln("<xsd:element name=\"" + a->Name + "\" type=\"xsd:boolean\"" + minOccurs + "/>");
      }
      else if (a->Type->Name == "XmlDate") {
         gml.writeln("<xsd:element name=\"" + a->Name + "\" type=\"xsd:date\"" + minOccurs + "/>");
      }
      else if (a->Type->Name == "XmlDateTime") {
         gml.writeln("<xsd:element name=\"" + a->Name + "\" type=\"xsd:dateTime\"" + minOccurs + "/>");
      }
      else if (a->Type->Name == "XmlTime") {
         gml.writeln("<xsd:element name=\"" + a->Name + "\" type=\"xsd:time\"" + minOccurs + " / > ");
      }
      else {
         if (a->Type->_other_type != nullptr) {
            gml.writeln("<xsd:element name=\"" + a->Name + "\" type=\"" + a->Type->_other_type->Name + "\"" + minOccurs + "/>");
         }
         else {
            gml.writeln("<xsd:element name=\"" + a->Name + "\" type=\"" + a->Type->Name + "\"" + minOccurs + "/>");
         }
      }

      return;
   }

   if (a->Type->getClass() == "CoordType") {
      gml.writeln("<xsd:element name=\"" + a->Name + "\"" + minOccurs + " type=\"gml:PointPropertyType\"/>");
   }
   else if (a->Type->getClass() == "LineType") {
      LineType *lt = static_cast<LineType *>(a->Type);

      if (lt->Kind == LineType::Polyline) {
         gml.writeln("<xsd:element name=\"" + a->Name + "\"" + minOccurs + " type=\"gml:CurvePropertyType\">");
         gml.writeln("</xsd:element>");
      }
      else if (lt->Kind == LineType::Surface) {
         gml.writeln("<xsd:element name=\"" + a->Name + "\"" + minOccurs + " type=\"gml:SurfacePropertyType\">");
         gml.writeln("</xsd:element>");
      }
      else if (lt->Kind == LineType::Area) {
         string base = lt->CoordType->Name;
         gml.writeln("<xsd:element name=\"" + a->Name + "\" type=\"" + base + "\"" + minOccurs + ">");
         gml.writeln("</xsd:element>");

         areaAttributes.push_back(a);
      }
   }
   else if (a->Type->getClass() == "EnumType" ||
      a->Type->getClass() == "EnumTreeValueType") {
      EnumType* lt = static_cast<EnumType*>(a->Type);

      string baseClass = t->getBaseClass();

      if (!lt->Final) {
         gml.writeln("<xsd:element name=\"" + a->Name + "\" type=\"gml:CodeWithAuthorityType\"" + minOccurs + "/>");

         list<string> enums;

         for (auto node : lt->TopNode) {
            buildEnum(&enums, "", node);
         }

         codelistKeys.push_back(a->AttrParent->Name + "." + a->Name);
         codelistValues.push_back(enums);
      }
      else {
         string typeAttribute = "";

         if (t->Name != "" && t->Name != "TOP" && t->Name != "TYPE") {
            typeAttribute = " name=\"" + t->Name + "\"";
         }

         gml.writeln("<xsd:simpleType" + typeAttribute + ">");
         gml.writelnIncNestLevel("<xsd:restriction base=\"xsd:normalizedString\">");

         gml.incNestLevel();

         list<string> enums;

         for (auto node : lt->TopNode) {
            buildEnum(&enums, "", node);
         }

         for (auto entry : enums) {
            gml.writeln("<xsd:enumeration value=\"" + entry + "\"/>");
         }

         gml.writelnDecNestLevel("</xsd:restriction>");
         gml.writelnDecNestLevel("</xsd:simpleType>");
      }
   }
   else {
      string type = "";
      string maxOccurs = "";

      if (a->Type->getClass() == "ReferenceType") {
         type = " type=\"gml:ReferenceType\"";
      }
      else if (a->Type->getClass() == "MultiValue") {
         MultiValue* lt = static_cast<MultiValue*>(a->Type);

         if (lt->Multiplicity.Min > 1) {
            minOccurs = " minOccurs=\"" + to_string(lt->Multiplicity.Min) + "\"";
         }
         else
         {
            minOccurs = "";
         }

         if (lt->Multiplicity.Max != 1) {
            if (lt->Multiplicity.Max == -1) {
               maxOccurs = " maxOccurs=\"unbounded\"";
            }
            else {
               maxOccurs = " maxOccurs=\"" + to_string(lt->Multiplicity.Max) + "\"";
            }
         }
      }

      gml.writeln("<xsd:element name=\"" + a->Name + "\"" + type + minOccurs + maxOccurs + ">");

      gml.incNestLevel();

      writeType(t);

      gml.decNestLevel();
      gml.writeln("</xsd:element>");
  }
}

void GmlOutput::postVisitSubModel(metamodel::SubModel *s) {
   gml.writeln("<xsd:complexType name=\"" + s->Name + "MemberType\">");
   gml.writelnIncNestLevel("<xsd:complexContent>");
   gml.writelnIncNestLevel("<xsd:extension base=\"gml:AbstractFeatureMemberType\">");
   gml.writelnIncNestLevel("<xsd:sequence>");
   gml.writelnIncNestLevel("<xsd:choice>");

   gml.incNestLevel();

   for (auto *a : s->Element) {
      if (a->getClass() == "Class") {
         Class *c = static_cast<Class *>(a);

         if (c->Kind == c->ClassVal) {
            gml.writeln("<xsd:element ref=\"" + a->Name + "\"/>");
         }


      }
   }

   for (auto *a : areaAttributes) {
      gml.writeln("<xsd:element ref=\"" + a->AttrParent->Name + "." + a->Name + "\"/>");
   }

   gml.decNestLevel();

   gml.writeln("</xsd:choice>");
   gml.writelnDecNestLevel("</xsd:sequence>");
   gml.writelnDecNestLevel("</xsd:extension>");
   gml.writelnDecNestLevel("</xsd:complexContent>");
   gml.writelnDecNestLevel("</xsd:complexType>");

   gml.writeln("<xsd:element name=\"" + s->Name + "\" type=\"" + s->Name + "Type\" substitutionGroup=\"gml:AbstractFeature\"/>");
   gml.writeln("<xsd:complexType name=\"" + s->Name + "Type\">");
   gml.writelnIncNestLevel("<xsd:complexContent>");
   gml.writelnIncNestLevel("<xsd:extension base=\"gml:AbstractFeatureType\">");
   gml.writelnIncNestLevel("<xsd:sequence>");
   gml.writelnIncNestLevel("<xsd:element name=\"member\" type=\"" + s->Name + "MemberType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>");
   gml.writelnDecNestLevel("</xsd:sequence>");
   gml.writeln("<xsd:attributeGroup ref=\"gml:AggregationAttributeGroup\"/>");
   gml.writelnDecNestLevel("</xsd:extension>");
   gml.writelnDecNestLevel("</xsd:complexContent>");
   gml.writelnDecNestLevel("</xsd:complexType>");
}

void GmlOutput::buildEnum(list<string>* list, string prefix, metamodel::EnumNode* enumNode) {
   if (prefix.length() > 0) {
      prefix += ".";
   }

   if (enumNode->Node.size() == 0) {
      list->push_back(prefix + enumNode->Name);
   }
   else {
      for (auto* node : enumNode->Node) {
         buildEnum(list, prefix + enumNode->Name, node);
      }
   }
}