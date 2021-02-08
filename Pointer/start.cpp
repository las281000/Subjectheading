#include "start.h"
#include "ui_start.h"
#include "mainwindow.h"

#include "functions.h"

#include <QPushButton>
#include <QSize>
#include <QIcon>
#include <QPalette>
#include <QColor>

Start::Start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Start)
{

    ui->setupUi(this);
    QSize size(302, 110);

    QPalette window;
    window.setColor(QPalette::Window, Qt::white);

    setAutoFillBackground(true);
    setPalette(window);

    ui->CreateButton->setIcon(QIcon(":/images/icons/create.png"));
    ui->CreateButton->setIconSize(size);
    ui->CreateButton->setStyleSheet("text-align: left;");

    ui->OpenButton->setIcon(QIcon(":/images/icons/open.png"));
    ui->OpenButton->setIconSize(size);
    ui->OpenButton->setStyleSheet("text-align: left;");

    ui->TextButton->setIcon(QIcon(":/images/icons/text.png"));
    ui->TextButton->setIconSize(size);
    ui->TextButton->setStyleSheet("text-align: left;");
}

Start::~Start()
{
    delete ui;
}

void Start::on_OpenButton_released()
{
    emit sendState(OPEN);
}

void Start::on_CreateButton_released()
{
    emit sendState(CREATE);
}

void Start::on_TextButton_released()
{
    emit sendState(TEXT);
}
