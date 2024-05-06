#include "mainwindow.h"
#include "graph.h"
#include "graphitem.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    graph.loadGraph(":/Cities.txt");
    MainWindow w;

    w.show();
    return a.exec();

}
