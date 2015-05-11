#include "inter.h"
#include "ui_inter.h"

Inter::Inter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inter)
{
    ui->setupUi(this);
}

Inter::~Inter()
{
    delete ui;
}
