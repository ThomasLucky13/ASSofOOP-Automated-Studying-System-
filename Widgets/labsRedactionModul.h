#ifndef LABSREDACTIONMODUL_H
#define LABSREDACTIONMODUL_H

#include <QWidget>
#include <QButtonGroup>
#include "Moduls/labsthemsmanager.h"
#include "mainwindow.h"

namespace Ui {
class LabsRedactionModul;
}

class LabsRedactionModul : public QWidget
{
    Q_OBJECT

public:
    explicit LabsRedactionModul(MainWindow* mainWindow, QWidget *parent = nullptr);
    ~LabsRedactionModul();

private:
    Ui::LabsRedactionModul *ui;
    QButtonGroup *themsButtons;
    LabsThemsManager *mThemsManager;

protected slots:
};

#endif // LABSREDACTIONMODUL_H
