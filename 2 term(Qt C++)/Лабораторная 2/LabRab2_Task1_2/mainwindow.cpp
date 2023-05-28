#include "mainwindow.h"
#include "ui_mainwindow.h"

extern int amount;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(786,467);
    ui->pushButton->setStyleSheet("* { background-color: rgb(255,125,100) }");
    ui->search->setStyleSheet("* { background-color: rgb(133,196,120) }");
    add = new addDialog();
    add->setModal(true);
    add->setFixedSize(460,345);
    connect(ui->pushButton,SIGNAL(clicked()),add,SLOT(show()));
    connect(add, SIGNAL(sendData(QString)),this, SLOT(recieveData(QString)));

    double_click = new doubleClick();
    double_click->setModal(true);
    double_click->setFixedSize(356,226);
    connect(ui->listWidget,SIGNAL(doubleClicked(QModelIndex)),double_click,SLOT(show()));
    connect(this, SIGNAL(sendIndex(int)),double_click, SLOT(recieveIndex(int)));
    connect(double_click,SIGNAL(update(QString)),this,SLOT(update1(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete add;
    delete double_click;
}

int index1=0;
int sortIndex=0;
bool isSaved=false;
bool somethingChanged=false;
extern bool closed;

list List;

bool checkingFile(QString filename)
{
    bool error=false;
    int commaCount=0;

    QFile file(filename);
    file.open(QIODevice::ReadOnly|QIODevice::Text);

    QTextStream text(&file);
    QChar ch;

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
        if(!tmpInfo.isEmpty() && commaCount==0)
        {
            return true;
        }
        QString id,FIO,adress,date;
        QChar tmp;
        int i=0;
        id = tmpInfo.section(',',0,-4);
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

        date=tmpInfo.section(',',3,3);
        QDate data = QDate::fromString(date,"dd.MM.yyyy");
        if(!data.isValid())
        {
            error = true;
        }
    }


    file.close();
    qDebug()<<error;
    return error;
}


void merge(list& List, int low, int mid, int high,int field)
{

    list temp;
    int i = low;
    int j = mid + 1;
    int k = 0;

    switch (field)
    {
    case 0:
        while (i <= mid && j <= high)
        {
            if (List.getAt(i).getNumber() <= List.getAt(j).getNumber())
            {
                temp.pushBack(List.getAt(i++));
                k++;
            }
            else
            {
                temp.pushBack(List.getAt(j++)); k++;
            }
        }
        break;
    case 1:
        while (i <= mid && j <= high)
        {
            if (List.getAt(i).getFIO() <= List.getAt(j).getFIO())
            {
                temp.pushBack(List.getAt(i++));
                k++;
            }
            else
            {
                temp.pushBack(List.getAt(j++)); k++;
            }
        }
        break;
    case 2:
        while (i <= mid && j <= high)
        {
            if (List.getAt(i).getAdress() <= List.getAt(j).getAdress())
            {
                temp.pushBack(List.getAt(i++));
                k++;
            }
            else
            {
                temp.pushBack(List.getAt(j++)); k++;
            }
        }
        break;

    case 3:
        while (i <= mid && j <= high)
        {
            if (List.getAt(i).getDate() <= List.getAt(j).getDate())
            {
                temp.pushBack(List.getAt(i++));
                k++;
            }
            else
            {
                temp.pushBack(List.getAt(j++)); k++;
            }
        }
        break;
    }

    while (i <= mid)
    {
        temp.pushBack(List.getAt(i++));
        k++;
    }
    while (j <= high)
    {
        temp.pushBack(List.getAt(j++));
        k++;
    }
    k--;
    while (k >= 0)
    {
        List.getAt(k + low) = temp.getAt(k);
        k--;
    }
}

void mergeSort(list& List, int low, int high,int field)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(List, low, mid,field);
        mergeSort(List, mid + 1, high,field);
        merge(List, low, mid, high,field);
    }
}

void MainWindow::saveFile(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::WriteOnly|QIODevice::Text);

    QTextStream text(&file);

    for(int i=0;i<List.size()-1;i++)
    {
        QDate date = List.getAt(i).getDate();
        QString info = QString::number(List.getAt(i).getNumber())+ "," +List.getAt(i).getFIO()+ "," + List.getAt(i).getAdress() + "," + date.toString("dd.MM.yyyy")+"\n";
        text<<info;
    }
    QDate date = List.getAt(List.size()-1).getDate();
    QString info = QString::number(List.getAt(List.size()-1).getNumber())+ "," +List.getAt(List.size()-1).getFIO()+ ","+ List.getAt(List.size()-1).getAdress() + "," + date.toString("dd.MM.yyyy") +"\n";
    text<<info;

    file.close();
}

