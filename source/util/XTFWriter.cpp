#include "XTFWriter.h"

#include "Logger.h"
#include "../metamodel/MetaModel.h"

using namespace util;

//------------------------------------------------------------------------
// private interface
//------------------------------------------------------------------------

void XTFWriter::openTransfer()
{
   StringMap attributes;
   attributes.put("xmlns","http://www.interlis.ch/INTERLIS2.3");
   xml.openTag("TRANSFER", attributes);
};

void XTFWriter::closeTransfer()
{
   xml.closeTag(); // TRANSFER
};

void XTFWriter::openDataSection()
{
   xml.openTag("DATASECTION");
};

void XTFWriter::closeDataSection()
{
   xml.closeTag(); // DATASECTION
};

extern string get_version_string();

void XTFWriter::writeHeaderSection(list<metamodel::Model *> models)
{

   StringMap attributes;
   attributes.put("SENDER",get_version_string());
   attributes.put("VERSION","2.3");
   xml.openTag("HEADERSECTION", attributes); 

   xml.openTag("MODELS");
   for (metamodel::Model *m : models) {
      if (m->Name == "INTERLIS") {
         continue;
      }
      StringMap attrs;
      attrs.put("NAME",m->Name);
      attrs.put("VERSION",m->Version);
      attrs.put("URI","unknown");
      xml.writeTag("MODEL",attrs);
   }
   xml.closeTag(); // MODELS

   xml.closeTag(); // HEADERSECTION

};

//------------------------------------------------------------------------
// public interface
//------------------------------------------------------------------------

void XTFWriter::openFile(string xtf_file,list<metamodel::Model *> models)
{
   xml.openFile(xtf_file,"UTF-8");
   openTransfer();
   writeHeaderSection(models);
   openDataSection();
};

void XTFWriter::closeFile()
{
   closeDataSection();
   closeTransfer();
   xml.closeFile();
};

void XTFWriter::openTag(string tag, StringMap attributes)
{
   xml.openTag(tag, attributes);
};

void XTFWriter::openTag(string tag)
{
   xml.openTag(tag);
};

void XTFWriter::closeTag()
{
   xml.closeTag();
};

void XTFWriter::writeTag(string tag, string content)
{
   if (content == "" || content == "-1") {
      return;
   }
   StringMap attributes;
   xml.writeTag(tag,attributes,content);
};

void XTFWriter::writeTag(string tag, StringMap attributes)
{
   xml.writeTag(tag,attributes);
};

void XTFWriter::writeTag(string tag, StringMap attributes,string content)
{
   xml.writeTag(tag,attributes,content);
};

void XTFWriter::writeReference(string tag, string target)
{
   if (target == "nullptr" || target == "unknown") {
      return;
   }
   StringMap attributes;
   attributes.put("REF",target);
   xml.writeTag(tag,attributes);
};

void XTFWriter::openBasket(string model, string topic, string bid)
{
   StringMap attributes;
   attributes.put("BID",bid);
   openTag(model + "." + topic,attributes);
};

void XTFWriter::closeBasket()
{
   closeTag();
};

void XTFWriter::openObject(string model, string topic, string class_name, string tid, StringMap attributes)
{
   if (tid != "unknown") {
      attributes.put("TID",tid);
   }
   openTag(model + "." + topic + "." + class_name, attributes);
};

void XTFWriter::openObject(string model, string topic, string class_name, string tid)
{
   StringMap attributes;
   if (tid != "unknown") {
      attributes.put("TID",tid);
   }
   openTag(model + "." + topic + "." + class_name, attributes);
};

void XTFWriter::openObject(string model, string topic, string class_name)
{
   openTag(model + "." + topic + "." + class_name);
};

void XTFWriter::writeComment(string comment)
{
   xml.writeComment(comment);
};

void XTFWriter::closeObject()
{
   closeTag();
};
