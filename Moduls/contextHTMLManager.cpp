#include "contextHTMLManager.h"
#include <QFile>
#include <iostream>

contextHTMLManager::contextHTMLManager()
{
    readContext();
}

void contextHTMLManager::readContext()
{
    QFile contextFile(":/theoryMaterials/context.txt");
    contextFile.open(QIODevice::ReadOnly);
    QString contextText = contextFile.readAll();
    contextFile.close();
    QStringList contextStrings = contextText.split("\n");
    for (int i = 0 ; i < contextStrings.length(); ++i)
    {
        if(!contextStrings[i].isEmpty())
        {
            QStringList chapter = contextStrings[i].split("file:");
            if(chapter.length()>1)
            {
                chapters.push_back(chapterData(chapter[0], chapter[1]));
            }
        }
    }
}

void contextHTMLManager::setHTMLText(QString fileName)
{
    QFile contextFile(fileName);
    contextFile.open(QIODevice::ReadOnly);
    htmlText = contextFile.readAll();
    contextFile.close();
}

void contextHTMLManager::setChapter(int i)
{
    setHTMLText(chapters[i].fileName);
}
