#include "mainwindow.h"
#include "ui_mainwindow.h"

extern int amount;
bool fileChangeError = false;
bool byUser=false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setStyleSheet("* { background-color: rgb(220 220 220  ) }");
    ui->lineEdit->setToolTip("Введите ключ поиска");

    const QIcon passwordIcon("D:/3.3.4.png");
    ui->lineEdit->addAction(passwordIcon, QLineEdit::LeadingPosition);
    ui->lineEdit->setPlaceholderText("Поиск...");
    ui->lineEdit->setFrame(true);

    //ui->label_3->setStyleSheet("* { background-color: rgb(100,204,0) }");

    ui->label_2->setStyleSheet("* { background-color: rgb(255,204,0) }"); //"* { background-color: rgb(133,196,120) }"

    ui->pushButton->setStyleSheet("* { background-color: rgb(255,125,100) }");
    ui->search->setStyleSheet("* { background-color: rgb(255,204,0) }");
    setFixedSize(796,471);
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
    connect(double_click,SIGNAL(sendData(QString)),this,SLOT(update(QString)));


    //watcher = new QFileSystemWatcher(this);
    //qDebug()<<filename;
    //QObject::connect(watcher,SIGNAL(fileChanged(QString)),this,SLOT(showWarning(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
//    delete add;
//    delete double_click;
}

int index1=0;
int sortIndex=0;
bool isSaved=false;
bool somethingChanged=false;
extern bool closed;
list List;
QStringList _list;

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
            if (List[i]->data.getNumber() <= List[j]->data.getNumber())
            {
                temp.pushBack(List[i++]->data);
                k++;
            }
            else
            {
                temp.pushBack(List[j++]->data); k++;
            }
        }
        break;
    case 1:
        while (i <= mid && j <= high)
        {
            if (List[i]->data.getName() <= List[j]->data.getName())
            {
                temp.pushBack(List[i++]->data);
                k++;
            }
            else
            {
                temp.pushBack(List[j++]->data); k++;
            }
        }
        break;
    case 2:
        while (i <= mid && j <= high)
        {
            if (List[i]->data.getAmount() <= List[j]->data.getAmount())
            {
                temp.pushBack(List[i++]->data);
                k++;
            }
            else
            {
                temp.pushBack(List[j++]->data); k++;
            }
        }
        break;
    }

    while (i <= mid)
    {
        temp.pushBack(List[i++]->data);
        k++;
    }
    while (j <= high)
    {
        temp.pushBack(List[j++]->data);
        k++;
    }
    k--;
    while (k >= 0)
    {
        List[k + low]->data = temp[k]->data;
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
            if(commaCount!=2)
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
        QString id,amount;
        QChar tmp;
        int i=0;
        id = tmpInfo.section(',',0,-3);
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

        amount=tmpInfo.section(',',2,2);
        i=0;
        int size2=amount.size();
        while(size2--)
        {
            tmp=amount[i];
            if(!tmp.isDigit())
            {
                error = true;
                break;
            }
            i++;
        }
    }


    file.close();
    qDebug()<<error;
    return error;
}



void MainWindow::sort(list &flights, int left, int right)
{
    int i = left, j = right;
    double x = flights[(left + right) / 2]->data.getNumber();
    do
    {
        while (flights[i]->data.getNumber() < x) i++;
        while (flights[j]->data.getNumber() > x) j--;
        if (i <= j)
        {
            workshop temp = flights[i]->data;
            flights[i]->data = flights[j]->data;
            flights[j]->data = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j) sort(flights, left, j);
    if (i < right) sort(flights, i, right);
}


void MainWindow::saveFile(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::WriteOnly|QIODevice::Text);

    if(!filename.isEmpty())
    {
    QTextStream text(&file);

    for(int i=0;i<List.size()-1;i++)
    {
        QString info = QString::number(List[i]->data.getNumber())+","+List[i]->data.getName()+","+QString::number(List[i]->data.getAmount())+"\n";
        text<<info;
    }
    QString info = QString::number(List[List.size()-1]->data.getNumber())+","+List[List.size()-1]->data.getName()+","+QString::number(List[List.size()-1]->data.getAmount());
    text<<info;

    file.close();
    }
    else
    {
       QMessageBox::warning(this,"Ошибка","Для начала откройте файл");
       return;
    }
}


