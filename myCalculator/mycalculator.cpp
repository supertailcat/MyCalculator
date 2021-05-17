#include "mycalculator.h"
#include "ui_mycalculator.h"

MyCalculator::MyCalculator(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyCalculator)
{
    ui->setupUi(this);
    this->text = "";
}

MyCalculator::~MyCalculator()
{
    delete ui;
}

void MyCalculator::on_bt1_clicked()
{
    if(this->text.endsWith(')'))
        return;
    this->text = this->text + this->ui->bt1->text();
    this->ui->label->setText(text);
}

void MyCalculator::on_bt2_clicked()
{
    if(this->text.endsWith(')'))
        return;
    this->text = this->text + this->ui->bt2->text();
    this->ui->label->setText(text);
}

void MyCalculator::on_bt3_clicked()
{
    if(this->text.endsWith(')'))
        return;
    this->text = this->text + this->ui->bt3->text();
    this->ui->label->setText(text);
}

void MyCalculator::on_bt4_clicked()
{
    if(this->text.endsWith(')'))
        return;
    this->text = this->text + this->ui->bt4->text();
    this->ui->label->setText(text);
}

void MyCalculator::on_bt5_clicked()
{
    if(this->text.endsWith(')'))
        return;
    this->text = this->text + this->ui->bt5->text();
    this->ui->label->setText(text);
}

void MyCalculator::on_bt6_clicked()
{
    if(this->text.endsWith(')'))
        return;
    this->text = this->text + this->ui->bt6->text();
    this->ui->label->setText(text);
}

void MyCalculator::on_bt7_clicked()
{
    if(this->text.endsWith(')'))
        return;
    this->text = this->text + this->ui->bt7->text();
    this->ui->label->setText(text);
}

void MyCalculator::on_bt8_clicked()
{
    if(this->text.endsWith(')'))
        return;
    this->text = this->text + this->ui->bt8->text();
    this->ui->label->setText(text);
}

void MyCalculator::on_bt9_clicked()
{
    if(this->text.endsWith(')'))
        return;
    this->text = this->text + this->ui->bt9->text();
    this->ui->label->setText(text);
}

void MyCalculator::on_bt0_clicked()
{
    if(this->text == "")
        return;
    if(this->text.endsWith(')'))
        return;
    if(this->text.endsWith('0') && !this->text.at(this->text.length() - 2).isNumber() && !(this->text.at(this->text.length() - 2) == '.'))
        return;
    this->text = this->text + this->ui->bt0->text();
    this->ui->label->setText(text);
}

void MyCalculator::on_dotbt_clicked()
{
    if(this->text.length() == 0)
        this->text = "0";
    QString tempstr = this->text;
    while(this->text.at(tempstr.length() - 1).isNumber())
    {
        tempstr = tempstr.mid(0, tempstr.length() - 1);
        if(tempstr.length() == 0)
            goto add;
    }
    if(this->text.at(tempstr.length() - 1) == '.')
        return;
    else
    {
add:
        this->text = this->text + this->ui->dotbt->text();
        this->ui->label->setText(text);
    }
}

void MyCalculator::on_plusbt_clicked()
{
    if(this->text.length() == 0)
        return;
    if(this->text.at(this->text.length() - 1).isNumber() || this->text.endsWith(')'))
    {
        this->text = this->text + this->ui->plusbt->text();
        this->ui->label->setText(text);
    }
}

void MyCalculator::on_subbt_clicked()
{
    if(this->text.length() == 0)
        return;
    if(this->text.at(this->text.length() - 1).isNumber() || this->text.endsWith(')'))
    {
        this->text = this->text + this->ui->subbt->text();
        this->ui->label->setText(text);
    }
}

void MyCalculator::on_multbt_clicked()
{
    if(this->text.length() == 0)
        return;
    if(this->text.at(this->text.length() - 1).isNumber() || this->text.endsWith(')'))
    {
        this->text = this->text + this->ui->multbt->text();
        this->ui->label->setText(text);
    }
}

void MyCalculator::on_divbt_clicked()
{
    if(this->text.length() == 0)
        return;
    if(this->text.at(this->text.length() - 1).isNumber() || this->text.endsWith(')'))
    {
        this->text = this->text + this->ui->divbt->text();
        this->ui->label->setText(text);
    }
}

void MyCalculator::on_lprbt_clicked()
{
    if(this->text.length() == 0 || (!this->text.at(this->text.length() - 1).isNumber() && !this->text.endsWith(')') && !this->text.endsWith('.')))
    {
        this->text = this->text + this->ui->lprbt->text();
        this->ui->label->setText(text);
    }
}

void MyCalculator::on_rprbt_clicked()
{
    if((this->text.length() != 0) && (this->text.at(this->text.length() - 1).isNumber() || this->text.endsWith(')')) && (this->text.count('(') > this->text.count(')')))
    {
        this->text = this->text + this->ui->rprbt->text();
        this->ui->label->setText(text);
    }
}

void MyCalculator::on_eqlbt_clicked()
{
    this->ui->resultlabel->setText("=" + this->model->calculate(text));
    this->text = "";
}

void MyCalculator::on_backbt_clicked()
{
    this->text = this->text.mid(0, this->text.length() - 1);
    if(this->text != "")
    {
        this->ui->label->setText(text);
    }
    else
    {
        this->ui->label->setText("0");
    }
}

void MyCalculator::on_cleanbt_clicked()
{
    this->text = "";
    this->ui->label->setText("0");
}
