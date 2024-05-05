#ifndef CITIES_H
#define CITIES_H

#include <QDialog>

namespace Ui {
class Cities;
}

class Cities : public QDialog
{
    Q_OBJECT

public:
    explicit Cities(QWidget *parent = nullptr);
    ~Cities();

private slots:
    void on_back_clicked();

    void on_plus1_clicked();

    void on_plus2_clicked();

    void on_delete2_clicked();

    void on_plus3_clicked();

    void on_delete3_clicked();

    void on_plus4_clicked();

    void on_delete4_clicked();

    void on_plus5_clicked();

    void on_delete5_clicked();

    void on_plus6_clicked();

    void on_delete6_clicked();

    void on_plus7_clicked();

    void on_delete7_clicked();

    void on_plus8_clicked();

    void on_delete8_clicked();

    void on_plus9_clicked();

    void on_delete9_clicked();

    void on_plus10_clicked();

    void on_delete10_clicked();

    void on_plus11_clicked();

    void on_delete11_clicked();

    void on_plus12_clicked();

    void on_delete12_clicked();

    void on_plus13_clicked();

    void on_delete13_clicked();

    void on_delete14_clicked();

private:
    Ui::Cities *ui;
};

#endif // CITIES_H
