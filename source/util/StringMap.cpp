#include "StringMap.h"

using namespace std;

void util::StringMap::put(string key,string value)
{

   m[key] = value;

   // append key at end of list keys
   list<string> l;
   for (auto k : keys) {
      if (k == key) {
         // ignore key already in list
         continue;
      }
      l.push_back(k);
   }
   l.push_back(key);
   keys = l;

}

string util::StringMap::get(string key)
{
   return m[key];
}

list<string> util::StringMap::getKeys()
{
   return keys;
}

int util::StringMap::size()
{
   return keys.size();
}
