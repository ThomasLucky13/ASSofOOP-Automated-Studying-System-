#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Moduls/labsthemsmanager.h"
#include "Moduls/labstasksmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    LabsThemsManager * themsManager;
    labsTasksManager * tasksManager;
    ~MainWindow();

public slots:
    void labsModulOn();
    void labsRedactionModulOn();
    void labsThemeRedactionModulOn(int id);
    void labsThemeRedactionModulOn();
    void labsFieldRedactionModulOn(int id);
    void labsFieldCreateModulOn();
    void labsThemeCreateModulOn();
    void labsTasksRedactionModulOn();
    void labsTaskRedactionModulOn(int id);
    void labsTaskCreateModulOn();

protected slots:
    void theoryModulOn();
    void testModulOn();
    void settingsOpen();

private:
    Ui::MainWindow *ui;
    QWidget *currentWidget;
    int currentThemeId;
    int currentTaskId;
    bool themeCreation;
    bool taskCreation;
};
#endif // MAINWINDOW_H
