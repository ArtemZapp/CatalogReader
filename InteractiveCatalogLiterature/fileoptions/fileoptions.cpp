#include "fileoptions.h"

FileOptions::FileOptions() : b_ModeWork(MODE_READING),
    b_LanguageProgram(LANGUAGE_RUSSIAN),
    b_StateStandardToolbar(TOOLBAR_SHOW),
    b_StateEditToolbar(TOOLBAR_HIDE),
    b_StateFormatToolbar(TOOLBAR_HIDE),
    b_StateFindToolbar(TOOLBAR_HIDE),
    b_PathOptionsLocally(true),
    b_RememberLastOpened(true),
    b_SavePasswordBook(true),
    ba_ModeEditingPassword(""),
    s_PathStatistics(QDir::homePath()),
    s_PathOptions(""),
    s_PathLastLibrary(""),
    s_PathProgramShelkTest(""),
    r_SizeMainWindow(QRect(260, 300, 700, 420))
{

}

FileOptions::~FileOptions()
{
    clear();
}

bool FileOptions::isModeWork() const
{
    return b_ModeWork;
}

bool FileOptions::isLanguageProgram() const
{
    return b_LanguageProgram;
}

bool FileOptions::isStateStandardToolbar() const
{
    return b_StateStandardToolbar;
}

bool FileOptions::isStateEditToolbar() const
{
    return b_StateEditToolbar;
}

bool FileOptions::isStateFormatToolbar() const
{
    return b_StateFormatToolbar;
}

bool FileOptions::isStateFindToolbar() const
{
    return b_StateFindToolbar;
}

bool FileOptions::isPathOptionsLocally() const
{
    return b_PathOptionsLocally;
}

bool FileOptions::isRememberLastOpened() const
{
    return b_RememberLastOpened;
}

bool FileOptions::isSavePasswordBook() const
{
    return b_SavePasswordBook;
}

QByteArray FileOptions::modeEditingPassword() const
{
    return ba_ModeEditingPassword;
}

QString FileOptions::pathStatistics() const
{
    return s_PathStatistics;
}

QString FileOptions::pathOptions() const
{
    return s_PathOptions;
}

QString FileOptions::pathLastLibrary() const
{
    return s_PathLastLibrary;
}

QString FileOptions::pathProgramShelkTest() const
{
    return s_PathProgramShelkTest;
}

QRect FileOptions::sizeMainWindow() const
{
    return r_SizeMainWindow;
}

QByteArray FileOptions::stateMainWindow() const
{
    return ba_StateMainWindow;
}

void FileOptions::setModeWork(bool bModeWork)
{
    b_ModeWork = bModeWork;
}

void FileOptions::setLanguageProgram(bool bLanguageProgram)
{
    b_LanguageProgram = bLanguageProgram;
}

void FileOptions::setStateStandardToolbar(bool bStateStandardToolbar)
{
    b_StateStandardToolbar = bStateStandardToolbar;
}

void FileOptions::setStateEditToolbar(bool bStateEditToolbar)
{
    b_StateEditToolbar = bStateEditToolbar;
}

void FileOptions::setStateFormatToolbar(bool bStateFormatToolbar)
{
    b_StateFormatToolbar = bStateFormatToolbar;
}

void FileOptions::setStateFindToolbar(bool bStateFindToolbar)
{
    b_StateFindToolbar = bStateFindToolbar;
}

void FileOptions::setPathOptionsLocally(bool bPathOptionsLocally)
{
    b_PathOptionsLocally = bPathOptionsLocally;
}

void FileOptions::setRememberLastOpened(bool bRememberLastOpened)
{
    b_RememberLastOpened = bRememberLastOpened;
}

void FileOptions::setSavePasswordBook(bool bSavePasswordBook)
{
    b_SavePasswordBook = bSavePasswordBook;
}

void FileOptions::setModeEditingPassword(QByteArray baModeEditingPassword)
{
    ba_ModeEditingPassword = baModeEditingPassword;
}

void FileOptions::setPathStatistics(QString sPathStatistics)
{
    s_PathStatistics = sPathStatistics;
}

void FileOptions::setPathOptions(QString sPathOptions)
{
    s_PathOptions = sPathOptions;
}

void FileOptions::setPathLastLibrary(QString sPathLastLibrary)
{
    s_PathLastLibrary = sPathLastLibrary;
}

void FileOptions::setPathProgramShelkTest(QString sPathProgramShelkTest)
{
    s_PathProgramShelkTest = sPathProgramShelkTest;
}

void FileOptions::setSizeMainWindow(QRect rSizeMainWindow)
{
    r_SizeMainWindow = rSizeMainWindow;
}

void FileOptions::setStateMainWindow(QByteArray baStateMainWindow)
{
    ba_StateMainWindow = baStateMainWindow;
}

