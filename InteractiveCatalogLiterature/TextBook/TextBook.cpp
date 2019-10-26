/* ======================================================================
**  MenuText.cpp - Исходный файл модуля контекстного меню.
*/

#include "TextBook.h"

TTextBook::TTextBook(QTextEdit *pwgt /* = 0*/) : QTextEdit(pwgt),
    b_Saved(true),
    b_ModeWork(true),
    i_NumberBook(-1),
    i_Year(2013),
    i_CurrentPage(0),
    ba_Password("")
{
    MenuText = new QMenu(this);
    actionUndo = new QAction(QPixmap(":/toolbar/toolbar/undo.png"), tr("Undo"),this);
    actionUndo->setShortcut(Qt::CTRL + Qt::Key_Z);
    connect(actionUndo, SIGNAL(triggered()), this, SLOT(undo()));
    actionRedo = new QAction(QPixmap(":/toolbar/toolbar/redo.png"), tr("Redo"),this);
    actionRedo->setShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_Z);
    connect(actionRedo, SIGNAL(triggered()), this, SLOT(redo()));
    actionSelectAll = new QAction(QPixmap(":/toolbar/toolbar/select-all.png"), tr("Select all"),this);
    actionSelectAll->setShortcut(Qt::CTRL + Qt::Key_A);
    connect(actionSelectAll, SIGNAL(triggered()), this, SLOT(selectAll()));
    actionCut = new QAction(QPixmap(":/toolbar/toolbar/cut.png"), tr("Cut"),this);
    actionCut->setShortcut(Qt::CTRL + Qt::Key_X);
    connect(actionCut, SIGNAL(triggered()), this, SLOT(cut()));
    actionCopy = new QAction(QPixmap(":/toolbar/toolbar/copy.png"), tr("Copy"),this);
    actionCopy->setShortcut(Qt::CTRL + Qt::Key_C);
    connect(actionCopy, SIGNAL(triggered()), this, SLOT(copy()));
    actionPaste = new QAction(QPixmap(":/toolbar/toolbar/paste.png"), tr("Paste"),this);
    actionPaste->setShortcut(Qt::CTRL + Qt::Key_V);
    connect(actionPaste, SIGNAL(triggered()), this, SLOT(paste()));
    MenuText->addAction(actionUndo);
    MenuText->addAction(actionRedo);
    MenuText->addSeparator();
    MenuText->addAction(actionSelectAll);
    MenuText->addSeparator();
    MenuText->addAction(actionCut);
    MenuText->addAction(actionCopy);
    MenuText->addAction(actionPaste);
}

/*virtual*/ void TTextBook::contextMenuEvent(QContextMenuEvent *event)
{
    MenuText->exec(event->globalPos());
}

TTextBook::~TTextBook()
{
    delete MenuText;
    delete actionUndo;
    delete actionRedo;
    delete actionSelectAll;
    delete actionCut;
    delete actionCopy;
    delete actionPaste;
}

bool TTextBook::isSaved() const
{
    return b_Saved;
}

void TTextBook::setSaved(bool bSaved)
{
    b_Saved = bSaved;
}

int TTextBook::countPages() const
{
    return ListPages.count();
}

int TTextBook::numberBook() const
{
    return i_NumberBook;
}

void TTextBook::setNumberBook(int iNumberBook)
{
    i_NumberBook = iNumberBook;
}

int TTextBook::year() const
{
    return i_Year;
}

void TTextBook::setYear(int iYear)
{
    i_Year = iYear;
}

int TTextBook::currentPage() const
{
    return i_CurrentPage;
}

void TTextBook::setCurrentPage(int iCurrentPage)
{
    i_CurrentPage = iCurrentPage;
}

int TTextBook::isModeWork() const
{
    return b_ModeWork;
}

void TTextBook::setModeWork(bool bModeWork)
{
    b_ModeWork = bModeWork;
}

QByteArray TTextBook::password() const
{
    return ba_Password;
}

void TTextBook::setPassword(QByteArray baPassword)
{
    ba_Password = baPassword;
}

void TTextBook::slotJustifyLeft()
{
    setAlignment(Qt::AlignLeft);
}

void TTextBook::slotJustifyCenter()
{
    setAlignment(Qt::AlignHCenter);
}

void TTextBook::slotJustifyRight()
{
    setAlignment(Qt::AlignRight);
}

void TTextBook::slotJustifyFill()
{
    setAlignment(Qt::AlignJustify);
}

void TTextBook::slotUppercase()
{
    QString sText;
    sText = textCursor().selection().toHtml();
    sText = sText.toUpper();
    textCursor().removeSelectedText();
    textCursor().insertHtml(sText);
}

void TTextBook::slotLowercase()
{
    QString sText;
    sText = textCursor().selection().toHtml();
    sText = sText.toLower();
    textCursor().removeSelectedText();
    textCursor().insertHtml(sText);
}

void TTextBook::slotPrint()
{
    QPrinter printer;
    QPrintDialog *pPrintDialog = new QPrintDialog(&printer);
    QTextDocument *textDoc = new QTextDocument;
    QString sPrint;

    if(pPrintDialog->exec() == QDialog::Accepted)
    {
        sPrint = makeOneHTML();

        QImage textImage;

        for (int i = 0; i < ListImages.count(); i++)
        {
            textImage.loadFromData(ListImages.at(i));
            textDoc->addResource(QTextDocument::ImageResource, QUrl(slNumberImages.at(i)), textImage);
        }

        textDoc->setHtml(sPrint);
        textDoc->print(&printer);
    }

    delete textDoc;
    delete pPrintDialog;
}

