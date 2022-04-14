#define MODULE_EXPORT

export module FULL_NAME_CodeCompass_Generated;

/* Header files */

#include "model/include/model/position-odb.hxx"
#include "model/include/model/filecontent-odb.hxx"
#include "model/include/model/buildaction-odb.hxx"
#include "model/include/model/buildsourcetarget-odb.hxx"
#include "model/include/model/buildlog-odb.hxx"
#include "model/include/model/fileloc-odb.hxx"
#include "model/include/model/file-odb.hxx"
#include "model/include/model/statistics-odb.hxx"
#include "service/authentication/gen-cpp/authentication_constants.h"
#include "service/authentication/gen-cpp/AuthenticationService.h"
#include "service/authentication/gen-cpp/authentication_types.h"
#include "service/language/gen-cpp/language_constants.h"
#include "service/language/gen-cpp/LanguageService.h"
#include "service/language/gen-cpp/language_types.h"
#include "service/plugin/gen-cpp/plugin_constants.h"
#include "service/plugin/gen-cpp/PluginService.h"
#include "service/plugin/gen-cpp/plugin_types.h"
#include "service/project/gen-cpp/common_constants.h"
#include "service/project/gen-cpp/common_types.h"
#include "service/project/gen-cpp/project_constants.h"
#include "service/project/gen-cpp/ProjectService.h"
#include "service/project/gen-cpp/project_types.h"
#include "service/workspace/gen-cpp/workspace_constants.h"
#include "service/workspace/gen-cpp/WorkspaceService.h"
#include "service/workspace/gen-cpp/workspace_types.h"
#include "plugins/cpp/model/include/model/cppastnode-odb.hxx"
#include "plugins/cpp/model/include/model/cppheaderinclusion-odb.hxx"
#include "plugins/cpp/model/include/model/cppinheritance-odb.hxx"
#include "plugins/cpp/model/include/model/cppdoccomment-odb.hxx"
#include "plugins/cpp/model/include/model/cppmacro-odb.hxx"
#include "plugins/cpp/model/include/model/cpprecord-odb.hxx"
#include "plugins/cpp/model/include/model/cpprelation-odb.hxx"
#include "plugins/cpp/model/include/model/cppfriendship-odb.hxx"
#include "plugins/cpp/model/include/model/cppvariable-odb.hxx"
#include "plugins/cpp/model/include/model/cppenum-odb.hxx"
#include "plugins/cpp/model/include/model/cppnamespace-odb.hxx"
#include "plugins/cpp/model/include/model/cppfunction-odb.hxx"
#include "plugins/cpp/model/include/model/cpptypedef-odb.hxx"
#include "plugins/cpp/model/include/model/cppmacroexpansion-odb.hxx"
#include "plugins/cpp/model/include/model/cppedge-odb.hxx"
#include "plugins/cpp/model/include/model/cppentity-odb.hxx"
#include "plugins/cpp_reparse/service/gen-cpp/cppreparse_constants.h"
#include "plugins/cpp_reparse/service/gen-cpp/CppReparseService.h"
#include "plugins/cpp_reparse/service/gen-cpp/cppreparse_types.h"
#include "plugins/dummy/service/gen-cpp/dummy_constants.h"
#include "plugins/dummy/service/gen-cpp/DummyService.h"
#include "plugins/dummy/service/gen-cpp/dummy_types.h"
#include "plugins/git/service/gen-cpp/git_constants.h"
#include "plugins/git/service/gen-cpp/GitService.h"
#include "plugins/git/service/gen-cpp/git_types.h"
#include "plugins/metrics/model/include/model/metrics-odb.hxx"
#include "plugins/metrics/service/gen-cpp/metrics_constants.h"
#include "plugins/metrics/service/gen-cpp/MetricsService.h"
#include "plugins/metrics/service/gen-cpp/metrics_types.h"
#include "plugins/search/indexer/gen-cpp/searchindexer_constants.h"
#include "plugins/search/indexer/gen-cpp/IndexerService.h"
#include "plugins/search/indexer/gen-cpp/searchindexer_types.h"
#include "plugins/search/service/gen-cpp/search_constants.h"
#include "plugins/search/service/gen-cpp/SearchService.h"
#include "plugins/search/service/gen-cpp/search_types.h"

/* Source files */

