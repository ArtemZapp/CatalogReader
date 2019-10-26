#include "ICL.h"

    ICL::ICL(QMainWindow *pwgt /* = 0*/): QMainWindow(pwgt),
    TextBook(new TTextBook),
    FO(new FileOptions),
    ui(new Ui::ICL),
    wvUpdate(new QWebView)
{
    ui->setupUi(this);

    setWindowTitle(APPLICATION_NAME_VERSION);

    lMode.setText(tr("Reading"));
    sbNumberPage.setEnabled(false);
    sbNumberPage.setMinimum(1);
    TextBook->show();

    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(slotExitProgram()));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(slotOpenBook()));
    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(slotClose()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(slotSave()));
    connect(ui->actionExportThisBook, SIGNAL(triggered()), this, SLOT(slotBeforeExport()));
    connect(ui->actionExportAllBooks, SIGNAL(triggered()), TextBook, SLOT(slotExportAllBooks()));
    connect(ui->actionNextPage, SIGNAL(triggered()), this, SLOT(slotNextPage()));
    connect(ui->actionPreviousPage, SIGNAL(triggered()), this, SLOT(slotPreviousPage()));
    connect(ui->actionUndo, SIGNAL(triggered()), TextBook, SLOT(undo()));
    connect(ui->actionRedo, SIGNAL(triggered()), TextBook, SLOT(redo()));
    connect(ui->actionSelectAll, SIGNAL(triggered()), TextBook, SLOT(slotToPlainText()/*selectAll()*/));
    connect(ui->actionInsertImage, SIGNAL(triggered()), TextBook, SLOT(slotInsertImage()));
    connect(ui->actionCut, SIGNAL(triggered()), TextBook, SLOT(cut()));
    connect(ui->actionCopy, SIGNAL(triggered()), TextBook, SLOT(copy()));
    connect(ui->actionPaste, SIGNAL(triggered()), TextBook, SLOT(paste()));
    connect(ui->actionEditing, SIGNAL(triggered()), this, SLOT(slotModeEditing()));
    connect(ui->actionReading, SIGNAL(triggered()), this, SLOT(slotModeViewing()));
    connect(ui->actionEnterNumberPage, SIGNAL(triggered()), this, SLOT(slotNumberPage()));
    connect(TextBook, SIGNAL(textChanged()), this, SLOT(slotTextChanged()));
    connect(ui->actionCreate, SIGNAL(triggered()), this, SLOT(slotCreate()));
    connect(ui->actionDeletePage, SIGNAL(triggered()), this, SLOT(slotDeleteCurrentPage()));
    connect(&sbNumberPage, SIGNAL(valueChanged(int)), this, SLOT(slotPanelNumberPage()));
    connect(ui->actionFindText, SIGNAL(triggered()), TextBook, SLOT(slotFindText()));
    connect(ui->actionCloseLibrary, SIGNAL(triggered()), this, SLOT(slotCloseLibrary()));
    connect(ui->actionAdditionally, SIGNAL(triggered()), this, SLOT(slotShowAdditionally()));
    connect(TextBook, SIGNAL(cursorPositionChanged()), this, SLOT(slotCursorPositionChanged()));
    connect(ui->actionCreateLibrary, SIGNAL(triggered()), this, SLOT(slotCreateLibrary()));
    connect(ui->actionOpenLibrary, SIGNAL(triggered()), this, SLOT(slotOpenLibrary()));
    connect(ui->actionBackupLibrary, SIGNAL(triggered()), this, SLOT(slotBackupLibrary()));
    connect(ui->actionRestoreLibrary, SIGNAL(triggered()), this, SLOT(slotRestoreLibrary()));
    connect(TextBook, SIGNAL(undoAvailable(bool)), this, SLOT(slotUndoAvailable(bool)));
    connect(TextBook, SIGNAL(redoAvailable(bool)), this, SLOT(slotRedoAvailable(bool)));
    connect(TextBook, SIGNAL(copyAvailable(bool)), this, SLOT(slotCopyAvailable(bool)));
    connect(TextBook, SIGNAL(NextPage()), this, SLOT(slotNextPage()));
    connect(TextBook, SIGNAL(PreviousPage()), this, SLOT(slotPreviousPage()));
    connect(TextBook, SIGNAL(totbFindEdit(QString)), this, SLOT(totbFindEdit(QString)));
    connect(TextBook, SIGNAL(slotClose()), this, SLOT(slotClose()));
    connect(TextBook, SIGNAL(getModeWork()), this, SLOT(slotGetModeWork()));
    connect(&tbFindEdit, SIGNAL(textChanged(QString)), this, SLOT(slotEnableFindButtons(QString)));
    connect(&tbFindEdit, SIGNAL(returnPressed()), this, SLOT(slotToolFindText()));
    connect(wvUpdate, SIGNAL(loadFinished(bool)), SLOT(slotMakeCheckUpdates(bool)));

    ui->sbKlenLibrary->addWidget(&lMode);
    ui->sbKlenLibrary->addWidget(&lUserName);
    lUserName.setToolTip(tr("User name"));
    ui->sbKlenLibrary->addWidget(&lNameBook);
    ui->sbKlenLibrary->addWidget(&lSubcategory);
    ui->sbKlenLibrary->addWidget(&lCategory);
    ui->sbKlenLibrary->addWidget(&lYear);
    ui->sbKlenLibrary->addWidget(&lPrintingHouse);
    ui->sbKlenLibrary->addWidget(&sbNumberPage);
    sbNumberPage.setToolTip(tr("Page number"));
    ui->sbKlenLibrary->addWidget(&lCountPages);
    lMode.setToolTip(tr("Mode work of the program"));
    lNameBook.setToolTip(tr("The name of book"));
    lSubcategory.setToolTip(tr("The subcategory"));
    lCategory.setToolTip(tr("The category"));
    lYear.setToolTip(tr("The year"));
    lPrintingHouse.setToolTip(tr("The printing house"));
    lCountPages.setToolTip(tr("The count pages"));

    QBoxLayout* pbxLayout;
    pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    pbxLayout->addWidget(TextBook, 3);
    ui->centralwidget->setLayout(pbxLayout);

    CreateToolBar();
}

ICL::~ICL()
{
    delete TextBook;
    delete ShelkTest;
    delete wvUpdate;
    delete FO;
    delete ui;
}

