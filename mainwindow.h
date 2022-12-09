#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Moduls/labsthemsmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    LabsThemsManager * themsManager;
    ~MainWindow();

public slots:
    void labsModulOn();
    void labsThemeRedactionModulOn(int id);
    void labsThemeRedactionModulOn();
    void labsFieldRedactionModulOn(int id);
    void labsFieldCreateModulOn();

protected slots:
    void theoryModulOn();
    void testModulOn();
    void settingsOpen();

private:
    Ui::MainWindow *ui;
    QWidget *currentWidget;
    int currentThemeId;
};
#endif // MAINWINDOW_H
