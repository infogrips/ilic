#pragma once

#include "XsdOutput.h"

#include "../metamodel/MetaModelOutput.h"
#include "../util/StringMap.h"
#include "../util/Logger.h"

using namespace util;
using namespace metamodel;
using namespace output;

XsdOutput::XsdOutput(string xsd_file,string iliversion, string ilic_version) {
   this->xsd_file = xsd_file;
   this->iliversion = iliversion;
   this->ilic_version = ilic_version;
}
   
void XsdOutput::preVisit(void) {
   Log.warning("xsd generation not fully implemented yet");
   
   xsd.openFile(xsd_file);

   xsd.writeln("<?xml version=\"1.0\" encoding=\"UTF-8\" ?>");
   
   xsd.writeln("<xsd:schema xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\""
      " xmlns=\"http://www.interlis.ch/INTERLIS2.3\" xmlns:ili2c=\"http://www.interlis.ch/ili2c\""
      " targetNamespace=\"http://www.interlis.ch/INTERLIS2.3\""
      " elementFormDefault=\"qualified\" attributeFormDefault=\"unqualified\""
      ">"
   );

   Log.debug("write annotations");
   writeAnnotations();
   
   Log.debug("write fix types 1");
   writeFixTypes1();

   Log.debug("write alias tables");
   writeAliasTables();

   Log.debug("write fix types 2");
   writeFixTypes2();

   Log.debug("write datasection");
   writeDatasection();
}

void XsdOutput::postVisit() {
   Log.debug("write interlis reference types");
   writeInterlisReferenceTypes();

   Log.debug("write header section");
   writeHeadersection();

   xsd.writelnDecNestLevel("</xsd:schema>");
   xsd.closeFile();
}

void XsdOutput::writeAnnotations() {
   xsd.writelnIncNestLevel("<xsd:annotation>");

   xsd.writelnIncNestLevel("<xsd:appinfo source=\"http://www.interlis.ch/ili2c/ili2cversion\">"
      + ilic_version + "</xsd:appinfo>"
   );

   for (Model *m : get_all_models()) {
      xsd.writeln("<xsd:appinfo source=\"http://www.interlis.ch/ili2c\">");
      xsd.writelnIncNestLevel("<ili2c:model>" + m->Name + "</ili2c:model>");
      xsd.writeln("<ili2c:modelVersion>" + m->Version + "</ili2c:modelVersion>");

      if (!m->VersionExplanation.empty()) {
         xsd.writeln("<ili2c:modelVersionExplanation>" + m->VersionExplanation + "</ili2c:modelVersionExplanation>");
      }

      xsd.writeln("<ili2c:modelAt>" + m->At + "</ili2c:modelAt>");
      xsd.writeln("<ili2c:textMinimalCharset>" "ili23AnnexB" "</ili2c:textMinimalCharset>");
      xsd.writelnDecNestLevel("</xsd:appinfo>");
   }

   xsd.writelnDecNestLevel("</xsd:annotation>");
}

void XsdOutput::writeFixTypes1() {
   xsd.writeln("<xsd:element name=\"TRANSFER\" type=\"Transfer\"/>");

   xsd.writeln("<xsd:simpleType name=\"IliID\">");
   xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:string\">");
   xsd.writelnIncNestLevel("<xsd:pattern value=\"([a-zA-Z_][0-9a-zA-Z_\\-\\.]*:)?[0-9a-zA-Z_][0-9a-zA-Z_\\-\\.]*\"/>");
   xsd.writelnDecNestLevel("</xsd:restriction>");
   xsd.writelnDecNestLevel("</xsd:simpleType>");

   xsd.writeln("<xsd:complexType name=\"Transfer\">");
   xsd.writelnIncNestLevel("<xsd:sequence>");
   xsd.writelnIncNestLevel("<xsd:element name=\"HEADERSECTION\" type=\"HeaderSection\"/>");
   xsd.writeln("<xsd:element name=\"DATASECTION\" type=\"DataSection\"/>");
   xsd.writelnDecNestLevel("</xsd:sequence>");
   xsd.writelnDecNestLevel("</xsd:complexType>");
}

void XsdOutput::writeAliasTables() {
   //Log.warning("writeAliasTables not implemented yet");
}

