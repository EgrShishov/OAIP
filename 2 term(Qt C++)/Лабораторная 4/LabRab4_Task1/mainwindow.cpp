#include "mainwindow.h"
#include "ui_mainwindow.h"

unique_ptr<int> Foo2()
{
    unique_ptr<int> p2(new int(123));
    return p2;
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    int* arr = new int[5];
//    for(int i=0;i<5;i++)
//        arr[i]=i+1;

//    for(int i =0;i<5;i++)
//        qDebug()<<arr[i];
//    int* arr2 = new int[5];
//    for(int i=0;i<5;i++)
//        arr2[i]=10+1;

//    shared_ptr<int[]> ptr(arr);
//    shared_ptr<int[]> ptr2(arr2);

//    std::shared_ptr<int[]> ptr3(arr);
//    std::shared_ptr<int[]> ptr4(arr2);
//    ptr3=ptr4;

//    for(int i=0;i<5;i++)
//        qDebug()<<ptr3[i];

//    for(int i=0;i<5;i++)
//        qDebug()<<ptr[i];
//    qDebug()<<ptr.unique();

//    unique_ptr<int> pointer(new int(7));
//    qDebug()<<pointer;

//    qDebug()<<"fshjfef";
//    int* a = new int(5);
//    int* b = new int(31);
//    shared_ptr<int> aboba(a);
//    shared_ptr<int> max(b);
//    aboba.swap(max);
//    qDebug()<<QString::number(*aboba.get())<<" "<<QString::number(*max.get());
//    shared_ptr<int> p1(new int(4));
//        qDebug() << *p1;
//        qDebug() << p1;
//        p1.reset(nullptr);
//        qDebug() << p1;
//        p1.reset(new int (10));
//        int* a = p1.get();
//        qDebug() << *a;
//        qDebug() << *p1;
//        qDebug() << p1;
//        p1 = Foo2();
//        qDebug() << *p1;
//        shared_ptr<int> p2(Foo2());
//        qDebug() << *p2;
//        p2.reset(new int(321));
//        p1.swap(p2);
//        qDebug() << *p1;
//        qDebug() << *p2;
//        qDebug() << p1.use_count();
//        p2 = p1;
//        qDebug() << p1.use_count();
//        p1.reset(nullptr);
//        qDebug() << p2.use_count();

    unique_ptr<int> p1(new int(4));
        qDebug() << *p1;
        qDebug() << p1;
        p1.reset(nullptr);
        qDebug() << p1;
        p1.reset(new int (10));
        int* a = p1.get();
        qDebug() << *a;
        qDebug() << *p1;
        qDebug() << p1;
        p1 = Foo2();
        qDebug() << *p1;
        unique_ptr<int> p2(Foo2());
        qDebug() << *p2;
        p2.reset(new int(321));
        p1.swap(p2);
        qDebug() << *p1;
        qDebug() << *p2;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString text = ui->textEdit->toPlainText();
    QString adress = QString( "0x%1" ).arg( reinterpret_cast<quintptr>(&unique),
                        QT_POINTER_SIZE * 2, 16, QChar('0') );
    QString adress2 = QString( "0x%1" ).arg( reinterpret_cast<quintptr>(&shared),
                        QT_POINTER_SIZE * 2, 16, QChar('0') );
    int N = ui->comboBox->currentIndex();
    switch (N)
    {
    case 0:
    {
        ui->statusbar->showMessage("Адресс указателя " + adress);
        if(!unique)
        {
        unique = unique_ptr<int>::make_unique(new int(text.toInt()));
        }
        else QMessageBox::warning(this,"Ошибка","unique_ptr уже занят по этому адресу");
        break;
    }
    case 1:
    {
        ui->statusbar->showMessage("Адресс указателя " + adress2 + ", use_count : " + QString::number(shared.use_count()));
        shared = shared_ptr<int>::make_shared(text.toInt());
        break;
    }
    default:
    {
        break;
    }
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    int N = ui->comboBox->currentIndex();
    switch (N)
    {
    case 0:
    {
        unique.reset(nullptr);
        ui->statusbar->showMessage("Деструктор unique_ptr успешно вызван");
        break;
    }
    case 1:
    {
        if(shared.use_count()!=0)
        {

        }
        break;
    }
    default:
    {
        break;
    }
    }
}

