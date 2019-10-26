/********************************************************************************
** Form generated from reading UI file 'Create.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_H
#define UI_CREATE_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Create
{
public:
    QVBoxLayout *verticalLayout_4;
    QGroupBox *gbName;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *leNameBook;
    QGroupBox *gbPrintingHouse;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lePrintingHouse;
    QGroupBox *gbCategory;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *leCategory;
    QGroupBox *gbSubcategory;
    QVBoxLayout *verticalLayout;
    QLineEdit *leSubCategory;
    QGroupBox *gbYear;
    QVBoxLayout *verticalLayout_3;
    QSpinBox *sbYear;
    QDialogButtonBox *bbListBooks;

    void setupUi(QDialog *Create)
    {
        if (Create->objectName().isEmpty())
            Create->setObjectName(QString::fromUtf8("Create"));
        Create->resize(365, 376);
        Create->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        verticalLayout_4 = new QVBoxLayout(Create);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gbName = new QGroupBox(Create);
        gbName->setObjectName(QString::fromUtf8("gbName"));
        horizontalLayout_2 = new QHBoxLayout(gbName);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        leNameBook = new QLineEdit(gbName);
        leNameBook->setObjectName(QString::fromUtf8("leNameBook"));

        horizontalLayout_2->addWidget(leNameBook);


        verticalLayout_4->addWidget(gbName);

        gbPrintingHouse = new QGroupBox(Create);
        gbPrintingHouse->setObjectName(QString::fromUtf8("gbPrintingHouse"));
        horizontalLayout_3 = new QHBoxLayout(gbPrintingHouse);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lePrintingHouse = new QLineEdit(gbPrintingHouse);
        lePrintingHouse->setObjectName(QString::fromUtf8("lePrintingHouse"));

        horizontalLayout_3->addWidget(lePrintingHouse);


        verticalLayout_4->addWidget(gbPrintingHouse);

        gbCategory = new QGroupBox(Create);
        gbCategory->setObjectName(QString::fromUtf8("gbCategory"));
        verticalLayout_2 = new QVBoxLayout(gbCategory);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        leCategory = new QLineEdit(gbCategory);
        leCategory->setObjectName(QString::fromUtf8("leCategory"));

        verticalLayout_2->addWidget(leCategory);


        verticalLayout_4->addWidget(gbCategory);

        gbSubcategory = new QGroupBox(Create);
        gbSubcategory->setObjectName(QString::fromUtf8("gbSubcategory"));
        verticalLayout = new QVBoxLayout(gbSubcategory);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        leSubCategory = new QLineEdit(gbSubcategory);
        leSubCategory->setObjectName(QString::fromUtf8("leSubCategory"));

        verticalLayout->addWidget(leSubCategory);


        verticalLayout_4->addWidget(gbSubcategory);

        gbYear = new QGroupBox(Create);
        gbYear->setObjectName(QString::fromUtf8("gbYear"));
        verticalLayout_3 = new QVBoxLayout(gbYear);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        sbYear = new QSpinBox(gbYear);
        sbYear->setObjectName(QString::fromUtf8("sbYear"));
        sbYear->setMinimum(-999999999);
        sbYear->setMaximum(999999999);
        sbYear->setValue(2013);

        verticalLayout_3->addWidget(sbYear);


        verticalLayout_4->addWidget(gbYear);

        bbListBooks = new QDialogButtonBox(Create);
        bbListBooks->setObjectName(QString::fromUtf8("bbListBooks"));
        bbListBooks->setOrientation(Qt::Horizontal);
        bbListBooks->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        bbListBooks->setCenterButtons(true);

        verticalLayout_4->addWidget(bbListBooks);


        retranslateUi(Create);
        QObject::connect(bbListBooks, SIGNAL(accepted()), Create, SLOT(accept()));
        QObject::connect(bbListBooks, SIGNAL(rejected()), Create, SLOT(reject()));

        QMetaObject::connectSlotsByName(Create);
    } // setupUi

    void retranslateUi(QDialog *Create)
    {
        Create->setWindowTitle(QApplication::translate("Create", "Creating new a book", 0, QApplication::UnicodeUTF8));
        gbName->setTitle(QApplication::translate("Create", "Name book", 0, QApplication::UnicodeUTF8));
        gbPrintingHouse->setTitle(QApplication::translate("Create", "Printing house", 0, QApplication::UnicodeUTF8));
        gbCategory->setTitle(QApplication::translate("Create", "Category", 0, QApplication::UnicodeUTF8));
        gbSubcategory->setTitle(QApplication::translate("Create", "Subcategory", 0, QApplication::UnicodeUTF8));
        gbYear->setTitle(QApplication::translate("Create", "Year", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Create: public Ui_Create {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_H