void ICL::CreateToolBar()
{
    ui->tbStandard->addWidget(&tbNew);
    tbNew.setIcon(QPixmap(":/toolbar/toolbar/document-new.png"));
    tbNew.setText(tr("New"));
    tbNew.setToolButtonStyle(Qt::ToolButtonIconOnly);
    tbNew.setToolTip(tr("New"));
    connect(&tbNew, SIGNAL(clicked()), SLOT(slotCreate()));

    ui->tbStandard->addWidget(&tbOpen);
    tbOpen.setIcon(QPixmap(":/toolbar/toolbar/document-open.png"));
    tbOpen.setText(tr("Open"));
    tbOpen.setToolButtonStyle(Qt::ToolButtonIconOnly);
    tbOpen.setToolTip(tr("Open"));
    connect(&tbOpen, SIGNAL(clicked()), SLOT(slotOpenBook()));

    ui->tbStandard->addSeparator();

    ui->tbStandard->addWidget(&tbClose);
    tbClose.setIcon(QPixmap(":/toolbar/toolbar/dialog-close.png"));
    tbClose.setText(tr("Close"));
    tbClose.setToolButtonStyle(Qt::ToolButtonIconOnly);
    tbClose.setToolTip(tr("Close"));
    connect(&tbClose, SIGNAL(clicked()), SLOT(slotClose()));

    ui->tbStandard->addWidget(&tbSave);
    tbSave.setIcon(QPixmap(":/toolbar/toolbar/document-save.png"));
    tbSave.setText(tr("Save"));
    tbSave.setToolButtonStyle(Qt::ToolButtonIconOnly);
    tbSave.setToolTip(tr("Save"));
    connect(&tbSave, SIGNAL(clicked()), SLOT(slotSave()));

    ui->tbStandard->addSeparator();

    ui->tbStandard->addWidget(&tbPrevious);
    tbPrevious.setIcon(QPixmap(":/toolbar/toolbar/previous.png"));
    tbPrevious.setText(tr("Previous page"));
    tbPrevious.setToolButtonStyle(Qt::ToolButtonIconOnly);
    tbPrevious.setToolTip(tr("Previous page"));
    connect(&tbPrevious, SIGNAL(clicked()), SLOT(slotPreviousPage()));

    ui->tbStandard->addWidget(&tbNext);
    tbNext.setIcon(QPixmap(":/toolbar/toolbar/next.png"));
    tbNext.setText(tr("Next page"));
    tbNext.setToolButtonStyle(Qt::ToolButtonIconOnly);
    tbNext.setToolTip(tr("Next page"));
    connect(&tbNext, SIGNAL(clicked()), SLOT(slotNextPage()));

    ui->tbStandard->addSeparator();

    ui->tbStandard->addWidget(&tbDeletePage);
    tbDeletePage.setIcon(QPixmap(":/toolbar/toolbar/delete.png"));
    tbDeletePage.setText(tr("Delete page"));
    tbDeletePage.setToolButtonStyle(Qt::ToolButtonIconOnly);
    tbDeletePage.setToolTip(tr("Delete page"));
    connect(&tbDeletePage, SIGNAL(clicked()), SLOT(slotDeleteCurrentPage()));

    ui->tbStandard->addWidget(&tbPastePage);
    tbPastePage.setIcon(QPixmap(":/toolbar/toolbar/paste-page.png"));
    tbPastePage.setText(tr("Paste page"));
    tbPastePage.setToolButtonStyle(Qt::ToolButtonIconOnly);
    tbPastePage.setToolTip(tr("Paste page"));
    connect(&tbPastePage, SIGNAL(clicked()), SLOT(slotInsertNewPage()));

    ui->tbStandard->addSeparator();

    ui->tbStandard->addWidget(&tbInsertImage);
    tbInsertImage.setIcon(QPixmap(":/toolbar/toolbar/insert-image.png"));
    tbInsertImage.setText(tr("Insert image"));
    tbInsertImage.setToolButtonStyle(Qt::ToolButtonIconOnly);
    tbInsertImage.setToolTip(tr("Insert image"));
    connect(&tbInsertImage, SIGNAL(clicked()), TextBook, SLOT(slotInsertImage()));

    ui->tbStandard->addSeparator();

    ui->tbStandard->addWidget(&tbExit);
    tbExit.setIcon(QPixmap(":/toolbar/toolbar/application-exit.png"));
    tbExit.setText(tr("Exit"));
    tbExit.setToolButtonStyle(Qt::ToolButtonIconOnly);
    tbExit.setToolTip(tr("Exit"));
    connect(&tbExit, SIGNAL(clicked()), SLOT(slotExitProgram()));

    ui->tbFind->addWidget(&tbFindEdit);
    tbFindEdit.setText(tr("Text for find..."));
    tbFindEdit.setMaximumWidth(150);

    ui->tbFind->addWidget(&tbFind);
    tbFind.setIcon(QPixmap(":/toolbar/toolbar/edit-find.png"));
    tbFind.setText(tr("Find"));
    tbFind.setToolButtonStyle(Qt::ToolButtonIconOnly);
    tbFind.setToolTip(tr("Find"));
    connect(&tbFind, SIGNAL(clicked()), this, SLOT(slotToolFindText()));

    ui->tbFind->addWidget(&tbFindPrevious);
    tbFindPrevious.setIcon(QPixmap(":/toolbar/toolbar/go-previous-page.png"));
    tbFindPrevious.setText(tr("Previous find"));
    tbFindPrevious.setToolButtonStyle(Qt::ToolButtonIconOnly);
    tbFindPrevious.setToolTip(tr("Previous find"));
    connect(&tbFindPrevious, SIGNAL(clicked()), TextBook,  SLOT(slotFindPrevious()));

    ui->tbFind->addWidget(&tbFindNext);
    tbFindNext.setIcon(QPixmap(":/toolbar/toolbar/go-next-page.png"));
    tbFindNext.setText(tr("Next find"));
    tbFindNext.setToolButtonStyle(Qt::ToolButtonIconOnly);
    tbFindNext.setToolTip(tr("Next find"));
    tbFindNext.setShortcut(Qt::Key_F3);
    connect(&tbFindNext, SIGNAL(clicked()), TextBook, SLOT(slotFindNext()));

    return;
}

void ICL::setVisibilityOfToolbar()
{
    if (FO->isStateStandardToolbar() == FileOptions::TOOLBAR_SHOW)
        ui->tbStandard->setVisible(FileOptions::TOOLBAR_SHOW);
    else
        ui->tbStandard->setVisible(FileOptions::TOOLBAR_HIDE);

    if (FO->isStateFindToolbar() == FileOptions::TOOLBAR_SHOW)
        ui->tbFind->setVisible(FileOptions::TOOLBAR_SHOW);
    else
        ui->tbFind->setVisible(FileOptions::TOOLBAR_HIDE);
}

void ICL::showWelcome()
{
    QMessageBox *mbWelcome;
    mbWelcome = new QMessageBox(tr("This is the first launch. You are welcome!"),
                                tr("Hello!"
                                   " Welcome to the professional electronic library \"Klen-library\"."
                                   " This is a first start the program."
                                   " Thank you for using this software and wish you a pleasant work!"),
                                QMessageBox::Information, QMessageBox::Ok, 0, 0);
    mbWelcome->exec();
    delete mbWelcome;
}

void ICL::closeEvent(QCloseEvent *event)//функция закрытия приложения
{
    slotExitProgram();
    event->ignore();//игнорировать закрытие
}

void ICL::slotOpenBook()
{
    ListBooks FormListBooks;

    if (FO->isModeWork() == FileOptions::MODE_READING)
    {
        FormListBooks.ui->AddBook->setVisible(false);
        FormListBooks.ui->DelBook->setVisible(false);
        FormListBooks.ui->bSave->setVisible(false);
        FormListBooks.ui->TableListBooks->setEditTriggers(QTableView::NoEditTriggers);
    }

    QSqlTableModel model;
    model.setTable("ListBooks");
    model.select();
    model.setEditStrategy(QSqlTableModel::OnManualSubmit);

    FormListBooks.model = &model;
    FormListBooks.ui->TableListBooks->setModel(FormListBooks.model);
    FormListBooks.iCountTable = FormListBooks.ui->TableListBooks->model()->rowCount();
    FormListBooks.ui->TableListBooks->resizeColumnsToContents();
    FormListBooks.slTableNumber = &TextBook->slTableNumber;

    QSqlQuery QueryBook;
    QSqlRecord RecordBook;
    QString strBook;
    strBook = "SELECT slTableNumber FROM slListBooks;";
    QueryBook.exec(strBook);
    RecordBook = QueryBook.record();
    TextBook->slTableNumber.clear();

    while(QueryBook.next())
    {
        TextBook->slTableNumber.append(QueryBook.value(RecordBook.indexOf("slTableNumber")).toString());
    }

    if(FormListBooks.exec() == QDialog::Accepted)
    {
        if (slotClose() == QMessageBox::Cancel) return;

        if (FormListBooks.iNumberBook != -1)
        {
            //clock_t t0 = clock();

            TextBook->setNumberBook(FormListBooks.iNumberBook);
            TextBook->FO = FO;

            if (TextBook->openBookBase(false) == 1) return;

            openBook();

            /*clock_t t1 = clock();
            double vTime;
            vTime = (double)(t1 - t0) / CLOCKS_PER_SEC;
            sTime.setNum(vTime);
            setWindowTitle(sTime);*/
        }
    }
}

