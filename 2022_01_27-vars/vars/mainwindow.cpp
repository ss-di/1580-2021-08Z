#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnPlusOne_clicked()
{
     QString s;
     s = ui->lblCount->text();
     long cnt = s.toLong();
     cnt = cnt + 1;
     s.setNum(cnt);
     ui->lblCount->setText(s);
}

