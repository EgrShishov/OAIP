/********************************************************************************
** Form generated from reading UI file 'edittingwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITTINGWINDOW_H
#define UI_EDITTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_edittingWindow
{
public:
    QLabel *label;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;

    void setupUi(QDialog *edittingWindow)
    {
        if (edittingWindow->objectName().isEmpty())
            edittingWindow->setObjectName("edittingWindow");
        edittingWindow->resize(301, 278);
        label = new QLabel(edittingWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 261, 20));
        comboBox = new QComboBox(edittingWindow);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(10, 50, 271, 25));
        lineEdit = new QLineEdit(edittingWindow);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 110, 271, 25));
        label_2 = new QLabel(edittingWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 90, 151, 20));
        buttonBox = new QDialogButtonBox(edittingWindow);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(90, 220, 193, 29));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        pushButton = new QPushButton(edittingWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 150, 271, 29));

        retranslateUi(edittingWindow);

        QMetaObject::connectSlotsByName(edittingWindow);
    } // setupUi

    void retranslateUi(QDialog *edittingWindow)
    {
        edittingWindow->setWindowTitle(QCoreApplication::translate("edittingWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("edittingWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200 \320\264\320\273\321\217 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("edittingWindow", "\320\235\320\276\320\262\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        pushButton->setText(QCoreApplication::translate("edittingWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class edittingWindow: public Ui_edittingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITTINGWINDOW_H
