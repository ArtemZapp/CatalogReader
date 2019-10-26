/* ======================================================================
**  ListAdditionally.h - Заголовочный файл модуля формы дополнительной информации.
*/

#ifndef LISTADDITIONALLY_H
#define LISTADDITIONALLY_H
#include "ui_ListAdditionally.h"
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QTemporaryFile>
#include <QtGui/QFileDialog>
#include <QtGui/QDialog>
#include <QtGui/QDesktopServices>
#include "const.h"

namespace Ui {
class ListAdditionally;
}

class ListAdditionally : public QDialog, public Ui::ListAdditionally {
    Q_OBJECT

public:
    QStringList  slMusic;//Список музыки
    QStringList  slFilms;//Список фильмов
    QStringList  slPhotos;//Список фотографий
    QStringList  slDocuments;//Список документов
    QStringList  slPrograms;//Список программ

    QTemporaryFile *tfDoc;//Временный файл документа
    QString *sItem;//Тип информации

    bool gMode;//true - Режим просмотра, false - Режим редактирования

    explicit ListAdditionally(QDialog *pwgt = 0);
    ~ListAdditionally();

    Ui::ListAdditionally *ui;

private:

public slots:

private slots:
    void on_pbAddFile_clicked();//Добавить файл
    void on_pbRemoveFile_clicked();//Удалить файл
    void slotRunFile();//Запустить файл
};
#endif
