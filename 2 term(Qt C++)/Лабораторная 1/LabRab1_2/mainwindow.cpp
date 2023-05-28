#include "mainwindow.h"
#include "ui_mainwindow.h"


QString filename1="";
QString filename2="";
Library* database=NULL;
Reader* ourLibrary=NULL;
Dolg* listOfBooks=NULL;
int choice=0,choice1=0;
int choice2=0,choice3=0;
int N=0,K=0,M=0,D=0;
int _id;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    window()->setFixedSize(851,419);
    //qDebug()<<window()->size();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool checkingBooksFile(QString filename,int key)
{
    bool error=false;
    int commaCount=0;

    QFile file(filename);
    file.open(QIODevice::ReadOnly|QIODevice::Text);

    QTextStream text(&file);
    QChar ch;

    switch(key){

    case 0:
    {
//    while(!text.atEnd())
//    {
//        text>>ch;
//        if(ch==',') commaCount++;
//    }
//    commaCount=0;
//    qDebug()<<commaCount<<" ";
//    if(commaCount%4!=0)
//    {
//        error = true;
//    }

//    file.seek(0);

        while(!text.atEnd())
        {
            QChar ch;
            QString tmp = text.readLine();
            commaCount=0;

            for(int i=0;i<tmp.size();i++)
            {
                ch=tmp[i];
                if(ch==',') commaCount++;

            }
            if(commaCount!=4)
            {
                error=true;
                break;
            }
            if(error)
            {
                break;
                return error;
            }
            qDebug()<<tmp<<" "<<commaCount;
        }
        qDebug()<<error;
//    while(!text.atEnd())
//    {
//        commaCount=0;
//        QString tmp=text.readLine();
//        for(int i=0;i<tmp.size();i++)
//        {
//            if(tmp[i]==',')
//             commaCount++;

//            if(commaCount>4)
//            {
//                error=true;
//                break;
//            }
//        }
//        if(error) break;
//    }

    //qDebug()<<commaCount;
    file.seek(0);

    while(!text.atEnd())
    {
        QString tmpInfo=text.readLine();
        if(!tmpInfo.isEmpty() && commaCount==0)
        {
            return true;
        }
        QString id,year;
        QChar tmp;
        int i=0;
        id = tmpInfo.section(',',0,-5);
        int size1=id.size();
        while(size1--)
        {
            tmp=id[i];
            if(!tmp.isDigit())
            {
                error = true;
                break;
            }
            i++;
        }

        year=tmpInfo.section(',',3,3);
        i=0;
        int size2=year.size();
        while(size2--)
        {
            tmp=year[i];
            if(!tmp.isDigit())
            {
                error = true;
                break;
            }
            i++;
        }
    }
        break;
}

case 1:
{

commaCount=0;
//while(!text.atEnd())
//{
//    text>>ch;
//    if(ch==',') commaCount++;
//}
//qDebug()<<commaCount<<" ";
//if(commaCount%3!=0) error = true;

while(!text.atEnd())
{
    QChar ch;
    QString tmp = text.readLine();
    qDebug()<<tmp;
    commaCount=0;

    for(int i=0;i<tmp.size();i++)
    {
        ch=tmp[i];
        if(ch==',') commaCount++;

    }
    if(commaCount!=3)
    {
        error=true;
        break;
    }
    if(error)
    {
        break;
        return error;
    }
    qDebug()<<tmp<<" "<<commaCount;
}
qDebug()<<error;

file.seek(0);

while(!text.atEnd())
{
    QString tmpInfo=text.readLine();
    if(!tmpInfo.isEmpty() && commaCount==0 || error)
    {
        return true;
    }
    QString id,phonenumber;
    QChar tmp;
    int i=0;
    id = tmpInfo.section(',',0,-4);
    qDebug()<<id;
    int size=id.size();
    while(size--)
    {
        tmp=id[i];
        if(!tmp.isDigit())
        {
            error = true;
            break;
        }
        i++;
    }

    phonenumber=tmpInfo.section(',',3,3);
    qDebug()<<phonenumber;
    i=1;
    size=phonenumber.size()-1;
    while(size--)
    {
        tmp=phonenumber[i];
        if(!tmp.isDigit())
        {
            error = true;
            break;
        }
        i++;
    }
}

break;
}

}
    file.close();
    qDebug()<<error;
    return error;
}

