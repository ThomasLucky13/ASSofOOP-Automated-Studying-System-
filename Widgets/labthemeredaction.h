#ifndef LABTHEMEREDACTION_H
#define LABTHEMEREDACTION_H

#include <QWidget>
#include "Moduls/labsthemsmanager.h"
#include "mainwindow.h"
#include <QButtonGroup>

namespace Ui {
class LabThemeRedaction;
}

class LabThemeRedaction : public QWidget
{
    Q_OBJECT

public:
    explicit LabThemeRedaction(int themeId, MainWindow* mainWindow, QWidget *parent = nullptr);
    ~LabThemeRedaction();

private:
    Ui::LabThemeRedaction *ui;
    Theme * mTheme;
    LabsThemsManager * mThemsManager;
    void closeTheme(MainWindow* mainWindow);

    QButtonGroup *themeFieldsGroup;

protected slots:
    void ChangedUsable();

};

#endif // LABTHEMEREDACTION_H
