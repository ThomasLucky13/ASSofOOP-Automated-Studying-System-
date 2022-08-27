#ifndef THEORYMODUL_H
#define THEORYMODUL_H

#include <QWidget>
#include <QButtonGroup>

#include "Moduls/contextHTMLManager.h"

namespace Ui {
class TheoryModul;
}

class TheoryModul : public QWidget
{
    Q_OBJECT

public:
    explicit TheoryModul(QWidget *parent = nullptr);
    ~TheoryModul();

protected:
    void setChapter(int);
protected slots:
    void chapterChanged(int);
    void previousChapter();
    void nextChapter();

private:
    Ui::TheoryModul *ui;
    QButtonGroup *chaptersButtons;

    contextHTMLManager context;
    int currentChapter;
    int chapterCount;

};

#endif // THEORYMODUL_H
