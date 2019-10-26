/********************************************************************************
** Form generated from reading UI file 'ICL.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ICL_H
#define UI_ICL_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ICL
{
public:
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionSelectAll;
    QAction *actionEditing;
    QAction *actionReading;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionCreate;
    QAction *actionAdditionally;
    QAction *actionCreateLibrary;
    QAction *actionOpenLibrary;
    QAction *actionCloseLibrary;
    QAction *actionBackupLibrary;
    QAction *actionRestoreLibrary;
    QAction *actionFindText;
    QAction *actionInsertImage;
    QAction *actionDeletePage;
    QAction *actionNextPage;
    QAction *actionPreviousPage;
    QAction *actionEnterNumberPage;
    QAction *actionExportAllBooks;
    QAction *actionExportThisBook;
    QAction *actionImportFolder;
    QAction *actionImportOneBook;
    QWidget *centralwidget;
    QMenuBar *mmKlenLibrary;
    QMenu *menuBook;
    QMenu *menuExport;
    QMenu *menuImport;
    QMenu *menuService;
    QMenu *menuLibrary;
    QMenu *menuView;
    QMenu *menuInsert;
    QMenu *menuEdit;
    QToolBar *tbStandard;
    QStatusBar *sbKlenLibrary;
    QToolBar *tbFind;

    void setupUi(QMainWindow *ICL)
    {
        if (ICL->objectName().isEmpty())
            ICL->setObjectName(QString::fromUtf8("ICL"));
        ICL->resize(681, 444);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/toolbar/toolbar/klen-poster.png"), QSize(), QIcon::Normal, QIcon::Off);
        ICL->setWindowIcon(icon);
        ICL->setAutoFillBackground(false);
        ICL->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        actionOpen = new QAction(ICL);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/toolbar/toolbar/document-open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionClose = new QAction(ICL);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/toolbar/toolbar/dialog-close.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon2);
        actionSave = new QAction(ICL);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/toolbar/toolbar/document-save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon3);
        actionExit = new QAction(ICL);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/toolbar/toolbar/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon4);
        actionUndo = new QAction(ICL);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/toolbar/toolbar/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon5);
        actionRedo = new QAction(ICL);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/toolbar/toolbar/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon6);
        actionSelectAll = new QAction(ICL);
        actionSelectAll->setObjectName(QString::fromUtf8("actionSelectAll"));
        actionSelectAll->setCheckable(false);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/toolbar/toolbar/select-all.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectAll->setIcon(icon7);
        actionEditing = new QAction(ICL);
        actionEditing->setObjectName(QString::fromUtf8("actionEditing"));
        actionEditing->setCheckable(true);
        actionEditing->setChecked(false);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/toolbar/toolbar/editing.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEditing->setIcon(icon8);
        actionReading = new QAction(ICL);
        actionReading->setObjectName(QString::fromUtf8("actionReading"));
        actionReading->setCheckable(true);
        actionReading->setChecked(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/toolbar/toolbar/view.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReading->setIcon(icon9);
        actionCut = new QAction(ICL);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/toolbar/toolbar/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon10);
        actionCopy = new QAction(ICL);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/toolbar/toolbar/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon11);
        actionPaste = new QAction(ICL);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/toolbar/toolbar/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon12);
        actionCreate = new QAction(ICL);
        actionCreate->setObjectName(QString::fromUtf8("actionCreate"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/toolbar/toolbar/document-new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreate->setIcon(icon13);
        actionAdditionally = new QAction(ICL);
        actionAdditionally->setObjectName(QString::fromUtf8("actionAdditionally"));
        actionCreateLibrary = new QAction(ICL);
        actionCreateLibrary->setObjectName(QString::fromUtf8("actionCreateLibrary"));
        actionOpenLibrary = new QAction(ICL);
        actionOpenLibrary->setObjectName(QString::fromUtf8("actionOpenLibrary"));
        actionCloseLibrary = new QAction(ICL);
        actionCloseLibrary->setObjectName(QString::fromUtf8("actionCloseLibrary"));
        actionBackupLibrary = new QAction(ICL);
        actionBackupLibrary->setObjectName(QString::fromUtf8("actionBackupLibrary"));
        actionRestoreLibrary = new QAction(ICL);
        actionRestoreLibrary->setObjectName(QString::fromUtf8("actionRestoreLibrary"));
        actionFindText = new QAction(ICL);
        actionFindText->setObjectName(QString::fromUtf8("actionFindText"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/toolbar/toolbar/edit-find.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFindText->setIcon(icon14);
        actionInsertImage = new QAction(ICL);
        actionInsertImage->setObjectName(QString::fromUtf8("actionInsertImage"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/toolbar/toolbar/insert-image.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInsertImage->setIcon(icon15);
        actionDeletePage = new QAction(ICL);
        actionDeletePage->setObjectName(QString::fromUtf8("actionDeletePage"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/toolbar/toolbar/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDeletePage->setIcon(icon16);
        actionNextPage = new QAction(ICL);
        actionNextPage->setObjectName(QString::fromUtf8("actionNextPage"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/toolbar/toolbar/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNextPage->setIcon(icon17);
        actionPreviousPage = new QAction(ICL);
        actionPreviousPage->setObjectName(QString::fromUtf8("actionPreviousPage"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/toolbar/toolbar/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPreviousPage->setIcon(icon18);
        actionEnterNumberPage = new QAction(ICL);
        actionEnterNumberPage->setObjectName(QString::fromUtf8("actionEnterNumberPage"));
        actionExportAllBooks = new QAction(ICL);
        actionExportAllBooks->setObjectName(QString::fromUtf8("actionExportAllBooks"));
        actionExportThisBook = new QAction(ICL);
        actionExportThisBook->setObjectName(QString::fromUtf8("actionExportThisBook"));
        actionImportFolder = new QAction(ICL);
        actionImportFolder->setObjectName(QString::fromUtf8("actionImportFolder"));
        actionImportOneBook = new QAction(ICL);
        actionImportOneBook->setObjectName(QString::fromUtf8("actionImportOneBook"));
        centralwidget = new QWidget(ICL);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ICL->setCentralWidget(centralwidget);
        mmKlenLibrary = new QMenuBar(ICL);
        mmKlenLibrary->setObjectName(QString::fromUtf8("mmKlenLibrary"));
        mmKlenLibrary->setGeometry(QRect(0, 0, 681, 21));
        menuBook = new QMenu(mmKlenLibrary);
        menuBook->setObjectName(QString::fromUtf8("menuBook"));
        menuBook->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        menuExport = new QMenu(menuBook);
        menuExport->setObjectName(QString::fromUtf8("menuExport"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/toolbar/toolbar/document-export.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuExport->setIcon(icon19);
        menuImport = new QMenu(menuBook);
        menuImport->setObjectName(QString::fromUtf8("menuImport"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/toolbar/toolbar/import.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuImport->setIcon(icon20);
        menuService = new QMenu(mmKlenLibrary);
        menuService->setObjectName(QString::fromUtf8("menuService"));
        menuLibrary = new QMenu(mmKlenLibrary);
        menuLibrary->setObjectName(QString::fromUtf8("menuLibrary"));
        menuView = new QMenu(mmKlenLibrary);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuInsert = new QMenu(mmKlenLibrary);
        menuInsert->setObjectName(QString::fromUtf8("menuInsert"));
        menuEdit = new QMenu(mmKlenLibrary);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        ICL->setMenuBar(mmKlenLibrary);
        tbStandard = new QToolBar(ICL);
        tbStandard->setObjectName(QString::fromUtf8("tbStandard"));
        ICL->addToolBar(Qt::TopToolBarArea, tbStandard);
        sbKlenLibrary = new QStatusBar(ICL);
        sbKlenLibrary->setObjectName(QString::fromUtf8("sbKlenLibrary"));
        sbKlenLibrary->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        ICL->setStatusBar(sbKlenLibrary);
        tbFind = new QToolBar(ICL);
        tbFind->setObjectName(QString::fromUtf8("tbFind"));
        ICL->addToolBar(Qt::TopToolBarArea, tbFind);

        mmKlenLibrary->addAction(menuLibrary->menuAction());
        mmKlenLibrary->addAction(menuBook->menuAction());
        mmKlenLibrary->addAction(menuEdit->menuAction());
        mmKlenLibrary->addAction(menuView->menuAction());
        mmKlenLibrary->addAction(menuInsert->menuAction());
        mmKlenLibrary->addAction(menuService->menuAction());
        menuBook->addAction(actionCreate);
        menuBook->addSeparator();
        menuBook->addAction(actionOpen);
        menuBook->addAction(menuImport->menuAction());
        menuBook->addSeparator();
        menuBook->addAction(actionClose);
        menuBook->addAction(actionSave);
        menuBook->addAction(menuExport->menuAction());
        menuBook->addSeparator();
        menuExport->addAction(actionExportAllBooks);
        menuExport->addAction(actionExportThisBook);
        menuImport->addAction(actionImportFolder);
        menuImport->addAction(actionImportOneBook);
        menuService->addAction(actionAdditionally);
        menuService->addSeparator();
        menuService->addSeparator();
        menuService->addSeparator();
        menuLibrary->addAction(actionCreateLibrary);
        menuLibrary->addSeparator();
        menuLibrary->addAction(actionOpenLibrary);
        menuLibrary->addAction(actionRestoreLibrary);
        menuLibrary->addSeparator();
        menuLibrary->addAction(actionCloseLibrary);
        menuLibrary->addAction(actionBackupLibrary);
        menuLibrary->addSeparator();
        menuLibrary->addAction(actionExit);
        menuView->addAction(actionFindText);
        menuView->addAction(actionPreviousPage);
        menuView->addAction(actionNextPage);
        menuView->addAction(actionEnterNumberPage);
        menuInsert->addAction(actionInsertImage);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addSeparator();

        retranslateUi(ICL);

        QMetaObject::connectSlotsByName(ICL);
    } // setupUi

    void retranslateUi(QMainWindow *ICL)
    {
        ICL->setWindowTitle(QString());
        actionOpen->setText(QApplication::translate("ICL", "Open...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionOpen->setStatusTip(QApplication::translate("ICL", "Opening book from database", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionOpen->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        actionOpen->setShortcut(QApplication::translate("ICL", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("ICL", "Close", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionClose->setStatusTip(QApplication::translate("ICL", "Close opened book", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionClose->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        actionSave->setText(QApplication::translate("ICL", "Save", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionSave->setStatusTip(QApplication::translate("ICL", "Save opened book to database", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionSave->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        actionSave->setShortcut(QApplication::translate("ICL", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("ICL", "Exit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionExit->setStatusTip(QApplication::translate("ICL", "Exit from program", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionExit->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        actionExit->setShortcut(QApplication::translate("ICL", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionUndo->setText(QApplication::translate("ICL", "Undo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionUndo->setStatusTip(QApplication::translate("ICL", "Cancel the action", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionUndo->setShortcut(QApplication::translate("ICL", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        actionRedo->setText(QApplication::translate("ICL", "Redo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionRedo->setStatusTip(QApplication::translate("ICL", "Retry the action", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionRedo->setShortcut(QApplication::translate("ICL", "Ctrl+Shift+Z", 0, QApplication::UnicodeUTF8));
        actionSelectAll->setText(QApplication::translate("ICL", "Select all", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionSelectAll->setStatusTip(QApplication::translate("ICL", "Selection all the text", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionSelectAll->setShortcut(QApplication::translate("ICL", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        actionEditing->setText(QApplication::translate("ICL", "Editing", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionEditing->setStatusTip(QApplication::translate("ICL", "Program switch into regime the editing.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionEditing->setShortcut(QApplication::translate("ICL", "Ctrl+Shift+E", 0, QApplication::UnicodeUTF8));
        actionReading->setText(QApplication::translate("ICL", "Reading", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionReading->setStatusTip(QApplication::translate("ICL", "Program switch into regime the reading.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionReading->setShortcut(QApplication::translate("ICL", "Ctrl+Shift+V", 0, QApplication::UnicodeUTF8));
        actionCut->setText(QApplication::translate("ICL", "Cut", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionCut->setStatusTip(QApplication::translate("ICL", "Cuts selected of the text", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionCut->setShortcut(QApplication::translate("ICL", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        actionCopy->setText(QApplication::translate("ICL", "Copy", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionCopy->setStatusTip(QApplication::translate("ICL", "Copy selected of the text", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionCopy->setShortcut(QApplication::translate("ICL", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        actionPaste->setText(QApplication::translate("ICL", "Paste", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionPaste->setStatusTip(QApplication::translate("ICL", "Paste contents clipboard into the  text", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionPaste->setShortcut(QApplication::translate("ICL", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        actionCreate->setText(QApplication::translate("ICL", "Create...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionCreate->setStatusTip(QApplication::translate("ICL", "Opening the window of the parameters of the new book", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionCreate->setShortcut(QApplication::translate("ICL", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionAdditionally->setText(QApplication::translate("ICL", "Additionally", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionAdditionally->setStatusTip(QApplication::translate("ICL", "Open window with additional of information", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionCreateLibrary->setText(QApplication::translate("ICL", "Create...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionCreateLibrary->setStatusTip(QApplication::translate("ICL", "Create of the new library", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionCreateLibrary->setShortcut(QApplication::translate("ICL", "Ctrl+Shift+N", 0, QApplication::UnicodeUTF8));
        actionOpenLibrary->setText(QApplication::translate("ICL", "Open...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionOpenLibrary->setStatusTip(QApplication::translate("ICL", "Open new library", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionOpenLibrary->setShortcut(QApplication::translate("ICL", "Ctrl+Shift+O", 0, QApplication::UnicodeUTF8));
        actionCloseLibrary->setText(QApplication::translate("ICL", "Close", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionCloseLibrary->setStatusTip(QApplication::translate("ICL", "Close of library", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionBackupLibrary->setText(QApplication::translate("ICL", "Backup...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionBackupLibrary->setStatusTip(QApplication::translate("ICL", "Backup of library", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionBackupLibrary->setShortcut(QApplication::translate("ICL", "Ctrl+Shift+B", 0, QApplication::UnicodeUTF8));
        actionRestoreLibrary->setText(QApplication::translate("ICL", "Restore...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionRestoreLibrary->setStatusTip(QApplication::translate("ICL", "Restore library from the archive", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionFindText->setText(QApplication::translate("ICL", "Find text", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionFindText->setStatusTip(QApplication::translate("ICL", "Finding the text in the book", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionFindText->setShortcut(QApplication::translate("ICL", "Ctrl+F", 0, QApplication::UnicodeUTF8));
        actionInsertImage->setText(QApplication::translate("ICL", "Image", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionInsertImage->setStatusTip(QApplication::translate("ICL", "Inserting image to book", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionInsertImage->setShortcut(QApplication::translate("ICL", "Ctrl+Alt+I", 0, QApplication::UnicodeUTF8));
        actionDeletePage->setText(QApplication::translate("ICL", "Delete", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionDeletePage->setStatusTip(QApplication::translate("ICL", "Delete page from the book", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionDeletePage->setShortcut(QApplication::translate("ICL", "Ctrl+D", 0, QApplication::UnicodeUTF8));
        actionNextPage->setText(QApplication::translate("ICL", "Next page", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionNextPage->setStatusTip(QApplication::translate("ICL", "Go to the next page of book", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionNextPage->setShortcut(QApplication::translate("ICL", "Ctrl+Right", 0, QApplication::UnicodeUTF8));
        actionPreviousPage->setText(QApplication::translate("ICL", "Previous page", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionPreviousPage->setStatusTip(QApplication::translate("ICL", "Go to the previous page of book", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionPreviousPage->setShortcut(QApplication::translate("ICL", "Ctrl+Left", 0, QApplication::UnicodeUTF8));
        actionEnterNumberPage->setText(QApplication::translate("ICL", "Enter number page...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionEnterNumberPage->setStatusTip(QApplication::translate("ICL", "Go to number page of book", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionEnterNumberPage->setShortcut(QApplication::translate("ICL", "Ctrl+Alt+N", 0, QApplication::UnicodeUTF8));
        actionExportAllBooks->setText(QApplication::translate("ICL", "All books...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionExportAllBooks->setStatusTip(QApplication::translate("ICL", "Export all of books into a file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionExportThisBook->setText(QApplication::translate("ICL", "This book...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionExportThisBook->setStatusTip(QApplication::translate("ICL", "Export of book into a file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionExportThisBook->setShortcut(QApplication::translate("ICL", "Ctrl+E", 0, QApplication::UnicodeUTF8));
        actionImportFolder->setText(QApplication::translate("ICL", "Folder...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionImportFolder->setStatusTip(QApplication::translate("ICL", "Batch Import all books from a selected folder", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionImportOneBook->setText(QApplication::translate("ICL", "One book...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionImportOneBook->setStatusTip(QApplication::translate("ICL", "Import of book from a file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionImportOneBook->setShortcut(QApplication::translate("ICL", "Ctrl+I", 0, QApplication::UnicodeUTF8));
        menuBook->setTitle(QApplication::translate("ICL", "Book", 0, QApplication::UnicodeUTF8));
        menuExport->setTitle(QApplication::translate("ICL", "Export", 0, QApplication::UnicodeUTF8));
        menuImport->setTitle(QApplication::translate("ICL", "Import", 0, QApplication::UnicodeUTF8));
        menuService->setTitle(QApplication::translate("ICL", "Service", 0, QApplication::UnicodeUTF8));
        menuLibrary->setTitle(QApplication::translate("ICL", "Catalog", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("ICL", "View", 0, QApplication::UnicodeUTF8));
        menuInsert->setTitle(QApplication::translate("ICL", "Insert", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("ICL", "Edit", 0, QApplication::UnicodeUTF8));
        tbStandard->setWindowTitle(QApplication::translate("ICL", "Standard toolbar", 0, QApplication::UnicodeUTF8));
        tbFind->setWindowTitle(QApplication::translate("ICL", "Find toolbar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ICL: public Ui_ICL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ICL_H
