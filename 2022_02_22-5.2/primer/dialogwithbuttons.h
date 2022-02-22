#ifndef DIALOGWITHBUTTONS_H
#define DIALOGWITHBUTTONS_H

#include <QDialog>

namespace Ui {
class DialogWithButtons;
}

class DialogWithButtons : public QDialog
{
    Q_OBJECT

public:
    explicit DialogWithButtons(QWidget *parent = nullptr);
    ~DialogWithButtons();

private slots:
    void on_btnClose_clicked();

private:
    Ui::DialogWithButtons *ui;
};

#endif // DIALOGWITHBUTTONS_H
