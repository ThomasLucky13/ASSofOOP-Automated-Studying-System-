#ifndef THEMEFRIENDSTHEMSREDACTION_H
#define THEMEFRIENDSTHEMSREDACTION_H

#include <QDialog>
#include <QCheckBox>
#include "Moduls/labsthemsmanager.h"

namespace Ui {
class themeFriendsThemsRedaction;
}

class themeFriendsThemsRedaction : public QDialog
{
    Q_OBJECT

public:
    explicit themeFriendsThemsRedaction(LabsThemsManager* themsManager, QWidget *parent = nullptr);
    QList<QString> result();
    ~themeFriendsThemsRedaction();

private:
    Ui::themeFriendsThemsRedaction *ui;
    LabsThemsManager *mThemsManager;
    QList<QCheckBox*> mCheckBoxes;
    QList<std::tuple<QString, bool>> themsRes;

protected slots:
    void saveChanges();
};

#endif // THEMEFRIENDSTHEMSREDACTION_H
