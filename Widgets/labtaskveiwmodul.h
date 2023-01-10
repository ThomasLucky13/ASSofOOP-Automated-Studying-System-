#ifndef LABTASKVEIWMODUL_H
#define LABTASKVEIWMODUL_H

#include <QWidget>
#include "mainwindow.h"

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
    QString HTMLText;
    Task task;
};

#endif // LABTASKVEIWMODUL_H
