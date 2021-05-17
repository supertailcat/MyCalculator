#ifndef MYCALCULATOR_H
#define MYCALCULATOR_H

#include <QDialog>
#include <QString>
#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MyCalculator; }
QT_END_NAMESPACE

class MyCalculator : public QDialog
{
    Q_OBJECT

public:
    MyCalculator(QWidget *parent = nullptr);
    ~MyCalculator();

private slots:
    void on_bt1_clicked();

    void on_bt2_clicked();

    void on_bt9_clicked();

    void on_bt3_clicked();

    void on_bt4_clicked();

    void on_bt5_clicked();

    void on_bt6_clicked();

    void on_bt7_clicked();

    void on_bt8_clicked();

    void on_bt0_clicked();

    void on_dotbt_clicked();

    void on_plusbt_clicked();

    void on_subbt_clicked();

    void on_multbt_clicked();

    void on_divbt_clicked();

    void on_lprbt_clicked();

    void on_rprbt_clicked();

    void on_eqlbt_clicked();

    void on_backbt_clicked();

    void on_cleanbt_clicked();

private:
    Model * model;
    Ui::MyCalculator *ui;
    QString text;
};
#endif // MYCALCULATOR_H
