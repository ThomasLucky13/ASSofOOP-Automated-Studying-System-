#include "labgenerationmanager.h"
#include <QtCore>
labGenerationManager::labGenerationManager()
{

}
labGenerationManager::labGenerationManager(Task _task, LabsThemsManager* themsManager)
{
    task = _task;
    mThemsManager = themsManager;
}

QString labGenerationManager::generateLabHTML(int _width)
{
    qWarning()<<_width;
    QString HTMLtext = "<!DOCTYPE html><html><style>div {width: "+QString::number(_width-30)+"px;}div.a {word-wrap: break-word;}</style><body>";
    HTMLtext += "<center><h1>" + task.Name() + "</h1></center>";
    HTMLtext += "<div class = \"a\">" + task.Text() + "</div>";

    for (int i = 0; i < 10; ++i)
    {
        HTMLtext += "<P><div><text><b>";
        HTMLtext += "Вариант №" +QString::number(i+1)+ "</b></text></div>";
        HTMLtext += "<text><u> Поля: </u></text>";

        for (int j = 0; j < 5; ++j)
        {
            QString fieldString;
            fieldString = "Поле " + QString::number(j);
            HTMLtext += "<div class = \"a\" >" + fieldString+ "</div>";
        }
        QString methodsString;
        methodsString = "Куча Куча методов. Всех их надо реализовать. Ничего нельзя забыть.";
        methodsString += "Да. Даже про инит-функцию нельзя забыть и конструктор.";
        methodsString +=  "И да... Инит функция должна быть приватной как и полня.";
        methodsString +=  "А остальные функции публичными.";
        HTMLtext += "<text><u> Методы: </u></text>";
        HTMLtext += "<div class = \"a\">" + methodsString+ "</div>";
        HTMLtext+="</P>";
    }
    HTMLtext += "</body></html>";
    return HTMLtext;
}