bool checkingReaderFile(QString filename)
{
    bool error=false;
    int commaCount=0;

    QFile file(filename);
    file.open(QIODevice::ReadOnly|QIODevice::Text);

    QTextStream text(&file);
    QChar ch;

    while(!text.atEnd())
    {
        text>>ch;
        if(ch==',') commaCount++;
    }
    //qDebug()<<commaCount<<" ";
    if(commaCount%3!=0) error = true;

    file.seek(0);

    while(!text.atEnd())
    {
        QString tmpInfo=text.readLine();
        QString id,phonenumber;
        QChar tmp;
        int i=0;
        id = tmpInfo.section(',',0,-4);
        int size=id.size();
        while(size--)
        {
            tmp=id[i];
            if(!tmp.isDigit())
            {
                error = true;
                break;
            }
            i++;
        }

        phonenumber=tmpInfo.section(',',3,3);
        i=1;
        size=phonenumber.size()-1;
        while(size--)
        {
            tmp=phonenumber[i];
            if(!tmp.isDigit())
            {
                error = true;
                break;
            }
            i++;
        }
    }

    file.close();
    return error;
}



void MainWindow::on_action_triggered() //окна открытия файлов
{
    filename1 = QFileDialog::getOpenFileName(this,tr("Откройте файл с книгами"),"D://","Text File (*.txt)");
    //filename2 = QFileDialog::getOpenFileName(this,tr("Откройте файл с читателями"),"D://","Text File (*.txt)");
    if(checkingBooksFile(filename1,0)==false && !filename1.isEmpty())
    {
    database=database->load_from_file(filename1);
    QMessageBox::information(this,("Успешно!"),("Теперь вы можете просмотреть сожержимое файла по кнопке 'Просмотр содержимого файла(книги)'"));
    //ourLibrary=ourLibrary->load_from_file(filename2);
    }
    else
    {
        filename1="";
        qDebug()<<filename1;
        QMessageBox::critical(this,tr("Ошибка открытия файлов"),tr("Проверьте файл на корректность записи данных"));
    }
}


void MainWindow::on_pushButton_clicked() //открытие окна с книгами
{
    if(checkingBooksFile(filename1,0))
        filename1="";
    if(!filename1.isEmpty())
    {
    secondwindow window;
    window.setModal(true);
    window.exec();
    }
    else
    {
        QMessageBox::critical(this,tr("Ошибка"),tr("Файл не открыт"));
    }
}


void MainWindow::on_pushButton_2_clicked() //открытие окна с читателями
{
    if(checkingBooksFile(filename2,1))
        filename2="";
    if(!filename2.isEmpty())
    {
    thirdwindow window;
    window.setModal(true);
    window.exec();
    }
    else
    {
        QMessageBox::critical(this,tr("Ошибка"),tr("Файл не открыт"));
    }
}


void MainWindow::on_action_2_triggered() //выход из приложения
{
    QApplication::quit();
}


void MainWindow::on_pushButton_3_clicked()
{
    qDebug()<<filename2;
    qDebug()<<filename1;
    if(checkingBooksFile(filename1,0))
        filename1="";
    if(!filename1.isEmpty())
    {
     database->sort_info(database,choice1);
     ui->listWidget->clear();
     qDebug()<<N;
     for(int i=0;i<N;i++)
     {
         QString field;
         QListWidgetItem* item=new QListWidgetItem();
         field=QString::number(database[i].get_id())+","+database[i].get_surname()+","+database[i].get_bookname()+","+database[i].get_language()+","+QString::number(database[i].get_year());
         item->setText(field);
         ui->listWidget->addItem(item);
     }

     ui->statusbar->showMessage("Данные отсортированы!");
    }
    else
    {
        ui->listWidget->clear();
        QMessageBox::warning(this,tr("Error"),tr("Файл не открыт"));
        return;
    }
}


void MainWindow::on_comboBox_activated(int index) //индекс выбора
{
  choice=index;
}


