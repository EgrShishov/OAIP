/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QWidget *centralwidget;
    QListWidget *listWidget;
    QComboBox *comboBox_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QPushButton *search;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(786, 467);
        action = new QAction(MainWindow);
        action->setObjectName("action");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/Img/png-transparent-folder-open-file-common-toolbar-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action->setIcon(icon);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName("action_2");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rec/Img/png-clipart-computer-icons-floppy-disk-symbol-icon-user-interface-blue-angle.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_2->setIcon(icon1);
        action_3 = new QAction(MainWindow);
        action_3->setObjectName("action_3");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/rec/Img/360.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_3->setIcon(icon2);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(10, 40, 501, 331));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(530, 332, 241, 31));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(530, 150, 241, 41));
        pushButton_4->setLayoutDirection(Qt::LeftToRight);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(530, 290, 241, 31));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(530, 70, 241, 25));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 380, 241, 29));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(270, 380, 241, 29));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(530, 40, 241, 25));
        search = new QPushButton(centralwidget);
        search->setObjectName("search");
        search->setGeometry(QRect(530, 100, 241, 29));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 10, 521, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 786, 26));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addAction(action_3);
        menu->addAction(action_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
#if QT_CONFIG(shortcut)
        action->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272", nullptr));
#if QT_CONFIG(shortcut)
        action_2->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_3->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(shortcut)
        action_3->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "\320\237\320\276\321\200\321\217\320\264\320\272\320\276\320\262\321\213\320\271 \320\275\320\276\320\274\320\265\321\200", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236 \320\277\320\276\320\272\321\203\320\277\320\260\321\202\320\265\320\273\321\217", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "\320\224\320\276\320\274\320\260\321\210\320\275\320\270\320\271 \320\260\320\264\321\200\320\265\321\201", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\277\320\276\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\270 \320\275\320\260 \321\203\321\207\320\265\321\202", nullptr));

        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265 \320\277\320\276\320\262\321\202\320\276\321\200\320\275\321\213\320\265 \320\267\320\260\320\277\320\270\321\201\320\270", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \321\215\320\273.\321\201\320\277\320\270\321\201\320\272\320\260", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\321\201\321\202\320\270 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\237\320\276\321\200\321\217\320\264\320\272\320\276\320\262\321\213\320\271 \320\275\320\276\320\274\320\265\321\200", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236 \320\277\320\276\320\272\321\203\320\277\320\260\321\202\320\265\320\273\321\217", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\320\224\320\276\320\274\320\260\321\210\320\275\320\270\320\271 \320\260\320\264\321\200\320\265\321\201", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\277\320\276\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\270 \320\275\320\260 \321\203\321\207\320\265\321\202", nullptr));

        search->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272!", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\262\321\213\320\262\320\276\320\264\320\270\321\202\321\201\321\217 \320\262 \321\204\320\276\321\200\320\274\320\260\321\202\320\265 <span style=\" font-weight:700; font-style:italic;\">\320\275\320\276\320\274\320\265\321\200 \320\267\320\260\320\272\320\260\320\267\320\260,\320\244\320\230\320\236,\320\260\320\264\321\200\320\265\321\201,\320\264\320\260\321\202\320\260</span></p></body></html>", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
