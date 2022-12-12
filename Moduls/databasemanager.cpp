#include "databasemanager.h"
#include <QFile>
#include <QJsonDocument>
#include <QCborMap>
#include <QJsonArray>
#include <QDir>
#include <QtCore>

DatabaseManager::DatabaseManager()
{
    themsDatabaseFileName = QDir().absolutePath()+ "/resources/labsMaterials/labsDatabase.dat";
}

QJsonObject DatabaseManager::getJsonObjectFromFile(QString fileName)
{
    QFile loadFile(fileName);
    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return QJsonObject();
    }

    QByteArray saveData = loadFile.readAll();
    loadFile.close();
    QJsonDocument loadDoc(QJsonDocument(QCborValue::fromCbor(saveData).toMap().toJsonObject()));
    return loadDoc.object();
}

void DatabaseManager::writeJsonObjectToFile(QJsonObject json, QString fileName)
{
    QFile saveFile(fileName);

    if (saveFile.exists())
    {
        if (!saveFile.open(QIODevice::WriteOnly)) {
            qWarning("Couldn't open save file.");
            return;
        }
    } else
    {
        saveFile.open(QIODevice::WriteOnly | QIODevice::Text);
    }
    saveFile.write(QCborValue::fromJsonValue(json).toCbor());
    saveFile.close();

}

QList<Theme> DatabaseManager::ReadThems()
{
    QList<Theme> thems;
    QJsonObject json = getJsonObjectFromFile(themsDatabaseFileName);

    if (json.contains("Thems") && json["Thems"].isArray()) {
        QJsonArray themsArray = json["Thems"].toArray();
        for (int themeIndex = 0; themeIndex < themsArray.size(); ++themeIndex)
        {
            QJsonObject themeObject = themsArray[themeIndex].toObject();
            if (themeObject.contains("id") && themeObject["id"].isString())
            {
                Theme theme = Theme(themeObject["id"].toString());
                if (themeObject.contains("name") && themeObject["name"].isString())
                {
                    theme.setName(themeObject["name"].toString());
                }
                if (themeObject.contains("isDeletable") && themeObject["isDeletable"].isBool())
                {
                    theme.setDeletable(themeObject["isDeletable"].toBool());
                }
                if(themeObject.contains("isUsable") && themeObject["isUsable"].isBool())
                {
                    theme.setUsable(themeObject["isUsable"].toBool());
                }
                if(themeObject.contains("fields") && themeObject["fields"].isArray())
                {
                    QList<Field> fields;
                    QJsonArray fieldsArray = themeObject["fields"].toArray();
                    for (int fieldIndex = 0; fieldIndex < fieldsArray.count(); ++fieldIndex)
                    {
                        QJsonObject fieldObject = fieldsArray[fieldIndex].toObject();
                        if(fieldObject.contains("id") && fieldObject["id"].isString())
                        {
                            Field field = Field(fieldObject["id"].toString());
                            if(fieldObject.contains("name") && fieldObject["name"].isString())
                            {
                                field.setName(fieldObject["name"].toString());
                            }
                            if(fieldObject.contains("type") && fieldObject["type"].isDouble())
                            {
                                int typeIndex = fieldObject["type"].toInt();
                                switch(typeIndex)
                                {
                                case fieldType::type_integer:
                                    field.setType(fieldType::type_integer);
                                    break;
                                case fieldType::type_unsigned:
                                    field.setType(fieldType::type_unsigned);
                                    break;
                                case fieldType::type_float:
                                    field.setType(fieldType::type_float);
                                    break;
                                case fieldType::type_string:
                                    field.setType(fieldType::type_string);
                                    break;
                                }
                            }
                            if(fieldObject.contains("isRequired") && fieldObject["isRequired"].isBool())
                            {
                                field.setRequired(fieldObject["isRequired"].toBool());
                            }
                            if(fieldObject.contains("methods") && fieldObject["methods"].isArray())
                            {
                                QJsonArray methodsArray = fieldObject["methods"].toArray();
                                for (int methodIndex = 0; methodIndex < methodsArray.count(); ++methodIndex)
                                {
                                    QJsonObject methodObject = methodsArray[methodIndex].toObject();
                                    if(methodObject.contains("text") && methodObject["text"].isString())
                                    {
                                        field.addMethod(methodObject["text"].toString());
                                    }
                                }
                            }
                            fields.push_back(field);
                        }
                    }
                    theme.setFields(fields);
                }
                if(themeObject.contains("friendsThems") && themeObject["friendsThems"].isArray())
                {
                    QJsonArray friendsThemsArray = themeObject["friendsThems"].toArray();
                    for (int friendsThemeIndex = 0; friendsThemeIndex < friendsThemsArray.count(); ++friendsThemeIndex)
                    {
                        QJsonObject friendFieldObject = friendsThemsArray[friendsThemeIndex].toObject();
                        if(friendFieldObject.contains("id") && friendFieldObject["id"].isString())
                        {
                            theme.addFriendTheme(friendFieldObject["id"].toString());
                        }
                    }
                }
                thems.push_back(theme);
            }

        }
    }
    return thems;
}

void DatabaseManager::WriteThems(QList<Theme> thems)
{
    QJsonObject json;

    QJsonArray themsArray;

    for (Theme theme : thems)
    {
        QJsonObject themeObject;

        themeObject["id"] = theme.Id();
        themeObject["name"] = theme.Name();
        themeObject["isDeletable"] = theme.IsDeletable();
        themeObject["isUsable"] = theme.IsUsable();

        QJsonArray fieldsArray;
        for (Field field : theme.Fields())
        {
            QJsonObject fieldObject;

            fieldObject["id"] = field.Id();
            fieldObject["name"] = field.Name();
            fieldObject["type"] = field.Type();
            fieldObject["isRequired"] = field.IsRequired();

            QJsonArray methodsArray;
            for(QString method : field.Methods())
            {
                QJsonObject methodObject;
                methodObject["text"] = method;
                methodsArray.append(methodObject);
            }
            fieldObject["methods"] = methodsArray;

            fieldsArray.append(fieldObject);
        }
        themeObject["fields"] = fieldsArray;

        QJsonArray friendsThemsArray;
        for (QString friendsThemeId : theme.FriendsThems())
        {
            QJsonObject friendsThemeObject;
            friendsThemeObject["id"] = friendsThemeId;
            friendsThemsArray.append(friendsThemeObject);
        }
        themeObject["friendsThems"] = friendsThemsArray;

        themsArray.append(themeObject);
    }
    json["Thems"] = themsArray;

    writeJsonObjectToFile(json, themsDatabaseFileName);
}