/*void TTextBook::slotInsertTable()
{
    TInputParametrTable *FormInputParametrTable = new TInputParametrTable;

    if(FormInputParametrTable->exec() == QDialog::Accepted)
    {
        if(FormInputParametrTable->ui->SpinRowCount->value() > 0
                && FormInputParametrTable->ui->SpinColumnCount->value() > 0)
        {
            textCursor().insertTable(FormInputParametrTable->ui->SpinRowCount->value(),
                                     FormInputParametrTable->ui->SpinColumnCount->value());
        }
    }

    delete FormInputParametrTable;
}*/

void TTextBook::clearVariable()
{
    setCurrentPage(0);
    setNumberBook(-1);
    clear();
    setSaved(true);
    sTextPage.clear();
    ListPages.clear();
    ListImages.clear();
    sNameBook.clear();
    setYear(0);
    sPrintingHouse.clear();
    sTimeBegin.clear();
    setPassword("");
    slNumberImages.clear();
}

/*void TTextBook::slotResizeTable()
{
    TInputParametrTable *FormInputParametrTable = new TInputParametrTable;
    FormInputParametrTable->setWindowTitle(tr("Change table parametrs"));

    if(FormInputParametrTable->exec() == QDialog::Accepted)
    {
        if(FormInputParametrTable->ui->SpinColumnCount->value() > 0
                && FormInputParametrTable->ui->SpinColumnCount->value() > 0)
        {
            textCursor().currentTable()->resize(FormInputParametrTable->ui->SpinRowCount->value(),
                                                FormInputParametrTable->ui->SpinColumnCount->value());
        }
    }

    delete FormInputParametrTable;
}*/

void TTextBook::slotFindText()
{
    bool ok;
    QString item;

    if(sFindText != "")
        item = QInputDialog::getText(this, tr("Find text"), tr("Input text:"), QLineEdit::Normal, sFindText, &ok);
    else
        item = QInputDialog::getText(this, tr("Find text"), tr("Input text:"), QLineEdit::Normal, tr("Text for find..."), &ok);

    if(!ok) return;

    sFindText = item;

    emit totbFindEdit(sFindText);

    while((currentPage() < countPages())&&(!find(sFindText)))
    {
        emit NextPage();
    }
}

void TTextBook::slotFindNext()
{
    if(sFindText == "") return;

    while((currentPage() < countPages())&&(!find(sFindText)))
    {
        emit NextPage();
    }
}

void TTextBook::slotFindPrevious()
{
    if(sFindText == "") return;

    while(currentPage() > 1)
    {
lFind:
        if(find(sFindText, QTextDocument::FindBackward) == false)
        {
            emit PreviousPage();

            while(find(sFindText) == true)
            {
                //find(sFindText);
            };

            //find(sFindText, QTextDocument::FindBackward);

            if(currentPage() == 1) break;

            goto lFind;
        }
        else break;
    }
}

void TTextBook::exportBook()
{
    QString sFileNameBook, sTemp;
    QFileDialog *DialogExportBook;
    DialogExportBook = new QFileDialog(0, tr("Export of book into the file"), tr("book1"),
                                 "XWB - " + tr("Format books program of Klen-library") + " (*.xwb);;"
                                 "PDF - Portable Document Format (*.pdf);;"
                                 "PS - PostScript Files (*.ps);;"
                                 "Rich Text Format (*.rtf);;"
                                 + tr("Document") + " HTML (*.html);;"
                                 + tr("Text Format") + " (*.txt)");

    DialogExportBook->setAcceptMode(QFileDialog::AcceptSave);

    if(DialogExportBook->exec() == QFileDialog::Accepted)
    {
        sFileNameBook = DialogExportBook->selectedFiles().at(0);

        if (sFileNameBook.isEmpty()) return;

        sTemp = DialogExportBook->selectedFilter();

        if(sTemp.indexOf("*.xwb") != -1) sTemp = ".xwb";
        if(sTemp.indexOf("*.html") != -1) sTemp = ".html";
        if(sTemp.indexOf("*.txt") != -1) sTemp = ".txt";
        if(sTemp.indexOf("*.rtf") != -1) sTemp = ".rtf";
        if(sTemp.indexOf("*.pdf") != -1) sTemp = ".pdf";
        if(sTemp.indexOf("*.ps") != -1) sTemp = ".ps";


        if(sFileNameBook.indexOf(sTemp) == -1) sFileNameBook += sTemp;
    }
    else return;

    delete DialogExportBook;

    if(sTemp == ".xwb")
    {
        saveToFile(sFileNameBook);
    }

    if(sTemp == ".html")
    {
        saveToHTMLFile(sFileNameBook);
    }

    if(sTemp == ".txt")
    {
        saveToEncodedPlainText(sFileNameBook);
    }

    if(sTemp == ".rtf")
    {
        saveToRTF(sFileNameBook);
    }

    if(sTemp == ".pdf")
    {
        saveToPortable(sFileNameBook, "PDF");
    }

    if(sTemp == ".ps")
    {
        saveToPortable(sFileNameBook, "PS");
    }
}

