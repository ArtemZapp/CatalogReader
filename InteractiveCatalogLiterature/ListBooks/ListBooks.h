/* ======================================================================
**  ListBooks.h - Заголовочный файл модуля формы списка книг библиотеки.
*/

#ifndef LISTBOOKS_H
#define LISTBOOKS_H
#include "ui_ListBooks.h"
#include <QtCore/QString>
#include <QtCore/QTime>
#include <QtCore/QStringList>
#include <QtGui/QDialog>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlTableModel>

namespace Ui {
class TListBooks;
}

class ListBooks : public QDialog, public Ui::ListBooks {
    Q_OBJECT

public:

    int iNumberBook;//Номер книги
    int iCountTable;//Количество книг

    QStringList *slTableNumber;//Список номеров таблиц

    QSqlTableModel *model;//Модель списка книг

    explicit ListBooks(QDialog *pwgt = 0);
    ~ListBooks();

    Ui::ListBooks *ui;

private:

public slots:
    void slotCellClicked();//Выбор книги
    void slotAddBook();//Добавить книгу
    void slotDelBook();//Удалить книгу
    void slotbSave();//Сохранить базу


};
#endif //LISTBOOKS_H
