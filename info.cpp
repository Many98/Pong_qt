#include "info.h"
#include "ui_info.h"

Info::Info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Info)
{
    this->setFixedSize(400,350);
    ui->setupUi(this);
}

Info::~Info()
{
    delete ui;
}
