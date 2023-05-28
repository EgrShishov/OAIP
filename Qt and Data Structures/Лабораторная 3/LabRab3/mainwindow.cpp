#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QStringList keywords;
    keywords<<"vector<string>" << "vector<double>" << "vector<int>"<<"print()"<<"assign()"<<"at()"<<"back()"<<"begin()"<<"capacity()"<<"cbegin()"<<"clear()"<<"data()"<<
              "emplace()"<<"emplace_back()"<<"empty()"<<"end()"<<"erase()"<<"front()"<<"insert()"<<"max_size()"<<"pop_back()"<<"push_back()"<<
              "rbegin()"<<"rend()"<<"reserve()"<<"resize()"<<"size()"<<"swap()";
    QCompleter* completer = new QCompleter(keywords,this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);

    setFixedSize(526,247);
    ui->setupUi(this);
    ui->label_7->setText("Для информации нажмитие Ctrl+I");
    ui->lineEdit->setPlaceholderText("Введите название функции...");
    ui->lineEdit->setFrame(true);
    ui->lineEdit->setToolTip("Доступные функции : vector<double>, vector<string>, assign,at(int index),back,begin,capacity,cbegin,clear,data,"
                             "\nemplace(T...args,int index),emplace_back(T...args),empty,end,erase(int index)"
                             ",erase(int index, int amount),front,insert(T value,int index),insert(T value,int index, int n),"
                             "max_size,pop_back,push_back(T value),\npop_back,"
                             "rbegin,rend,reserve(int newCapacity),resize(int newSize),size,swap(int index1,int index2)");
    ui->lineEdit->setCompleter(completer);
    const QIcon passwordIcon("D:/command-line.png");
    ui->lineEdit->addAction(passwordIcon, QLineEdit::LeadingPosition);
    ui->label->setStyleSheet("* { background-color: rgb(220,220,220) }");
    //ui->label_3->setStyleSheet("* { background-color: rgb(255,160,0) }");
    ui->pushButton->setStyleSheet("* { background-color: rgb(255,160,0) }");
    ui->label_5->setStyleSheet("* { background-color: rgb(255,160,0) }");
    ui->lineEdit->setStyleSheet(QString("QLineEdit {border-width: 2px;"
                                        "  border-style: solid; "
                                        "border-color: orange;}"));
    ui->textEdit->setStyleSheet(QString("QTextEdit {border-width: 2px;"
                                        "  border-style: solid; "
                                        "border-color: orange;}"));

    keyCtrlI = new QShortcut(this);
    keyCtrlI->setKey(Qt::CTRL + Qt::Key_I);
    connect(keyCtrlI, SIGNAL(activated()), this, SLOT(slotShortcutCtrlI()));

    ui->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    for(int i=0;i<10;i++)
        myVect.push_back(1.3133*(rand()%34));
    for(int i=0;i<10;i++)
        intVect.push_back(rand()%34);
    stringVect.push_back("mama");
    print();
    varType="<double>";
    QString info = "Текущий вектор : vector" + varType +", size : " +QString::number(myVect.size()) + ", " + "capacity : " + QString::number(myVect.capacity());
    ui->statusbar->showMessage(info);
    //ui->statusbar->setStyleSheet("* { background-color: rgb(220,220,220) }");
    Vector<Vector<int>> aboba(6);
    for(int i=0;i<6;i++)
    {
        aboba.push_back(i);
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::checkInput(QString input)
{
    for(int i=0;i<input.size();i++)
    {
        QChar ch = input[i];
        if(ch.isDigit() || ch==' ' || ch=='.' ) {}
        else
        {
            return true;
            break;
        }
    }
    return false;
}


void MainWindow::print()
{
    QString text="";
    for(int i=0;i<myVect.size();i++)
    {
        text+=QString::number(myVect[i])+" ";
    }
    ui->textEdit->setText(text);
}

void MainWindow::Print()
{
    QString text="";
    for(int i=0;i<stringVect.size();i++)
    {
        text+=QString::fromStdString(stringVect[i])+" ";
    }
    ui->textEdit->setText(text);
}

void MainWindow::PrintInt()
{
    QString text="";
    for(int i=0;i<intVect.size();i++)
    {
        text+=QString::number(intVect[i])+" ";
    }
    ui->textEdit->setText(text);
}
void MainWindow::on_pushButton_clicked()
{

//    Vector<Vector<QString>> a(10);

//    for(int i=0;i<10;i++)
//    {
//        if(i%2==0)
//        {
//            a[i].insert("papa",0,6);
//        }
//        else
//        {
//          a[i].insert("mama",0,3);
//        }
//    }

//    a[0].erase(0,3);
//    a[2].erase(0,3);
//    a[4].erase(0,3);
//    for(int i=0;i<a.size();i++)
//       for(int j=0;j<a[i].size();j++)
//           qDebug()<<a[i][j];

//   struct obj
//   {
//       int a;
//       double b;
//       obj(int a,double b) :a(a),b(b){}
//   };

//     Vector<obj> b;
//      b.emplace_back(10,12.2131);
//      b.emplace_back(13,13.23213);
//      b.emplace(0,12,12.2321);
//      b.emplace_back(32,1.d);
//      qDebug()<<QString::number(b.size());
//      qDebug()<<QString::number(b[0].a)<<QString::number(b[0].b);


   //ui->textEdit->clear();
   QString currentFunction1 = ui->lineEdit->text();
   QString currentFunction;
   QString vectorInit = currentFunction1;
   currentFunction=currentFunction1.section('(',0,-2);

   vectorInit = vectorInit.section('<',0,-1);
   qDebug()<<vectorInit;
   qDebug()<<currentFunction;
   int comma=0;

   QString args;
   int index1 = currentFunction1.indexOf("(");
   int index2 = currentFunction1.indexOf(")");
   if(index1!=-1 && index2!=-1)
   {
   for(int i=index1;i<=index2;i++)
   {
       args+=currentFunction1[i];
   }
   qDebug()<<args;
   }

   if(vectorInit.indexOf("<")!=-1 && vectorInit.indexOf(">")!=-1)
   {
       varType.clear();
   for(int i = vectorInit.indexOf("<");i<=vectorInit.indexOf(">");i++)
   {
       varType+=vectorInit[i];
   }
   }

   for(int i=0;i<args.size();i++)
   {
       if(args[i]==',') comma++;
   }
   qDebug()<<QString::number(comma);


   if(currentFunction1.count('<')>0)
   {
       vectorInit = vectorInit.section('<',0,0);
       for(int i=0;i<vectorInit.size();i++)
       {
           if(vectorInit[i]==' ')
               vectorInit.replace(" ", "" );
       }
       qDebug()<<vectorInit;
   }


   if(vectorInit=="vector")
   {
       if(varType=="<double>")
       {
           ui->lineEdit->clear();
           print();
           QString info = "Текущий вектор : vector" + varType +", size : " +QString::number(myVect.size()) + ", " + "capacity : " + QString::number(myVect.capacity());
           ui->statusbar->showMessage(info);
           qDebug()<<"double";
           return;
       }
       if(varType=="<string>")
       {
           ui->lineEdit->clear();
           Print();
           QString info = "Текущий вектор : vector" + varType +", size : " +QString::number(stringVect.size()) + ", " + "capacity : " + QString::number(stringVect.capacity());
           ui->statusbar->showMessage(info);
           qDebug()<<"string";
           return;
       }
       if(varType=="<int>")
       {
           ui->lineEdit->clear();
           PrintInt();
           QString info = "Текущий вектор : vector" + varType +", size : " +QString::number(intVect.size()) + ", " + "capacity : " + QString::number(intVect.capacity());
           ui->statusbar->showMessage(info);
           qDebug()<<"double";
           return;
       }
       else
       {
           QMessageBox::warning(this,"Ошибка","Такой тип данных не доступен или введен не правильно");
       }
       return;
   }

   if(currentFunction1.indexOf("(")!=-1 && currentFunction1.indexOf(")")!=currentFunction1.size()-1)
   {
       QMessageBox::warning(this,"Ошибка","После скобок не должно быть никаких записей");
       return;
   }
   if(currentFunction=="print")
   {
       args.remove(0,1);
       args.remove(args.indexOf(")"),1);
       if(comma!=0 || args.size()!=0)
       {
           QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки."
                                              "\nФункция не принимает аргументов.Возможно вы имели в виду : print()");
           return;
       }
       qDebug()<<varType;
       if(varType=="<double>")
       print();
       else if(varType=="<string>")
       Print();
       else if(varType=="<int>")
       PrintInt();
   }
   else if(currentFunction=="assign")
   {
       args.remove(0,1);
       qDebug()<<"args"<<args;
       if(args[0]==')')
       {
           QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки."
                                              "\nФункция не принимает аргументов.Возможно вы имели в виду : assign("+varType+" value,int amount)");
           return;
       }
       QString data,amount;
       int i = 0;
       for(i;args[i]!=',';i++)
           data+=args[i];
       args.remove(i,1);
       for(i;args[i]!=')';i++)
           amount+=args[i];
       args.remove(args.indexOf(")"),1);



       if(!checkInput(data) && !checkInput(amount))
       {
       if(varType=="<double>")
       {
       myVect.assign(data.toDouble(),amount.toInt());
       print();
       } else if(varType=="<string>")
       {
           stringVect.assign(data.toStdString(),amount.toInt());
           Print();
       } else if(varType=="<int>")
       {
           //qDebug()<<QString::number(data.toInt());
           intVect.assign((int)(data.toDouble()),amount.toInt());
           PrintInt();
       }
       }
       else
       {
           QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки."
                                              "\nФункция не принимает аргументов.Возможно вы имели в виду : assign("+varType+" value,int amount)");
           return;
       }
   }
   else if(currentFunction=="at")
   {
       args.remove(0,1);
       args.remove(args.indexOf(")"),1);


       if(!checkInput(args))
       {
        int index = args.toInt();

        if(varType=="<double>"  && index<myVect.size())
        {
        ui->textEdit->setText(QString::number(myVect.at(args.toInt())));
        }
        else if(varType=="<string>" && index<stringVect.size())
        {
            ui->textEdit->setText(QString::fromStdString(stringVect.at(args.toInt())));
        }
        else if(varType=="<int>" && index<intVect.size())
        {
             ui->textEdit->setText(QString::number(intVect.at(args.toInt())));
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Выход за границы вектора");
            return;
        }

       }
       else
       {
           QMessageBox::warning(this,"Ошибка","Неверное значение в скобках");
           return;
       }
   }
   else if(currentFunction=="back")
   {
       args.remove(0,1);
       args.remove(args.indexOf(")"),1);

       if(comma!=0 || !args.isEmpty())
       {
           QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки."
                                              "\nФункция не принимает аргументов.Возможно вы имели в виду : back()");
           return;
       }
       if(varType=="<double>" && !myVect.empty())
       ui->textEdit->setText(QString::number(myVect.back()));
       else if(varType=="<string>" && !stringVect.empty())
       ui->textEdit->setText(QString::fromStdString(stringVect.back()));
       else if(varType=="<int>" && !intVect.empty())
           ui->textEdit->setText(QString::number(intVect.back()));
       else
       {
           ui->textEdit->setText("Vector is empty");
       }
   }
   else if(currentFunction=="begin")
   {
       args.remove(0,1);
       args.remove(args.indexOf(")"),1);

       if(comma!=0 || !args.isEmpty())
       {
           QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки."
                                              "\nФункция не принимает аргументов.Возможно вы имели в виду : begin()");
           return;
       }
       if(varType=="<double>" && !myVect.empty())
       {
       QString ptrStr = QString( "0x%1" ).arg( reinterpret_cast<quintptr>(&*myVect.begin()),
                           QT_POINTER_SIZE * 2, 16, QChar('0') );
       ui->textEdit->setText(ptrStr);
       }
       else if(varType=="<string>" && !stringVect.empty())
       {
           QString ptrStr = QString( "0x%1" ).arg( reinterpret_cast<quintptr>(&*stringVect.begin()),
                               QT_POINTER_SIZE * 2, 16, QChar('0') );
           ui->textEdit->setText(ptrStr);
       }
       else if(varType=="<int>" && !intVect.empty())
       {
       QString ptrStr = QString( "0x%1" ).arg( reinterpret_cast<quintptr>(&*intVect.begin()),
                           QT_POINTER_SIZE * 2, 16, QChar('0') );
       ui->textEdit->setText(ptrStr);
       }
       else
       {
            ui->textEdit->setText("Vector is empty");
       }
   }
   else if(currentFunction=="capacity")
   {
       args.remove(0,1);
       args.remove(args.indexOf(")"),1);

       if(comma!=0 || !args.isEmpty())
       {
           QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки."
                                              "\nФункция не принимает аргументов.Возможно вы имели в виду : capacity()");
           return;
       }
       if(varType=="<double>")
       ui->textEdit->setText(QString::number(myVect.capacity()));
       else if(varType=="<string>")
       ui->textEdit->setText(QString::number(stringVect.capacity()));
       else if(varType=="<int>")
       ui->textEdit->setText(QString::number(intVect.capacity()));
   }
   else if(currentFunction=="cbegin")
   {
       args.remove(0,1);
       args.remove(args.indexOf(")"),1);

       if(comma!=0 || !args.isEmpty())
       {
           QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки."
                                              "\nФункция не принимает аргументов.Возможно вы имели в виду : cbegin()");
           return;
       }

       qDebug()<<"werwer";
       if(varType=="<double>" && !myVect.empty())
       {
       QString ptrStr = QString( "0x%1" ).arg( reinterpret_cast<quintptr>(&*myVect.cbegin()),
                           QT_POINTER_SIZE * 2, 16, QChar('0') );
       ui->textEdit->setText(ptrStr);
       }
       else if(varType=="<string>" && !stringVect.empty())
       {
           QString ptrStr = QString( "0x%1" ).arg( reinterpret_cast<quintptr>(&*stringVect.cbegin()),
                               QT_POINTER_SIZE * 2, 16, QChar('0') );
           ui->textEdit->setText(ptrStr);
       }
       else if(varType=="<int>" && !intVect.empty())
       {
       QString ptrStr = QString( "0x%1" ).arg( reinterpret_cast<quintptr>(&*intVect.cbegin()),
                           QT_POINTER_SIZE * 2, 16, QChar('0') );
       ui->textEdit->setText(ptrStr);
       }
       else
       {
           ui->textEdit->setText("Vector is empty");
       }
   }
   else if(currentFunction=="clear")
   {
       args.remove(0,1);
       args.remove(args.indexOf(")"),1);

       if(comma!=0 || !args.isEmpty())
       {
           QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки."
                                              "\nФункция не принимает аргументов.Возможно вы имели в виду : clear()");
           return;
       }
       if(varType=="<double>")
       {
       myVect.clear();
       ui->textEdit->clear();
       ui->textEdit->setText(QString::number(myVect.size()));
       print();
       }
       else if(varType=="<string>")
       {
           stringVect.clear();
           ui->textEdit->clear();
           ui->textEdit->setText(QString::number(stringVect.size()));
           Print();
       }
       else if(varType=="<int>")
       {
       intVect.clear();
       ui->textEdit->clear();
       ui->textEdit->setText(QString::number(intVect.size()));
       PrintInt();
       }
   }
   else if(currentFunction=="data")
   {
       args.remove(0,1);
       args.remove(args.indexOf(")"),1);

       if(comma!=0 || !args.isEmpty())
       {
           QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки."
                                              "\nФункция не принимает аргументов.Возможно вы имели в виду : data()");
           return;
       }
       if(varType=="<double>" &&!myVect.empty())
       {
       QString ptrStr = QString( "0x%1" ).arg( reinterpret_cast<quintptr>(myVect.data()),
                           QT_POINTER_SIZE * 2, 16, QChar('0') );
       ui->textEdit->setText(ptrStr);
       }
       else if (varType=="<string>" && !stringVect.empty())
       {
           QString ptrStr = QString( "0x%1" ).arg( reinterpret_cast<quintptr>(stringVect.data()),
                               QT_POINTER_SIZE * 2, 16, QChar('0') );
           ui->textEdit->setText(ptrStr);
       }
       else if(varType=="<int>" && !intVect.empty())
       {
       QString ptrStr = QString( "0x%1" ).arg( reinterpret_cast<quintptr>(intVect.data()),
                           QT_POINTER_SIZE * 2, 16, QChar('0') );
       ui->textEdit->setText(ptrStr);
       }
       else
       {
            ui->textEdit->setText("Vector is empty");
       }
   }
   else if(currentFunction=="emplace")
   {
       args.remove(0,1);

       QString index,data;

       int i=0;
       for(i;args[i]!=',';i++)
           index+=args[i];
       args.remove(i,1);
       for(i;args[i]!=')';i++)
           data+=args[i];
       args.remove(args.indexOf(")"),1);
       qDebug()<<data<<" "<<index;

       if(varType=="<double>")
       {
           if(!checkInput(index))
           {
               myVect.emplace(index.toInt(),data.toDouble());
               print();
           }
           else
           {
               QMessageBox::warning(this,"Ошибка","Неверное значение в скобках");
               return;
           }
       }
       else if (varType=="<string>")
       {
           if(!checkInput(index))
           {
           stringVect.emplace(index.toInt(),data.toStdString());
           Print();
           }
           else
           {
               QMessageBox::warning(this,"Ошибка","Неверное значение в скобках");
               return;
           }
       }
       else if(varType=="<int>")
       {
           if(!checkInput(index))
           {
               intVect.emplace(index.toInt(),int(data.toDouble()));
               PrintInt();
           }
           else
           {
               QMessageBox::warning(this,"Ошибка","Неверное значение в скобках");
               return;
           }
       }
   }
   else if(currentFunction=="emplace_back")
   {
       args.remove(0,1);
       args.remove(args.indexOf(")"),1);
       if(varType=="<double>")
       {
       myVect.emplace_back(args.toDouble());
       print();
       }
       else if(varType == "<string>")
       {
           qDebug()<<args;
           stringVect.emplace_back(args.toStdString());
           Print();
       }
       else if(varType=="<int>")
       {
       intVect.emplace_back(int(args.toDouble()));
       PrintInt();
       }
   }
   else if(currentFunction=="empty")
   {
       args.remove(0,1);
       args.remove(args.indexOf(")"),1);

       if(comma!=0 || !args.isEmpty())
       {
           QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки."
                                              "\nФункция не принимает аргументов.Возможно вы имели в виду : empty()");
           return;
       }

       if(varType=="<double>")
       {
       bool ans = myVect.empty();
       if(ans)
           ui->textEdit->setText("Empty");
       else
           ui->textEdit->setText("Not empty");
       }
       else if(varType=="<string>")
       {
           bool ans = stringVect.empty();
           if(ans)
               ui->textEdit->setText("Empty");
           else
               ui->textEdit->setText("Not empty");
       }
       else if(varType=="<int>")
       {
       bool ans = intVect.empty();
       if(ans)
           ui->textEdit->setText("Empty");
       else
           ui->textEdit->setText("Not empty");
       }
   }
   else if(currentFunction=="end")
   {
       args.remove(0,1);
       args.remove(args.indexOf(")"),1);

       if(comma!=0 || !args.isEmpty())
       {
           QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки."
                                              "\nФункция не принимает аргументов.Возможно вы имели в виду : end()");
           return;
       }
       if(varType=="<double>" && !myVect.empty())
       {
       QString ptrStr = QString( "0x%1" ).arg( reinterpret_cast<quintptr>(&*myVect.end()),
                           QT_POINTER_SIZE * 2, 16, QChar('0') );
       ui->textEdit->setText(ptrStr);
       }
       else if(varType=="<string>" && !stringVect.empty())
       {
           QString ptrStr = QString( "0x%1" ).arg( reinterpret_cast<quintptr>(&*stringVect.end()),
                               QT_POINTER_SIZE * 2, 16, QChar('0') );
           ui->textEdit->setText(ptrStr);
       }
       else if(varType=="<int>" && !intVect.empty())
       {
       QString ptrStr = QString( "0x%1" ).arg( reinterpret_cast<quintptr>(&*intVect.end()),
                           QT_POINTER_SIZE * 2, 16, QChar('0') );
       ui->textEdit->setText(ptrStr);
       }
       else
       {
            ui->textEdit->setText("Vector is empty");
       }
   }
   else if(currentFunction=="erase")
   {
       args.remove(0,1);
       args.remove(args.indexOf(")"),1);
       if(comma>1 || comma<0 || args.isEmpty())
       {
           QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки."
                                              "\nВозможно вы имели в виду : erase(int index),\nerase(int index,int n)");
           return;
       }

       if(comma==0)
       {
       if(!checkInput(args))
       {
           if(varType=="<double>" && !myVect.empty() && args.toInt()<myVect.size())
           {
           myVect.erase(args.toInt());
           print();
           }
           else if(varType=="<string>" && !stringVect.empty() && args.toInt()<stringVect.size())
           {
           stringVect.erase(args.toInt());
           Print();
           }
           else if(varType=="<int>" && !intVect.empty() && args.toInt()<intVect.size())
           {
           intVect.erase(args.toInt());
           PrintInt();
           }
           else
           {
               QMessageBox::warning(this,"Ошибка","Выход за границы или вектор пуст");
               return;
           }

       }
           else
       {
           QMessageBox::warning(this,"Ошибка","Неверное значение в скобках");
           return;
       }

       }
       else if(comma==1)
       {
               QString _args = args.section(',',0,-2);
               qDebug()<<"args"<<_args;
               QString args2 = args.section(',',1,1);
               qDebug()<<"args2"<<args2;



               if(!checkInput(_args) && !checkInput(args2))
               {
               if(varType=="<double>")
               {
                  if(_args.toInt()<myVect.size() && args2.toInt()<myVect.size()){
               myVect.erase(_args.toInt(),args2.toInt());
               print();
                   }
                   else
                  {
                    QMessageBox::warning(this,"Ошибка","Индекс выходит за границы вектора");
                    return;
                  }
               }
               else if(varType=="<string>")
               {
                   if(_args.toInt()<stringVect.size() && args2.toInt()<stringVect.size())
                   {
               stringVect.erase(_args.toInt(),args2.toInt());
               Print();
                   }
                   else
                   {
                       QMessageBox::warning(this,"Ошибка","Индекс выходит за границы вектора");
                       return;
                   }
               }
               else if(!checkInput(_args) && !checkInput(args2))
               {
               if(varType=="<int>")
               {
                   if(_args.toInt()<intVect.size() && args2.toInt()<intVect.size())
                   {
               intVect.erase(_args.toInt(),args2.toInt());
               PrintInt();
                   }
                   else
                   {
                       QMessageBox::warning(this,"Ошибка","Индекс выходит за границы вектора");
                       return;
                   }
               }
               }

               }
               else
               {
                   QMessageBox::warning(this,"Ошибка","Неверное значение в скобках");
                   return;
               }
   }
   }
   else if(currentFunction=="front")
   {
       args.remove(0,1);
       args.remove(args.indexOf(")"),1);

       if(comma!=0 || !args.isEmpty())
       {
           QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки."
                                              "\nФункция не принимает аргументов.Возможно вы имели в виду : front()");
           return;
       }
       if(varType=="<double>" && !myVect.empty())
       ui->textEdit->setText(QString::number(myVect.front()));
       else if(varType=="<string>" && !stringVect.empty())
       ui->textEdit->setText(QString::fromStdString(stringVect.front()));
       else if(varType=="<int>" && !intVect.empty())
       ui->textEdit->setText(QString::number(intVect.front()));
       else
            ui->textEdit->setText("Vector is empty");
   }
   else if(currentFunction=="insert")
   {
       args.remove(0,1);
       //args.remove(args.indexOf(")"),1);
       QString _index,_data,_end;

       if(comma<1 || comma>2)
       {
           QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки."
                                              "\nВозможно вы имели в виду : insert("+varType+" value,int index),\ninsert("+varType+" value,int begin, int end)");
           return;
       }


       if(comma==1)
       {
           int i=0;
           for(i;args[i]!=',';i++)
               _data+=args[i];
           args.remove(i,1);
           for(i;args[i]!=')';i++)
               _index+=args[i];
           args.remove(args.indexOf(")"),1);
           qDebug()<<args;
           qDebug()<<i;
           qDebug()<<_data<<" "<<_index;
       }
       else if(comma==2)
       {
           int i=0;
           for(i;i!=args.indexOf(',');i++)
               _data+=args[i];
           args.remove(i,1);

           for(i;args[i]!=',';i++)
               _index+=args[i];
           args.remove(i,1);

           for(i;args[i]!=')';i++)
               _end+=args[i];

           args.remove(args.indexOf(")"),1);
           qDebug()<<args;
           qDebug()<<i;
           qDebug()<<_data<<" "<<_index<<_end;
       }

       if(_index.toInt()<0 || _index.toInt()>myVect.size())
       {
           QMessageBox::warning(this,"Ошибка","Индекс выходит за границы вектора");
           return;
       }

       qDebug()<<"comma"<<QString::number(comma);
       if(varType=="<double>")
       {

        if(comma==1)
        {
       if(!checkInput(_index)&& !checkInput(_data))
       {
       int index = _index.toInt();
       double data = _data.toDouble();
       if(index>myVect.size())
       {
           QMessageBox::warning(this,"Ошибка","Выход за границы вектора");
           return;
       }
       myVect.insert(data,index);
       print();
       }
       else
       {
           QMessageBox::warning(this,"Ошибка","Неверное значение в скобках");
           return;
       }

       }
        else if(comma==2)
        {
            if(!checkInput(_index) && !checkInput(_data) && !checkInput(_end))
            {
                int index = _index.toInt();
                int end = _end.toInt();
                double data = _data.toDouble();
                qDebug()<<QString::number(index)<<QString::number(data)<<QString::number(end);
                myVect.insert(data,index,end);
                print();
            }
            else
            {
                QMessageBox::warning(this,"Ошибка","Неверное значение в скобках");
                return;
            }
        }
       }
       else if(varType=="<string>")
       {

           if(comma==1)
           {
       if(!checkInput(_index))
       {
           if(_index.toInt()>stringVect.size())
           {
               QMessageBox::warning(this,"Ошибка","Выход за границы вектора");
               return;
           }
            stringVect.insert((_data).toStdString(),_index.toInt());
            Print();
       }
       else
       {
           QMessageBox::warning(this,"Ошибка","Неверное значение в скобках");
           return;
       }
           }
           else if(comma==2)
           {
               if(!checkInput(_index)&&!checkInput(_end))
               {
                   stringVect.insert((_data).toStdString(),_index.toInt(),_end.toInt());
                   Print();
               }
               else
               {
                   QMessageBox::warning(this,"Ошибка","Неверное значение в скобках");
                   return;
               }
           }
       }
       else if(varType=="<int>")
       {

        if(comma==1)
        {
       if(!checkInput(_index)&& !checkInput(_data))
       {
       int index = _index.toInt();
       double data = _data.toDouble();
       if(index>intVect.size())
       {
           QMessageBox::warning(this,"Ошибка","Выход за границы вектора");
           return;
       }
       intVect.insert(int(data),index);
       PrintInt();
       }
       else
       {
           QMessageBox::warning(this,"Ошибка","Неверное значение в скобках");
           return;
       }

       }
        else if(comma==2)
        {
            if(!checkInput(_index) && !checkInput(_data) && !checkInput(_end))
            {
                int index = _index.toInt();
                int end = _end.toInt();
                double data = _data.toDouble();
                qDebug()<<QString::number(index)<<QString::number(data)<<QString::number(end);
                intVect.insert(int(data),index,end);
                PrintInt();
            }
            else
            {
                QMessageBox::warning(this,"Ошибка","Неверное значение в скобках");
                return;
            }
        }
       }
   }
   else if(currentFunction=="max_size")
   {
       args.remove(0,1);
       args.remove(args.indexOf(")"),1);
       if(!args.isEmpty() || comma!=0)
       {
           QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки."
                                              "\nФункция не принимает аргументов. Возиожно вы имели в виду : max_size()");
           return;
       }
       ui->textEdit->setText(QString::number(myVect.max_size()));
   }
   else if(currentFunction=="pop_back")
   {
       args.remove(args.indexOf(")"),1);
       args.remove(args.indexOf("("),1);
       if(comma!=0 || !args.isEmpty())
       {
           QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки."
                                              "\nФункция не принимает аргументов. Возиожно вы имели в виду : pop_back()");
           return;
       }

       if(varType=="<double>" && myVect.size()>0)
       {
       myVect.pop_back();
       print();
       }
       else if(varType=="<string>" && stringVect.size()>0)
       {
           stringVect.pop_back();
           Print();
       }
       else if(varType=="<int>" && intVect.size()>0)
       {
       intVect.pop_back();
       PrintInt();
       }
       else
       {
           QMessageBox::warning(this,"Ошибка","Индекс выходит за границы вектора");
       }
   }
   else if(currentFunction=="push_back")
   {
       args.remove(0,1);
       args.remove(args.indexOf(")"),1);

       if(comma!=0 || args.isEmpty())
       {
           QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки."
                                              "\nВозможно вы имели в виду : push_back("+varType+" value)");
           return;
       }

       if(varType=="<double>")
       {
       if(!checkInput(args))
       {
       myVect.push_back(args.toDouble());
       print();
       }
       else
       {
           QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки."
                                              "\nВозможно вы имели в виду : push_back("+varType+" value)");
           return;
       }
       }
       else if (varType=="<string>")
       {
           stringVect.push_back(args.toStdString());
           Print();
       }
       else if(varType=="<int>")
       {
       if(!checkInput(args))
       {
       intVect.push_back((int)args.toDouble());
       PrintInt();
       }
       else
       {
           QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки."
                                              "\nВозможно вы имели в виду : push_back("+varType+" value)");
           return;
       }
       }
   }
   else if(currentFunction=="rbegin")
   {
       args.remove(0,1);
       args.remove(args.indexOf(")"),1);

       if(comma!=0 || !args.isEmpty())
       {
           QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки."
                                              "\nФункция не принимает аргументов, возиожно вы имели в виду : rbegin()");
           return;
       }
       if(varType=="<double>" && !myVect.empty())
       {
       QString ptrStr = QString( "0x%1" ).arg( reinterpret_cast<quintptr>(&*myVect.rbegin()),
                           QT_POINTER_SIZE * 2, 16, QChar('0') );
       ui->textEdit->setText(ptrStr);
       }
       else if(varType=="<string>" && !stringVect.empty())
       {
           QString ptrStr = QString( "0x%1" ).arg( reinterpret_cast<quintptr>(&*stringVect.rbegin()),
                               QT_POINTER_SIZE * 2, 16, QChar('0') );
           ui->textEdit->setText(ptrStr);
       }
       else if(varType=="<int>" && !intVect.empty())
       {
       QString ptrStr = QString( "0x%1" ).arg( reinterpret_cast<quintptr>(&*intVect.rbegin()),
                           QT_POINTER_SIZE * 2, 16, QChar('0') );
       ui->textEdit->setText(ptrStr);
       }
       else
            ui->textEdit->setText("Vector is empty");
   }
   else if(currentFunction=="rend")
   {
       args.remove(0,1);
       args.remove(args.indexOf(")"),1);

       if(comma!=0 || !args.isEmpty())
       {
           QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки."
                                              "\nФункция не принимает аргументов, возиожно вы имели в виду : rend()");
           return;
       }
       if(varType=="<double>" && !myVect.empty())
       {
       QString ptrStr = QString( "0x%1" ).arg( reinterpret_cast<quintptr>(&*myVect.rend()),
                           QT_POINTER_SIZE * 2, 16, QChar('0') );
       ui->textEdit->setText(ptrStr);
       }
       else if(varType=="<string>" && !stringVect.empty())
       {
           QString ptrStr = QString( "0x%1" ).arg( reinterpret_cast<quintptr>(&*stringVect.rend()),
                               QT_POINTER_SIZE * 2, 16, QChar('0') );
           ui->textEdit->setText(ptrStr);
       }
       else if(varType=="<int>" && !intVect.empty())
       {
       QString ptrStr = QString( "0x%1" ).arg( reinterpret_cast<quintptr>(&*intVect.rend()),
                           QT_POINTER_SIZE * 2, 16, QChar('0') );
       ui->textEdit->setText(ptrStr);
       }
       else  ui->textEdit->setText("Vector is empty");
   }
   else if(currentFunction=="reserve")
   {
       args.remove(0,1);
       args.remove(args.indexOf(")"),1);

       if(args.isEmpty() || comma!=0)
       {
           QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки. reserve(int newCapacity)");
           return;
       }

       if(!checkInput(args))
       {
           if(args.size()>5)
           {
               QMessageBox::warning(this,"Ошибка","Моей оперативной памяти не хватит!");
               return;
           }
       if(varType=="<double>")
       myVect.reserve(args.toInt());
       else if(varType=="<string>")
       {
           stringVect.reserve(args.toInt());
       }
       else if(varType=="<int>")
           intVect.reserve(args.toInt());
       else
       {
            QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки. reserve(int newCapacity)");
           return;
       }
       }
   }
   else if(currentFunction=="resize")
   {
       args.remove(0,1);
       args.remove(args.indexOf(")"),1);

       if(args.size()>5 && !checkInput(args))
       {
           QMessageBox::warning(this,"Ошибка","Моей оперативной памяти не хватит!");
           return;
       }

       if(checkInput(args))
       {
           QMessageBox::warning(this,"Ошибка","Неверное значение в скобках");
           return;
       }
       if(varType=="<double>")
       {
       myVect.resize(args.toInt());
       print();
       }
       else if(varType=="<string>")
       {
       stringVect.resize(args.toInt());
       Print();
       }
       else if(varType=="<int>")
       {
       intVect.resize(args.toInt());
       PrintInt();
       }
   }
   else if(currentFunction=="size")
   {
       args.remove(0,1);
       args.remove(args.indexOf(")"),1);
       if(!args.isEmpty() || comma!=0)
       {
            QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки.\nФункция не принимает аргументов, возможно вы иммели в виду : size()");
           return;
       }
       if(varType=="<double>")
       {
       ui->textEdit->setText(QString::number(myVect.size()));
       QString info = "size : " +QString::number(myVect.size()) + ", " + "capacity : " + QString::number(myVect.capacity());
       ui->statusbar->showMessage(info);
       }
       else if(varType=="<string>")
       {
           ui->textEdit->setText(QString::number(stringVect.size()));
           QString info = "size : " +QString::number(stringVect.size()) + ", " + "capacity : " + QString::number(stringVect.capacity());
           ui->statusbar->showMessage(info);
       }
       else if(varType=="<int>")
       {
       ui->textEdit->setText(QString::number(intVect.size()));
       QString info = "size : " +QString::number(intVect.size()) + ", " + "capacity : " + QString::number(intVect.capacity());
       ui->statusbar->showMessage(info);
       }
   }
   else if(currentFunction=="swap")
   {
       args.remove(0,1);

       QString _index,_index2;
       int i=0;
       for(i;args[i]!=',';i++)
           _index+=args[i];
       args.remove(i,1);
       for(i;args[i]!=')';i++)
           _index2+=args[i];
       args.remove(args.indexOf(")"),1);

       if(comma!=1 || args.isEmpty())
       {
           QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки. swap(int index1,int index2)");
           return;
       }


       if(!checkInput(_index) && !checkInput(_index2))
       {
       qDebug()<<_index<<_index2;
       if(varType=="<double>")
       {
           if(_index.toInt()<0 || _index.toInt()>=myVect.size() || _index2.toInt()<0 || _index2.toInt()>=myVect.size())
           {
               QMessageBox::warning(this,"Ошибка","Выход за границы вектора");
               return;
           }
       myVect.swap(_index.toInt(),_index2.toInt());
       print();
       }
       else if(varType=="<string>")
       {
           if(_index.toInt()<0 || _index.toInt()>=stringVect.size() || _index2.toInt()<0 || _index2.toInt()>=stringVect.size())
           {
               QMessageBox::warning(this,"Ошибка","Выход за границы вектора");
               return;
           }
           stringVect.swap(_index.toInt(),_index2.toInt());
           Print();
       }
       else if(varType=="<int>")
       {
           if(_index.toInt()<0 || _index.toInt()>=intVect.size() || _index2.toInt()<0 || _index2.toInt()>=intVect.size())
           {
               QMessageBox::warning(this,"Ошибка","Выход за границы вектора");
               return;
           }
       intVect.swap(_index.toInt(),_index2.toInt());
       print();
       }
       } else
       {
            QMessageBox::warning(this,"Ошибка","Для данной функции не существует такой перегрузки. swap(int index1,int index2)");
           return;
       }
   }
   else
   {
       QMessageBox::warning(this,"Ошибка","Функция не найдена!\nНаведитесь на поле для ввода и ознакомтесь с доступными функциями");
       return;
   }
   if(varType=="<double>")
   {
   QString info = "Текущий вектор : vector" + varType +", size : " +QString::number(myVect.size()) + ", " + "capacity : " + QString::number(myVect.capacity());
   ui->statusbar->showMessage(info);
   }
   else if(varType=="<string>")
   {
   QString info = "Текущий вектор : vector" + varType +", size : " +QString::number(stringVect.size()) + ", " + "capacity : " + QString::number(stringVect.capacity());
   ui->statusbar->showMessage(info);
   }
   else if(varType=="<int>")
   {
   QString info = "Текущий вектор : vector" + varType +", size : " +QString::number(intVect.size()) + ", " + "capacity : " + QString::number(intVect.capacity());
   ui->statusbar->showMessage(info);
   }
   QString infoLabel = "Использована функция " + currentFunction1;
   ui->label_2->setText(infoLabel);
   ui->lineEdit->clear();
}


void MainWindow::slotShortcutCtrlI()
{
    dlg = new Dialog();
    dlg->setWindowTitle("Information about myVector fuctions");
    dlg->show();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QApplication::quit();
}

void MainWindow::on_pushButton_2_clicked()
{

}

