#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected slots:
    void theoryModulOn();
    void testModulOn();
    void labsModulOn();
    void settingsOpen();

private:
    Ui::MainWindow *ui;
    QWidget *currentWidget;
};
#endif // MAINWINDOW_H
