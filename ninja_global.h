#ifndef NINJA_GLOBAL_H
#define NINJA_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(NINJA_LIBRARY)
#  define NINJASHARED_EXPORT Q_DECL_EXPORT
#else
#  define NINJASHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // NINJA_GLOBAL_H
