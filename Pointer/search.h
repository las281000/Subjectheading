#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>

namespace Ui {
class Search;
}

class Search : public QWidget
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = nullptr);
    ~Search();
    Ui::Search *ui;

private slots:
    void findTheKey(QMap<QString,QString>*);
};

#endif // SEARCH_H
