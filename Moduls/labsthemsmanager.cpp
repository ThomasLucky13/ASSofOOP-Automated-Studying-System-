#include "labsthemsmanager.h"
#include <QtCore>
#include <QUuid>
#include "Moduls/databasemanager.h"

LabsThemsManager::LabsThemsManager()
{
    getThemsFromDatabase();
    creationTheme = new Theme("-1");
}

LabsThemsManager::~LabsThemsManager()
{
    DatabaseManager().WriteThems(thems());
    delete creationTheme;
}

void LabsThemsManager::getThemsFromDatabase()
{
    QList<Theme> thems = DatabaseManager().ReadThems();

    usedThems.clear();
    unusedThems.clear();
    for (int i = 0 ; i < thems.count(); ++i)
    {
        if (thems[i].IsUsable())
        {
            usedThems.push_back(thems[i]);
        }else
        {
            unusedThems.push_back(thems[i]);
        }
    }
}
QList<Theme> LabsThemsManager::thems()
{
    QList<Theme> res = usedThems;
    res.append(unusedThems);
    return res;
}

Theme * LabsThemsManager::getTheme(QString id)
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

int LabsThemsManager::usedThemsIndex(QString id)
{
    for (int i = 0; i < usedThems.count(); ++i)
    {
        if (usedThems[i].Id()==id)
            return i;
    }
    return -1;
}
int LabsThemsManager::unusedThemsIndex(QString id)
{
    for (int i = 0; i < unusedThems.count(); ++i)
    {
        if (unusedThems[i].Id()==id)
            return i;
    }
    return -1;
}

int LabsThemsManager::getFieldIndex(Theme* theme, QString id)
{
    for (int i = 0; i < theme->fieldsCount(); ++i)
    {
        if (theme->Fields()[i].Id() == id)
            return i;
    }
    return -1;
}

QString LabsThemsManager::getThemeIdFromPosition(int index)
{
    if (index<usedThems.count())
    {
        return usedThems[index].Id();
    }
    return unusedThems[index-usedThems.count()].Id();
}

QString LabsThemsManager::getFieldIdFromPosition(int index)
{
    if(creationTheme->Fields().count() > index)
    {
        return creationTheme->Fields()[index].Id();
    } else
    {
        return "-1";
    }
}

Field* LabsThemsManager::getField(QString id)
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

void LabsThemsManager::changeField(QString fieldId, Field field)
{
    int fieldIndex = getFieldIndex(creationTheme, fieldId);
    creationTheme->changeField(fieldIndex, field);
}

void LabsThemsManager::deleteField(QString fieldId)
{
    int fieldIndex = getFieldIndex(creationTheme, fieldId);
    creationTheme->deleteField(fieldIndex);
}

void LabsThemsManager::addField(Field field)
{
    field.setId(QUuid().createUuid().toString());
    creationTheme->addField(field);
}

QString LabsThemsManager::generateFieldId(Theme theme)
{
    if(theme.Fields().count()==0) return 0;
    return QString::number(theme.Fields().last().Id().toInt()+1);
}

void LabsThemsManager::changeTheme(QString themeId, Theme theme)
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

void LabsThemsManager::deleteTheme(QString themeId)
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
    changeFriendsThems(themeId, QList<QString>());
}

void LabsThemsManager::addTheme(Theme theme)
{
    //theme.setId(generateThemeId());
    theme.setId(QUuid().createUuid().toString());
    if (theme.IsUsable())
    {
        usedThems.push_back(theme);
    } else
    {
        unusedThems.push_back(theme);
    }
    changeFriendsThems(theme.Id(), theme.FriendsThems());
}

QString LabsThemsManager::generateThemeId()
{
    int res=0;
    for (int i = 0; i < usedThems.count(); ++i)
    {
        if (usedThems[i].Id().toInt()>res)
        {
            res = usedThems[i].Id().toInt();
        }
    }
    for (int i = 0; i < unusedThems.count(); ++i)
    {
        if(unusedThems[i].Id().toInt()>res)
        {
            res = unusedThems[i].Id().toInt();
        }
    }
    return QString::number(res+1);
}

void LabsThemsManager::changeFriendsThems(QString themeId, QList<QString> friendsThems)
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
