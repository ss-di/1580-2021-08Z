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
    void on_btnAdd_clicked();

    void on_btnInsert_clicked();

    void on_btnSetCurrent_clicked();

    void on_lstPrimer_itemSelectionChanged();

    void on_lstPrimer_2_itemSelectionChanged();

    void on_btnChange_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
