#define MODULE_EXPORT

export module FULL_NAME_BuildPluginServiceImpl;

/* Header files */

#include "./plugin_constants.h"
#include "./PluginService.h"
#include "./plugin_types.h"

/* Source files */

#include "./plugin_constants.cpp"
#include "./PluginService_server.skeleton.cpp"
#include "./PluginService.cpp"
#include "./plugin_types.cpp"
