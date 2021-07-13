#include "StringUtil.h"

bool util::starts_with(std::string const &value, std::string const &start)
{
   return (value.rfind(start, 0) == 0);
}

bool util::ends_with(std::string const &value, std::string const &ending)
{
   if (ending.size() > value.size()) {
      return false;
   }
   return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

bool util::find_string(vector<string> list,string search_string)
{
   for (auto l : list) {
      if (l == search_string) {
         return true;
      }
   }
   return false;
}
