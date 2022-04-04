#define MODULE_EXPORT

export module FULL_NAME_CppReparseService;

/* Header files */

#include "./include/service/cppreparseservice.h"
#include "./include/service/reparser.h"
#include "./src/astcache.h"
#include "./src/asthtml.h"
#include "./src/astnodelocator.h"
#include "./src/databasefilesystem.h"

/* Source files */

#include "./src/astcache.cpp"
#include "./src/asthtml.cpp"
#include "./src/cppreparseservice.cpp"
#include "./src/databasefilesystem.cpp"
#include "./src/plugin.cpp"
#include "./src/reparser.cpp"
