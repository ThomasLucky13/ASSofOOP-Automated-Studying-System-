#include "labsmodul.h"
#include "ui_labsmodul.h"

#include <QPushButton>
#include <string>

#include <iostream>

LabsModul::LabsModul(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LabsModul)
{
    qWarning("Create Labs");
    ui->setupUi(this);

    themsButtons = new QButtonGroup();
    for (int i = 0; i < 15; ++i)
    {
        QPushButton* button = new QPushButton();
        button->setText("  Theme " + QString::number(i));
        button->setStyleSheet("text-align:left;\ncolor: rgb(4, 32, 44);");
        themsButtons->addButton(button, i);
        ui->contextLayout->addWidget(button);
    }
    ui->contextLayout->addSpacerItem(
                new QSpacerItem(20,40, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding));

    connect(themsButtons, SIGNAL(idClicked(int)), this, SLOT(themeChoosed(int)));
}

LabsModul::~LabsModul()
{
    qWarning("Delete Labs");
    delete themsButtons;
    delete ui;
}

void LabsModul::themeChoosed(int i)
{
    std::cout << " Theme : " << i << std::endl;

}
