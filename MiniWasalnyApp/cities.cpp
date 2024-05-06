#include "cities.h"
#include "ui_cities.h"
#include "welcomepage.h"
#include "graphitem.h"

Cities::Cities(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Cities)
{
    ui->setupUi(this);
    ui->frame->hide();
    ui->errorlabel->setVisible(false);
    ui->errorlabel_2->setVisible(false);

    // loadList();

    for (const auto& cities : graph.adjList)
    {
        ui->comboBox->addItem(cities.first);
    }
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



void Cities::on_addcity_clicked()
{
    ui->addcity->setEnabled(false);
    ui->deletecity->setEnabled(false);
    ui->frame->show();
    ui->choosecity->hide();
    ui->comboBox->hide();
    ui->delete1->hide();
    ui->delete1->setEnabled(false);
    ui->add->show();
    ui->add->setEnabled(true);
    ui->entername->show();
    ui->nameEdit->show();

}


void Cities::on_deletecity_clicked()
{
    ui->addcity->setEnabled(false);
    ui->deletecity->setEnabled(false);
    ui->frame->show();
    ui->choosecity->show();
    ui->comboBox->show();
    ui->delete1->show();
    ui->delete1->setEnabled(true);
    ui->add->hide();
    ui->add->setEnabled(false);
    ui->entername->hide();
    ui->nameEdit->hide();

}

void Cities::on_cancel_clicked()
{
    ui->addcity->setEnabled(true);
    ui->deletecity->setEnabled(true);
    ui->frame->hide();
    ui->errorlabel->setVisible(false);
    ui->errorlabel_2->setVisible(false);

}


void Cities::on_delete1_clicked()
{
    if (ui->nameEdit->text().isEmpty())
        ui->errorlabel->setVisible(true);
    else
    {
        QString cityname = ui->nameEdit->text();

        if(citylist.contains(cityname)){
            citylist.removeAll(cityname);
            ui->comboBox->removeItem(ui->comboBox->findText(cityname));
            graph.DeleteCity(cityname.toStdString());
            saveList();
        }
    }

}

void Cities::on_add_clicked()
{
    if (ui->nameEdit->text().isEmpty())
        ui->errorlabel->setVisible(true);
    else
    {
        QString cityname = ui->nameEdit->text();

        if(!citylist.contains(cityname)){
            citylist.append(cityname);
            ui->comboBox->addItem(cityname);
            graph.AddCity(cityname.toStdString());
            saveList();
        }
    }

}

// void Cities::saveList(){
//     QFile file("citylist.txt");
//     if (file.open(QIODevice::WriteOnly | QIODevice::Text))
//     {
//         QTextStream out(&file);
//         for (const QString &city : citylist)
//         {
//             out << city << Qt::endl;
//         }
//         file.close();
//     }
// }


// void Cities::loadList(){

//     QFile file("citylist.txt");
//     if (file.open(QIODevice::ReadOnly | QIODevice::Text))
//     {
//         QTextStream in(&file);
//         while (!in.atEnd())
//         {
//             QString city = in.readLine();
//             citylist.append(city);
//             ui->comboBox->addItem(city); //Add city to combo box
//         }
//         file.close();
//     }
// }
