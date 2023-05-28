#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class dialog;
}

class dialog : public QDialog
{
    Q_OBJECT

public:
    explicit dialog(QWidget *parent = nullptr);
    ~dialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void accept();

private:
    Ui::dialog *ui;
};

#endif // DIALOG_H
