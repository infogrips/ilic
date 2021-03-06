#include "stdio.h"
#include <iostream>
#include <list>

#include "../util/os.h"
#include "../util/StringMap.h"
#include "../util/StringUtil.h"
#include "../util/Logger.h"
#include "../util/IliFile.h"

#include "../input/ili1/Ili1Input.h"
#include "../input/ili2/Ili2Input.h"
#include "../input/ili2/InterlisModel.h"

#include "../metamodel/MetaModelInput.h"

#include "../output/Ili1Output.h"
#include "../output/Ili2Output.h"
#include "../output/ImdOutput.h"
#include "../output/XsdOutput.h"
#include "../output/GmlOutput.h"

#include "ilic.h"
//#include "Gui.h"

using namespace std;
using namespace util;
using namespace metamodel;
string model_filter = "";

static void abort(int exitcode)
{
   Log.internal_error("compilation aborted with status " + to_string(exitcode),exitcode);
}

string get_program_name()
{
   return "ilic";
}

string get_version()
{
   return "0.9.9";
}

string get_version_string()
{
   return get_program_name() + " " + get_version() 
      + " (builddate=" + ansi_date_to_ymd(__DATE__) + ", platform=" + get_platform() + ")";
}

static void display_version() {
	Log.message(get_version_string());
   Log.message("");
   Log.incNestLevel();
	Log.message("Distributed by the Coordination of Geographic Information");
	Log.message("and Geographic Information Systems Group (COSIG), CH-3084 Wabern.");
	Log.message("Developed and maintained by infoGrips GmbH, CH-8005 Zurich.");
	Log.message("See http://www.interlis.ch for information about INTERLIS.");
	Log.message("Parts of this program have been generated by ANTLR; see http://www.antlr.org");
	Log.message("Parts of this program have been taken from the ili2c compiler project.");
   Log.message(get_program_name() + " is free software without any license restrictions. The project is");
   Log.message("maintained on http://github.com/infogrips/ilic.");
   Log.decNestLevel();
}

static void display_description() {
	Log.message("DESCRIPTION");
   Log.message("");
   Log.incNestLevel();
   Log.message("Compiles INTERLIS Version 1.0, 2.3 and 2.4 data model definitions and validates them.");
   Log.message("ilic can generate output in serveral formats (ili, imd, xsd, gml).");
   Log.decNestLevel();
}

static void display_options() {

   Log.message("OPTIONS");
   Log.incNestLevel();

   Log.message("");
   Log.message("input options:");
   Log.message("-ilidirs");
   Log.message("   list of directories to search for .ili files separated by semicolons.");
   Log.message("-no_auto|-no-auto");
   Log.message("   don't search automatically for missing models.");

   Log.message("");
   Log.message("output options:");
   Log.message("-o1 [ili_file] [-model_filter model_name]");
   Log.message("   generate INTERLIS 1.0 model definition for model model_name.");
   Log.message("-o23 [ili_file] | -o2 [ili_file] [-model_filter model_name]");
   Log.message("   generate INTERLIS 2.3 model definition.");
   Log.message("-o24 [ili_file] [-model model_filter]");
   Log.message("   generate INTERLIS 2.4 model definition.");
   Log.message("-oIMD [imd_file]");
   Log.message("   generate IlisMeta07 output.");
   Log.message("-oXSD [xsd_file]");
   Log.message("   generate xml schema for xtf transfer.");
   Log.message("-oGML [gml_file]");
   Log.message("   generate gml schema for transfer.");
   Log.message("-out|-output file (for compatiblity with ili2c compiler only)");
   Log.message("   file for output");

   Log.message("");
   Log.message("log options:");
   Log.message("-log logfile");
   Log.message("   generate log file");
   Log.message("-silent|-quiet");
   Log.message("    suppress all messages.");
   Log.message("-no_info");
   Log.message("   display no info messages.");
   Log.message("-no_warnings|-without-warnings");
   Log.message("   display no warnings.");
   Log.message("-no_errors");
   Log.message("   display no errors.");
   Log.message("-debug");
   Log.message("   display debug messages.");

   Log.message("");
   Log.message("other options:");
   Log.message("-h|-help");
   Log.message("    display this help text.");
   Log.message("-u|-usage");
   Log.message("   display short information about usage.");
   Log.message("-v|-version");
   Log.message("   display the version of ili2c.");
   Log.message("-werror");
   Log.message("   treat warnings as errors.");
   Log.message("-success success_status");
   Log.message("   return status success_status, if no errors detected (default: 0).");
   Log.message("-indent spaces");
   Log.message("   number of ident spaces for output formats.");

   Log.decNestLevel();

}

