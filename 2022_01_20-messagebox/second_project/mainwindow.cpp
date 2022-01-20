#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

#define MB QMessageBox

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


void MainWindow::on_btnMessage_clicked()
{
/*    QMessageBox::about(this, "Заголовок", "Тест сообщения.");
    ui->lblAbout->setText("Done.");
    QMessageBox::critical(this, "Заголовок", "Тест сообщения.");
    ui->lblCrit->setText("Done.");
    QMessageBox::information(this, "Заголовок", "Тест сообщения.");
    ui->lblInfo->setText("Done.");
    QMessageBox::warning(this, "Заголовок", "Тест сообщения.");
    ui->lblWarn->setText("Done.");*/

    QMessageBox::StandardButton res = MB::question(this, "Ваш вопрос", "Настроение хорошее?", MB::No | MB::Yes |  MB::Abort);
    if (res == MB::Yes)
        QMessageBox::about(this, "Заголовок", "YES");
    else if (res == MB::No)
        QMessageBox::about(this, "Заголовок", "NO");
    else
        QMessageBox::about(this, "Заголовок", "Выбора нет");

}

