/********************************************************************************
** Form generated from reading UI file 'secondwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_secondwindow
{
public:
    QPushButton *pushButton;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_5;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label;

    void setupUi(QDialog *secondwindow)
    {
        if (secondwindow->objectName().isEmpty())
            secondwindow->setObjectName("secondwindow");
        secondwindow->resize(331, 429);
        pushButton = new QPushButton(secondwindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 370, 281, 29));
        label_5 = new QLabel(secondwindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 290, 111, 20));
        lineEdit = new QLineEdit(secondwindow);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 40, 281, 25));
        lineEdit_5 = new QLineEdit(secondwindow);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(20, 320, 281, 25));
        label_2 = new QLabel(secondwindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 80, 111, 20));
        lineEdit_2 = new QLineEdit(secondwindow);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(20, 110, 281, 25));
        label_3 = new QLabel(secondwindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 150, 111, 20));
        lineEdit_3 = new QLineEdit(secondwindow);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(20, 180, 281, 25));
        label_4 = new QLabel(secondwindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 220, 111, 20));
        lineEdit_4 = new QLineEdit(secondwindow);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(20, 250, 281, 25));
        label = new QLabel(secondwindow);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 111, 20));

        retranslateUi(secondwindow);

        QMetaObject::connectSlotsByName(secondwindow);
    } // setupUi

    void retranslateUi(QDialog *secondwindow)
    {
        secondwindow->setWindowTitle(QCoreApplication::translate("secondwindow", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("secondwindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216 \320\276 \320\272\320\275\320\270\320\263\320\265", nullptr));
        label_5->setText(QCoreApplication::translate("secondwindow", "\320\257\320\267\321\213\320\272 \320\272\320\275\320\270\320\263\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("secondwindow", "\320\220\320\262\321\202\320\276\321\200 \320\272\320\275\320\270\320\263\320\270", nullptr));
        lineEdit_2->setText(QString());
        label_3->setText(QCoreApplication::translate("secondwindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        lineEdit_3->setText(QString());
        label_4->setText(QCoreApplication::translate("secondwindow", "\320\223\320\276\320\264 \320\270\320\267\320\264\320\260\320\275\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("secondwindow", "\320\232\320\276\320\264 \320\272\320\275\320\270\320\263\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class secondwindow: public Ui_secondwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H
