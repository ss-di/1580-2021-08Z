#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <string>
#include "about.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ifstream inpf("text.txt");
    int num;
    inpf >> num;
    QString s;
    s.setNum(num);
    ui->edtNum->setText(s);
    inpf.close();

    ifstream inpf2("text2.txt");
    string s2;
    inpf2 >> s2;
    QString s3;
    s3 = QString::fromUtf8(s2.c_str());
    ui->tedText->setText(s3);
    inpf2.close();

}

MainWindow::~MainWindow()
{
    ofstream outf("text.txt");
    int num = ui->edtNum->text().toInt();
    outf << num;
    outf.close();

    ofstream outf2("text2.txt");
    outf2 << ui->tedText->toPlainText().toStdString();
    outf2.close();

    delete ui;   
}


void MainWindow::on_btnAbout_clicked()
{
    About about_window;
    about_window.setModal(true);
    about_window.exec();
}