void XsdOutput::writeFixTypes2() {
   xsd.writeln("<xsd:complexType name=\"Models\">");
   xsd.writelnIncNestLevel("<xsd:sequence>");
   xsd.writelnIncNestLevel("<xsd:element name=\"MODEL\" type=\"Model\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>");
   xsd.writelnDecNestLevel("</xsd:sequence>");
   xsd.writelnDecNestLevel("</xsd:complexType>");

   xsd.writeln("<xsd:complexType name=\"Model\">");
   xsd.writelnIncNestLevel("<xsd:attribute name=\"NAME\" type=\"INTERLIS.NAME\" use=\"required\"/>");
   xsd.writeln("<xsd:attribute name=\"VERSION\" type=\"xsd:string\" use=\"required\"/>");
   xsd.writeln("<xsd:attribute name=\"URI\" type=\"xsd:anyURI\" use=\"required\"/>");
   xsd.writelnDecNestLevel("</xsd:complexType>");

   bool addAliasTable = false;

   if(get_all_models().size() > 0) {
      Model *m = get_all_models().back();

      Log.warning("ili2c.ili23xsd.addAliasTableDefault not implemented yet");
      for (MetaAttribute* ma : m->MetaAttribute) {
         if (ma->Name == "ili2c.ili23xsd.addAliasTableDefault") {
            if (ma->Value == "true") {
               addAliasTable = true;
            }
         }
      }
   }

   if(addAliasTable) {
      xsd.writeln("<xsd:complexType name=\"Alias\">");
      xsd.writelnIncNestLevel("<xsd:sequence>");
      xsd.writelnIncNestLevel("<xsd:element name=\"ENTRIES\" type=\"Entries\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>");
      xsd.writelnDecNestLevel("</xsd:sequence>");
      xsd.writelnDecNestLevel("</xsd:complexType>");

      xsd.writeln("<xsd:complexType name=\"Entries\">");
      xsd.writelnIncNestLevel("<xsd:sequence>");
      xsd.writelnIncNestLevel("<xsd:choice maxOccurs=\"unbounded\">");
      xsd.writelnIncNestLevel("<xsd:element name=\"TAGENTRY\" type=\"Tagentry\"/>");
      xsd.writeln("<xsd:element name=\"VALENTRY\" type=\"Valentry\"/>");
      xsd.writeln("<xsd:element name=\"DELENTRY\" type=\"Delentry\"/>");
      xsd.writelnDecNestLevel("</xsd:choice>");
      xsd.writelnDecNestLevel("</xsd:sequence>");
      xsd.writeln("<xsd:attribute name=\"FOR\" type=\"xsd:string\" use=\"required\"/>");
      xsd.writelnDecNestLevel("</xsd:complexType>");

      xsd.writeln("<xsd:complexType name=\"Tagentry\">");
      xsd.writelnIncNestLevel("<xsd:attribute name=\"FROM\" type=\"xsd:string\" use=\"required\"/>");
      xsd.writeln("<xsd:attribute name=\"TO\" type=\"xsd:string\" use=\"required\"/>");
      xsd.writelnDecNestLevel("</xsd:complexType>");

      xsd.writeln("<xsd:complexType name=\"Valentry\">");
      xsd.writelnIncNestLevel("<xsd:attribute name=\"TAG\" type=\"xsd:string\" use=\"required\"/>");
      xsd.writeln("<xsd:attribute name=\"ATTR\" type=\"xsd:string\" use=\"required\"/>");
      xsd.writeln("<xsd:attribute name=\"FROM\" type=\"xsd:string\" use=\"required\"/>");
      xsd.writeln("<xsd:attribute name=\"TO\" type=\"xsd:string\" use=\"required\"/>");
      xsd.writelnDecNestLevel("</xsd:complexType>");

      xsd.writeln("<xsd:complexType name=\"Delentry\">");
      xsd.writelnIncNestLevel("<xsd:attribute name=\"TAG\" type=\"xsd:string\" use=\"required\"/>");
      xsd.writeln("<xsd:attribute name=\"ATTR\" type=\"xsd:string\"/>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
   }

   xsd.writeln("<xsd:complexType name=\"RoleType\">");
   xsd.writelnIncNestLevel("<xsd:simpleContent>");
   xsd.writelnIncNestLevel("<xsd:extension base=\"xsd:string\">");
   xsd.writelnIncNestLevel("<xsd:attribute name=\"REF\" type=\"IliID\" use=\"required\"/>");
   xsd.writeln("<xsd:attribute name=\"BID\" type=\"IliID\"/>");
   xsd.writeln("<xsd:attribute name=\"ORDER_POS\" type=\"xsd:positiveInteger\"/>");
   xsd.writelnDecNestLevel("</xsd:extension>");
   xsd.writelnDecNestLevel("</xsd:simpleContent>");
   xsd.writelnDecNestLevel("</xsd:complexType>");
}

void XsdOutput::writeDatasection() {
   xsd.writeln("<xsd:complexType name=\"DataSection\">");
   xsd.writelnIncNestLevel("<xsd:sequence>");
   xsd.writelnIncNestLevel("<xsd:choice minOccurs=\"0\" maxOccurs=\"unbounded\">");

   xsd.incNestLevel();

   for (Model *m : get_all_models()) {
      if (m->Name == "INTERLIS" || m->Kind != m->NormalM) {
         continue;
      }

      for (auto *me : m->Element) {
         if (me->getClass() == "SubModel") {
            xsd.writeln("<xsd:element name=\"" + get_path(me) + "\" type=\"" + get_path(me) + "\"/>");
         }
      }
   }

   xsd.decNestLevel();

   xsd.writeln("</xsd:choice>");
   xsd.writelnDecNestLevel("</xsd:sequence>");
   xsd.writelnDecNestLevel("</xsd:complexType>");
}

void XsdOutput::writeInterlisReferenceTypes() {
   //if (addAllInterlisTypes || refCoordValue) {
      xsd.writeln("<xsd:complexType name=\"CoordValue\">");
      xsd.writelnIncNestLevel("<xsd:sequence>");
      xsd.writelnIncNestLevel("<xsd:element name=\"C1\" type=\"xsd:double\"/>");
      xsd.writeln("<xsd:element name=\"C2\" type=\"xsd:double\" minOccurs=\"0\"/>");
      xsd.writeln("<xsd:element name=\"C3\" type=\"xsd:double\" minOccurs=\"0\"/>");
      xsd.writelnDecNestLevel("</xsd:sequence>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
   //}
   //if (addAllInterlisTypes || refArcPoint) {
      xsd.writeln("<xsd:complexType name=\"ArcPoint\">");
      xsd.writelnIncNestLevel("<xsd:sequence>");
      xsd.writelnIncNestLevel("<xsd:element name=\"C1\" type=\"xsd:double\"/>");
      xsd.writeln("<xsd:element name=\"C2\" type=\"xsd:double\"/>");
      xsd.writeln("<xsd:element name=\"C3\" type=\"xsd:double\" minOccurs=\"0\"/>");
      xsd.writeln("<xsd:element name=\"A1\" type=\"xsd:double\"/>");
      xsd.writeln("<xsd:element name=\"A2\" type=\"xsd:double\"/>");
      xsd.writeln("<xsd:element name=\"R\" type=\"xsd:double\" minOccurs=\"0\"/>");
      xsd.writelnDecNestLevel("</xsd:sequence>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
   //}

   xsd.writeln("<xsd:simpleType name=\"INTERLIS.NAME\">");
   xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:normalizedString\">");
   xsd.writelnIncNestLevel("<xsd:maxLength value=\"255\"/>");
   xsd.writelnDecNestLevel("</xsd:restriction>");
   xsd.writelnDecNestLevel("</xsd:simpleType>");

   //if (addAllInterlisTypes || referencedTypes.contains(td.INTERLIS.METAOBJECT)) {
      xsd.writeln("<xsd:complexType name=\"INTERLIS.METAOBJECT\">");
      xsd.writelnIncNestLevel("<xsd:sequence>");
      xsd.writelnIncNestLevel("<xsd:element name=\"Name\" type=\"INTERLIS.NAME\"/>");
      xsd.writelnDecNestLevel("</xsd:sequence>");
      xsd.writeln("<xsd:attribute name=\"TID\" type=\"IliID\" use=\"required\"/>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
   //}
   //if (addAllInterlisTypes || referencedTypes.contains(td.INTERLIS.METAOBJECT_TRANSLATION)) {
      xsd.writeln("<xsd:complexType name=\"INTERLIS.METAOBJECT_TRANSLATION\">");
      xsd.writelnIncNestLevel("<xsd:sequence>");
      xsd.writelnIncNestLevel("<xsd:element name=\"Name\" type=\"INTERLIS.NAME\"/>");
      xsd.writeln("<xsd:element name=\"NameInBaseLanguage\" type=\"INTERLIS.NAME\"/>");
      xsd.writelnDecNestLevel("</xsd:sequence>");
      xsd.writeln("<xsd:attribute name=\"TID\" type=\"IliID\" use=\"required\"/>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
   //}
   //if (addAllInterlisTypes || referencedTypes.contains(td.INTERLIS.AXIS)) {
      xsd.writeln("<xsd:complexType name=\"INTERLIS.AXIS\">");
      xsd.writelnIncNestLevel("<xsd:sequence>");
      xsd.writeln("</xsd:sequence>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
   //}
   //if (addAllInterlisTypes || referencedTypes.contains(td.INTERLIS.REFSYSTEM)) {
      xsd.writeln("<xsd:complexType name=\"INTERLIS.REFSYSTEM\">");
      xsd.writelnIncNestLevel("<xsd:sequence>");
      xsd.writelnIncNestLevel("<xsd:element name=\"Name\" type=\"INTERLIS.NAME\"/>");
      xsd.writelnDecNestLevel("</xsd:sequence>");
      xsd.writeln("<xsd:attribute name=\"TID\" type=\"IliID\" use=\"required\"/>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
   //}
   //if (addAllInterlisTypes || referencedTypes.contains(td.INTERLIS.COORDSYSTEM)) {
      xsd.writeln("<xsd:complexType name=\"INTERLIS.COORDSYSTEM\">");
      xsd.writelnIncNestLevel("<xsd:sequence>");
      xsd.writelnIncNestLevel("<xsd:element name=\"Name\" type=\"INTERLIS.NAME\"/>");
      xsd.writeln("<xsd:element name=\"Axis\">");
      xsd.writelnIncNestLevel("<xsd:complexType>");
      xsd.writelnIncNestLevel("<xsd:sequence>");
      xsd.writelnIncNestLevel("<xsd:element name=\"INTERLIS.AXIS\" type=\"INTERLIS.AXIS\"  maxOccurs=\"3\"/>");
      xsd.writelnDecNestLevel("</xsd:sequence>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
      xsd.writelnDecNestLevel("</xsd:element>");
      xsd.writelnDecNestLevel("</xsd:sequence>");
      xsd.writeln("<xsd:attribute name=\"TID\" type=\"IliID\" use=\"required\"/>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
   //}
   //if (addAllInterlisTypes || referencedTypes.contains(td.INTERLIS.SCALSYSTEM)) {
      xsd.writeln("<xsd:complexType name=\"INTERLIS.SCALSYSTEM\">");
      xsd.writelnIncNestLevel("<xsd:sequence>");
      xsd.writelnIncNestLevel("<xsd:element name=\"Name\" type=\"INTERLIS.NAME\"/>");
      xsd.writelnDecNestLevel("</xsd:sequence>");
      xsd.writeln("<xsd:attribute name=\"TID\" type=\"IliID\" use=\"required\"/>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
   //}
   //if (addAllInterlisTypes || referencedTypes.contains(td.INTERLIS.SIGN)) {
      xsd.writeln("<xsd:complexType name=\"INTERLIS.SIGN\">");
      xsd.writelnIncNestLevel("<xsd:sequence>");
      xsd.writelnIncNestLevel("<xsd:element name=\"Name\" type=\"INTERLIS.NAME\"/>");
      xsd.writelnDecNestLevel("</xsd:sequence>");
      xsd.writeln("<xsd:attribute name=\"TID\" type=\"IliID\" use=\"required\"/>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
   //}
   //if (addAllInterlisTypes || referencedTypes.contains(td.INTERLIS.TIMESYSTEMS.CALENDAR)) {
      xsd.writeln("<xsd:complexType name=\"INTERLIS.TIMESYSTEMS.CALENDAR\">");
      xsd.writelnIncNestLevel("<xsd:sequence>");
      xsd.writelnIncNestLevel("<xsd:element name=\"Name\" type=\"INTERLIS.NAME\"/>");
      xsd.writelnDecNestLevel("</xsd:sequence>");
      xsd.writeln("<xsd:attribute name=\"TID\" type=\"IliID\" use=\"required\"/>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
   //}
   //if (addAllInterlisTypes || referencedTypes.contains(td.INTERLIS.TIMESYSTEMS.TIMEOFDAYSYS)) {
      xsd.writeln("<xsd:complexType name=\"INTERLIS.TIMESYSTEMS.TIMEOFDAYSYS\">");
      xsd.writelnIncNestLevel("<xsd:sequence>");
      xsd.writelnIncNestLevel("<xsd:element name=\"Name\" type=\"INTERLIS.NAME\"/>");
      xsd.writelnDecNestLevel("</xsd:sequence>");
      xsd.writeln("<xsd:attribute name=\"TID\" type=\"IliID\" use=\"required\"/>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
   //}
   //if (addAllInterlisTypes || referencedTypes.contains(td.INTERLIS.TimeOfDay)) {
      xsd.writeln("<xsd:complexType name=\"INTERLIS.TimeOfDay\">");
      xsd.writelnIncNestLevel("<xsd:sequence>");

      xsd.writelnIncNestLevel("<xsd:element name=\"Hours\" minOccurs=\"0\">");
      xsd.writelnIncNestLevel("<xsd:simpleType>");
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:integer\">");
      xsd.writelnIncNestLevel("<xsd:minInclusive value=\"0\"/>");
      xsd.writeln("<xsd:maxInclusive value=\"23\"/>");
      xsd.writelnDecNestLevel("</xsd:restriction>");
      xsd.writelnDecNestLevel("</xsd:simpleType>");
      xsd.writelnDecNestLevel("</xsd:element>");

      xsd.writeln("<xsd:element name=\"Minutes\" minOccurs=\"0\">");
      xsd.writelnIncNestLevel("<xsd:simpleType>");
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:integer\">");
      xsd.writelnIncNestLevel("<xsd:minInclusive value=\"0\"/>");
      xsd.writeln("<xsd:maxInclusive value=\"59\"/>");
      xsd.writelnDecNestLevel("</xsd:restriction>");
      xsd.writelnDecNestLevel("</xsd:simpleType>");
      xsd.writelnDecNestLevel("</xsd:element>");

      xsd.writeln("<xsd:element name=\"Seconds\" minOccurs=\"0\">");
      xsd.writelnIncNestLevel("<xsd:simpleType>");
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:double\">");
      xsd.writelnIncNestLevel("<xsd:minInclusive value=\"0.000\"/>");
      xsd.writeln("<xsd:maxInclusive value=\"59.999\"/>");
      xsd.writelnDecNestLevel("</xsd:restriction>");
      xsd.writelnDecNestLevel("</xsd:simpleType>");
      xsd.writelnDecNestLevel("</xsd:element>");

      xsd.writelnDecNestLevel("</xsd:sequence>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
   //}
   //if (addAllInterlisTypes || referencedTypes.contains(td.INTERLIS.UTC)) {
      xsd.writeln("<xsd:complexType name=\"INTERLIS.UTC\">");
      xsd.writelnIncNestLevel("<xsd:sequence>");

      xsd.writelnIncNestLevel("<xsd:element name=\"Hours\" minOccurs=\"0\">");
      xsd.writelnIncNestLevel("<xsd:simpleType>");
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:integer\">");
      xsd.writelnIncNestLevel("<xsd:minInclusive value=\"0\"/>");
      xsd.writeln("<xsd:maxInclusive value=\"23\"/>");
      xsd.writelnDecNestLevel("</xsd:restriction>");
      xsd.writelnDecNestLevel("</xsd:simpleType>");
      xsd.writelnDecNestLevel("</xsd:element>");

      xsd.writeln("<xsd:element name=\"Minutes\" minOccurs=\"0\">");
      xsd.writelnIncNestLevel("<xsd:simpleType>");
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:integer\">");
      xsd.writelnIncNestLevel("<xsd:minInclusive value=\"0\"/>");
      xsd.writeln("<xsd:maxInclusive value=\"59\"/>");
      xsd.writelnDecNestLevel("</xsd:restriction>");
      xsd.writelnDecNestLevel("</xsd:simpleType>");
      xsd.writelnDecNestLevel("</xsd:element>");

      xsd.writeln("<xsd:element name=\"Seconds\" minOccurs=\"0\">");
      xsd.writelnIncNestLevel("<xsd:simpleType>");
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:double\">");
      xsd.writelnIncNestLevel("<xsd:minInclusive value=\"0.000\"/>");
      xsd.writeln("<xsd:maxInclusive value=\"59.999\"/>");
      xsd.writelnDecNestLevel("</xsd:restriction>");
      xsd.writelnDecNestLevel("</xsd:simpleType>");
      xsd.writelnDecNestLevel("</xsd:element>");

      xsd.writelnDecNestLevel("</xsd:sequence>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
   //}
   //if (addAllInterlisTypes || referencedTypes.contains(td.INTERLIS.GregorianDate)) {
      xsd.writeln("<xsd:complexType name=\"INTERLIS.GregorianDate\">");
      xsd.writelnIncNestLevel("<xsd:sequence>");

      xsd.writelnIncNestLevel("<xsd:element name=\"Year\" type=\"INTERLIS.GregorianYear\" minOccurs=\"0\"/>");

      xsd.writeln("<xsd:element name=\"Month\" minOccurs=\"0\">");
      xsd.writelnIncNestLevel("<xsd:simpleType>");
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:integer\">");
      xsd.writelnIncNestLevel("<xsd:minInclusive value=\"1\"/>");
      xsd.writeln("<xsd:maxInclusive value=\"12\"/>");
      xsd.writelnDecNestLevel("</xsd:restriction>");
      xsd.writelnDecNestLevel("</xsd:simpleType>");
      xsd.writelnDecNestLevel("</xsd:element>");

      xsd.writeln("<xsd:element name=\"Day\" minOccurs=\"0\">");
      xsd.writelnIncNestLevel("<xsd:simpleType>");
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:integer\">");
      xsd.writelnIncNestLevel("<xsd:minInclusive value=\"1\"/>");
      xsd.writeln("<xsd:maxInclusive value=\"31\"/>");
      xsd.writelnDecNestLevel("</xsd:restriction>");
      xsd.writelnDecNestLevel("</xsd:simpleType>");
      xsd.writelnDecNestLevel("</xsd:element>");

      xsd.writelnDecNestLevel("</xsd:sequence>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
   //}
   //if (addAllInterlisTypes || referencedTypes.contains(td.INTERLIS.GregorianDateTime)) {
      xsd.writeln("<xsd:complexType name=\"INTERLIS.GregorianDateTime\">");
      xsd.writelnIncNestLevel("<xsd:sequence>");

      xsd.writelnIncNestLevel("<xsd:element name=\"Year\" type=\"INTERLIS.GregorianYear\" minOccurs=\"0\"/>");

      xsd.writeln("<xsd:element name=\"Month\" minOccurs=\"0\">");
      xsd.writelnIncNestLevel("<xsd:simpleType>");
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:integer\">");
      xsd.writelnIncNestLevel("<xsd:minInclusive value=\"1\"/>");
      xsd.writeln("<xsd:maxInclusive value=\"12\"/>");
      xsd.writelnDecNestLevel("</xsd:restriction>");
      xsd.writelnDecNestLevel("</xsd:simpleType>");
      xsd.writelnDecNestLevel("</xsd:element>");

      xsd.writeln("<xsd:element name=\"Day\" minOccurs=\"0\">");
      xsd.writelnIncNestLevel("<xsd:simpleType>");
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:integer\">");
      xsd.writelnIncNestLevel("<xsd:minInclusive value=\"1\"/>");
      xsd.writeln("<xsd:maxInclusive value=\"31\"/>");
      xsd.writelnDecNestLevel("</xsd:restriction>");
      xsd.writelnDecNestLevel("</xsd:simpleType>");
      xsd.writelnDecNestLevel("</xsd:element>");

      xsd.writelnIncNestLevel("<xsd:element name=\"Hours\" minOccurs=\"0\">");
      xsd.writelnIncNestLevel("<xsd:simpleType>");
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:integer\">");
      xsd.writelnIncNestLevel("<xsd:minInclusive value=\"0\"/>");
      xsd.writeln("<xsd:maxInclusive value=\"23\"/>");
      xsd.writelnDecNestLevel("</xsd:restriction>");
      xsd.writelnDecNestLevel("</xsd:simpleType>");
      xsd.writelnDecNestLevel("</xsd:element>");

      xsd.writeln("<xsd:element name=\"Minutes\" minOccurs=\"0\">");
      xsd.writelnIncNestLevel("<xsd:simpleType>");
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:integer\">");
      xsd.writelnIncNestLevel("<xsd:minInclusive value=\"0\"/>");
      xsd.writeln("<xsd:maxInclusive value=\"59\"/>");
      xsd.writelnDecNestLevel("</xsd:restriction>");
      xsd.writelnDecNestLevel("</xsd:simpleType>");
      xsd.writelnDecNestLevel("</xsd:element>");

      xsd.writeln("<xsd:element name=\"Seconds\" minOccurs=\"0\">");
      xsd.writelnIncNestLevel("<xsd:simpleType>");
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:double\">");
      xsd.writelnIncNestLevel("<xsd:minInclusive value=\"0.000\"/>");
      xsd.writeln("<xsd:maxInclusive value=\"59.999\"/>");
      xsd.writelnDecNestLevel("</xsd:restriction>");
      xsd.writelnDecNestLevel("</xsd:simpleType>");
      xsd.writelnDecNestLevel("</xsd:element>");

      xsd.writelnDecNestLevel("</xsd:sequence>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
   //}
   //if (addAllInterlisTypes || referencedTypes.contains(td.INTERLIS.HALIGNMENT)) {
      xsd.writeln("<xsd:simpleType name=\"INTERLIS.HALIGNMENT\">");
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:string\">");
      xsd.writelnIncNestLevel("<xsd:enumeration value=\"Left\"/>");
      xsd.writeln("<xsd:enumeration value=\"Center\"/>");
      xsd.writeln("<xsd:enumeration value=\"Right\"/>");
      xsd.writelnDecNestLevel("</xsd:restriction>");
      xsd.writelnDecNestLevel("</xsd:simpleType>");
   //}
   //if (addAllInterlisTypes || referencedTypes.contains(td.INTERLIS.VALIGNMENT)) {
      xsd.writeln("<xsd:simpleType name=\"INTERLIS.VALIGNMENT\">");
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:string\">");
      xsd.writelnIncNestLevel("<xsd:enumeration value=\"Top\"/>");
      xsd.writeln("<xsd:enumeration value=\"Cap\"/>");
      xsd.writeln("<xsd:enumeration value=\"Half\"/>");
      xsd.writeln("<xsd:enumeration value=\"Base\"/>");
      xsd.writeln("<xsd:enumeration value=\"Bottom\"/>");
      xsd.writelnDecNestLevel("</xsd:restriction>");
      xsd.writelnDecNestLevel("</xsd:simpleType>");
   //}
   //if (addAllInterlisTypes || referencedTypes.contains(td.INTERLIS.URI)) {
      xsd.writeln("<xsd:simpleType name=\"INTERLIS.URI\">");
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:normalizedString\">");
      xsd.writelnIncNestLevel("<xsd:maxLength value=\"1023\"/>");
      xsd.writelnDecNestLevel("</xsd:restriction>");
      xsd.writelnDecNestLevel("</xsd:simpleType>");
   //}
   //if (addAllInterlisTypes || referencedTypes.contains(td.INTERLIS.INTERLIS_1_DATE)) {
      xsd.writeln("<xsd:simpleType name=\"INTERLIS.INTERLIS_1_DATE\">");
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:normalizedString\">");
      xsd.writelnIncNestLevel("<xsd:maxLength value=\"8\"/>");
      xsd.writelnDecNestLevel("</xsd:restriction>");
      xsd.writelnDecNestLevel("</xsd:simpleType>");
   //}
   //if (addAllInterlisTypes || referencedTypes.contains(td.INTERLIS.STANDARDOID)) {
      xsd.writeln("<xsd:complexType name=\"INTERLIS.STANDARDOID\">");
      xsd.writelnIncNestLevel("<xsd:attribute name=\"OID\" type=\"IliID\" use=\"required\"/>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
   //}
   //if (addAllInterlisTypes || referencedTypes.contains(td.INTERLIS.I32OID)) {
      xsd.writeln("<xsd:complexType name=\"INTERLIS.I32OID\">");
      xsd.writelnIncNestLevel("<xsd:attribute name=\"OID\" type=\"IliID\" use=\"required\"/>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
   //}
   //if (addAllInterlisTypes || referencedTypes.contains(td.INTERLIS.UUIDOID)) {
      xsd.writeln("<xsd:complexType name=\"INTERLIS.UUIDOID\">");
      xsd.writelnIncNestLevel("<xsd:attribute name=\"OID\" type=\"IliID\" use=\"required\"/>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
   //}
   //if (addAllInterlisTypes || referencedTypes.contains(td.INTERLIS.GregorianYear)) {
      xsd.writeln("<xsd:simpleType name=\"INTERLIS.GregorianYear\">");
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:integer\">");
      xsd.writelnIncNestLevel("<xsd:minInclusive value=\"1582\"/>");
      xsd.writeln("<xsd:maxInclusive value=\"2999\"/>");
      xsd.writelnDecNestLevel("</xsd:restriction>");
      xsd.writelnDecNestLevel("</xsd:simpleType>");
   //}
}

void XsdOutput::writeHeadersection() {
   xsd.writeln("<xsd:complexType name=\"HeaderSection\">");
   xsd.writelnIncNestLevel("<xsd:sequence>");
   xsd.writelnIncNestLevel("<xsd:element name=\"MODELS\" type=\"Models\"/>");

   bool addAliasTable = false;
   if (addAliasTable) {
      xsd.writeln("<xsd:element name=\"ALIAS\" type=\"Alias\" minOccurs=\"0\"/>");
   }

   //if (refOidSpaces) {
      xsd.writeln("<xsd:element name=\"OIDSPACES\" type=\"OidSpaces\" minOccurs=\"0\"/>");
   //}

   xsd.writeln("<xsd:element name=\"COMMENT\" type=\"xsd:string\" minOccurs=\"0\"/>");
   xsd.writelnDecNestLevel("</xsd:sequence>");
   xsd.writeln("<xsd:attribute name=\"VERSION\" type=\"xsd:decimal\" use=\"required\" fixed=\"2.3\"/>");
   xsd.writeln("<xsd:attribute name=\"SENDER\" type=\"xsd:string\" use=\"required\"/>");
   xsd.writelnDecNestLevel("</xsd:complexType>");

   //if (refOidSpaces) {
      xsd.writeln("<xsd:complexType name=\"OidSpaces\">");
      xsd.writelnIncNestLevel("<xsd:sequence>");
      xsd.writelnIncNestLevel("<xsd:element name=\"OIDSPACE\" type=\"OidSpace\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>");
      xsd.writelnDecNestLevel("</xsd:sequence>");
      xsd.writelnDecNestLevel("</xsd:complexType>");

      xsd.writeln("<xsd:complexType name=\"OidSpace\">");
      xsd.writelnIncNestLevel("<xsd:attribute name=\"NAME\" type=\"xsd:string\" use=\"required\"/>");
      xsd.writeln("<xsd:attribute name=\"OIDDOMAIN\" type=\"xsd:string\" use=\"required\"/>");
      xsd.writelnDecNestLevel("</xsd:complexType>");

   //}
   //if (addAllInterlisTypes || refIncrementalTypes) {
      xsd.writeln("<xsd:simpleType name=\"OperationType\">");
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:string\">");
      xsd.writelnIncNestLevel("<xsd:enumeration value=\"INSERT\"/>");
      xsd.writeln("<xsd:enumeration value=\"UPDATE\"/>");
      xsd.writeln("<xsd:enumeration value=\"DELETE\"/>");
      xsd.writelnDecNestLevel("</xsd:restriction>");
      xsd.writelnDecNestLevel("</xsd:simpleType>");
      xsd.writeln("<xsd:simpleType name=\"TransferKindType\">");
      xsd.writeln("<xsd:restriction base=\"xsd:string\">");
      xsd.writelnIncNestLevel("<xsd:enumeration value=\"FULL\"/>");
      xsd.writeln("<xsd:enumeration value=\"INITIAL\"/>");
      xsd.writeln("<xsd:enumeration value=\"UPDATE\"/>");
      xsd.writelnDecNestLevel("</xsd:restriction>");
      xsd.writelnDecNestLevel("</xsd:simpleType>");
   //}
   //if (addAllInterlisTypes || refConsistencyType) {
      xsd.writeln("<xsd:simpleType name=\"ConsistencyType\">");
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:string\">");
      xsd.writelnIncNestLevel("<xsd:enumeration value=\"COMPLETE\"/>");
      xsd.writeln("<xsd:enumeration value=\"INCOMPLETE\"/>");
      xsd.writeln("<xsd:enumeration value=\"INCONSISTENT\"/>");
      xsd.writeln("<xsd:enumeration value=\"ADAPTED\"/>");
      xsd.writelnDecNestLevel("</xsd:restriction>");
      xsd.writelnDecNestLevel("</xsd:simpleType>");
   //}
}

