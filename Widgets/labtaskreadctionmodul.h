#ifndef LABTASKREADCTIONMODUL_H
#define LABTASKREADCTIONMODUL_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class labTaskReadctionModul;
}

class labTaskReadctionModul : public QWidget
{
    Q_OBJECT

public:
    explicit labTaskReadctionModul(MainWindow* mainWindow, QWidget *parent = nullptr);
    explicit labTaskReadctionModul(QString taskId, MainWindow* mainWindow, QWidget *parent = nullptr);
    ~labTaskReadctionModul();
protected slots:
    void saveChanges();
    void deleteTask();
private:
    Ui::labTaskReadctionModul *ui;
    labsTasksManager* mTasksManager;
    bool creationMode;

    Task* mTask;
};

#endif // LABTASKREADCTIONMODUL_H
