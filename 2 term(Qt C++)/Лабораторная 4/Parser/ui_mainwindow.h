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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTextEdit *Tab1TextEdit;
    QWidget *tab_2;
    QTextEdit *Tab2TextEdit;
    QWidget *tab_3;
    QTextEdit *Tab3TextEdit;
    QWidget *tab_4;
    QTextEdit *Tab4TextEdit;
    QWidget *tab_5;
    QTextEdit *Tab5TextEdit;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(840, 646);
        action = new QAction(MainWindow);
        action->setObjectName("action");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 60, 821, 311));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 10, 101, 31));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 380, 331, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 400, 821, 201));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 0, 861, 51));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(-10, 0, 20, 51));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 410, 801, 181));
        tab = new QWidget();
        tab->setObjectName("tab");
        Tab1TextEdit = new QTextEdit(tab);
        Tab1TextEdit->setObjectName("Tab1TextEdit");
        Tab1TextEdit->setGeometry(QRect(0, 0, 801, 151));
        Tab1TextEdit->setReadOnly(true);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        Tab2TextEdit = new QTextEdit(tab_2);
        Tab2TextEdit->setObjectName("Tab2TextEdit");
        Tab2TextEdit->setGeometry(QRect(0, 0, 801, 151));
        Tab2TextEdit->setReadOnly(true);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        Tab3TextEdit = new QTextEdit(tab_3);
        Tab3TextEdit->setObjectName("Tab3TextEdit");
        Tab3TextEdit->setGeometry(QRect(0, 0, 801, 151));
        Tab3TextEdit->setReadOnly(true);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        Tab4TextEdit = new QTextEdit(tab_4);
        Tab4TextEdit->setObjectName("Tab4TextEdit");
        Tab4TextEdit->setGeometry(QRect(0, 0, 801, 151));
        Tab4TextEdit->setReadOnly(true);
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        Tab5TextEdit = new QTextEdit(tab_5);
        Tab5TextEdit->setObjectName("Tab5TextEdit");
        Tab5TextEdit->setGeometry(QRect(0, 0, 801, 151));
        Tab5TextEdit->setReadOnly(true);
        tabWidget->addTab(tab_5, QString());
        MainWindow->setCentralWidget(centralwidget);
        label_3->raise();
        label_2->raise();
        textEdit->raise();
        pushButton->raise();
        label->raise();
        label_4->raise();
        tabWidget->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 840, 26));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
#if QT_CONFIG(shortcut)
        action->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButton->setText(QCoreApplication::translate("MainWindow", "Parse", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202 \320\277\321\200\320\276\320\262\320\265\321\200\320\272\320\270 :", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\213\320\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\320\232\320\273\320\260\321\201\321\201\321\213,\321\201\321\202\321\200\321\203\320\272\321\202\321\203\321\200\321\213,\320\274\320\260\321\201\321\201\320\270\320\262\321\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\202\320\276\321\202\320\270\320\277\321\213,\320\273\320\276\320\272\320\260\320\273\321\214\320\275\321\213\320\265 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\213\320\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\263\321\200\320\267\321\203\320\272\320\270,\320\262\320\265\321\202\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\321\207\320\265\321\201\320\272\320\270\320\265 \320\276\321\210\320\270\320\261\320\272\320\270", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
