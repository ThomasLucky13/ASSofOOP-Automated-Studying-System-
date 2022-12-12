#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "Moduls/labsstructures.h"
#include <QJsonObject>

class DatabaseManager
{
public:
    DatabaseManager();
    QList<Theme> ReadThems();
    void WriteThems(QList<Theme> thems);
private:
    QString themsDatabaseFileName;
    QJsonObject getJsonObjectFromFile(QString fileName);
    void writeJsonObjectToFile(QJsonObject json, QString fileName);
};

#endif // DATABASEMANAGER_H
