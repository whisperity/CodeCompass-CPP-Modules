#define MODULE_EXPORT

export module FULL_NAME_CppParser;

/* Header files */

#include "./include/cppparser/filelocutil.h"
#include "./include/cppparser/cppparser.h"
#include "./src/clangastvisitor.h"
#include "./src/diagnosticmessagehandler.h"
#include "./src/doccommentcollector.h"
#include "./src/doccommentformatter.h"
#include "./src/entitycache.h"
#include "./src/ppincludecallback.h"
#include "./src/ppmacrocallback.h"
#include "./src/relationcollector.h"
#include "./src/symbolhelper.h"

/* Source files */

#include "./src/diagnosticmessagehandler.cpp"
#include "./src/doccommentformatter.cpp"
#include "./src/entitycache.cpp"
#include "./src/ppincludecallback.cpp"
#include "./src/ppmacrocallback.cpp"
#include "./src/relationcollector.cpp"
#include "./src/symbolhelper.cpp"
#include "./src/cppparser.cpp"
