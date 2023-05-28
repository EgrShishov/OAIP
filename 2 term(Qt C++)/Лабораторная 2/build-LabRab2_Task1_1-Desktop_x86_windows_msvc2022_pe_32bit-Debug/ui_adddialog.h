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
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_addDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *textEdit;
    QLabel *label;

    void setupUi(QDialog *addDialog)
    {
        if (addDialog->objectName().isEmpty())
            addDialog->setObjectName("addDialog");
        addDialog->resize(460, 345);
        buttonBox = new QDialogButtonBox(addDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(110, 300, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        textEdit = new QTextEdit(addDialog);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 40, 441, 251));
        label = new QLabel(addDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 441, 21));

        retranslateUi(addDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, addDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, addDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(addDialog);
    } // setupUi

    void retranslateUi(QDialog *addDialog)
    {
        addDialog->setWindowTitle(QCoreApplication::translate("addDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("addDialog", "<html><head/><body><p>\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\320\275\320\275\321\213\320\265 \320\262 \321\204\320\276\321\200\320\274\320\260\321\202\320\265<span style=\" font-weight:700; font-style:italic;\"> \320\275\320\276\320\274\320\265\321\200 \321\206\320\265\321\205\320\260,\320\275\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265 , \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addDialog: public Ui_addDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDIALOG_H
