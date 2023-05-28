#ifndef DOUBLECLICK_H
#define DOUBLECLICK_H

#include <QDialog>
#include <QMessageBox>
#include <QDialogButtonBox>
#include "shop.h"
#include "list.h"
namespace Ui {
class doubleClick;
}

class doubleClick : public QDialog
{
    Q_OBJECT

public:
    explicit doubleClick(QWidget *parent = nullptr);
    ~doubleClick();

public slots:
    void recieveIndex(int index);

signals:
    void sendData();

    void update(QString str);

private slots:

    void accept();

    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::doubleClick *ui;
};

#endif // DOUBLECLICK_H
