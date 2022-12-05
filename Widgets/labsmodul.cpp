#include "labsmodul.h"
#include "ui_labsmodul.h"

#include <QPushButton>
#include <string>

#include "Moduls/labsthemsmanager.h"

#include <iostream>

LabsModul::LabsModul( MainWindow* mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LabsModul)
{
    qWarning("Create Labs");
    mThemsManager = mainWindow->themsManager;
    ui->setupUi(this);

    themsButtons = new QButtonGroup();
    QList<Theme> thems = mThemsManager->thems();
    for (int i = 0; i < thems.count(); ++i)
    {
        QPushButton* button = new QPushButton();
        button->setText("  "+thems[i].Name());
        if(thems[i].IsUsable())
        {
            button->setStyleSheet("text-align:left;\ncolor: rgb(4, 32, 44);");
        } else
        {
            button->setStyleSheet("text-align:left;\ncolor: rgb(4, 32, 44);\nbackground-color: rgb(201, 209, 200);");
        }
        themsButtons->addButton(button, i);
        ui->contextLayout->addWidget(button);
    }
    ui->contextLayout->addSpacerItem(
                new QSpacerItem(20,40, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding));

    connect(themsButtons, SIGNAL(idClicked(int)), mainWindow, SLOT(labsThemeRedactionModulOn(int)));
}

LabsModul::~LabsModul()
{
    qWarning("Delete Labs");
    delete themsButtons;
    delete ui;
}

