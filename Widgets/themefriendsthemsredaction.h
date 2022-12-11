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
    QList<int> result();
    ~themeFriendsThemsRedaction();

private:
    Ui::themeFriendsThemsRedaction *ui;
    LabsThemsManager *mThemsManager;
    QList<QCheckBox*> mCheckBoxes;
    QList<std::tuple<int, bool>> themsRes;

protected slots:
    void saveChanges();
};

#endif // THEMEFRIENDSTHEMSREDACTION_H
