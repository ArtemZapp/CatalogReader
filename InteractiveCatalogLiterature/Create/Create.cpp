#include "Create.h"


Create::Create(QDialog *pwgt /* = 0*/): QDialog(pwgt),
    ui(new Ui::Create)
{
    ui->setupUi(this);
}

Create::~Create()
{
    delete ui;
}
