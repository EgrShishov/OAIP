#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "list.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setWindowTitle("HashMap");
    setFixedSize(530,270);
    ui->setupUi(this);
    QStringList names;
    names<<"insert()"<<"peek()"<<"replace()"<<"remove()"<<"size()"<<"is_empty()"<<"clear()";

    QCompleter* completer = new QCompleter(names,this);
    ui->label_7->setText("Для информации нажмитие Ctrl+I");
    ui->lineEdit->setPlaceholderText("Введите название функции...");
    ui->lineEdit->setFrame(true);
    ui->lineEdit->setToolTip("Доступные функции : insert(T value), peek()\n"
                             "replace(int index, T new_element), remove(int index), size(), is_empty(), clear()");
    ui->lineEdit->setCompleter(completer);
    const QIcon passwordIcon("D:/command-line.png");
    ui->lineEdit->addAction(passwordIcon, QLineEdit::LeadingPosition);
    ui->label->setStyleSheet("* { background-color: rgb(220,220,220) }");
    ui->pushButton->setStyleSheet("* {background-color : rgb(209,226,49)}");
    ui->label_5->setStyleSheet("* { background-color: rgb(209,226,49) }");
    ui->lineEdit->setStyleSheet(QString("QLineEdit {border-width: 2px;"
                                        "  border-style: solid; "
                                        "border-color: rgb(209,226,49)}"));
    ui->textEdit->setStyleSheet(QString("QTextEdit {border-width: 2px;"
                                        "  border-style: solid; "
                                        "border-color: rgb(209,226,49);}"));
    ui->treeWidget->setStyleSheet(QString("QTreeWidget {border-width: 2px;"
                                        "  border-style: solid; "
                                        "border-color: rgb(209,226,49);}"));

    effect = new QGraphicsDropShadowEffect(this);
    effect->setColor(QColor(209,226,49));
    effect->setBlurRadius(50);
    effect->setXOffset(3);
    effect->setYOffset(3);
    effect->setEnabled(true);
    ui->treeWidget->setGraphicsEffect(effect);

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));

    forward_list<double> mama;
    for(int i=0;i<10000;i++)
        mama.push_front(i);
    qDebug()<<"succesfully";

    for(int i=0;i<10000;i++)
    {
        qDebug()<<mama.front()->data;
        mama.pop_front();
    }
    list<int> lst;
    for(int i=0;i<100;i++)
    {
        if(i%2==0)
        lst.push_front(i);
        else
            lst.push_back(i);
    }
    for(int i=0;i<50;i++)
    {
        lst.erase(i);
    }
    for(int i=0;i<lst.size();i++)
        qDebug()<<lst.getAt(i)->data;
    list_heap<int> h;
    //h.insert(300);
//    h.insert(200);
//    h.insert(10);
//    h.insert(50);
//    h.insert(150);
//    h.pop();
//    h.remove(3);
//    h.replace(0,1);
    qDebug()<<"heap";
//    for(int i=0;i<h.size();i++)
//        qDebug()<<h[i];
//    qDebug()<<"peek"<<h.peek();
    //h.clear();
    //qDebug()<<h.peek();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->treeWidget->clear();
    bool on_list = ui->checkBox->isChecked();
    QString command = ui->lineEdit->text();
    QStringList args;
    QString used_function_info = command;
    QRegularExpression re("\\((.*)\\)");
    QRegularExpressionMatch match = re.match(command);
    command=command.section('(',0,-2);
    qDebug()<<command;
    args = match.captured(1).split(",");
    qDebug()<<"im working";

    if(command=="insert")
    {
        if(!args[0].isEmpty() && args.size()==1)
        {
            if(on_list)
            {
            myHeap.insert(args[0].toInt());
            myHeap.print_heap(ui->treeWidget,nullptr,0);
            }
            else
            {
                intHeap.insert(args[0].toInt());
                intHeap.print_heap(ui->treeWidget,nullptr,0);
            }
        }
        else
            QMessageBox::warning(this,"Ошибка","Для функции " + used_function_info + " не существует такой перегрузки!");
    }
    else if(command=="remove")
    {
        if(!args[0].isEmpty() && args.size()==1)
        {
            if(on_list)
            {
            myHeap.remove(args[0].toInt());
            myHeap.print_heap(ui->treeWidget,nullptr,0);
            }
            else
            {
                intHeap.remove(args[0].toInt());
                intHeap.print_heap(ui->treeWidget,nullptr,0);
            }
        }
        else
            QMessageBox::warning(this,"Ошибка","Для функции " + used_function_info + " не существует такой перегрузки!");
    }
    else if(command=="peek")
    {
        if(args[0].isEmpty() && args.size()==1)
        {
            if(on_list)
            {
            ui->textEdit->setText(QString::number(myHeap.peek()));
            }
            else
            {
                ui->textEdit->setText(QString::number(intHeap.peek()));
            }
        }
        else
            QMessageBox::warning(this,"Ошибка","Для функции " + used_function_info + " не существует такой перегрузки!");
    }
    else if(command=="clear")
    {
        if(args[0].isEmpty() && args.size()==1)
        {
            if(on_list)
            {
            myHeap.clear();
            }
            else
                intHeap.clear();
        }
        else
            QMessageBox::warning(this,"Ошибка","Для функции " + used_function_info + " не существует такой перегрузки!");
    }
    else if(command=="replace")
    {
        if(!args[0].isEmpty() && args.size()==2)
        {
            if(on_list)
            {
            myHeap.replace(args[0].toInt(),args[1].toInt());
            myHeap.print_heap(ui->treeWidget,nullptr,0);
            }
            else
            {
                intHeap.replace(args[0].toInt(),args[1].toInt());
                intHeap.print_heap(ui->treeWidget,nullptr,0);
            }
        }
        else
            QMessageBox::warning(this,"Ошибка","Для функции " + used_function_info + " не существует такой перегрузки!");
    }
    else if(command=="size")
    {
        if(args[0].isEmpty() && args.size()==1)
        {
            if(on_list)
            ui->textEdit->setText(QString::number(myHeap.size()));
            else
                ui->textEdit->setText(QString::number(intHeap.size()));
        }
        else
            QMessageBox::warning(this,"Ошибка","Для функции " + used_function_info + " не существует такой перегрузки!");
    }
    else if(command=="is_empty")
    {
        if(args[0].isEmpty() && args.size()==1)
        {
            if(on_list)
            !myHeap.is_empty() ? ui->textEdit->setText("Куча не пуста") : ui->textEdit->setText("Куча пуста");
            else
                !intHeap.is_empty() ? ui->textEdit->setText("Куча не пуста") : ui->textEdit->setText("Куча пуста");
        }
        else
            QMessageBox::warning(this,"Ошибка","Для функции " + used_function_info + " не существует такой перегрузки!");
    }
    else
    {
        if(ui->lineEdit->text().isEmpty())
            QMessageBox::warning(this,"Ошибка","Командная строка пуста!");
        else
        QMessageBox::warning(this,"Ошибка","Такой функции не существует/не реализована");
        return;
    }

    QString info;
    if(on_list)
        info += "Куча на списке, ";
    else
        info += "Куча на массиве, ";
    info = "Использована функция : " + used_function_info;
    ui->lineEdit->clear();
    ui->statusbar->showMessage(info);
}

