#include "testmodul.h"
#include "ui_testmodul.h"

TestModul::TestModul(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestModul)
{
    qWarning("Create Test");
    ui->setupUi(this);
}

TestModul::~TestModul()
{
    qWarning("Delete Test");
    delete ui;
}
