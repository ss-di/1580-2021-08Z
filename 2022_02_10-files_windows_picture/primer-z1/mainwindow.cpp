#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include "about.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ifstream f("num.txt");
    int n;
    f >> n;
    QString s;
    s.setNum(n);
    ui ->edtNum->setText(s);
    f.close();

}

MainWindow::~MainWindow()
{
    ofstream f("num.txt");
    QString s = ui ->edtNum->text();
    int n = s.toInt();
    f << n;
    f.close();

    delete ui;
}


void MainWindow::on_btnAbout_clicked()
{
    About win;
    win.setModal(true);
    win.exec();
}

