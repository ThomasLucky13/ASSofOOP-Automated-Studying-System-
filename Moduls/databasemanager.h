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

    QList<Task> ReadTasks();
    void WriteTasks(QList<Task> tasks);

private:
    QString themsDatabaseFileName;
    QString tasksDatabaseFileName;

    QJsonObject getJsonObjectFromFile(QString fileName);
    void writeJsonObjectToFile(QJsonObject json, QString fileName);
};

#endif // DATABASEMANAGER_H
