/* ======================================================================
**  ListAdditionally.cpp - Исходный файл модуля формы дополнительной информации.
*/

#include "ListAdditionally.h"

ListAdditionally::ListAdditionally(QDialog *pwgt /* = 0*/): QDialog(pwgt),
    tfDoc(new QTemporaryFile),
    ui(new Ui::ListAdditionally)
{
    ui->setupUi(this);

    connect(ui->lwAdditionally, SIGNAL(doubleClicked(QModelIndex)), SLOT(slotRunFile()));

}

ListAdditionally::~ListAdditionally()
{
    tfDoc->close();
    delete tfDoc;
    delete ui;
}

void ListAdditionally::slotRunFile()
{
    if(*sItem == tr("Documents") && gMode == true)
    {
        QFile ifile(ui->lwAdditionally->item(ui->lwAdditionally->currentRow())->text());
        QByteArray baFile;
        ifile.open(QIODevice::ReadOnly);
        baFile = ifile.readAll();
        ifile.close();

        if (tfDoc->isOpen()) tfDoc->close();

        tfDoc->open();
        tfDoc->write(baFile);
        QDesktopServices::openUrl(QUrl::fromLocalFile(tfDoc->fileName()));
    }
    else QDesktopServices::openUrl(QUrl::fromLocalFile(ui->lwAdditionally->item(ui->lwAdditionally->currentRow())->text()));
}

void ListAdditionally::on_pbAddFile_clicked()
{
    QString sFile;
    sFile = QFileDialog::getOpenFileName(0, tr("Open additional file"), "", "*");

    if (sFile != "")
    {
        ui->lwAdditionally->addItem(sFile);

        if (*sItem == tr("Music")) slMusic.append(sFile);
        if (*sItem == tr("Films")) slFilms.append(sFile);
        if (*sItem == tr("Photo")) slPhotos.append(sFile);
        if (*sItem == tr("Documents")) slDocuments.append(sFile);
        if (*sItem == tr("Programs")) slPrograms.append(sFile);
    }
}

void ListAdditionally::on_pbRemoveFile_clicked()
{
    if (*sItem == tr("Music"))
    {
        slMusic.removeAt(ui->lwAdditionally->currentRow());
        ui->lwAdditionally->model()->removeRow(ui->lwAdditionally->currentRow());
    }

    if (*sItem == tr("Films"))
    {
        slFilms.removeAt(ui->lwAdditionally->currentRow());
        ui->lwAdditionally->model()->removeRow(ui->lwAdditionally->currentRow());
    }

    if (*sItem == tr("Photo"))
    {
        slPhotos.removeAt(ui->lwAdditionally->currentRow());
        ui->lwAdditionally->model()->removeRow(ui->lwAdditionally->currentRow());
    }

    if (*sItem == tr("Documents"))
    {
        slDocuments.removeAt(ui->lwAdditionally->currentRow());
        ui->lwAdditionally->model()->removeRow(ui->lwAdditionally->currentRow());
    }

    if (*sItem == tr("Programs"))
    {
        slPrograms.removeAt(ui->lwAdditionally->currentRow());
        ui->lwAdditionally->model()->removeRow(ui->lwAdditionally->currentRow());
    }
}