void MainWindow::on_action_triggered()
{
    QString tmp = filename;
    if(!List.isEmpty())
    {
    List.clear();
    }

    ui->listWidget->clear();

    filename=QFileDialog::getOpenFileName(this,tr("Откройте файл"),"D://","Text File (*.txt)");

    if(checkingFile(filename)==false)
    {
    QFile file(filename);
    file.open(QIODevice::ReadOnly|QIODevice::Text);

    QTextStream text(&file);

    while(!text.atEnd())
    {
        QString tmp = text.readLine();
        int number=tmp.section(',',0,-4).toInt();
        QString FIO=tmp.section(',',1,1);
        QString adress = tmp.section(',',2,2);
        QString stringDate = tmp.section(',',3,3);

        QDate date;
        date = QDate::fromString(stringDate,"dd.MM.yyyy");

        shop temp;
        temp.setNumber(number);
        temp.setFIO(FIO);
        temp.setAdress(adress);
        temp.setDate(date);

        QString info = QString::number(number)+ "," + FIO + "," +adress + "," + date.toString("dd.MM.yyyy");
        ui->listWidget->addItem(info);

        List.pushBack(temp);
    }


    for(int i=0;i<List.size();i++)
        //qDebug()<<List[i]->data.getName();
    file.close();
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Файл содержит ошибки или не соответствует ожиданиям");
        filename="";
        return;
    }

}


void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::recieveData(QString str)
{
    shop temp;

    int N = 1;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='\n') N++;
    }
    QString* arr = new QString[N];

    arr[0]=str.section('\n',0,-N);
    int number = arr[0].section(',',0,-4).toInt();
    QString FIO = arr[0].section(',',1,1);
    QString adress = arr[0].section(',',2,2);
    QString stringDate = arr[0].section(',',3,3);

    QDate date;
    date = QDate::fromString(stringDate,"dd.MM.yyyy");

    QString info = QString::number(number) + "," + FIO + "," + adress + "," + date.toString("dd.MM.yyyy");
    ui->listWidget->addItem(info);

    temp.setNumber(number);
    temp.setFIO(FIO);
    temp.setAdress(adress);
    temp.setDate(date);

    List.pushBack(temp);

    for(int i=1;i<N;i++)
    {
        arr[i]=str.section('\n',i,i);

        int number = arr[0].section(',',0,-4).toInt();
        QString FIO = arr[0].section(',',1,1);
        QString adress = arr[0].section(',',2,2);
        QString stringDate = arr[0].section(',',3,3);

        QDate date;
        date = QDate::fromString(stringDate,"dd.MM.yyyy");

        temp.setNumber(number);
        temp.setFIO(FIO);
        temp.setAdress(adress);
        temp.setDate(date);

        List.pushBack(temp);

        QString info = QString::number(number) + "," + FIO + "," + adress + "," + date.toString("dd.MM.yyyy");
        ui->listWidget->addItem(info);
    }


    somethingChanged=true;
    delete[] arr;
}

void MainWindow::on_pushButton_2_clicked()
{
    if(!List.isEmpty())
    {
    ui->listWidget->clear();

    for(int i=0;i<List.size();i++)
    {
        QDate date = List.getAt(i).getDate();
        ui->listWidget->addItem(QString::number(List.getAt(i).getNumber())+ "," +List.getAt(i).getFIO()+ ","+ List.getAt(i).getAdress() + "," + date.toString("dd.MM.yyyy"));
    }

    }
    else
        QMessageBox::warning(this,("Ошибка"),"Список пустой,либо заполните его вручную,либо откройте файл");
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    index1=index;
    ui->lineEdit->clear();
}


