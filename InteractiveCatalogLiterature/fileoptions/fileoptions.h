/* ======================================================================
**  fileoptions.h - Заголовочный файл модуля свойств программы.
*/

#ifndef FILEOPTIONS_H
#define FILEOPTIONS_H
#include <QtCore/QString>
#include <QtCore/QByteArray>
#include <QtCore/QCryptographicHash>
#include <QtCore/QSettings>
#include <QtCore/QCoreApplication>
#include <QtCore/QDir>
#include <QtCore/QVector>
#include <QtCore/QRect>

//Класс файла свойств программы
class FileOptions
{
private:
    bool b_ModeWork;//Режим работы программы
    bool b_LanguageProgram;//Язык программы
    bool b_StateStandardToolbar;//Состояние показа стандартной панели
    bool b_StateEditToolbar;//Состояние показа панели редактирования
    bool b_StateFormatToolbar;//Состояние показа панели форматирования
    bool b_StateFindToolbar;//Состояние показа панели поиска
    bool b_PathOptionsLocally;//Локальное расположение файла свойств
    bool b_RememberLastOpened;//Запомнить последнюю открытую базу хранилища
    bool b_SavePasswordBook;//Сохранение пароля книги
    QByteArray ba_ModeEditingPassword;//Пароль режима
    QString s_PathStatistics;//Путь к файлу статистики
    QString s_PathOptions;//Путь к файлу свойств
    QString s_PathLastLibrary;//Путь к прошлому хранилищу
    QString s_PathProgramShelkTest;//Путь к программе Шёлковый тест
    QRect r_SizeMainWindow;//Размер и положение главного окна
    QByteArray ba_StateMainWindow;//Состояние всех панелей инструментов

public:

    enum modeConst
    {
        MODE_READING = true,
        MODE_EDITING = false
                   };

    enum languageConst
    {
        LANGUAGE_RUSSIAN = true,
        LANGUAGE_ENGLISH = false
                       };

    enum toolbarConst
    {
        TOOLBAR_SHOW = true,
        TOOLBAR_HIDE = false
                   };

    FileOptions();
    ~FileOptions();

    bool isModeWork() const;//Получить режим работы программы
    bool isLanguageProgram() const;//Получить язык программы
    bool isStateStandardToolbar() const;//Получить состояние показа стандартной панели
    bool isStateEditToolbar() const;//Получить состояние показа панели редактирования
    bool isStateFormatToolbar() const;//Получить состояние показа панели форматирования
    bool isStateFindToolbar() const;//Получить состояние показа панели поиска
    bool isPathOptionsLocally() const;//Получить состояние локального расположения файла свойств
    bool isRememberLastOpened() const;//Получить состояние запоминания последней открытой базы хранилища
    bool isSavePasswordBook() const;//Получить состояние сохранения пароля книги
    QByteArray modeEditingPassword() const;//Получить пароль режима
    QString pathStatistics() const;//Получить путь к файлу статистики
    QString pathOptions() const;//Получить путь к файлу свойств
    QString pathLastLibrary() const;//Получить путь к прошлому хранилищу
    QString pathProgramShelkTest() const;//Получить путь к программе Шёлковый тест
    QRect sizeMainWindow() const;//Получить размер и положение главного окна
    QByteArray stateMainWindow() const;//Получить состояние всех панелей инструментов
    void setModeWork(bool bModeWork);//Задать режим работы программы
    void setLanguageProgram(bool bLanguageProgram);//Задать язык программы
    void setStateStandardToolbar(bool bStateStandardToolbar);//Задать состояние показа стандартной панели
    void setStateEditToolbar(bool bStateEditToolbar);//Задать состояние показа панели редактирования
    void setStateFormatToolbar(bool bStateFormatToolbar);//Задать состояние показа панели форматирования
    void setStateFindToolbar(bool bStateFindToolbar);//Задать состояние показа панели поиска
    void setModeEditingPassword(QByteArray baModeEditingPassword);//Задать пароль режима
    void setPathStatistics(QString sPathStatistics);//Задать путь к файлу статистики
    void setPathOptions(QString sPathOptions);//Задать путь к файлу свойств
    void setPathLastLibrary(QString sPathLastLibrary);//Задать Путь к прошлому хранилищу
    void setPathProgramShelkTest(QString sPathProgramShelkTest);//Задать путь к программе Шёлковый тест
    void setPathOptionsLocally(bool bPathOptionsLocally);//Задать состояние локального расположения файла свойств
    void setRememberLastOpened(bool bRememberLastOpened);//Задать состояние запоминания последней открытой базы хранилища
    void setSavePasswordBook(bool bSavePasswordBook);//Задать состояние сохранения пароля книги
    void setSizeMainWindow(QRect rSizeMainWindow);//Задать размер и положение главного окна
    void setStateMainWindow(QByteArray baStateMainWindow);//Задать состояние всех панелей инструментов
    bool load();//Загрузка свойств
    bool write();//Запись свойств
    void clear();//Очистка свойств
};

#endif // FILEOPTIONS_H
