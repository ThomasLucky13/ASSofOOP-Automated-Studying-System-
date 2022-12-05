#include "labthemeredaction.h"
#include "ui_labthemeredaction.h"

LabThemeRedaction::LabThemeRedaction(int themeId, MainWindow* mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LabThemeRedaction)
{
    mThemsManager = mainWindow->themsManager;
    mTheme = mThemsManager->getTheme(themeId);

    ui->setupUi(this);
    if (!mTheme)
    {
        qWarning("Тема не найдена!");
        ui->isUsableCheckBox->setEnabled(false);
    } else
    {
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

    }

    connect(ui->backButton,  SIGNAL(clicked()), mainWindow, SLOT(labsModulOn()));
    connect(ui->isUsableCheckBox, SIGNAL(clicked()), this, SLOT(ChangedUsable()));
    connect(themeFieldsGroup, SIGNAL(idClicked(int)), mainWindow, SLOT(labsFieldRedactionModulOn(int)));
}

LabThemeRedaction::~LabThemeRedaction()
{
    delete ui;
    delete mTheme;
    delete themeFieldsGroup;
}

void LabThemeRedaction::ChangedUsable()
{
    mThemsManager->changeThemeUsable(mTheme->Id(), ui->isUsableCheckBox->isChecked());
}


