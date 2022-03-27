
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <inputline.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Engine* ep;
    engEvalString(ep,"a=[1,2,3]");
    windowInit();
}

void MainWindow::windowInit()
{
    this->resize(2560,1440);
    {
        ui->inputLine_0->setVisible(false);
        ui->inputLine_1->setVisible(false);
        ui->inputLine_2->setVisible(false);
        ui->inputLine_3->setVisible(false);
        ui->inputLine_4->setVisible(false);
        ui->inputLine_5->setVisible(false);
        ui->inputLine_6->setVisible(false);
        ui->inputLine_7->setVisible(false);
        ui->inputLine_8->setVisible(false);
        ui->inputLine_9->setVisible(false);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeViewFileList_doubleClicked(const QModelIndex &index)
{
    ui->statusbar->showMessage(fileSystemModel->filePath(index),60000); //状态栏显示文件路径一分钟
/******加载模型******/
    runModule = loadExternal;

/*******************/
}


void MainWindow::on_tBtnOpen_clicked()
{
    if(fileSystemModel != nullptr)
    {
        delete fileSystemModel;
        fileSystemModel = nullptr;
    }
    fileSystemModel = new QFileSystemModel(this);
    fileSystemModel->setRootPath(QDir::currentPath());
    ui->treeViewFileList->setModel(fileSystemModel);
}


void MainWindow::on_tBtnSet_clicked()
{
    DialogSet* dialogSet = new DialogSet(this);
    dialogSet->setVisible(true);
    int ret = dialogSet->exec();
    if(ret == QDialog::Accepted)
    {
        u0 = dialogSet->getMagneticPermeability();
        epsi = dialogSet->getPermittivity();
        theta = dialogSet->getConductivity();
        c0 = dialogSet->getLightSpeed();
        acc = dialogSet->getAccuracy();
    }
    delete dialogSet;
}


void MainWindow::on_tBtnLoadSingleWire_clicked()
{
    runModule = loadInternal;
    modelType = SingleWire;
    ui->inputLine_0->setText("距地高度");
    ui->inputLine_0->addComboItem("M");
    ui->inputLine_0->setVisible(true);
    ui->inputLine_1->setText("线缆半径");
    ui->inputLine_1->addComboItem("M");
    ui->inputLine_1->setVisible(true);
    ui->inputLine_2->setText("线缆总长");
    ui->inputLine_2->addComboItem("M");
    ui->inputLine_2->setVisible(true);
    ui->inputLine_3->setText("转移阻抗（左）");
    ui->inputLine_3->addComboItem("V/A");
    ui->inputLine_3->setVisible(true);
    ui->inputLine_4->setText("转移阻抗（右）");
    ui->inputLine_4->addComboItem("V/A");
    ui->inputLine_4->setVisible(true);
    ui->inputLine_5->setText("入射电场强度");
    ui->inputLine_5->addComboItem("V/M");
    ui->inputLine_5->setVisible(true);
    ui->inputLine_6->setText("thetaP");
    ui->inputLine_6->addComboItem("°C");
    ui->inputLine_6->setVisible(true);
    ui->inputLine_7->setText("phiP");
    ui->inputLine_7->addComboItem("°C");
    ui->inputLine_7->setVisible(true);
    ui->inputLine_8->setText("thetaE");
    ui->inputLine_8->addComboItem("°C");
    ui->inputLine_8->setVisible(true);
    ui->toolBoxFunction->setCurrentIndex(0);
//    double h = 0.01;
//    double rw = 0.00025;
//    double L = 1;
//    double Zsh_SL = 100;
//    double Zsh_SR = 100;
//    double E0 = 1;
//    double thetaP = M_PI/2;
//    double phiP = -M_PI/2;
//    double thetaE = M_PI/2;
}


void MainWindow::on_tBtnRun_clicked()
{
    if(runModule == loadInternal)
    {
        Model* model = new Model();
        delete series; series = new QLineSeries();
        delete chartView; chartView = new QChartView();
        delete chart; chart = new QChart();
        delete axisX; axisX = new QLogValueAxis();
        delete axisY; axisY = new QValueAxis();
        switch (modelType)
        {
            case SingleWire:
                {
//                    if(ui->inputLine_0->)
                    parameter0 = ui->inputLine_0->getLine().toDouble();
                    parameter1 = ui->inputLine_1->getLine().toDouble();
                    parameter2 = ui->inputLine_2->getLine().toDouble();
                    parameter3 = ui->inputLine_3->getLine().toDouble();
                    parameter4 = ui->inputLine_4->getLine().toDouble();
                    parameter5 = ui->inputLine_5->getLine().toDouble();
                    parameter6 = ui->inputLine_6->getLine().toDouble()*M_PI/180;
                    parameter7 = ui->inputLine_7->getLine().toDouble()*M_PI/180;
                    parameter8 = ui->inputLine_8->getLine().toDouble()*M_PI/180;
                    QVector<QVector<double>> ret = model->sigleWireC(&parameter0,&parameter1,&parameter2,
                                                                     &parameter3,&parameter4,&parameter5,
                                                                     &parameter6,&parameter7,&parameter8,
                                                                     &u0,&epsi,&c0,&acc);
                    chart->setTitle("模型曲线图");
                    chartView->setChart(chart);
                    for(int i=0;i<ret[0].size();i++)
                        series->append(ret[0][i],ret[1][i]);
                    series->setName("单线缆模型");
                    chart->addSeries(series);
                    axisX->setBase(10);
                    axisX->setRange(0,5e10);
                    axisX->setTitleText("Frequency");
                    axisY->setRange(-140,0);
                    axisY->setTitleText("Modal Currents Magnitude");
                    chart->addAxis(axisX,Qt::AlignBottom);
                    chart->addAxis(axisY,Qt::AlignLeft);
                    series->attachAxis(axisX);
                    series->attachAxis(axisY);
                    ui->tabWidView->removeTab(1);
                    ui->tabWidView->insertTab(1,chartView,"结果");
                    ui->tabWidView->setCurrentIndex(1);
                    break;
                }
            default: break;
        }
    }
    if(runModule == loadExternal)
    {

    }
    if(runModule == paint)
    {

    }
}

void MainWindow::on_tBtnLoadExe_clicked()
{
    QString path = QInputDialog::getText(NULL,"路径输入","请输入exe文件路径");
    process = new QProcess(this);
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = true;
    bool bRet = CreateProcess(
                NULL,
                (LPWSTR)path.toStdWString().c_str(),
                NULL,
                NULL,
                FALSE,
                CREATE_NEW_CONSOLE,
                NULL,
                NULL, &si, &pi);
    Sleep(1000);
    WId wid = (WId)FindWindow(L"Notepad", NULL);//获取窗口句柄
    m_window = QWindow::fromWinId(wid);
    m_window->setFlags(m_window->flags() | Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    widget = new QWidget();
    m_widget = QWidget::createWindowContainer(m_window, widget);
    ui->tabWidView->removeTab(2);
    ui->tabWidView->insertTab(2,m_widget,"exe加载");
    ui->tabWidView->setCurrentIndex(2);
}

