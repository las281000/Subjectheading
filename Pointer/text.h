#ifndef TEXT_H
#define TEXT_H

#include <QWidget>
#include <QFile>
#include "light.h"

namespace Ui {
class Text;
}

class Text : public QWidget
{
    Q_OBJECT

public:
    explicit Text(QString filePath, QWidget *parent = nullptr);
    ~Text();

private slots:
    void on_searchButton_released();
    void changeMessageText(int);
    void sendStartF();

private:
    QFile file;
    QString filePath;
    Ui::Text *ui;
    Light* light;

signals:
   void sendStart(int);


};

#endif // TEXT_H
