#ifndef REMOVE_H
#define REMOVE_H

#include <QWidget>

namespace Ui {
class Remove;
}

class Remove : public QWidget
{
    Q_OBJECT

public:
    explicit Remove(QWidget *parent = nullptr);
    ~Remove();
    Ui::Remove *ui;

signals:
    void sendData(QString);

private slots:
    void on_removeButton_released();
};

#endif // REMOVE_H
