#include "functions.h"
#include <QFile>
#include <QString>
#include <QMap>


//полная перезапись файла
void writeToFile (QString filePath, QMap<QString,QString>* map, int purpose){

    QFile file (filePath);
    file.open(QIODevice:: WriteOnly | QIODevice::Truncate);

    QString newLine;


    for(QMap<QString, QString>:: iterator it = map->begin(); it != map->end(); it++){
        if (purpose == PROGRAMME){
            newLine = it.key() + ";"+ it.value() +";\n";
        }
        else{
            newLine = it.key() + " - "+ it.value() +";\n";
        }
        file.write(newLine.toUtf8());
    }

    file.close();
}
