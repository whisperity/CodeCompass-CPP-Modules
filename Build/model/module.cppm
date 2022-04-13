#define MODULE_EXPORT

export module FULL_NAME_BuildCoreModelImpl;

/* Header files */

#include "include/model/statistics-odb.hxx"
#include "include/model/fileloc-odb.hxx"
#include "include/model/position-odb.hxx"
#include "include/model/buildaction-odb.hxx"
#include "include/model/buildlog-odb.hxx"
#include "include/model/filecontent-odb.hxx"
#include "include/model/file-odb.hxx"
#include "include/model/buildsourcetarget-odb.hxx"

/* Source files */

#include "include/model/statistics-odb.ixx"
#include "include/model/fileloc-odb.ixx"
#include "include/model/position-odb.ixx"
#include "include/model/buildaction-odb.ixx"
#include "include/model/buildlog-odb.ixx"
#include "include/model/filecontent-odb.ixx"
#include "include/model/file-odb.ixx"
#include "include/model/buildsourcetarget-odb.ixx"
#include "fileloc-odb.cxx"
#include "statistics-odb.cxx"
#include "buildlog-odb.cxx"
#include "buildaction-odb.cxx"
#include "position-odb.cxx"
#include "filecontent-odb.cxx"
#include "buildsourcetarget-odb.cxx"
#include "file-odb.cxx"
