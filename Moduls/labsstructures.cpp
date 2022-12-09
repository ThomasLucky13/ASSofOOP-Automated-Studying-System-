#include "labsstructures.h"


// ============================= Field ============================= //
Field::Field()
{
    id = -1;
    name = "";
    isRequired = false;
    methods = QList<QString>();
}
Field::Field(int _id)
{
    id = _id;
    name = "";
    isRequired = false;
    methods = QList<QString>();
}
Field::Field(int _id, QString _name)
{
    id = _id;
    name = _name;
    isRequired = false;
    methods = QList<QString>();
}
Field::Field (int _id, QString _name, bool _isRequired)
{
    id = _id;
    name = _name;
    isRequired = _isRequired;
    methods = QList<QString>();
}
Field::Field (int _id, QString _name, bool _isRequired, QList<QString> _methods)
{
    id = _id;
    name = _name;
    isRequired = _isRequired;
    methods = _methods;
}
Field::Field (int _id, Field _other)
{
    id = _id;
    name = _other.name;
    isRequired = _other.IsRequired();
    methods = _other.Methods();
}

Field::~Field()
{

}

void Field::setId(int _id)
{
    id=_id;
}
void Field::setName(QString _name)
{
    name = _name;
}
void Field::setRequired(bool _isRequired)
{
    isRequired = _isRequired;
}
void Field::setMethods(QList<QString> _methods)
{
    methods = _methods;
}
void Field::addMethod(QString _method)
{
    methods.push_back(_method);
}

void Field::setMethod(int index, QString _method)
{
    if (index >= methods.count()) return;
    methods[index] = _method;
}

void Field::deleteMethod(int index)
{
    methods.removeAt(index);
}

int Field::Id()
{
    return id;
}
QString Field::Name()
{
    return name;
}
bool Field::IsRequired()
{
    return isRequired;
}
QList<QString> Field::Methods()
{
    return methods;
}

QString Field::getMethod(int i)
{
    if(i<methods.length())
    {
        return (methods[i]);
    }
    return ("NotFounded");
}
int Field::methodsCount()
{
    return methods.length();
}

//===================================================================//


// ============================= Theme ============================= //

Theme::Theme()
{
    id = -1;
    name = "";
    isDeletable = true;
    isUsable = false;
    fields = QList<Field>();
    friendsThems = QList<int>();
}
Theme::Theme(int _id)
{
    id = _id;
    name = "";
    isDeletable = true;
    isUsable = false;
    fields = QList<Field>();
    friendsThems = QList<int>();
}
Theme::Theme(int _id, QString _name)
{
    id = _id;
    name = _name;
    isDeletable = true;
    isUsable = false;
    fields = QList<Field>();
    friendsThems = QList<int>();
}
Theme::Theme(int _id, QString _name, bool _isDeletable)
{
    id = _id;
    name = _name;
    isDeletable = _isDeletable;
    isUsable = false;
    fields = QList<Field>();
    friendsThems = QList<int>();
}
Theme::Theme(int _id, QString _name, bool _isDeletable, bool _isUsable)
{
    id = _id;
    name = _name;
    isDeletable = _isDeletable;
    isUsable = _isUsable;
    fields = QList<Field>();
    friendsThems = QList<int>();
}
Theme::Theme(int _id, QString _name, bool _isDeletable, bool _isUsable, QList<Field> _fields)
{
    id = _id;
    name = _name;
    isDeletable = _isDeletable;
    isUsable = _isUsable;
    fields = _fields;
    friendsThems = QList<int>();
}
Theme::Theme(int _id, QString _name, bool _isDeletable, bool _isUsable, QList<Field> _fields, QList<int> _friendsThems)
{
    id = _id;
    name = _name;
    isDeletable = _isDeletable;
    isUsable = _isUsable;
    fields = _fields;
    friendsThems = _friendsThems;
}
Theme::Theme(int _id, Theme _other)
{
    id = _id;
    name = _other.name;
    isDeletable = _other.IsDeletavle();
    isUsable = _other.IsUsable();
    fields = _other.Fields();
    friendsThems = _other.FriendsThems();
}
Theme::~Theme()
{

}

void Theme::setId(int _id)
{
    id = _id;
}
void Theme::setName(QString _name)
{

    name = _name;
}
void Theme::setDeletable(bool _isDeletable)
{

    isDeletable = _isDeletable;
}
void Theme::setUsable(bool _isUsable)
{
    isUsable = _isUsable;
}
void Theme::setFields(QList<Field> _fields)
{
    fields = _fields;
}
void Theme::setFriendsThems(QList<int> _friendsThems)
{
    friendsThems = _friendsThems;
}
void Theme::addField(Field _field)
{
    fields.push_back(_field);
}
void Theme::addFriendTheme(int _i)
{
    friendsThems.push_back(_i);
}
void Theme::changeField(int fieldIndex, Field field)
{
    fields[fieldIndex] = field;
}
void Theme::deleteField(int _i)
{
    fields.removeAt(_i);
}
int Theme::Id()
{
    return id;
}
QString Theme::Name()
{
    return name;
}
bool Theme::IsDeletavle()
{
    return isDeletable;
}
bool Theme::IsUsable()
{
    return isUsable;
}
QList<Field> Theme::Fields()
{
    return fields;
}
QList<int> Theme::FriendsThems()
{
    return friendsThems;
}
Field Theme::getField(int i)
{
    if (i < fields.length())
    {
        return fields[i];
    }
    return Field(-1, "NotFounded", false);
}
int Theme::getFriendThemeId(int i)
{
    if (i<friendsThems.length())
    {
        return friendsThems[i];
    }
    return -1;
}
int Theme::fieldsCount()
{
    return fields.length();
}
int Theme::friendsThemsCount()
{
    return friendsThems.length();
}

//===================================================================//
