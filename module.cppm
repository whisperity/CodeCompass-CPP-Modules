#define MODULE_EXPORT

export module FULL_NAME_CodeCompass_Handwritten;

/* Header files */

#include "logger/src/ldlogger-hooks.h"
#include "logger/src/ldlogger-util.h"
#include "logger/src/ldlogger-tool.h"
#include "model/include/model/buildaction.h"
#include "model/include/model/buildlog.h"
#include "model/include/model/buildsourcetarget.h"
#include "model/include/model/file.h"
#include "model/include/model/filecontent.h"
#include "model/include/model/fileloc.h"
#include "model/include/model/position.h"
#include "model/include/model/statistics.h"
#include "parser/include/parser/abstractparser.h"
#include "parser/include/parser/parsercontext.h"
#include "parser/include/parser/pluginhandler.h"
#include "parser/include/parser/sourcemanager.h"
#include "plugins/cpp/model/include/model/common.h"
#include "plugins/cpp/model/include/model/cppastnode.h"
#include "plugins/cpp/model/include/model/cppdoccomment.h"
#include "plugins/cpp/model/include/model/cppedge.h"
#include "plugins/cpp/model/include/model/cppfriendship.h"
#include "plugins/cpp/model/include/model/cppheaderinclusion.h"
#include "plugins/cpp/model/include/model/cpprelation.h"
#include "plugins/cpp/model/include/model/cppentity.h"
#include "plugins/cpp/model/include/model/cppenum.h"
#include "plugins/cpp/model/include/model/cppfunction.h"
#include "plugins/cpp/model/include/model/cppinheritance.h"
#include "plugins/cpp/model/include/model/cppmacro.h"
#include "plugins/cpp/model/include/model/cppmacroexpansion.h"
#include "plugins/cpp/model/include/model/cppnamespace.h"
#include "plugins/cpp/model/include/model/cpprecord.h"
#include "plugins/cpp/model/include/model/cpptypedef.h"
#include "plugins/cpp/model/include/model/cppvariable.h"
#include "plugins/cpp/parser/include/cppparser/filelocutil.h"
#include "plugins/cpp/parser/include/cppparser/cppparser.h"
#include "plugins/cpp/parser/src/diagnosticmessagehandler.h"
#include "plugins/cpp/parser/src/doccommentformatter.h"
#include "plugins/cpp/parser/src/entitycache.h"
#include "plugins/cpp/parser/src/relationcollector.h"
#include "plugins/cpp/parser/src/symbolhelper.h"
#include "plugins/cpp/parser/src/doccommentcollector.h"
#include "plugins/cpp/parser/src/clangastvisitor.h"
#include "plugins/cpp/parser/src/ppincludecallback.h"
#include "plugins/cpp/parser/src/ppmacrocallback.h"
#include "plugins/cpp/service/include/service/cppservice.h"
#include "plugins/cpp/service/src/diagram.h"
#include "plugins/cpp/service/src/filediagram.h"
#include "plugins/cpp/test/sources/service/inheritance.h"
#include "plugins/cpp/test/sources/service/nestedclass.h"
#include "plugins/cpp/test/sources/service/simpleclass.h"
#include "plugins/cpp/test/src/servicehelper.h"
#include "plugins/cpp_reparse/service/include/service/cppreparseservice.h"
#include "plugins/cpp_reparse/service/include/service/reparser.h"
#include "plugins/cpp_reparse/service/src/astcache.h"
#include "plugins/cpp_reparse/service/src/asthtml.h"
#include "plugins/cpp_reparse/service/src/astnodelocator.h"
#include "plugins/cpp_reparse/service/src/databasefilesystem.h"
#include "plugins/dummy/parser/include/dummyparser/dummyparser.h"
#include "plugins/dummy/service/include/service/dummyservice.h"
#include "plugins/git/parser/include/gitparser/gitparser.h"
#include "plugins/git/service/include/service/gitservice.h"
#include "plugins/metrics/model/include/model/metrics.h"
#include "plugins/metrics/parser/include/metricsparser/metricsparser.h"
#include "plugins/metrics/service/include/metricsservice/metricsservice.h"
#include "plugins/search/indexer/include/indexer/indexerprocess.h"
#include "plugins/search/parser/include/searchparser/searchparser.h"
#include "plugins/search/service/include/service/searchservice.h"
#include "plugins/search/service/include/service/serviceprocess.h"
#include "service/authentication/include/authenticationservice/authenticationservice.h"
#include "service/plugin/include/pluginservice/pluginservice.h"
#include "service/project/include/projectservice/projectservice.h"
#include "service/workspace/include/workspaceservice/workspaceservice.h"
#include "util/include/util/dbutil.h"
#include "util/include/util/dynamiclibrary.h"
#include "util/include/util/filesystem.h"
#include "util/include/util/graph.h"
#include "util/include/util/hash.h"
#include "util/include/util/logutil.h"
#include "util/include/util/odbobjectcache.h"
#include "util/include/util/parserutil.h"
#include "util/include/util/pipedprocess.h"
#include "util/include/util/threadpool.h"
#include "util/include/util/util.h"
#include "util/include/util/webserverutil.h"
#include "util/include/util/legendbuilder.h"
#include "util/include/util/odbtransaction.h"
#include "util/src/graphpimpl.h"
#include "webserver/authenticators/ldap/ldap-cpp/cldap_types.h"
#include "webserver/authenticators/ldap/ldap-cpp/cldap.h"
#include "webserver/authenticators/ldap/ldap-cpp/cldap_entry.h"
#include "webserver/authenticators/ldap/ldap-cpp/cldap_mod.h"
#include "webserver/authenticators/ldap/ldap-cpp/cldap_server.h"
#include "webserver/include/webserver/authenticator.h"
#include "webserver/include/webserver/mongoose.h"
#include "webserver/include/webserver/servercontext.h"
#include "webserver/include/webserver/session.h"
#include "webserver/include/webserver/pluginhandler.h"
#include "webserver/include/webserver/pluginhelper.h"
#include "webserver/include/webserver/requesthandler.h"
#include "webserver/include/webserver/thrifthandler.h"
#include "webserver/src/authentication.h"
#include "webserver/src/sessionmanager.h"
#include "webserver/src/threadedmongoose.h"
#include "webserver/src/mainrequesthandler.h"

