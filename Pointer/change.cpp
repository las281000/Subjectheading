#include "change.h"
#include "ui_change.h"
#include <QPair>
Change::Change(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Change)
{
    ui->setupUi(this);
    ui->message->hide();
    ui->saveButton->hide();
    ui->Lpages->hide();
    ui->pagesEdit->hide();
    ui->success->hide();
}

Change::~Change()
{
    delete ui;
}

void Change:: checkInput(QMap<QString, QString>* map)
{
    ui->message->hide();
    ui->saveButton->hide();
    ui->Lpages->hide();
    ui->pagesEdit->hide();
    ui->success->hide();

    if (ui->termEdit->text() == ""){
        ui->message->setText("Заполните поле!");
        ui->message->show();
    }
    else{
    bool shit = true;

    for(QMap<QString, QString>:: iterator it = map->begin(); it != map->end(); it++ ){
        if (it.key() == ui->termEdit->text()) {
            shit = false;
            break;
        }
    }

    if (shit == true){
        ui->message->setText("Термин не найден. Для добавления нового термина используйте функцию Добавить.");
        ui->message->show();
    }

    else{
        ui->Lpages->show();
        ui->pagesEdit->show();
        ui->saveButton->show();
    }
  }
}

void Change::on_saveButton_released()
{
    if(ui->pagesEdit->text() == ""){
        ui->message->setText("Заполните поле \"Страницы\"!");
        ui->message->show();
    }
    else {
      ui->message->hide();

      QString term = ui->termEdit->text();
      QString pages = ui->pagesEdit->text();
      QString str = (term + ";" + pages+";");

      emit sendChangedData(str);

      ui->termEdit->clear();

      ui->pagesEdit->clear();
      ui->pagesEdit->hide();

      ui->Lpages->hide();
      ui->saveButton->hide();
    }
}

