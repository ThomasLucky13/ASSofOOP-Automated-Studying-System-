#include "mainwindow.h"
#include "Widgets/theorymodul.h"
#include "Widgets/labsmodul.h"
#include "Widgets/testmodul.h"
#include "Widgets/labthemeredaction.h"
#include "Widgets/labfieldredaction.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    themsManager = new LabsThemsManager();
    currentWidget = new TheoryModul();
    ui->TheoryButton->setEnabled(false);
    ui->TestButton->setEnabled(true);
    ui->LabsButton->setEnabled(true);

    ui->verticalLayout->insertWidget(0, currentWidget);

    connect(ui->TheoryButton, SIGNAL(clicked()), this, SLOT(theoryModulOn()));
    connect(ui->TestButton, SIGNAL(clicked()), this, SLOT(testModulOn()));
    connect(ui->LabsButton, SIGNAL(clicked()), this, SLOT(labsModulOn()));
    connect(ui->menuButton, SIGNAL(clicked()), this, SLOT(settingsOpen()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete themsManager;
    delete currentWidget;
}

void MainWindow::theoryModulOn()
{
    delete currentWidget;
    currentWidget = new TheoryModul();
    ui->TheoryButton->setEnabled(false);
    ui->TestButton->setEnabled(true);
    ui->LabsButton->setEnabled(true);
    ui->verticalLayout->insertWidget(0, currentWidget);
}

void MainWindow::testModulOn()
{
    delete currentWidget;
    currentWidget = new TestModul();
    ui->TheoryButton->setEnabled(true);
    ui->TestButton->setEnabled(false);
    ui->LabsButton->setEnabled(true);
    ui->verticalLayout->insertWidget(0, currentWidget);
}

void MainWindow::labsModulOn()
{
    delete currentWidget;
    currentWidget = new LabsModul(this);
    ui->TheoryButton->setEnabled(true);
    ui->TestButton->setEnabled(true);
    ui->LabsButton->setEnabled(false);
    ui->verticalLayout->insertWidget(0, currentWidget);
}

void MainWindow::labsThemeRedactionModulOn(int id)
{
    delete currentWidget;
    currentThemeId = themsManager->getThemeIdFromPosition(id);
    currentWidget = new LabThemeRedaction(currentThemeId, this);
    ui->TheoryButton->setEnabled(true);
    ui->TestButton->setEnabled(true);
    ui->LabsButton->setEnabled(false);
    ui->verticalLayout->insertWidget(0, currentWidget);
}

void MainWindow::labsThemeRedactionModulOn()
{
    delete currentWidget;
    currentWidget = new LabThemeRedaction(currentThemeId, this);
    ui->TheoryButton->setEnabled(true);
    ui->TestButton->setEnabled(true);
    ui->LabsButton->setEnabled(false);
    ui->verticalLayout->insertWidget(0, currentWidget);
}

void MainWindow::labsFieldRedactionModulOn(int id)
{
    delete currentWidget;
    currentWidget = new LabFieldRedaction(currentThemeId, themsManager->getFieldIdFromPosition(id, currentThemeId), this);
    ui->TheoryButton->setEnabled(true);
    ui->TestButton->setEnabled(true);
    ui->LabsButton->setEnabled(false);
    ui->verticalLayout->insertWidget(0, currentWidget);
}

void MainWindow::settingsOpen()
{
    qWarning("settings");
}
