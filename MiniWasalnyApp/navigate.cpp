#include "navigate.h"
#include "ui_navigate.h"
#include "welcomepage.h"
#include "graphitem.h"

Navigate::Navigate(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Navigate)
{
    ui->setupUi(this);
    ui->errorlabel->setVisible(false);

    for (const auto& cities : graph.adjList)
    {
        ui->sourcebox->addItem(cities.first);
    }

    for (const auto& cities : graph.adjList)
    {
        ui->destinationbox->addItem(cities.first);
    }

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

