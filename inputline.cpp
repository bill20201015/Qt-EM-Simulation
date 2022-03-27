#include "inputline.h"
#include "ui_inputline.h"

//InputLine::InputLine(QWidget *parent) :
//    QWidget(parent),
//    ui(new Ui::InputLine)
//{
//    ui->setupUi(this);
//}

InputLine::InputLine(QWidget *parent, bool isCombox):
    QWidget(parent),
    ui(new Ui::InputLine)
{
    ui->setupUi(this);
    if(!isCombox)
    {ui->comboBox->hide();}


}


void InputLine::setText(QString text)
{
    ui->label->setText(text);
}

QString InputLine::getLine()
{
    return ui->lineEdit->text();
}

void InputLine::addComboItem(QString text)
{
    ui->comboBox->addItem(text);
}

InputLine::~InputLine()
{
    delete ui;
}

void InputLine::hideCombox()
{
    ui->comboBox->hide();
}
