#ifndef LABSTHEMSMANAGER_H
#define LABSTHEMSMANAGER_H

#include "labsstructures.h"
#include <QList>

class LabsThemsManager
{
private:
    QList <Theme> usedThems;
    QList <Theme> unusedThems;

    int usedThemsIndex(int id);
    int unusedThemsIndex(int id);
    int getFieldIndex(Theme theme, int id);
    int generateFieldId(Theme theme);

public:
    LabsThemsManager();

    void updateManager();
    QList<Theme> thems();

    Theme* getTheme(int id);
    Field* getField(int themeId, int id);

    int getThemeIdFromPosition(int index);
    int getFieldIdFromPosition(int index, int themeId);

    void changeThemeUsable(int id, bool usable);
    void changeField(int themeId, int fieldId, Field field);
    void deleteField(int themeId, int fieldId);
    void addField(int themeId, Field field);

};

#endif // LABSTHEMSMANAGER_H
