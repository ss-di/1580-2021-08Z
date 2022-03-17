#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

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


void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter p(this);
    p.drawLine(10, 20, 1000, 40);
    p.drawPoint(20, 30);
    p.setBrush(QBrush(Qt::red, Qt::CrossPattern));
    p.drawRect(20, 40, 50, 100);
    p.setPen(Qt::red);
    p.drawEllipse(80, 40, 50, 100);
    p.drawArc(140, 40, 100, 100, 30*16, 150*16);
    p.setBrush(Qt::green);
    p.drawPie(140, 150, 100, 100, 30*16, 150*16);
    //p.setPen(Qt::DashDotDotLine);
    p.setPen(QPen(QBrush(Qt::blue, Qt::Dense3Pattern),
                  5.5));
    p.drawChord(10, 150, 100, 100, 30*16, 100*16);
    p.drawText(105, 90, "Hello");
    p.eraseRect(10, 10, 50, 50);
}
