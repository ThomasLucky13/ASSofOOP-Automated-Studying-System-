#ifndef TASKSREADCTIONMODUL_H
#define TASKSREADCTIONMODUL_H

#include <QWidget>
#include <QButtonGroup>
#include "mainwindow.h"

namespace Ui {
class TasksReadctionModul;
}

class TasksReadctionModul : public QWidget
{
    Q_OBJECT

public:
    explicit TasksReadctionModul(MainWindow* mainWindow, QWidget *parent = nullptr);
    ~TasksReadctionModul();

private:
    Ui::TasksReadctionModul *ui;
    QButtonGroup *tasksButtons;
    labsTasksManager *mTasksManager;
};

#endif // TASKSREADCTIONMODUL_H
