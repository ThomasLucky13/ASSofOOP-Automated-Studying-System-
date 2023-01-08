#include "labtaskreadctionmodul.h"
#include "ui_labtaskreadctionmodul.h"
labTaskReadctionModul::labTaskReadctionModul(QString taskId, MainWindow* mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::labTaskReadctionModul)
{
    ui->setupUi(this);
    mTasksManager = mainWindow->tasksManager;
    creationMode = false;
    mTask = mTasksManager->getTask(taskId);

    if (!mTask)
    {
        qWarning("Задание не найдено!");
        ui->savedChanges->setEnabled(false);
        ui->deleteButton->setEnabled(false);
    } else
    {
        ui->TaskName->setText(mTask->Name());
        ui->textEdit->setText(mTask->Text());
    }

    connect(ui->backButton,  SIGNAL(clicked()), mainWindow, SLOT(labsTasksRedactionModulOn()));
    connect(ui->savedChanges, SIGNAL(clicked()), this, SLOT(saveChanges()));
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(deleteTask()));
}

labTaskReadctionModul::labTaskReadctionModul(MainWindow* mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::labTaskReadctionModul)
{
    ui->setupUi(this);
    mTasksManager = mainWindow->tasksManager;
    creationMode = true;
    mTask = new Task();

    ui->deleteButton->setEnabled(false);
    ui->deleteButton->setVisible(false);

    connect(ui->backButton,  SIGNAL(clicked()), mainWindow, SLOT(labsTasksRedactionModulOn()));
    connect(ui->savedChanges, SIGNAL(clicked()), this, SLOT(saveChanges()));
}

void labTaskReadctionModul::saveChanges()
{
    mTask->setName(ui->TaskName->text());
    mTask->setText(ui->textEdit->toPlainText());
    if (creationMode)
    {
        mTasksManager->AddTask(Task(mTask->Id(), mTask->Name(), mTask->Text()));
    } else
    {
        mTasksManager->ChangeTask(mTask->Id(), Task(mTask->Id(), mTask->Name(), mTask->Text()));
    }
    ui->backButton->click();
}
void labTaskReadctionModul::deleteTask()
{
    mTasksManager->DeleteTask(mTask->Id());
    ui->backButton->click();
}

labTaskReadctionModul::~labTaskReadctionModul()
{
    delete ui;
    delete mTask;
}
