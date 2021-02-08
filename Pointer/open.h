#ifndef OPEN_H
#define OPEN_H

#include <QWidget>
#include <QMap>
#include <QFile>
#include "search.h"
#include "ui_search.h"
#include "add.h"
#include "ui_add.h"
#include "change.h"
#include "ui_change.h"
#include "remove.h"
#include "ui_remove.h"

namespace Ui {
class Open;
}

class Open : public QWidget
{
    Q_OBJECT

public:
    explicit Open(QString filePath, QWidget *parent = nullptr);

    ~Open();
    Ui::Open *ui;

private:
    QFile file;
    QString filePath;
    QMap <QString, QString> map;

    Search* searchWindow;
    Add* addWindow;
    Change* changeWindow;
    Remove* removeWindow;

signals:
    void sendData(QMap <QString,QString>*);
    void sendStart(int);

private slots:
    void showSearch();
    void showAdd();
    void showChange();
    void showRemove();

    void sendDataF();
    void sendStartF();

    void addNewTerm(QString, QString);    
    void changeData(QString);   
    void removeData(QString);
    void saveInFile();
};

#endif // OPEN_H
