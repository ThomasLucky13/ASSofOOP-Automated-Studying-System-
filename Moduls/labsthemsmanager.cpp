#include "labsthemsmanager.h"
#include <iostream>

LabsThemsManager::LabsThemsManager()
{
    updateManager();
}

LabsThemsManager::~LabsThemsManager()
{
    delete creationTheme;
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

int LabsThemsManager::getFieldIndex(Theme* theme, int id)
{
    for (int i = 0; i < theme->fieldsCount(); ++i)
    {
        if (theme->Fields()[i].Id() == id)
            return i;
    }
    return -1;
}

int LabsThemsManager::getThemeIdFromPosition(int index)
{
    if (index<usedThems.count())
    {
        return usedThems[index].Id();
    }
    return unusedThems[index-usedThems.count()].Id();
}

int LabsThemsManager::getFieldIdFromPosition(int index)
{
    if(creationTheme->Fields().count() > index)
    {
        return creationTheme->Fields()[index].Id();
    } else
    {
        return -1;
    }
}

Field* LabsThemsManager::getField(int id)
{
    for (int i = 0; i < creationTheme->Fields().count(); ++i)
    {
        if (creationTheme->Fields()[i].Id() == id)
        {
            return new Field(id, creationTheme->Fields()[i]);
        }
    }
    return NULL;
}

void LabsThemsManager::changeField(int fieldId, Field field)
{
    int fieldIndex = getFieldIndex(creationTheme, fieldId);
    creationTheme->changeField(fieldIndex, field);
}

void LabsThemsManager::deleteField(int fieldId)
{
    int fieldIndex = getFieldIndex(creationTheme, fieldId);
    creationTheme->deleteField(fieldIndex);
}

void LabsThemsManager::addField(Field field)
{
    creationTheme->addField(field);
}

int LabsThemsManager::generateFieldId(Theme theme)
{
    if(theme.Fields().count()==0) return 0;
    return theme.Fields().last().Id()+1;
}

void LabsThemsManager::changeTheme(int themeId, Theme theme)
{
    int themeIndex = unusedThemsIndex(themeId);  //ищем тему среди неиспользуемых
    if (themeIndex == -1)
    {
        themeIndex = usedThemsIndex(themeId);
        if (themeIndex == -1)
        {
            return;
        }
        if(theme.IsUsable())
        {
            usedThems[themeIndex] = theme;
        } else
        {
            usedThems.removeAt(themeIndex);
            unusedThems.push_back(theme);
        }
    } else
    {
        if(theme.IsUsable())
        {
            unusedThems.removeAt(themeIndex);
            usedThems.push_back(theme);
        } else
        {
            unusedThems[themeIndex] = theme;
        }
    }
    changeFriendsThems(themeId, theme.FriendsThems());
}

void LabsThemsManager::deleteTheme(int themeId)
{
    int themeIndex = unusedThemsIndex(themeId);  //ищем тему среди неиспользуемых
    if (themeIndex == -1)
    {
        themeIndex = usedThemsIndex(themeId);
        if (themeIndex == -1)
            return;
        usedThems.removeAt(themeIndex);
    } else
    {
        unusedThems.removeAt(themeIndex);
    }
    changeFriendsThems(themeId, QList<int>());
}

void LabsThemsManager::addTheme(Theme theme)
{
    theme.setId(generateThemeId());
    if (theme.IsUsable())
    {
        usedThems.push_back(theme);
    } else
    {
        unusedThems.push_back(theme);
    }
    changeFriendsThems(theme.Id(), theme.FriendsThems());
}

int LabsThemsManager::generateThemeId()
{
    int res=0;
    for (int i = 0; i < usedThems.count(); ++i)
    {
        if (usedThems[i].Id()>res)
        {
            res = usedThems[i].Id();
        }
    }
    for (int i = 0; i < unusedThems.count(); ++i)
    {
        if(unusedThems[i].Id()>res)
        {
            res = unusedThems[i].Id();
        }
    }
    return res+1;
}

void LabsThemsManager::changeFriendsThems(int themeId, QList<int> friendsThems)
{
    for (int i = 0; i < usedThems.count(); ++i)
    {
        if (friendsThems.contains(usedThems[i].Id()))
        {
            usedThems[i].addFriendTheme(themeId);
        } else
        {
            usedThems[i].deleteFriendTheme(themeId);
        }
    }

    for(int i = 0; i < unusedThems.count(); ++i)
    {
        if (friendsThems.contains(unusedThems[i].Id()))
        {
            unusedThems[i].addFriendTheme(themeId);
        } else
        {
           unusedThems[i].deleteFriendTheme(themeId);
        }
    }
}
