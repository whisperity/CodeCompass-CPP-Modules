#define MODULE_EXPORT

export module FULL_NAME_BuildPluginDummyServiceImpl;

/* Header files */

#include "./dummy_constants.h"
#include "./DummyService.h"
#include "./dummy_types.h"

/* Source files */

#include "./dummy_constants.cpp"
#include "./DummyService_server.skeleton.cpp"
#include "./DummyService.cpp"
#include "./dummy_types.cpp"
