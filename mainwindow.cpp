#include "mainwindow.h"
#include "Widgets/theorymodul.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    theoryModulOn();
    ui->verticalLayout->insertWidget(0, currentWidget);

    connect(ui->TheoryButton, SIGNAL(clicked()), this, SLOT(theoryModulOn()));
    connect(ui->TestButton, SIGNAL(clicked()), this, SLOT(testModulOn()));
    connect(ui->LabsButton, SIGNAL(clicked()), this, SLOT(labsModulOn()));
    connect(ui->menuButton, SIGNAL(clicked()), this, SLOT(settingsOpen()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete currentWidget;
}

void MainWindow::theoryModulOn()
{
    qWarning("theory");
    currentWidget = new TheoryModul();
    ui->TheoryButton->setEnabled(false);
    ui->TestButton->setEnabled(true);
    ui->LabsButton->setEnabled(true);
}

void MainWindow::testModulOn()
{
    qWarning("test");

    ui->TheoryButton->setEnabled(true);
    ui->TestButton->setEnabled(false);
    ui->LabsButton->setEnabled(true);
}

void MainWindow::labsModulOn()
{
    qWarning("labs");

    ui->TheoryButton->setEnabled(true);
    ui->TestButton->setEnabled(true);
    ui->LabsButton->setEnabled(false);
}

void MainWindow::settingsOpen()
{
    qWarning("settings");
}
