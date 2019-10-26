#ifndef CREATE_H
#define CREATE_H
#include "ui_Create.h"
#include <QtGui/QDialog>

namespace Ui {
class Create;
}

class Create : public QDialog, public Ui::Create {
      Q_OBJECT

public:

       explicit Create(QDialog *pwgt = 0);
       ~Create();

       Ui::Create *ui;

private:

};
#endif //CREATE_H
