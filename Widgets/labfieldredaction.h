#ifndef LABFIELDREDACTION_H
#define LABFIELDREDACTION_H

#include <QWidget>
#include "mainwindow.h"
#include <QButtonGroup>

namespace Ui {
class LabFieldRedaction;
}

class LabFieldRedaction : public QWidget
{
    Q_OBJECT

public:
    explicit LabFieldRedaction(int themeId, int fieldId, MainWindow* mainWindow, QWidget *parent = nullptr);
    ~LabFieldRedaction();

private:
    Ui::LabFieldRedaction *ui;

    Field * mField;
    LabsThemsManager * mThemsManager;
    QButtonGroup *methodsGroup;
    int mThemeId;

protected slots:
    void fieldNameChanged();
    void saveChanges();
    void isRequiredChanged();
    void openMethod(int index);
    void addMethod();
};

#endif // LABFIELDREDACTION_H