int ICL::slotClose()
{
    if(TextBook->isSaved() == false && FO->isModeWork() == FileOptions::MODE_EDITING)
    {
        int inbox = messageChangeText();

        if(inbox == QMessageBox::Yes)
        {
            TextBook->save();
            TextBook->setSaved(true);
        }
        else
            if(inbox == QMessageBox::No)
            {
                TextBook->setSaved(true);
            }
            else
                if(inbox == QMessageBox::Cancel)
                {
                    return QMessageBox::Cancel;
                }
    }

    if (!TextBook->sNameBook.isEmpty()) userStat();

    lNameBook.clear();
    lPrintingHouse.clear();
    lYear.clear();
    lCountPages.clear();
    lCategory.clear();
    lSubcategory.clear();
    ui->actionClose->setEnabled(false);
    tbClose.setEnabled(false);
    ui->actionDeletePage->setEnabled(false);
    TextBook->setReadOnly(true);
    TextBook->clearVariable();
    setWindowTitle(sLibraryName + " - " + APPLICATION_NAME_VERSION);
    sbNumberPage.setValue(1);
    sbNumberPage.setEnabled(false);
    tbPrint.setEnabled(false);
    tbDeletePage.setEnabled(false);
    tbPastePage.setEnabled(false);
    tbInsertImage.setEnabled(false);
    tbNext.setEnabled(false);
    tbPrevious.setEnabled(false);
    ui->actionSave->setEnabled(false);
    tbSave.setEnabled(false);
    ui->actionExportThisBook->setEnabled(false);
    ui->menuInsert->setEnabled(false);
    ui->menuView->setEnabled(false);
    ui->menuEdit->setEnabled(false);
    ui->tbFind->setEnabled(false);
    closeMenuEditActions();

    return 0;
}




void ICL::slotSave()
{
    /*if (FileOptions->isSavePasswordBook() == true && TextBook->password().isEmpty())
        if (TextBook->setPasswordBook() == 1) return;*/

    TextBook->FO = FO;
    TextBook->save();
    ui->actionSave->setEnabled(false);
    tbSave.setEnabled(false);
}

void ICL::slotExitProgram()
{
    if (slotCloseLibrary() == QMessageBox::Cancel) return;

    FO->setSizeMainWindow(geometry());
    FO->setStateMainWindow(saveState());
    FO->write();
    exit(0);
}

void ICL::openBook()
{
    setWindowTitle(TextBook->sNameBook + " : " + sLibraryName + " - " + APPLICATION_NAME_VERSION);
    lYear.setText(QString::number(TextBook->year()));
    lCountPages.setText(" / " + QString::number(TextBook->countPages()));
    lNameBook.setText(TextBook->sNameBook);
    lSubcategory.setText(TextBook->sSubcategory);
    lCategory.setText(TextBook->sCategory);
    lPrintingHouse.setText(TextBook->sPrintingHouse);
    ui->actionSave->setEnabled(false);
    tbSave.setEnabled(false);
    ui->actionClose->setEnabled(true);
    tbClose.setEnabled(true);
    ui->actionNextPage->setEnabled(true);
    tbNext.setEnabled(true);
    ui->menuEdit->setEnabled(true);
    openMenuEditActions();
    ui->actionExportThisBook->setEnabled(true);
    tbPrint.setEnabled(true);
    ui->menuView->setEnabled(true);
    ui->tbFind->setEnabled(true);

    if(FO->isModeWork() == FileOptions::MODE_EDITING)
    {
        //ui->menuFormat->setEnabled(true);
        TextBook->setReadOnly(false);
        ui->actionDeletePage->setEnabled(true);
        tbDeletePage.setEnabled(true);
        tbPastePage.setEnabled(true);
        ui->actionInsertImage->setEnabled(true);
        tbInsertImage.setEnabled(true);
        openMenuEditActions();
        ui->menuView->setEnabled(true);
        ui->menuInsert->setEnabled(true);
    }
}

void ICL::slotNextPage()
{
    if (TextBook->nextPage() == 1) return;

    if (TextBook->currentPage() > 1)
    {
        ui->actionPreviousPage->setEnabled(true);
        tbPrevious.setEnabled(true);
    }

    if (TextBook->currentPage() == TextBook->countPages() && FO->isModeWork()
            == FileOptions::MODE_READING)
    {
        ui->actionNextPage->setEnabled(false);
        tbNext.setEnabled(false);
    }

    sbNumberPage.setValue(TextBook->currentPage());
    lCountPages.setText(" / " + QString::number(TextBook->countPages()));
}

void ICL::slotPreviousPage()
{
    if (TextBook->previousPage() == 1) return;

    if (TextBook->currentPage() == 1)
    {
        ui->actionPreviousPage->setEnabled(false);
        tbPrevious.setEnabled(false);
    }

    if (TextBook->currentPage() == TextBook->countPages() - 1)
    {
        ui->actionNextPage->setEnabled(true);
        tbNext.setEnabled(true);
    }

    sbNumberPage.setValue(TextBook->currentPage());
}

int ICL::slotModeEditing()
{
    if (FO->modeEditingPassword().isEmpty())
        if (setModePassword() == 1)
        {
            ui->actionEditing->setChecked(false);
            slotModeViewing();
            return 1;
        }

  /*  if (checkModePassword() == false)
    {
        ui->actionEditing->setChecked(false);
        slotModeViewing();
        return 1;
    }

    if (TextBook->password() != "")
    {
        QString strPassword;
        QByteArray baPassword;
        bool bOk;
        strPassword = QInputDialog::getText(0, tr("Enter password of book."), tr("Password") + ":",
                                            QLineEdit::Password, "", &bOk);
        baPassword.append(strPassword);
        baPassword = QCryptographicHash::hash(baPassword, QCryptographicHash::Sha1);

        if (baPassword == "")
        {
            QMessageBox::critical(0,tr("Error"), tr("Wrong password of book") + "!", QMessageBox::Ok);
            ui->actionEditing->setChecked(false);
            return 1;
        }

        if (baPassword != TextBook->password())
        {
            QMessageBox::critical(0,tr("Error"), tr("Wrong password of book") + "!", QMessageBox::Ok);
            ui->actionEditing->setChecked(false);
            return 1;
        }
        else
        {

            ui->actionReading->setChecked(false);
            ui->actionEditing->setChecked(true);
            slotSetModeEditing();
            return 0;
        }
    }
    else
    {*/
        ui->actionReading->setChecked(false);
        ui->actionEditing->setChecked(true);
        slotSetModeEditing();
        return 0;
    //}
}

int ICL::slotModeViewing()
{
    ui->actionEditing->setChecked(false);
    ui->actionReading->setChecked(true);
    slotSetModeViewing();
    return 0;
}

void ICL::slotSetModeViewing()
{
    ui->actionCreateLibrary->setEnabled(false);
    ui->actionOpenLibrary->setEnabled(true);
    ui->actionRestoreLibrary->setEnabled(false);
    ui->actionCloseLibrary->setEnabled(false);
    ui->actionBackupLibrary->setEnabled(false);
    ui->menuBook->setEnabled(false);
    ui->actionCreate->setEnabled(false);
    ui->actionOpen->setEnabled(false);
    ui->menuImport->setEnabled(false);
    ui->actionImportFolder->setEnabled(false);
    ui->actionClose->setEnabled(false);
    ui->actionSave->setEnabled(false);
    ui->menuExport->setEnabled(false);
    ui->actionExportAllBooks->setEnabled(false);
    ui->actionExportThisBook->setEnabled(false);
    ui->menuEdit->setEnabled(false);
    closeMenuEditActions();
    ui->menuView->setEnabled(false);
    ui->actionNextPage->setEnabled(false);
    ui->actionPreviousPage->setEnabled(false);

    TextBook->setReadOnly(true);
    tbNew.setEnabled(false);
    tbOpen.setEnabled(false);
    tbClose.setEnabled(false);
    tbSave.setEnabled(false);
    tbPrevious.setEnabled(false);
    tbNext.setEnabled(false);
    tbDeletePage.setEnabled(false);
    tbPastePage.setEnabled(false);
    tbInsertImage.setEnabled(false);
    tbPrint.setEnabled(false);
    tbSettings.setEnabled(false);
    tbFind.setEnabled(false);
    tbFindNext.setEnabled(false);
    tbFindPrevious.setEnabled(false);
    ui->tbFind->setEnabled(false);

    if(sLibraryPath != "")
    {
        ui->actionCloseLibrary->setEnabled(true);

        if(TextBook->sNameBook == "")
        {
            ui->menuBook->setEnabled(true);
            ui->actionOpen->setEnabled(true);
            ui->menuImport->setEnabled(true);
            tbOpen.setEnabled(true);
        }
        else
        {
            ui->menuBook->setEnabled(true);
            ui->actionOpen->setEnabled(true);
            ui->menuImport->setEnabled(true);
            tbOpen.setEnabled(true);
            ui->menuExport->setEnabled(true);
            ui->actionExportThisBook->setEnabled(true);
            ui->actionClose->setEnabled(true);
            tbClose.setEnabled(true);
            ui->menuEdit->setEnabled(true);
            ui->actionSelectAll->setEnabled(true);
            TextBook->actionSelectAll->setEnabled(true);
            ui->menuView->setEnabled(true);
            ui->actionFindText->setEnabled(true);
            ui->actionNextPage->setEnabled(true);
            tbNext.setEnabled(true);

            if (TextBook->currentPage() > 1)
            {
                ui->actionPreviousPage->setEnabled(true);
                tbPrevious.setEnabled(true);
            }

            ui->actionEnterNumberPage->setEnabled(true);
            ui->tbFind->setEnabled(true);
            tbPrint.setEnabled(true);
        }
    }

    lMode.setText(tr("Reading"));
    FO->setModeWork(FileOptions::MODE_READING);
}

