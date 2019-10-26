/* ======================================================================
**  TFormOptions.h - Заголовочный файл формы модуля параметров библиотеки.
*/

#ifndef TFORMOPTIONS_H
#define TFORMOPTIONS_H
#include <QtGui/QDialog>
#include <QtGui/QFileDialog>
#include <QtCore/QDir>
#include <fileoptions/fileoptions.h>

/*namespace Ui {
class FormOptions;
}*/

class FormOptions: public QDialog/*, public Ui::FormOptions */{
      Q_OBJECT

public:

       FileOptions FO;

       explicit FormOptions(QDialog *pwgt = 0);
       ~FormOptions();

       /*Ui::FormOptions *ui;*/

       void initVariables();

private:

public slots:


private slots:
       void on_cbLastOpened_clicked();
       void on_cbPathOptionsLocally_clicked();
       //void on_bbOptions_clicked(QAbstractButton *button);
       void on_pbPathLibrary_clicked();
       void on_pbPathStatistics_clicked();
       void on_pbPathOptions_clicked();
       void on_pbPathShelkTest_clicked();
};
#endif
