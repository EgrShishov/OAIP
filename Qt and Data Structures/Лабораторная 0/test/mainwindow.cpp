#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QCursor"
#include "canva.h"
#include <QColor>

int type;
double old_value=0;
extern bool triangle_exsist;
double angle;
bool is_drawning=false;
qreal scale =1 ;
qreal arg1=38,arg2=40;
QColor color;
bool aded=false;
int count = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene(this);
    ui->pushButton_8->hide();
    ui->graphicsView->setScene(scene);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов

    //ui->graphicsView->resize(800,500);  // Устанавливаем размер graphicsView
    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену в graphicsView
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключаем скроллбар по вертикали
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по горизонтали
    //connect(rescaleTimer, SIGNAL(timeout()), this, SLOT(on_doubleSpinBox_4_valueChanged(double)));

    connect(this,SIGNAL(centreChange()),this,SLOT(updateInfo()));

    scene->setSceneRect(0,0,600,600); // Устанавливаем размер сцены

    currentFigure = "triangle";

    rectDlg = new QDialog(this);

    InputWidth = new QLabel("Ширина:", rectDlg); InputWidth->adjustSize();
    InputHeight = new QLabel("Высота:", rectDlg); InputHeight->adjustSize();
    LE_Height = new QLineEdit(rectDlg);
    LE_Width = new QLineEdit(rectDlg);

    triangDlg = new QDialog(this);

    InputX1 = new QLabel("X1: ", triangDlg); InputX1->adjustSize();
    InputX2 = new QLabel("X2: ", triangDlg); InputX2->adjustSize();
    InputX3 = new QLabel("X3: ", triangDlg); InputX3->adjustSize();
    InputY1 = new QLabel("Y1: ", triangDlg); InputY1->adjustSize();
    InputY2 = new QLabel("Y2: ", triangDlg); InputY2->adjustSize();
    InputY3 = new QLabel("Y3: ", triangDlg); InputY3->adjustSize();
    LE_X1 = new QLineEdit(triangDlg);
    LE_X2 = new QLineEdit(triangDlg);
    LE_X3 = new QLineEdit(triangDlg);
    LE_Y1 = new QLineEdit(triangDlg);
    LE_Y2 = new QLineEdit(triangDlg);
    LE_Y3 = new QLineEdit(triangDlg);

    circleDlg = new QDialog(this);
    InputR = new QLabel("Радиус: ", circleDlg); InputR->adjustSize();
    LE_R = new QLineEdit(circleDlg);

    squareDlg = new QDialog(this);
    InputA = new QLabel("Сторона: ",squareDlg); InputA->adjustSize();
    LE_A = new QLineEdit(squareDlg);

    rhombDlg = new QDialog(this);
    Inputr = new QLabel("Радиус: ",rhombDlg); InputA->adjustSize();
    LE_r = new QLineEdit(rhombDlg);

    ovalDlg= new QDialog(this);
    LE_ovalR = new QLineEdit(ovalDlg);

    starDlg = new QDialog(this);
    InputStarR = new QLabel("R: ",starDlg); InputStarR->adjustSize();
    LE_starR = new QLineEdit(starDlg);

    hexDlg = new QDialog(this);
    InputHexR = new QLabel("R:", hexDlg); InputHexR->adjustSize();
    LE_HexR = new QLineEdit(hexDlg);

    star6Dlg = new QDialog(this);
    InputStar6R = new QLabel("R: ",star6Dlg); InputStar6R->adjustSize();
    LE_star6R = new QLineEdit(star6Dlg);

    star8Dlg = new QDialog(this);
    InputStar8R = new QLabel("R: ",star8Dlg); InputStar8R->adjustSize();
    LE_star8R = new QLineEdit(star8Dlg);

    rotateTimer = new QTimer(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_square_clicked()
{
    currentFigure = "rectangle";
    aded=true; count++;
    rectangle* item = new rectangle(60,120);
    item->setPos(38,40);
    item->setFlag(QGraphicsItem::ItemIsSelectable);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    Figure=item;
    scene->addItem(Figure);
    Figure->setPos(38,40);
    Figure->newScale(1);
    ui->doubleSpinBox->setValue(38);
    ui->doubleSpinBox_2->setValue(40);
    updateInfo();

}

void MainWindow::on_square_2_clicked()
{
    currentFigure="square";
    aded=true; count++;
    square* item=new square(70);
    item->setPos(40,40);
    item->setFlag(QGraphicsItem::ItemIsSelectable);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    Figure=item;
    scene->addItem(Figure);
    ui->doubleSpinBox->setValue(38);
    ui->doubleSpinBox_2->setValue(40);
    updateInfo();
}


void MainWindow::on_doubleSpinBox_3_valueChanged(double arg1)
{
   //connect(timer_rotation, SIGNAL(timeout()), this, SLOT(rotate_left()));
  // connect(timer_rotation,SIGNAL(timeout()),this, SLOT(display_angle()));
   //timer_rotation->start(10);

//    if(old_value>=arg1)
//    {
//   Figure->rotate_left(arg1);
//    }
//    else{
//   Figure->rotate_right(arg1);
//    }
//       old_value=arg1;

    if(aded && count)
    Figure->rotate_left(arg1);
else
    {
        QMessageBox::warning(this,tr("error"),"empty scene");
    }
}


void MainWindow::on_doubleSpinBox_4_valueChanged(double arg1)
{
    if(aded && count)
    {
    Figure->newScale(arg1);
    scale=arg1;
    //scene2->newScale(arg1);
    updateInfo();
    } else
    {
        QMessageBox::warning(this,tr("error"),("empty scene"));
        ui->doubleSpinBox_4->setValue(1);
    }
}

void MainWindow::updateInfo()
{
    ui->area->setText(QString::number(Figure->area()));
    ui->perimetr->setText(QString::number(Figure->perimetr()));
}

void MainWindow::on_clear_clicked()
{
    scene->clear();
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    updateInfo();
}


void MainWindow::on_triangle_clicked()
{  
    currentFigure="triangle";
    aded=true; count++;
    triangle* item = new triangle();
    item->setPos(40,40);
    item->setFlag(QGraphicsItem::ItemIsSelectable);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    Figure=item;
    scene->addItem(Figure);
    ui->doubleSpinBox->setValue(38);
    ui->doubleSpinBox_2->setValue(40);
    updateInfo();
}


void MainWindow::on_ellipse_clicked()
{
    currentFigure="ellipse";
    aded=true; count++;
    ellipse* item = new ellipse(60);
    item->setPos(40,40);
    item->setFlag(QGraphicsItem::ItemIsSelectable);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    Figure=item;
    scene->addItem(Figure);
    ui->doubleSpinBox->setValue(38);
    ui->doubleSpinBox_2->setValue(40);
    updateInfo();
}


void MainWindow::on_pushButton_clicked()
{
    ui->doubleSpinBox->setValue(38);
    ui->doubleSpinBox_2->setValue(40);
    currentFigure="rhoombus";
    rhombus* item = new rhombus(30,30,90);
    aded=true; count++;
    item->setPos(40,40);
    item->setFlag(QGraphicsItem::ItemIsSelectable);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    Figure=item;
    scene->addItem(Figure);
    updateInfo();
}


void MainWindow::on_radioButton_clicked()
{

}


void MainWindow::on_radioButton_clicked(bool checked)
{

}


void MainWindow::on_pushButton_2_clicked()
{
    if(aded && count)
    {
    QString info=ui->textEdit->toPlainText();

    int aboba = ui->textEdit->toPlainText().toInt();
    if(aboba>=0 && aboba<10000 && !info.isEmpty() && Figure!=nullptr)
    {
    connect(rotateTimer, SIGNAL(timeout()), this, SLOT(rotatef()));
    angle = (ui->textEdit->toPlainText().toInt() + Figure->rotation());
    rotateTimer->start(10);
    }
    else
    {
        QMessageBox::warning(this,tr("error"),("too much :)"));
    }

    } else
    {
        QMessageBox::warning(this,"error","empty scene");
    }
}

void MainWindow::rotatef(){

    if (Figure->rotation() != angle){
        Figure->setRotation(Figure->rotation() + 1);
    }
    else{
        rotateTimer->stop();
    }
}

void MainWindow::rescalef()
{
//    scale=1;
//    Figure->setScale(scale);
//    scale+=0.1;
}

void MainWindow::on_doubleSpinBox_2_valueChanged(double arg)
{
    if(aded && count)
    {
    arg2=arg;
    Figure->setPos(arg1,arg);
    } else
    {
        QMessageBox::warning(this,tr("error"),("empty scene"));
    }
}


void MainWindow::on_pushButton_3_clicked()
{

    currentFigure="hexagon";
    aded=true; count++;
    hexagon* item = new hexagon(38,40,40);
    item->setPos(38,40);
    item->setFlag(QGraphicsItem::ItemIsSelectable);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    Figure=item;
    scene->addItem(Figure);
    Figure->setPos(38,40);
    ui->doubleSpinBox->setValue(38);
    ui->doubleSpinBox_2->setValue(40);
    updateInfo();
}


void MainWindow::on_pushButton_4_clicked()
{
    currentFigure="star5";
    aded=true; count++;
    star* item = new star(0,0,40);
    item->setPos(40,40);
    item->setFlag(QGraphicsItem::ItemIsSelectable);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    Figure=item;
    scene->addItem(Figure);
    ui->doubleSpinBox->setValue(38);
    ui->doubleSpinBox_2->setValue(40);
    updateInfo();
}


void MainWindow::on_pushButton_5_clicked()
{
    currentFigure="star6";
    aded=true; count++;
    star6* item = new star6(0,0,40);
    item->setPos(40,40);
    item->setFlag(QGraphicsItem::ItemIsSelectable);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    Figure=item;
    scene->addItem(Figure);
    ui->doubleSpinBox->setValue(38);
    ui->doubleSpinBox_2->setValue(40);
    updateInfo();
}


void MainWindow::on_pushButton_6_clicked()
{
    currentFigure="star8";
    aded=true; count++;
    star8* item = new star8(0,0,40);
    item->setPos(40,40);
    item->setFlag(QGraphicsItem::ItemIsSelectable);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    Figure=item;
    scene->addItem(Figure);
    ui->doubleSpinBox->setValue(38);
    ui->doubleSpinBox_2->setValue(40);
    updateInfo();
}


void MainWindow::on_checkBox_stateChanged(int arg1)
{

}


void MainWindow::on_checkBox_clicked(bool checked)
{
if(checked)
{
    ui->statusbar->showMessage("clicked");
    scene2 = new canva();
    ui->graphicsView->setScene(scene2);
    QImage image("Canva-logo.png");
    QGraphicsPixmapItem item(QPixmap::fromImage(image));
    scene2->addItem(&item);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключаем скроллбар по вертикали
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по горизонтали
    scene2->setSceneRect(0,0,600,600); // Устанавливаем размер сцены
    ui->ellipse->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->change->hide();
    ui->square->hide();
    ui->square_2->hide();
    ui->triangle->hide();
    ui->textEdit->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->show();
    ui->doubleSpinBox->hide();
    ui->doubleSpinBox_2->hide();
    ui->doubleSpinBox_3->hide();
    ui->doubleSpinBox_4->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->groupBox->hide();
    ui->groupBox_2->hide();
    ui->groupBox_3->hide();
    ui->perimetr->hide();
    ui->area->hide();
    ui->label_6->hide();
    ui->pushButton_10->hide();
    ui->pushButton_9->hide();
    ui->pushButton_11->show();

} else if(!checked)
{
     ui->graphicsView->setScene(scene);
     ui->ellipse->show();
     ui->pushButton->show();
     ui->pushButton_2->show();
     ui->pushButton_3->show();
     ui->pushButton_4->show();
     ui->pushButton_5->show();
     ui->pushButton_6->show();
     ui->square->show();
     ui->change->show();
     ui->pushButton_7->show();
     ui->square_2->show();
     ui->triangle->show();
     ui->textEdit->show();
     ui->pushButton_8->hide();
     ui->doubleSpinBox->show();
     ui->doubleSpinBox_2->show();
     ui->doubleSpinBox_3->show();
     ui->doubleSpinBox_4->show();
     ui->label->show();
     ui->label_2->show();
     ui->label_3->show();
     ui->label_4->show();
     ui->label_5->show();
     ui->groupBox->show();
     ui->groupBox_2->show();
     ui->groupBox_3->show();
     ui->area->show();
     ui->perimetr->show();
     ui->label_6->show();
     ui->pushButton_10->show();
     ui->pushButton_9->show();
     ui->pushButton_11->hide();
}

}


void MainWindow::on_pushButton_7_clicked()
{
    if(aded && count)
   rotateTimer->stop();
    else QMessageBox::warning(this,"error","empty scene");
}

void MainWindow::createRect()
{
    Figure->deleteLater();
    rectDlg->hide();
    scene->clear();
    QString strHeight = LE_Height->text();
    QString strWidth = LE_Width->text();
    Figure = new rectangle(strHeight.toDouble(),strWidth.toDouble());
    Figure->setPos(38,40);
    Figure->setFlag(QGraphicsItem::ItemIsSelectable);
    Figure->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(Figure);
    ui->doubleSpinBox->setValue(38);
    ui->doubleSpinBox_2->setValue(40);
    updateInfo();
    scene->update();
}

void MainWindow::createSquare()
{
    Figure->deleteLater();
    squareDlg->hide();
    QString strA = LE_A->text();
    scene->clear();
    Figure = new square(strA.toDouble());
    Figure->setPos(38,40);
    Figure->setFlag(QGraphicsItem::ItemIsSelectable);
    Figure->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(Figure);
    ui->doubleSpinBox->setValue(38);
    ui->doubleSpinBox_2->setValue(40);
    updateInfo();
    scene->update();
}

void MainWindow::createEllipse()
{
    Figure->deleteLater();
    ovalDlg->hide();
    QString strOvalR = LE_ovalR->text();
    //scene->clear();
    Figure = new ellipse(strOvalR.toDouble());
    Figure->setPos(38,40);
    Figure->setFlag(QGraphicsItem::ItemIsSelectable);
    Figure->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(Figure);
    ui->doubleSpinBox->setValue(38);
    ui->doubleSpinBox_2->setValue(40);
    updateInfo();
    scene->update();
}

void MainWindow::createRhombus()
{
    Figure->deleteLater();
    rhombDlg->hide();
    QString strr = LE_r->text();
    Figure = new rhombus((double)38,(double)40,strr.toDouble());
    Figure->setPos(38,40);
    Figure->setFlag(QGraphicsItem::ItemIsSelectable);
    Figure->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(Figure);
    ui->doubleSpinBox->setValue(38);
    ui->doubleSpinBox_2->setValue(40);
    updateInfo();
    scene->update();
}

void MainWindow::createHexagon()
{
    Figure->deleteLater();
    hexDlg->hide();
    QString strHexR = LE_HexR->text();

    Figure = new hexagon(38,40,strHexR.toDouble());
    Figure->setPos(38,40);
    Figure->setFlag(QGraphicsItem::ItemIsSelectable);
    Figure->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(Figure);
    ui->doubleSpinBox->setValue(38);
    ui->doubleSpinBox_2->setValue(40);
    updateInfo();
    scene->update();
}

void MainWindow::createStar5()
{
    Figure->deleteLater();
    starDlg->hide();
    QString starR = LE_starR->text();

    Figure = new star(38,40,starR.toDouble());
    Figure->setPos(38,40);
    Figure->setFlag(QGraphicsItem::ItemIsSelectable);
    Figure->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(Figure);
    ui->doubleSpinBox->setValue(38);
    ui->doubleSpinBox_2->setValue(40);
    updateInfo();
    scene->update();
}

void MainWindow::createStar6()
{
    Figure->deleteLater();
    star6Dlg->hide();
    QString starR = LE_star6R->text();

    Figure = new star6(38,40,starR.toDouble());
    Figure->setPos(38,40);
    Figure->setFlag(QGraphicsItem::ItemIsSelectable);
    Figure->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(Figure);
    ui->doubleSpinBox->setValue(38);
    ui->doubleSpinBox_2->setValue(40);
    updateInfo();
    scene->update();
}

void MainWindow::createStar8()
{
    Figure->deleteLater();
    star8Dlg->hide();
    QString star8R = LE_star8R->text();

    Figure = new star8(38,40,star8R.toDouble());
    Figure->setPos(38,40);
    Figure->setFlag(QGraphicsItem::ItemIsSelectable);
    Figure->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(Figure);
    ui->doubleSpinBox->setValue(38);
    ui->doubleSpinBox_2->setValue(40);
    updateInfo();
    scene->update();
}

void MainWindow::on_change_clicked()
{
    if(aded && count)
    {
    if(currentFigure=="rectangle")
    {
    rectDlg->setModal(true);
    rectDlg->resize(160, 120);

    InputWidth->move(5, 5);
    InputHeight->move(5, 55);
    LE_Width->resize(65, 35);
    LE_Height->resize(65, 35);
    LE_Width->move(75, 5);
    LE_Height->move(75, 45);

    Enter = new QPushButton("Ввод ", rectDlg); Enter->adjustSize();
    Enter->move(50,90);
    connect(Enter, SIGNAL(clicked()), this, SLOT(createRect()));
    rectDlg->show();
    }
    else if (currentFigure == "triangle") {

            triangDlg->setModal(true);
            triangDlg->resize(300, 180);


            InputX1->move(40, 5);
            InputX2->move(40, 50);
            InputX3->move(40, 95);
            InputY1->move(180, 5);
            InputY2->move(180, 50);
            InputY3->move(180,95);

            LE_X1->resize(50, 30);
            LE_X2->resize(50, 30);
            LE_X3->resize(50, 30);
            LE_Y1->resize(50, 30);
            LE_Y2->resize(50, 30);
            LE_Y3->resize(50, 30);

            LE_X1->move(70, 5);
            LE_X2->move(70, 50);
            LE_X3->move(70, 95);
            LE_Y1->move(200, 5);
            LE_Y2->move(200, 50);
            LE_Y3->move(200, 95);

            Enter = new QPushButton("Ввод ", triangDlg); Enter->adjustSize();
            Enter->move(120, 140);
            //connect(Enter, SIGNAL(clicked()), this, SLOT(createTriang()));
            triangDlg->show();
        }
         else if (currentFigure == "square") {
            squareDlg->setModal(true);
            squareDlg->resize(300, 300);

            InputA->move(100, 130);

            LE_A->resize(60, 30);

            LE_A->move(170, 130);

            Enter = new QPushButton("Ввод ", squareDlg); Enter->adjustSize();
            Enter->move(150, 200);
            connect(Enter, SIGNAL(clicked()), this, SLOT(createSquare()));
            squareDlg->show();

        }
    else if (currentFigure == "rhoombus") {
            rhombDlg->setModal(true);
            rhombDlg->resize(300, 300);

            Inputr->move(100, 130);

            LE_r->resize(60, 30);

            LE_r->move(170, 130);

            Enter = new QPushButton("Ввод ", rhombDlg); Enter->adjustSize();
            Enter->move(150, 200);
            connect(Enter, SIGNAL(clicked()), this, SLOT(createRhombus()));
            rhombDlg->show();
        }
         else if (currentFigure == "ellipse") {
            ovalDlg->setModal(true);
            ovalDlg->resize(300, 300);
            LE_ovalR->resize(60, 30);
            LE_ovalR->move(170, 100);

            Enter = new QPushButton("Ввод ", ovalDlg); Enter->adjustSize();
            Enter->move(150, 200);
            connect(Enter, SIGNAL(clicked()), this, SLOT(createEllipse()));
            ovalDlg->show();
        } else if (currentFigure == "star5") {
            starDlg->setModal(true);
            starDlg->resize(300, 400);
            InputStarR->move(100, 150);
            LE_starR->resize(60, 30);

            LE_starR->move(170, 150);

            Enter = new QPushButton("Ввод ", starDlg); Enter->adjustSize();
            Enter->move(150, 300);
            connect(Enter, SIGNAL(clicked()), this, SLOT(createStar5()));
            starDlg->show();
        }
        else if (currentFigure == "hexagon") {
            hexDlg->setModal(true);
            hexDlg->resize(300, 300);

            InputHexR->move(100, 130);

            LE_HexR->resize(60, 30);

            LE_HexR->move(170, 130);

            Enter = new QPushButton("Ввод ", hexDlg); Enter->adjustSize();
            Enter->move(150, 200);
            connect(Enter, SIGNAL(clicked()), this, SLOT(createHexagon()));
            hexDlg->show();
        }
        else if (currentFigure == "star6") {
            star6Dlg->setModal(true);
            star6Dlg->resize(300, 400);
            InputStar6R->move(100, 150);
            LE_star6R->resize(60, 30);

            LE_star6R->move(170, 150);

            Enter = new QPushButton("Ввод ", star6Dlg); Enter->adjustSize();
            Enter->move(150, 300);
            connect(Enter, SIGNAL(clicked()), this, SLOT(createStar6()));
            star6Dlg->show();
        }
        else if (currentFigure == "star8") {
            star8Dlg->setModal(true);
            star8Dlg->resize(300, 400);
            InputStar8R->move(100, 150);
            LE_star8R->resize(60, 30);

            LE_star8R->move(170, 150);

            Enter = new QPushButton("Ввод ", star8Dlg); Enter->adjustSize();
            Enter->move(150, 300);
            connect(Enter, SIGNAL(clicked()), this, SLOT(createStar8()));
            star8Dlg->show();

    }

    } else
    {
        QMessageBox::warning(this,("error"),"empty scene");
    }
}

void MainWindow::nulling()
{
    ui->area->setText(QString::number(0));
    ui->perimetr->setText(QString::number(0));
    ui->doubleSpinBox_4->setValue(1.00);
    //ui->doubleSpinBox->setValue(21);
    //ui->doubleSpinBox_2->setValue(32);
}

void MainWindow::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    ui->statusbar->showMessage("3rwefjkwel;");
    this->updateInfo();
}

