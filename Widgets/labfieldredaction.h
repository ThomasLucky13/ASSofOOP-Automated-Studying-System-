#ifndef LABFIELDREDACTION_H
#define LABFIELDREDACTION_H

#include <QWidget>
#include "mainwindow.h"
#include <QButtonGroup>
#include <QPushButton>

namespace Ui {
class LabFieldRedaction;
}

class LabFieldRedaction : public QWidget
{
    Q_OBJECT

public:
    explicit LabFieldRedaction(int fieldId, MainWindow* mainWindow, QWidget *parent = nullptr);
    explicit LabFieldRedaction(MainWindow* mainWindow, QWidget *parent = nullptr);
    ~LabFieldRedaction();

private:
    Ui::LabFieldRedaction *ui;

    Field * mField;
    LabsThemsManager * mThemsManager;
    QButtonGroup *methodsGroup;

    bool creationMode;

    void setMethods();

protected slots:
    void fieldNameChanged();
    void saveChanges();
    void isRequiredChanged();
    void openMethod(int index);
    void addMethod();
    void deleteField();
};

#endif // LABFIELDREDACTION_H
