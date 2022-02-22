#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogwithbuttons.h"
extern QString text;

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

void MainWindow::on_btnNewWindow_clicked()
{
    text = ui -> edtText -> text();
    DialogWithButtons w;
    w.setModal(true);
    w.exec();
}

