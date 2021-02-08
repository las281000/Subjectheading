#ifndef ADD_H
#define ADD_H

#include <QWidget>

namespace Ui {
class Add;
}

class Add : public QWidget
{
    Q_OBJECT

public:
    explicit Add(QWidget *parent = nullptr);
    ~Add();

    Ui::Add *ui;

signals:
   void sendData(QString,QString);

private slots:
   void on_addButton_released(); //ОТПРАВКА СИГНАЛА
};

#endif // ADD_H
