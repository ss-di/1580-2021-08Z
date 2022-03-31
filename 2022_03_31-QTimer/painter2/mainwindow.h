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
    QTimer *t1, *t2;
    long cnt = 0, x = 140, y = 150, napr = 1;
    long x2 = 140, y2 = 150, napr2 = 1;

private slots:
    void on_pushButton_clicked();
    void Alarm1();
    void Alarm2();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
