#define MODULE_EXPORT

export module FULL_NAME_Logger;

/* Header files */

#include "ldlogger-hooks.h"
#include "ldlogger-tool.h"
#include "ldlogger-util.h"

/* Source files */

#include "ldlogger-hooks.c"
#include "ldlogger-logger.c"
#include "ldlogger-tool.c"
#include "ldlogger-tool-gcc.c"
#include "ldlogger-tool-javac.c"
#include "ldlogger-util.c"
