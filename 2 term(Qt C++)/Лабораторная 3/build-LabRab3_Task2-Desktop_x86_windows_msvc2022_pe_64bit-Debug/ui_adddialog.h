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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AddDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *AddDialog)
    {
        if (AddDialog->objectName().isEmpty())
            AddDialog->setObjectName("AddDialog");
        AddDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(AddDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(AddDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 90, 371, 25));
        spinBox = new QSpinBox(AddDialog);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(10, 30, 51, 25));
        spinBox->setMinimum(2);
        spinBox_2 = new QSpinBox(AddDialog);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setGeometry(QRect(80, 30, 51, 25));
        spinBox_2->setMinimum(2);
        label = new QLabel(AddDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 63, 20));
        label_2 = new QLabel(AddDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 10, 63, 20));
        label_3 = new QLabel(AddDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 70, 191, 20));

        retranslateUi(AddDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddDialog);
    } // setupUi

    void retranslateUi(QDialog *AddDialog)
    {
        AddDialog->setWindowTitle(QCoreApplication::translate("AddDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddDialog", "\320\241\321\202\321\200\320\276\320\272\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("AddDialog", "\320\241\321\202\320\276\320\273\320\261\321\206\321\213", nullptr));
        label_3->setText(QCoreApplication::translate("AddDialog", "\320\255\320\273\320\265\320\274\320\265\320\275\321\202\321\213 \320\274\320\260\321\202\321\200\320\270\321\206\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDialog: public Ui_AddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDIALOG_H
