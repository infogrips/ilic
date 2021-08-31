#pragma once

#include "MetaModel.h"

using namespace std;

namespace metamodel {

   extern Class *ANYCLASS;
   extern Class *ANYSTRUCTURE;

   class InterlisModel : public metamodel::Model {
   public:

      InterlisModel(string iliversion);

   };

};
