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
    explicit LabThemeRedaction(bool _creationMode, MainWindow* mainWindow, QWidget *parent = nullptr);
    ~LabThemeRedaction();

private:
    Ui::LabThemeRedaction *ui;

    Theme * mTheme;
    LabsThemsManager * mThemsManager;
    QButtonGroup *themeFieldsGroup;

    bool creationMode;

protected slots:
    void themeNameChanged();
    void saveChanges();
    void isUsableChanged();
    void deleteTheme();
    void friendsThemsRedaction();

};

#endif // LABTHEMEREDACTION_H
