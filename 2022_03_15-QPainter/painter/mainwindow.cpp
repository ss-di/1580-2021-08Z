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
    p.drawPoint(10, 5);
    p.drawLine(50, 100, 100, 50);
    p.drawRect(100, 100, 50, 200);
    p.setBrush( QBrush(Qt::green, Qt::CrossPattern));
    p.drawEllipse(200, 100, 50, 200);
    p.setPen(Qt::red);
    p.drawArc(300, 100, 100, 100, 45*16, 90*16);
    p.setPen( QPen(QBrush(Qt::yellow, Qt::Dense7Pattern), 50));
    p.drawPie(400, 100, 100, 100, 45*16, 90*16);
    p.setPen(Qt::blue);
    p.drawChord(500, 100, 100, 100, 45*16, 90*16);
    p.drawText(600, 100, "Привет!!!");
    //p.eraseRect(100, 100, 200, 150);
}
