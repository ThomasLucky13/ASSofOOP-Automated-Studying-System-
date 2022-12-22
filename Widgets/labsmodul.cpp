#include "labsmodul.h"
#include "ui_labsmodul.h"
#include <QLabel>

LabsModul::LabsModul(MainWindow* mMainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LabsModul)
{
    ui->setupUi(this);

    QList<Theme> usedThems = mMainWindow->themsManager->getUsedThems();

    for (int i = 0; i < usedThems.count(); ++i)
    {
        QLabel* themeLabel = new QLabel();
        themeLabel->setText(usedThems[i].Name());
        themeLabel->setStyleSheet("color: rgb(201, 209, 200);");
        ui->themsLayout->addWidget(themeLabel);
    }

    QList<Task> tasks = mMainWindow->tasksManager->getTasks();

    for (int i = 0; i < tasks.count(); ++i)
    {
        QLabel* taskLabel = new QLabel();
        taskLabel->setText(tasks[i].Name());
        taskLabel->setStyleSheet("color: rgb(201, 209, 200);");
        ui->tasksLayout->addWidget(taskLabel);
    }

    connect(ui->themsEditButton, SIGNAL(clicked()), mMainWindow, SLOT(labsRedactionModulOn()));
}

LabsModul::~LabsModul()
{
    delete ui;
}
