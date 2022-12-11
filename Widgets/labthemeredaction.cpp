#include "labthemeredaction.h"
#include "ui_labthemeredaction.h"
#include "Widgets/themefriendsthemsredaction.h"

LabThemeRedaction::LabThemeRedaction(bool _creationMode, MainWindow* mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LabThemeRedaction)
{
    mThemsManager = mainWindow->themsManager;
    mTheme = mThemsManager->creationTheme;

    creationMode = _creationMode;

    ui->setupUi(this);
    ui->ThemeName->setText(mTheme->Name());
    ui->isUsableCheckBox->setChecked(mTheme->IsUsable());
    themeFieldsGroup = new QButtonGroup();

    for (int i = 0; i < mTheme->Fields().count(); ++i)
    {
        QPushButton* button = new QPushButton();
        button->setText("  " + mTheme->getField(i).Name());
        button->setStyleSheet("text-align:left;\ncolor: rgb(201, 209, 200);");
        themeFieldsGroup->addButton(button, i);
        ui->themeFieldsLayout->addWidget(button);
    }
    ui->themeFieldsLayout->addSpacerItem(
                new QSpacerItem(20,40, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding));

    connect(ui->ThemeName, SIGNAL(editingFinished()), this, SLOT(themeNameChanged()));
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveChanges()));
    connect(ui->backButton,  SIGNAL(clicked()), mainWindow, SLOT(labsModulOn()));
    connect(ui->addField, SIGNAL(clicked()), mainWindow, SLOT(labsFieldCreateModulOn()));
    connect(ui->isUsableCheckBox, SIGNAL(clicked()), this, SLOT(isUsableChanged()));
    connect(themeFieldsGroup, SIGNAL(idClicked(int)), mainWindow, SLOT(labsFieldRedactionModulOn(int)));
    connect(ui->friendsThemsButton, SIGNAL(clicked()), this, SLOT(friendsThemsRedaction()));

    if (creationMode)
    {
        ui->deleteButton->setEnabled(false);
        ui->deleteButton->setVisible(false);
    } else
    {
        connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(deleteTheme()));
    }
}

LabThemeRedaction::~LabThemeRedaction()
{
    delete ui;
    delete themeFieldsGroup;
}

void LabThemeRedaction::themeNameChanged()
{
    mTheme->setName(ui->ThemeName->text());
}

void LabThemeRedaction::saveChanges()
{
    if (mTheme->Name().length() < 1)
    {
        ui->ThemeName->setFocus();
        return;
    }
    if (creationMode)
    {
        mThemsManager->addTheme(Theme(mTheme->Id(), mTheme->Name(), mTheme->IsDeletable(), mTheme->IsUsable(), mTheme->Fields(), mTheme->FriendsThems()));
    } else
    {
        mThemsManager->changeTheme(mTheme->Id(), Theme(mTheme->Id(), mTheme->Name(), mTheme->IsDeletable(), mTheme->IsUsable(), mTheme->Fields(), mTheme->FriendsThems()));
    }
    ui->backButton->click();
}

void LabThemeRedaction::isUsableChanged()
{
    mTheme->setUsable(ui->isUsableCheckBox->isChecked());
}

void LabThemeRedaction::deleteTheme()
{
    mThemsManager->deleteTheme(mTheme->Id());
    ui->backButton->click();
}

void LabThemeRedaction::friendsThemsRedaction()
{
    themeFriendsThemsRedaction friendsThemsDialog (mThemsManager, this);
    int dialogRes =  friendsThemsDialog.exec();
    if (dialogRes == QDialog().Accepted)
    {
        mTheme->setFriendsThems(friendsThemsDialog.result());
    }
}

