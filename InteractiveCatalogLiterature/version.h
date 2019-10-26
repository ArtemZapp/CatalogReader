/* ======================================================================
**  version.h - Заголовочный файл модуля версии библиотеки.
*/

#ifndef VERSION_H
#define VERSION_H
#include <QtCore/QObject>
#include <QtCore/QString>

//Название программы и версия
static const QString APPLICATION_NAME  = QObject::tr("ICL");
static const QString APPLICATION_VERSION  = "0.0.5";
static const QString APPLICATION_NAME_VERSION = APPLICATION_NAME + " " + APPLICATION_VERSION;

#endif // VERSION_H