void ICL::slotSetModeEditing()
{
    ui->actionCreateLibrary->setEnabled(true);
    ui->actionOpenLibrary->setEnabled(true);
    ui->actionRestoreLibrary->setEnabled(true);
    ui->actionCloseLibrary->setEnabled(false);
    ui->actionBackupLibrary->setEnabled(false);
    ui->menuBook->setEnabled(false);
    ui->actionCreate->setEnabled(false);
    ui->actionOpen->setEnabled(false);
    ui->menuImport->setEnabled(false);
    ui->actionClose->setEnabled(false);
    ui->actionSave->setEnabled(false);
    ui->menuExport->setEnabled(false);
    ui->actionExportAllBooks->setEnabled(false);
    ui->actionExportThisBook->setEnabled(false);
    ui->menuEdit->setEnabled(false);
    closeMenuEditActions();
    ui->menuView->setEnabled(false);
    ui->actionNextPage->setEnabled(false);
    ui->actionPreviousPage->setEnabled(false);

    TextBook->setReadOnly(true);
    tbNew.setEnabled(false);
    tbOpen.setEnabled(false);
    tbClose.setEnabled(false);
    tbSave.setEnabled(false);
    tbPrevious.setEnabled(false);
    tbNext.setEnabled(false);
    tbDeletePage.setEnabled(false);
    tbPastePage.setEnabled(false);
    tbInsertImage.setEnabled(false);
    tbPrint.setEnabled(false);
    tbSettings.setEnabled(true);
    tbFind.setEnabled(false);
    tbFindNext.setEnabled(false);
    tbFindPrevious.setEnabled(false);

    ui->tbFind->setEnabled(false);

    if(sLibraryPath != "")
    {
        ui->actionCloseLibrary->setEnabled(true);

        if(TextBook->sNameBook == "")
        {
            ui->menuBook->setEnabled(true);
            ui->actionCreate->setEnabled(true);
            ui->actionOpen->setEnabled(true);
            ui->menuImport->setEnabled(true);
            ui->actionImportFolder->setEnabled(true);
            tbNew.setEnabled(true);
            tbOpen.setEnabled(true);
            ui->actionExportAllBooks->setEnabled(true);
        }
        else
        {
            ui->menuBook->setEnabled(true);
            ui->actionCreate->setEnabled(true);
            ui->actionOpen->setEnabled(true);
            ui->menuImport->setEnabled(true);
            tbNew.setEnabled(true);
            tbOpen.setEnabled(true);
            ui->menuExport->setEnabled(true);
            ui->actionExportThisBook->setEnabled(true);
            ui->actionClose->setEnabled(true);
            tbClose.setEnabled(true);
            ui->menuEdit->setEnabled(true);
            openMenuEditActions();
            ui->menuView->setEnabled(true);
            ui->menuInsert->setEnabled(true);
            tbDeletePage.setEnabled(true);
            tbPastePage.setEnabled(true);
            tbInsertImage.setEnabled(true);
            ui->actionFindText->setEnabled(true);
            ui->actionNextPage->setEnabled(true);
            tbNext.setEnabled(true);

            if (TextBook->currentPage() > 1)
            {
                ui->actionPreviousPage->setEnabled(true);
                tbPrevious.setEnabled(true);
            }

            ui->actionEnterNumberPage->setEnabled(true);
            ui->tbFind->setEnabled(true);
            tbPrint.setEnabled(true);
        }
    }

    lMode.setText(tr("Editing"));
    FO->setModeWork(FileOptions::MODE_EDITING);
}

void ICL::slotNumberPage()
{
    if (TextBook->numberPage() == 1) return;

    if (TextBook->currentPage() == 1)
    {
        ui->actionPreviousPage->setEnabled(false);
        tbPrevious.setEnabled(false);
    }

    if(FO->isModeWork() == FileOptions::MODE_READING)
    {
        TextBook->setSaved(true);
        ui->actionSave->setEnabled(false);
    }

    sbNumberPage.setValue(TextBook->currentPage());
}

void ICL::slotTextChanged()
{
    TextBook->setSaved(false);

    if (FO->isModeWork() == FileOptions::MODE_EDITING)
    {
        ui->actionSave->setEnabled(true);
        tbSave.setEnabled(true);
    }

    if (TextBook->countPages() > 0)
    {
        sbNumberPage.setEnabled(true);
        sbNumberPage.setMaximum(TextBook->countPages());
    }
}

int ICL::messageChangeText()
{
    QMessageBox*  mbox = new QMessageBox(tr("Changing text"),
                                         tr("Text was change, save") + "?",
                                         QMessageBox::Information,
                                         QMessageBox::Yes,
                                         QMessageBox::No,
                                         QMessageBox::Cancel);
    int inbox = mbox->exec();
    delete mbox;
    return inbox;
}

bool ICL::slotOpenBookFile(QString FileNameBook)
{
    TextBook->FO = FO;

    if (TextBook->isSaved() == false)
    {
        int inbox = messageChangeText();

        if (inbox == QMessageBox::Yes)
        {
            TextBook->save();
            TextBook->setSaved(true);
            slotClose();

            if (TextBook->openBookFile(FileNameBook) == 1) return false;

            openBook();
        }
        else
            if (inbox == QMessageBox::No)
            {
                TextBook->setSaved(true);
                slotClose();

                if (TextBook->openBookFile(FileNameBook) == 1) return false;

                openBook();
            }
    }
    else
    {
        slotClose();

        if (TextBook->openBookFile(FileNameBook) == 1) return false;

        openBook();
    }

    return true;
}

