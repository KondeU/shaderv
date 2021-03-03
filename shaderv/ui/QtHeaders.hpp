// NB: Do not include this header file directly,
//     please include UiBasic.h instead, otherwise
//     the memory leak tracing will be unavailable!!!
#ifndef _QT_HEADERS_HPP_
#define _QT_HEADERS_HPP_

#include <QtCore>
#include <QtGui>
#include <QtWidgets>

// Solve the problem of Chinese characters, please make sure
// all files format is UTF-8 without BOM!!!
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

// The Qt relies on the parent-child relationship model to
// maintain Qt's resources, and follows the principle of
// compounds and responsibility chains.
#define QT_NEW new
#define QT_DEL delete

#endif
