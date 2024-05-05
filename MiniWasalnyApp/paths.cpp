#include "paths.h"
#include "ui_paths.h"
#include "welcomepage.h"

Paths::Paths(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Paths)
{
    ui->setupUi(this);
    ui->frame->hide();
    ui->errorlabel->setVisible(false);
    ui->errorlabel_2->setVisible(false);
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


void Paths::on_addpath_clicked()
{
    ui->addpath->setEnabled(false);
    ui->modifypath->setEnabled(false);
    ui->deletepath->setEnabled(false);
    ui->frame->show();
    ui->distlabel->setVisible(false);
    ui->newdistlabel->setVisible(false);
    ui->delete1->setVisible(false);
    ui->delete1->setEnabled(false);
    ui->modify->setVisible(false);
    ui->modify->setEnabled(false);
    ui->enterdistlabel->setVisible(true);
    ui->distedit->setVisible(true);
    ui->add->setEnabled(true);
    ui->add->setVisible(true);

}


void Paths::on_modifypath_clicked()
{
    ui->addpath->setEnabled(false);
    ui->modifypath->setEnabled(false);
    ui->deletepath->setEnabled(false);
    ui->frame->show();
    ui->enterdistlabel->setVisible(false);
    ui->delete1->setVisible(false);
    ui->delete1->setEnabled(false);
    ui->add->setVisible(false);
    ui->add->setEnabled(false);
    ui->distlabel->setVisible(true);
    ui->newdistlabel->setVisible(true);
    ui->distedit->setVisible(true);
    ui->modify->setEnabled(true);
    ui->modify->setVisible(true);
}


void Paths::on_deletepath_clicked()
{
    ui->addpath->setEnabled(false);
    ui->modifypath->setEnabled(false);
    ui->deletepath->setEnabled(false);
    ui->frame->show();
    ui->enterdistlabel->setVisible(false);
    ui->newdistlabel->setVisible(false);
    ui->distedit->setVisible(false);
    ui->add->setVisible(false);
    ui->add->setEnabled(false);
    ui->modify->setVisible(false);
    ui->modify->setEnabled(false);
    ui->delete1->setEnabled(true);
    ui->delete1->setVisible(true);

}


void Paths::on_cancel_clicked()
{
    ui->frame->hide();
    ui->addpath->setEnabled(true);
    ui->modifypath->setEnabled(true);
    ui->deletepath->setEnabled(true);
    ui->errorlabel->setVisible(false);
    ui->errorlabel_2->setVisible(false);

}

