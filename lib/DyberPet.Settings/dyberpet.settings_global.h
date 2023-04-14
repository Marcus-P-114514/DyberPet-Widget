#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(DYBERPET.SETTINGS_LIB)
#  define DYBERPET.SETTINGS_EXPORT Q_DECL_EXPORT
# else
#  define DYBERPET.SETTINGS_EXPORT Q_DECL_IMPORT
# endif
#else
# define DYBERPET.SETTINGS_EXPORT
#endif