void TTextBook::saveToFile(QString FileNameBook)
{
    sTextPage = toHtml();
    ListPages.replace(currentPage() - 1, sTextPage);

    QFile ifile(FileNameBook);
    QDataStream istream(&ifile);

    if(FO->isSavePasswordBook() == true) ListImages.append(password());

    ifile.open(QIODevice::WriteOnly);

    istream << QCoreApplication::applicationVersion();
    istream << sNameBook;
    istream << sPrintingHouse;
    istream << QString::number(year());
    istream << ListPages;
    istream << slNumberImages;

    QString sHTML;
    QString stemp;
    int iCountDelete;

    sHTML.append(ListPages.at(0));
    sHTML.truncate(sHTML.indexOf("</body>"));

    for(int i = 1; i < ListPages.count() - 1; i++)
    {
        iCountDelete = 0;
        stemp.clear();
        stemp.append(ListPages.at(i));
        iCountDelete = stemp.indexOf(">", stemp.indexOf("<body"));
        stemp.remove(0, iCountDelete + 1);
        stemp.truncate(stemp.indexOf("</body>"));
        sHTML.append(stemp);
    }

    iCountDelete = 0;
    stemp.clear();
    stemp.append(ListPages.at(ListPages.count() - 1));
    iCountDelete = stemp.indexOf(">", stemp.indexOf("<body"));
    stemp.remove(0, iCountDelete + 1);
    sHTML.append(stemp);

    int j = 0;

    while (j < slNumberImages.count())
    {
        if (sHTML.indexOf(slNumberImages.at(j)) == -1)
        {
            slNumberImages.removeAt(j);
            ListImages.remove(j);
            j = 0;
        }

        j++;
    }

    for(int i = 0; i < ListImages.count(); i++)
        if(ListImages.at(i).count() != 0) istream << ListImages.at(i);
    else break;

    ifile.close();
    ifile.open(QIODevice::ReadOnly);
    QByteArray baExport;
    baExport = ifile.readAll();
    ifile.close();
    baExport = baExport.toBase64();
    baExport = qCompress(baExport, 9);
    ifile.open(QIODevice::WriteOnly);
    ifile.write(baExport);
    ifile.close();

    if(FO->isSavePasswordBook() == true) ListImages.remove(ListImages.count() - 1);
}

void TTextBook::saveToHTMLFile(QString FileNameBook)
{
    QString sHTML;
    QString soFileNameBook;
    QString sOutputDir;
    QString sFileNumber;

    sHTML = makeOneHTML();
    soFileNameBook = FileNameBook;
    soFileNameBook.replace(".html", "");
    soFileNameBook.remove(0, soFileNameBook.lastIndexOf("/") + 1);

    QDir odir;

    sOutputDir = FileNameBook;
    sOutputDir.truncate(sOutputDir.lastIndexOf("/"));
    odir.setPath(sOutputDir);
    odir.mkdir(soFileNameBook);
    odir.cd(soFileNameBook);

    QImage oImage;

    for (int i = 0; i < slNumberImages.count(); i++)
    {
        sHTML.replace("<img src=\"" + slNumberImages.at(i) + "\"" , "<img src=\"" + soFileNameBook + "/" + sFileNumber + QString::number(i) + ".png\"");
        oImage.loadFromData(ListImages.at(i));
        oImage.save(sOutputDir + "/" + soFileNameBook + "/" + QString::number(i) + ".png", "PNG", 0);
    }

    sHTML.replace("</head>", "<META http-equiv=Content-Type content=\"text/html; charset=utf-8\">\n</head>");
    QFile ofile(FileNameBook);
    QTextStream txtstream(&ofile);
    txtstream.setCodec("UTF-8");

    ofile.open(QIODevice::WriteOnly);
    txtstream << sHTML;
    ofile.close();
}

void TTextBook::saveToEncodedPlainText(QString FileNameBook)
{
    QString sTXT;
    QFile ifile(FileNameBook);
    QTextStream idata(&ifile);
    idata.setCodec("UTF-8");
    ifile.open(QIODevice::WriteOnly);

    QTextDocument *textDoc = new QTextDocument;

    for(int i = 0; i < ListPages.count(); i++)
    {
        textDoc->setHtml(ListPages.at(i));
        sTXT.append(textDoc->toPlainText());
    }

    delete textDoc;
    idata << sTXT;
    ifile.close();
    setHtml(sTextPage);
    setSaved(true);
}

void TTextBook::slotExportAllBooks()
{
    emit slotClose();
    QString sFolder;
    QString sFilter;
    QFileDialog *DialogExportBook;
    DialogExportBook = new QFileDialog(0, tr("Export all of book into the files"), "",
                                 "XWB - " + tr("Format books program of Klen-library") + " (*.xwb);;"
                                 "PDF - Portable Document Format (*.pdf);;"
                                 "PS - PostScript Files (*.ps);;"
                                 "Rich Text Format (*.rtf);;"
                                 + tr("Document") + " HTML (*.html);; "
                                 + tr("Text Format") + " (*.txt)");
    DialogExportBook->setAcceptMode(QFileDialog::AcceptSave);

    if(DialogExportBook->exec() == QFileDialog::Accepted)
    {
        sFolder = DialogExportBook->directory().path();

        if (sFolder.isEmpty()) return;

        sFilter = DialogExportBook->selectedFilter();

        if(sFilter.indexOf("*.xwb") != -1) sFilter = ".xwb";
        if(sFilter.indexOf("*.html") != -1) sFilter = ".html";
        if(sFilter.indexOf("*.txt") != -1) sFilter = ".txt";
        if(sFilter.indexOf("*.rtf") != -1) sFilter = ".rtf";
        if(sFilter.indexOf("*.pdf") != -1) sFilter = ".pdf";
        if(sFilter.indexOf("*.ps") != -1) sFilter = ".ps";
    }
    else return;

    delete DialogExportBook;

    QSqlTableModel model;
    model.setTable("ListBooks");
    model.select();

    QProgressDialog *DialogExportAllBook = new QProgressDialog(tr("Exporting..."), tr("Cancel"), 0,
                                                            model.rowCount());
    DialogExportAllBook->setMinimumDuration(0);
    DialogExportAllBook->setWindowTitle(tr("Please wait"));

    for(int i = 0; i < model.rowCount(); i++)
    {
        if (i > DialogExportAllBook->value()) DialogExportAllBook->setValue(i);

        setNumberBook(i);
        QSqlQuery QueryBook;
        QSqlRecord RecordBook;
        QString strBook;
        strBook = "SELECT slTableNumber FROM slListBooks;";
        QueryBook.exec(strBook);
        RecordBook = QueryBook.record();
        slTableNumber.clear();

        while(QueryBook.next())
        {
            slTableNumber.append(QueryBook.value(RecordBook.indexOf("slTableNumber")).toString());
        }

        openBookBase(true);

        if (sFilter == ".xwb") saveToFile(sFolder + "/book" + QString::number(i) + sFilter);
        if (sFilter == ".html") saveToHTMLFile(sFolder + "/book" + QString::number(i) + sFilter);
        if (sFilter == ".txt") saveToEncodedPlainText(sFolder + "/book" + QString::number(i) + sFilter);
        if (sFilter == ".pdf") saveToPortable(sFolder + "/book" + QString::number(i) + sFilter, "PDF");
        if (sFilter == ".ps") saveToPortable(sFolder + "/book" + QString::number(i) + sFilter, "PS");
        if (sFilter == ".rtf") saveToRTF(sFolder + "/book" + QString::number(i) + sFilter);

        emit slotClose();

        //QApplication::processEvents();

        if (DialogExportAllBook->wasCanceled()) break;
    }

    delete DialogExportAllBook;
}

