#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->btnPlus1->setText("+1");
    ui->lblCnt->setText("0");
    cnt = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnPlus1_clicked()
{
    QString s;
    cnt = cnt + 1;
    ui->lblCnt->setText(s.setNum(cnt));
}

