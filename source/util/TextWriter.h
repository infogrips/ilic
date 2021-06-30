#pragma once

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

namespace util {

   class TextWriter {
   public:
      void openFile(string output_file);
      void closeFile();
      void setNestLevel(int nestlevel);
      int getNestLevel();
      void incNestLevel();
      void decNestLevel();
      void write(string buffer);
      void write(int nestlevel, string buffer);
      void writeNoIdent(string buffer);
      void writeln(string buffer);
      void writelnNoIdent(string buffer);
      void writeln(int nestlevel, string buffer);
      void writelnIncNestLevel(string buffer);
      void writelnDecNestLevel(string buffer);
   private:
      ofstream out;
      int nestlevel = 0;
      void ident(int nestlevel);
   };

};