void ICL::slotCreate()
{
   Create FormCreate;

    if(FormCreate.exec() == QDialog::Accepted)
    {
        TextBook->sNameBook = FormCreate.ui->leNameBook->text();
        TextBook->sSubcategory = FormCreate.ui->leSubCategory->text();
        TextBook->sCategory = FormCreate.ui->leCategory->text();
        TextBook->setYear(FormCreate.ui->sbYear->value());
        TextBook->sPrintingHouse = FormCreate.ui->lePrintingHouse->text();

        lNameBook.setText(TextBook->sNameBook);
        setWindowTitle(TextBook->sNameBook + " : " + sLibraryName + " - " + APPLICATION_NAME_VERSION);
        lSubcategory.setText(TextBook->sSubcategory);
        lCategory.setText(TextBook->sCategory);
        lPrintingHouse.setText(TextBook->sPrintingHouse);

        TextBook->sTextPage.clear();

        if(TextBook->countPages() == 0) TextBook->ListPages << tr("The first page of a new book");

        TextBook->sTextPage.append(TextBook->ListPages.at(0));
        TextBook->setCurrentPage(1);

        QString sCurrentPage;
        sCurrentPage.setNum(TextBook->currentPage());


        lCountPages.setText(" / " + QString::number(TextBook->countPages()));
        lYear.setText(QString::number(TextBook->year()));

        TextBook->setHtml(TextBook->sTextPage);

        TextBook->setSaved(false);
        tbPrint.setEnabled(true);

        ui->actionClose->setEnabled(true);
        tbClose.setEnabled(true);
        ui->actionNextPage->setEnabled(true);
        tbNext.setEnabled(true);
        tbPrevious.setEnabled(true);
        tbFont.setEnabled(true);
        ui->menuExport->setEnabled(true);
        ui->actionExportThisBook->setEnabled(true);
        tbSettings.setEnabled(true);
        ui->tbFind->setEnabled(true);
        ui->actionFindText->setEnabled(true);
        ui->menuEdit->setEnabled(true);
        openMenuEditActions();
        ui->menuInsert->setEnabled(true);
        ui->menuView->setEnabled(true);
        //ui->menuFormat->setEnabled(true);
        //ui->menuTable->setEnabled(true);
        TextBook->setReadOnly(false);
        //ui->menuTable->setEnabled(true);
        ui->actionDeletePage->setEnabled(false);
        tbPastePage.setEnabled(true);
        ui->actionInsertImage->setEnabled(true);
        tbInsertImage.setEnabled(true);
        ui->actionUndo->setEnabled(true);
        ui->actionRedo->setEnabled(true);
        tbUndo.setEnabled(true);
        tbRedo.setEnabled(true);
        ui->actionCut->setEnabled(true);
        ui->actionPaste->setEnabled(true);
        tbCut.setEnabled(true);
        tbPaste.setEnabled(true);
    }
}

bool ICL::slotOpenHTMLFile(QString sFileNameBook)
{
    if (TextBook->openHTMLFile(sFileNameBook) == 1) return false;

    sFileNameBook = sFileNameBook.remove(0, sFileNameBook.lastIndexOf("/") + 1);
    TextBook->sNameBook = sFileNameBook;
    TextBook->sPrintingHouse = QApplication::organizationName();
    TextBook->setYear(2013);
    TextBook->sTextPage.clear();

    if (TextBook->countPages() == 0) TextBook->ListPages << tr("The first page of a new book");

    TextBook->sTextPage.append(TextBook->ListPages.at(0));
    TextBook->setCurrentPage(1);
    TextBook->setHtml(TextBook->sTextPage);
    openBook();

    if (FO->isModeWork() == FileOptions::MODE_EDITING)
        TextBook->setReadOnly(false);

    return true;
}

void ICL::slotDeleteCurrentPage()
{
    TextBook->deleteCurrentPage();
    QString sNum;
    sNum.setNum(TextBook->countPages());
    lCountPages.setText(" / " + sNum);
    sbNumberPage.setValue(TextBook->currentPage());

    if (TextBook->countPages() == 1)
    {
        ui->actionDeletePage->setEnabled(false);
        tbDeletePage.setEnabled(false);
    }
}

void ICL::slotInsertNewPage()
{
    TextBook->insertNewPage();
    lCountPages.setText(" / " + QString::number(TextBook->countPages()));
    sbNumberPage.setValue(TextBook->currentPage());
    ui->actionDeletePage->setEnabled(true);
    tbDeletePage.setEnabled(true);
}

void ICL::slotPanelNumberPage()
{
    if (TextBook->currentPage() > 0) TextBook->ListPages.replace(TextBook->currentPage() - 1, TextBook->toHtml());

    TextBook->setCurrentPage(sbNumberPage.value());

    if (TextBook->currentPage() < 1 || TextBook->currentPage() > TextBook->countPages()) return;

    TextBook->sTextPage = TextBook->ListPages.at(TextBook->currentPage() - 1);
    TextBook->setHtml(TextBook->sTextPage);

    if (TextBook->currentPage() == 1)
    {
        ui->actionPreviousPage->setEnabled(false);
        tbPrevious.setEnabled(false);
    }

    if (TextBook->currentPage() > 1)
    {
        ui->actionPreviousPage->setEnabled(true);
        tbPrevious.setEnabled(true);
    }

    if (FO->isModeWork() == FileOptions::MODE_READING)
    {
        TextBook->setSaved(true);
        ui->actionSave->setEnabled(false);
    }
}

bool ICL::slotOpenEncodedPlainText(QString sFileNameBook)
{
    if (TextBook->openEncodedPlainText(sFileNameBook) == 1) return false;

    sFileNameBook = sFileNameBook.remove(0, sFileNameBook.lastIndexOf("/") + 1);
    TextBook->sNameBook = sFileNameBook;
    TextBook->sPrintingHouse = QApplication::organizationName();
    TextBook->setYear(2016);
    TextBook->sTextPage.clear();

    if (TextBook->countPages() == 0) TextBook->ListPages << tr("The first page of a new book");

    TextBook->sTextPage.append(TextBook->ListPages.at(0));
    TextBook->setCurrentPage(1);
    TextBook->setHtml(TextBook->sTextPage);
    openBook();

    if (FO->isModeWork() == FileOptions::MODE_READING)
    {
        ui->actionSave->setEnabled(false);
        tbSave.setEnabled(false);
        TextBook->setSaved(true);
    }
    else TextBook->setReadOnly(false);

    return true;
}

uchar ICL::setModePassword()
{
    QString oldPassword;
    bool bOk1;
    bool bOk2;

    oldPassword = QInputDialog::getText(0, tr("Enter a new password for a mode editing of program"),
                                        tr("Password") + ":", QLineEdit::Password, "", &bOk1);
    QByteArray baPassword;
    QByteArray baPassword1;
    baPassword.append(oldPassword);
    baPassword = QCryptographicHash::hash(baPassword, QCryptographicHash::Sha1);

    if(bOk1)
    {
        oldPassword = QInputDialog::getText(0, tr("Re-Enter a new password for a mode editing of program"),
                                            tr("Password") + ":", QLineEdit::Password, "", &bOk2);

        baPassword1.append(oldPassword);
        baPassword1 = QCryptographicHash::hash(baPassword1, QCryptographicHash::Sha1);
    }
    else return 1;

    if(bOk2 && baPassword == baPassword1)
    {
        FO->setModeEditingPassword(baPassword);
    }
    else return 1;

    return 0;
}

void ICL::slotEditModePassword()
{
    QString oldPassword;
    bool bOk1,
            bOk2,
            bOk3;

    oldPassword = QInputDialog::getText(0, tr("Enter old mode password"),
                                        tr("Password") + ":", QLineEdit::Password, "", &bOk3);

    QByteArray baPassword,
               baPassword1;
    baPassword.append(oldPassword);
    baPassword = QCryptographicHash::hash(baPassword, QCryptographicHash::Sha1);

    if(baPassword == FO->modeEditingPassword())
    {

        oldPassword = QInputDialog::getText(0, tr("Enter new mode password"),
                                             tr("Password") + ":", QLineEdit::Password, "", &bOk1);

        baPassword.clear();
        baPassword.append(oldPassword);
        baPassword = QCryptographicHash::hash(baPassword, QCryptographicHash::Sha1);

        if(bOk1)
        {
            oldPassword = QInputDialog::getText(0, tr("Re-Enter new mode password"),
                                                      tr("Password") + ":", QLineEdit::Password, "", &bOk2);

            baPassword1.append(oldPassword);
            baPassword1 = QCryptographicHash::hash(baPassword1, QCryptographicHash::Sha1);
            oldPassword.clear();

        }
        else return;

        if(bOk2 && baPassword == baPassword1) FO->setModeEditingPassword(baPassword);
        else return;
    }
    else QMessageBox::critical(0,tr("Error"), tr("Wrong old mode password") + "!", QMessageBox::Ok);
}

