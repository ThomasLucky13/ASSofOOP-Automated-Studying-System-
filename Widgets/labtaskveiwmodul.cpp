#include "labtaskveiwmodul.h"
#include "ui_labtaskveiwmodul.h"

labTaskVeiwModul::labTaskVeiwModul(Task _task, MainWindow* mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::labTaskVeiwModul)
{
    task = _task;
    ui->setupUi(this);
    generationManager = labGenerationManager(task, mainWindow->themsManager);
    ui->scrollArea->setVisible(false);
    ui->TaskName->setText(task.Name());
    ui->taskText->setText(task.Text());

    connect(ui->backButton, SIGNAL(clicked()), mainWindow, SLOT(labsModulOn()));
    connect(ui->GenerateButton, SIGNAL(clicked()), this, SLOT(GenerateLab()));
}

void labTaskVeiwModul::GenerateLab()
{

    HTMLtext = generationManager.generateLabHTML();
    ui->webEngineView->setHtml(HTMLtext);
    ui->scrollArea->setVisible(true);
}

labTaskVeiwModul::~labTaskVeiwModul()
{
    delete ui;
}
