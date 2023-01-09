#include "tasksreadctionmodul.h"
#include "ui_tasksreadctionmodul.h"

#include <QPushButton>
#include <string>

TasksReadctionModul::TasksReadctionModul(MainWindow* mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TasksReadctionModul)
{
    mTasksManager = mainWindow->tasksManager;
    ui->setupUi(this);

    tasksButtons = new QButtonGroup();
    QList<Task> tasks = mTasksManager->getTasks();
    for (int i = 0; i < tasks.count(); ++i)
    {
        QPushButton* button = new QPushButton();
        button->setText("  "+tasks[i].Name());
        button->setStyleSheet("text-align:left;\ncolor: rgb(4, 32, 44);");

        tasksButtons->addButton(button, i);
        ui->contextLayout->addWidget(button);
    }
    ui->contextLayout->addSpacerItem(
                new QSpacerItem(20,40, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding));
    connect(tasksButtons, SIGNAL(idClicked(int)), mainWindow, SLOT(labsTaskRedactionModulOn(int)));
    connect(ui->addTask, SIGNAL(clicked()), mainWindow, SLOT(labsTaskCreateModulOn()));
    connect(ui->backButton, SIGNAL(clicked()), mainWindow, SLOT(labsModulOn()));
}

TasksReadctionModul::~TasksReadctionModul()
{
    delete tasksButtons;
    delete ui;
}