bool ICL::checkModePassword()
{
    QString strPassword;
    bool bOk;

    strPassword = QInputDialog::getText(0, tr("Enter mode password"),
                                        tr("Password") + ":", QLineEdit::Password, "", &bOk);

    QByteArray baPassword;
    baPassword.append(strPassword);
    baPassword = QCryptographicHash::hash(baPassword, QCryptographicHash::Sha1);

    try
    {
        if(baPassword != FO->modeEditingPassword())
        {
            throw WrongPassword();
        }
    }
    catch(WrongPassword)
    {
        QMessageBox::critical(0,tr("Error"), tr("Wrong mode password") + "!", QMessageBox::Ok);
        return false;
    }

    return true;
}

void ICL::slotShowAdditionally()
{
    QSqlQuery QueryBook;
    QSqlQuery QueryAdditional;
    QSqlRecord RecordAdditional;
    QString strBook;
    QStringList sListTypes;
    sListTypes << tr("Music") << tr("Films") << tr("Photo") << tr("Documents") << tr("Programs");

    bool ok;
    QString item = QInputDialog::getItem(this, tr("Select information type"), tr("File types:"), sListTypes, 0, false, &ok);

    if (ok && !item.isEmpty())
    {
        ListAdditionally FormListAdditionally;

        if (FO->isModeWork() == FileOptions::MODE_READING)
        {
            FormListAdditionally.ui->pbAddFile->setVisible(false);
            FormListAdditionally.ui->pbRemoveFile->setVisible(false);
        }

        strBook = "SELECT Music, Films, Photos, Documents, Programs FROM Additional;";
        QueryAdditional.exec(strBook);
        RecordAdditional = QueryAdditional.record();

        slMusic.clear();
        slFilms.clear();
        slPhotos.clear();
        slDocuments.clear();
        slPrograms.clear();

        while (QueryAdditional.next())
        {
            if (QueryAdditional.value(RecordAdditional.indexOf("Music")).toString() != "")
                slMusic << QueryAdditional.value(RecordAdditional.indexOf("Music")).toString();

            if (QueryAdditional.value(RecordAdditional.indexOf("Films")).toString() != "")
                slFilms << QueryAdditional.value(RecordAdditional.indexOf("Films")).toString();

            if (QueryAdditional.value(RecordAdditional.indexOf("Photos")).toString() != "")
                slPhotos << QueryAdditional.value(RecordAdditional.indexOf("Photos")).toString();

            if (QueryAdditional.value(RecordAdditional.indexOf("Documents")).toString() != "")
                slDocuments << QueryAdditional.value(RecordAdditional.indexOf("Documents")).toString();

            if (QueryAdditional.value(RecordAdditional.indexOf("Programs")).toString() != "")
                slPrograms << QueryAdditional.value(RecordAdditional.indexOf("Programs")).toString();

        }

        if (slMusic.count() > 0 && item == tr("Music"))
            FormListAdditionally.ui->lwAdditionally->addItems(slMusic);

        if (slFilms.count() > 0 && item == tr("Films"))
            FormListAdditionally.ui->lwAdditionally->addItems(slFilms);

        if (slPhotos.count() > 0 && item == tr("Photo"))
            FormListAdditionally.ui->lwAdditionally->addItems(slPhotos);

        if (slDocuments.count() > 0 && item == tr("Documents"))
            FormListAdditionally.ui->lwAdditionally->addItems(slDocuments);

        if (slPrograms.count() > 0 && item == tr("Programs"))
            FormListAdditionally.ui->lwAdditionally->addItems(slPrograms);

        if (FO->isModeWork() == FileOptions::MODE_EDITING)
        {
            FormListAdditionally.slMusic = slMusic;
            FormListAdditionally.slFilms = slFilms;
            FormListAdditionally.slPhotos = slPhotos;
            FormListAdditionally.slDocuments = slDocuments;
            FormListAdditionally.slPrograms = slPrograms;
            FormListAdditionally.sItem = &item;

            FormListAdditionally.setWindowFlags(Qt::Window);

            if (FormListAdditionally.exec() == QDialog::Accepted)
            {

                slMusic = FormListAdditionally.slMusic;
                slFilms = FormListAdditionally.slFilms;
                slPhotos = FormListAdditionally.slPhotos;
                slDocuments = FormListAdditionally.slDocuments;
                slPrograms = FormListAdditionally.slPrograms;

                strBook = "DROP TABLE Additional;";
                QueryBook.exec(strBook);

                strBook = "CREATE TABLE Additional (Music VARCHAR, Films VARCHAR, Photos VARCHAR, Documents VARCHAR"
                        ", Programs VARCHAR);";
                QueryBook.exec(strBook);

                for (int i = 0; i < slMusic.count(); i++)
                {
                    QueryBook.prepare("INSERT INTO Additional (Music) VALUES (?);");
                    QueryBook.bindValue(0, slMusic.at(i));
                    QueryBook.exec();
                }

                for (int i = 0; i < slFilms.count(); i++)
                {
                    QueryBook.prepare("INSERT INTO Additional (Films) VALUES (?);");
                    QueryBook.bindValue(0, slFilms.at(i));
                    QueryBook.exec();
                }

                for (int i = 0; i < slPhotos.count(); i++)
                {
                    QueryBook.prepare("INSERT INTO Additional (Photos) VALUES (?);");
                    QueryBook.bindValue(0, slPhotos.at(i));
                    QueryBook.exec();
                }

                for (int i = 0; i < slDocuments.count(); i++)
                {
                    QueryBook.prepare("INSERT INTO Additional (Documents) VALUES (?);");
                    QueryBook.bindValue(0, slDocuments.at(i));
                    QueryBook.exec();
                }

                for (int i = 0; i < slPrograms.count(); i++)
                {
                    QueryBook.prepare("INSERT INTO Additional (Programs) VALUES (?);");
                    QueryBook.bindValue(0, slPrograms.at(i));
                    QueryBook.exec();
                }
            }
        }
        else
        {
            FormListAdditionally.sItem = &item;
            FormListAdditionally.gMode = FileOptions::MODE_READING;

            if (FormListAdditionally.exec() == QDialog::Accepted)
            {

            }
        }
    }
}

void ICL::slotOpenDonate()
{
    if(FO->isLanguageProgram() == FileOptions::LANGUAGE_RUSSIAN) QDesktopServices::openUrl(QUrl("https://vk.com/artemzhil"));
    if(FO->isLanguageProgram() == FileOptions::LANGUAGE_ENGLISH) QDesktopServices::openUrl(QUrl("https://vk.com/artemzhil"));
}

void ICL::slotOpenGetSource()
{
    QDesktopServices::openUrl(QUrl("https://vk.com/artemzhil"));
}

void ICL::closeMenuEditActions()
{
    ui->actionUndo->setEnabled(false);
    ui->actionRedo->setEnabled(false);
    ui->actionSelectAll->setEnabled(false);
    ui->actionCut->setEnabled(false);
    ui->actionCopy->setEnabled(false);
    ui->actionPaste->setEnabled(false);
    tbUndo.setEnabled(false);
    tbRedo.setEnabled(false);
    tbSelectAll.setEnabled(false);
    tbCut.setEnabled(false);
    tbCopy.setEnabled(false);
    tbPaste.setEnabled(false);
    tbFont.setEnabled(false);
    TextBook->actionUndo->setEnabled(false);
    TextBook->actionRedo->setEnabled(false);
    TextBook->actionSelectAll->setEnabled(false);
    TextBook->actionCut->setEnabled(false);
    TextBook->actionCopy->setEnabled(false);
    TextBook->actionPaste->setEnabled(false);
}

void ICL::openMenuEditActions()
{
    ui->actionSelectAll->setEnabled(true);
    TextBook->actionSelectAll->setEnabled(true);
    tbSelectAll.setEnabled(true);

    if (FO->isModeWork() == FileOptions::MODE_EDITING)
    {
        tbPaste.setEnabled(true);
        ui->actionPaste->setEnabled(true);
        TextBook->actionPaste->setEnabled(true);
    }
}

void ICL::slotOpenTest()
{
    ShelkTest->start(FO->pathProgramShelkTest());
}

