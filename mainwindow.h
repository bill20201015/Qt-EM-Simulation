#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QtCharts>

#include "model.h"
#include "dialogset.h"

#include <QDebug>
#include <QWidget>
#include <QProcess>
#include <QWindow>
#include <Windows.h>
#include <QInputDialog>

#include <mat.h>
#include <engine.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void windowInit();
    ~MainWindow();

private slots:
    void on_treeViewFileList_doubleClicked(const QModelIndex &index);

    void on_tBtnOpen_clicked();

    void on_tBtnSet_clicked();

    void on_tBtnLoadSingleWire_clicked();

    void on_tBtnRun_clicked();
    void on_tBtnLoadExe_clicked();

private:
    Ui::MainWindow *ui;
    QFileSystemModel* fileSystemModel = nullptr;
    enum tBtnRunModel{loadInternal,loadExternal,paint};//运行按钮的三种状态，计算加载的内部模型(单线缆)、计算加载的外部模型（step文件）、计算绘制的模型
    tBtnRunModel runModule = loadInternal;
/***2D***/
    enum ModelType{SingleWire,None};
    ModelType modelType = None;
    QLineSeries* series = nullptr;
    QChartView* chartView = nullptr;
    QChart* chart = nullptr;
    QLogValueAxis* axisX = nullptr;
    QValueAxis* axisY = nullptr;
    double xStart,xEnd,yStart,yEnd;
/********/
public:
    double u0 = 4*M_PI*1e-7; //磁导率，默认真空
    double epsi = 8.85*1e-12; //介电常数，默认真空
    double theta = 0; //电导率
    double c0 = 299792458; //光速
    double acc = 0.00001; //精度
private:
    double parameter0;
    double parameter1;
    double parameter2;
    double parameter3;
    double parameter4;
    double parameter5;
    double parameter6;
    double parameter7;
    double parameter8;
    double parameter9;
private:
    QWidget* widget = nullptr;
    QWidget* m_widget = nullptr;
    QWindow* m_window = nullptr;
    QProcess* process = nullptr;
};
#endif // MAINWINDOW_H
