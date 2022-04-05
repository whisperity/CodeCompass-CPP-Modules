#define MODULE_EXPORT

export module FULL_NAME_webserverwebserver;

/* Header files */

#include "../include/webserver/authenticator.h"
#include "../include/webserver/servercontext.h"
#include "../include/webserver/pluginhandler.h"
#include "../include/webserver/pluginhelper.h"
#include "../include/webserver/requesthandler.h"
#include "../include/webserver/thrifthandler.h"

/* Source files */

#include "./webserver.cpp"
