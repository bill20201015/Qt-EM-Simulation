#include "mainwindow.h"

#include <QApplication>

#include <QDebug>
#include <QWidget>
#include <QProcess>
#include <QWindow>
#include <Windows.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    QWidget *widget = new QWidget;
//    QProcess m_process;
//    m_process.start("C:/Windows/System32/notepad.exe",QStringList()<<""); // 1.电脑中记事本的路径

//    if(!m_process.waitForFinished(3000))
//    {
//        qDebug()<<"--------";
//    }
//    Sleep(1000);
//    WId wid = (WId)FindWindow(L"Notepad", NULL); // 2.需要嵌入的exe的界面的类名称
//    QWindow *m_window = QWindow::fromWinId(wid);
//    m_window->setFlags(m_window->flags() | Qt::CustomizeWindowHint | Qt::WindowTitleHint); //这边可以设置一下属性
//    QWidget *m_widget  = QWidget::createWindowContainer(m_window, widget);
//    m_widget->setMinimumSize(500, 500);//窗口大小
//    widget->show();
    return a.exec();
}
