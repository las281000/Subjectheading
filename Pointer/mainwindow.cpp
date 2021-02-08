#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "functions.h"
#include <QObject>
#include <QToolBar>
#include <QIcon>
#include <QString>
#include <QPair>
#include <QFileDialog>

#include "start.h"
#include "open.h"
#include "create.h"
#include "search.h"

#include "ui_start.h"
#include "ui_open.h"
#include "ui_create.h"
#include "ui_search.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    start = nullptr;
    open = nullptr;
    create = nullptr;
    text = nullptr;
    tools = nullptr;

    connect(this, SIGNAL(sendStart(int)), this, SLOT(changeState(int)));
    emit sendStart(START);
}

MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow:: createToolBar(){ //создание панели инструментов
    tools =  new QToolBar("Инструменты");
    QSize size (50,60);

    QIcon home (":/images/icons/home.png");
    tools->addAction(home, "На начальную страницу",open, SLOT(sendStartF()));


    QIcon add (":/images/icons/add.png");
    QIcon file (":/images/icons/file.png");
    QIcon find (":/images/icons/find.png");
    QIcon change (":/images/icons/change.png");
    QIcon remove (":/images/icons/delete.png");

    tools->addAction(find, "Найти", open, SLOT(showSearch()));
    tools->addAction(file, "Сохранить в файл", open, SLOT(saveInFile()));
    tools->addAction(change, "Изменить", open, SLOT(showChange()));
    tools->addAction(remove, "Удалить термин", open,SLOT(showRemove()));
    tools->addAction(add,"Добавить термин", open, SLOT(showAdd()));

    addToolBar(Qt::LeftToolBarArea, tools);
    tools->setMovable(false);
    tools->setIconSize(size);
}

void MainWindow:: changeState(int state) { //функция изменяющяя внешний вид окна
    switch (state) {

    case OPEN:
    {
        QFileDialog choice;
        QString filename = "";
        filename = choice.getOpenFileName(nullptr, "Выбрать предметный указатель","*.csv");

        if(filename != ""){
            open = new Open (filename);
            setCentralWidget(open);
            open->show();

            createToolBar();
            connect(open, SIGNAL(sendStart(int)), this, SLOT(changeState(int)));

            if(start != nullptr){
                delete start;
                start = nullptr;
            }
        }
        break;
    }

    case CREATE:
    {
        create = new Create();
        setCentralWidget(create);
        create->show();

        if(start != nullptr){
            delete start;
            start = nullptr;
        }

        connect (create, SIGNAL(sendState(int)), this, SLOT(changeState(int)));
        break;
    }

    case START:
    {
        if (create != nullptr){
            delete create;
            create = nullptr;
        }
        if (open != nullptr){
            delete open;
            open = nullptr;
        }
        if (tools != nullptr){
            delete tools;
            tools = nullptr;
        }
        if (text != nullptr){
            delete text;
            text = nullptr;
        }
        start = new Start();
        setCentralWidget(start);
        start->show();

        connect(start, SIGNAL(sendState(int)), this, SLOT(changeState(int)));
        break;
    }

    case TEXT:
    {
        QFileDialog choice;

        QString filename = "";
        filename = choice.getOpenFileName(nullptr, "Выбрать предметный указатель","*.txt");



        if(filename != ""){
            text = new Text (filename);

            tools =  new QToolBar("Инструменты");
            QSize size (50,60);
            QIcon home (":/images/icons/home.png");
            tools->addAction(home, "На начальную страницу",text, SLOT(sendStartF()));
            addToolBar(Qt::LeftToolBarArea, tools);
            tools->setMovable(false);
            tools->setIconSize(size);

            text->show();
            setCentralWidget(text);
            connect(text, SIGNAL(sendStart(int)), this, SLOT(changeState(int)));

            if(start != nullptr){
                delete start;
                start = nullptr;
            }
        }
            break;
    }
  }

}
