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
    int getFieldIndex(Theme* theme, int id);
    int generateFieldId(Theme theme);
    int generateThemeId();

    void changeFriendsThems(int themeId, QList<int> friendsThems);


public:
    LabsThemsManager();
    ~LabsThemsManager();

    void updateManager();
    QList<Theme> thems();

    Theme* getTheme(int id);
    Field* getField(int id);

    int getThemeIdFromPosition(int index);
    int getFieldIdFromPosition(int index);

    void changeField(int fieldId, Field field);
    void deleteField(int fieldId);
    void addField(Field field);

    void changeTheme(int themeId, Theme theme);
    void deleteTheme(int themeId);
    void addTheme(Theme theme);
    Theme* creationTheme;
};

#endif // LABSTHEMSMANAGER_H
