#include "paths.h"
#include "ui_paths.h"
#include "welcomepage.h"

Paths::Paths(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Paths)
{
    ui->setupUi(this);
}

Paths::~Paths()
{
    delete ui;
}

void Paths::on_back_clicked()
{
    this->hide();
    welcomePage* welcome = new welcomePage(this);
    welcome->show();
}

