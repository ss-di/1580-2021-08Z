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


void MainWindow::on_btnInsert_clicked()
{
    QString s;
    int pos;
    s = ui -> edtText -> text();
    pos = ui -> edtPos -> text().toInt();
    ui -> lstPrimer -> insertItem(pos, s);
}


void MainWindow::on_btnSetCurrent_clicked()
{
    QString s;
    int pos;
    pos = ui -> edtPos -> text().toInt();
    ui -> lstPrimer -> setCurrentRow(pos);
}

void MainWindow::on_lstPrimer_itemSelectionChanged()
{
    ui -> btnSetCurrent -> setText(ui -> lstPrimer -> currentItem() -> text());
    QString s;
    int pos;
    pos = ui -> lstPrimer -> currentRow();
    ui -> lstPrimer_2 -> setCurrentRow(pos);
}


void MainWindow::on_lstPrimer_2_itemSelectionChanged()
{
    ui -> lstPrimer -> setCurrentRow(ui -> lstPrimer_2 -> currentRow());
}


void MainWindow::on_btnChange_clicked()
{
    QString s;
    int pos;
    s = ui -> edtText -> text();
    pos = ui -> edtPos -> text().toInt();
    ui -> lstPrimer -> item(pos) -> setText(s);
}

