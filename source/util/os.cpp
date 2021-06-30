#include <string>

#include "os.h"

string util::get_platform()
{
#ifdef _WIN32
   const string os = "win";
#elif __unix__
   const string os = "unix";
#elif __linux__
   const string os = "linux";
#elif __APPLE__
   const string os = "macos";
#endif
   if (sizeof(void *) == 8) {
      return os + "64";
   }
   else {
      return os + "32";
   }
}
