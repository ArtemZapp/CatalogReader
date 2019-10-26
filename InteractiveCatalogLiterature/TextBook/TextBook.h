/* ======================================================================
**  TextBook.h - Заголовочный файл модуля контекстного меню
*/

#ifndef TEXTBOOK_H
#define TEXTBOOK_H
#include <QtGui/QTextEdit>
#include <QtGui/QMenu>
#include <QtGui/QContextMenuEvent>
#include <QtGui/QAction>
#include <QtGui/QTextDocumentFragment>
#include <QtGui/QPrintDialog>
#include <QtGui/QPrinter>
#include <QtGui/QPainter>
#include <QtGui/QInputDialog>
//#include <QtGui/QTextTable>
#include <QtGui/QFileDialog>
#include <QtGui/QProgressDialog>
#include <QtGui/QMessageBox>
#include <QtGui/QFontDialog>
#include <QtCore/QDir>
#include <QtCore/QTextStream>
#include <QtCore/QTime>
#include <QtCore/QBuffer>
#include <QtCore/QCryptographicHash>
#include <QtCore/QUrl>
#include <QtCore/QTemporaryFile>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include "../fileoptions/fileoptions.h"
#include "../const.h"

class TTextBook : public QTextEdit {
    Q_OBJECT
    Q_PROPERTY(bool saved READ isSaved() WRITE setSaved())
    Q_PROPERTY(bool modeWork READ isModeWork() WRITE setModeWork())
    Q_PROPERTY(int numberBook READ numberBook() WRITE setNumberBook())
    Q_PROPERTY(int year READ year() WRITE setYear())
    Q_PROPERTY(int currentPage READ currentPage() WRITE setCurrentPage())
    Q_PROPERTY(QByteArray password READ password() WRITE setPassword())


public:
    class WrongFileFormat {};
    class WrongPassword {};

    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionSelectAll;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;

    QStringList ListPages;//Список страниц
    QStringList slTableNumber;//Список номеров таблиц базы данных
    QStringList slNumberImages;//Список номеров изображений
    QVector<QByteArray> ListImages;//Список изображений

    QString sTextPage;//Текст текущей страницы
    QString sNameBook;//Название книги
    QString sPrintingHouse;//Издательство
    QString sCategory;//Категория
    QString sSubcategory;//Подкатегория
    QString sFindText;//Текст для поиска
    QString sTimeBegin;//Время начала

    FileOptions *FO;

    explicit TTextBook(QTextEdit *pwgt = 0);
    ~TTextBook();

    bool isSaved() const;//Проверить состояние сохранения
    int countPages() const;//Получить количество страниц
    int numberBook() const;//Получить номер книги
    int year() const;//Получить год издания
    int currentPage() const;//Получить номер текущей страницы
    int isModeWork() const;//Получить режим работы программы
    QByteArray password() const;//Получить пароль книги
    uchar openBookBase(bool bExport);//Открыть книгу
    void clearVariable();//Очистка переменных
    void save();//Сохранение книги
    uchar openBookFile(QString FileNameBook);//Открыть книгу из файла(импорт)
    void insertNewPage();//Вставить новую страницу
    void deleteCurrentPage();//Удалить текущую страницу
    uchar numberPage();//Перейти на выбранную страницу
    uchar openHTMLFile(QString FileNameBook);//Импорт html-файла
    uchar openEncodedPlainText(QString FileNameBook);//Импорт из кодированного текста, формата UTF-8
    uchar nextPage();//Следующая страница
    uchar previousPage();//Предыдущая страница
    uchar setPasswordBook();//Изменить пароль книги

private:
    QMenu *MenuText;
    bool b_Saved;//Состояние сохранения
    bool b_ModeWork;//Режим работы программы
    int i_NumberBook;//Текущая книга
    int i_Year;//Год издания
    int i_CurrentPage;//Текущая страница
    QByteArray ba_Password;//Пароль книги

    void saveToFile(QString FileNameBook);//Выполнить экспорт в файл xwb
    void saveToHTMLFile(QString FileNameBook);//Выполнить экспорт в файл html
    void saveToEncodedPlainText(QString FileNameBook);//Выполнить экспорт в файл txt
    void saveToPortable(QString FileNameBook, QString sFormat);//Выполнить экспорт в файл PDF или PostScript
    void saveToRTF(QString FileNameBook);//Выполнить экспорт в файл rtf
    bool checkPasswordBook();//Проверить пароль книги
    QString makeOneHTML();//Сделать одну html-страницу
    QString wordToUnicode(QString sWord);//Сформировать rtf-предложение :)

protected:
    virtual void contextMenuEvent(QContextMenuEvent *event);

signals:
    void NextPage();
    void PreviousPage();
    void totbFindEdit(QString fText);
    void slotClose();
    void getModeWork();

public slots:
    void setSaved(bool bSaved);//Задать состояние сохранения
    void setNumberBook(int iNumberBook);//Задать номер книги
    void setYear(int iYear);//Задать год издания
    void setCurrentPage(int iCurrentPage);//Задать номер текущей страницы
    void setModeWork(bool bModeWork);//Задать режим работы программы
    void setPassword(QByteArray baPassword );//Задать пароль книги
    uchar slotEditPasswordBook();//Изменить пароль книги
    void slotJustifyLeft();//Выравнивание по левому краю
    void slotJustifyCenter();//Выравнивание по центру
    void slotJustifyRight();//Выравнивание по правому краю
    void slotJustifyFill();//Выравнивание по ширине
    void slotUppercase();//Прописные буквы
    void slotLowercase();//Строчные буквы
    void slotPrint();//Печать
    void slotFindText();//Поиск текста вперёд
    void slotFindNext();//Поиск далее
    void slotFindPrevious();//Поиск назад
    void slotExportAllBooks();//Экспорт всех книг в файы
    void slotInsertImage();//Вставить изображение
    void slotChangeFont();//Изменить шрифт
    void slotToPlainText();
    void exportBook();//Сохранить книгу в файл(экспорт)

};
#endif // TEXTBOOK_H