void MainWindow::on_pushButton_8_clicked()
{
    scene2->clear();
}


void MainWindow::on_doubleSpinBox_valueChanged(double arg)
{
    if(aded && count)
    {
    arg1=arg;
    Figure->setPos(arg1,arg2);
    }
    else
    {
        QMessageBox::warning(this,("error"),"empty scene");
    }
}


void MainWindow::on_pushButton_9_clicked()
{
    if(aded && count)
    {
    QPointF pos = Figure->scenePos();
    ui->doubleSpinBox->setValue(pos.x());
    ui->doubleSpinBox_2->setValue(pos.y());
    emit cords();
    } else
    {
        QMessageBox::warning(this,tr("error"),("empty scene"));
    }
}


void MainWindow::on_pushButton_10_clicked()
{
    clown* item = new clown();
    aded=true; count++;
    item->setPos(38,40);
    item->setFlag(QGraphicsItem::ItemIsSelectable);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    Figure=item;
    scene->addItem(Figure);
    updateInfo();
    scene->update();
}


void MainWindow::on_pushButton_11_clicked()
{
   color = QColorDialog::getColor(Qt::black,this,tr("enter color"));
}


void MainWindow::on_doubleSpinBox_textChanged(const QString &arg1)
{

}


void MainWindow::on_pushButton_2_clicked(bool checked)
{

}

void MainWindow::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
}

void MainWindow::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //PreviousPoint=QCursor::pos();
}