uchar TTextBook::openBookBase(bool bExport)
{
    QSqlQuery QueryBook;
    QSqlRecord RecordBook;
    QString strBook;
    strBook = "SELECT NameBook, Subcategory, Category, Year, PrintingHouse FROM ListBooks;";
    QueryBook.exec(strBook);
    RecordBook = QueryBook.record();

    for (int i = 0; i <= numberBook(); i++)
    {
        QueryBook.next();

        if (i == numberBook())
        {
            sNameBook = QueryBook.value(RecordBook.indexOf("NameBook")).toString();
            sSubcategory = QueryBook.value(RecordBook.indexOf("Subcategory")).toString();
            sCategory = QueryBook.value(RecordBook.indexOf("Category")).toString();
            sPrintingHouse = QueryBook.value(RecordBook.indexOf("PrintingHouse")).toString();
            setYear(QueryBook.value(RecordBook.indexOf("Year")).toInt());
        }
    }

    QString sNumBook;

    if (slTableNumber.count() > 0 && slTableNumber.count() > numberBook()) sNumBook = slTableNumber.at(numberBook());

    strBook = "SELECT Pages, Images, NumberImages FROM Table" + sNumBook + ";";
    QueryBook.exec(strBook);

    if (QueryBook.record().count() == 0)
    {
        strBook = "SELECT Pages, Images FROM Table" + sNumBook + ";";
        QueryBook.exec(strBook);
    }

    RecordBook = QueryBook.record();

    while (QueryBook.next())
    {
        if (QueryBook.value(RecordBook.indexOf("Pages")).toString() != "")
            ListPages.append(QueryBook.value(RecordBook.indexOf("Pages")).toString());

        if (!QueryBook.value(RecordBook.indexOf("Images")).toByteArray().isEmpty())
            ListImages.append(QueryBook.value(RecordBook.indexOf("Images")).toByteArray());

        if (QueryBook.value(RecordBook.indexOf("NumberImages")).toString() != "")
            slNumberImages.append(QueryBook.value(RecordBook.indexOf("NumberImages")).toString());
    }

    if (ListImages.count() > 0 && ListImages.at(ListImages.count() - 1).count() <= 1024)
    {
        setPassword(ListImages.at(ListImages.count() - 1));
        ListImages.remove(ListImages.count() - 1);
    }

    emit getModeWork();

    if (!password().isEmpty() && isModeWork() == FileOptions::MODE_EDITING && bExport == false)
    {
        QString strPassword;
        QByteArray baPassword;
        bool bOk;
        strPassword = QInputDialog::getText(0, tr("Enter password of book"), tr("Password") + ":",
                                            QLineEdit::Password, "", &bOk);
        baPassword.append(strPassword);
        baPassword = QCryptographicHash::hash(baPassword, QCryptographicHash::Sha1);

        if(baPassword == "")
        {
            QMessageBox::critical(0,tr("Error"), tr("Wrong password of book") + "!", QMessageBox::Ok);
            emit slotClose();
            return 1;
        }

        if(baPassword != password())
        {
            QMessageBox::critical(0,tr("Error"), tr("Wrong password of book") + "!", QMessageBox::Ok);
            emit slotClose();
            return 1;
        }
    }

    if (!slNumberImages.isEmpty())
    {
        QImage textImage;

        for (int i = 0; i < ListImages.count(); i++)
        {
            textImage.loadFromData(ListImages.at(i));
            document()->addResource(QTextDocument::ImageResource, QUrl(slNumberImages.at(i)), textImage);
        }
    }

    QFile ifile;

    ifile.close();
    sTextPage.clear();

    if (ListPages.count() == 0) ListPages.append(tr("The first page of a new book"));

    sTextPage.append(ListPages.at(0));
    setCurrentPage(1);

    QString sCurrentPage;
    sCurrentPage.setNum(currentPage());

    setHtml(sTextPage);

    //Время начала
    sTimeBegin.append(QTime::currentTime().toString(Qt::LocalDate));
    setSaved(true);
    return 0;
}

