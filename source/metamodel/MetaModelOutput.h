#pragma once

#include <list>
#include "MetaModel.h"
#include "../util/TextWriter.h"

using namespace std;

namespace metamodel {

   // helper methods for output modules

   int count_metaelement(list <MetaElement*> l, string class_name);

   void write_expression(util::TextWriter *ili2,Expression *e);
   void write_enumtype(util::TextWriter *ili2,EnumType *t);

};
