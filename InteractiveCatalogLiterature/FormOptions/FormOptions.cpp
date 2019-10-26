/* ======================================================================
**  Options.cpp - Исходный файл модуля формы параметров библиотеки.
*/

#include "FormOptions.h"


//FormOptions::FormOptions(QDialog *pwgt /* = 0*/): QDialog(pwgt),
//    ui(new Ui::FormOptions)
//{
//    ui->setupUi(this);
//}

//FormOptions::~FormOptions()
//{
//    delete ui;
//}

//void FormOptions::initVariables()
//{
//    if (ui->cbLanguage->currentIndex() == 0)
//        FO.setLanguageProgram(FileOptions::LANGUAGE_RUSSIAN);
//    else
//        FO.setLanguageProgram(FileOptions::LANGUAGE_ENGLISH);

//    FO.setStateStandardToolbar(ui->cbStandardToolbar->isChecked());
//    FO.setStateEditToolbar(ui->cbEditToolbar->isChecked());
//    FO.setStateFindToolbar(ui->cbFindToolbar->isChecked());
//    FO.setStateFormatToolbar(ui->cbFormatToolbar->isChecked());
//    FO.setSavePasswordBook(ui->cbSavePasswordBook->isChecked());
//    FO.setPathOptionsLocally(ui->cbPathOptionsLocally->isChecked());
//    FO.setPathOptions(ui->lePathOptions->text());
//    FO.setPathStatistics(ui->lePathStatistics->text());
//    FO.setRememberLastOpened(ui->cbLastOpened->isChecked());
//    FO.setPathLastLibrary(ui->lePathLibrary->text());
//    FO.setPathProgramShelkTest(ui->lePathShelkTest->text());
//}

//void FormOptions::on_cbLastOpened_clicked()
//{
//    ui->lePathLibrary->setEnabled(ui->cbLastOpened->isChecked());
//    ui->pbPathLibrary->setEnabled(ui->cbLastOpened->isChecked());
//}

//void FormOptions::on_cbPathOptionsLocally_clicked()
//{
//    ui->lePathOptions->setEnabled(!ui->cbPathOptionsLocally->isChecked());
//    ui->pbPathOptions->setEnabled(!ui->cbPathOptionsLocally->isChecked());
//}

//void FormOptions::on_bbOptions_clicked(QAbstractButton *button)
//{
//    if (button == ui->bbOptions->button(QDialogButtonBox::RestoreDefaults))
//    {
//        ui->cbSavePasswordBook->setChecked(true);
//        ui->cbLastOpened->setChecked(true);
//        on_cbLastOpened_clicked();
//        ui->lePathLibrary->clear();
//        ui->cbPathOptionsLocally->setChecked(true);
//        on_cbPathOptionsLocally_clicked();
//        ui->lePathOptions->clear();
//        ui->lePathStatistics->setText(QDir::homePath());
//        ui->cbStandardToolbar->setChecked(true);
//        ui->cbEditToolbar->setChecked(false);
//        ui->cbFormatToolbar->setChecked(false);
//        ui->cbFindToolbar->setChecked(false);
//        ui->cbLanguage->setCurrentIndex(0);
//        ui->lePathShelkTest->clear();
//    }

//    if (button == ui->bbOptions->button(QDialogButtonBox::Reset))
//    {
//        ui->cbSavePasswordBook->setChecked(FO.isSavePasswordBook());
//        ui->cbLastOpened->setChecked(FO.isRememberLastOpened());
//        on_cbLastOpened_clicked();
//        ui->lePathLibrary->setText(FO.pathLastLibrary());
//        ui->cbPathOptionsLocally->setChecked(FO.isPathOptionsLocally());
//        on_cbPathOptionsLocally_clicked();
//        ui->lePathOptions->setText(FO.pathOptions());
//        ui->lePathStatistics->setText(FO.pathStatistics());
//        ui->cbStandardToolbar->setChecked(FO.isStateStandardToolbar());
//        ui->cbEditToolbar->setChecked(FO.isStateEditToolbar());
//        ui->cbFormatToolbar->setChecked(FO.isStateFormatToolbar());
//        ui->cbFindToolbar->setChecked(FO.isStateFindToolbar());
//        ui->lePathShelkTest->setText(FO.pathProgramShelkTest());

//        if (FO.isLanguageProgram() == FileOptions::LANGUAGE_RUSSIAN)
//            ui->cbLanguage->setCurrentIndex(0);
//        else
//            ui->cbLanguage->setCurrentIndex(1);
//    }
//}

//void FormOptions::on_pbPathLibrary_clicked()
//{
//    QString str = QFileDialog::getOpenFileName(0, tr("Select Library"), ui->lePathLibrary->text(),
//                                               "XWLB - " + tr("Library of books, software of Klen-library") + " (*.xwlb)");

//    if(str != "") ui->lePathLibrary->setText(str);
//}

//void FormOptions::on_pbPathStatistics_clicked()
//{
//    QString sStatistics = QFileDialog::getSaveFileName(0, tr("Select file of statistics."), ui->lePathStatistics->text(),
//                                               tr("Document") + " HTML (*.html);;");

//    if (sStatistics != "")
//    {
//        if (sStatistics.indexOf(".html") == -1) sStatistics.append(".html");

//        ui->lePathStatistics->setText(sStatistics);
//    }
//}

//void FormOptions::on_pbPathOptions_clicked()
//{
//    QString str = QFileDialog::getExistingDirectory(0, tr("Selection directory path of options"), ui->lePathOptions->text());

//    if(str != "") ui->lePathOptions->setText(str);
//}

//void FormOptions::on_pbPathShelkTest_clicked()
//{
//    QString str = QFileDialog::getOpenFileName(0, tr("Select program of Shelk-test"), ui->lePathShelkTest->text());

//    if(str != "") ui->lePathShelkTest->setText(str);
//}
//
