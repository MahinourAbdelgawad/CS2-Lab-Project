#ifndef PATHS_H
#define PATHS_H

#include <QDialog>

namespace Ui {
class Paths;
}

class Paths : public QDialog
{
    Q_OBJECT

public:
    explicit Paths(QWidget *parent = nullptr);
    ~Paths();

private slots:
    void on_back_clicked();

    void on_addpath_clicked();

    void on_modifypath_clicked();

    void on_deletepath_clicked();

    void on_cancel_clicked();

private:
    Ui::Paths *ui;
};

#endif // PATHS_H
