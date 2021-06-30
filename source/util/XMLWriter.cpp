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

void XMLWriter::ident()
{
   for (int i = 0; i < nestLevel; i++) {
      out << "   ";
   }
};

void XMLWriter::writeAttributes(StringMap attributes)
{
   for (auto key : attributes.getKeys()) {
      string value = attributes.get(key);
      if (value.substr(0,1) == "\"") {
         out << " " << key << "=" << value;
      }
      else {
         out << " " << key << "=" << "\"" << value << "\"";
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

   out << content;
};

//----------------------------------------------------------------------
// public interface
//----------------------------------------------------------------------

void XMLWriter::openFile(string output_file,string encoding)
{
   out.open(output_file);
   out << "<?xml version=\"1.0\" encoding=\"" + encoding + "\" ?>\n";
};

void XMLWriter::closeFile()
{
   out.close();
};

void XMLWriter::openTag(string tag,StringMap attributes)
{

   ident();

   out << "<" << tag;
   writeAttributes(attributes);
   out << ">\n";

   tags.push_back(tag);
   nestLevel++;

};

void XMLWriter::openTag(string tag)
{
   StringMap attributes; // empty attribute list
   openTag(tag,attributes);
};

void XMLWriter::closeTag()
{
   nestLevel--;
   ident();
   out << "</" << tags.back() << ">\n";
   tags.pop_back();
};

void XMLWriter::writeTag(string tag,StringMap attributes)
{
   ident();
   out << "<" << tag;
   writeAttributes(attributes);
   out << "/>\n";
};

void XMLWriter::writeTag(string tag, string content)
{

   if (content == "" || content == "unknown" || content == "nullptr") {
      return;
   }

   ident();

   // opening tag
   out << "<" << tag;
   out << ">";

   // content
   writeContent(content);

   // closing tag
   out << "</" << tag << ">\n";

};

void XMLWriter::writeTag(string tag,StringMap attributes,string content)
{

   ident();

   // opening tag
   out << "<" << tag;
   writeAttributes(attributes);
   out << ">";

   // content
   writeContent(content);
   
   // closing tag
   out << "</" << tag << ">\n";

};

void XMLWriter::writeComment(string comment)
{

   ident();

   out << "<!-- " << comment << " -->\n";

};
