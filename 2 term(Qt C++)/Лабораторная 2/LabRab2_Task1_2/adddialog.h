#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QDate>
#include <shop.h>
#include <QTextDocument>
#include <QTextBlock>
#include <QMessageBox>
#include <QCloseEvent>
#include <QPushButton>

namespace Ui {
class addDialog;
}

class addDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addDialog(QWidget *parent = nullptr);
    ~addDialog();

signals:
    void sendData(QString str);

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

    void accept();

private:
    Ui::addDialog *ui;
    QPushButton* okButton;
    QPushButton* cancelButton;
};

#endif // ADDDIALOG_H
