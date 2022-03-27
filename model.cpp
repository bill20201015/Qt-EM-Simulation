#include "model.h"

Model::Model(QObject *parent)
    : QObject{parent}
{

}

QVector<QVector<double>> Model::sigleWireC(double *h, double *rw, double *L, double *Zsh_SL, double *Zsh_SR, double *E0, double *thetaP, double *phiP, double *thetaE, double *u0, double *epsi, double *c0, double *acc)
{
    QVector<QVector<double>> ret;
    if(!singleLineInitialize())
        {
            QMessageBox::information(NULL,"Error","DLL initialization failed");
            return ret;
        }
    /***数据转换c++到matlab***/
        mwArray matrixH(1,1,mxDOUBLE_CLASS);
        matrixH.SetData(h,1);
        mwArray matrixRW(1,1,mxDOUBLE_CLASS);
        matrixRW.SetData(rw,1);
        mwArray matrixL(1,1,mxDOUBLE_CLASS);
        matrixL.SetData(L,1);
        mwArray matrixZSHSL(1,1,mxDOUBLE_CLASS);
        matrixZSHSL.SetData(Zsh_SL,1);
        mwArray matrixZSHSR(1,1,mxDOUBLE_CLASS);
        matrixZSHSR.SetData(Zsh_SR,1);
        mwArray matrixE0(1,1,mxDOUBLE_CLASS);
        matrixE0.SetData(E0,1);
        mwArray matrixTHETAP(1,1,mxDOUBLE_CLASS);
        matrixTHETAP.SetData(thetaP,1);
        mwArray matrixPHIP(1,1,mxDOUBLE_CLASS);
        matrixPHIP.SetData(phiP,1);
        mwArray matrixTHETAE(1,1,mxDOUBLE_CLASS);
        matrixTHETAE.SetData(thetaE,1);
        mwArray matrixU0(1,1,mxDOUBLE_CLASS);
        matrixU0.SetData(u0,1);
        mwArray matrixEPSI(1,1,mxDOUBLE_CLASS);
        matrixEPSI.SetData(epsi,1);
        mwArray matrixC0(1,1,mxDOUBLE_CLASS);
        matrixC0.SetData(c0,1);
        mwArray matrixACC(1,1,mxDOUBLE_CLASS);
        matrixACC.SetData(acc,1);
    /************************/

        mwArray X(1,500,mxDOUBLE_CLASS);
        mwArray Y(1,500,mxDOUBLE_CLASS);
        singleLine(2,X,Y,
                   matrixU0,matrixEPSI,matrixC0,matrixH,
                   matrixRW,matrixL,matrixZSHSL,matrixZSHSR,
                   matrixE0,matrixTHETAP,matrixPHIP,matrixTHETAE,matrixACC);
        QVector<double> x;
        QVector<double> y;
        for(int i=1;i<=500;i++)
        {
            x.push_back(X.Get(1,i));
            y.push_back(Y.Get(1,i));
        }
        ret.push_back(x);
        ret.push_back(y);
        return ret;
}
