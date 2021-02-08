#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include "start.h"
#include "open.h"
#include "create.h"
#include "search.h"
#include "text.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    Start* start;
    Create* create;
    Open* open;
    Text* text;

    QToolBar* tools;

    void createToolBar();

private slots:
    void changeState(int);

signals:
    void sendStart(int);

};
#endif // MAINWINDOW_H
