#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("HashMap");
    setFixedSize(530,270);
    ui->setupUi(this);
    QStringList names;
    names<<"insert()"<<"remove()"<<"find()"<<"percent_of_load()"<<"print()"<<"get()"<<"rehash()";
    QCompleter* completer = new QCompleter(names,this);
    ui->label_7->setText("Для информации нажмитие Ctrl+I");
    ui->lineEdit->setPlaceholderText("Введите название функции...");
    ui->lineEdit->setFrame(true);
    ui->lineEdit->setToolTip("Доступные функции : insert(int key, T value), remove(int key)\nfind(int key,T value),"
                             " get(int key), percent_of_load(), print(), rehash()");
    ui->lineEdit->setCompleter(completer);
    const QIcon passwordIcon("D:/command-line.png");
    ui->lineEdit->addAction(passwordIcon, QLineEdit::LeadingPosition);
    ui->label->setStyleSheet("* { background-color: rgb(220,220,220) }");
    ui->pushButton->setStyleSheet("* {background-color : rgb(123,104,238)}");
    ui->pushButton_2->setStyleSheet("* { background-color: rgb(123,104,238) }");
    ui->label_5->setStyleSheet("* { background-color: rgb(123,104,238) }");
    ui->lineEdit->setStyleSheet(QString("QLineEdit {border-width: 2px;"
                                        "  border-style: solid; "
                                        "border-color: rgb(123,104,238)}"));
    ui->textEdit->setStyleSheet(QString("QTextEdit {border-width: 2px;"
                                        "  border-style: solid; "
                                        "border-color: rgb(123,104,238);}"));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(on_pushButton_2_clicked()));

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setColor(QColor(123,104,238));
    effect->setBlurRadius(50);
    effect->setXOffset(3);
    effect->setYOffset(3);
    effect->setEnabled(true);
    ui->textEdit->setGraphicsEffect(effect);

    for(int i=0;i<5;i++)
        map.insert(rand()%3433,names[i%6]);
}


MainWindow::~MainWindow()
{
    delete ui;
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
    qDebug()<<"im working";

    if(command=="insert")
    {
        if(args.size()==2)
        {
            map.insert(args[0].toInt(),args[1]);
            ui->textEdit->setText(map.print_map());
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }
    }
    else if(command=="find")
    {
        if(args.size()==2)
        {
            QString ans;
            if(map.find(args[0].toInt(),args[1])==true)
            {
                ans = "Содержится";
            }
            else ans = "Не содержится ";
            ui->textEdit->setText(ans);
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }
    }
    else if(command=="remove")
    {
        if(args.size()==1)
        {
            map.remove(args[0].toInt());
            ui->textEdit->setText(map.print_map());
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }
    }
    else if(command=="percent_of_load")
    {
        if(args.size()==1)
        {
            QString ans = QString::number(map.percent_of_load()) + " %";
            ui->textEdit->setText(ans);
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }
    }
    else if(command=="get")
    {
        if(map.exist(args[0].toInt()))
                ui->textEdit->setText(map.get(args[0].toInt()));
        else
            ui->textEdit->setText("Такая пара в таблице отсутствует");
    }
    else if(command=="print")
    {
        if(args.size()==1)
        {
            qDebug()<<"im here";
            ui->textEdit->setText(map.print_map());
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }
    }
    else if(command=="rehash")
    {
        map.rehash();
        ui->textEdit->setText(map.print_map());
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Данная функция не найдена");
    }

    QString info;
    QString hash_map;
    hash_map = "Size : " + QString::number(map.size()) + ", load_factor : " + QString::number(map.percent_of_load());
    info = "Использована функция : " + used_function_info;
    ui->lineEdit->clear();
    ui->statusbar->showMessage(info + ", " + hash_map);
}

void MainWindow::on_pushButton_clicked()
{
    solution task;
    ui->textEdit->setText(task.map.print_map() + " " + QString::number(task.solve()) + "\n" + task.print());
}

