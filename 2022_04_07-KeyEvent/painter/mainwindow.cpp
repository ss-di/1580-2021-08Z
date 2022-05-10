#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    f1.x = 100;
    f1.y = 200;
    f1.napr=1;
    v.resize(2);
    v[0] = f1;
    v[1].x = 100;
    v[1].y = 100;
    v[1].napr = 1;
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


void MainWindow::Alarm1()
{
    cnt1 += 1;
    QString s;
    s.setNum(cnt1);
    ui -> lblCount -> setText(s);
    if (f1.napr == 1)
        f1.x += 1;
    else
        f1.x -= 1;
    repaint();
    if (f1.x > 700 && f1.napr == 1)
        f1.napr = 2;
    else if (f1.x < 100 && f1.napr == 2)
        f1.napr = 1;

}

void MainWindow::Alarm2()
{
    for (long i = 0; i < long(v.size()); i += 1)
        v[i].x += 1+i;
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
    if (cnt_key % 2 == 0)
        p.drawLine(10, 20, 1000, 40);
    p.drawPoint(20, 30);
    p.setBrush(QBrush(Qt::red, Qt::CrossPattern));
    p.drawRect(20, 40, 50, 100);
    p.setPen(Qt::red);
    for (long i = 0; i < long(v.size()); i += 1)
        p.drawEllipse(v[i].x, v[i].y, 50, 100);
    p.drawArc(140, 40, 100, 100, 30*16, 150*16);
    p.setBrush(Qt::green);
    p.drawPie(f1.x, f1.y, 100, 100, 30*16, 150*16);
    //p.setPen(Qt::DashDotDotLine);
    p.setPen(QPen(QBrush(Qt::blue, Qt::Dense3Pattern),
                  5.5));
    p.drawChord(x3, y3, 100, 100, 30*16, 100*16);
    p.drawText(105, 90, "Hello");
    p.eraseRect(10, 10, 50, 50);
}

void MainWindow::keyPressEvent(QKeyEvent *e){
    cnt_key += 1;
    QString s;
    s.setNum(cnt_key);
    ui -> lblCountKey -> setText(s);
    switch (e->key()){
        case Qt::Key_Up:
           y3 -= 1;
           break;
        case Qt::Key_Down:
           y3 += 1;
           break;
        case Qt::Key_Left:
           x3 -= 1;
           break;
        case Qt::Key_Right:
           x3 += 1;
           break;
    }
    repaint();
}

void MainWindow::on_pushButton_clicked()
{
    timer1 -> stop();
}

