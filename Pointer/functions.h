#ifndef WRITETOFILE_H
#define WRITETOFILE_H

#include <QString>
#include <QFile>

enum purpose{
    PROGRAMME,
    USER,
};

enum states{
    OPEN,
    CREATE,
    START,
    TEXT
};

void writeToFile (QString filePath, QMap<QString,QString>* map, int purpose);

#endif // WRITETOFILE_H