void MainWindow::on_action_triggered()
{
    if(!List.isEmpty() && !isSaved)
    {
        QMessageBox* msg = new QMessageBox;
        msg->setIcon(QMessageBox::Warning);
        msg->setText("Внесенные данные после открытия файла будут удалены!Все равно открыть?");
        QPushButton *OK = msg->addButton(tr("OK"), QMessageBox::ActionRole);
        QPushButton *Cancel = msg->addButton(tr("Отмена"), QMessageBox::ActionRole);
        msg->setDefaultButton(OK);
        msg->exec();
        if(msg->clickedButton()== OK)
        {
           //List.clear();

        }
        else if(msg->clickedButton()== Cancel)
        {
            return;
        }

    }

    if(!List.isEmpty())
    {
    List.clear();
    }

    //QString tmp = filename;
    ui->listWidget->clear();
    isSaved=false;
    somethingChanged=false;
    filename=QFileDialog::getOpenFileName(this,tr("Откройте файл"),"D://","Text File (*.txt)");
    bool error = checkingFile(filename);
     //"D:/workshop.txt"

    //watcher->removePath(filename);
    if(!error && !filename.isEmpty())
    {

    //watcher->addPath(filename);

    QFile file(filename);
    file.open(QIODevice::ReadOnly|QIODevice::Text);

    QTextStream text(&file);

    while(!text.atEnd())
    {
        QString tmp = text.readLine();
        int number=tmp.section(',',0,-3).toInt();
        QString name=tmp.section(',',1,1);
        int amount=tmp.section(',',2,2).toInt();

        workshop temp;
        temp.setAmount(amount);
        temp.setName(name);
        temp.setNumber(number);
        QString info =QString::number(number)+","+name+","+QString::number(amount);
        ui->listWidget->addItem(info);

        List.pushBack(temp);
        _list<<QString::number(temp.getNumber())<<temp.getName()<<QString::number(temp.getAmount());
    }
    QStringList keywords;
    for(int i=0;i<_list.size();i+=3)
        keywords<<_list.at(i);
    int count = keywords.removeDuplicates();
    completer = new QCompleter(keywords,this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(completer);


    for(int i=0;i<List.size();i++)
        qDebug()<<List[i]->data.getName();
    file.close();
    }
    else
    {
       QMessageBox::warning(this,"Ошибка","Файл не соответствует ожиданием.Перепроверьте его содержимое");
       filename="";
       return;
    }
}


void MainWindow::on_pushButton_clicked()
{

}


void MainWindow::recieveData(QString str)
{
    workshop temp;

    int N = 1;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='\n') N++;
    }
    QString* arr = new QString[N];

    arr[0]=str.section('\n',0,-N);
    int number = arr[0].section(',',0,-3).toInt();
    QString name = arr[0].section(',',1,1);
    int amount = arr[0].section(',',2,2).toInt();

    QString info = QString::number(number)+","+name+","+QString::number(amount);
    ui->listWidget->addItem(info);

    temp.setAmount(amount);
    temp.setName(name);
    temp.setNumber(number);

    List.pushBack(temp);
    _list<<QString::number(temp.getNumber())<<temp.getName()<<QString::number(temp.getAmount());

    for(int i=1;i<N;i++)
    {
        arr[i]=str.section('\n',i,i);

        int number = arr[i].section(',',0,-3).toInt();
        QString name = arr[i].section(',',1,1);
        int amount = arr[i].section(',',2,2).toInt();

        temp.setAmount(amount);
        temp.setName(name);
        temp.setNumber(number);

        List.pushBack(temp);
        _list<<QString::number(temp.getNumber())<<temp.getName()<<QString::number(temp.getAmount());

        QString info = QString::number(number)+","+name+","+QString::number(amount);
        ui->listWidget->addItem(info);
    }
    completer = new QCompleter(_list,this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(completer);

    somethingChanged=true;
    isSaved=false;
    delete[] arr;
}


void MainWindow::on_pushButton_2_clicked()
{

    if(!List.isEmpty())
    {
    ui->listWidget->clear();

    for(int i=0;i<List.size();i++)
    {
        ui->listWidget->addItem(QString::number(List[i]->data.getNumber())+","+List[i]->data.getName()+","+QString::number(List[i]->data.getAmount()));
    }

    }
    else
    {
        QMessageBox::warning(this,("Ошибка"),"Список пустой,либо заполните его вручную,либо откройте файл");
        return;
    }
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    index1=index;
    QStringList keywords;
        switch(index)
        {
        case 0:
        {
            for(int i=0;i<_list.size();i+=3)
                keywords<<_list.at(i);
            int count = keywords.removeDuplicates();
            completer = new QCompleter(keywords,this);
            completer->setCaseSensitivity(Qt::CaseInsensitive);
            ui->lineEdit->setCompleter(completer);
            break;
        }
        case 1:
        {
            for(int i=1;i<_list.size();i+=3)
                keywords<<_list.at(i);
            int count = keywords.removeDuplicates();
            completer = new QCompleter(keywords,this);
            completer->setCaseSensitivity(Qt::CaseInsensitive);
            ui->lineEdit->setCompleter(completer);
            break;
        }
        case 2:
        {
            for(int i=2;i<_list.size();i+=3)
                keywords<<_list.at(i);
            int count = keywords.removeDuplicates();
            completer = new QCompleter(keywords,this);
            completer->setCaseSensitivity(Qt::CaseInsensitive);
            ui->lineEdit->setCompleter(completer);
            break;
        }
        }
    ui->lineEdit->clear();
}


