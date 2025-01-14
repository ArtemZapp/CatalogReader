/* ======================================================================
**  ICL.h - Заголовочный файл модуля главной формы библиотеки.
*/

#ifndef ICL_H
#define ICL_H
#include "ui_ICL.h"
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QByteArray>
#include <QtCore/QTime>
#include <QtCore/QProcess>
#include <QtCore/QBuffer>
#include <QtCore/QUrl>
#include <QtCore/QSettings>
#include <QtCore/QCryptographicHash>
#include <QtGui/QLabel>
#include <QtGui/QFontComboBox>
#include <QtGui/QToolButton>
#include <QtGui/QBoxLayout>
#include <QtGui/QMessageBox>
#include <QtGui/QInputDialog>
#include <QtGui/QProgressDialog>
#include <QtGui/QFontDialog>
#include <QtGui/QPrinter>
#include <QtGui/QPrintDialog>
#include <QtGui/QPainter>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlTableModel>
#include <QtWebKit/QWebView>
#include "../ListBooks/ListBooks.h"
#include "../Create/Create.h"
#include "../FormOptions/FormOptions.h"
#include "../ListAdditionally/ListAdditionally.h"
#include "../TextBook/TextBook.h"
#include "../fileoptions/fileoptions.h"
#include "../const.h"
#include "../version.h"
//#include <time.h>//Директива нужна для работы со временем

namespace Ui {
class ICL;
}

class ICL : public QMainWindow, public Ui::ICL {
      Q_OBJECT

public:
       class WrongPassword {};

       QString sUserName;//Имя пользователя
       QString sLibraryPath;//Путь к библиотеке
       QString sLibraryName;//Название библиотеки
       QString sTime;

       QStringList slMusic;//Список музыки
       QStringList slFilms;//Список фильмов
       QStringList slPhotos;//Список фотографий
       QStringList slDocuments;//Список документов
       QStringList slPrograms;//Список программ
       QStringList slPrintingHouse;//Список издательств
       QStringList slYear;//Список лет
       QStringList slCategory;//Список категорий
       QStringList slSubCategory;//Список подкатегорий
       QStringList slNameBook;//Список названий книг

       QSqlDatabase db;//База данных библиотеки

       //Метки в строке состояния
       QLabel lUserName;//Имя пользователя
       QLabel lMode;
       QLabel lNameBook;
       QLabel lPrintingHouse;
       QLabel lYear;
       QLabel lCategory;
       QLabel lSubcategory;
       QLabel lCountPages;
       QLabel lCurrentPage;

       QFontComboBox cbFont;

       QToolButton tbNew;
       QToolButton tbOpen;
       QToolButton tbClose;
       QToolButton tbSave;
       QToolButton tbPrevious;
       QToolButton tbNext;
       QToolButton tbDeletePage;
       QToolButton tbPastePage;
       QToolButton tbInsertImage;
       QToolButton tbSettings;
       QToolButton tbExit;
       QToolButton tbUndo;
       QToolButton tbRedo;
       QToolButton tbSelectAll;
       QToolButton tbFont;
       QToolButton tbCut;
       QToolButton tbCopy;
       QToolButton tbPaste;
       QToolButton tbFind;
       QToolButton tbFindPrevious;
       QToolButton tbFindNext;
       QToolButton tbPrint;
       QToolButton tbUppercase;
       QToolButton tbLowercase;
       QToolButton tbJustifyLeft;
       QToolButton tbJustifyCenter;
       QToolButton tbJustifyRight;
       QToolButton tbJustifyFill;

       QSpinBox sbNumberPage;

       QLineEdit tbFindEdit;//Поле для поиска

       TTextBook *TextBook;//Текст книги
       //TStatistics *FormStat;//Форма статистики
       //THelpViewer *FormHelpViewer;//Форма руководства пользователя
       FileOptions *FO;//Форма свойств программы
       //FormOptions *FormOpt;

       explicit ICL(QMainWindow *pwgt = 0);
       ~ICL();

       Ui::ICL *ui;

       void setVisibilityOfToolbar();//Задать видимость панелей
       void showWelcome();//Показать окно приветствия
       void getUserName();//Получить имя пользователя

private:
        QProcess *ShelkTest;//Процесс внешней программы Шёлковый тест
        QWebView *wvUpdate;//Для проверки наличия новой версии

        void CreateToolBar();//Создание панелей инструментов

protected:
       void closeEvent(QCloseEvent *event);//Событие закрытия окна

public slots:
       int slotModeEditing();//Переключение меню в режим редактирования
       int slotModeViewing();//Переключение меню в режим просмотра
       void openLibrary(bool bOpen);
       
private slots:
       void slotOpenDonate();//Открытие страницы сайта о программе
       void slotOpenGetSource();//Открытие страницы сайта о программе
       void slotBackupLibrary();//Резервировать библиотеку
       void slotRestoreLibrary();//Восстановить из архива библиотеку
       void slotGetSupport();//Получить техническую поддержку
       void slotReportBug();//Сообщить об ошибке
       void slotCreateLibrary();//Создать библиотеку
       int slotCloseLibrary();//Закрыть библиотеку
       void slotExitProgram();//Выход из программы
       void slotOpenBook();//Показать список книг
       int slotClose();//Закрыть книгу
       void slotSave();//Перед сохранением
       void openBook();//Открыть книгу
       void slotNextPage();//Следующая страница
       void slotPreviousPage();//Предыдущая страница
       void slotSetModeViewing();//Применить режим просмотра
       void slotSetModeEditing();//Применить режим редактирования
       void slotNumberPage();//Перейти на выбранную страницу
       void slotTextChanged();//При изменении текста
       int messageChangeText();//Диалог об изменении текста
       bool slotOpenBookFile(QString FileNameBook);//Перед открытием книги из файла
       void slotCreate();//Создать новую книгу
       void showOptions();//Показать параметры программы
       bool slotOpenHTMLFile(QString sFileNameBook);//Импорт html-файла
       void slotDeleteCurrentPage();//Удалить текущую страницу
       void slotInsertNewPage();//Вставить новую страницу
       void slotPanelNumberPage();//Переход на номер страницы в QSpinBox sbNumberPage
       bool slotOpenEncodedPlainText(QString sFileNameBook);//Импорт из кодированного текста, формата UTF-8
       uchar setModePassword();//Задать пароль режима
       bool checkModePassword();//Проверка режима пароля
       void slotEditModePassword();//Изменить пароль режима
       void slotShowAdditionally();//Показать дополнительную информацию
       void openMenuEditActions();//Включение пунктов меню правки
       void closeMenuEditActions();//Выключение пунктов меню правки
       void slotOpenTest();//Открыть внешнюю программу Шёлковый тест
       void userStat();//Статистика работы с программой
       void slotCursorPositionChanged();//Активация пунктов меню, относительно положения курсора
       void slotFontNext();//Изменение шрифта из списка шрифтов
       void slotUndoAvailable(bool b);//Проверить доступность отмены
       void slotRedoAvailable(bool b);//Проверить доступность возврата
       void slotCopyAvailable(bool b);//Проверить доступность возможности копирования
       void totbFindEdit(QString fText);
       void slotToolFindText();//Поиск текста вперёд с интрументальной панели поиска
       void slotGetModeWork();//Получить режим работы программы
       void slotEnableFindButtons(QString fText);//Включить кнопки поиска
       void slotCheckForUpdates();
       void slotMakeCheckUpdates(bool bError);
       void slotBeforeExport();
       void slotOpenLibrary();//Перед открытием библиотеки
       void on_actionImportFolder_triggered();
       void on_actionImportOneBook_triggered();
};
#endif //ICL_H
