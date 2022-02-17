#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_btnAdd_clicked()
{
    QString s;
    s = ui -> edtText -> text();
    ui -> lstPrimer -> addItem(s);
}


void MainWindow::on_btnIns_clicked()
{
    QString s;
    s = ui -> edtText -> text();
    int p;
    p = ui -> edtPos -> text().toInt();
    ui -> lstPrimer -> insertItem(p, s);
}


void MainWindow::on_pushButton_clicked()
{
    int p;
    p = ui -> edtPos -> text().toInt();
    ui -> lstPrimer -> takeItem(p);
}


void MainWindow::on_btnCur_clicked()
{
    ui -> btnCur -> setText(ui -> lstPrimer -> currentItem() -> text());
}


void MainWindow::on_lstPrimer_itemSelectionChanged()
{
    ui -> btnCur -> setText(ui -> lstPrimer -> currentItem() -> text());
    ui -> lstPrimer_2 -> setCurrentRow(ui -> lstPrimer -> currentRow());
}


void MainWindow::on_btnSetCur_clicked()
{
    int p;
    p = ui -> edtPos -> text().toInt();
    ui -> lstPrimer -> setCurrentRow(p);
}


void MainWindow::on_lstPrimer_2_itemSelectionChanged()
{
    ui -> lstPrimer -> setCurrentRow(ui -> lstPrimer_2 -> currentRow());
}

