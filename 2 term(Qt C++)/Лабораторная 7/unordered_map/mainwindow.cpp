#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("unordered_map");
    ui->setupUi(this);
    QStringList names;
    names<<"insert()"<<"erase()"<<"clear()"<<"contains()"<<"find()"<<"print()"<<"load_factor()"<<"size()"<<"empty()"<<"[]";
    QCompleter* completer = new QCompleter(names,this);
    ui->label_7->setText("Для информации нажмитие Ctrl+I");
    ui->lineEdit->setPlaceholderText("Введите название функции...");
    ui->lineEdit->setFrame(true);
    ui->lineEdit->setToolTip("Доступные функции : insert(KeyType key,ValueType value), erase(KeyType key,ValueType value)\n"
                             "find(KeyType key,ValueType value), contains(KeyType key), print(), load_factor(), size(), empty(), [KeyType key]");
    ui->lineEdit->setCompleter(completer);
    const QIcon passwordIcon("D:/command-line.png");
    ui->lineEdit->addAction(passwordIcon, QLineEdit::LeadingPosition);
    ui->label->setStyleSheet("* { background-color: rgb(220,220,220) }");
    ui->pushButton_2->setStyleSheet("* { background-color: rgb(220,20,60) }");
    ui->label_5->setStyleSheet("* { background-color: rgb(220,20,60) }");
    ui->lineEdit->setStyleSheet(QString("QLineEdit {border-width: 2px;"
                                        "  border-style: solid; "
                                        "border-color: rgb(220,20,60)}"));
    ui->textEdit->setStyleSheet(QString("QTextEdit {border-width: 2px;"
                                        "  border-style: solid; "
                                        "border-color: rgb(220,20,60);}"));

    effect = new QGraphicsDropShadowEffect(this);
    effect->setBlurRadius(50);
    effect->setColor(QColor(220,20,60));
    effect->setXOffset(3);
    effect->setYOffset(3);
    effect->setEnabled(true);
    ui->textEdit->setGraphicsEffect(effect);

    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_2_clicked()));

    map["mama"] = 4;
    qDebug()<<"mama"<<map["mama"];
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    QString command = ui->lineEdit->text();
    if(command.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Коммандная строка пуста!");
        return;
    }
    bool is_square = false;
    QString used_function_info = command;
    QRegularExpression re("\\((.*)\\)*");
    QRegularExpressionMatch match = re.match(command);
    QStringList args;
    if(command.contains('[') && command.contains(']'))
    {
        is_square = true;
    }
    else
    {
    for(int i=0;i<args.size();i++) qDebug()<<args[i];
    command = command.section('(',0,-2);
    qDebug()<<command;
    args = match.captured(1).chopped(1).split(",");
    }
    qDebug()<<"im working";

    if(command=="insert")
    {
        if(args.size()==2)
        {
            map.insert(args[0].toStdString(),args[1].toInt());
            ui->textEdit->setText(map.print());
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функции " + used_function_info + " не существует такой перегрузки!");
        return;
        }
    }
    else if(command=="erase")
    {
        if(args.size()==2)
        {
            map.erase(args[0].toStdString(),args[1].toInt());
            ui->textEdit->setText(map.print());
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функции " + used_function_info + " не существует такой перегрузки!");
            return;
        }
    }
    else if(command=="contains")
    {
        if(args.size()==1)
        {
            bool cont = map.contains(args[0].toStdString());
            if(cont)
                ui->textEdit->setText("Такой ключ содержится");
            else
                ui->textEdit->setText("Такой ключ не содержится");
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функции " + used_function_info + " не существует такой перегрузки!");
            return;
        }
    }
    else if(command=="find")
    {
        if(args.size()==2)
        {
            bool found = map.find(args[0].toStdString(),args[1].toInt());
            if(found)
                ui->textEdit->setText("Такая пара найдена");
            else
                ui->textEdit->setText("Такая пара не найдена");
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функции " + used_function_info + " не существует такой перегрузки!");
            return;
        }
    }
    else if(command=="clear")
    {
        if(args.size()==1 && args[0].isEmpty())
        {
           map.clear();
           ui->textEdit->setText("unordered_map была очищена");
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функции " + used_function_info + " не существует такой перегрузки!");
            return;
        }
    }
    else if(command=="size")
    {
        if(args.size()==1 && args[0].isEmpty())
        {
            ui->textEdit->setText("Размер : " + QString::number(map.size()));
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функции " + used_function_info + " не существует такой перегрузки!");
            return;
        }
    }
    else if(command=="load_factor")
    {
        if(args.size()==1 && args[0].isEmpty())
        {
            ui->textEdit->setText("Заполнена на " + QString::number(map.load_factor()) + " %");
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функции " + used_function_info + " не существует такой перегрузки!");
            return;
        }
    }
    else if(command=="empty")
    {
        if(args.size()==1 && args[0].isEmpty())
        {
            bool empty = map.empty();
            if(empty)
                ui->textEdit->setText("unordered_map пуста");
            else
                ui->textEdit->setText("unordered_map не пуста");
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функции " + used_function_info + " не существует такой перегрузки!");
            return;
        }
    }
    else if(command=="print")
    {
        if(args.size()==1 && args[0].isEmpty())
        {
           ui->textEdit->setText(map.print());
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функции " + used_function_info + " не существует такой перегрузки!");
            return;
        }
    }
    else if(is_square)
    {
        std::string index = command.remove('[').remove(']').toStdString();
        qDebug()<<QString::fromStdString(index);
        ui->textEdit->setText(QString::number(map[index]));
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Такой функции не найдено!");
        return;
    }
    QString info;
    QString mapa = "Size : " + QString::number(map.size()) + ", load_factor : " + QString::number(map.load_factor()) + " %";
    info = "Использована функция : " + used_function_info;
    ui->lineEdit->clear();
    ui->statusbar->showMessage(info + ", " + mapa);
}

