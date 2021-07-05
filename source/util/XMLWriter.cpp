/*

to do !!!

*/

#include "XMLWriter.h"
#include "Logger.h"

#include "../util/StringUtil.h"

using namespace util;

//----------------------------------------------------------------------
// private interface
//----------------------------------------------------------------------

void XMLWriter::writeAttributes(StringMap attributes)
{
   for (auto key : attributes.getKeys()) {
      string value = attributes.get(key);
      if (value.substr(0,1) == "\"") {
         txt.write(0," " + key + "=" + value);
      }
      else {
         txt.write(0," " + key + "=" + "\"" + value + "\"");
      }
   }
};

void XMLWriter::writeContent(string content)
{

   string pre_postfix = "\"";

   if (content.substr(0, pre_postfix.size()) == pre_postfix &&
      content.substr(content.size()-pre_postfix.size(),content.size()) == pre_postfix) {
      content = content.substr(1);
      content = content.substr(0, content.size() - 1);
   }

   txt.write(0,content);

};

//----------------------------------------------------------------------
// public interface
//----------------------------------------------------------------------

void XMLWriter::openFile(string output_file,string encoding)
{
   txt.openFile(output_file);
   txt.writeln(0,"<?xml version=\"1.0\" encoding=\"" + encoding + "\" ?>");
};

void XMLWriter::closeFile()
{
   txt.closeFile();
};

void XMLWriter::openTag(string tag,StringMap attributes)
{
   txt.writeln("<" + tag + ">");
   tags.push_back(tag);
   txt.incNestLevel();
};

void XMLWriter::openTag(string tag)
{
   StringMap attributes; // empty attribute list
   openTag(tag,attributes);
};

void XMLWriter::closeTag()
{
   txt.decNestLevel();
   txt.writeln("</" + tags.back() + ">");
   tags.pop_back();
};

void XMLWriter::writeTag(string tag,StringMap attributes)
{
   txt.write("<" + tag);
   writeAttributes(attributes);
   txt.writeln(0,"/>");
};

void XMLWriter::writeTag(string tag, string content)
{

   if (content == "" || content == "unknown" || content == "nullptr") {
      return;
   }

   // opening tag
   txt.write("<" + tag + ">");

   // content
   writeContent(content);

   // closing tag
   txt.writeln(0,"</" + tag + ">");

};

void XMLWriter::writeTag(string tag,StringMap attributes,string content)
{

   // opening tag
   txt.write("<" + tag);
   writeAttributes(attributes);
   txt.write(0,">");

   // content
   writeContent(content);
   
   // closing tag
   txt.writeln(0,"</" + tag + ">");

};

void XMLWriter::writeComment(string comment)
{
   txt.writeln("<!-- " + comment + " -->");
};
