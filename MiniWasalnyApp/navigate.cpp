#include "navigate.h"
#include "ui_navigate.h"
#include "welcomepage.h"

Navigate::Navigate(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Navigate)
{
    ui->setupUi(this);
    ui->errorlabel->setVisible(false);
}

Navigate::~Navigate()
{
    delete ui;
}

void Navigate::on_back_clicked()
{
    this->hide();
    welcomePage* welcome = new welcomePage(this);
    welcome->show();
}

