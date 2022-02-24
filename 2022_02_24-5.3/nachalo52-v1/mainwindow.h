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

private slots:
    void on_btnCheck_clicked();

    void on_btnDel_clicked();

    void on_btnErase_clicked();

    void on_lstUser_itemSelectionChanged();

    void on_btnUpdate_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
