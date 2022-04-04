#define MODULE_EXPORT

export module FULL_NAME_CppTest;

/* Header files */

#include "./sources/service/inheritance.h"
#include "./sources/service/nestedclass.h"
#include "./sources/service/simpleclass.h"
#include "./src/servicehelper.h"

/* Source files */

#include "./sources/parser/cxxrecord.cpp"
#include "./sources/parser/enum.cpp"
#include "./sources/parser/function.cpp"
#include "./sources/parser/namespace.cpp"
#include "./sources/parser/typedef.cpp"
#include "./sources/parser/variable.cpp"
#include "./sources/service/inheritance.cpp"
#include "./sources/service/nestedclass.cpp"
#include "./sources/service/simpleclass.cpp"
#include "./src/cpparsertest.cpp"
#include "./src/cpppropertiesservicetest.cpp"
#include "./src/cppreferenceservicetest.cpp"
#include "./src/cpptest.cpp"
#include "./src/servicehelper.cpp"
#include "./src/cppparsertest.cpp"