static void display_usage() {
   Log.message("USAGE");
   Log.message("");
   Log.incNestLevel();
   Log.message(get_program_name() + " [options] file1.ili file2.ili ...");
   Log.decNestLevel();
}

static void display_examples() {
	Log.message("EXAMPLES");
   Log.incNestLevel();
   Log.message("");
	Log.message("check whether INTERLIS definition in \"file.ili\" is valid:");
	Log.message("   " + get_program_name() + " file.ili");
	Log.message("");
	Log.message("check whether definitions distributed over several files are valid:");
	Log.message("   " + get_program_name() + " file1.ili file2.ili");
   Log.message("");
   Log.message("generate INTERLIS 1 model definition:");
   Log.message("   " + get_program_name() + " -o1 file1.ili file.ili");
   Log.message("");
   Log.message("generate INTERLIS 2.4 model definition:");
   Log.message("   " + get_program_name() + " -o24 file24.ili file.ili");
   Log.message("");
   Log.message("generate INTERLIS metamodel format:");
   Log.message("   " + get_program_name() + " -oIMD file.imd file1.ili file2.ili");
   Log.message("");
   Log.message("generate XML-Schema:");
   Log.message("   " + get_program_name() + " -oXSD file.xsd file1.ili file2.ili");
   Log.message("");
   Log.message("generate INTERLIS meta format and XML-Schema:");
   Log.message("   " + get_program_name() + " -oIMD file.imd -oXSD file.xsd file1.ili file2.ili");
   Log.decNestLevel();
}

static void display_help() {
   Log.message("");
   display_version();
   Log.message("");
   display_description();
   Log.message("");
   display_usage();
   Log.message("");
   display_options();
   Log.message("");
   display_examples();
}

StringMap parse_arguments(int argc, char* argv[])
{

   StringMap arguments;
   string key = "";
   string value = "";
   int fid = 1;
   
   for (int i=1;i<argc;i++) {
      string arg = argv[i];
      if (arg.find("--") == 0) {
         key = arg.substr(2);
      }
      else if (arg.find("-") == 0) {
         key = arg.substr(1);
      }
      else if (ends_with(arg,".ili")) {
         if (key != "o1" && key != "o23" && key != "o24") {
            key = "ilifile" + to_string(fid++);
         }
         value = arg;
      }
      else {
         value = arg;
      }
      if (key != "") {
         if (key == "o2") {
            key = "o23";
         }
         else if (key == "out") {
            key = "output";
         }
         else if (key == "v") {
            key = "version";
         }
         else if (key == "u") {
            key = "usage";
         }
         else if (key == "h") {
            key = "help";
         }
         else if (key == "quiet") {
            key = "silent";
         }
         else if (arg == "without-warnings") {
            key = "no_warnings";
         }
         else if (arg == "no-auto") {
            key = "no_auto";
         }
         arguments.put(key,value);
         value = "";
      }
   }

   return arguments;

}

static void check_arguments(StringMap arguments) 
{
   
   if (arguments.size() == 0) {
      display_help();
		exit(0);
	}

   for (auto arg : arguments.getKeys()) {
      if (arg == "no_auto") {
         continue;
      }
      else if (arg == "o1") {
         continue;
      }
      else if (arg == "o23") {
         continue;
      }
      else if (arg == "o24") {
         continue;
      }
      else if (arg == "oXSD") {
         continue;
      }
      else if (arg == "oGML") {
         continue;
      }
      else if (arg == "oIMD") {
         continue;
      }
      else if (arg == "output") {
         continue;
      }
      else if (arg == "ilidirs") {
         continue;
      }
      else if (arg == "silent") {
         continue;
      }
      else if (arg == "no_info") {
         continue;
      }
      else if (arg == "no_warnings") {
         continue;
      }
      else if (arg == "no_errors") {
         continue;
      }
      else if (arg == "debug") {
         continue;
      }
      else if (arg == "help") {
         continue;
      }
      else if (arg == "usage") {
         continue;
      }
      else if (arg == "version") {
         continue;
      }
      else if (arg == "log") {
         continue;
      }
      else if (arg.find("ilifile") == 0) {
         continue;
      }
      else if (arg.find("gui") == 0) {
         continue;
      }
      else if (arg.find("model_filter") == 0) {
         continue;
      }
      else if (arg == "werror") {
         continue;
      }
      else if (arg == "success") {
         continue;
      }
      else if (arg == "ident") {
         continue;
      }
      else {
         Log.error("unknown argument -" + arg + "/--" + arg);
         abort(1);
      }
   }
   
}

