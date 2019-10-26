/********************************************************************************
** Form generated from reading UI file 'ListAdditionally.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTADDITIONALLY_H
#define UI_LISTADDITIONALLY_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ListAdditionally
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbAddFile;
    QPushButton *pbRemoveFile;
    QListWidget *lwAdditionally;
    QDialogButtonBox *bbAdditionally;

    void setupUi(QDialog *ListAdditionally)
    {
        if (ListAdditionally->objectName().isEmpty())
            ListAdditionally->setObjectName(QString::fromUtf8("ListAdditionally"));
        ListAdditionally->resize(664, 300);
        ListAdditionally->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        horizontalLayout_2 = new QHBoxLayout(ListAdditionally);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pbAddFile = new QPushButton(ListAdditionally);
        pbAddFile->setObjectName(QString::fromUtf8("pbAddFile"));

        horizontalLayout->addWidget(pbAddFile);

        pbRemoveFile = new QPushButton(ListAdditionally);
        pbRemoveFile->setObjectName(QString::fromUtf8("pbRemoveFile"));

        horizontalLayout->addWidget(pbRemoveFile);


        verticalLayout->addLayout(horizontalLayout);

        lwAdditionally = new QListWidget(ListAdditionally);
        lwAdditionally->setObjectName(QString::fromUtf8("lwAdditionally"));

        verticalLayout->addWidget(lwAdditionally);

        bbAdditionally = new QDialogButtonBox(ListAdditionally);
        bbAdditionally->setObjectName(QString::fromUtf8("bbAdditionally"));
        bbAdditionally->setOrientation(Qt::Horizontal);
        bbAdditionally->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        bbAdditionally->setCenterButtons(true);

        verticalLayout->addWidget(bbAdditionally);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(ListAdditionally);
        QObject::connect(bbAdditionally, SIGNAL(accepted()), ListAdditionally, SLOT(accept()));
        QObject::connect(bbAdditionally, SIGNAL(rejected()), ListAdditionally, SLOT(reject()));

        QMetaObject::connectSlotsByName(ListAdditionally);
    } // setupUi

    void retranslateUi(QDialog *ListAdditionally)
    {
        ListAdditionally->setWindowTitle(QApplication::translate("ListAdditionally", "List files", 0, QApplication::UnicodeUTF8));
        pbAddFile->setText(QApplication::translate("ListAdditionally", "Add file", 0, QApplication::UnicodeUTF8));
        pbRemoveFile->setText(QApplication::translate("ListAdditionally", "Remove file", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ListAdditionally: public Ui_ListAdditionally {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTADDITIONALLY_H