void XsdOutput::writeType(metamodel::DomainType *t) {
   bool isOIDType = false;

   if (t->getClass() == "LineType") {
      write_linetype(static_cast<LineType*>(t));
   } 
   else if (t->getClass() == "CoordType") {
      write_coordtype(static_cast<CoordType *>(t));
   }
   else if (t->getClass() == "ReferenceType") {
      write_referencetype(static_cast<ReferenceType*>(t));
   }
   else if (t->getClass() == "AnyOIDType") {
      isOIDType = true;
   }
   else if (t->getClass() == "EnumType") {
      write_enumtype(static_cast<EnumType *>(t));
   }
   else if (t->getClass() == "NumType") {
      NumType *numType = static_cast<NumType*>(t);

      if (numType->OIDType) {
         isOIDType = true;
      }
      else {
         write_numtype(numType);
      }
   }
   else if (t->getClass() == "TextType") {
      TextType* textType = static_cast<TextType*>(t);

      if (textType->OIDType) {
         isOIDType = true;
      }
      else {
         write_texttype(textType);
      }
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
      xsd.writeln("<xsd:complexType name=\"" + get_path(t) + "\">");
      xsd.writelnIncNestLevel("<xsd:simpleContent>");
      xsd.writelnIncNestLevel("<xsd:extension base=\"xsd:string\"/>");
      xsd.writelnDecNestLevel("</xsd:simpleContent>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
   }

   if (isOIDType) {
      xsd.writeln("<xsd:complexType name=\"" + get_path(t) + "\">");
      xsd.writelnIncNestLevel("<xsd:attribute name=\"OID\" type=\"IliID\" use=\"required\"/>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
   }
}

void XsdOutput::write_texttype(metamodel::TextType *t) {
   DomainType* domainType = static_cast<DomainType*>(t);
   string typeAttribute = "";
   
   if (domainType->Name != "" && domainType->Name != "TOP" && domainType->Name != "TYPE") {
      typeAttribute = " name=\"" + get_path(t) + "\"";
   }

   xsd.writeln("<xsd:simpleType" + typeAttribute + ">");

   if (t->Kind == t->Text) {
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:normalizedString\">");
   }
   else {
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:string\">");
   }

   if (t->MaxLength > 0) {
      xsd.writelnIncNestLevel("<xsd:maxLength value=\"" + to_string(t->MaxLength) + "\"/>");
      xsd.decNestLevel();
   }

   xsd.writeln("</xsd:restriction>");
   xsd.writelnDecNestLevel("</xsd:simpleType>");
}

