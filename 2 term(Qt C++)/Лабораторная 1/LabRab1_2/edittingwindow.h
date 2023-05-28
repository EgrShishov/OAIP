#ifndef EDITTINGWINDOW_H
#define EDITTINGWINDOW_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class edittingWindow;
}

class edittingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit edittingWindow(QWidget *parent = nullptr);
    ~edittingWindow();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::edittingWindow *ui;
};

#endif // EDITTINGWINDOW_H
