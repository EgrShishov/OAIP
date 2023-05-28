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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_2;
    QAction *action;
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QTextBrowser *textBrowser;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_5;
    QTableWidget *tableWidget;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_8;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_6;
    QLabel *label_4;
    QLineEdit *lineEdit_7;
    QGroupBox *groupBox;
    QPushButton *pushButton_9;
    QLabel *label_5;
    QMenuBar *menubar;
    QMenu *menuLabRab1;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1258, 514);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName("action_2");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/Img/20-209142_small-close-button-svg-png-icon-free-download.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_2->setIcon(icon);
        action = new QAction(MainWindow);
        action->setObjectName("action");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rec/Img/png-transparent-folder-open-file-common-toolbar-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action->setIcon(icon1);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(930, 60, 161, 40));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(990, 330, 161, 40));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(330, 409, 141, 31));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(1430, 380, 281, 41));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(1380, 330, 161, 41));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(670, 60, 231, 41));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(20, 410, 131, 31));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 10, 631, 371));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(170, 410, 141, 31));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(930, 150, 291, 41));
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(670, 150, 231, 41));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(490, 410, 141, 31));
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(1390, 390, 161, 41));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(670, 240, 231, 41));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(930, 240, 161, 41));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(670, 30, 421, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(670, 120, 271, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(670, 210, 271, 20));
        lineEdit_6 = new QLineEdit(centralwidget);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(730, 330, 231, 41));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(740, 300, 271, 20));
        lineEdit_7 = new QLineEdit(centralwidget);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(680, 330, 31, 41));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 400, 631, 51));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(660, 410, 141, 29));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(670, 300, 63, 20));
        MainWindow->setCentralWidget(centralwidget);
        groupBox->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_4->raise();
        textBrowser->raise();
        lineEdit_2->raise();
        lineEdit_3->raise();
        pushButton_5->raise();
        tableWidget->raise();
        pushButton_6->raise();
        pushButton_7->raise();
        lineEdit_4->raise();
        pushButton_8->raise();
        lineEdit_5->raise();
        lineEdit->raise();
        pushButton_3->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        lineEdit_6->raise();
        label_4->raise();
        lineEdit_7->raise();
        pushButton_9->raise();
        label_5->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1258, 26));
        menuLabRab1 = new QMenu(menubar);
        menuLabRab1->setObjectName("menuLabRab1");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuLabRab1->menuAction());
        menuLabRab1->addAction(action);
        menuLabRab1->addAction(action_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\203", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\321\201\321\202\320\270", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\264\320\260\321\202\321\203", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\321\201\320\276\320\272\320\276\321\201\320\275\321\213\320\271?", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "\320\262\320\270\321\201\320\276\320\272\320\276\321\201\320\275\321\213", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\320\241\320\273\320\265\320\264\321\203\321\216\321\211\320\270\320\271 \320\264\320\265\320\275\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\241\320\273\320\265\320\264\321\203\321\216\321\211\320\270\320\271 \320\264\320\265\320\275\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\320\264\321\213\320\264\321\203\321\211\320\270\320\271 \320\264\320\265\320\275\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\275\320\270\321\206\320\260 \321\202\320\265\320\272. \320\270 \321\201\320\273\320\265\320\264.", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\275\320\265\320\264\320\265\320\273\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\321\201\320\276\320\272\320\276\321\201\320\275\321\213\320\271?", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\320\264\321\213\320\264\321\203\321\211\320\270\320\271 \320\264\320\265\320\275\321\214", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\275\320\270\321\206\320\260 \320\274\320\265\320\266\320\264\321\203 \321\202\320\265\320\272\321\203\321\211\320\265\320\271 \320\270 \320\262\320\262\320\265\320\264\320\265\320\275\320\275\320\276\320\271", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\275\320\265\320\264\320\265\320\273\320\270", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("MainWindow", "\320\275\320\276\320\274\320\265\321\200", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\264\320\260\321\202\321\203", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\320\260\321\210 \320\264\320\265\320\275\321\214 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217 \320\262 \321\204\320\276\321\200\320\274\320\260\321\202\320\265 dd.mm.yyyy(\320\264\321\200 \320\270\320\273\320\270 \320\264\321\200\321\203\320\263\320\260\321\217)", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\320\260\321\210\320\260 \320\264\320\260\321\202\320\260 \320\262 \321\204\320\276\321\200\320\274\320\260\321\202\320\265 dd.mm.yyyy", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\222\320\260\321\210\320\260 \320\264\320\260\321\202\320\260 \320\262 \321\204\320\276\321\200\320\274\320\260\321\202\320\265 dd.mm.yyyy", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\222\320\260\321\210\320\260 \320\264\320\260\321\202\320\260 \320\262 \321\204\320\276\321\200\320\274\320\260\321\202\320\265 dd.mm.yyyy", nullptr));
        groupBox->setTitle(QString());
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \321\204\320\260\320\271\320\273\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\342\204\226 \320\277\320\276\320\273\321\217", nullptr));
        menuLabRab1->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
