#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Fig {
    long x, y, napr;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    QTimer *timer1;
    QTimer *timer2;
    long cnt1=0;
    Fig f1;
    std::vector<Fig> v;
    long x2 = 100, y2 = 200, napr2=1;
    void keyPressEvent(QKeyEvent *e);
    long cnt_key=0;
    long x3 = 100, y3 = 400;

private slots:
    void Alarm1();
    void Alarm2();


    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
