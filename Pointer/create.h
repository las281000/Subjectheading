#ifndef CREATE_H
#define CREATE_H

#include <QWidget>

namespace Ui {
class Create;
}

class Create : public QWidget
{
    Q_OBJECT

public:
    explicit Create(QWidget *parent = nullptr);
    ~Create();
    Ui::Create *ui;

signals:
   void sendState(int state);

private slots:
   void on_createButton_released();
   void on_cancel_released();
};

#endif // CREATE_H
