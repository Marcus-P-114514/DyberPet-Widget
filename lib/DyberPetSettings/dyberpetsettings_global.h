#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(DYBERPETSETTINGS_LIB)
#  define DYBERPETSETTINGS_EXPORT Q_DECL_EXPORT
# else
#  define DYBERPETSETTINGS_EXPORT Q_DECL_IMPORT
# endif
#else
# define DYBERPETSETTINGS_EXPORT
#endif
