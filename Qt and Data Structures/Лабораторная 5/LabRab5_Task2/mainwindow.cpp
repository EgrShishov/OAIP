#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(526,247);
    QStringList names;
    names<<"push_front()"<<"emplace_front()"<<"emplace_back()"<<"push_back()"<<"pop_front()"<<"pop_back()"<<"front()"<<"back()"<<"getAt"
        <<"clear()"<<"resize()"<<"print()"<<"isEmpty()"<<"size()"<<"capacity()";
    QCompleter* completer = new QCompleter(names,this);
    ui->label_7->setText("Для информации нажмитие Ctrl+I");
    ui->lineEdit->setPlaceholderText("Введите название функции...");
    ui->lineEdit->setFrame(true);
    ui->lineEdit->setToolTip("Доступные функции : push_front(T data),emplace_front(args...),emplace_back(args...),push_back(T data)\ngetAt(int index),pop_front(),"
                             "front(),back(),pop_back(),size(),resize(),capacity(),clear(),print(),isEmpty()");
    ui->lineEdit->setCompleter(completer);
    const QIcon passwordIcon("D:/command-line.png");
    ui->lineEdit->addAction(passwordIcon, QLineEdit::LeadingPosition);
    ui->label->setStyleSheet("* { background-color: rgb(220,220,220) }");
    ui->pushButton->setStyleSheet("* { background-color: rgb(255,127,80);"
                                  "border-radius: 10px;"
                                  "font : bold;}");
    ui->label_5->setStyleSheet("* { background-color: rgb(255,127,80);}");
    ui->lineEdit->setStyleSheet(QString("QLineEdit {border-width: 2px;"
                                        "border-style: solid; "
                                        "border-color: rgb(255,127,80);"
                                        "border-radius: 10px;}"));
    ui->textEdit->setStyleSheet(QString("QTextEdit {border-width: 2px;"
                                        "border-style: solid; "
                                        "border-color: rgb(255,127,80);}"));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));

    effect = new QGraphicsDropShadowEffect(this);
    effect->setColor(QColor(255,127,80));
    effect->setBlurRadius(50);
    effect->setXOffset(3);
    effect->setYOffset(3);
    effect->setEnabled(true);
    ui->textEdit->setGraphicsEffect(effect);

    for(int i=0;i<1000;i++)
    {
       if(i%2==0)
           deq.push_front(i);
       else
           deq.push_back(i);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString command = ui->lineEdit->text();
    QStringList args;
    QString used_function_info = command;
    QRegularExpression re("\\((.*)\\)");
    QRegularExpressionMatch match = re.match(command);
    command=command.section('(',0,-2);
    qDebug()<<command;
    args = match.captured(1).split(",");

    for(int i=0;i<deq.size();i++)
        qDebug()<<QString::number(deq[i]);

    if(command=="push_front")
    {
        if(args.size()==1)
        {
            deq.push_front(args[0].toInt());
            print();
        }
        else
        {
            QMessageBox::warning(this,"","");
        }
    }
    else if(command=="push_back")
    {
        if(args.size()==1)
        {
            deq.push_back(args[0].toInt());
            print();
        }
        else
        {
            QMessageBox::warning(this,"","");
        }
    }
    else if(command=="pop_front")
    {
        if(args.size()==1 && args[0].isEmpty())
        {
            deq.pop_front();
            print();
        }
        else
        {
            QMessageBox::warning(this,"","");
        }
    }
    else if(command=="pop_back")
    {
        if(args.size()==1 && args[0].isEmpty())
        {
            deq.pop_back();
            print();
        }
        else
        {
            QMessageBox::warning(this,"","");
        }
    }
    else if(command=="front")
    {
        ui->textEdit->setText(QString::number(deq.front()));
        if(args.size()==1 && args[0].isEmpty())
        {
            if(!deq.isEmpty()) ui->textEdit->setText("Очередь пуста!");
            else
            {
            QString ans = QString::number(deq.front());
            ui->textEdit->setText(ans);
            }
        }
        else
        {
            QMessageBox::warning(this,"","");
        }
    }
    else if(command=="back")
    {
        if(args.size()==1 && args[0].isEmpty())
        {
            if(!deq.isEmpty()) ui->textEdit->setText("Очередь пуста!");
            else
            {
            QString ans = QString::number(deq.back());
            ui->textEdit->setText(ans);
            }
        }
        else
        {
            QMessageBox::warning(this,"","");
        }
    }
    else if(command=="clear")
    {
        if(args.size()==1 && args[0].isEmpty())
        {
            deq.clear();
            ui->textEdit->setText("Очередь очищена");
        }
        else
        {
            QMessageBox::warning(this,"","");
        }
    }
    else if(command=="print")
    {
        if(args.size()==1 && args[0].isEmpty())
        {
            if(deq.size()!=0)
            print();
            else ui->textEdit->setText("Очередь пуста");
        }
        else
        {
            QMessageBox::warning(this,"","");
        }
    }
    else if(command=="isEmpty")
    {
        if(args.size()==1 && args[0].isEmpty())
        {
            bool ans = deq.isEmpty();
            if(ans==true)
                ui->textEdit->setText("Очередь пуста");
            else
                ui->textEdit->setText("Очередь не пуста");
        }
        else
        {
            QMessageBox::warning(this,"","");
        }
    }
    else if(command=="size")
    {
        if(args.size()==1 && args[0].isEmpty())
        {
            int ans = deq.size();
            if(ans==0)
                ui->textEdit->setText("Очередь пуста");
            else
                ui->textEdit->setText(QString::number(ans));
        }
        else
        {
            QMessageBox::warning(this,"","");
        }
    }
    else if(command=="resize")
    {
        qDebug()<<QString::number(args[0].toInt());
        //deq.resize(args[0].toInt());
    }
    else if(command=="getAt")
    {
//        if(args[0].toInt() < deq.size() - 1 && args[0].toInt() >= 0 && deq.isEmpty())
        ui->textEdit->setText(QString::number(deq[args[0].toInt()]));
//        else
//            QMessageBox::warning(this,"Ошибка","Выход за границы дэка");
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Данная функция не найдена");
    }
    QString info;
    info = "Использована функция : " + used_function_info;
    QString size = "Size : " + QString::number(deq.size());
    ui->lineEdit->clear();
    ui->label_2->setText(info);
    ui->statusbar->showMessage(size);
}

void MainWindow::print()
{
    ui->textEdit->clear();
    QString ans;
    for(int i = 0;i<deq.size();i++)
        ans += QString::number(deq[i]) + ", ";
    ui->textEdit->setText(ans);
}
