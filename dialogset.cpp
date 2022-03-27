#include "dialogset.h"
#include "ui_dialogset.h"

DialogSet::DialogSet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSet)
{
    ui->setupUi(this);
}

DialogSet::~DialogSet()
{
    delete ui;
}

double DialogSet::getPermittivity()
{
    if(!ui->inputPermittivity->text().isEmpty()&&ui->inputPermittivity->text().toDouble()>0)
    {
          return ui->inputPermittivity->text().toDouble();
    }
    return 8.85e-12;
}

double DialogSet::getConductivity()
{
    if(!ui->inputConductivity->text().isEmpty()&&ui->inputConductivity->text().toDouble()>0)
    {
          return ui->inputConductivity->text().toDouble();
    }
    return 0;
}

double DialogSet::getMagneticPermeability()
{
    if(!ui->inputMagneticPermeability->text().isEmpty()&&ui->inputMagneticPermeability->text().toDouble()>0)
    {
          return ui->inputMagneticPermeability->text().toDouble();
    }
    return M_PI*4e-7;
}

double DialogSet::getLightSpeed()
{
    if(!ui->inputLightSpeed->text().isEmpty()&&ui->inputLightSpeed->text().toDouble()>0)
    {
          return ui->inputLightSpeed->text().toDouble();
    }
    return 299792458;
}

double DialogSet::getAccuracy()
{
    if(!ui->inputAccuracy->text().isEmpty()&&ui->inputAccuracy->text().toDouble()>0)
    {
          return ui->inputAccuracy->text().toDouble();
    }
    return 0.00001;
}
