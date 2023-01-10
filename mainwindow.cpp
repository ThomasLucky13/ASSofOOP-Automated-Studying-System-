#include "mainwindow.h"
#include "Widgets/theorymodul.h"
#include "Widgets/labsRedactionModul.h"
#include "Widgets/labsmodul.h"
#include "Widgets/testmodul.h"
#include "Widgets/labthemeredaction.h"
#include "Widgets/labfieldredaction.h"
#include "Widgets/labsRedactionModul.h"
#include "Widgets/tasksreadctionmodul.h"
#include "Widgets/labtaskreadctionmodul.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    themsManager = new LabsThemsManager();
    tasksManager = new labsTasksManager();
    currentWidget = new TheoryModul();
    ui->TheoryButton->setEnabled(false);
    ui->TestButton->setEnabled(true);
    ui->LabsButton->setEnabled(true);

    ui->verticalLayout->insertWidget(0, currentWidget);

    themeCreation = false;
    taskCreation = false;

    connect(ui->TheoryButton, SIGNAL(clicked()), this, SLOT(theoryModulOn()));
    connect(ui->TestButton, SIGNAL(clicked()), this, SLOT(testModulOn()));
    connect(ui->LabsButton, SIGNAL(clicked()), this, SLOT(labsModulOn()));
    connect(ui->menuButton, SIGNAL(clicked()), this, SLOT(settingsOpen()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete themsManager;
    delete tasksManager;
    delete currentWidget;
}

void MainWindow::theoryModulOn()
{
    themeCreation = false;
    taskCreation = false;
    delete currentWidget;
    currentWidget = new TheoryModul();
    ui->TheoryButton->setEnabled(false);
    ui->TestButton->setEnabled(true);
    ui->LabsButton->setEnabled(true);
    ui->verticalLayout->insertWidget(0, currentWidget);
}

void MainWindow::testModulOn()
{
    themeCreation = false;
    taskCreation = false;
    delete currentWidget;
    currentWidget = new TestModul();
    ui->TheoryButton->setEnabled(true);
    ui->TestButton->setEnabled(false);
    ui->LabsButton->setEnabled(true);
    ui->verticalLayout->insertWidget(0, currentWidget);
}

void MainWindow::labsModulOn()
{
    themeCreation = false;
    taskCreation = false;
    delete currentWidget;
    currentWidget = new LabsModul(this);
    ui->TheoryButton->setEnabled(true);
    ui->TestButton->setEnabled(true);
    ui->LabsButton->setEnabled(false);
    ui->verticalLayout->insertWidget(0, currentWidget);
}

void MainWindow::labsRedactionModulOn()
{
    themeCreation = false;
    taskCreation = false;
    delete currentWidget;
    currentWidget = new LabsRedactionModul(this);
    ui->TheoryButton->setEnabled(true);
    ui->TestButton->setEnabled(true);
    ui->LabsButton->setEnabled(false);
    ui->verticalLayout->insertWidget(0, currentWidget);
}

void MainWindow::labsThemeRedactionModulOn(int id)
{
    delete currentWidget;
    themsManager->creationTheme = themsManager->getTheme(themsManager->getThemeIdFromPosition(id));
    currentWidget = new LabThemeRedaction(themeCreation, this);
    ui->TheoryButton->setEnabled(true);
    ui->TestButton->setEnabled(true);
    ui->LabsButton->setEnabled(false);
    ui->verticalLayout->insertWidget(0, currentWidget);
}

void MainWindow::labsThemeRedactionModulOn()
{
    delete currentWidget;
    currentWidget = new LabThemeRedaction(themeCreation, this);
    ui->TheoryButton->setEnabled(true);
    ui->TestButton->setEnabled(true);
    ui->LabsButton->setEnabled(false);
    ui->verticalLayout->insertWidget(0, currentWidget);
}

void MainWindow::labsFieldRedactionModulOn(int id)
{
    delete currentWidget;
    currentWidget = new LabFieldRedaction(themsManager->getFieldIdFromPosition(id), this);
    ui->TheoryButton->setEnabled(true);
    ui->TestButton->setEnabled(true);
    ui->LabsButton->setEnabled(false);
    ui->verticalLayout->insertWidget(0, currentWidget);
}

void MainWindow::labsFieldCreateModulOn()
{
    delete currentWidget;
    currentWidget = new LabFieldRedaction(this);
    ui->TheoryButton->setEnabled(true);
    ui->TestButton->setEnabled(true);
    ui->LabsButton->setEnabled(false);
    ui->verticalLayout->insertWidget(0, currentWidget);
}

void MainWindow::labsThemeCreateModulOn()
{
    delete currentWidget;
    themeCreation = true;
    themsManager->creationTheme = new Theme("-1", "", true, true, QList<Field>(), QList<QString>());
    currentWidget = new LabThemeRedaction(themsManager->creationTheme, this);
    ui->TheoryButton->setEnabled(true);
    ui->TestButton->setEnabled(true);
    ui->LabsButton->setEnabled(false);
    ui->verticalLayout->insertWidget(0, currentWidget);
}

void MainWindow::labsTasksRedactionModulOn()
{
    delete currentWidget;
    themeCreation = false;
    taskCreation = false;
    currentWidget = new TasksReadctionModul(this);
    ui->TheoryButton->setEnabled(true);
    ui->TestButton->setEnabled(true);
    ui->LabsButton->setEnabled(false);
    ui->verticalLayout->insertWidget(0, currentWidget);
}
void MainWindow::labsTaskRedactionModulOn(int id)
{
    delete currentWidget;
    currentWidget = new labTaskReadctionModul(tasksManager->getTaskIdFromIndex(id), this);
    ui->TheoryButton->setEnabled(true);
    ui->TestButton->setEnabled(true);
    ui->LabsButton->setEnabled(false);
    ui->verticalLayout->insertWidget(0, currentWidget);
}
void MainWindow::labsTaskCreateModulOn()
{
    delete currentWidget;
    currentWidget = new labTaskReadctionModul(this);
    ui->TheoryButton->setEnabled(true);
    ui->TestButton->setEnabled(true);
    ui->LabsButton->setEnabled(false);
    ui->verticalLayout->insertWidget(0, currentWidget);
}

void MainWindow::labsTaskViewModulOn(int id)
{

}

void MainWindow::settingsOpen()
{
    qWarning("settings");
}
