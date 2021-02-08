#include "open.h"
#include "ui_open.h"

#include "search.h"
#include "ui_search.h"

#include "add.h"
#include "ui_add.h"

#include "change.h"
#include "ui_change.h"

#include"functions.h"

#include <QPalette>
#include <QColor>
#include <QTableWidget>
#include <QFile>
#include <QFileDialog>
#include <QMap>
#include <QString>
#include <QFileInfo>
#include <QMessageBox>

//конструктор
Open::Open(QString filePath, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Open)
{

    ui->setupUi(this);

    QPalette window;
    window.setColor(QPalette::Window, Qt::white);
    setAutoFillBackground(true);
    setPalette(window);

    this->filePath = filePath;

    file.setFileName(filePath);
    file.open(QIODevice::ReadOnly);

    this->filePath = filePath;

    filePath.chop(4);
    while  (filePath.contains("/")){
        if (filePath.contains("/")) {
            filePath.remove(0, filePath.indexOf("/")+1);
        }
    }

    ui->book->setText(filePath);
    ui->list->setColumnWidth(0,530);
    ui->list->setColumnWidth(1, 300);
    

    QString newLine;
    QMap<QString, QString>::iterator it = map.begin();

    while (!file.atEnd()){ //пихаем в таблицу мап
        newLine = file.readLine();

        ui->list->setRowCount(ui->list->rowCount()+1);
        it = map.insert(newLine.section(';',0,0), newLine.section(';',1,1));

        QTableWidgetItem* book = new QTableWidgetItem(it.key());
        QTableWidgetItem* pages = new QTableWidgetItem(it.value());
        book->setFlags(Qt::ItemIsEnabled);
        pages->setFlags(Qt::ItemIsEnabled);
        ui->list->setItem(ui->list->rowCount()-1, 0, book);
        ui->list->setItem(ui->list->rowCount()-1, 1, pages);
    }
    file.close();
}

//деструктор
Open::~Open(){
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//открывает окно поиска
void Open::showSearch(){
    searchWindow = new Search();
    searchWindow->show();

    connect (searchWindow->ui->search, SIGNAL(released()), this, SLOT (sendDataF()));
    connect(this, SIGNAL(sendData(QMap<QString, QString>*)), searchWindow, SLOT(findTheKey(QMap<QString, QString>*)));
}


//открывает окно добавления термина
void Open:: showAdd(){
    addWindow = new Add();
    addWindow->show();

    connect(addWindow, SIGNAL(sendData(QString,QString)), this, SLOT(addNewTerm(QString, QString)));

}

//открывает окно редактирования терминов
void Open:: showChange(){
    changeWindow = new Change();
    changeWindow->show();

    connect(changeWindow->ui->checkButton, SIGNAL(released()), this, SLOT(sendDataF()));
    connect(this, SIGNAL(sendData(QMap<QString, QString>*)), changeWindow, SLOT(checkInput(QMap<QString, QString>*)));

    connect (changeWindow, SIGNAL(sendChangedData(QString)), this, SLOT(changeData(QString)));
}


//открывает окно удаления терминов
void Open:: showRemove(){
    removeWindow = new Remove();
    removeWindow->show();

    connect(removeWindow, SIGNAL(sendData(QString)), this, SLOT(removeData(QString)));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//отправление map в функции
void Open:: sendDataF(){
    emit sendData(&map);
}

void Open:: sendStartF(){
    emit sendStart(START);
}


//добавления нового термина
void Open:: addNewTerm(QString term, QString pages){
    QFile file (filePath);
    file.open(QIODevice::WriteOnly);

    bool shit = false;

    for (QMap<QString,QString>::iterator it = map.begin(); it != map.end(); it++){
        if (it.key() == term){
            shit = true;
        }
    }

    if (shit == true){
        addWindow->ui->massage->setText("Такой термин уже есть в указателеле,"
                                        "используйте функцию редактирования записей.");
        addWindow->ui->massage->show();
    }
    else{
            QString newLine = term + ";" + pages + ";\n";
            file.write(newLine.toUtf8());
            map.insert(term, pages);

            ui->list->setRowCount(0);

            for (QMap<QString, QString>::iterator it = map.begin(); it!= map.end(); it++){
                ui->list->setRowCount(ui->list->rowCount()+1);
                QTableWidgetItem* book = new QTableWidgetItem(it.key());
                QTableWidgetItem* pages = new QTableWidgetItem(it.value());
                book->setFlags(Qt::ItemIsEnabled);
                pages->setFlags(Qt::ItemIsEnabled);
                ui->list->setItem(ui->list->rowCount()-1, 0, book);
                ui->list->setItem(ui->list->rowCount()-1, 1, pages);
                }
            addWindow->ui->massage->setText("Термин успешно добавлен.");
            addWindow->ui->massage->show();
    }
    file.close();
}


//изменение существующего термина
void Open::changeData(QString data){

    QString term = data.section(";", 0,0);
    QString pages = data.section (";", 1,1);

    for(QMap<QString,QString>:: iterator it = map.begin(); it != map.end(); it++){
        if (it.key() == term){
            it.value() = pages;
        }
    }

    for (int i = 0; i < ui->list->rowCount(); i++){
        if(ui->list->item(i,0)->text() == term){
            ui->list->item(i,1)->setText(pages);
            changeWindow->ui->success->show();
        }
    }

    writeToFile(filePath, &map, PROGRAMME);

}


//удаление термина
void Open:: removeData(QString term){
    bool deleted = false; //удалено - нет
    int row = 0;

    for(QMap<QString,QString>:: iterator it = map.begin(); it != map.end();){

        if (it.key() == term){
            deleted = true;

            it = map.erase(it);

            if (ui->list->item(row, 0)->text() == term){
                ui->list->removeRow(row);

            removeWindow->ui->message->setText("Термин удален.");
            removeWindow->ui->message->show();

            writeToFile(filePath, &map, PROGRAMME);
            }
        }
        else {
            it++;
        }
        row++;
    }

    if (deleted == false){
        removeWindow->ui->message->setText("Такого термина нет в указателе.");
        removeWindow->ui->message->show();
    }
}


//сохранение в файл
void Open:: saveInFile(){
   QString saveFileName = "";

   saveFileName = QFileDialog:: getSaveFileName(nullptr, "Сохранить предметный указатель") + ".txt";

   if (saveFileName != ".txt"){
        writeToFile(saveFileName, &map, USER);
        QMessageBox::information(this, "Информация", "Файл успешно сохранен.\nПуть:"+saveFileName);
   }
}