/* Source files */

#include "logger/src/ldlogger-hooks.c"
#include "logger/src/ldlogger-logger.c"
#include "logger/src/ldlogger-tool-gcc.c"
#include "logger/src/ldlogger-tool-javac.c"
#include "logger/src/ldlogger-tool.c"
#include "logger/src/ldlogger-util.c"
#include "parser/src/parser.cpp"
#include "parser/src/parsercontext.cpp"
#include "parser/src/sourcemanager.cpp"
#include "parser/src/pluginhandler.cpp"
#include "plugins/cpp/parser/src/cppparser.cpp"
#include "plugins/cpp/parser/src/diagnosticmessagehandler.cpp"
#include "plugins/cpp/parser/src/entitycache.cpp"
#include "plugins/cpp/parser/src/ppincludecallback.cpp"
#include "plugins/cpp/parser/src/ppmacrocallback.cpp"
#include "plugins/cpp/parser/src/relationcollector.cpp"
#include "plugins/cpp/parser/src/doccommentformatter.cpp"
#include "plugins/cpp/parser/src/symbolhelper.cpp"
#include "plugins/cpp/service/src/plugin.cpp"
#include "plugins/cpp/service/src/cppservice.cpp"
#include "plugins/cpp/service/src/diagram.cpp"
#include "plugins/cpp/service/src/filediagram.cpp"
#include "plugins/cpp/test/sources/parser/cxxrecord.cpp"
#include "plugins/cpp/test/sources/parser/enum.cpp"
#include "plugins/cpp/test/sources/parser/function.cpp"
#include "plugins/cpp/test/sources/parser/namespace.cpp"
#include "plugins/cpp/test/sources/parser/typedef.cpp"
#include "plugins/cpp/test/sources/parser/variable.cpp"
#include "plugins/cpp/test/sources/service/inheritance.cpp"
#include "plugins/cpp/test/sources/service/nestedclass.cpp"
#include "plugins/cpp/test/sources/service/simpleclass.cpp"
#include "plugins/cpp/test/src/cpparsertest.cpp"
#include "plugins/cpp/test/src/cpptest.cpp"
#include "plugins/cpp/test/src/cppparsertest.cpp"
#include "plugins/cpp/test/src/cpppropertiesservicetest.cpp"
#include "plugins/cpp/test/src/cppreferenceservicetest.cpp"
#include "plugins/cpp/test/src/servicehelper.cpp"
#include "plugins/cpp_reparse/service/src/plugin.cpp"
#include "plugins/cpp_reparse/service/src/astcache.cpp"
#include "plugins/cpp_reparse/service/src/asthtml.cpp"
#include "plugins/cpp_reparse/service/src/cppreparseservice.cpp"
#include "plugins/cpp_reparse/service/src/databasefilesystem.cpp"
#include "plugins/cpp_reparse/service/src/reparser.cpp"
#include "plugins/dummy/parser/src/dummyparser.cpp"
#include "plugins/dummy/service/src/dummyservice.cpp"
#include "plugins/dummy/service/src/plugin.cpp"
#include "plugins/dummy/test/src/dummyparsertest.cpp"
#include "plugins/dummy/test/src/dummyservicetest.cpp"
#include "plugins/git/parser/src/gitparser.cpp"
#include "plugins/git/service/src/plugin.cpp"
#include "plugins/git/service/src/gitservice.cpp"
#include "plugins/metrics/parser/src/metricsparser.cpp"
#include "plugins/metrics/service/src/metricsservice.cpp"
#include "plugins/metrics/service/src/plugin.cpp"
#include "plugins/search/indexer/src/indexerprocess.cpp"
#include "plugins/search/parser/src/searchparser.cpp"
#include "plugins/search/service/src/plugin.cpp"
#include "plugins/search/service/src/searchservice.cpp"
#include "service/authentication/src/authenticationservice.cpp"
#include "service/authentication/src/plugin.cpp"
#include "service/plugin/src/plugin.cpp"
#include "service/plugin/src/pluginservice.cpp"
#include "service/project/src/plugin.cpp"
#include "service/project/src/projectservice.cpp"
#include "service/workspace/src/plugin.cpp"
#include "service/workspace/src/workspaceservice.cpp"
#include "util/src/dynamiclibrary.cpp"
#include "util/src/filesystem.cpp"
#include "util/src/legendbuilder.cpp"
#include "util/src/pipedprocess.cpp"
#include "util/src/util.cpp"
#include "util/src/dbutil.cpp"
#include "util/src/graph.cpp"
#include "util/src/logutil.cpp"
#include "util/src/parserutil.cpp"
#include "webserver/authenticators/ldap/ldap-cpp/cldap_entry.cpp"
#include "webserver/authenticators/ldap/ldap-cpp/cldap_mod.cpp"
#include "webserver/authenticators/ldap/ldap-cpp/cldap_server.cpp"
#include "webserver/authenticators/ldap/src/plugin.cpp"
#include "webserver/authenticators/plain/src/plugin.cpp"
#include "webserver/src/mainrequesthandler.cpp"
#include "webserver/src/sessionmanager.cpp"
#include "webserver/src/webserver.cpp"
#include "webserver/src/authentication.cpp"
#include "webserver/src/mongoose.c"
#include "webserver/src/session.cpp"
#include "webserver/src/threadedmongoose.cpp"