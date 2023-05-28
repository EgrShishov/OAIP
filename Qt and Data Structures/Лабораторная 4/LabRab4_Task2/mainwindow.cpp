#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("MyString");
    QStringList keywords;
    keywords<<"memcpy()"<<"memmove()"<<"strcpy()"<<"strncpy()"<<"strcat()"<<"strncat()"<<"memcmp()"<<
    "strcmp()"<<"strncmp()"<<"strtok()"<<"memset()"<<"strerror()"<<"strlen()"<<"print()";
    QCompleter* completer = new QCompleter(keywords,this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);

    setFixedSize(526,247);
    ui->setupUi(this);
    ui->label_7->setText("Для информации нажмитие Ctrl+I");
    ui->lineEdit->setPlaceholderText("Введите название функции...");
    ui->lineEdit->setFrame(true);
    ui->lineEdit->setToolTip("Доступные функции : memcpy(void* s1,const void* s2,size_t n),memmove(void* s1, const void* s2, size_t n)\nstrcpy(char* s1, const char* s2)"
                             ",strncpy(char* s1, const char* s2, size_t n),strcat(char* s1, const char* s2)\nstrncat(char* s1, const char* s2, size_t n),"
                             "memcp(const void* s1, const void* s2, size_t n),strcmp(const char* s1, const char* s2)\nstrncmp(const char* s1, const char* s2, size_t n),"
                             "strtok(char* s1, const char* s2),memset(void* s, int c, size_t n)\nstrerror(int errnum),strlen(const char* s)");
    ui->lineEdit->setCompleter(completer);
    const QIcon passwordIcon("D:/command-line.png");
    ui->lineEdit->addAction(passwordIcon, QLineEdit::LeadingPosition);
    ui->label->setStyleSheet("* { background-color: rgb(220,220,220) }");
    //ui->label_3->setStyleSheet("* { background-color: rgb(255,160,0) }");
    ui->pushButton->setStyleSheet("* { background-color: rgb(31,174,233) }");
    ui->lineEdit->setStyleSheet("border: 5px sold red");
    ui->label_5->setStyleSheet("* { background-color: rgb(31,174,233) }");
    ui->lineEdit->setStyleSheet(QString("QLineEdit {border-width: 2px;"
                                        "  border-style: solid; "
                                        "border-color: rgb(31,174,233);}"));
    ui->textEdit->setStyleSheet(QString("QTextEdit {border-width: 2px;"
                                        "  border-style: solid; "
                                        "border-color: rgb(31,174,233);}"));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));


    HINSTANCE load;
    load=LoadLibrary(L"D:/build-StringDLL-Desktop_x86_windows_msvc2022_pe_64bit-Release/release/StringDLL.dll");

    if(load==nullptr)
    {
        qDebug()<<"failed";
        return;
    }
    qDebug()<<"success";
    //CREATE_STRING p = (CREATE_STRING)GetProcAddress(load,"CreateStringObject");
    //String* pString = p();

    FreeLibrary(load);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void demo(const char* lhs, const char* rhs, int sz)
{
    String ab;
    int rc = ab.strncmp(lhs, rhs, sz);
    if(rc == 0)
        printf("First %d chars of [%s] equal [%s]\n", sz, lhs, rhs);
    else if(rc < 0)
        printf("First %d chars of [%s] precede [%s]\n", sz, lhs, rhs);
    else if(rc > 0)
        printf("First %d chars of [%s] follow [%s]\n", sz, lhs, rhs);

}

