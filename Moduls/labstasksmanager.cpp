#include "labstasksmanager.h"
#include "Moduls/databasemanager.h"
#include <QUuid>
labsTasksManager::labsTasksManager()
{
    //tasks = DatabaseManager().ReadTasks();
    for (int i = 0; i < 5; i++)
    {
        tasks.push_back(Task(QString::number(i), "Task N"+QString::number(i), "Текст задания"));
    }
    mCreationTask = new Task("-1");
}

labsTasksManager::~labsTasksManager()
{
    //DatabaseManager().WriteTasks(tasks);
    delete mCreationTask;
}

QList<Task> labsTasksManager::getTasks()
{
    return tasks;
}

int labsTasksManager::getTaskIndexFromId(QString id)
{
    for (int i = 0; i < tasks.count(); ++i)
    {
        if(tasks[i].Id() == id)
            return i;
    }
    return -1;
}

void labsTasksManager::AddTask(Task task)
{
    task.setId(QUuid().createUuid().toString());
    tasks.push_back(task);
}

void labsTasksManager::DeleteTask(QString id)
{
    int index = getTaskIndexFromId(id);
    if (index != -1)
    {
        tasks.removeAt(index);
    }
}

void labsTasksManager::ChangeTask(QString id, Task task)
{
    int index = getTaskIndexFromId(id);
    if (index != -1)
    {
        tasks[index] = task;
    }
}

Task labsTasksManager::getTask(int index)
{
    return tasks[index];
}
Task* labsTasksManager::getTask(QString id)
{
    Task task = tasks[getTaskIndexFromId(id)];
    return new Task(task);
}
QString labsTasksManager::getTaskIdFromIndex(int index)
{
    if (index >= tasks.count()) return "-1";
    return tasks[index].Id();
}
