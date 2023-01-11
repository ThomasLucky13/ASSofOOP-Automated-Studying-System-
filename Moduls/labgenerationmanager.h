#ifndef LABGENERATIONMANAGER_H
#define LABGENERATIONMANAGER_H

#include "Moduls/labsthemsmanager.h"
#include "Moduls/labsstructures.h"

class labGenerationManager
{
public:
    labGenerationManager();
    labGenerationManager(Task _task, LabsThemsManager* themsManager);
    QString generateLabHTML();

private:
    LabsThemsManager* mThemsManager;
    Task task;
};

#endif // LABGENERATIONMANAGER_H