static list<IliFile *> compiled_files;
static list<string> compiled_models;
static bool compile(IliFile *f)
{
   
   if (f->getIliVersion() == "1.0") {
   }
   else if (f->getIliVersion() == "2.3") {
   }
   else if (f->getIliVersion() == "2.4") {
   }
   else {
      Log.error(f->getFilePath() + ": unsupported iliversion " + f->getIliVersion());
      Log.decNestLevel();
      abort(1);
   }
   
   for (auto ff : compiled_files) {
      if (ff == f) {
         return true;
      }
   }
   
   // verify if all imported models are in the same file or already compiled
   for (auto import : f->getImports()) {
      bool found = false;
      // search in same file
      for (auto model : f->getModels()) {
         if (model == import) {
            found = true;
            break;
         }
      }

      for (auto model : f->getModels()) {
         if (model == import) {
            found = true;
            break;
         }
      }

      if (!found) {
         // search in already compiled files
         for (auto model : compiled_models) {
            if (model == import) {
               found = true;
               break;
            }
         }
      }
      if (!found) {
         return false; // not ready to compile f
      }
   }

   Log.info("");
   Log.info("compiling " + f->getFilePath() + " ...");
   Log.incNestLevel();
   int errors = Log.getErrorCount();

   // parse input
   if (f->getIliVersion() == "1.0") {
      input::parseIli1(f->getFilePath());
   }
   else {
      input::parseIli2(f->getFilePath());
   }
   
   compiled_files.push_back(f);
   if (f->getFilePath() == "INTERLIS") {
      compiled_models.push_back("INTERLIS");
   }
   else {
      for (auto model : f->getModels()) {
         compiled_models.push_back(model);
      }
   }

   Log.decNestLevel();
   if (Log.getErrorCount() == errors) {
      Log.info(f->getFilePath() + " compiled.");
   }
   else {
      Log.info(f->getFilePath() + " compiled with errors.");
   }
   
   return true;

}

static void generate_ili1(string ili1_file,Model *m)
{
   Log.info("");
   Log.info("generating " + ili1_file + ", model=" + m->Name + " ...");
   Log.incNestLevel();
   output::Ili1Output *ili1output = new output::Ili1Output(ili1_file);
   ili1output->visit(m);
   Log.decNestLevel();
   Log.info("done.");
}

static void generate_ili23(string ili23_file)
{
   Log.info("");
   Log.info("generating " + ili23_file + " ...");
   Log.incNestLevel();
   output::Ili2Output *ili23output = new output::Ili2Output(ili23_file,"2.3");
   if (model_filter == "") {
      ili23output->visitAllModels();
   }
   else {
      ili23output->preVisit();
      for (auto m : get_all_models()) {
         if (m->Name == model_filter) {
            ili23output->visit(m);
         }
      }
      ili23output->postVisit();
   }
   Log.decNestLevel();
   Log.info("done.");
}

static void generate_ili24(string ili24_file)
{
   Log.info("");
   Log.info("generating " + ili24_file + " ...");
   Log.incNestLevel();
   output::Ili2Output *ili24output = new output::Ili2Output(ili24_file, "2.4");
   if (model_filter == "") {
      ili24output->visitAllModels();
   }
   else {
      ili24output->preVisit();
      for (auto m : get_all_models()) {
         if (m->Name == model_filter) {
            ili24output->visit(m);
         }
      }
      ili24output->postVisit();
   }
   Log.decNestLevel();
   Log.info("done.");
}

static void generate_imd(string imd_file,string iliversion)
{
   Log.info("");
   Log.info("generating " + imd_file + " ...");
   Log.incNestLevel();
   output::ImdOutput *imdoutput = new output::ImdOutput(imd_file,iliversion);
   imdoutput->visitAllModels();
   Log.decNestLevel();
   Log.info("done.");
}

static void generate_xsd(string xsd_file,string iliversion)
{
   Log.info("");
   Log.info("generating " + xsd_file + " ...");
   Log.incNestLevel();
   output::XsdOutput *xsdoutput = new output::XsdOutput(xsd_file,iliversion,get_version());
   xsdoutput->visitAllModels();
   Log.decNestLevel();
   Log.info("done.");
}

