/* ======================================================================
**  TStatistics.cpp - Исходный файл модуля формы статистики.
**  Является частью программы Клён-библиотека, распространяемой под
**  Стандартной общественной лицензией, версии 2 (GNU GPL v2).
** ======================================================================
**  Copyleft 2009 - 2013 by Lab Free Technologies <admin@LabFreeTech.org>
** ==============================================================================
**  Copyleft 2009 - 2013 Лаборатория свободных технологий <admin@LabFreeTech.org>
** ==============================================================================
*/

#include "TStatistics.h"

TStatistics::TStatistics(QDialog *pwgt/* = 0*/): QDialog(pwgt),
    ui(new Ui::TStatistics)
{
    ui->setupUi(this);
}

TStatistics::~TStatistics()
{
    delete ui;
}

void TStatistics::on_pbStatisticsClear_clicked()//Очистить статистику
{
    QString strStat;
    int ibegin;
    int iend;
    QFile rfile(FileOptions->pathStatistics());
    QTextStream srfile(&rfile);
    srfile.setCodec("UTF-8");
    rfile.open(QIODevice::ReadOnly);
    strStat.clear();
    strStat = srfile.readAll();
    rfile.close();
    QFile wfile(FileOptions->pathStatistics());
    QTextStream swfile(&wfile);
    swfile.setCodec("UTF-8");
    wfile.open(QIODevice::WriteOnly);
    ibegin = strStat.indexOf("</TR>\n") + 6;
    iend = strStat.lastIndexOf("</TABLE>");
    strStat.remove(ibegin, iend - ibegin);
    swfile << strStat;
    wfile.close();
    ui->teStatistics->setText(strStat);
}
