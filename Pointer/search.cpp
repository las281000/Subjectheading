#include "open.h"
#include "open.h"
#include "search.h"
#include "ui_search.h"

#include <QMap>
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>

Search::Search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Search)
{ 
    ui->setupUi(this);
    ui->result->removeRow(0);

    ui->result->hide();
    ui->notFound->hide();
}

Search::~Search()
{
    delete ui;
}

void Search:: findTheKey(QMap<QString,QString>* map){
    ui->result->hide();
    ui->notFound->hide();
    QString term = ui->input->text(); //получили термин для поиска

    if (term==""){
        ui->notFound->setText("Заполните поле!");
        ui->notFound->show();
    }
    else{
    bool flag = false;

    ui->result->setColumnWidth(0,297);
    ui->result->setColumnWidth(1, 409);

    QMap<QString,QString>:: iterator it;
    for (it = map->begin(); it!= map->end(); it++){

        if (it.key() == term) { //если найден нужный ключ

            flag = true;
            ui->result->setRowCount(1);

            QTableWidgetItem* key = new QTableWidgetItem(term);
            ui->result->setItem(0, 0, key);
            key->setFlags(Qt::ItemIsEnabled);

            QTableWidgetItem* val = new QTableWidgetItem (it.value());
            ui->result->setItem(0, 1, val);
            val->setFlags (Qt::ItemIsEnabled);
        }
    }

    if (flag==false){
        ui->notFound->setText("Заданный термин не найден.");
        ui->notFound->show();
    }
    else{
        ui->result->show();
    }
  }
}
