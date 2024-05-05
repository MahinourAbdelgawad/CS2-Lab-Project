#include "cities.h"
#include "ui_cities.h"
#include "welcomepage.h"

Cities::Cities(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Cities)
{
    ui->setupUi(this);
    ui->city2->hide();
    ui->city3->hide();
    ui->city4->hide();
    ui->city5->hide();
    ui->city6->hide();
    ui->city7->hide();
    ui->city8->hide();
    ui->city9->hide();
    ui->city10->hide();
    ui->city11->hide();
    ui->city12->hide();
    ui->city13->hide();
    ui->city14->hide();
    ui->delete2->hide();
    ui->delete3->hide();
    ui->delete4->hide();
    ui->delete5->hide();
    ui->delete6->hide();
    ui->delete7->hide();
    ui->delete8->hide();
    ui->delete9->hide();
    ui->delete10->hide();
    ui->delete11->hide();
    ui->delete12->hide();
    ui->delete13->hide();
    ui->delete14->hide();
    ui->plus2->hide();
    ui->plus3->hide();
    ui->plus4->hide();
    ui->plus5->hide();
    ui->plus6->hide();
    ui->plus7->hide();
    ui->plus8->hide();
    ui->plus9->hide();
    ui->plus10->hide();
    ui->plus11->hide();
    ui->plus12->hide();
    ui->plus13->hide();


}

Cities::~Cities()
{
    delete ui;
}

void Cities::on_back_clicked()
{
    this->hide();
    welcomePage* welcome = new welcomePage(this);
    welcome->show();
}


void Cities::on_plus1_clicked()
{
    ui->city2->show();
    ui->plus2->show();
    ui->delete2->show();
}


void Cities::on_plus2_clicked()
{
    ui->city3->show();
    ui->plus3->show();
    ui->delete3->show();
}


void Cities::on_delete2_clicked()
{
    ui->city2->hide();
    ui->plus2->hide();
    ui->delete2->hide();
}


void Cities::on_plus3_clicked()
{
    ui->city4->show();
    ui->plus4->show();
    ui->delete4->show();
}


void Cities::on_delete3_clicked()
{
    ui->city3->hide();
    ui->plus3->hide();
    ui->delete3->hide();
}


void Cities::on_plus4_clicked()
{
    ui->city5->show();
    ui->plus5->show();
    ui->delete5->show();
}


void Cities::on_delete4_clicked()
{
    ui->city4->hide();
    ui->plus4->hide();
    ui->delete4->hide();
}


void Cities::on_plus5_clicked()
{
    ui->city6->show();
    ui->plus6->show();
    ui->delete6->show();
}


void Cities::on_delete5_clicked()
{
    ui->city5->hide();
    ui->plus5->hide();
    ui->delete5->hide();
}


void Cities::on_plus6_clicked()
{
    ui->city7->show();
    ui->plus7->show();
    ui->delete7->show();
}


void Cities::on_delete6_clicked()
{
    ui->city6->hide();
    ui->plus6->hide();
    ui->delete6->hide();
}


void Cities::on_plus7_clicked()
{
    ui->city8->show();
    ui->plus8->show();
    ui->delete8->show();
}


void Cities::on_delete7_clicked()
{
    ui->city7->hide();
    ui->plus7->hide();
    ui->delete7->hide();
}


void Cities::on_plus8_clicked()
{
    ui->city9->show();
    ui->plus9->show();
    ui->delete9->show();
}


void Cities::on_delete8_clicked()
{
    ui->city8->hide();
    ui->plus8->hide();
    ui->delete8->hide();
}


void Cities::on_plus9_clicked()
{
    ui->city10->show();
    ui->plus10->show();
    ui->delete10->show();
}


void Cities::on_delete9_clicked()
{
    ui->city9->hide();
    ui->plus9->hide();
    ui->delete9->hide();
}


void Cities::on_plus10_clicked()
{
    ui->city11->show();
    ui->plus11->show();
    ui->delete11->show();
}


void Cities::on_delete10_clicked()
{
    ui->city10->hide();
    ui->plus10->hide();
    ui->delete10->hide();
}


void Cities::on_plus11_clicked()
{
    ui->city12->show();
    ui->plus12->show();
    ui->delete12->show();
}


void Cities::on_delete11_clicked()
{
    ui->city11->hide();
    ui->plus11->hide();
    ui->delete11->hide();
}


void Cities::on_plus12_clicked()
{
    ui->city13->show();
    ui->plus13->show();
    ui->delete13->show();
}


void Cities::on_delete12_clicked()
{
    ui->city12->hide();
    ui->plus12->hide();
    ui->delete12->hide();
}


void Cities::on_plus13_clicked()
{
    ui->city14->show();
    ui->delete14->show();
}


void Cities::on_delete13_clicked()
{
    ui->city13->hide();
    ui->plus13->hide();
    ui->delete13->hide();
}


void Cities::on_delete14_clicked()
{
    ui->city14->hide();
    ui->delete14->hide();
}

