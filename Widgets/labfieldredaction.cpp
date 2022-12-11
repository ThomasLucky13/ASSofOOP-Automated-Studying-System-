#include "labfieldredaction.h"
#include "ui_labfieldredaction.h"
#include "Widgets/fieldmethoddialog.h"
#include <QtCore>

LabFieldRedaction::LabFieldRedaction(QString fieldId, MainWindow* mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LabFieldRedaction)
{
    ui->setupUi(this);
    mThemsManager = mainWindow->themsManager;
    creationMode = false;
    mField = mThemsManager->getField(fieldId);
    if (!mField)
    {
        qWarning("Поле не найдено!");
        ui->savedChanges->setEnabled(false);
        ui->isRequiredCheckBox->setEnabled(false);
        ui->deleteButton->setEnabled(false);
        ui->addMethod->setEnabled(false);
    } else
    {
        ui->FieldName->setText(mField->Name());
        ui->isRequiredCheckBox->setChecked(mField->IsRequired());
        methodsGroup = new QButtonGroup();
        setMethods();

    }

    connect(ui->backButton,  SIGNAL(clicked()), mainWindow, SLOT(labsThemeRedactionModulOn()));
    connect(ui->savedChanges, SIGNAL(clicked()), this, SLOT(saveChanges()));
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(deleteField()));
    connect(ui->FieldName, SIGNAL(editingFinished()), this, SLOT(fieldNameChanged()));
    connect(ui->isRequiredCheckBox, SIGNAL(clicked()), this, SLOT(isRequiredChanged()));
    connect(ui->addMethod, SIGNAL(clicked()), this, SLOT(addMethod()));
}

LabFieldRedaction::LabFieldRedaction(MainWindow* mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LabFieldRedaction)
{
    ui->setupUi(this);
    mThemsManager = mainWindow->themsManager;
    creationMode = true;
    mField = new Field();

    ui->FieldName->setText(mField->Name());
    ui->isRequiredCheckBox->setChecked(mField->IsRequired());
    methodsGroup = new QButtonGroup();
    setMethods();

    ui->deleteButton->setEnabled(false);
    ui->deleteButton->setVisible(false);

    connect(ui->backButton,  SIGNAL(clicked()), mainWindow, SLOT(labsThemeRedactionModulOn()));
    connect(ui->savedChanges, SIGNAL(clicked()), this, SLOT(saveChanges()));
    connect(ui->FieldName, SIGNAL(editingFinished()), this, SLOT(fieldNameChanged()));
    connect(ui->isRequiredCheckBox, SIGNAL(clicked()), this, SLOT(isRequiredChanged()));
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
    if (mField->Name().length() < 1)
    {
        ui->FieldName->setFocus();
        return;
    }
    if (creationMode)
    {
        mThemsManager->addField(Field(mField->Id(), mField->Name(), mField->IsRequired(), mField->Methods()));
    } else
    {
        mThemsManager->changeField(mField->Id(), Field(mField->Id(), mField->Name(), mField->IsRequired(), mField->Methods()));
    }
    ui->backButton->click();
}

void LabFieldRedaction::isRequiredChanged()
{
    mField->setRequired(ui->isRequiredCheckBox->isChecked());
}

void LabFieldRedaction::openMethod(int index)
{
    fieldMethodDialog methodDialog (mField->getMethod(index),this);
    int dialogRes =  methodDialog.exec();
    if (dialogRes == fieldMethodDialogStatus::Save)
    {
         mField->setMethod(index, methodDialog.getText());
         setMethods();
    }
    else if(dialogRes == fieldMethodDialogStatus::Delete)
    {
        mField->deleteMethod(index);
        setMethods();
    }
}

void LabFieldRedaction::addMethod()
{
    fieldMethodDialog methodDialog (this);
    int dialogRes =  methodDialog.exec();
    if (dialogRes == fieldMethodDialogStatus::Save)
    {
         mField->addMethod(methodDialog.getText());
         setMethods();
    }
}

void LabFieldRedaction::setMethods()
{
    for(int i = methodsGroup->buttons().count()-1; i>=0; --i)
    {
        QAbstractButton* button = methodsGroup->buttons()[i];
        methodsGroup->removeButton(button);
        ui->fieldMethodsLayout->removeWidget(button);
        delete button;
    }
    for(int i=ui->fieldMethodsLayout->count()-1;i>=0;--i) {
        QLayoutItem *item = ui->fieldMethodsLayout->itemAt(i);
        ui->fieldMethodsLayout->removeItem(item);
        delete item;
    }
    methodsGroup = new QButtonGroup();
    for (int i = 0; i < mField->Methods().count(); ++i)
    {
        QPushButton* button = new QPushButton();
        QString methodName = mField->getMethod(i).split('\n')[0];
        if (methodName.size() > 50)
        {
            methodName.resize(50);
            methodName += "...";
        }
        button->setText("  " + methodName);
        button->setStyleSheet("text-align:left;\ncolor: rgb(201, 209, 200);");
        methodsGroup->addButton(button, i);
        ui->fieldMethodsLayout->addWidget(button);
    }
    ui->fieldMethodsLayout->addSpacerItem(
                new QSpacerItem(20,40, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding));
     connect(methodsGroup, SIGNAL(idClicked(int)), this, SLOT(openMethod(int)));
}

void LabFieldRedaction::deleteField()
{
    mThemsManager->deleteField(mField->Id());
    ui->backButton->click();
}
