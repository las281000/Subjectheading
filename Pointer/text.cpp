#include "text.h"
#include "ui_text.h"
#include "light.h"
#include "functions.h"

Text::Text (QString filePath, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Text)
{
    ui->setupUi(this);
    ui->message->hide();

    QPalette window;
    window.setColor(QPalette::Window, Qt::white);
    setAutoFillBackground(true);
    setPalette(window);

    this->filePath = filePath;

    file.setFileName(filePath);
    file.open(QIODevice::ReadOnly);

    this->filePath = filePath;

    ui->text->setText(file.readAll());
    ui->text->setReadOnly(true);

}

Text::~Text()
{
    delete ui;
}

void Text::on_searchButton_released()
{
    light = new Light (ui->text->document());
    connect(light,SIGNAL(setMessageText(int)), this, SLOT(changeMessageText(int)));
    light->searchStr(ui->lineEdit->text());
}

void Text::changeMessageText(int t){
    if (t==0){
        ui->message->setText("Совпадений не найдено.");
        ui->message->show();
        ui->message->setStyleSheet("color: rgb(255, 44, 44)");
    }
    else{
        ui->message->setText("Найдено " + QString::number(t) + " совпадение(й).");
        ui->message->show();
        ui->message->setStyleSheet("color: rgb(90, 185, 174)");
    }
}

void Text:: sendStartF(){
    emit sendStart(START);
}
