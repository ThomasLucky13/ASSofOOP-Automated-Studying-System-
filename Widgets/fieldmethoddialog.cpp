#include "fieldmethoddialog.h"
#include "ui_fieldmethoddialog.h"

fieldMethodDialog::fieldMethodDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fieldMethodDialog)
{
    ui->setupUi(this);
    ui->deleteButton->setEnabled(false);
    ui->deleteButton->setVisible(false);

    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveButton()));
}

fieldMethodDialog::fieldMethodDialog(QString methodText, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fieldMethodDialog)
{
    ui->setupUi(this);
    ui->textEdit->setText(methodText);

    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveButton()));
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(deleteButton()));
}

QString fieldMethodDialog::getText()
{
    return ui->textEdit->toPlainText();
}

void fieldMethodDialog::saveButton()
{
    QDialog::done(fieldMethodDialogStatus::Save);
    //accept();
}

void fieldMethodDialog::deleteButton()
{
    QDialog::done(fieldMethodDialogStatus::Delete);
    //reject();
}

fieldMethodDialog::~fieldMethodDialog()
{
    delete ui;
}
