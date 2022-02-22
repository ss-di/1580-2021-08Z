#include "dialogwithbuttons.h"
#include "ui_dialogwithbuttons.h"
extern QString text;

DialogWithButtons::DialogWithButtons(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogWithButtons)
{
    ui->setupUi(this);
    ui -> lblText -> setText(text);
}

DialogWithButtons::~DialogWithButtons()
{
    delete ui;
}

void DialogWithButtons::on_btnClose_clicked()
{
    close();
}

