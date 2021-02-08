#ifndef CHANGE_H
#define CHANGE_H

#include <QWidget>
#include <QPair>

namespace Ui {
class Change;
}

class Change : public QWidget
{
    Q_OBJECT

public:
    explicit Change(QWidget *parent = nullptr);
    ~Change();

    Ui::Change *ui;

signals:
    void sendChangedData(QString);

private slots:
   void on_saveButton_released();
   void checkInput(QMap<QString, QString>*);
};

#endif // CHANGE_H
