#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vector"
#include "string"
#include "fstream"
#include "qmessagebox.h"

using namespace std;
vector<string> users;

string qs2s(QString qs){
    return qs.toStdString();
}

QString s2qs(string s){
    return QString::fromUtf8(s.c_str());
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    string s;
    ifstream input_file("data.csv");
    while (getline(input_file, s))
        users.push_back(s);
    input_file.close();

    for(int i = 0; i < int(users.size()); i += 1)
        ui->lstUser->addItem(s2qs(users[i]));

}

MainWindow::~MainWindow()
{
    ofstream out_file("data.csv");
    for (int i = 0; i < long(users.size()); i+=1)
        out_file << users[i] << endl;
    out_file.close();

    delete ui;
}

string GetWordFromData(string data, int n){
    for (int i = 1; i < n; i+=1)
        data.erase(0, data.find(";")+1);
    return data.substr(0, data.find(";"));
}

string GetNameFromData(string data){
    return GetWordFromData(data, 3);
}

string GetLoginFromData(string data){
    return GetWordFromData(data, 4);
}

string GetDataByLogin(string log){
    for (int i = 1; i < long(users.size()); i+=1)
        if (log == GetLoginFromData(users[i]))
            return users[i];
    return "";
}

void MainWindow::on_btnCheck_clicked()
{
    QString qlog = ui -> edtLogin -> text();
    string log = qs2s(qlog);
    string res = GetDataByLogin(log);
    if (res == "")
        QMessageBox::critical(this, "Ошибка", "Пользователь не найден");
    else {
        string name = GetNameFromData(res);
        QString qname = s2qs(name);
        QMessageBox::information(this, "Ok", "Hello, " + qname + "!" );
    }
}


void MainWindow::on_btnDel_clicked()
{
    int pos = ui->lstUser->currentRow();
    ui->lstUser->takeItem(pos);

    for(int i = pos; i < int(users.size())-1; i += 1)
        users[i] = users[i + 1];
    users.resize(users.size()-1);

}


void MainWindow::on_btnErase_clicked()
{
    int pos = ui->lstUser->currentRow();
    ui->lstUser->takeItem(pos);
    users.erase(users.begin()+pos);
}


void MainWindow::on_lstUser_itemSelectionChanged()
{
    ui ->edtUser->setText(ui->lstUser->currentItem()->text());
}


void MainWindow::on_btnUpdate_clicked()
{
    ui->lstUser->currentItem()->setText(ui ->edtUser->text());
    int pos = ui->lstUser->currentRow();
    users[pos] = qs2s(ui ->edtUser->text());
}

