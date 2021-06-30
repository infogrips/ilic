#pragma once

#include <string>
#include <list>
#include <map>

using namespace std;

namespace util {

   class StringMap {
   public:
      void put(string key,string value);
      string get(string key);
      list<string> getKeys();
      int size();
   private:
      std::map<string,string> m;
      std::list<string> keys;
   };

};
