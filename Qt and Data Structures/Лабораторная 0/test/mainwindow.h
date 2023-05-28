#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "figure.h"
#include "rectangle.h"
#include "square.h"
#include "triangle.h"
#include "ellipse.h"
#include "rhombus.h"
#include "hexagon.h"
#include "star.h"
#include "star6.h"
#include "star8.h"
#include "canva.h"
#include "clown.h"
#include <QColorDialog>

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QGraphicsItem>
#include <QPainter>
#include <QSlider>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QDialog>
#include <QLineEdit>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QDialog *rectDlg, *triangDlg, *circleDlg, *squareDlg, *rhombDlg, *ovalDlg, *starDlg, *hexDlg, *star6Dlg,*star8Dlg;
    QLabel *InputWidth, *InputHeight,
    *InputX1, *InputX2, *InputX3, *InputY1, *InputY2, *InputY3,
    *InputR, *InputA, *Inputr, *InputOvalR, *InputOvalr, *InputStarR,*InputStar6R,*InputStar8R,*InputHexR;
    QLineEdit *LE_Width, *LE_Height,
    *LE_X1, *LE_X2, *LE_X3, *LE_Y1, *LE_Y2, *LE_Y3,
    *LE_R, *LE_A, *LE_r, *LE_ovalR, *LE_ovalr, *LE_starR,*LE_star6R,*LE_star8R, *LE_HexR;
    QPushButton *Enter;

    QString currentFigure;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void centreChange();

private slots:
    void nulling();

    void createRect();

    void createEllipse();

    void createSquare();

    void createRhombus();

    void createHexagon();

    void createStar5();

    void createStar6();

    void createStar8();

    void on_square_clicked();

    void on_square_2_clicked();

    void on_doubleSpinBox_3_valueChanged(double arg1);

    void on_doubleSpinBox_4_valueChanged(double arg1);

    void on_clear_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_triangle_clicked();

    void on_ellipse_clicked();

    void on_pushButton_clicked();

    void on_radioButton_clicked();

    void on_radioButton_clicked(bool checked);

    void on_pushButton_2_clicked();

    void rotatef();

    void rescalef();

    void on_doubleSpinBox_2_valueChanged(double arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_clicked(bool checked);

    void on_pushButton_7_clicked();

    void on_change_clicked();

    void on_pushButton_8_clicked();

    void on_doubleSpinBox_valueChanged(double arg1);

    void updateInfo();

    void on_pushButton_9_clicked();

    void on_doubleSpinBox_4_textChanged(const QString &arg1);

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_doubleSpinBox_textChanged(const QString &arg1);

    void on_pushButton_2_clicked(bool checked);

signals:
    void cords();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    figure* Figure;
    canva* scene2;
    QTimer*  rotateTimer;
    QTimer* rescaleTimer;


    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

    QPointF rotationPoint;

    QPointF previousPoint;
    QPointF FirstPoint;

};
#endif // MAINWINDOW_H
