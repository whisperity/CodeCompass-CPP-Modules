#define MODULE_EXPORT

export module FULL_NAME_Parser;

/* Header files */

#include "include/parser/abstractparser.h"
#include "include/parser/parsercontext.h"
#include "include/parser/pluginhandler.h"
#include "include/parser/sourcemanager.h"

/* Source files */

#include "src/parser.cpp"
#include "src/parsercontext.cpp"
#include "src/pluginhandler.cpp"
#include "src/sourcemanager.cpp"
