#include "labsstructures.h"


// ============================= Field ============================= //
Field::Field()
{
    id = "-1";
    name = "";
    type = fieldType::type_string;
    isRequired = false;
    methods = QList<QString>();
}
Field::Field(QString _id)
{
    id = _id;
    name = "";
    type = fieldType::type_string;
    isRequired = false;
    methods = QList<QString>();
}
Field::Field(QString _id, QString _name)
{
    id = _id;
    name = _name;
    type = fieldType::type_string;
    isRequired = false;
    methods = QList<QString>();
}
Field::Field(QString _id, QString _name, fieldType::Enum _type)
{
    id = _id;
    name = _name;
    type = _type;
    isRequired = false;
    methods = QList<QString>();
}
Field::Field (QString _id, QString _name, fieldType::Enum _type, bool _isRequired)
{
    id = _id;
    name = _name;
    type = _type;
    isRequired = _isRequired;
    methods = QList<QString>();
}
Field::Field (QString _id, QString _name, fieldType::Enum _type, bool _isRequired, QList<QString> _methods)
{
    id = _id;
    name = _name;
    type = _type;
    isRequired = _isRequired;
    methods = _methods;
}
Field::Field (QString _id, Field _other)
{
    id = _id;
    name = _other.name;
    type = _other.type;
    isRequired = _other.IsRequired();
    methods = _other.Methods();
}

Field::~Field()
{

}

void Field::setId(QString _id)
{
    id=_id;
}
void Field::setName(QString _name)
{
    name = _name;
}
void Field::setType(fieldType::Enum _type)
{
    type = _type;
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

QString Field::Id()
{
    return id;
}
QString Field::Name()
{
    return name;
}
fieldType::Enum Field::Type()
{
    return type;
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
    id = "-1";
    name = "";
    isDeletable = true;
    isUsable = false;
    fields = QList<Field>();
    friendsThems = QList<QString>();
}
Theme::Theme(QString _id)
{
    id = _id;
    name = "";
    isDeletable = true;
    isUsable = false;
    fields = QList<Field>();
    friendsThems = QList<QString>();
}
Theme::Theme(QString _id, QString _name)
{
    id = _id;
    name = _name;
    isDeletable = true;
    isUsable = false;
    fields = QList<Field>();
    friendsThems = QList<QString>();
}
Theme::Theme(QString _id, QString _name, bool _isDeletable)
{
    id = _id;
    name = _name;
    isDeletable = _isDeletable;
    isUsable = false;
    fields = QList<Field>();
    friendsThems = QList<QString>();
}
Theme::Theme(QString _id, QString _name, bool _isDeletable, bool _isUsable)
{
    id = _id;
    name = _name;
    isDeletable = _isDeletable;
    isUsable = _isUsable;
    fields = QList<Field>();
    friendsThems = QList<QString>();
}
Theme::Theme(QString _id, QString _name, bool _isDeletable, bool _isUsable, QList<Field> _fields)
{
    id = _id;
    name = _name;
    isDeletable = _isDeletable;
    isUsable = _isUsable;
    fields = _fields;
    friendsThems = QList<QString>();
}
Theme::Theme(QString _id, QString _name, bool _isDeletable, bool _isUsable, QList<Field> _fields, QList<QString> _friendsThems)
{
    id = _id;
    name = _name;
    isDeletable = _isDeletable;
    isUsable = _isUsable;
    fields = _fields;
    friendsThems = _friendsThems;
}
Theme::Theme(QString _id, Theme _other)
{
    id = _id;
    name = _other.name;
    isDeletable = _other.IsDeletable();
    isUsable = _other.IsUsable();
    fields = _other.Fields();
    friendsThems = _other.FriendsThems();
}
Theme::~Theme()
{

}

void Theme::setId(QString _id)
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
void Theme::setFriendsThems(QList<QString> _friendsThems)
{
    friendsThems = _friendsThems;
}
void Theme::addField(Field _field)
{
    fields.push_back(_field);
}
void Theme::changeField(int fieldIndex, Field field)
{
    fields[fieldIndex] = field;
}
void Theme::deleteField(int _i)
{
    fields.removeAt(_i);
}
QString Theme::Id()
{
    return id;
}
QString Theme::Name()
{
    return name;
}
bool Theme::IsDeletable()
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
QList<QString> Theme::FriendsThems()
{
    return friendsThems;
}
Field Theme::getField(int i)
{
    if (i < fields.length())
    {
        return fields[i];
    }
    return Field("-1", "NotFounded", fieldType::type_string, false);
}
QString Theme::getFriendThemeId(int i)
{
    if (i<friendsThems.length())
    {
        return friendsThems[i];
    }
    return "-1";
}
int Theme::fieldsCount()
{
    return fields.length();
}
int Theme::friendsThemsCount()
{
    return friendsThems.length();
}
void Theme::addFriendTheme(QString _id)
{
    if(friendsThems.contains(_id)) return;
    friendsThems.push_back(_id);
}
void Theme::deleteFriendTheme(QString _id)
{
    if(friendsThems.contains(_id)) friendsThems.removeAll(_id);
}
//===================================================================//

// ============================== Task ============================= //
Task::Task()
{
    id = "-1";
    name = "";
    text = "";
}
Task::Task(QString _id)
{
    id = _id;
    name = "";
    text = "";
}
Task::Task(QString _id, QString _name)
{
    id = _id;
    name = _name;
    text = "";
}
Task::Task(QString _id, QString _name, QString _text)
{
    id = _id;
    name = _name;
    text = _text;
}
Task::Task(const Task & _other)
{
    id = _other.id;
    name = _other.name;
    text = _other.text;
}
void Task::setId(QString _id)
{
    id = _id;
}
void Task::setName(QString _name)
{
    name = _name;
}
void Task::setText(QString _text)
{
    text = _text;
}

QString Task::Id()
{
    return id;
}
QString Task::Name()
{
    return name;
}
QString Task::Text()
{
    return text;
}
//===================================================================//
