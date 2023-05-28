#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("map's analog");
    setFixedSize(530,270);
    ui->setupUi(this);
    QStringList names;
    names<<"insert()"<<"erase()"<<"find()"<<"contains()"<<"empty()"<<"size()"<<"clear()"<<"getAt()"<<"print()";
    completer = new QCompleter(names,this);
    ui->label_7->setText("Для информации нажмитие Ctrl+I");
    ui->lineEdit->setPlaceholderText("Введите название функции...");
    ui->lineEdit->setFrame(true);
    ui->lineEdit->setToolTip("Доступные функции : insert(KeyType key, ValueType value), erase(KeyType key)\nfind(KeyType key),"
                             " contains(KeyType key), clear(), print() , ()");
    ui->lineEdit->setCompleter(completer);
    const QIcon passwordIcon("D:/command-line.png");
    ui->lineEdit->addAction(passwordIcon, QLineEdit::LeadingPosition);
    ui->label->setStyleSheet("* { background-color: rgb(188,204,203) }");
    ui->pushButton->setStyleSheet("* {background-color : rgb(142,172,80)}");
    ui->label_5->setStyleSheet("* { background-color: rgb(195,164,26) }");
    ui->lineEdit->setStyleSheet(QString("QLineEdit {border-width: 3px;"
                                        "  border-style: solid; "
                                        "border-color: rgb(190,183,117)}"));
    ui->textEdit->setStyleSheet(QString("QTextEdit {border-width: 2px;"
                                        "  border-style: solid; "
                                        "border-color: rgb(195,164,26);}"));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setColor(QColor(195,164,26));
    effect->setBlurRadius(50);
    effect->setXOffset(3);
    effect->setYOffset(3);
    effect->setEnabled(true);
    ui->textEdit->setGraphicsEffect(effect);

    for(int i=0;i<32;i++)
        myMap.insert(rand()%32,QString::number(rand()%21563621));
    myMap.erase(16);
    myMap.erase(33);
    myMap.erase(19);
    myMap.erase(1);
    myMap.erase(32);
    int i=0;
    for(auto it = myMap.lbegin();it!=myMap.lend();it++)
    {
        qDebug()<<it->data.second;
    }
    qDebug()<<"deque\n";
    myMap.print_list();
    set<int> mySet;
    mySet.insert(322);
    mySet.insert(234);
    qDebug()<<mySet.contains(322);
    qDebug()<<mySet.count(322);
    //mySet.erase(322);
//    QString ans;
//    mySet.print(ans);
//    qDebug()<<ans;
    //qDebug()<<mySet.count(322);
    //mySet[23]=3123;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString command = ui->lineEdit->text();
    bool brackets = false;
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
        if(args.size()==2)
        {
            myMap.insert(args[0].toInt(),args[1]);
            QString _map;
            myMap.print(_map);
            ui->textEdit->setText(_map);
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
            return;
        }
    }
    else if(command=="erase")
    {
        if(args.size()==1 && !args[0].isEmpty())
        {
            if(!myMap.contains(args[0].toInt()))
            {
                QMessageBox::warning(this,"Ошибка","Такого ключа не найдено");
                return;
            }
            myMap.erase(args[0].toInt());
            QString _map;
            myMap.print(_map);
            ui->textEdit->setText(_map);
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }
    }
    else if(command=="find")
    {
        if(args.size()==1 && !args[0].isEmpty())
        {
            QString ans = myMap.find(args[0].toInt());
            ui->textEdit->setText("Найдено : " + ans);
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }
    }
    else if(command=="contains")
    {
        if(args.size()==1 && !args[0].isEmpty())
        {
            bool is = myMap.contains(args[0].toInt());
            if(is)
               ui->textEdit->setText("Данная пара содержится");
            else
                ui->textEdit->setText("Данная пара не содержится");
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
           myMap.clear();
           ui->textEdit->setText("Мапа очищена");
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }
    }
    else if(command=="empty")
    {
        if(args.size()==1 && args[0].isEmpty())
        {
            bool is = myMap.empty();
            if(is)
               ui->textEdit->setText("Данная мапа пуста");
            else
                ui->textEdit->setText("Данная мапа не пуста");
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
          ui->textEdit->setText("Размер : " + QString::number(myMap.size()));
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
          QString _map;
          myMap.print(_map);
          ui->textEdit->setText(_map);
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }
    }
    else if(command=="getAt")
    {
        ui->textEdit->setText(myMap[args[0].toInt()]);
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Данная функция не найдена");
        return;
    }

    QString info, mapa;
    mapa = "Size : " + QString::number(myMap.size());
    info = "Использована функция : " + used_function_info;
    ui->lineEdit->clear();
    ui->statusbar->showMessage(info + ", " + mapa);
}

