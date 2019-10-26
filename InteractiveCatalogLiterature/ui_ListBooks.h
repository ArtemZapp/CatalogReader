/********************************************************************************
** Form generated from reading UI file 'ListBooks.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTBOOKS_H
#define UI_LISTBOOKS_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ListBooks
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *AddBook;
    QPushButton *DelBook;
    QPushButton *bSave;
    QVBoxLayout *verticalLayout;
    QTableView *TableListBooks;
    QDialogButtonBox *ButtonBoxListBooks;

    void setupUi(QDialog *ListBooks)
    {
        if (ListBooks->objectName().isEmpty())
            ListBooks->setObjectName(QString::fromUtf8("ListBooks"));
        ListBooks->resize(484, 397);
        ListBooks->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout = new QGridLayout(ListBooks);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        AddBook = new QPushButton(ListBooks);
        AddBook->setObjectName(QString::fromUtf8("AddBook"));

        horizontalLayout->addWidget(AddBook);

        DelBook = new QPushButton(ListBooks);
        DelBook->setObjectName(QString::fromUtf8("DelBook"));

        horizontalLayout->addWidget(DelBook);

        bSave = new QPushButton(ListBooks);
        bSave->setObjectName(QString::fromUtf8("bSave"));

        horizontalLayout->addWidget(bSave);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        TableListBooks = new QTableView(ListBooks);
        TableListBooks->setObjectName(QString::fromUtf8("TableListBooks"));
        TableListBooks->setSelectionMode(QAbstractItemView::SingleSelection);
        TableListBooks->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(TableListBooks);

        ButtonBoxListBooks = new QDialogButtonBox(ListBooks);
        ButtonBoxListBooks->setObjectName(QString::fromUtf8("ButtonBoxListBooks"));
        ButtonBoxListBooks->setOrientation(Qt::Horizontal);
        ButtonBoxListBooks->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        ButtonBoxListBooks->setCenterButtons(true);

        verticalLayout->addWidget(ButtonBoxListBooks);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);


        retranslateUi(ListBooks);
        QObject::connect(ButtonBoxListBooks, SIGNAL(accepted()), ListBooks, SLOT(accept()));
        QObject::connect(ButtonBoxListBooks, SIGNAL(rejected()), ListBooks, SLOT(reject()));

        QMetaObject::connectSlotsByName(ListBooks);
    } // setupUi

    void retranslateUi(QDialog *ListBooks)
    {
        ListBooks->setWindowTitle(QApplication::translate("ListBooks", "List books", 0, QApplication::UnicodeUTF8));
        AddBook->setText(QApplication::translate("ListBooks", "Add book", 0, QApplication::UnicodeUTF8));
        DelBook->setText(QApplication::translate("ListBooks", "Delete book", 0, QApplication::UnicodeUTF8));
        bSave->setText(QApplication::translate("ListBooks", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ListBooks: public Ui_ListBooks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTBOOKS_H
