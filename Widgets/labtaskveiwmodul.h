#ifndef LABTASKVEIWMODUL_H
#define LABTASKVEIWMODUL_H

#include <QWidget>
#include "mainwindow.h"
#include "Moduls/labgenerationmanager.h"

namespace Ui {
class labTaskVeiwModul;
}

class labTaskVeiwModul : public QWidget
{
    Q_OBJECT

public:
    explicit labTaskVeiwModul(Task _task, MainWindow* mainWindow, QWidget *parent = nullptr);
    ~labTaskVeiwModul();

protected slots:
    void GenerateLab();
private:
    Ui::labTaskVeiwModul *ui;
    QString HTMLtext;
    Task task;
    labGenerationManager generationManager;
};

#endif // LABTASKVEIWMODUL_H
