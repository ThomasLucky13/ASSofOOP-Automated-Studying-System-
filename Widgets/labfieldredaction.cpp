#include "labfieldredaction.h"
#include "ui_labfieldredaction.h"
#include <QtCore>

LabFieldRedaction::LabFieldRedaction(int themeId, int fieldId, MainWindow* mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LabFieldRedaction)
{
    ui->setupUi(this);
    mThemsManager = mainWindow->themsManager;
    mField = mThemsManager->getField(themeId, fieldId);
    mThemeId = themeId;
    if (!mField)
    {
        qWarning("Поле не найдено!");
        ui->savedChanges->setEnabled(false);
        ui->isRequiredCheckBox->setEnabled(false);
    } else
    {
        ui->FieldName->setText(mField->Name());
        ui->isRequiredCheckBox->setChecked(mField->IsRequired());
        methodsGroup = new QButtonGroup();

        for (int i = 0; i < mField->Methods().count(); ++i)
        {
            QPushButton* button = new QPushButton();
            button->setText("  " + mField->getMethod(i));
            button->setStyleSheet("text-align:left;\ncolor: rgb(201, 209, 200);");
            methodsGroup->addButton(button, i);
            ui->fieldMethodsLayout->addWidget(button);
        }
        ui->fieldMethodsLayout->addSpacerItem(
                    new QSpacerItem(20,40, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding));

    }

    connect(ui->backButton,  SIGNAL(clicked()), mainWindow, SLOT(labsThemeRedactionModulOn()));
    connect(ui->savedChanges, SIGNAL(clicked()), this, SLOT(saveChanges()));
    connect(ui->FieldName, SIGNAL(editingFinished()), this, SLOT(fieldNameChanged()));
    connect(ui->isRequiredCheckBox, SIGNAL(clicked()), this, SLOT(isRequiredChanged()));
    connect(methodsGroup, SIGNAL(idClicked(int)), this, SLOT(openMethod(int)));
    connect(ui->addMethod, SIGNAL(clicked()), this, SLOT(addMethod()));
}

LabFieldRedaction::~LabFieldRedaction()
{
    delete ui;
    delete methodsGroup;
    delete mField;
}

void LabFieldRedaction::fieldNameChanged()
{
    mField->setName(ui->FieldName->text());
}

void LabFieldRedaction::saveChanges()
{
    mThemsManager->changeField(mThemeId, mField->Id(), Field(mField->Id(), mField->Name(), mField->IsRequired(), mField->Methods()));
    ui->backButton->click();
}

void LabFieldRedaction::isRequiredChanged()
{
    mField->setRequired(ui->isRequiredCheckBox->isChecked());
}

void LabFieldRedaction::openMethod(int index)
{
    qWarning() << "Open window " << index;
}

void LabFieldRedaction::addMethod()
{
    qWarning("Open window");
}
