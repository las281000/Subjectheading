#include "add.h"
#include "ui_add.h"
#include <QStyle>
Add::Add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
    ui->massage->hide();
}

Add::~Add()
{
    delete ui;
}

void Add::on_addButton_released()
{
    if ((ui->termEdit->text() != "")&&(ui->pageEdit->text() != "")){
        emit sendData(ui->termEdit->text(),ui->pageEdit->text());
    }
    else {
        ui->massage->setText("Заполните поля!");
        ui->massage->show();
    }
}
