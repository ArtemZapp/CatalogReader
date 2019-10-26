/* ======================================================================
**  ListBooks.cpp - Исходный файл модуля формы списка книг библиотеки.
*/

#include "ListBooks.h"


ListBooks::ListBooks(QDialog *pwgt /* = 0*/): QDialog(pwgt),
    ui(new Ui::ListBooks)
{
    ui->setupUi(this);

    connect(ui->AddBook, SIGNAL(clicked()), SLOT(slotAddBook()));
    connect(ui->DelBook, SIGNAL(clicked()), SLOT(slotDelBook()));
    connect(ui->bSave, SIGNAL(clicked()), SLOT(slotbSave()));
    connect(ui->TableListBooks, SIGNAL(clicked(QModelIndex)), SLOT(slotCellClicked()));
    iNumberBook = -1;
}

ListBooks::~ListBooks()
{
    delete ui;
}

void ListBooks::slotCellClicked()
{
    iNumberBook = ui->TableListBooks->currentIndex().row();
}

void ListBooks::slotAddBook()
{
    QSqlQuery sqNewBook;
    QString sQuery;
    sQuery = "INSERT INTO ListBooks (NameBook) VALUES('');";
    sqNewBook.exec(sQuery);

    /*srand(QTime::currentTime().msec());
    iNumberBook = rand() % 10000000;

    while ((slTableNumber->indexOf(QString::number(iNumberBook)) != -1))
    {
        srand(QTime::currentTime().msec());
        iNumberBook = rand() % 10000000;
    }

    slTableNumber->append(QString::number(iNumberBook));
    sQuery = "DROP TABLE slListBooks;";
    sqNewBook.exec(sQuery);
    sQuery = "CREATE TABLE slListBooks (slTableNumber VARCHAR);";
    sqNewBook.exec(sQuery);

    for(int i = 0; i < slTableNumber->count(); i++)
    {

        sqNewBook.prepare("INSERT INTO slListBooks (slTableNumber) VALUES (?);");
        sqNewBook.bindValue(0, slTableNumber->at(i));
        sqNewBook.exec();

    }

    sQuery = "CREATE TABLE Table" + QString::number(iNumberBook) + " (Pages VARCHAR, Images BLOB, NumberImages VARCHAR);";
    sqNewBook.exec(sQuery);*/
    model->submitAll();
    iCountTable++;
}

void ListBooks::slotDelBook()
{
    QSqlQuery sqDeleteBook;
    QString sQuery;
    QString strNumber;

    if (slTableNumber->count() > 0 && iNumberBook >= 0) strNumber = slTableNumber->at(iNumberBook);

    if (ui->TableListBooks->currentIndex().row() == -1)
    {
        model->removeRow(model->rowCount() - 1);
        sQuery = "DROP TABLE Table" + QString::number(iCountTable) + ";";
        slTableNumber->removeLast();
        sqDeleteBook.exec(sQuery);
        model->submitAll();
    }
    else
    {
        model->removeRow(iNumberBook);
        sQuery = "DROP TABLE Table" + strNumber + ";";
        slTableNumber->removeAt(iNumberBook);
        sqDeleteBook.exec(sQuery);
        model->submitAll();
    }

    model->submitAll();

    if (iCountTable > 0) iCountTable--;

    iNumberBook = -1;
}

void ListBooks::slotbSave()
{
    model->submitAll();
}
