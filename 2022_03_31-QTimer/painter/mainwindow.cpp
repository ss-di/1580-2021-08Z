#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer1 = new QTimer();
    connect(timer1, SIGNAL(timeout()), this, SLOT(Alarm1()));
    timer1 -> start(10);

    timer2 = new QTimer();
    connect(timer2, SIGNAL(timeout()), this, SLOT(Alarm2()));
    timer2 -> start(20);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    timer1 -> stop();
}

void MainWindow::Alarm1()
{
    cnt1 += 1;
    QString s;
    s.setNum(cnt1);
    ui -> lblCount -> setText(s);
    if (napr == 1)
        x += 1;
    else
        x -= 1;
    repaint();
    if (x > 700 && napr == 1)
        napr = 2;
    else if (x < 100 && napr == 2)
        napr = 1;

}

void MainWindow::Alarm2()
{
    switch(napr2){
        case 1:
            x2 += 1;
            if (x2 > 500)
                napr2 = 2;
            break;
        case 2:
            y2 += 1;
            if (y2 > 500)
                napr2 = 3;
            break;
        case 3:
            x2 -= 1;
            if (x2 < 300)
                napr2 = 4;
            break;
        case 4:
            y2 -= 1;
            if (y2 < 200)
                napr2 = 1;
            break;
    }
    repaint();
}

void MainWindow::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter p(this);
    p.drawLine(10, 20, 1000, 40);
    p.drawPoint(20, 30);
    p.setBrush(QBrush(Qt::red, Qt::CrossPattern));
    p.drawRect(20, 40, 50, 100);
    p.setPen(Qt::red);
    p.drawEllipse(x2, y2, 50, 100);
    p.drawArc(140, 40, 100, 100, 30*16, 150*16);
    p.setBrush(Qt::green);
    p.drawPie(x, y, 100, 100, 30*16, 150*16);
    //p.setPen(Qt::DashDotDotLine);
    p.setPen(QPen(QBrush(Qt::blue, Qt::Dense3Pattern),
                  5.5));
    p.drawChord(10, 150, 100, 100, 30*16, 100*16);
    p.drawText(105, 90, "Hello");
    p.eraseRect(10, 10, 50, 50);
}
