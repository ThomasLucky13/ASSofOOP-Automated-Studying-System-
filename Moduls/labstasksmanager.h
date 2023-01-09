#ifndef LABSTASKSMANAGER_H
#define LABSTASKSMANAGER_H

#include "Moduls/labsstructures.h"
class labsTasksManager
{
private:
    QList<Task> tasks;

    void getTasksFromDatabase();
    int getTaskIndexFromId(QString id);
public:
    labsTasksManager();
    ~labsTasksManager();

    QList<Task> getTasks();

    Task* mCreationTask;

    void AddTask(Task task);
    void DeleteTask(QString id);
    void ChangeTask(QString id, Task task);
    Task getTask(int index);
    Task* getTask(QString id);
    QString getTaskIdFromIndex(int index);

};

#endif // LABSTASKSMANAGER_H