void MainWindow::on_pushButton_4_clicked() //поиск доработать
{
    QString key=ui->lineEdit->text();
    int count=0;

    if(checkingBooksFile(filename2,1))
        filename2="";
    qDebug()<<filename1;
    qDebug()<<filename2;
    if((filename1.isEmpty()) && (choice==0 || choice==1))
    {
        QMessageBox::critical(this,tr("Ошибка"),tr("Откройте файл с книгами"));
        return;
    } else if (key.isEmpty())
    {
        QMessageBox::critical(this,("Ошибка"),("Заполните поле"));
        return;
    }

    if((filename2.isEmpty() || key.isEmpty() )&& choice==2)
    {
        QMessageBox::critical(this,tr("Ошибка"),tr("Откройте файл с читателями"));
        return;
    }

    ui->listWidget->clear();
  if(choice==0)
  {
    for(int i=0;i<N;i++)
    {
        if(database[i].get_surname()==key)
        {
            QString surname,language,bookname,ryear,rid;
            short year,id;

            surname=database[i].get_surname();
            language=database[i].get_language();
            bookname=database[i].get_bookname();

            year=database[i].get_year();
            ryear=QString::number(year);

            id=database[i].get_id();
            rid=QString::number(id);

            QListWidgetItem* item=new QListWidgetItem();
            item->setText(rid+","+surname+","+bookname+","+language+","+ryear+","+rid);
            ui->listWidget->addItem(item);

            QMessageBox::information(this,("info"),rid+","+surname+","+bookname+","+language+","+ryear+","+rid);
            count++;
        }
    }

  } else if(choice==1)
  {
      for(int i=0;i<N;i++)
      {
          if(database[i].get_bookname()==key)
          {
              QString surname,language,bookname,ryear,rid;
              short year,id;

              surname=database[i].get_surname();
              language=database[i].get_language();
              bookname=database[i].get_bookname();

              year=database[i].get_year();
              ryear=QString::number(year);

              id=database[i].get_id();
              rid=QString::number(id);

              QListWidgetItem* item=new QListWidgetItem();
              item->setText(rid+","+surname+","+bookname+","+language+","+ryear+","+rid);
              ui->listWidget->addItem(item);

              QMessageBox::information(this,("info"),rid+","+surname+","+bookname+","+language+","+ryear+","+rid);
              count++;
          }
      }

  } else if(choice==2)
  {
      for(int i=0;i<K;i++)
      {
          if(ourLibrary[i].get_FIO()==key)
          {
              QListWidgetItem* item = new QListWidgetItem();
              QString adress,phonenumber,FIO;
              short id;
              adress=ourLibrary[i].get_adress();
              FIO=ourLibrary[i].get_FIO();
              phonenumber=ourLibrary[i].get_phonenumber();
              id=ourLibrary[i].get_reader_id();
              QString rid=QString::number(id);

              QString info = rid+","+FIO+"," + adress+","+phonenumber;

              item->setText(info);
              QMessageBox::information(this,"info",rid+","+FIO+"," + adress + "," + phonenumber);
              ui->listWidget->addItem(item);
              count++;
          }

      }
  }

  if(count==0)
  {
      QListWidgetItem* item = new QListWidgetItem();
      item->setText("Не найдено");
      ui->listWidget->addItem(item);
  }
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->statusbar->showMessage("lox");
    QString filename=QFileDialog::getOpenFileName(this,tr("Откройте список"),"D://","Text File (*.txt)");
    listOfBooks=listOfBooks->load_from_file(filename);

    ui->listWidget->clear();

    for(int i=0;i<D;i++)
    {
    QString info = listOfBooks[i].dolgList(ourLibrary);
    QListWidgetItem* item = new QListWidgetItem;
    item->setText(info);
    ui->listWidget->addItem(item);
    }
}

void MainWindow::on_pushButton_7_clicked()
{
   //QString filename=QFileDialog::getOpenFileName(this,tr("Откройте список"),"D://","Text File (*.txt)");
   QString filename="D:\\список третий.txt";
   if(!filename.isEmpty() && !filename1.isEmpty() && !filename2.isEmpty())
   {
   listOfBooks=listOfBooks->load_from_file(filename);

   ui->listWidget->clear();

   for(int i=0;i<D;i++)
   {
   QString info = listOfBooks[i].createList(database);
   QListWidgetItem* item = new QListWidgetItem;
   item->setFlags(Qt::ItemFlag::ItemIsEditable);
   item->setText(info);
   ui->listWidget->addItem(item);
   }
   }
   else
   {
       if(filename1.isEmpty() && filename2.isEmpty())
       {
           QMessageBox::warning(this,"Ошибка","Откройте оба файла");
           return;
       }
       else if(filename1.isEmpty())
       {
       QMessageBox::warning(this,"Ошибка","Откройте файл с читателями");
       return;
       }else if(filename2.isEmpty())
       {
           QMessageBox::warning(this,"Ошибка","Откройте файл с читателями");
           return;
       }

   }
}


