#include "theorymodul.h"
#include "ui_theorymodul.h"
#include <iostream>

TheoryModul::TheoryModul(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TheoryModul)
{
    ui->setupUi(this);

    chaptersButtons = new QButtonGroup();
    context = contextHTMLManager();
    chapterCount = context.countChapters();

    ui->previous_button->setEnabled(false);

    if (chapterCount < 2)
        ui->next_button->setEnabled(false);

    for (int i = 0; i < chapterCount; ++i)
    {
        QPushButton* button = new QPushButton();
        button->setText(context.chapterName(i));
        chaptersButtons->addButton(button, i);
        ui->contextLayout->addWidget(button);
    }
    ui->contextLayout->addSpacerItem(
                new QSpacerItem(20,40, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding));

    if (chapterCount>0)
    {
        setChapter(0);
    }

    connect(chaptersButtons, SIGNAL(idClicked(int)), this, SLOT(chapterChanged(int)));
    connect(ui->previous_button, SIGNAL(clicked()), this, SLOT(previousChapter()));
    connect(ui->next_button, SIGNAL(clicked()), this, SLOT(nextChapter()));

}

TheoryModul::~TheoryModul()
{
    delete ui;
    delete chaptersButtons;
}

void TheoryModul::setChapter(int i )
{
    currentChapter = i;
    context.setChapter(i);
    ui->webEngineView->setHtml(context.HTMLText());
}

void TheoryModul::chapterChanged(int i)
{
    if (i == currentChapter && i< chapterCount) return;
    setChapter(i);
}

void TheoryModul::previousChapter()
{
    if(currentChapter>0)
    {
        setChapter(currentChapter-1);
        if (currentChapter==0)
            ui->previous_button->setEnabled(false);
        if(!ui->next_button->isEnabled())
            ui->next_button->setEnabled(true);
    }
}

void TheoryModul::nextChapter()
{
    if(currentChapter<chapterCount-1)
    {
        setChapter(currentChapter+1);
        if (currentChapter == chapterCount-1)
            ui->next_button->setEnabled(false);
        if(!ui->previous_button->isEnabled())
            ui->previous_button->setEnabled(true);
    }
}
