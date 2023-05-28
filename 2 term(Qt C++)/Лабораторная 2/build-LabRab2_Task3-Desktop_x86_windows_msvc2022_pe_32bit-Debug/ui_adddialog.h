/********************************************************************************
** Form generated from reading UI file 'adddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDIALOG_H
#define UI_ADDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox_4;
    QDoubleSpinBox *doubleSpinBox_5;

    void setupUi(QDialog *AddDialog)
    {
        if (AddDialog->objectName().isEmpty())
            AddDialog->setObjectName("AddDialog");
        AddDialog->resize(503, 193);
        buttonBox = new QDialogButtonBox(AddDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(150, 150, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(AddDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(120, 30, 371, 25));
        label = new QLabel(AddDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 30, 101, 20));
        label_2 = new QLabel(AddDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 70, 63, 20));
        label_3 = new QLabel(AddDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(150, 70, 63, 20));
        label_4 = new QLabel(AddDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(250, 70, 63, 20));
        label_5 = new QLabel(AddDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(330, 70, 63, 20));
        label_6 = new QLabel(AddDialog);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(420, 70, 63, 20));
        doubleSpinBox = new QDoubleSpinBox(AddDialog);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setGeometry(QRect(40, 100, 62, 25));
        doubleSpinBox->setMinimum(-1000.000000000000000);
        doubleSpinBox->setMaximum(1000.000000000000000);
        doubleSpinBox_2 = new QDoubleSpinBox(AddDialog);
        doubleSpinBox_2->setObjectName("doubleSpinBox_2");
        doubleSpinBox_2->setGeometry(QRect(130, 100, 62, 25));
        doubleSpinBox_2->setMinimum(-1000.000000000000000);
        doubleSpinBox_2->setMaximum(1000.000000000000000);
        doubleSpinBox_3 = new QDoubleSpinBox(AddDialog);
        doubleSpinBox_3->setObjectName("doubleSpinBox_3");
        doubleSpinBox_3->setGeometry(QRect(220, 100, 62, 25));
        doubleSpinBox_3->setMinimum(-1000.000000000000000);
        doubleSpinBox_3->setMaximum(1000.000000000000000);
        doubleSpinBox_4 = new QDoubleSpinBox(AddDialog);
        doubleSpinBox_4->setObjectName("doubleSpinBox_4");
        doubleSpinBox_4->setGeometry(QRect(310, 100, 62, 25));
        doubleSpinBox_4->setMinimum(-1000.000000000000000);
        doubleSpinBox_4->setMaximum(1000.000000000000000);
        doubleSpinBox_5 = new QDoubleSpinBox(AddDialog);
        doubleSpinBox_5->setObjectName("doubleSpinBox_5");
        doubleSpinBox_5->setGeometry(QRect(400, 100, 62, 25));
        doubleSpinBox_5->setMinimum(-1000.000000000000000);
        doubleSpinBox_5->setMaximum(1000.000000000000000);

        retranslateUi(AddDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddDialog);
    } // setupUi

    void retranslateUi(QDialog *AddDialog)
    {
        AddDialog->setWindowTitle(QCoreApplication::translate("AddDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddDialog", "\320\222\321\213\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        label_2->setText(QCoreApplication::translate("AddDialog", "a", nullptr));
        label_3->setText(QCoreApplication::translate("AddDialog", "b", nullptr));
        label_4->setText(QCoreApplication::translate("AddDialog", "c", nullptr));
        label_5->setText(QCoreApplication::translate("AddDialog", "d", nullptr));
        label_6->setText(QCoreApplication::translate("AddDialog", "e", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDialog: public Ui_AddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDIALOG_H