void MainWindow::on_comboBox_4_activated(int index)
{
    choice1=index;
}


void MainWindow::on_pushButton_5_clicked() //просмотр списка книг
{
    ui->listWidget->clear();
    if(filename1.isEmpty() && filename2.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка открытия файлов","Файлы не открыты!");
        return;
    }
    if(filename1.isEmpty() && choice2==0)
    {
        QMessageBox::warning(this,"Ошибка открытия файлоы","Файл с книгами не открыт");
        return;
    }
    if(filename2.isEmpty() && choice2==1)
    {
        QMessageBox::warning(this,"Ошибка открытия файлов","Файл с читателями не открыт");
        return;
    }
    QString fname;
    if(choice2==0)
        fname=filename1;
    else if(choice2==1)
        fname=filename2;

    QFile file(fname);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream text(&file);
    QString tmp;
    if(checkingBooksFile(fname,choice2)==false)
    {
    while(!text.atEnd())
    {
        tmp=text.readLine();
        QListWidgetItem* item=new QListWidgetItem();
        item->setText(tmp);
        ui->listWidget->addItem(item);
    }
    }
    else
    {
        QMessageBox::critical(this,tr("Ошибка открытия файлов"),tr("Не могу открыть файл,проверьте его на корректность записи данных"));
    }

}


void MainWindow::on_pushButton_10_clicked()
{
    QListWidgetItem* item = ui->listWidget->currentItem();

    QString key1=ui->listWidget->currentItem()->text();
    QString key=key1.section(",",0,-5);

    for(int i=0;i<N;i++)
    {
        if(database[i].get_id()==key.toShort())
        {
            QMessageBox::information(this,tr("пустота"),database[i].get_bookname());
        }
    }
}


void MainWindow::on_comboBox_5_currentIndexChanged(int index)
{
    choice2=index;
}

void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{
    choice3=index;
}


void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QString test=ui->lineEdit->text();
    if(test.isEmpty())
    {

    }
    else
    {
        ui->lineEdit->clear();
        ui->listWidget->clear();
        return;
    }

    QString _text=item->text();
    if(choice2==0)
    {
    _id=_text.section(',',0,-5).toInt();
    }
    else if(choice2==1)
    {
     _id=_text.section(',',0,-4).toInt();

    }


    edittingWindow window;
   // ui->statusbar->showMessage(QString::number(_id));
    window.setModal(true);
    window.exec();
}


void MainWindow::on_comboBox_5_activated(int index)
{

}


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{

}


void MainWindow::on_pushButton_6_clicked() //список должников(больше чем 10 дней)
{
    ui->statusbar->showMessage("lox");
    QString filename=QFileDialog::getOpenFileName(this,tr("Откройте список"),"D://","Text File (*.txt)");
    listOfBooks=listOfBooks->load_from_file(filename);

    ui->listWidget->clear();

    for(int i=0;i<D;i++)
    {
    QString info = listOfBooks[i].dolgList(ourLibrary);
    QListWidgetItem* item = new QListWidgetItem;
    item->setText(info);
    ui->listWidget->addItem(item);
    }
}


void MainWindow::on_action_3_triggered()
{
    filename2 = QFileDialog::getOpenFileName(this,tr("Откройте файл с читателями"),"D://","Text File (*.txt)");
    if(!checkingBooksFile(filename2,1)&& !filename2.isEmpty())
    {
    ourLibrary=ourLibrary->load_from_file(filename2);
    QMessageBox::information(this,("Успешно!"),("Теперь вы можете просмотреть сожержимое файла по кнопке 'Просмотр содержимого файла(читатели)'"));
    }
    else if(filename2.isEmpty())
    {

    }
    else
    {
        filename2="";
        QMessageBox::critical(this,tr("Ошибка открытия файла"),tr("Проверьте файл на корректность записи данных"));
    }
}

