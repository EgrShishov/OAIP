/********************************************************************************
** Form generated from reading UI file 'thirdwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THIRDWINDOW_H
#define UI_THIRDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_thirdwindow
{
public:
    QPushButton *pushButton_2;
    QLabel *label_9;
    QLineEdit *lineEdit_10;
    QLabel *label_8;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLabel *label_7;
    QLabel *label_10;

    void setupUi(QDialog *thirdwindow)
    {
        if (thirdwindow->objectName().isEmpty())
            thirdwindow->setObjectName("thirdwindow");
        thirdwindow->resize(307, 406);
        pushButton_2 = new QPushButton(thirdwindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 300, 251, 29));
        label_9 = new QLabel(thirdwindow);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 220, 111, 20));
        lineEdit_10 = new QLineEdit(thirdwindow);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(20, 250, 251, 25));
        label_8 = new QLabel(thirdwindow);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 150, 111, 20));
        lineEdit_6 = new QLineEdit(thirdwindow);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(20, 40, 251, 25));
        lineEdit_8 = new QLineEdit(thirdwindow);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(20, 110, 251, 25));
        lineEdit_9 = new QLineEdit(thirdwindow);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(20, 180, 251, 25));
        label_7 = new QLabel(thirdwindow);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 80, 111, 20));
        label_10 = new QLabel(thirdwindow);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 10, 111, 20));

        retranslateUi(thirdwindow);

        QMetaObject::connectSlotsByName(thirdwindow);
    } // setupUi

    void retranslateUi(QDialog *thirdwindow)
    {
        thirdwindow->setWindowTitle(QCoreApplication::translate("thirdwindow", "Dialog", nullptr));
        pushButton_2->setText(QCoreApplication::translate("thirdwindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\207\320\270\321\202\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_9->setText(QCoreApplication::translate("thirdwindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        label_8->setText(QCoreApplication::translate("thirdwindow", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        lineEdit_8->setText(QString());
        lineEdit_9->setText(QString());
        label_7->setText(QCoreApplication::translate("thirdwindow", "\320\244\320\230\320\236", nullptr));
        label_10->setText(QCoreApplication::translate("thirdwindow", "\320\232\320\276\320\264 \321\207\320\270\321\202\320\260\321\202\320\265\320\273\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class thirdwindow: public Ui_thirdwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THIRDWINDOW_H
