#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QtMath>
#include <QMessageBox>
#include <QDebug>
#include "singleLine.h"

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);
public:
    enum modelType{sigleWire,None};
    static modelType model;
    QVector<QVector<double>> sigleWireC(double* h,double* rw,double* L,double* Zsh_SL,
                   double* Zsh_SR,double* E0,double* thetaP,double* phiP,double* thetaE,
                   double* u0,double* epsi,double* c0,double* acc);
    //距地高度、半径、长度、左端阻抗、右端阻抗、电场强度、thetaP、phiP、thetaE、电导率、介电常数、光速、精度
signals:

};

#endif // MODEL_H