void MainWindow::on_search_clicked()
{
    if(ui->lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Поле ввода информации пустое!");
        return;
    }
    if(!filename.isEmpty() || !List.isEmpty())
    {
    QString key=ui->lineEdit->text();
    QString info="";
    bool find=false;
    QString str = "dd.MM.yyyy";
    switch (index1)
    {
      case 0:
    {
        int num=key.toInt();
        for(int i=0;i<List.size();i++)
        {
            if(List.getAt(i).getNumber()==num)
            {
                info+=QString::number(List.getAt(i).getNumber()) + "," + List.getAt(i).getFIO() + "," + List.getAt(i).getAdress()+ "," + (List.getAt(i).getDate()).toString(str)+"\n";
                find = true;
            }
        }
        if(find)
            QMessageBox::information(this,"Информация",info);
        else
            QMessageBox::information(this,"Информация","Не найдено");
        break;
    }
      case 1:
    {
        for(int i=0;i<List.size();i++)
        {
            if(List.getAt(i).getFIO()==key)
            {
                info+=QString::number(List.getAt(i).getNumber()) + "," + List.getAt(i).getFIO() + "," + List.getAt(i).getAdress()+ "," + (List.getAt(i).getDate()).toString(str)+"\n";
                find = true;
            }
        }
        if(find)
            QMessageBox::information(this,"Информация",info);
        else
            QMessageBox::information(this,"Информация","Не найдено");
        break;
    }
      case 2:
    {
        for(int i=0;i<List.size();i++)
        {
            if(List.getAt(i).getAdress()==key)
            {
                info+=QString::number(List.getAt(i).getNumber()) + "," + List.getAt(i).getFIO() + "," + List.getAt(i).getAdress()+ "," + (List.getAt(i).getDate()).toString(str)+"\n";
                find = true;
            }
        }
        if(find)
            QMessageBox::information(this,"Информация",info);
        else
            QMessageBox::information(this,"Информация","Не найдено");
        break;
    }
       case 3:
    {
        for(int i=0;i<List.size();i++)
        {
            QDate date = QDate::fromString(key,"dd.MM.yyyy");

            if(!date.isValid())
            {
                QMessageBox::warning(this,"Ошибка","Проверьте корректность воода данных!");
                return;
            }

            if(List.getAt(i).getDate()==date)
            {
                info+=QString::number(List.getAt(i).getNumber()) + "," + List.getAt(i).getFIO() + "," + List.getAt(i).getAdress()+ "," + (List.getAt(i).getDate()).toString(str)+"\n";
                find = true;
            }
        }
        if(find)
            QMessageBox::information(this,"Информация",info);
        else
            QMessageBox::information(this,"Информация","Не найдено");
        break;
    }

    }

    } else
    {
        QMessageBox::warning(this,("Ошибка"),"Сперва откройте файл или заполните список вручную");
    }
}


void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    sortIndex=index;
}


void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{

}


void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    int number = index.row();
    ui->statusbar->showMessage(QString::number(number));
    emit sendIndex(number);
}


void MainWindow::on_action_2_triggered()
{

}


void MainWindow::on_save_triggered()
{
    filename = QFileDialog::getSaveFileName(this,("Создайте файл"),"D://", tr("Text files (*.txt)"));
    if(!filename.isEmpty())
    saveFile(filename);
}


void MainWindow::on_action_3_triggered()
{
    if(!filename.isEmpty())
    {
         ui->statusbar->showMessage("Данные сохранены!");
         isSaved=true;
         saveFile(filename);
    }
    else
    {
        QMessageBox::warning(this,("Ошибка"),"Откройте файл сперва");
    }
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    if(isSaved==false && somethingChanged==true)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this,("Постойте!"),"Вы не сохранили файл! Все несохраненные данный потеряются. Сохранить файл?",
                                      QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::No) {
        event->accept();
    } else {
        if(filename.isEmpty())
        filename=QFileDialog::getOpenFileName(this,tr("Откройте файл"),"D://","Text File (*.txt)");

        if(filename.isEmpty())
        {
            QMessageBox::warning(this,("Ошибка"),("Ваши данные не будут сохранены,если вы не выберите файл"));
            event->ignore();
        }

        saveFile(filename);
    }

    }
}


void MainWindow::on_pushButton_4_clicked() //delete
{
    if(!filename.isEmpty() || !List.isEmpty())
    {
    if(!closed)
    {
    QString info1 = "";
    bool find=false;

    mergeSort(List,0,List.size()-1,1);
    mergeSort(List,0,List.size()-1,2);

    QString fio1,fio2,adress1,adress2;
    for(int i=0;i<List.size();i++)
    {
        fio1=List.getAt(i).getFIO();
        adress1=List.getAt(i).getAdress();
        for(int j=i+1;j<List.size();j++)
        {
            fio2=List.getAt(j).getFIO();
            adress2=List.getAt(j).getAdress();

            if(fio1==fio2 && adress1==adress2)
            {
                List.erase(j);
                j--;
                somethingChanged=true;
            }
        }
    }
    updateTable();
    }
    }
    else
    {
        QMessageBox::warning(this,("Файл не открыт!"),"Откройте сначала файл с цехами или введите данные вручную");
    }

}


void MainWindow::on_pushButton_3_clicked()
{
    int comboChoice = ui->comboBox_2->currentIndex();
    ui->statusbar->showMessage(QString::number(comboChoice));

    if(!List.isEmpty())
    {
       mergeSort(List,0,List.size()-1,comboChoice);
       ui->statusbar->showMessage("Отсортировано!");
       updateTable();
    }
    else
        QMessageBox::warning(this,("Ошибка"),"Список пустой,либо заполните его вручную,либо откройте файл");
}


void MainWindow::on_pushButton_5_clicked()
{

}


void MainWindow::updateTable()
{
    ui->listWidget->clear();

    for(int i=0;i<List.size();i++)
    {
        QDate date = List.getAt(i).getDate();
        ui->listWidget->addItem(QString::number(List.getAt(i).getNumber())+ "," +List.getAt(i).getFIO()+ ","+ List.getAt(i).getAdress() + "," + date.toString("dd.MM.yyyy"));
    }
}

void MainWindow::update1(QString str)
{
    updateTable();
}
