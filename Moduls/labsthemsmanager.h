#ifndef LABSTHEMSMANAGER_H
#define LABSTHEMSMANAGER_H

#include "labsstructures.h"
#include <QList>

class LabsThemsManager
{
private:
    QList <Theme> usedThems;
    QList <Theme> unusedThems;

    int usedThemsIndex(QString id);
    int unusedThemsIndex(QString id);
    int getFieldIndex(Theme* theme, QString id);
    QString generateFieldId(Theme theme);
    QString generateThemeId();

    void changeFriendsThems(QString themeId, QList<QString> friendsThems);


public:
    LabsThemsManager();
    ~LabsThemsManager();

    void getThemsFromDatabase();
    QList<Theme> thems();
    QList<Theme> getUsedThems();

    Theme* getTheme(QString id);
    Field* getField(QString id);

    QString getThemeIdFromPosition(int index);
    QString getFieldIdFromPosition(int index);

    void changeField(QString fieldId, Field field);
    void deleteField(QString fieldId);
    void addField(Field field);

    void changeTheme(QString themeId, Theme theme);
    void deleteTheme(QString themeId);
    void addTheme(Theme theme);
    Theme* creationTheme;
};

#endif // LABSTHEMSMANAGER_H
