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
    QAction *save;
    QAction *action_3;
    QWidget *centralwidget;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QPushButton *search;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QComboBox *comboBox_2;
    QPushButton *pushButton_4;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(802, 471);
        action = new QAction(MainWindow);
        action->setObjectName("action");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/Img/png-transparent-folder-open-file-common-toolbar-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action->setIcon(icon);
        save = new QAction(MainWindow);
        save->setObjectName("save");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rec/Img/png-clipart-computer-icons-floppy-disk-symbol-icon-user-interface-blue-angle.png"), QSize(), QIcon::Normal, QIcon::Off);
        save->setIcon(icon1);
        action_3 = new QAction(MainWindow);
        action_3->setObjectName("action_3");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/rec/Img/360.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_3->setIcon(icon2);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(20, 40, 501, 331));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(300, 380, 221, 29));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 380, 221, 29));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(530, 40, 260, 25));
        search = new QPushButton(centralwidget);
        search->setObjectName("search");
        search->setGeometry(QRect(720, 80, 61, 25));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(540, 80, 171, 25));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(530, 300, 260, 29));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(530, 340, 260, 25));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(530, 140, 260, 41));
        pushButton_4->setLayoutDirection(Qt::LeftToRight);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 10, 521, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(530, 70, 260, 44));
        MainWindow->setCentralWidget(centralwidget);
        label_2->raise();
        listWidget->raise();
        pushButton->raise();
        pushButton_2->raise();
        comboBox->raise();
        search->raise();
        lineEdit->raise();
        pushButton_3->raise();
        comboBox_2->raise();
        pushButton_4->raise();
        label->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 802, 26));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addAction(action_3);
        menu->addAction(save);

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
        save->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272", nullptr));
#if QT_CONFIG(shortcut)
        save->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_3->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(shortcut)
        action_3->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\321\201\321\202\320\270 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \321\215\320\273.\321\201\320\277\320\270\321\201\320\272\320\260", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \321\206\320\265\321\205\320\260", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\270 \320\277\321\200\320\276\320\264\321\203\320\272\321\206\320\270\320\270", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));

        search->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270!", nullptr));
        lineEdit->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\277\320\276:", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200\321\203 \321\206\320\265\321\205\320\260", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\321\216 \320\277\321\200\320\276\320\264\321\203\320\272\321\206\320\270\320\270", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\321\203", nullptr));

        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\320\246\320\265\321\205 \321\201 \320\272\320\276\320\273-\320\262\320\276\320\274 \320\277\321\200\320\276\320\264\321\203\320\272\321\206\320\270\320\270 \n"
"\320\275\320\265 \320\275\320\270\320\266\320\265 \320\262\320\262\320\265\320\264\320\265\320\275\320\275\320\276\320\263\320\276", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\262\321\213\320\262\320\276\320\264\320\270\321\202\321\201\321\217 \320\262 \321\204\320\276\321\200\320\274\320\260\321\202\320\265 <i><b>\320\275\320\276\320\274\320\265\321\200 \321\206\320\265\321\205\320\260,\320\277\321\200\320\276\320\264\321\203\320\272\321\206\320\270\321\217,\320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276</i></b>", nullptr));
        label_2->setText(QString());
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
