#include "remove.h"
#include "ui_remove.h"
#include <QString>

Remove::Remove(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Remove)
{
    ui->setupUi(this);
    ui->message->hide();
}

Remove::~Remove()
{
    delete ui;
}



void Remove::on_removeButton_released()
{    
    QString str = ui->termEdit->text();
    if (str != ""){
        emit sendData(str);
        ui->termEdit->clear();
    }
    else{
        ui->message->setText("Заполните поле!");
        ui->message->show();
    }

}
