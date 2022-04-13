#define MODULE_EXPORT

export module FULL_NAME_Webserver;

/* Header files */

#include "include/webserver/authenticator.h"
#include "include/webserver/mongoose.h"
#include "include/webserver/pluginhandler.h"
#include "include/webserver/pluginhelper.h"
#include "include/webserver/requesthandler.h"
#include "include/webserver/servercontext.h"
#include "include/webserver/session.h"
#include "include/webserver/thrifthandler.h"
#include "src/authentication.h"
#include "src/sessionmanager.h"
#include "src/threadedmongoose.h"
#include "src/mainrequesthandler.h"

/* Source files */

#include "src/authentication.cpp"
#include "src/mainrequesthandler.cpp"
#include "src/mongoose.c"
#include "src/session.cpp"
#include "src/sessionmanager.cpp"
#include "src/threadedmongoose.cpp"
#include "src/webserver.cpp"