static void generate_gml(string gml_file)
{
   Log.info("");
   Log.info("generating " + gml_file + " ...");
   Log.incNestLevel();
   output::GmlOutput *gmloutput = new output::GmlOutput(gml_file,iliversion,get_version());
   gmloutput->visitAllModels();
   Log.decNestLevel();
   Log.info("done.");
}

int main(int argc, char* argv[])
{

   StringMap arguments = parse_arguments(argc,argv);
   check_arguments(arguments);
   bool help = false;
   bool usage = false;
   bool version = false;
   bool no_auto = false;
   string output = "";
   bool ili1 = false;
   string ili1_output = "interlis1.ili";
   bool ili23 = false;
   string ili23_output = "interlis23.ili";
   bool ili24 = false;
   string ili24_output = "interlis24.ili";
   bool imd = false;
   string imd_output = "output.imd";
   bool xsd = false;
   string xsd_output = "output.xsd";
   bool gml = false;
   string gml_output = "output.gml";
   string ilidirs = "";
   bool log_silent = false;
   bool log_info = true;
   bool log_warnings = true;
   bool log_errors = true;
   bool log_debug = false;
   string log = "";
   bool gui = false;
   int success_status = 0;

   for (auto arg : arguments.getKeys()) {

      string value = arguments.get(arg);
      
      if (arg == "help") {
         help = true;
      }
      else if (arg == "usage") {
         usage = true;
      }
      else if (arg == "version") {
         version = true;
      }
      else if (arg == "no_auto") {
         no_auto = true;
      }
      else if (arg == "oIMD") {
         imd = true;
         if (value != "") {
            imd_output = value;
         }
      }
      else if (arg == "o1") {
         ili1 = true;
         if (value != "") {
            ili1_output = value;
         }
      }
      else if (arg == "o23") {
         ili23 = true;
         if (value != "") {
            ili23_output = value;
         }
      }
      else if (arg == "o24") {
         ili24 = true;
         if (value != "") {
            ili24_output = value;
         }
      }
      else if (arg == "oXSD") {
         xsd = true;
         if (value != "") {
            xsd_output = value;
         }
      }
      else if (arg == "oGML") {
         gml = true;
         if (value != "") {
            gml_output = value;
         }
      }
      else if (arg == "output") {
         output = value;
         imd_output = value;
         xsd_output = value;
         gml_output = value;
      }
      else if (arg == "ilidirs") {
         ilidirs = value;
      }
      else if (arg == "silent") {
         log_silent = true;
      }
      else if (arg == "no_info") {
         log_info = false;
      }
      else if (arg == "no_warnings") {
         log_warnings = false;
      }
      else if (arg == "no_errors") {
         log_errors = false;
      }
      else if (arg == "debug") {
         log_debug = true;
      }
      else if (arg == "log") {
         log = value;
      }
      else if (arg == "model_filter") {
         model_filter = value;
      }
      else if (arg == "gui") {
         gui = true;
      }
      else if (arg == "success") {
         try {
            success_status = atoi(value.c_str());
         }
         catch (exception e) {
            Log.error("parameter success must be of type int");
         }
      }
      else if (arg == "ident") {
         try {
            Log.setIdentSpaces(atoi(value.c_str()));
         }
         catch (exception e) {
            Log.error("parameter ident must be of type int");
         }
      }
      else if (arg == "werror") {
         Log.warningsAsErrors();
      }
   }

   if (log != "") {
      Log.openFile(log);
   }

   Log.setSilent(log_silent);
   Log.displayInfo(log_info);
   Log.displayWarnings(log_warnings);
   Log.displayErrors(log_errors);
   Log.displayDebug(log_debug);
   
   if (help) {
      display_help();
      exit(0);
   }
   if (usage) {
      display_usage();
      Log.message("");
      display_examples();
      exit(0);
   }
   if (version) {
      display_version();
      exit(0);
   }
   if (gui) {
      //show_gui();
      exit(0);
   }

   Log.info(get_version_string());

   Log.info("");
   Log.info("loading ili files from command line ...");
   Log.incNestLevel();
   set_autosearch(!no_auto);
   set_ilidirs(ilidirs);
   for (auto arg : arguments.getKeys()) {
      string value = arguments.get(arg);
      if (arg.find("ilifile") == 0) {
         Log.info("loading " + value + " ...");
         Log.incNestLevel();
         if (!load_ilifiles_by_file(value)) {
            Log.info("not done.");
            abort(1);
         }
         Log.decNestLevel();
         Log.info("done.");
      }      
   }
   Log.decNestLevel();
   Log.info("done.");

   // get interlis version from last file
   string iliversion = all_ilifiles.back()->getIliVersion();
   metamodel::init(iliversion);

   Log.info("");
   Log.info("loading imported models ...");
   Log.incNestLevel();
   map<string,bool> loaded_models;
   while (true) {
      int fcount = all_ilifiles.size();
      for (IliFile *f : all_ilifiles) {
         for (string modelname : f->getImports()) {
            if (loaded_models[modelname]) {
               continue;
            }
            else if (modelname == "INTERLIS") {
               continue;
            }
            Log.info("searching for model " + modelname + " ...");
            Log.incNestLevel();
            IliFile *f = load_ilifiles_by_model(modelname,iliversion);
            if (f == nullptr) {
               Log.info("not found.");
               abort(1);
            }
            loaded_models[modelname] = true;
            Log.decNestLevel();
            Log.info("found in " + f->getFilePath() + ".");
         }
      }
      if (fcount == all_ilifiles.size()) {
         break;
      }
      else if (fcount == 100) {
         // something went wrong
         break;
      }
   }
   Log.decNestLevel();
   Log.info("done.");
      
   Log.info("");
   Log.info("all input files are:");
   for (IliFile *f : all_ilifiles) {
      string models = "";
      for (string model : f->getModels()) {
         if (models == "") {
            models = model;
         }
         else {
            models += "," + model;
         }
      }
      if (f->getFilePath() == "INTERLIS") {
         continue;
      }
      if (f->getAutoSearch()) {
         Log.info(1,f->getFilePath() + ", iliversion=" + f->getIliVersion() + ", models=" + models + ", auto search");
      }
      else {
         Log.info(1,f->getFilePath() + ", iliversion=" + f->getIliVersion() + ", models=" + models + ", command line");
      }
   }
   Log.info("done.");

   // compile all .ili files
   bool multiple_iliversions = false;
   compile(load_ilifiles_by_model("INTERLIS",iliversion));
   int count=0;
   while (true) {
      bool all_compiled = true;
      for (IliFile *f : all_ilifiles) {
         if (f->getIliVersion() != iliversion && f->getFilePath() != "INTERLIS") {
            multiple_iliversions = true;
         }
         all_compiled = compile(f) && all_compiled;
      }
      if (all_compiled) {
         break;
      }
      count++;
      if (count > 20) {
         Log.info("");
         Log.info("the following files do not compile:");
         for (IliFile *f : all_ilifiles) {
            if (!compile(f)) {
               Log.info("   " + f->getFilePath());
            }
         }
         Log.internal_error("endless compile loop");
      }
   }
   
   // list all models
   Log.info("");
   Log.info("all models are:");
   for (Model *m : get_all_models()) {
      Log.info(1, "model " + m->Name + ", iliversion=" + m->iliVersion + ", file=" + m->_ilifile);
   }
   if (multiple_iliversions) {
      Log.error("multiple iliversions found.");
   }
   Log.info("done.");
   
   if (Log.getErrorCount() == 0) {
      // generate output
      if (imd) {
         generate_imd(imd_output,iliversion);
      }
      if (ili1) {
         Model *m;
         if (model_filter == "") {
            m = get_all_models().back();
         }
         else {
            for (auto mm : get_all_models()) {
               if (mm->Name == model_filter) {
                  m = mm;
                  break;
               }
            }
         }
         generate_ili1(ili1_output,m);
      }
      if (ili23) {
         generate_ili23(ili23_output);
      }
      if (ili24) {
         generate_ili24(ili24_output);
      }
      if (xsd) {
         generate_xsd(xsd_output,iliversion);
      }
      if (gml) {
         generate_gml(gml_output);
      }
   }
   else if (imd || ili1 || ili23 || ili24 || xsd || gml) {
      Log.info("");
      Log.warning("no output generated, because of errors.");
   }
   
   Log.info("");
   string message = get_program_name() + " completed with";

   if (Log.getErrorCount() == 0) {
      message += " no errors";
   }
   else if (Log.getErrorCount() == 1) {
      message += " 1 error";
   }
   else {
      message += " " + to_string(Log.getErrorCount()) + " errors";
   }

   if (Log.getWarningCount() == 0) {
      message += ", no warnings";
   }
   else if (Log.getWarningCount() == 1) {
      message += ", 1 warning";
   }
   else {
      message += ", " + to_string(Log.getWarningCount()) + " warnings";
   }

   Log.info(message + ".");
   Log.closeFile();
   
   if (Log.getErrorCount() == 0) {
      return success_status;
   }
   else {
      return 1;
   }

}
