#include "labgenerationmanager.h"

labGenerationManager::labGenerationManager()
{

}
labGenerationManager::labGenerationManager(Task _task, LabsThemsManager* themsManager)
{
    task = _task;
    mThemsManager = themsManager;
}

QString labGenerationManager::generateLabHTML()
{
    QString HTMLtext = "";
    HTMLtext += task.Text();
    return HTMLtext;
}