void MainWindow::on_pushButton_clicked()
{
    qDebug()<<"mama";
    String popa("jadd");
    String jopa("jadd");
    String mama("fjsjkslf");
    int a = (popa==jopa);
    int b = (jopa==mama);
    int c = (jopa!=mama);
    qDebug()<<QString::number(a)<<QString::number(b)<<QString::number(c);
    mama += "papa";
    mama+=String("tetya");
    std::string papa = mama.to_std_string();
    qDebug()<<QString::number(papa.size());
    qDebug()<<mama.to_QString();
    mama =  popa;
    qDebug()<<mama.to_QString();
    String sestra = String::to_String("dmada");
    sestra += String("adkjadla");
    qDebug()<<sestra.to_QString();


    String mama2 = String::fromStdString(std::string("papa"));
    qDebug()<<mama2.to_QString();
    String papa2 = String::fromQString(QString("brat"));
    qDebug()<<papa2.to_QString();


    QString func = ui->lineEdit->text();
    if(func.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Введите в командную строку нужную команду!");
        return;
    }
    QString copy = func;
    QString args;
        qDebug()<<"mama";
        size_t index = func.indexOf("(");
    for(size_t i = index;func[i]!=')';i++)
        args+=func[i];
    args.remove(0,1);
    func = func.section('(',0,-2);
    qDebug()<<func<<args;

    if(func=="memcpy")
    {
        if(args.count(",")==2)
        {
        QStringList tmp = args.split(",");
        const char* input = tmp[1].toLocal8Bit().data();
        int n = tmp[2].toInt();
        char empty[n];
        String::memcpy(empty,input,n);
        ui->textEdit->setText(empty);
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функции не существует такой перегрузки");
        }

    }
    else if(func=="memmove")
    {
        if(args.count(",")==2)
        {
        QStringList tmp = args.split(",");
        char str[] ="1234567890";
//        char* empty = new char[tmp[0].toLocal8Bit().size()];
//        String::memcpy(empty,tmp[0].toLocal8Bit().data(),tmp[0].toLocal8Bit().size());
//        const char* input = tmp[1].toLocal8Bit().constData();
        int c = tmp[0].toInt();
        int b = tmp[1].toInt();
        int n = tmp[2].toInt();
        String::memmove(str+c,str+b,n);
        ui->textEdit->setText(str);
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функции не существует такой перегрузки");
        }

        String aboba;
        char str[] ="1234567890";
        aboba.memmove(str+3,str+5,4);
        qDebug()<<str;
    }
    else if(func=="strcpy")
    {
        if(args.count(",")==1)
        {
            QStringList tmp = args.split(",");

            char* str1 = (char*)calloc((tmp[0].size() + 1),sizeof(char));
            String::strcpy(str1, tmp[0].toLocal8Bit().constData());
            const char* str2 = tmp[1].toLocal8Bit().constData();

            String::strcpy(str1, str2);
            QString info = str1;
            ui->textEdit->setText(info);
            free(str1);
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функции не существует такой перегрузки");
        }
    }
    else if(func=="strncpy")
    {
        if(args.count(",")==2)
        {
            QStringList tmp = args.split(",");

            const char* str2 = tmp[1].toLocal8Bit().constData();
            int n = tmp[2].toInt();
            char* str1 = (char*)calloc((tmp[0].size() + 1),sizeof(char));
            String::strcpy(str1, tmp[0].toLocal8Bit().constData() );

            String::strncpy(str1, str2,n);
            QString info = str1;
            ui->textEdit->setText(info);
            free(str1);
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функции не существует такой перегрузки");
        }
    }
    else if(func=="strcat")
    {
        if(args.count(",")==1)
        {
            QStringList tmp = args.split(",");

            char* str1 = (char*)calloc(tmp[0].size() + 1 + tmp[1].size(),sizeof(char));
            String::strcpy(str1, tmp[0].toLocal8Bit().constData());
            const char* str2 = tmp[1].toLocal8Bit().constData();

            String::strcat(str1,str2);
            QString info = str1;
            ui->textEdit->setText(info);
            free(str1);
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функции не существует такой перегрузки");
        }
    }
    else if(func=="strncat")
    {
        if(args.count(",")==2)
        {
            QStringList tmp = args.split(",");

            char* str1 = (char*)calloc(tmp[0].size() + 1 + tmp[1].size(),sizeof(char));
            String::strcpy(str1, tmp[0].toLocal8Bit().constData());
            const char* str2 = tmp[1].toLocal8Bit().constData();
            int n = tmp[2].toInt();

            String::strncat(str1,str2,n);
            QString info = str1;
            ui->textEdit->setText(info);
            free(str1);
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функции не существует такой перегрузки");
        }
    }
    else if(func=="memcpy")
    {
        if(args.count(",")==2)
        {
            QStringList tmp = args.split(",");
            char* str1 = (char*)calloc(tmp[0].size() + 1 + tmp[2].toInt(),sizeof(char));
            String::strcpy(str1, tmp[0].toLocal8Bit().constData());
            const char* str2 = tmp[1].toLocal8Bit().constData();
            int n = tmp[2].toInt();
            String::memcpy(str1,str2,n);

            ui->textEdit->setText(str1);
            free(str1);
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функции не существует такой перегрузки");
        }
    }
    else if(func=="strcmp")
    {
        if(args.count(",")==1)
        {
            QStringList tmp = args.split(",");
            for(int i=0;i<tmp.size();i++)
                qDebug()<<"striing"<<tmp[i];
            const char* str1 = tmp[0].toLocal8Bit().constData();
            const char* str2 = tmp[1].toLocal8Bit().constData();
            int ans = String::strcmp(str1,str2);
            qDebug()<<QString::number(ans);
            QString info;
            if(ans>0)
                info = "Строка 1 больше строки 2";
            else if(ans<0)
                info = "Строка 1 меньше строки 2";
            else
                info = "Строки равны";
            ui->textEdit->setText(info);
        }
        else
        {
           QMessageBox::warning(this,"Ошибка","Для функции не существует такой перегрузки");
        }
    }
    else if(func=="strncmp")
    {
        if(args.count(",")==2)
        {
            QStringList tmp = args.split(",");
            for(int i=0;i<tmp.size();i++)
                qDebug()<<"striing"<<tmp[i];
            const char* str1 = tmp[0].toLocal8Bit().constData();
            const char* str2 = tmp[1].toLocal8Bit().constData();
            int n = tmp[2].toInt();
            int ans = String::strncmp(str1,str2,n);
            qDebug()<<QString::number(ans);
            QString info;
            if(ans>0)
                info = "Первые " + QString::number(n) + " символа(ов) строки 1 больше строки 2";
            else if(ans<0)
                info = "Первые " + QString::number(n) + " символоа(ов) строки 1 меньше строки 2";
            else
                info = "Первые " + QString::number(n) + " символоа(ов) строк равны";
            ui->textEdit->setText(info);
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функции не существует такой перегрузки");
        }

//        char droids[][10] = { "R2D2" , "C3PO" , "R2A6" };                            // имеющиеся дроиды

//          qDebug() <<  "Ищете R2-дроида астромеханика...n";

//          for (int counter = 0 ; counter <= 2 ; counter++) // проход по дроидам
//            if ( ab.strncmp( droids[counter], "R2**", 2 ) == 0 ) //сравниваем первые два символа строк
//            {
//                qDebug() << "дроид [+_+] >> " << droids[counter] << "\n";
//            }

//          const char* string = "Hello World!";
//            demo(string, "Hello!", 5);
//            demo(string, "Hello", 10);
//            demo(string, "Hello there", 10);
//            demo("Hello, everybody!" + 12, "Hello, somebody!" + 11, 5);

    }
    else if(func=="strtok")
    {
        if(args.count(",")==1)
        {
            QStringList tmp = args.split(",");
            QString str1,del,result;
            str1=tmp[0];
            del=tmp[1];
            char* cstr = (char*)calloc(str1.size(),sizeof(char));
            std::strcpy(cstr,str1.toStdString().c_str());
            char* c_delim = (char*)calloc(del.size(),sizeof(char));
            std::strcpy(c_delim,del.toStdString().c_str());
            char* res = String::strtok(cstr,c_delim);
            result+=QString::fromUtf8(res)+'\n';
            while(res!=NULL){
                res = String::strtok(NULL,c_delim);
                result+=QString::fromUtf8(res)+'\n';
            }
            ui->textEdit->setText(result);
        }
        else
        {
            QMessageBox::warning(this,"","");
        }

    }
    else if(func=="memset")
    {
        if(args.count(",")==2)
        {
            QStringList tmp = args.split(",");
            int c = tmp[1].toInt();
            int n = tmp[2].toInt();
            char* str1 = (char*)calloc(tmp[0].size()+1+n,sizeof(char));
            String::strcpy(str1,tmp[0].toLocal8Bit().constData());
            String::memset(str1,c,n);
            ui->textEdit->setText(str1);
            free(str1);
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функции не существует такой перегрузки");
        }
    }
    else if(func=="memcmp")
    {
        if(args.count(",")==2)
        {
           QStringList tmp = args.split(",");

           const char* str1 = tmp[0].toLocal8Bit().constData();
           const char* str2 = tmp[1].toLocal8Bit().constData();
           int n = tmp[2].toInt();
           int ans = String::memcmp(str1,str2,n);

           QString info;
           if(ans>0)
               info = "Первые " + QString::number(n) + " символа(ов) строки 1 больше строки 2";
           else if(ans<0)
               info = "Первые " + QString::number(n) + " символоа(ов) строки 1 меньше строки 2";
           else
               info = "Первые " + QString::number(n) + " символоа(ов) строк равны";
           ui->textEdit->setText(info);

        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функции не существует такой перегрузки");
        }
    }
    else if(func=="strerror")
    {
        if(!args.isEmpty())
        {
            ui->textEdit->setText(String::strerror(args.toInt()));
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функции не существует такой перегрузки");
        }
    }
    else if(func=="strlen")
    {
        if(!args.isEmpty())
        {
            const char* str1=args.toLocal8Bit().constData();
            size_t len = String::strlen(str1);
            ui->textEdit->setText(QString::number(len));
            ui->statusbar->showMessage("Длина строки : " + QString::number(len));
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Для функции не существует такой перегрузки");
        }
    }
    else if(func=="print")
    {
        ui->textEdit->setText(mama.to_QString());
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Данная функция не найдена");
    }
    QString info;
    info="Использована функция : " + copy;
    ui->lineEdit->clear();
    ui->label_2->setText(info);
}