void ICL::userStat()
{
    QString strStat;
    QString strTimeEnd;
    strTimeEnd.append(QTime::currentTime().toString(Qt::LocalDate));
    QFile file(FO->pathStatistics());
    QTextStream sfile(&file);
    sfile.setCodec("UTF-8");

    if (!file.exists())
    {
        file.open(QIODevice::WriteOnly);
        strStat.append("<HTML>\n"
                       "  <HEAD>\n"
                       "   <META http-equiv=Content-Type content=\"text/html; charset=utf-8\">\n"
                       "  </HEAD>\n"
                       " <BODY>\n"
                       "  <TABLE border=\"1\">\n"
                       "   <TR>\n"
                       "    <TD> " + tr("User name") + " </TD>\n"
                       "    <TD> " + tr("Name of book") + " </TD>\n"
                       "    <TD> " + tr("Date") + " </TD>\n"
                       "    <TD> " + tr("Time begin") + "  </TD>\n"
                       "    <TD> " + tr("Time end") + "  </TD>\n"
                       "   </TR>\n"
                       "   <TR>\n"
                       "    <TD>" + sUserName + "</TD>\n"
                       "    <TD>" + TextBook->sNameBook + "</TD>\n"
                       "    <TD>" + QDate::currentDate().toString(Qt::LocalDate) + "</TD>\n"
                       "    <TD>" + TextBook->sTimeBegin + "</TD>\n"
                       "    <TD>" + strTimeEnd + "</TD>\n"
                       "   </TR>\n"
                       "  </TABLE>\n"
                       " </BODY>\n"
                       "</HTML>\n");
        sfile << strStat;
        file.close();

    }
    else
    {
        QFile rfile(FO->pathStatistics());
        QTextStream srfile(&rfile);
        srfile.setCodec("UTF-8");
        rfile.open(QIODevice::ReadOnly);
        strStat = srfile.readAll();
        rfile.close();
        QString strTemp;
        strTemp.clear();
        strTemp.append(strStat);
        int i = strTemp.indexOf("</TABLE>");
        strTemp.insert(i, "   <TR>\n"
                       "    <TD>" + sUserName + "</TD>\n"
                       "    <TD>" + TextBook->sNameBook + "</TD>\n"
                       "    <TD>" + QDate::currentDate().toString(Qt::LocalDate) + "</TD>\n"
                       "    <TD>" + TextBook->sTimeBegin + "</TD>\n"
                       "    <TD>" + strTimeEnd + "</TD>\n"
                       "   </TR>\n"
                       );
        strStat.clear();
        strStat.append(strTemp);
        QFile wfile(FO->pathStatistics());
        QTextStream swfile(&wfile);
        swfile.setCodec("UTF-8");
        wfile.open(QIODevice::WriteOnly);
        swfile << strStat;
        wfile.close();

    }
}

void ICL::getUserName()
{
    bool bOk;
    QString str = QInputDialog::getText(0, tr("Enter user name"), tr("User name") + ":",
                                        QLineEdit::Normal, tr("Artem"), &bOk);
    if(bOk)
    {
        sUserName = str;
        lUserName.setText(sUserName);
    }
    else
    {
        sUserName = str;
        lUserName.setText(tr("User1"));
    }
}

void ICL::slotGetSupport()
{
    if(FO->isLanguageProgram() == FileOptions::LANGUAGE_RUSSIAN) QDesktopServices::openUrl(QUrl("https://vk.com/artemzhil"));
    if(FO->isLanguageProgram() == FileOptions::LANGUAGE_ENGLISH) QDesktopServices::openUrl(QUrl("https://vk.com/artemzhil"));
}

void ICL::slotReportBug()
{
    QDesktopServices::openUrl(QUrl("https://vk.com/artemzhil"));
}

void ICL::slotCreateLibrary()
{
    sLibraryPath = QFileDialog::getSaveFileName(0, tr("Create of new catalog"), "",
                                                "XWLB - " + tr("InterectiveCatalog") + " (*.xwlb)");

    if(sLibraryPath == "") return;

    if(sLibraryPath.indexOf(".xwlb") == -1) sLibraryPath += ".xwlb";

    if (FO->isRememberLastOpened() == true) FO->setPathLastLibrary(sLibraryPath);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(sLibraryPath);
    db.setUserName("user");
    db.setHostName("host");
    db.setPassword("pas");

    if(!db.open())
    {
        QMessageBox::critical(0, tr("Detection error"), tr("Error creating library base!"));
        return;
    }

    QSqlQuery query1;
    QString str1,
            sNameLibrary;

    str1 = "CREATE TABLE slListBooks (Number INTEGER PRIMARY KEY NOT NULL,"
            " slTableNumber VARCHAR);";
    query1.exec(str1);

    str1 = "CREATE TABLE ListBooks (Number INTEGER PRIMARY KEY NOT NULL,"
            " NameBook VARCHAR, Subcategory VARCHAR, Category VARCHAR, Year INTEGER, PrintingHouse VARCHAR);";
    query1.exec(str1);

    str1 = "CREATE TABLE Additional (Music VARCHAR, Films VARCHAR, Photos VARCHAR, Documents VARCHAR, Programs VARCHAR);";
    query1.exec(str1);

    sNameLibrary.remove(0, sNameLibrary.lastIndexOf("/") + 1);
    setWindowTitle(windowTitle() + ". " + sNameLibrary);

    ui->menuBook->setEnabled(true);
    ui->actionCreate->setEnabled(true);
    ui->actionOpen->setEnabled(true);
    ui->menuImport->setEnabled(true);
    tbOpen.setEnabled(true);
    tbNew.setEnabled(true);
    ui->actionExportAllBooks->setEnabled(true);
    ui->actionCloseLibrary->setEnabled(true);
}

int ICL::slotCloseLibrary()
{
    if(slotClose() == QMessageBox::Cancel) return QMessageBox::Cancel;

    setWindowTitle(APPLICATION_NAME_VERSION);
    db.close();
    db.setDatabaseName("");
    ui->actionCloseLibrary->setEnabled(false);
    ui->menuBook->setEnabled(false);
    ui->actionBackupLibrary->setEnabled(false);
    tbNew.setEnabled(false);
    tbOpen.setEnabled(false);

    return 0;
}

void ICL::openLibrary(bool bOpen)
{
    if (db.isOpen()) slotCloseLibrary();

    if (FO->isRememberLastOpened() == true && !db.isOpen()) sLibraryPath = FO->pathLastLibrary();

    if ((FO->isRememberLastOpened() == true && bOpen == false) || FO->isRememberLastOpened() == false)
        sLibraryPath = QFileDialog::getOpenFileName(0, tr("Open library"),
                                                    "library.xwlb", "XWLB - " + tr("InteractiveCatalog") + " (*.xwlb)");

    if(sLibraryPath == "") return;

    if (FO->isRememberLastOpened() == true) FO->setPathLastLibrary(sLibraryPath);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(sLibraryPath);
    db.setUserName("user");
    db.setHostName("host");
    db.setPassword("pas");

    if(!db.open())
    {
        QMessageBox::critical(0, tr("Detection error"), tr("Error creating library base!"));
        return;
    }

    sLibraryName = sLibraryPath;
    sLibraryName.remove(0, sLibraryName.lastIndexOf("/") + 1);
    setWindowTitle(sLibraryName + " - " + APPLICATION_NAME_VERSION);

    ui->menuBook->setEnabled(true);
    ui->actionOpen->setEnabled(true);
    ui->menuImport->setEnabled(true);
    tbOpen.setEnabled(true);
    ui->menuExport->setEnabled(true);
    ui->actionCloseLibrary->setEnabled(true);

    if(FO->isModeWork() == FileOptions::MODE_EDITING)
    {
        ui->actionCreate->setEnabled(true);
        ui->actionExportAllBooks->setEnabled(true);
        ui->actionBackupLibrary->setEnabled(true);
        tbNew.setEnabled(true);
    }
}

void ICL::slotOpenLibrary()
{
    openLibrary(false);
}

