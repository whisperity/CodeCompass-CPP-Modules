#define MODULE_EXPORT

export module FULL_NAME_LDAPAuthenticator;

/* Header files */

#include "./ldap-cpp/cldap.h"
#include "./ldap-cpp/cldap_entry.h"
#include "./ldap-cpp/cldap_mod.h"
#include "./ldap-cpp/cldap_server.h"
#include "./ldap-cpp/cldap_types.h"

/* Source files */

#include "./ldap-cpp/cldap_entry.cpp"
#include "./ldap-cpp/cldap_mod.cpp"
#include "./ldap-cpp/cldap_server.cpp"
#include "./src/plugin.cpp"
