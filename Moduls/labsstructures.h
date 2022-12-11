#ifndef LABSSTRUCTURES_H
#define LABSSTRUCTURES_H

#include <QString>
#include <QList>

struct Field
{
private:
    QString id;
    QString name;
    bool isRequired;
    QList<QString> methods;

public:
    Field();
    Field(QString _id);
    Field(QString _id, QString _name);
    Field (QString _id, QString _name, bool _isRequired);
    Field (QString _id, QString _name, bool _isRequired, QList<QString> _methods);
    Field (QString _id, Field _other);
    ~Field();

    void setId(QString _id);
    void setName(QString _name);
    void setRequired(bool _isRequired);
    void setMethods(QList<QString> _methods);
    void addMethod(QString _method);
    void setMethod(int index, QString _method);
    void deleteMethod(int index);

    QString Id();
    QString Name();
    bool IsRequired();
    QList<QString> Methods();
    QString getMethod(int i);
    int methodsCount();
};

struct Theme
{
private:
    QString id;
    QString name;
    bool isDeletable;
    bool isUsable;
    QList<Field> fields;
    QList<QString> friendsThems;

public:
    Theme();
    Theme(QString _id);
    Theme(QString _id, QString _name);
    Theme(QString _id, QString _name, bool _isDeletable);
    Theme(QString _id, QString _name, bool _isDeletable, bool _isUsable);
    Theme(QString _id, QString _name, bool _isDeletable, bool _isUsable, QList<Field> _fields);
    Theme(QString _id, QString _name, bool _isDeletable, bool _isUsable, QList<Field> _fields, QList<QString> _friendsThems);
    Theme(QString _id, Theme _other);
    ~Theme();

    void setId(QString _id);
    void setName(QString _name);
    void setDeletable(bool _isDeletable);
    void setUsable(bool _isUsable);
    void setFields(QList<Field> _fields);
    void setFriendsThems(QList<QString> _friendsThems);
    void addField(Field _field);
    void changeField(int fieldIndex, Field field);
    void deleteField(int _i);
    void addFriendTheme(QString _id);
    void deleteFriendTheme(QString _id);

    QString Id();
    QString Name();
    bool IsDeletable();
    bool IsUsable();
    QList<Field> Fields();
    QList<QString> FriendsThems();
    Field getField(int i);
    QString getFriendThemeId(int i);
    int fieldsCount();
    int friendsThemsCount();

};
#endif // LABSSTRUCTURES_H
