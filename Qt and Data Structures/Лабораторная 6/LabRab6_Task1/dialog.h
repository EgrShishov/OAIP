#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <vector>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_buttonBox_accepted();

    void on_spinBox_valueChanged(int arg1);

signals:
    void send_data(std::vector<std::pair<int,QString>>);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
