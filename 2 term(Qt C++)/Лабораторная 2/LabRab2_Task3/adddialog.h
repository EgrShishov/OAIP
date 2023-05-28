#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QHeaderView>
#include "reversepolishnotation.h"

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = nullptr);
    ~AddDialog();
signals:
    void sendData(QString expr,double a,double b,double c,double d,double e);
private slots:
    void accept();
private:
    Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H