void ICL::slotFontNext()
{
    QString sFontFamily,
            sText;
    sFontFamily = cbFont.currentFont().family();
    sText = TextBook->textCursor().selection().toHtml();

    if(sText.indexOf("font-family:") != -1)
    {
        int a1;
        a1 = 0;
        for(int i = 0; i < 1001; i++)
        {
            int a2;
            a1 = sText.indexOf("font-family:'", a1) + 13;
            a2 = sText.indexOf("'", a1);
            sText.remove(a1, a2 - a1);
            sText.insert(a1, sFontFamily);
            a1 = a2;

            if(sText.indexOf("font-family:'", a1) == -1)
            {

                TextBook->textCursor().removeSelectedText();
                TextBook->textCursor().insertHtml(sText);
                break;
            }
        }
    }
}

void ICL::slotBackupLibrary()
{
    QString sNameBackupLibrary = QFileDialog::getSaveFileName(0, tr("Backup library"), "",
                                                              "XWLBZ - " + tr("InteractiveCatalog") + " (*.xwlbz)");

    if(sNameBackupLibrary == "") return;
    if(sNameBackupLibrary.indexOf(".xwlbz") == -1) sNameBackupLibrary += ".xwlbz";

    QFile ifile(sLibraryPath);
    ifile.open(QIODevice::ReadOnly);
    QByteArray baExport;
    baExport = ifile.readAll();
    ifile.close();
    baExport = qCompress(baExport, 9);
    QFile ofile(sNameBackupLibrary);
    ofile.open(QIODevice::WriteOnly);
    ofile.write(baExport);
    ofile.close();
}

void ICL::slotRestoreLibrary()
{
    QString sNameBackupLibrary = QFileDialog::getOpenFileName(0, tr("Open backup"), "",
                                                              "XWLBZ - " + tr("InteractiveCatalog") + " (*.xwlbz)");

    if(sNameBackupLibrary == "") return;

    QFile ifile(sNameBackupLibrary);
    ifile.open(QIODevice::ReadOnly);
    QByteArray baImport;
    baImport = ifile.readAll();
    ifile.close();
    baImport = qUncompress(baImport);

    sNameBackupLibrary = QFileDialog::getSaveFileName(0, tr("Restore library"), "",
                                                      "XWLB - " + tr("Library of books, software of Klen-library") + " (*.xwlb)");

    if(sNameBackupLibrary.indexOf(".xwlb") == -1) sNameBackupLibrary += ".xwlb";
    if(sNameBackupLibrary == "") return;

    QFile ofile(sNameBackupLibrary);
    ofile.open(QIODevice::WriteOnly);
    ofile.write(baImport);
    ofile.close();
}

void ICL::slotUndoAvailable(bool b)
{
    if(b == true)
    {
        tbUndo.setEnabled(true);
        ui->actionUndo->setEnabled(true);
        TextBook->actionUndo->setEnabled(true);
    }
    else
    {
        tbUndo.setEnabled(false);
        ui->actionUndo->setEnabled(false);
        TextBook->actionUndo->setEnabled(false);
    }
}

void ICL::slotRedoAvailable(bool b)
{
    if(b == true)
    {
        tbRedo.setEnabled(true);
        ui->actionRedo->setEnabled(true);
        TextBook->actionRedo->setEnabled(true);
    }
    else
    {
        tbRedo.setEnabled(false);
        ui->actionRedo->setEnabled(false);
        TextBook->actionRedo->setEnabled(false);
    }
}

void ICL::slotCopyAvailable(bool b)
{
    if(b == true)
    {
        tbCopy.setEnabled(true);
        ui->actionCopy->setEnabled(true);
        tbFont.setEnabled(true);
        cbFont.setEnabled(true);
        tbUppercase.setEnabled(true);
        tbLowercase.setEnabled(true);

        if(FO->isModeWork() == FileOptions::MODE_EDITING)
        {
            tbCut.setEnabled(true);
            ui->actionCut->setEnabled(true);
            TextBook->actionCut->setEnabled(true);
        }

        TextBook->actionCopy->setEnabled(true);
    }
    else
    {
        tbCopy.setEnabled(false);
        ui->actionCopy->setEnabled(false);
        tbFont.setEnabled(false);
        cbFont.setEnabled(false);
        tbUppercase.setEnabled(false);
        tbLowercase.setEnabled(false);

        if(FO->isModeWork() == FileOptions::MODE_EDITING)
        {
            tbCut.setEnabled(false);
            ui->actionCut->setEnabled(false);
            TextBook->actionCut->setEnabled(false);
        }

        TextBook->actionCopy->setEnabled(false);
    }
}

void ICL::totbFindEdit(QString fText)
{
    tbFindEdit.setText(fText);
}

void ICL::slotToolFindText()
{
    TextBook->sFindText = tbFindEdit.text();
    TextBook->slotFindNext();
}

void ICL::slotGetModeWork()
{
    TextBook->setModeWork(FO->isModeWork());
}

void ICL::slotEnableFindButtons(QString fText)
{
    if (fText.length() > 0)
    {
        tbFind.setEnabled(true);
        tbFindNext.setEnabled(true);
        tbFindPrevious.setEnabled(true);
    }
    else
    {
        tbFind.setEnabled(false);
        tbFindNext.setEnabled(false);
        tbFindPrevious.setEnabled(false);
    }
}

void ICL::slotCheckForUpdates()
{
    wvUpdate->load(QUrl("https://vk.com/artemzhil"));
}

void ICL::slotMakeCheckUpdates(bool bError)
{
    if (bError && wvUpdate->page()->findText("new_version")) QMessageBox::information(0, tr("Information"), tr("On the official website available a new version!"));
    else QMessageBox::information(0, tr("Information"), tr("You have the latest version!"));
}

void ICL::slotBeforeExport()
{
    if (FO->isSavePasswordBook() == true && TextBook->password().isEmpty())
        if (TextBook->setPasswordBook() == 1) return;

    TextBook->FO = FO;
    TextBook->exportBook();
}

void ICL::on_actionImportFolder_triggered()
{
    QString sDirectory = QFileDialog::getExistingDirectory(0, tr(
                              "Selection directory for import electronic books"), QDir::currentPath());

    QDir dImportBooks(sDirectory);

    foreach (QString sFilename, dImportBooks.entryList(QDir::Files, QDir::NoSort)) {
        if (sFilename.indexOf(".xwb") != -1)
        {
             if (slotOpenBookFile(dImportBooks.path() + "/" + sFilename) == false) return;

            slotSave();
        }

        if (sFilename.indexOf(".html") != -1)
        {
             if (slotOpenHTMLFile(dImportBooks.path() + "/" + sFilename) == false) return;

            slotSave();
            slotClose();
        }

        if (sFilename.indexOf(".txt") != -1)
        {
             if (slotOpenEncodedPlainText(dImportBooks.path() + "/" + sFilename) == false) return;

            slotSave();
            slotClose();
        }
    }
}

void ICL::on_actionImportOneBook_triggered()
{
    QString sFileNameBook, sTemp;
    QFileDialog *DialogImportBook;
    DialogImportBook = new QFileDialog(0, tr("Import of book from the file"), tr("book1"),
                                 "XWB - " + tr("InteractitiveCatalogBook") + " (*.xwb);;" +
                                 tr("Document") + " HTML (*.html);; "
                                 + tr("Text Format") + " (*.txt)");
    DialogImportBook->setAcceptMode(QFileDialog::AcceptOpen);

    if (DialogImportBook->exec() == QFileDialog::Accepted)
    {
        sFileNameBook = DialogImportBook->selectedFiles().at(0);

        if (sFileNameBook.isEmpty()) return;

        sTemp = DialogImportBook->selectedFilter();

        if (sTemp.indexOf("*.xwb") != -1) sTemp = ".xwb";
        if (sTemp.indexOf("*.html") != -1) sTemp = ".html";
        if (sTemp.indexOf("*.txt") != -1) sTemp = ".txt";


        if (sFileNameBook.indexOf(sTemp) == -1) sFileNameBook += sTemp;
    }
    else return;

    delete DialogImportBook;

    if (sTemp == ".xwb")
    {
        slotOpenBookFile(sFileNameBook);
    }

    if (sTemp == ".html")
    {
        slotOpenHTMLFile(sFileNameBook);
    }

    if (sTemp == ".txt")
    {
        slotOpenEncodedPlainText(sFileNameBook);
    }
}