#include "model/include/model/statistics-odb.ixx"
#include "model/include/model/filecontent-odb.ixx"
#include "model/include/model/buildaction-odb.ixx"
#include "model/include/model/buildsourcetarget-odb.ixx"
#include "model/include/model/buildlog-odb.ixx"
#include "model/include/model/fileloc-odb.ixx"
#include "model/include/model/file-odb.ixx"
#include "model/include/model/position-odb.ixx"
#include "model/fileloc-odb.cxx"
#include "model/buildaction-odb.cxx"
#include "model/buildsourcetarget-odb.cxx"
#include "model/filecontent-odb.cxx"
#include "model/buildlog-odb.cxx"
#include "model/file-odb.cxx"
#include "model/position-odb.cxx"
#include "model/statistics-odb.cxx"
#include "service/authentication/gen-cpp/authentication_constants.cpp"
#include "service/authentication/gen-cpp/AuthenticationService_server.skeleton.cpp"
#include "service/authentication/gen-cpp/AuthenticationService.cpp"
#include "service/authentication/gen-cpp/authentication_types.cpp"
#include "service/language/gen-cpp/language_constants.cpp"
#include "service/language/gen-cpp/LanguageService_server.skeleton.cpp"
#include "service/language/gen-cpp/LanguageService.cpp"
#include "service/language/gen-cpp/language_types.cpp"
#include "service/plugin/gen-cpp/plugin_constants.cpp"
#include "service/plugin/gen-cpp/PluginService_server.skeleton.cpp"
#include "service/plugin/gen-cpp/PluginService.cpp"
#include "service/plugin/gen-cpp/plugin_types.cpp"
#include "service/project/gen-cpp/common_constants.cpp"
#include "service/project/gen-cpp/common_types.cpp"
#include "service/project/gen-cpp/project_constants.cpp"
#include "service/project/gen-cpp/ProjectService_server.skeleton.cpp"
#include "service/project/gen-cpp/ProjectService.cpp"
#include "service/project/gen-cpp/project_types.cpp"
#include "service/workspace/gen-cpp/workspace_constants.cpp"
#include "service/workspace/gen-cpp/WorkspaceService_server.skeleton.cpp"
#include "service/workspace/gen-cpp/WorkspaceService.cpp"
#include "service/workspace/gen-cpp/workspace_types.cpp"
#include "plugins/cpp/model/include/model/cppastnode-odb.ixx"
#include "plugins/cpp/model/include/model/cppheaderinclusion-odb.ixx"
#include "plugins/cpp/model/include/model/cppinheritance-odb.ixx"
#include "plugins/cpp/model/include/model/cppdoccomment-odb.ixx"
#include "plugins/cpp/model/include/model/cppmacro-odb.ixx"
#include "plugins/cpp/model/include/model/cpprecord-odb.ixx"
#include "plugins/cpp/model/include/model/cpprelation-odb.ixx"
#include "plugins/cpp/model/include/model/cppfriendship-odb.ixx"
#include "plugins/cpp/model/include/model/cppvariable-odb.ixx"
#include "plugins/cpp/model/include/model/cppenum-odb.ixx"
#include "plugins/cpp/model/include/model/cppnamespace-odb.ixx"
#include "plugins/cpp/model/include/model/cppfunction-odb.ixx"
#include "plugins/cpp/model/include/model/cpptypedef-odb.ixx"
#include "plugins/cpp/model/include/model/cppmacroexpansion-odb.ixx"
#include "plugins/cpp/model/include/model/cppedge-odb.ixx"
#include "plugins/cpp/model/include/model/cppentity-odb.ixx"
#include "plugins/cpp/model/cppastnode-odb.cxx"
#include "plugins/cpp/model/cppheaderinclusion-odb.cxx"
#include "plugins/cpp/model/cppmacro-odb.cxx"
#include "plugins/cpp/model/cppfriendship-odb.cxx"
#include "plugins/cpp/model/cppinheritance-odb.cxx"
#include "plugins/cpp/model/cppdoccomment-odb.cxx"
#include "plugins/cpp/model/cppvariable-odb.cxx"
#include "plugins/cpp/model/cpprelation-odb.cxx"
#include "plugins/cpp/model/cppnamespace-odb.cxx"
#include "plugins/cpp/model/cpprecord-odb.cxx"
#include "plugins/cpp/model/cppenum-odb.cxx"
#include "plugins/cpp/model/cpptypedef-odb.cxx"
#include "plugins/cpp/model/cppfunction-odb.cxx"
#include "plugins/cpp/model/cppmacroexpansion-odb.cxx"
#include "plugins/cpp/model/cppentity-odb.cxx"
#include "plugins/cpp/model/cppedge-odb.cxx"
#include "plugins/cpp_reparse/service/gen-cpp/cppreparse_constants.cpp"
#include "plugins/cpp_reparse/service/gen-cpp/CppReparseService_server.skeleton.cpp"
#include "plugins/cpp_reparse/service/gen-cpp/CppReparseService.cpp"
#include "plugins/cpp_reparse/service/gen-cpp/cppreparse_types.cpp"
#include "plugins/dummy/service/gen-cpp/dummy_constants.cpp"
#include "plugins/dummy/service/gen-cpp/DummyService_server.skeleton.cpp"
#include "plugins/dummy/service/gen-cpp/DummyService.cpp"
#include "plugins/dummy/service/gen-cpp/dummy_types.cpp"
#include "plugins/git/service/gen-cpp/git_constants.cpp"
#include "plugins/git/service/gen-cpp/GitService_server.skeleton.cpp"
#include "plugins/git/service/gen-cpp/GitService.cpp"
#include "plugins/git/service/gen-cpp/git_types.cpp"
#include "plugins/metrics/model/include/model/metrics-odb.ixx"
#include "plugins/metrics/model/metrics-odb.cxx"
#include "plugins/metrics/service/gen-cpp/metrics_constants.cpp"
#include "plugins/metrics/service/gen-cpp/MetricsService_server.skeleton.cpp"
#include "plugins/metrics/service/gen-cpp/MetricsService.cpp"
#include "plugins/metrics/service/gen-cpp/metrics_types.cpp"
#include "plugins/search/indexer/gen-cpp/searchindexer_constants.cpp"
#include "plugins/search/indexer/gen-cpp/IndexerService_server.skeleton.cpp"
#include "plugins/search/indexer/gen-cpp/IndexerService.cpp"
#include "plugins/search/indexer/gen-cpp/searchindexer_types.cpp"
#include "plugins/search/service/gen-cpp/search_constants.cpp"
#include "plugins/search/service/gen-cpp/SearchService_server.skeleton.cpp"
#include "plugins/search/service/gen-cpp/SearchService.cpp"
#include "plugins/search/service/gen-cpp/search_types.cpp"
