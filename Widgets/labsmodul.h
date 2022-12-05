#ifndef LABSMODUL_H
#define LABSMODUL_H

#include <QWidget>
#include <QButtonGroup>
#include "Moduls/labsthemsmanager.h"
#include "mainwindow.h"

namespace Ui {
class LabsModul;
}

class LabsModul : public QWidget
{
    Q_OBJECT

public:
    explicit LabsModul(MainWindow* mainWindow, QWidget *parent = nullptr);
    ~LabsModul();

private:
    Ui::LabsModul *ui;
    QButtonGroup *themsButtons;
    LabsThemsManager *mThemsManager;

protected slots:
};

#endif // LABSMODUL_H
