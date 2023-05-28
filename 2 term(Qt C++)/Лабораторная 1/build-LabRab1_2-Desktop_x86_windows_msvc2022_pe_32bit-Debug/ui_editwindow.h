/********************************************************************************
** Form generated from reading UI file 'editwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITWINDOW_H
#define UI_EDITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QComboBox *comboBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *editWindow)
    {
        if (editWindow->objectName().isEmpty())
            editWindow->setObjectName("editWindow");
        editWindow->resize(434, 600);
        centralwidget = new QWidget(editWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 261, 20));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(20, 50, 271, 25));
        editWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(editWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 434, 26));
        editWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(editWindow);
        statusbar->setObjectName("statusbar");
        editWindow->setStatusBar(statusbar);

        retranslateUi(editWindow);

        QMetaObject::connectSlotsByName(editWindow);
    } // setupUi

    void retranslateUi(QMainWindow *editWindow)
    {
        editWindow->setWindowTitle(QCoreApplication::translate("editWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("editWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200 \320\264\320\273\321\217 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("editWindow", "\320\230\320\264\320\265\320\275\321\202\320\270\321\204\320\270\320\272\320\260\321\202\320\276\321\200", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("editWindow", "\320\244\320\230\320\236 \320\260\320\262\321\202\320\276\321\200\320\260", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("editWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\272\320\275\320\270\320\263\320\270", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("editWindow", "\320\223\320\276\320\264", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("editWindow", "\320\257\320\267\321\213\320\272", nullptr));

    } // retranslateUi

};

namespace Ui {
    class editWindow: public Ui_editWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITWINDOW_H
