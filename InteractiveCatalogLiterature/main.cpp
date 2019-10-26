/* ======================================================================
**  main.cpp - Исходный файл главного модуля.
*/

#include <QtGui/QApplication>
#include <QtGui/QIcon>
#include <QtCore/QTranslator>
#include <QtCore/QDataStream>
#include <QtCore/QTextStream>
#include <QtCore/QDir>
#include <QtCore/QStringList>
#include <QtCore/QString>
#include <QtCore/QFile>
#include <QtCore/QSettings>
#include <QtCore/QDebug>
#include <QtCore/QCryptographicHash>
#include "InteractiveCatalogLiterature/ICL.h"
#include "fileoptions/fileoptions.h"
#include "const.h"
#include "version.h"



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("Cursach");
    QCoreApplication::setOrganizationDomain("https://vk.com/artemzhil");
    QCoreApplication::setApplicationName(APPLICATION_NAME);
    QCoreApplication::setApplicationVersion(APPLICATION_VERSION);

    bool bState = false;

    FileOptions *FO = new FileOptions;
    bState = FO->load();

    ICL FormICL;
    FormICL.FO = FO;

    FormICL.setGeometry(FO->sizeMainWindow());
    //Восстановление положений панелей инструментов
    FormICL.restoreState(FO->stateMainWindow());
    FormICL.getUserName();
    FormICL.show();
    FormICL.setVisibilityOfToolbar();

//Применение режима работы программы
    switch(FO->isModeWork())
    {
    case FileOptions::MODE_READING:
        FormICL.ui->actionEditing->setChecked(false);
        FormICL.ui->actionReading->setChecked(true);
        FormICL.slotModeViewing();
        break;

    case FileOptions::MODE_EDITING:
        FormICL.ui->actionEditing->setChecked(true);
        FormICL.ui->actionReading->setChecked(false);
        FormICL.slotModeEditing();
        break;
    }

    if (FO->isRememberLastOpened() == true) FormICL.openLibrary(true);

    return app.exec();
}
