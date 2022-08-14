#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QMessageBox>
#include<QFontDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(Qt::red,this,tr("Color Choose Dialog!"));
    qDebug()<< "Color:" << color;
}

void MainWindow::on_pushButton_2_clicked()
{
    if(QMessageBox::Yes == QMessageBox::warning(this,
                                                "warning!", "warning!!",
                                                QMessageBox::Yes,
                                                QMessageBox::No))
    {
        qDebug() << "yes,rest!";
    }
    else {
        qDebug() << "no,work!";
    }

}

void MainWindow::on_pushButton_3_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Times", 12),
                         this, "Choosing font");
}