void TTextBook::save()
{
    sTextPage = toHtml();
    ListPages.replace(currentPage() - 1, sTextPage);

    if (numberBook() == -1)
    {
        QSqlQuery query1;
        QString str1;

        str1 = "CREATE TABLE slListBooks (Number INTEGER PRIMARY KEY NOT NULL, slTableNumber VARCHAR);";
        query1.exec(str1);

        str1 = "CREATE TABLE ListBooks (Number INTEGER PRIMARY KEY NOT NULL,"
               " NameBook VARCHAR, Subcategory VARCHAR, Category VARCHAR, Year INTEGER, PrintingHouse VARCHAR);";
        query1.exec(str1);

        str1 = "CREATE TABLE Additional (Music VARCHAR, Films VARCHAR, Photos VARCHAR, Documents VARCHAR, Programs VARCHAR);";
        query1.exec(str1);

        QString str3Query;
        QSqlQuery QueryBook2;
        str3Query = "INSERT INTO ListBooks (NameBook, Subcategory, Category, Year, PrintingHouse)"
                    "VALUES ('" + sNameBook + "', '" + sSubcategory + "', '" + sCategory + "', "
                    + QString::number(year()) + ", '" + sPrintingHouse + "');";

        QueryBook2.exec(str3Query);

        QSqlTableModel model3;
        model3.setTable("ListBooks");
        model3.select();

        setNumberBook(model3.rowCount() - 1);
    }

    QSqlQuery QueryBook;
    QSqlRecord RecordBook;
    QString strBook;

    strBook = "SELECT slTableNumber FROM slListBooks;";
    QueryBook.exec(strBook);
    RecordBook = QueryBook.record();
    slTableNumber.clear();

    while (QueryBook.next())
    {
        slTableNumber.append(QueryBook.value(RecordBook.indexOf("slTableNumber")).toString());
    }

    strBook.clear();

    if (slTableNumber.count() > numberBook())
    {
        bool *bOk;
        bOk = false;
        strBook = slTableNumber.at(numberBook());
        setNumberBook(strBook.toInt(bOk, 10));
        strBook.clear();
    }
    else
    {
        srand(QTime::currentTime().msec());
        setNumberBook(rand() % 10000000);

        while ((slTableNumber.indexOf(QString::number(numberBook())) != -1))
        {
            srand(QTime::currentTime().msec());
            setNumberBook(rand() % 10000000);
        }

        slTableNumber.append(QString::number(numberBook()));
    }

    strBook = "DROP TABLE Table" + QString::number(numberBook()) + ";";
    QueryBook.exec(strBook);
    strBook = "CREATE TABLE Table" + QString::number(numberBook()) + " (Pages VARCHAR, Images BLOB, NumberImages VARCHAR);";
    QueryBook.exec(strBook);

    //Удаление пустых страниц
    for (int i = 0; i < ListPages.count(); i++)
        ListPages.removeAt(ListPages.indexOf(""));

    if (ListPages.count() != 0)
        for(int i = 0; i < ListPages.count(); i++)
        {
        QueryBook.prepare("INSERT INTO Table" + QString::number(numberBook()) + " (Pages) VALUES (?);");
        QueryBook.bindValue(0, ListPages.at(i));
        QueryBook.exec(/*strBook*/);
    }

    if (FO->isSavePasswordBook() == true) ListImages.append(password());

    QString sHTML;
    //Вся книга представляется в виде одной HTML-страницы
    sHTML = makeOneHTML();
    int j = 0;

    while (j < slNumberImages.count())
    {
//Если в этой html-странице не будет найдено изображение из списка изображений
        if (sHTML.indexOf(slNumberImages.at(j)) == -1)
        {
            //то удалить номер этого изображения
            slNumberImages.removeAt(j);
            //и удалить само изображение
            ListImages.remove(j);
            j = 0;
        }

        j++;
    }

    for (int i = 0; i < ListImages.count(); i++)
    {

        if (ListImages.at(i).count() != 0)
        {
            QueryBook.prepare("INSERT INTO Table" + QString::number(numberBook()) + " (Images) VALUES (?);");
            QueryBook.bindValue(0, ListImages.at(i));
            QueryBook.exec(/*strBook*/);
        }
        else break;
    }

    strBook = "DROP TABLE slListBooks;";
    QueryBook.exec(strBook);
    strBook = "CREATE TABLE slListBooks (slTableNumber VARCHAR);";
    QueryBook.exec(strBook);

    for (int i = 0; i < slTableNumber.count(); i++)
    {

        QueryBook.prepare("INSERT INTO slListBooks (slTableNumber) VALUES (?);");
        QueryBook.bindValue(0, slTableNumber.at(i));
        QueryBook.exec(/*strBook*/);

    }

    if (slNumberImages.count() != 0)
        for (int i = 0; i < slNumberImages.count(); i++)
        {
        QueryBook.prepare("INSERT INTO Table" + QString::number(numberBook()) + " (NumberImages) VALUES (?);");
        QueryBook.bindValue(0, slNumberImages.at(i));
        QueryBook.exec(/*strBook*/);
    }

    setSaved(true);

    if (FO->isSavePasswordBook() == true) ListImages.remove(ListImages.count() - 1);
}

uchar TTextBook::slotEditPasswordBook()
{
    if (password().isEmpty())
    {
        setPasswordBook();
        return 0;
    }

    QString sOldPassword;
    bool bOk1;
    bool bOk2;
    bool bOk3;

    sOldPassword = QInputDialog::getText(0, tr("Enter old book password"),
                                        tr("Password") + ":", QLineEdit::Password, "", &bOk3);

    QByteArray baPassword;
    QByteArray baPassword1;
    baPassword.append(sOldPassword);
    baPassword = QCryptographicHash::hash(baPassword, QCryptographicHash::Sha1);

    if(baPassword == password())
    {
        sOldPassword = QInputDialog::getText(0, tr("Enter new book password"),
                                             tr("Password") + ":", QLineEdit::Password, "", &bOk1);

        baPassword.clear();
        baPassword.append(sOldPassword);
        baPassword = QCryptographicHash::hash(baPassword, QCryptographicHash::Sha1);

        if(bOk1)
        {
            sOldPassword = QInputDialog::getText(0, tr("Re-Enter new book password"),
                                                      tr("Password") + ":", QLineEdit::Password, "", &bOk2);

            baPassword1.append(sOldPassword);
            baPassword1 = QCryptographicHash::hash(baPassword1, QCryptographicHash::Sha1);
            sOldPassword.clear();

        }
        else return 1;

        if(bOk2 && baPassword == baPassword1)
        {
            setPassword(baPassword);
            setSaved(false);
        }
        else return 1;
    }
    else
    {
        QMessageBox::critical(0,tr("Error"), tr("Wrong old book password") + "!", QMessageBox::Ok);
        return 1;
    }

    return 0;
}

