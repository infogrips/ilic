#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include "ilic.h"

using namespace nana;

int show_gui()
{
   form fm;
   fm.caption((get_program_name() + " version " + get_version()).c_str());
   label lb(fm, rectangle(fm.size()));
   lb.caption((get_version_string().c_str()));
   fm.show();
   exec();
   return 0;
}