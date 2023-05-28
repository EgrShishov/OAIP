#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Deque");
    setFixedSize(526,270);
    ui->setupUi(this);
    QStringList names;
    names<<"push_front()"<<"push_back()"<<"pop_front()"<<"pop_back()"<<"front()"<<"back()"<<"clear()"<<"print()"<<"isEmpty()"<<"size()";
    QCompleter* completer = new QCompleter(names,this);
    ui->label_7->setText("Для информации нажмитие Ctrl+I");
    ui->lineEdit->setPlaceholderText("Введите название функции...");
    ui->lineEdit->setFrame(true);
    ui->lineEdit->setToolTip("Доступные функции : push_front(T data),push_back(T data),\npop_front(),front(),back(),pop_back(),size(),clear(),print(),isEmpty()");
    ui->lineEdit->setCompleter(completer);
    const QIcon passwordIcon("D:/command-line.png");
    ui->lineEdit->addAction(passwordIcon, QLineEdit::LeadingPosition);
    ui->label->setStyleSheet("* { background-color: rgb(220,220,220) }");
    ui->pushButton->setStyleSheet("* { background-color: rgb(60,170,60) }");
    ui->pushButton_2->setStyleSheet("* { background-color: rgb(60,170,60) }");
    ui->label_5->setStyleSheet("* { background-color: rgb(60,170,60) }");
    ui->lineEdit->setStyleSheet(QString("QLineEdit {border-width: 2px;"
                                        "  border-style: solid; "
                                        "border-color: rgb(60,170,60);}"));
    ui->textEdit->setStyleSheet(QString("QTextEdit {border-width: 2px;"
                                        "  border-style: solid; "
                                        "border-color: rgb(60,170,60);}"));
//    Deque<int> mama;
//    for(int i=0;i<10;i++)
//    mama.push_back(i);
//    int a = mama.front(), b = mama.back();
//    qDebug()<<QString::number(a)<<QString::number(b);
//    mama.pop_front();
//    mama.pop_front();
//    mama.pop_back();
//    a = mama.front();
//    b = mama.back();

//    Deque<int> papa = {112,141,4114};
//    for(int i=0;i<papa.size();i++)
//        qDebug()<<QString::number(papa[i]);

//    qDebug()<<QString::number(a)<<QString::number(b);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked()));

    effect = new QGraphicsDropShadowEffect(this);
    effect->setColor(QColor(60,170,60));
    effect->setBlurRadius(50);
    effect->setXOffset(3);
    effect->setYOffset(3);
    effect->setEnabled(true);
    ui->textEdit->setGraphicsEffect(effect);
    for(int i=0;i<25;i++)
    {
        if(i%2==0)
        intDeq.push_back(i);
        else
            intDeq.push_front(i);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool Checking(QString mama)
{
    bool ans = true;
    for(int i=0;i<mama.size();i++)
    {
        if(!mama[i].isDigit()) {ans = false; break;}
    }
    return ans;
}

void MainWindow::on_pushButton_2_clicked()
{
    QString command = ui->lineEdit->text();
    QStringList args;
    QString used_function_info = command;
    QRegularExpression re("\\((.*)\\)");
    QRegularExpressionMatch match = re.match(command);
    command=command.section('(',0,-2);
    qDebug()<<command;
    args = match.captured(1).split(",");


    if(command=="push_front")
    {
        if(args.size()==1 && Checking(args[0]))
        {
            intDeq.push_front(args[0].toInt());
            print();
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }

    }
    else if(command=="push_back")
    {
        if(args.size()==1 && Checking(args[0]))
        {
            intDeq.push_back(args[0].toInt());
            print();
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }
    }
    else if(command=="pop_front")
    {
        if(args.size()==1 && args[0].isEmpty())
        {
            if(!intDeq.isEmpty())
            {
            intDeq.pop_front();
            print();
            }
            else ui->textEdit->setText("Очередь пуста");
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }
    }
    else if(command=="pop_back") //change
    {
        if(args.size()==1 && args[0].isEmpty())
        {
            if(!intDeq.isEmpty())
            {
            intDeq.pop_back();
            print();
            }
            else ui->textEdit->setText("Очередь пуста");
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }
    }
    else if(command=="front")
    {
        if(args.size()==1 && args[0].isEmpty())
        {
            if(intDeq.isEmpty()) ui->textEdit->setText("Очередь пуста!");
            else
            {
            QString ans = QString::number(intDeq.front());
            ui->textEdit->setText(ans);
            }
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }
    }
    else if(command=="back")
    {
        if(args.size()==1 && args[0].isEmpty())
        {
            if(intDeq.isEmpty()) ui->textEdit->setText("Очередь пуста!");
            else
            {
            QString ans = QString::number(intDeq.back());
            ui->textEdit->setText(ans);
            }
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }
    }
    else if(command=="clear")
    {
        if(args.size()==1 && args[0].isEmpty())
        {
            intDeq.clear();
            ui->textEdit->setText("Очередь очищена");
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }
    }
    else if(command=="print")
    {
        if(args.size()==1 && args[0].isEmpty())
        {
            if(intDeq.size()!=0)
            print();
            else ui->textEdit->setText("Очередь пуста");
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }
    }
    else if(command=="isEmpty")
    {
        if(args.size()==1 && args[0].isEmpty())
        {
            bool ans = intDeq.isEmpty();
            if(ans==true)
                ui->textEdit->setText("Очередь пуста");
            else
                ui->textEdit->setText("Очередь не пуста");
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }
    }
    else if(command=="size")
    {
        if(args.size()==1 && args[0].isEmpty())
        {
            int ans = intDeq.size();
            if(ans==0)
                ui->textEdit->setText("Очередь пуста");
            else
                ui->textEdit->setText(QString::number(ans));
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Данная функция не найдена");
    }
    QString info;
    info = "Использована функция : " + used_function_info;
    ui->lineEdit->clear();
    ui->statusbar->showMessage(info);
}


void MainWindow::on_pushButton_clicked()
{
    solution solve;
    uint n = rand()%100;
    solve.input(n);
    ui->textEdit->setText(solve.solve());
}

void MainWindow::print()
{
    QString deq;
    if(intDeq.size()==0) deq+="Очередь пуста";
    else
    {
    for(int i=0;i<intDeq.size();i++)
    {
        deq += QString::number(intDeq[i]) + ", ";
    }
    }
    ui->textEdit->setText(deq);

}
