#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPushButton>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton *btn = new QPushButton("123",this);
    btn->move(100,100);
    //菜单栏   只有一个
    QMenuBar *bar = this->menuBar();
    //创建菜单
    QMenu *fileMenu = bar->addMenu("file");
    QMenu *editMenu = bar->addMenu("edit");
    //创建菜单项
    QAction *newAction = fileMenu->addAction("new");
    //添加分割线
    fileMenu->addSeparator();
    QAction *openAction = fileMenu->addAction("open");
    //工具栏
    QToolBar *toolBar = new QToolBar(this);
    this->addToolBar(Qt::LeftToolBarArea,toolBar);
    toolBar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);
    toolBar->setFloatable(false);
    //设置移动总开关
    toolBar->setFloatable(false);
    toolBar->setMovable(false);
    //添加部件
    toolBar->addAction(newAction);
    toolBar->addSeparator();
    toolBar->addAction(openAction);
    //状态栏 一个
    QStatusBar *stBar = this->statusBar();
    QLabel *label = new QLabel("left",this);
    stBar->addWidget(label);
    //锚接部件
    QDockWidget *dock = new QDockWidget("dock",this);
    this->addDockWidget(Qt::BottomDockWidgetArea,dock);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    if(QMessageBox::Yes == QMessageBox::question(this,"message","Are you sure?",QMessageBox::Yes,QMessageBox::No))
    {
        qDebug() << "选择yes";
    }
    else {
        qDebug() <<"choose no";
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
