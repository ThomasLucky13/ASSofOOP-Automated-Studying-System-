#ifndef LABSMODUL_H
#define LABSMODUL_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class LabsModul;
}

class LabsModul : public QWidget
{
    Q_OBJECT

public:
    explicit LabsModul(MainWindow* mMainWindow, QWidget *parent = nullptr);
    ~LabsModul();

private:
    Ui::LabsModul *ui;
};

#endif // LABSMODUL_H
