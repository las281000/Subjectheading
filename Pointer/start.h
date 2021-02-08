#ifndef START_H
#define START_H

#include <QWidget>

namespace Ui {
class Start;
}

class Start : public QWidget
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = nullptr);
    ~Start();

    Ui::Start *ui;

signals:
    void sendState (int state);
    
private slots:
    void on_OpenButton_released();
    void on_CreateButton_released();
    void on_TextButton_released();
};

#endif // START_H