bool FileOptions::load()
{
    bool bState = false;
    QByteArray baPassword;

    QSettings *setFileOptions = new QSettings(QSettings::IniFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());
    setFileOptions->beginGroup("/ProgramData");
    setPathOptionsLocally(setFileOptions->value("/bPathOptionsLocally", isPathOptionsLocally()).toBool());
    setPathOptions(setFileOptions->value("/sPathOptions", pathOptions()).toString());

    if (!isPathOptionsLocally() && !pathOptions().isEmpty())
    {
        delete setFileOptions;
        setFileOptions = new QSettings(pathOptions() + "/Klen-library.ini", QSettings::IniFormat);
        setFileOptions->beginGroup("/ProgramData");
    }

    setModeWork(setFileOptions->value("/bModeWork", isModeWork()).toBool());
    setLanguageProgram(setFileOptions->value("/bLanguageProgram", isLanguageProgram()).toBool());
    setStateStandardToolbar(setFileOptions->value("/bStateStandardToolbar", isStateStandardToolbar()).toBool());
    setStateEditToolbar(setFileOptions->value("/bStateEditToolbar", isStateEditToolbar()).toBool());
    setStateFormatToolbar(setFileOptions->value("/bStateFormatToolbar", isStateFormatToolbar()).toBool());
    setStateFindToolbar(setFileOptions->value("/bStateFindToolbar", isStateFindToolbar()).toBool());
    setModeEditingPassword(setFileOptions->value("/baModeEditingPassword", baPassword).toByteArray());
    setPathStatistics(setFileOptions->value("/sPathStatistics", pathStatistics()).toString());
    setPathProgramShelkTest(setFileOptions->value("/sPathProgramShelkTest", pathProgramShelkTest()).toString());
    setFileOptions->endGroup();
    setFileOptions->beginGroup("/ProgramView");
    setSizeMainWindow(setFileOptions->value("/rSizeMainWindow", sizeMainWindow()).toRect());
    setStateMainWindow(setFileOptions->value("/baStateMainWindow", stateMainWindow()).toByteArray());
    setFileOptions->endGroup();
    setFileOptions->beginGroup("/Library");
    setRememberLastOpened(setFileOptions->value("/bRememberLastOpened", isRememberLastOpened()).toBool());
    setPathLastLibrary(setFileOptions->value("/sPathLastLibrary", pathLastLibrary()).toString());
    setSavePasswordBook(setFileOptions->value("/bSavePasswordBook", isSavePasswordBook()).toBool());
    setFileOptions->endGroup();

    if (QFile::exists(setFileOptions->fileName()))
        bState = true;
    else
        bState = false;

    delete setFileOptions;

    return bState;
}

bool FileOptions::write()
{
    QSettings setFileOptions(QSettings::IniFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());

    setFileOptions.beginGroup("/ProgramData");
    setFileOptions.setValue("/bPathOptionsLocally", isPathOptionsLocally());
    setFileOptions.setValue("/sPathOptions", pathOptions());
    setFileOptions.setValue("/bModeWork", isModeWork());
    setFileOptions.setValue("/bLanguageProgram", isLanguageProgram());
    setFileOptions.setValue("/bStateStandardToolbar", isStateStandardToolbar());
    setFileOptions.setValue("/bStateEditToolbar", isStateEditToolbar());
    setFileOptions.setValue("/bStateFormatToolbar", isStateFormatToolbar());
    setFileOptions.setValue("/bStateFindToolbar", isStateFindToolbar());
    setFileOptions.setValue("/baModeEditingPassword", modeEditingPassword());
    setFileOptions.setValue("/sPathStatistics", pathStatistics());
    setFileOptions.setValue("/sPathProgramShelkTest", pathProgramShelkTest());
    setFileOptions.endGroup();
    setFileOptions.beginGroup("/ProgramView");
    setFileOptions.setValue("/rSizeMainWindow", sizeMainWindow());
    setFileOptions.setValue("/baStateMainWindow", stateMainWindow());
    setFileOptions.endGroup();
    setFileOptions.beginGroup("/Library");
    setFileOptions.setValue("/bRememberLastOpened", isRememberLastOpened());
    setFileOptions.setValue("/sPathLastLibrary", pathLastLibrary());
    setFileOptions.setValue("/bSavePasswordBook", isSavePasswordBook());
    setFileOptions.endGroup();
    setFileOptions.sync();

    return true;
}

void FileOptions::clear()
{
    setModeWork(MODE_READING);
    setLanguageProgram(LANGUAGE_RUSSIAN);
    setStateStandardToolbar(TOOLBAR_SHOW);
    setStateEditToolbar(TOOLBAR_HIDE);
    setStateFormatToolbar(TOOLBAR_HIDE);
    setStateFindToolbar(TOOLBAR_HIDE);
    setSavePasswordBook(true);
    setPathOptionsLocally(true);
    setRememberLastOpened(true);
    ba_ModeEditingPassword.clear();
    s_PathStatistics.clear();
    s_PathOptions.clear();
    s_PathLastLibrary.clear();
    s_PathProgramShelkTest.clear();
    r_SizeMainWindow = QRect(260, 300, 700, 420);
}