uchar TTextBook::setPasswordBook()
{
    QString sOldPassword;
    bool bOk1;
    bool bOk2;

    sOldPassword = QInputDialog::getText(0, tr("Enter a new password of book"),
                                        tr("Password") + ":", QLineEdit::Password, "", &bOk1);
    QByteArray baPassword;
    QByteArray baPassword1;
    baPassword.append(sOldPassword);
    baPassword = QCryptographicHash::hash(baPassword, QCryptographicHash::Sha1);

    if(bOk1)
    {
        sOldPassword = QInputDialog::getText(0, tr("Re-Enter a new password of book"),
                                            tr("Password") + ":", QLineEdit::Password, "", &bOk2);

        baPassword1.append(sOldPassword);
        baPassword1 = QCryptographicHash::hash(baPassword1, QCryptographicHash::Sha1);
    }
    else return 1;

    if(bOk2 && baPassword == baPassword1)
    {
        setPassword(baPassword);
        setSaved(false);
    }
    else return 1;

    return 0;
}

bool TTextBook::checkPasswordBook()
{
    QString strPassword;
    bool bOk;

    strPassword = QInputDialog::getText(0, tr("Enter book password"),
                                        tr("Password") + ":", QLineEdit::Password, "", &bOk);

    QByteArray baPassword;
    baPassword.append(strPassword);
    baPassword = QCryptographicHash::hash(baPassword, QCryptographicHash::Sha1);

    try
    {
        if(baPassword != password())
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

QString TTextBook::makeOneHTML()
{
    QString sHTML;
    QString stemp;
    sHTML.clear();
    int iCountDelete = 0;

    sHTML.append(ListPages.at(0));
    sHTML.truncate(sHTML.indexOf("</body>"));

    for(int i = 1; i < ListPages.count() - 1; i++)
    {
        iCountDelete = 0;
        stemp.clear();
        stemp.append(ListPages.at(i));
        iCountDelete = stemp.indexOf(">", stemp.indexOf("<body"));
        stemp.remove(0, iCountDelete + 1);
        stemp.truncate(stemp.indexOf("</body>"));
        sHTML.append(stemp);
    }

    iCountDelete = 0;
    stemp.clear();
    stemp.append(ListPages.at(ListPages.count() - 1));
    iCountDelete = stemp.indexOf(">", stemp.indexOf("<body"));
    stemp.remove(0, iCountDelete + 1);
    sHTML.append(stemp);
    return sHTML;
}

uchar TTextBook::openBookFile(QString FileNameBook)
{
    QString sYear;
    bool bOk;
    QFile ifile(FileNameBook);
    ifile.open(QIODevice::ReadOnly);
    QByteArray baImport;
    baImport = ifile.readAll();
    ifile.close();
    baImport = qUncompress(baImport);
    baImport = QByteArray::fromBase64(baImport);

    QTemporaryFile *tfBook = new QTemporaryFile;
    tfBook->open();
    tfBook->write(baImport);
    baImport.clear();
    ifile.setFileName(tfBook->fileName());
    QDataStream istream(&ifile);
    ifile.open(QIODevice::ReadOnly);
    QString sappVersion;

    try
    {
        istream >> sappVersion;

        if (sappVersion != "1.0.0") throw WrongFileFormat();
    }
    catch(WrongFileFormat)
    {
        QMessageBox::warning(0, tr("Detection warning"), tr("Wrong file format!"));
        emit slotClose();
        return 1;
    }
    catch(...)
    {
        QMessageBox::critical(0, tr("Detection error"), tr("An unknown error occurred!"));
        emit slotClose();
        return 1;
    }

    istream >> sNameBook;
    istream >> sPrintingHouse;
    istream >> sYear;
    setYear(sYear.toInt(&bOk, 10));
    istream >> ListPages;
    istream >> slNumberImages;

    while(!ifile.atEnd())
    {
        istream  >> baImport;
        ListImages.append(baImport);
    }

    ifile.close();
    tfBook->close();
    delete tfBook;

    if (ListImages.count() > 0 && ListImages.at(ListImages.count() - 1).count() <= 1024)
    {
        setPassword(ListImages.at(ListImages.count() - 1));
        ListImages.remove(ListImages.count() - 1);
    }

    emit getModeWork();

    if(!password().isEmpty() == true && isModeWork() == FileOptions::MODE_EDITING)
    {
        QString strPassword;
        QByteArray baPassword;
        bool bOk;
        strPassword = QInputDialog::getText(0, tr("Enter password of book"), tr("Password") + ":",
                                            QLineEdit::Password, "", &bOk);
        baPassword.append(strPassword);
        baPassword = QCryptographicHash::hash(baPassword, QCryptographicHash::Sha1);

        if (baPassword == "")
        {
            QMessageBox::critical(0,tr("Error"), tr("Wrong password of book") + "!", QMessageBox::Ok);
            emit slotClose();
            return 1;
        }

        if (baPassword != password())
        {
            QMessageBox::critical(0,tr("Error"), tr("Wrong password of book") + "!", QMessageBox::Ok);
            emit slotClose();
            return 1;
        }
    }

    QImage textImage;

    for (int i = 0; i < ListImages.count(); i++)
    {
        textImage.loadFromData(ListImages.at(i));
        document()->addResource(QTextDocument::ImageResource, QUrl(slNumberImages.at(i)), textImage);
    }

    sTextPage.clear();

    if (ListPages.count() == 0) ListPages.append(tr("The first page of a new book"));

    sTextPage.append(ListPages.at(0));
    setCurrentPage(1);

    QString sCurrentPage;
    sCurrentPage.setNum(currentPage());

    setHtml(sTextPage);
    setSaved(true);
    return 0;
}

uchar TTextBook::openHTMLFile(QString FileNameBook)
{
    QString str;
    QString sHTML;
    QString sFileName;
    QFile ifile(FileNameBook);
    QTextStream istream(&ifile);
    float i = 0;
    float ipt, iptc;
    iptc = 0;
    ipt = 0;
    ifile.open(QIODevice::ReadOnly);

    QStringList ListNameImage;
    sFileName = FileNameBook;
    sFileName.remove(0, sFileName.lastIndexOf("/") + 1);
    sFileName.truncate(sFileName.indexOf("."));
    FileNameBook.truncate(FileNameBook.lastIndexOf("/"));
    QDir dir;

    if (dir.exists(FileNameBook + "/" + sFileName))
        dir.setPath(FileNameBook + "/" + sFileName);
    else
        if (dir.exists(FileNameBook + "/" + sFileName + "_files"))
        {
            dir.setPath(FileNameBook + "/" + sFileName + "_files");
            sFileName += "_files";
        }
    else
        if (dir.exists(FileNameBook + "/" + sFileName + ".files"))
        {
            dir.setPath(FileNameBook + "/" + sFileName + ".files");
            sFileName += ".files";
        }

    QImage IOImage;
    QByteArray baImage;
    int CurrentImage;
    CurrentImage = 0;

    if (dir.isReadable())
    {
        foreach (QString strFileName, dir.entryList(QDir::Files))
        {
            if(strFileName.indexOf(".html") == -1)
            {
                IOImage.load(dir.path() + "/" + strFileName);
                QBuffer buffer(&baImage);
                buffer.open(QIODevice::WriteOnly);
                IOImage.save(&buffer, "PNG");
                IOImage.loadFromData(baImage);
                ListImages.append(baImage);
                slNumberImages.append(QString::number(IOImage.serialNumber()));
                ListNameImage.append(strFileName);
            }
        }
    }

    while(!ifile.atEnd())
    {

        str.append(istream.readLine());
        str.append(" ");
        int a1;
        a1 = 0;
        sHTML.append(str);

        if(str.indexOf("<TABLE") != -1) iptc = 1;
        if(str.indexOf("/TABLE>") != -1) iptc = 2;

        int j, iptc2;
        QString s1,s2;
        s1.clear();
        s2.clear();

        iptc2 = 0;
        j = str.indexOf("font-size:");

        if(j != -1 && str.indexOf("pt", j) != -1)
        {
            s1.append(str.at(str.indexOf("pt", j) - 1));

            if(str.at(str.indexOf("pt", j) - 2) != ' ') s2.append(str.at(str.indexOf("pt", j) - 2));
            if(s2 != "") s1.append(s2);
            bool bOk;
            ipt = s1.toFloat(&bOk);
            ipt = (ipt / 6) * 0.1375;

        }

        if(j == -1)
        {
            if(str.indexOf("FONT SIZE=1") != -1) j = 1 ;
            if(str.indexOf("FONT SIZE=2") != -1) j = 2 ;
            if(str.indexOf("FONT SIZE=3") != -1) j = 3 ;
            if(str.indexOf("FONT SIZE=4") != -1) j = 4 ;
            if(str.indexOf("FONT SIZE=5") != -1) j = 5 ;
            if(str.indexOf("FONT SIZE=6") != -1) j = 6 ;
            if(str.indexOf("FONT SIZE=7") != -1) j = 7 ;

            switch(j)
            {
            case 1:
                ipt = (8 / 6) * 0.1375;
            case 2:
                ipt = (10 / 6) * 0.1375;
            case 3:
                ipt = (12 / 6) * 0.1375;
            case 4:
                ipt = (14 / 6) * 0.1375;
            case 5:
                ipt = (18 / 6) * 0.1375;
            case 6:
                ipt = (24 / 6) * 0.1375;
            case 7:
                ipt = (36 / 6) * 0.1375;
            }
        }

        i += ipt;

        if(i >= 100)
        {
            for (int z = 0; z < slNumberImages.count(); z++)
            {
                sHTML.replace(sFileName + "/" + ListNameImage.at(z), slNumberImages.at(z));
            }

            if(iptc == 0)
            {
                sHTML.append("</body></html>");
                ListPages.append(sHTML);
                sHTML.clear();
                sHTML.append("<html><body>");
                i = 0;
            }
            else
            {
                if(iptc == 2)
                {
                    sHTML.append("</body></html>");
                    ListPages.append(sHTML);
                    sHTML.clear();
                    sHTML.append("<html><body>");
                    i = 0;
                    iptc = 0;
                }
            }
        }

        str.clear();
    }

    sHTML.replace("IMG SRC", "img src");

    for (int i = 0; i < slNumberImages.count(); i++)
    {
        sHTML.replace(sFileName + "/" + ListNameImage.at(i), slNumberImages.at(i));
        IOImage.loadFromData(ListImages.at(i));
        document()->addResource(QTextDocument::ImageResource, QUrl(slNumberImages.at(i)), IOImage);
    }

    if(sHTML != "") ListPages.append(sHTML + "</body></html>");

    ifile.close();

    return 0;
}

uchar TTextBook::openEncodedPlainText(QString FileNameBook)
{
    QString sTXT;
    QFile ifile(FileNameBook);
    QTextStream idata(&ifile);
    ifile.open(QIODevice::ReadOnly);
    ListPages.clear();

    while(!ifile.atEnd())
    {
        for(int i = 1; i <= 30; i++)
        {
            sTXT.append("<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px;"
                        " margin-right:0px; -qt-block-indent:0; text-indent:0px;\">" +
                        idata.readLine() + "</p>");
        }

        ListPages.append(sTXT);
        sTXT.clear();
    }

    ifile.close();
    return 0;
}

uchar TTextBook::nextPage()
{
    emit getModeWork();

    if (isModeWork() == FileOptions::MODE_EDITING && currentPage() == countPages() && toPlainText() != "")
    {
        ListPages.append(" ");
    }

    if (countPages() == currentPage()) return 1;

    ListPages.replace(currentPage() - 1, toHtml());
    setCurrentPage(currentPage() + 1);
    sTextPage = ListPages.at(currentPage() - 1);
    setHtml(sTextPage);
    return 0;
}

uchar TTextBook::previousPage()
{
    ListPages.replace(currentPage() - 1, toHtml());
    setCurrentPage(currentPage() - 1);
    sTextPage = ListPages.at(currentPage() - 1);
    setHtml(sTextPage);
    return 0;
}

void TTextBook::slotInsertImage()
{
    QString FileImage;
    FileImage = QFileDialog::getOpenFileName(0, tr("Image open"), "", "*.jpg *.jpeg *.gif *.png *.xpm *.ppm *.bmp *.pbm");

    if(FileImage != "")
    {
        QImage IOImage;
        QByteArray baImage;

        IOImage.load(FileImage);
        QBuffer buffer(&baImage);
        buffer.open(QIODevice::WriteOnly);
        IOImage.save(&buffer, "PNG");
        IOImage.loadFromData(baImage);
        ListImages.append(baImage);
        slNumberImages.append(QString::number(IOImage.serialNumber()));

        textCursor().insertImage(IOImage, QString::number(IOImage.serialNumber()));
    }
}

uchar TTextBook::numberPage()
{
    bool bOk;
    ListPages.replace(currentPage() - 1, toHtml());
    setCurrentPage(QInputDialog::getInteger(0, tr("Enter page"), tr("Page number:"), currentPage(), 1, countPages(), 1, &bOk));

    if(currentPage() < 1 || currentPage() > countPages()) return 1;

    sTextPage = ListPages.at(currentPage() - 1);
    QString sNumPage;
    sNumPage.setNum(currentPage());
    setHtml(sTextPage);
    return 0;
}

void TTextBook::slotChangeFont()
{
    bool Accept;
    QFont TextFont;
    TextFont = textCursor().charFormat().font();
    TextFont = QFontDialog::getFont(&Accept, TextFont);

    if(Accept)
    {
        QTextCharFormat tcf;
        tcf.setFont(TextFont);
        textCursor().setCharFormat(tcf);
    }
    else return;
}

void TTextBook::insertNewPage()
{
    ListPages.replace(currentPage() - 1, toHtml());
    setCurrentPage(currentPage() + 1);
    ListPages.insert(currentPage() - 1, " ");
    sTextPage = ListPages.at(currentPage() - 1);
    setHtml(sTextPage);
}

void TTextBook::deleteCurrentPage()
{
    ListPages.removeAt(currentPage() - 1);
    sTextPage.clear();

    if(countPages() < currentPage()) setCurrentPage(currentPage() - 1);
    if(currentPage() != countPages()) sTextPage.append(ListPages.at(currentPage() - 1));
    else
    {
        //sNum.setNum(iNumberPage);
        sTextPage.append(ListPages.at(currentPage() - 1));
    }

    setHtml(sTextPage);
}

void TTextBook::slotToPlainText()
{
    setPlainText(toHtml());
}

void TTextBook::saveToPortable(QString FileNameBook, QString sFormat)
{
#ifndef QT_NO_PRINTER

    QPrinter printer(QPrinter::HighResolution);

    if (sFormat == "PDF") printer.setOutputFormat(QPrinter::PdfFormat);
    if (sFormat == "PS") printer.setOutputFormat(QPrinter::PostScriptFormat);

    printer.setOutputFileName(FileNameBook);
    QTextDocument *textDoc = new QTextDocument;
    QString sPrint;

    sPrint = makeOneHTML();

    QImage textImage;

    for (int i = 0; i < ListImages.count(); i++)
    {
        textImage.loadFromData(ListImages.at(i));
        textDoc->addResource(QTextDocument::ImageResource, QUrl(slNumberImages.at(i)), textImage);
    }

    textDoc->setHtml(sPrint);
    textDoc->print(&printer);

    delete textDoc;
#endif
}

void TTextBook::saveToRTF(QString FileNameBook)
{
    QString sExport;
    QFile ifile(FileNameBook);
    QTextStream istream(&ifile);
    istream.setCodec("UTF-8");
    ifile.open(QIODevice::WriteOnly);
    sExport = makeOneHTML();
    QTextDocument *textDoc = new QTextDocument;
    textDoc->setHtml(sExport);
    sExport = textDoc->toPlainText();
    istream << "{\\rtf1";
    istream << wordToUnicode(sExport);
    istream << "}";
    ifile.close();
    delete textDoc;
}

QString TTextBook::wordToUnicode(QString sWord)
{
    QString sTemp;

    for (int i = 0; i < sWord.length(); i++)
        sTemp.append("\\u" + QString::number(sWord.at(i).unicode()) + "?");

    return sTemp;
}
