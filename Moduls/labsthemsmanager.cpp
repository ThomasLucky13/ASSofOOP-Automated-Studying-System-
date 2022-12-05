#include "labsthemsmanager.h"
#include <iostream>

LabsThemsManager::LabsThemsManager()
{
    updateManager();
}

void LabsThemsManager::updateManager()
{
    QList <QString> methods;
    for (int i = 0; i < 5; ++i)
    {
        methods.push_back("Method " + QString::number(i));
    }
    QList<Field> fields;
    for (int i = 0; i < 5; ++i)
    {
        fields.push_back(Field(i, "Field " + QString::number(i), true, methods));
    }
    for (int i = 0; i <5; ++i)
    {
        usedThems.push_back(Theme(i, "Theme " + QString::number(i), false, true, fields));
    }

    for (int i = 5; i <10; ++i)
    {
        unusedThems.push_back(Theme(i, "Theme " + QString::number(i), false, false, fields));
    }
}
QList<Theme> LabsThemsManager::thems()
{
    QList<Theme> res = usedThems;
    res.append(unusedThems);
    return res;
}

Theme * LabsThemsManager::getTheme(int id)
{
    for (int i = 0; i < usedThems.count(); ++i)
    {
        if (usedThems[i].Id() == id)
        {
            return new Theme(id, usedThems[i]);
        }
    }
    for (int i = 0; i < unusedThems.count(); ++i)
    {
        if (unusedThems[i].Id() == id)
        {
            return new Theme(id, unusedThems[i]);
        }
    }
    return NULL;
}

int LabsThemsManager::usedThemsIndex(int id)
{
    for (int i = 0; i < usedThems.count(); ++i)
    {
        if (usedThems[i].Id()==id)
            return i;
    }
    return -1;
}
int LabsThemsManager::unusedThemsIndex(int id)
{
    for (int i = 0; i < unusedThems.count(); ++i)
    {
        if (unusedThems[i].Id()==id)
            return i;
    }
    return -1;
}

int LabsThemsManager::getFieldIndex(Theme theme, int id)
{
    for (int i = 0; i < theme.fieldsCount(); ++i)
    {
        if (theme.Fields()[i].Id() == id)
            return i;
    }
    return -1;
}

void LabsThemsManager::changeThemeUsable(int id, bool usable)
{
    if (usable) //Если тема теперь используется
    {
        int index = unusedThemsIndex(id);  //ищем тему среди неиспользуемых
        if (index == -1) return;
        Theme theme = unusedThems[index];
        theme.setUsable(true);
        unusedThems.removeAt(index);
        usedThems.push_back(theme);

    } else              //Если тема теперь не используется
    {
        int index = usedThemsIndex(id);   //ищем тему среди используемых
        if (index == -1) return;
        Theme theme = usedThems[index];
        theme.setUsable(false);
        usedThems.removeAt(index);
        unusedThems.push_back(theme);
    }
}

int LabsThemsManager::getThemeIdFromPosition(int index)
{
    if (index<usedThems.count())
    {
        return usedThems[index].Id();
    }
    return unusedThems[index-usedThems.count()].Id();
}

int LabsThemsManager::getFieldIdFromPosition(int index, int themeId)
{
    Theme* theme = getTheme(themeId);
    return theme->Fields()[index].Id();
}

Field* LabsThemsManager::getField(int themeId, int id)
{
    Theme* theme = getTheme(themeId);

    if (theme != NULL)
    {
        for (int i = 0; i < theme->Fields().count(); ++i)
        {
            if (theme->Fields()[i].Id() == id)
            {
                return new Field(id, theme->Fields()[i]);
            }
        }
    }
    return NULL;
}

void LabsThemsManager::changeField(int themeId, int fieldId, Field field)
{
    int themeIndex = unusedThemsIndex(themeId);  //ищем тему среди неиспользуемых
    if (themeIndex == -1)
    {
        themeIndex = usedThemsIndex(themeId);
        if (themeIndex == -1)
            return;
        int fieldIndex = getFieldIndex(usedThems[themeIndex], fieldId);
        usedThems[themeIndex].changeField(fieldIndex, field);
    } else
    {
        int fieldIndex = getFieldIndex(unusedThems[themeIndex], fieldId);
        unusedThems[themeIndex].changeField(fieldIndex, field);
    }
}
