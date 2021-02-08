#include "create.h"
#include "ui_create.h"
#include <QPalette>
#include <QColor>
#include <QFile>
#include <QDir>
#include <QFileDialog>

#include <functions.h>

Create::Create(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Create)
{
    ui->setupUi(this);
    QPalette window;
    window.setColor(QPalette::Window, Qt::white);

    setAutoFillBackground(true);
    setPalette(window);

    ui->message->hide();

}

Create::~Create()
{
    delete ui;
}

void Create::on_createButton_released()
{
    if ((ui->name->text() == "")&(ui->author->text() == "")){
        ui->message->setText("Заполните поля!");
        ui->message->show();
    }
    else{ //формируем имя файла
         QString filename;
         if (ui->year->text() != ""){
            filename = ui->name->text() +
                       " (" +
                        ui->author->text() +
                        ", " +
                        ui->year->text() +
                        ").csv"   ;
         }
         else{
            filename = ui->name->text() +
                      " (" +
                       ui->author->text() +
                       ").csv"   ;
            }
         QFileDialog choice;
         QFile newPointer;

         newPointer.setFileName(choice.getExistingDirectory(nullptr, "Сохранить как...") + "/" + filename);

         newPointer.open(QIODevice:: WriteOnly);
         newPointer.close();

         emit sendState(OPEN);
    }
}

void Create::on_cancel_released()
{
    emit sendState(START);
}
