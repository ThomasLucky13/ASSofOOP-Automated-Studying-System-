#include "labsmodul.h"
#include "ui_labsmodul.h"
#include <QLabel>

LabsModul::LabsModul(MainWindow* mMainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LabsModul)
{
    ui->setupUi(this);

    tasksButtons = new QButtonGroup();
    QList<Task> tasks = mMainWindow->tasksManager->getTasks();

    for (int i = 0; i < tasks.count(); ++i)
    {
        QPushButton* button = new QPushButton();
        button->setText("  "+tasks[i].Name());
        button->setStyleSheet("text-align:left;\ncolor: rgb(201, 209, 200);");

        tasksButtons->addButton(button, i);
        ui->tasksLayout->addWidget(button);
    }
    ui->tasksLayout->addSpacerItem(
                new QSpacerItem(20,40, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding));

    connect(ui->themsEditButton, SIGNAL(clicked()), mMainWindow, SLOT(labsRedactionModulOn()));
    connect(ui->taskEditButton, SIGNAL(clicked()), mMainWindow, SLOT(labsTasksRedactionModulOn()));
    connect(tasksButtons, SIGNAL(idClicked(int)), mMainWindow, SLOT(labsTaskViewModulOn(int)));
}

LabsModul::~LabsModul()
{
    delete ui;
}
