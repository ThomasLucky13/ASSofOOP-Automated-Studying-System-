#ifndef LABSSTRUCTURES_H
#define LABSSTRUCTURES_H

#include <QString>
#include <QList>

struct Field
{
private:
    int id;
    QString name;
    bool isRequired;
    QList<QString> methods;

public:
    Field();
    Field(int _id);
    Field(int _id, QString _name);
    Field (int _id, QString _name, bool _isRequired);
    Field (int _id, QString _name, bool _isRequired, QList<QString> _methods);
    Field (int _id, Field _other);
    ~Field();

    void setId(int _id);
    void setName(QString _name);
    void setRequired(bool _isRequired);
    void setMethods(QList<QString> _methods);
    void addMethod(QString _method);

    int Id();
    QString Name();
    bool IsRequired();
    QList<QString> Methods();
    QString getMethod(int i);
    int methodsCount();
};

struct Theme
{
private:
    int id;
    QString name;
    bool isDeletable;
    bool isUsable;
    QList<Field> fields;
    QList<int> friendsThems;

public:
    Theme();
    Theme(int _id);
    Theme(int _id, QString _name);
    Theme(int _id, QString _name, bool _isDeletable);
    Theme(int _id, QString _name, bool _isDeletable, bool _isUsable);
    Theme(int _id, QString _name, bool _isDeletable, bool _isUsable, QList<Field> _fields);
    Theme(int _id, QString _name, bool _isDeletable, bool _isUsable, QList<Field> _fields, QList<int> _friendsThems);
    Theme(int _id, Theme _other);
    ~Theme();

    void setId(int _id);
    void setName(QString _name);
    void setDeletable(bool _isDeletable);
    void setUsable(bool _isUsable);
    void setFields(QList<Field> _fields);
    void setFriendsThems(QList<int> _friendsThems);
    void addField(Field _field);
    void addFriendTheme(int _i);
    void changeField(int fieldIndex, Field field);

    int Id();
    QString Name();
    bool IsDeletavle();
    bool IsUsable();
    QList<Field> Fields();
    QList<int> FriendsThems();
    Field getField(int i);
    int getFriendThemeId(int i);
    int fieldsCount();
    int friendsThemsCount();

};
#endif // LABSSTRUCTURES_H