void MainWindow::on_search_clicked()
{
    if(!filename.isEmpty() || !List.isEmpty())
    {

    //ui->listWidget->clear();
    QString key=ui->lineEdit->text();

    if(key.isEmpty())
    {
     QMessageBox::warning(this,("Ошибка"),"Введите в поле информацию");
     return;
    }

    QString info="";
    bool find=false;

    switch (index1)
    {
      case 0:
    {
        int num=key.toInt();
        for(int i=0;i<List.size();i++)
        {
            if(List[i]->data.getNumber()==num)
            {
                info+=QString::number(List[i]->data.getNumber()) + "," + List[i]->data.getName() + "," + QString::number(List[i]->data.getAmount())+"\n";
                //ui->listWidget->addItem(info);
                find = true;
            }
            //info.clear();
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
            if(List[i]->data.getName()==key)
            {
                info+=QString::number(List[i]->data.getNumber()) + "," + List[i]->data.getName() + "," + QString::number(List[i]->data.getAmount())+"\n";
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
        int num=key.toInt();
        for(int i=0;i<List.size();i++)
        {
            if(List[i]->data.getAmount()==num)
            {
                info+=QString::number(List[i]->data.getNumber()) + "," + List[i]->data.getName() + "," + QString::number(List[i]->data.getAmount())+"\n";
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

    }
    else if(filename.isEmpty())
    {
        QMessageBox::warning(this,("Ошибка"),"Сперва откройте файл или заполните список вручную");
        return;
    } else if(List.isEmpty())
    {
        QMessageBox::warning(this,("Ошибка"),"Список пуст");
        return;
    }
}


void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    sortIndex=index;
}


void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
//    QString text = item->text();
//    ui->statusbar->showMessage("this");
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
        isSaved=false;
        QMessageBox::warning(this,("Ошибка"),"Откройте файл сперва");
    }
}


void MainWindow::closeEvent (QCloseEvent *event)
{
    //if(somethingChanged) isSaved = false;
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


void MainWindow::on_pushButton_4_clicked()
{
    if(!filename.isEmpty() || !List.isEmpty())
    {
    dialog* dlg = new dialog();
    dlg->setModal(true);
    qDebug()<<dlg->size();
    dlg->exec();

    if(!closed)
    {
    QString info1 = "";
    bool find=false;

    for(int i=0;i<List.size();i++)
    {
        if(List[i]->data.getAmount()>amount)
        {
            find = true;
            info1+=QString::number(List[i]->data.getNumber())+ " " + List[i]->data.getName()+ "\n";
        }
    }

    if(find)
        QMessageBox::information(this,("Информация"),info1);
    else
       QMessageBox::information(this,("Информация"),"Не найдено");
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
        updateTable();
        ui->statusbar->showMessage("Отсортировано!");
    }
    else
        QMessageBox::warning(this,("Ошибка"),"Список пустой,либо заполните его вручную,либо откройте файл");
}


void MainWindow::on_pushButton_5_clicked()
{

}


void MainWindow::showWarning(QString str)
{
    if(!somethingChanged)
    {
    QMessageBox::warning(this,"Ошибка","Файл был изменен");
    fileChangeError=true;
    }
    return;
}


void MainWindow::updateTable()
{
    ui->listWidget->clear();

    for(int i=0;i<List.size();i++)
    {
        ui->listWidget->addItem(QString::number(List[i]->data.getNumber())+ "," +List[i]->data.getName() + "," + QString::number(List[i]->data.getAmount()));
    }
}

void MainWindow::update(QString str)
{
    completer = new QCompleter(_list,this);
    ui->lineEdit->setCompleter(completer);
    updateTable();
}

void MainWindow::on_comboBox_activated(int index)
{

}

