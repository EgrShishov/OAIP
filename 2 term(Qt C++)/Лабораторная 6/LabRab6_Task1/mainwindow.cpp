#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(size());
    newDlg = new Dialog();
    newDlg->setModal(true);
    connect(newDlg,SIGNAL(send_data(std::vector<std::pair<int,QString>>)),this,SLOT(recieve_data(std::vector<std::pair<int,QString>>)));

    QStringList funcs;
    funcs<<"insert()"<<"balance()"<<"load_from_array()"<<"search()"<<"delete()"<<"preorder_print()"<<"postorder_print()"<<"print_key()"<<"solve()";
    QCompleter* completer = new QCompleter(funcs,this);
    ui->label_7->setText("Для информации нажмитие Ctrl+I");
    ui->lineEdit->setPlaceholderText("Введите название функции...");
    ui->lineEdit->setFrame(true);
    ui->lineEdit->setToolTip("Доступные функции : insert(int key,QString value), balance(), load_from_array()\nsearch(int key), delete(int key), print_forward(), print_reverse(), print_key(),solve()");
    ui->lineEdit->setCompleter(completer);
    const QIcon passwordIcon("D:/command-line.png");
    ui->lineEdit->addAction(passwordIcon, QLineEdit::LeadingPosition);
    ui->label->setStyleSheet("* { background-color: rgb(220,220,220) }");
    ui->pushButton->setStyleSheet("* { background-color: rgb(60,170,60) }");
    ui->label_5->setStyleSheet("* { background-color: rgb(60,170,60) }");
    ui->lineEdit->setStyleSheet(QString("QLineEdit {border-width: 2px;"
                                        "  border-style: solid; "
                                        "border-color: rgb(60,170,60);}"));
    ui->textEdit->setStyleSheet(QString("QTextEdit {border-width: 2px;"
                                        "  border-style: solid; "
                                        "border-color: rgb(60,170,60);}"));
    ui->treeWidget->setStyleSheet(QString("QTreeWidget {border-width: 2px;"
                                          "  border-style: solid; "
                                          "border-color: rgb(60,170,60);}"));

    effect = new QGraphicsDropShadowEffect();
    effect->setEnabled(false);
    effect->setColor(QColor(60,170,60));
    effect->setBlurRadius(50);
    effect->setXOffset(3);
    effect->setYOffset(3);
    ui->textEdit->setGraphicsEffect(effect);

    effect2 = new QGraphicsDropShadowEffect();
    effect2->setEnabled(false);
    effect2->setColor(QColor(60,170,60));
    effect2->setBlurRadius(50);
    effect2->setXOffset(3);
    effect2->setYOffset(3);
    ui->treeWidget->setGraphicsEffect(effect2);

    timer = new QTimer(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    effect->setEnabled(true);
    effect2->setEnabled(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(set_off()));
    timer->setSingleShot(true);
    timer->start(1000);
//    QPropertyAnimation* anim = new QPropertyAnimation(effect, "blurRadius");
//    anim->setDuration(1000); // 1 second
//    anim->setStartValue(50); // полная непрозрачность
//    anim->setEndValue(0.0); // полная прозрачность
//    anim->start(QAbstractAnimation::DeleteWhenStopped);
//    QPropertyAnimation* anim2 = new QPropertyAnimation(effect2, "blurRadius");
//    anim2->setDuration(1000); // 1 second
//    anim2->setStartValue(50); // полная непрозрачность
//    anim2->setEndValue(0.0); // полная прозрачность
//    anim2->start(QAbstractAnimation::DeleteWhenStopped);


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
            tree.insert(tree.get_root(),args[0].toInt(),args[1]);
            ui->treeWidget->clear();
            tree.preorder_print(tree.get_root(),ui->treeWidget,nullptr);
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }
    }
    else if(command=="balance")
    {
        ui->treeWidget->clear();
        //tree.balance(root);
        tree.postorder_print(tree.get_root(),ui->treeWidget,nullptr);
    }
    else if(command=="load_from_array")
    {
        tree.load_from_array(root,array);
    }
    else if(command=="search")
    {
        if(args.size()==1)
        {
            ui->textEdit->setText("Найденное значение : " + tree.search(tree.get_root(),args[0].toInt())->value);
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }
    }
    else if(command=="delete")
    {
        if(args.size()==1)
        {
            tree.get_root() = tree._delete(tree.get_root(),args[0].toInt());
            ui->treeWidget->clear();
            tree.preorder_print(tree.get_root(),ui->treeWidget,nullptr);
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функци " + command + " не существует такой перегрузки!");
        }
    }
    else if(command=="preorder_print")
    {
        ui->treeWidget->clear();
        tree.preorder_print(tree.get_root(),ui->treeWidget,nullptr);
    }
    else if(command=="postorder_print")
    {
        ui->treeWidget->clear();
        tree.postorder_print(tree.get_root(),ui->treeWidget,nullptr);
    }
    else if(command=="print_key")
    {
        ui->treeWidget->clear();
        tree.key_print(tree.get_root(),ui->treeWidget,nullptr);
    }
    else if(command=="solve")
    {
        solution solve;
        ui->textEdit->setText("Число узлов в дереве, в которых есть указатель только на одну ветвь равно : " + QString::number(solve.solve(root)));
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


void MainWindow::on_pushButton_2_clicked()
{
    effect->setEnabled(true);
    effect2->setEnabled(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(set_off()));
    timer->setSingleShot(true);
    timer->start(1000);
    newDlg->exec();
}

void MainWindow::recieve_data(std::vector<std::pair<int,QString>> mama)
{
    ui->treeWidget->clear();
    qDebug()<<"data recived";
    tree.load_from_array(tree.get_root(),mama);
    tree.preorder_print(tree.get_root(),ui->treeWidget,nullptr);
}

void MainWindow::set_off()
{
    effect->setEnabled(false);
    ui->textEdit->setGraphicsEffect(effect);
    effect2->setEnabled(false);
    ui->treeWidget->setGraphicsEffect(effect2);
}

