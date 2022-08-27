#ifndef CONTEXTHTMLMANAGER_H
#define CONTEXTHTMLMANAGER_H
#include <QString>
#include <QList>

struct chapterData
{
public:
    QString name;
    QString fileName;
    chapterData(QString _name, QString _fileName)
    {
        name = _name;
        fileName = _fileName;
    }
};

class contextHTMLManager
{
public:
    contextHTMLManager();

private:
    QString htmlText;
    QList<chapterData> chapters;

protected:
    void readContext();
    void setHTMLText(QString fileName);

public:
    QString HTMLText()
    {
        return htmlText;
    }

    int countChapters()
    {
        return chapters.count();
    }

    QString chapterName(int i)
    {
        return chapters[i].name;
    }

    QString chapterFile(int i)
    {
        return chapters[i].fileName;
    }

    void setChapter(int i);
};

#endif // CONTEXTHTMLMANAGER_H
