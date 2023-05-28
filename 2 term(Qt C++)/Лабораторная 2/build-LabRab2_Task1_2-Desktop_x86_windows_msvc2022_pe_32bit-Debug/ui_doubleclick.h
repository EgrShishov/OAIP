/********************************************************************************
** Form generated from reading UI file 'doubleclick.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOUBLECLICK_H
#define UI_DOUBLECLICK_H

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

class Ui_doubleClick
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *doubleClick)
    {
        if (doubleClick->objectName().isEmpty())
            doubleClick->setObjectName("doubleClick");
        doubleClick->resize(356, 226);
        buttonBox = new QDialogButtonBox(doubleClick);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(-10, 170, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(doubleClick);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 301, 20));
        comboBox = new QComboBox(doubleClick);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(20, 40, 311, 25));
        lineEdit = new QLineEdit(doubleClick);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 80, 311, 31));
        pushButton = new QPushButton(doubleClick);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 130, 311, 29));

        retranslateUi(doubleClick);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, doubleClick, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, doubleClick, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(doubleClick);
    } // setupUi

    void retranslateUi(QDialog *doubleClick)
    {
        doubleClick->setWindowTitle(QCoreApplication::translate("doubleClick", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("doubleClick", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("doubleClick", "\320\237\320\276\321\200\321\217\320\264\320\272\320\276\320\262\321\213\320\271 \320\275\320\276\320\274\320\265\321\200", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("doubleClick", "\320\244\320\230\320\236 \320\277\320\276\320\272\321\203\320\277\320\260\321\202\320\265\320\273\321\217", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("doubleClick", "\320\224\320\276\320\274\320\260\321\210\320\275\320\270\320\271 \320\260\320\264\321\200\320\265\321\201", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("doubleClick", "\320\224\320\260\321\202\320\260 \320\277\320\276\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\270 \320\275\320\260 \321\203\321\207\320\265\321\202", nullptr));

        pushButton->setText(QCoreApplication::translate("doubleClick", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214 \320\262 \321\201\320\277\320\270\321\201\320\276\320\272 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\275\321\213\321\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class doubleClick: public Ui_doubleClick {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOUBLECLICK_H
