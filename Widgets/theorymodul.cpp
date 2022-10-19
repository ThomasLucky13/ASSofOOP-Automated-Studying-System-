#include "theorymodul.h"
#include "ui_theorymodul.h"
#include <iostream>

TheoryModul::TheoryModul(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TheoryModul)
{
    qWarning("Create Theory");
    ui->setupUi(this);

    chaptersButtons = new QButtonGroup();
    context = contextHTMLManager();
    chapterCount = context.countChapters();

    for (int i = 0; i < chapterCount; ++i)
    {
        QPushButton* button = new QPushButton();
        button->setText("  " + context.chapterName(i));
         button->setStyleSheet("text-align:left;");
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
    qWarning("Delete Theory");
    delete ui;
    delete chaptersButtons;
    delete ui->webEngineView;
}

void TheoryModul::setChapter(int i )
{
    currentChapter = i;
    context.setChapter(i);
    ui->webEngineView->setHtml(context.HTMLText());


    if (currentChapter == chapterCount-1)
        ui->next_button->setEnabled(false);
    else
        ui->next_button->setEnabled(true);

    if (currentChapter == 0)
        ui->previous_button->setEnabled(false);
    else
        ui->previous_button->setEnabled(true);
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
    }
}

void TheoryModul::nextChapter()
{
    if(currentChapter<chapterCount-1)
    {
        setChapter(currentChapter+1);
    }
}
