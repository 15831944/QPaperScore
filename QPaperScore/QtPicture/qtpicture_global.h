#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(QTPICTURE_LIB)
#  define QTPICTURE_EXPORT Q_DECL_EXPORT
# else
#  define QTPICTURE_EXPORT Q_DECL_IMPORT
# endif
#else
# define QTPICTURE_EXPORT
#endif
