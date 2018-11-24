#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(DATABASELOCAL_LIB)
#  define DATABASELOCAL_EXPORT Q_DECL_EXPORT
# else
#  define DATABASELOCAL_EXPORT Q_DECL_IMPORT
# endif
#else
# define DATABASELOCAL_EXPORT
#endif
