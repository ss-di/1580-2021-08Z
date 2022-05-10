#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    QTimer *timer1;
    QTimer *timer2;
    long cnt1=0, x = 100, y = 200, napr=1;
    long x2 = 100, y2 = 200, napr2=1;

private slots:
    void on_pushButton_clicked();
    void Alarm1();
    void Alarm2();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
