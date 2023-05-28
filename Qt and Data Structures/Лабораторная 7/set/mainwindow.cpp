#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("set's analog");
    setFixedSize(530,270);
    ui->setupUi(this);
    QStringList names;
    names<<"insert()"<<"erase()"<<"count()"<<"contains()"<<"empty()"<<"size()"<<"clear()"<<"print()";
    completer = new QCompleter(names,this);
    ui->label_7->setText("Для информации нажмитие Ctrl+I");
    ui->lineEdit->setPlaceholderText("Введите название функции...");
    ui->lineEdit->setFrame(true);
    ui->lineEdit->setToolTip("Доступные функции : insert(KeyType key), erase(KeyType key)\n,count(KeyType key)"
                             " contains(KeyType key), clear(), print()");
    ui->lineEdit->setCompleter(completer);
    const QIcon passwordIcon("D:/command-line.png");
    ui->lineEdit->addAction(passwordIcon, QLineEdit::LeadingPosition);
    ui->label->setStyleSheet("* { background-color: rgb(168,196,220) }");
    ui->pushButton->setStyleSheet("* {background-color : rgb(140,72,55)}");
    ui->label_5->setStyleSheet("* { background-color: rgb(140,72,55) }");
    ui->lineEdit->setStyleSheet(QString("QLineEdit {border-width: 2px;"
                                        "  border-style: solid; "
                                        "border-color: rgb(140,72,55)}"));
    ui->textEdit->setStyleSheet(QString("QTextEdit {border-width: 2px;"
                                        "  border-style: solid; "
                                        "border-color: rgb(140,72,55);}"));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->lineEdit,SIGNAL(editingFinished()),this,SLOT(on_pushButton_clicked()));

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setColor(QColor(140,72,55));
    effect->setBlurRadius(50);
    effect->setXOffset(3);
    effect->setYOffset(3);
    effect->setEnabled(false);
    ui->textEdit->setGraphicsEffect(effect);

    mySet.insert(QString::number(123768976));
    mySet.insert(QString::number(342384));
    mySet.insert(QString::number(234234));
    mySet.insert(QString::number(4234234879));
    for(auto it = mySet.lbegin();it!=mySet.lend();it++)
        qDebug()<<it->key;
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
    qDebug()<<"im working";

    if(command=="insert")
    {
        if(args.size()==1)
        {
            mySet.insert(args[0]);
            QString _set;
            mySet.print(_set);
            ui->textEdit->setText(_set);
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }
    }
    else if(command=="erase")
    {
        if(args.size()==1 && !args[0].isEmpty())
        {
            mySet.erase(args[0]);
            QString _set;
            mySet.print(_set);
            ui->textEdit->setText(_set);
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
            bool is = mySet.contains(args[0]);
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
           mySet.clear();
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
            bool is = mySet.empty();
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
          ui->textEdit->setText("Размер : " + QString::number(mySet.size()));
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }
    }
    else if(command=="count")
    {
        if(args.size()==1 && args[0].isEmpty())
        {
          ui->textEdit->setText("Размер : " + QString::number(mySet.count(args[0])));
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
          QString _set;
          mySet.print(_set);
          ui->textEdit->setText(_set);
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Данная функция не найдена");
        return;
    }

    QString info, set;
    set = "Size : " + QString::number(mySet.size());
    info = "Использована функция : " + used_function_info;
    ui->lineEdit->clear();
    ui->statusbar->showMessage(info + ", " + set);
}


void MainWindow::on_lineEdit_editingFinished()
{
    on_pushButton_clicked();
}