void XsdOutput::write_coordtype(metamodel::CoordType *t) {
   string typeAttribute = "";

   if (t->Name != "" && t->Name != "TOP" && t->Name != "TYPE") {
      typeAttribute = " name=\"" + get_path(t) + "\"";
   }

   xsd.writeln("<xsd:complexType" + typeAttribute + ">");
   xsd.writelnIncNestLevel("<xsd:sequence>");
   xsd.writelnIncNestLevel("<xsd:element name=\"COORD\" type=\"CoordValue\"/>");
   xsd.writelnDecNestLevel("</xsd:sequence>");
   xsd.writelnDecNestLevel("</xsd:complexType>");
}

void XsdOutput::write_enumtype(metamodel::EnumType *t) {
   string typeAttribute = "";

   if (t->Name != "" && t->Name != "TOP" && t->Name != "TYPE") {
      typeAttribute = " name=\"" + get_path(t) + "\"";
   }

   xsd.writeln("<xsd:simpleType" + typeAttribute + ">");
   xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:string\">");

   xsd.incNestLevel();

   list<string> enums;
   
   for (auto node : t->TopNode) {
      buildEnum(&enums, "", node);
   }

   for (auto entry : enums) {
      xsd.writeln("<xsd:enumeration value=\"" + entry + "\"/>");
   }

   //for (auto v : t->ETVT) {
   //   xsd.writeln("<xsd:enumeration value=\"" + v->Name + "\"/>");
   //}

   xsd.writelnDecNestLevel("</xsd:restriction>");
   xsd.writelnDecNestLevel("</xsd:simpleType>");
}

