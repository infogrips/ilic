#pragma once

#include <string>
#include <vector>

using namespace std;

namespace util {

   bool starts_with(std::string const &value, std::string const &start);
   bool ends_with(std::string const &value, std::string const &ending);
   bool find_string(vector<string> list,string search_string);
   bool compare_case_insensitive(string s1,string s2);

}
