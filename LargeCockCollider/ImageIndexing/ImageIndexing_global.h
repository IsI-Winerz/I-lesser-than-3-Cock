/** Author : Beretz Emile, Gaudet Kevin, Schimchowitsch Raphal
  * Project : I <3 Cock
  * File : imageindexing_global.h
  */

#ifndef IMAGEINDEXING_GLOBAL_H
#define IMAGEINDEXING_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(IMAGEINDEXING_LIBRARY)
#  define IMAGEINDEXINGSHARED_EXPORT Q_DECL_EXPORT
#else
#  define IMAGEINDEXINGSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // IMAGEINDEXING_GLOBAL_H