void XsdOutput::write_numtype(metamodel::NumType *t) {
   string typeAttribute = "";

   if (t->Name != "" && t->Name != "TOP" && t->Name != "TYPE") {
      typeAttribute = " name=\"" + get_path(t) + "\"";
   }

   xsd.writeln("<xsd:simpleType" + typeAttribute + ">");

   if (t->Abstract) {
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:double\">");
      xsd.writeln("</xsd:restriction>");
   }
   else {
      if (t->Min.find(".") < t->Min.length()) {
         xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:double\">");
      }
      else {
         xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:integer\">");
      }

      xsd.writelnIncNestLevel("<xsd:minInclusive value=\"" + t->Min + "\"/>");
      xsd.writeln("<xsd:maxInclusive value=\"" + t->Max + "\"/>");
      xsd.writelnDecNestLevel("</xsd:restriction>");
   }

   
   xsd.writelnDecNestLevel("</xsd:simpleType>");
}

void XsdOutput::write_linetype(metamodel::LineType *t) {
   string typeAttribute = "";

   if (t->Name != "" && t->Name != "TOP" && t->Name != "TYPE") {
      typeAttribute = " name=\"" + get_path(t) + "\"";
   }

   if (t->Kind == t->Polyline || t->Kind == t->DirectedPolyline) {
      xsd.writeln("<xsd:complexType" + typeAttribute + ">");
      xsd.writelnIncNestLevel("<xsd:sequence>");
      xsd.writelnIncNestLevel("<xsd:element name=\"POLYLINE\">");

      xsd.writelnIncNestLevel("<xsd:complexType>");
      xsd.writelnIncNestLevel("<xsd:choice minOccurs=\"2\" maxOccurs=\"unbounded\">");
      xsd.writelnIncNestLevel("<xsd:element name=\"COORD\" type=\"CoordValue\"/>");
      
      for (auto *lf : t->LineForm) {
         if (lf->Name == "STRAIGHTS") {

         }
         else if (lf->Name == "ARCS") {
            xsd.writeln("<xsd:element name=\"ARC\" type=\"ArcPoint\"/>");
         }
         else {
            xsd.writeln("<xsd:element name=\"" + get_path(lf) + "\" type=\"" + get_path(lf->Structure) + "\"/>");
         }
      }

      xsd.writelnDecNestLevel("</xsd:choice>");
      xsd.writelnDecNestLevel("</xsd:complexType>");

      xsd.writelnDecNestLevel("</xsd:element>");
      xsd.writelnDecNestLevel("</xsd:sequence>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
   }
   else if (t->Kind == t->Area || t->Kind == t->Surface) {
      xsd.writeln("<xsd:complexType" + typeAttribute + ">");
      xsd.writelnIncNestLevel("<xsd:sequence>");
      xsd.writelnIncNestLevel("<xsd:element name=\"SURFACE\">");
      xsd.writelnIncNestLevel("<xsd:complexType>");
      xsd.writelnIncNestLevel("<xsd:sequence>");
      xsd.writelnIncNestLevel("<xsd:element name=\"BOUNDARY\" maxOccurs=\"unbounded\">");
      xsd.writelnIncNestLevel("<xsd:complexType>");
      xsd.writelnIncNestLevel("<xsd:sequence>");
      xsd.writelnIncNestLevel("<xsd:element name=\"POLYLINE\" maxOccurs=\"unbounded\">");

      xsd.writelnIncNestLevel("<xsd:complexType>");

      bool hasLineAttr = false;
      if (t->LAStructure != nullptr) {
         hasLineAttr = true;
         xsd.writelnIncNestLevel("<xsd:sequence>");
         xsd.writelnIncNestLevel("<xsd:element name=\"LINEATTR\">");
         xsd.writelnIncNestLevel("<xsd:complexType>");
         xsd.writelnIncNestLevel("<xsd:sequence>");
         xsd.writelnIncNestLevel("<xsd:element name=\"" + get_path(t->LAStructure) + "\" type=\"" + get_path(t->LAStructure) + "\"/>");
         xsd.writelnDecNestLevel("</xsd:sequence>");
         xsd.writelnDecNestLevel("</xsd:complexType>");
         xsd.writelnDecNestLevel("</xsd:element>");
      }

      xsd.writeln("<xsd:choice minOccurs=\"2\" maxOccurs=\"unbounded\">");
      xsd.writelnIncNestLevel("<xsd:element name=\"COORD\" type=\"CoordValue\"/>");

      for (auto *lf : t->LineForm) {
         if (lf->Name == "STRAIGHTS") {

         }
         else if (lf->Name == "ARCS") {
            xsd.writeln("< xsd:element name = \"ARC\" type=\"ArcPoint\"/>");
         }
         else {
            xsd.writeln("< xsd:element name = \"ARC\" name=\"" + get_path(lf) + "\" type=\"" + get_path(lf->Structure) + "\"/>");
         }
      }

      xsd.writelnDecNestLevel("</xsd:choice>");
      if (hasLineAttr) {
         xsd.writelnDecNestLevel("</xsd:sequence>");
      }

      xsd.writelnDecNestLevel("</xsd:complexType>");

      xsd.writelnDecNestLevel("</xsd:element>");
      xsd.writelnDecNestLevel("</xsd:sequence>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
      xsd.writelnDecNestLevel("</xsd:element>");
      xsd.writelnDecNestLevel("</xsd:sequence>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
      xsd.writelnDecNestLevel("</xsd:element>");
      xsd.writelnDecNestLevel("</xsd:sequence>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
   }
}

void XsdOutput::write_formattedtype(metamodel::FormattedType *t) {
   string typeAttribute = "";

   if (t->Name != "" && t->Name != "TOP" && t->Name != "TYPE") {
      typeAttribute = " name=\"" + get_path(t) + "\"";
   }

   xsd.writeln("<xsd:simpleType" + typeAttribute + ">");

   if (t->Format == "INTERLIS.XMLDate") {
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:date\">");
      xsd.writelnIncNestLevel("<xsd:minInclusive value=\"" + t->Min + "\"/>");
      xsd.writeln("<xsd:maxInclusive value=\"" + t->Max + "\"/>");
   }
   else if (t->Format == "INTERLIS.XMLDateTime") {
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:dateTime\">");
      xsd.writelnIncNestLevel("<xsd:minInclusive value=\"" + t->Min + "\"/>");
      xsd.writeln("<xsd:maxInclusive value=\"" + t->Max + "\"/>");
   }
   else if (t->Format == "INTERLIS.XMLTime") {
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:time\">");
      xsd.writelnIncNestLevel("<xsd:minInclusive value=\"" + t->Min + "\"/>");
      xsd.writeln("<xsd:maxInclusive value=\"" + t->Max + "\"/>");
   }
   else {
      xsd.writelnIncNestLevel("<xsd:restriction base=\"xsd:normalizedString\">");
      xsd.incNestLevel();
   }

   xsd.writelnDecNestLevel("</xsd:restriction>");
   xsd.writelnDecNestLevel("</xsd:simpleType>");
}

void XsdOutput::write_blackboxtype(metamodel::BlackboxType *t) {
   string typeAttribute = "";

   if (t->Name != "" && t->Name != "TOP" && t->Name != "TYPE") {
      typeAttribute = " name=\"" + get_path(t) + "\"";
   }

   xsd.writeln("<xsd:complexType" + typeAttribute + ">");
   xsd.writelnIncNestLevel("<xsd:sequence>");

   if (t->Kind == t->Binary) {
      xsd.writelnIncNestLevel("<xsd:element name=\"BINBLBOX\">");
   }
   else {
      xsd.writelnIncNestLevel("<xsd:element name=\"XMLBLBOX\">");
   }

   xsd.writelnIncNestLevel("<xsd:complexType>");

   if (t->Kind == t->Binary) {
      xsd.writelnIncNestLevel("<xsd:simpleContent>");
      xsd.writelnIncNestLevel("<xsd:extension base=\"xsd:base64Binary\"/>");
      xsd.writelnDecNestLevel("</xsd:simpleContent>");
   }
   else {
      xsd.writelnIncNestLevel("<xsd:sequence>");
      xsd.writelnIncNestLevel("<xsd:any minOccurs=\"0\" maxOccurs=\"unbounded\" processContents=\"skip\"/>");
      xsd.writelnDecNestLevel("</xsd:sequence>");
   }

   xsd.writelnDecNestLevel("</xsd:complexType>");

   xsd.writelnDecNestLevel("</xsd:element>");
   xsd.writelnDecNestLevel("</xsd:sequence>");
   xsd.writelnDecNestLevel("</xsd:complexType>");
}

void XsdOutput::write_referencetype(metamodel::ReferenceType *t) {
   string typeAttribute = "";

   if (t->Name != "" && t->Name != "TOP" && t->Name != "TYPE") {
      typeAttribute = " name=\"" + get_path(t) + "\"";
   }

   xsd.writeln("<xsd:complexType" + typeAttribute + ">");
   xsd.writelnIncNestLevel("<xsd:attribute name=\"REF\" type=\"IliID\" use=\"required\"/>");
   xsd.writeln("<xsd:attribute name=\"BID\" type=\"IliID\"/>");
   xsd.writelnDecNestLevel("</xsd:complexType>");
}

void XsdOutput::write_multivalue(metamodel::MultiValue* t) {
   string typeAttribute = "";

   if (t->Name != "" && t->Name != "TOP" && t->Name != "TYPE") {
      typeAttribute = " name=\"" + get_path(t) + "\"";
   }

   string minOccurs = "";
   string maxOccurs = "";

   if (t->Multiplicity.Min > 1) {
      minOccurs = " minOccurs=\"" + to_string(t->Multiplicity.Min) + "\"";
   }

   if (t->Multiplicity.Max != 1) {
      if (t->Multiplicity.Max == -1) {
         maxOccurs = " maxOccurs=\"unbounded\"";
      }
      else {
         maxOccurs = " maxOccurs=\"" + to_string(t->Multiplicity.Max) + "\"";
      }
   }

   xsd.writeln("<xsd:complexType" + typeAttribute + ">");
   xsd.writelnIncNestLevel("<xsd:sequence>");

   xsd.incNestLevel();

   if (t->TypeRestriction.size() > 0) {
      for (auto *entry : t->TypeRestriction) {
         xsd.writeln("<xsd:element name=\"" + get_path(entry) + "\" type=\"" + get_path(entry) + "\"" + minOccurs + maxOccurs + "/>");
      }
   }
   else {
      xsd.writeln("<xsd:element name=\"" + get_path(t->BaseType) + "\" type=\"" + get_path(t->BaseType) + "\"" + minOccurs + maxOccurs + "/>");
   }
   

   xsd.writelnDecNestLevel("</xsd:sequence>");
   xsd.writelnDecNestLevel("</xsd:complexType>");
}

void XsdOutput::visitDomainType(metamodel::DomainType *t) {
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

void XsdOutput::preVisitModel(metamodel::Model* m) {
   /*if (m->Name == "INTERLIS") {
      ignoreVisit();
   }*/
}

void XsdOutput::preVisitClass(metamodel::Class *c) {
   if (c->Kind == c->Association) {
      //ignoreVisit();
      return;
   }

   xsd.writeln("<xsd:complexType name=\"" + get_path(c) + "\">");
   xsd.writelnIncNestLevel("<xsd:sequence>");

   xsd.incNestLevel();
}

void XsdOutput::postVisitClass(metamodel::Class *c) {
   if (c->Kind == c->Association) {
      //ignoreVisit();
      return;
   }

   xsd.writelnDecNestLevel("</xsd:sequence>");

   if (c->Kind == c->ClassVal) {
      if (c->Oid == nullptr) {
         xsd.writeln("<xsd:attribute name=\"TID\" type=\"IliID\" use=\"required\"/>");
      }
   }
   else if (c->Kind == c->Association) {
   }

   xsd.writelnDecNestLevel("</xsd:complexType>");
}

void XsdOutput::postVisitSubModel(metamodel::SubModel *s) {
   Log.warning("check XSDGenerator lines 834-896");

   xsd.writeln("<xsd:complexType name=\"" + get_path(s) + "\">");
   xsd.writelnIncNestLevel("<xsd:sequence>");
   xsd.writelnIncNestLevel("<xsd:choice minOccurs=\"0\" maxOccurs=\"unbounded\">");

   xsd.incNestLevel();

   for (auto *a : s->Element) {
      if (a->getClass() == "Class") {
         Class *c = static_cast<Class *>(a);

         if (c->Kind == c->ClassVal) {
            xsd.writeln("<xsd:element name=\"" + get_path(a) + "\" type=\"" + get_path(a) + "\"/>");
         }

         
      }
   }

   xsd.decNestLevel();

   xsd.writeln("</xsd:choice>");
   xsd.writelnDecNestLevel("</xsd:sequence>");

   xsd.writeln("<xsd:attribute name=\"BID\" type=\"IliID\" use=\"required\"/>");

   xsd.writelnDecNestLevel("</xsd:complexType>");
}

void XsdOutput::visitAttrOrParam(metamodel::AttrOrParam *a) {
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
         xsd.writeln("<xsd:element name=\"" + a->Name + "\" type=\"xsd:boolean\"" + minOccurs + "/>");
      }
      else if (a->Type->Name == "XMLDate") {
         xsd.writeln("<xsd:element name=\"" + a->Name + "\" type=\"xsd:date\"" + minOccurs + "/>");
      }
      else if (a->Type->Name == "XMLDateTime") {
         xsd.writeln("<xsd:element name=\"" + a->Name + "\" type=\"xsd:dateTime\"" + minOccurs + "/>");
      }
      else if (a->Type->Name == "XMLTime") {
         xsd.writeln("<xsd:element name=\"" + a->Name + "\" type=\"xsd:time\"" + minOccurs + " / > ");
      }
      else {
         if (a->Type->_other_type != nullptr) {
            xsd.writeln("<xsd:element name=\"" + a->Name + "\" type=\"" + get_path(a->Type->_other_type) + "\"" + minOccurs + "/>");
         }
         else {
            xsd.writeln("<xsd:element name=\"" + a->Name + "\" type=\"" + get_path(a->Type) + "\"" + minOccurs + "/>");
         }
      }

      return;
   }

   xsd.writeln("<xsd:element name=\"" + a->Name + "\"" + minOccurs + ">");

   xsd.incNestLevel();
   writeType(t);

   xsd.decNestLevel();
   xsd.writeln("</xsd:element>");
}

void XsdOutput::visitRole(metamodel::Role *r) {
   if (r->Multiplicity.Min == 1 && r->Multiplicity.Max == -1) {
      /*xsd.writeln("<xsd:element name=\"" + get_path(r) + "\">");
      xsd.writelnIncNestLevel("<xsd:complexType>");
      xsd.writelnIncNestLevel("<xsd:attribute name=\"REF\" type=\"IliID\" use=\"required\"/>");
      xsd.writeln("<xsd:attribute name=\"BID\" type=\"IliID\"/>");
      xsd.writeln("<xsd:attribute name=\"ORDER_POS\" type=\"xsd:positiveInteger\"/>");
      xsd.writelnDecNestLevel("</xsd:complexType>");
      xsd.writelnDecNestLevel("</xsd:element>");*/
   }
}

void XsdOutput::buildEnum(list<string> *list,string prefix, metamodel::EnumNode *enumNode) {
   if (prefix.length() > 0) {
      prefix += ".";
   }

   if (enumNode->Node.size() == 0) {
      list->push_back(prefix + enumNode->Name);
   }
   else {
      for (auto *node : enumNode->Node) {
         buildEnum(list,prefix+ enumNode->Name,node);
      }
   }
}