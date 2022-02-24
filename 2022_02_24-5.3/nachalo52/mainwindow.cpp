#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vector"
#include "string"
#include "fstream"
#include "qmessagebox.h"

using namespace std;
vector<string> users;

QString s2qs(string s){
    return QString::fromUtf8(s.c_str());
}

string qs2s(QString qs){
    return qs.toStdString();
}

void UpdateUsers(QListWidget* lst){
    lst -> clear();
    for(int i = 0; i < int(users.size()); i += 1)
        lst -> addItem(s2qs(users[i]));
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

    UpdateUsers(ui -> lstUsers);
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
    string log = qlog.toStdString();
    string res = GetDataByLogin(log);
    if (res == "")
        QMessageBox::critical(this, "Ошибка", "Пользователь не найден");
    else {
        string name = GetNameFromData(res);
        QString qname = QString::fromUtf8(name.c_str());
        QMessageBox::information(this, "Ok", "Hello, " + qname + "!" );
    }
}


void MainWindow::on_btnDelete_clicked()
{
    int pos = ui -> lstUsers -> currentRow();
//    ui -> lstUsers ->takeItem(pos);

    for(int i = pos; i < int(users.size())-1; i += 1)
        users[i] = users[i + 1];
    users.resize(users.size() - 1);

    UpdateUsers(ui -> lstUsers);
}


void MainWindow::on_btnDeleteErase_clicked()
{
    int pos = ui -> lstUsers -> currentRow();

    users.erase(users.begin()+pos);

    UpdateUsers(ui -> lstUsers);

}


void MainWindow::on_lstUsers_itemSelectionChanged()
{
    ui -> edtUser -> setText(ui -> lstUsers -> currentItem() -> text());
}


void MainWindow::on_btnUpdate_clicked()
{
    int pos = ui -> lstUsers -> currentRow();
    ui -> lstUsers->currentItem() -> setText(ui -> edtUser -> text());
    users[pos] = qs2s(ui -> edtUser -> text());
}

