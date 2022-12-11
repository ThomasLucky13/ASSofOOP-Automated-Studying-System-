#include "themefriendsthemsredaction.h"
#include "ui_themefriendsthemsredaction.h"

themeFriendsThemsRedaction::themeFriendsThemsRedaction(LabsThemsManager* themsManager, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::themeFriendsThemsRedaction)
{
    ui->setupUi(this);
    mThemsManager = themsManager;
    QList<Theme> thems = mThemsManager->thems();
    QList<QString> currentFriendsThems = themsManager->creationTheme->FriendsThems();
    for (int i = 0; i < thems.count(); ++i)
    {
        if (thems[i].Id() != themsManager->creationTheme->Id())
        {
            themsRes.push_back(std::make_tuple(thems[i].Id(), false));
            QCheckBox* checkBox = new QCheckBox();
            checkBox->setText("  " + thems[i].Name());
            checkBox->setChecked(currentFriendsThems.contains(thems[i].Id()));
            checkBox->setStyleSheet("color: rgb(201, 209, 200);");
            mCheckBoxes.push_back(checkBox);
            ui->friendsThemsLayout->addWidget(checkBox);
        }
    }
    ui->friendsThemsLayout->addSpacerItem(
                new QSpacerItem(20,40, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding));

    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveChanges()));
}

themeFriendsThemsRedaction::~themeFriendsThemsRedaction()
{
    delete ui;
    for (int i = mCheckBoxes.count()-1; i >=0; --i)
    {
        delete mCheckBoxes[i];
    }
}

void themeFriendsThemsRedaction::saveChanges()
{
    for (int i = 0; i < mCheckBoxes.count(); ++i)
    {
        std::get<1>(themsRes[i]) = mCheckBoxes[i]->isChecked();
    }
    QDialog::accept();
}

QList<QString> themeFriendsThemsRedaction::result()
{
    QList<QString> res;
    for (int i = 0; i < themsRes.count(); ++i)
    {
        if (std::get<1>(themsRes[i]) == true)
        {
            res.push_back(std::get<0>(themsRes[i]));
        }
    }
    return res;
}
