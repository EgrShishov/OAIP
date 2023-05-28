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
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *square;
    QPushButton *square_2;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label_3;
    QCheckBox *checkBox;
    QLineEdit *area;
    QLineEdit *perimetr;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *triangle;
    QPushButton *ellipse;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_7;
    QPushButton *change;
    QPushButton *pushButton_8;
    QLabel *label_6;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1050, 681);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(10, 20, 751, 471));
        square = new QPushButton(centralwidget);
        square->setObjectName("square");
        square->setGeometry(QRect(770, 20, 121, 29));
        square_2 = new QPushButton(centralwidget);
        square_2->setObjectName("square_2");
        square_2->setGeometry(QRect(770, 60, 121, 29));
        doubleSpinBox = new QDoubleSpinBox(centralwidget);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setGeometry(QRect(10, 530, 91, 25));
        doubleSpinBox->setMaximum(800.000000000000000);
        doubleSpinBox->setValue(38.000000000000000);
        doubleSpinBox_2 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_2->setObjectName("doubleSpinBox_2");
        doubleSpinBox_2->setGeometry(QRect(120, 530, 91, 25));
        doubleSpinBox_2->setMaximum(600.000000000000000);
        doubleSpinBox_2->setValue(40.000000000000000);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 510, 171, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(240, 510, 101, 20));
        doubleSpinBox_3 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_3->setObjectName("doubleSpinBox_3");
        doubleSpinBox_3->setGeometry(QRect(240, 530, 91, 25));
        doubleSpinBox_3->setMinimum(0.000000000000000);
        doubleSpinBox_3->setMaximum(360.000000000000000);
        doubleSpinBox_4 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_4->setObjectName("doubleSpinBox_4");
        doubleSpinBox_4->setGeometry(QRect(350, 530, 91, 25));
        doubleSpinBox_4->setMinimum(0.100000000000000);
        doubleSpinBox_4->setMaximum(4.000000000000000);
        doubleSpinBox_4->setSingleStep(0.100000000000000);
        doubleSpinBox_4->setValue(1.000000000000000);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(350, 510, 101, 20));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(750, 530, 111, 24));
        area = new QLineEdit(centralwidget);
        area->setObjectName("area");
        area->setGeometry(QRect(470, 530, 113, 25));
        perimetr = new QLineEdit(centralwidget);
        perimetr->setObjectName("perimetr");
        perimetr->setGeometry(QRect(620, 530, 113, 25));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(470, 510, 63, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(620, 510, 63, 20));
        triangle = new QPushButton(centralwidget);
        triangle->setObjectName("triangle");
        triangle->setGeometry(QRect(770, 100, 121, 29));
        ellipse = new QPushButton(centralwidget);
        ellipse->setObjectName("ellipse");
        ellipse->setGeometry(QRect(770, 140, 121, 29));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(770, 180, 121, 29));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(770, 380, 121, 29));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(910, 380, 111, 31));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(770, 220, 121, 29));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(770, 260, 121, 29));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(770, 300, 121, 29));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(770, 340, 121, 29));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setEnabled(false);
        groupBox->setGeometry(QRect(0, 500, 221, 80));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setEnabled(false);
        groupBox_2->setGeometry(QRect(230, 500, 221, 80));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(460, 500, 281, 80));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(770, 460, 121, 29));
        change = new QPushButton(centralwidget);
        change->setObjectName("change");
        change->setGeometry(QRect(770, 420, 121, 29));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(870, 530, 93, 29));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(910, 350, 111, 20));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(60, 580, 111, 29));
        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(910, 20, 121, 29));
        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(870, 570, 93, 29));
        MainWindow->setCentralWidget(centralwidget);
        groupBox->raise();
        groupBox_2->raise();
        graphicsView->raise();
        square->raise();
        square_2->raise();
        doubleSpinBox->raise();
        doubleSpinBox_2->raise();
        label->raise();
        label_2->raise();
        doubleSpinBox_3->raise();
        doubleSpinBox_4->raise();
        label_3->raise();
        checkBox->raise();
        area->raise();
        perimetr->raise();
        label_4->raise();
        label_5->raise();
        triangle->raise();
        ellipse->raise();
        pushButton->raise();
        pushButton_2->raise();
        textEdit->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        groupBox_3->raise();
        pushButton_7->raise();
        change->raise();
        pushButton_8->raise();
        label_6->raise();
        pushButton_9->raise();
        pushButton_10->raise();
        pushButton_11->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1050, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        square->setText(QCoreApplication::translate("MainWindow", "Add rectangle", nullptr));
        square_2->setText(QCoreApplication::translate("MainWindow", "Add sqaure", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Position of mass centre", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Canve mode", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Area", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Perimetr", nullptr));
        triangle->setText(QCoreApplication::translate("MainWindow", "Add triangle", nullptr));
        ellipse->setText(QCoreApplication::translate("MainWindow", "Add ellipse", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Add rhombus", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "rotate", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Add hexagon", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Add star-5", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Add star-6", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Add star-8", nullptr));
        groupBox->setTitle(QString());
        groupBox_2->setTitle(QString());
        groupBox_3->setTitle(QString());
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Stop rotation", nullptr));
        change->setText(QCoreApplication::translate("MainWindow", "Change", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Clear canve", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "rotation angle", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "centre of grav", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Add arrow", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Set color", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
