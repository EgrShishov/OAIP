#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setlocale(LC_CTYPE,"rus");
    setWindowTitle("Parser");
    QIcon parser("D:/mama(1).ico");
    QIcon icon("D:/greeb.png");
    setWindowIcon(parser);
    setFixedSize(840,646);

    ui->pushButton->setIcon(icon);
    ui->label_2->setStyleSheet("* { background-color: rgb(178,236,93) }");
    ui->label_3->setStyleSheet("* { background-color: rgb(220,220,220) }");
    ui->label_4->setStyleSheet("* { background-color: rgb(178,236,93) }");
    ui->tabWidget->setCurrentIndex(0);

    effect = new QGraphicsDropShadowEffect;
    effect->setBlurRadius(50);
    effect->setXOffset(3);
    effect->setYOffset(3);
    effect->setEnabled(false);
    ui->textEdit->setGraphicsEffect(effect);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_triggered()
{
    filename = QFileDialog::getOpenFileName(this,"Откройте файл","D:/","C++ File (*.cpp);;Header File(*.h)");

    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        effect->setEnabled(true);
        effect->setColor(Qt::red);
        ui->textEdit->setGraphicsEffect(effect);
        QMessageBox msg;
        msg.setIcon(QMessageBox::Warning);
        msg.setWindowTitle("Ошибка");
        msg.setText("Ошибка открытия файла");
        msg.setStandardButtons(QMessageBox::Ok);
        int ret = msg.exec();
        switch(ret)
        {
        case QMessageBox::Ok:
        {
        effect->setEnabled(false);
        ui->textEdit->setGraphicsEffect(effect);
        break;
        }
        }
        return;
    }

    QString code;

    QTextStream text(&file);
    code = text.readAll();

    ui->textEdit->setText(code);

    file.close();
}

void MainWindow::on_pushButton_clicked()
{
    effect->setEnabled(true);
    if(ui->textEdit->toPlainText().isEmpty())
    {
        effect->setColor(Qt::red);
        ui->textEdit->setGraphicsEffect(effect);
        //QMessageBox::warning(this,"Предупреждение","Поле для ввода кода пусто! Введите код вручную или откройте cpp/h файл.");
        QMessageBox msg;
        msg.setIcon(QMessageBox::Warning);
        msg.setWindowTitle("Предупреждение");
        msg.setText("Поле для ввода кода пусто! Введите код вручную или откройте cpp/h файл.");
        msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        int ret = msg.exec();
        switch(ret)
        {
        case QMessageBox::Ok:
        {
        effect->setEnabled(false);
        ui->textEdit->setGraphicsEffect(effect);
        break;
        }
        case QMessageBox::Cancel:
        {
        effect->setEnabled(false);
        ui->textEdit->setGraphicsEffect(effect);
        break;
        }
        }

        return;
    }
    effect->setColor(QColor(178,236,93));
    ui->textEdit->setGraphicsEffect(effect);
    doc = ui->textEdit->document();
    clearAllTabs();
    QString code = ui->textEdit->toPlainText();
    QStringList list;
    list = ui->textEdit->toPlainText().split("\n");

    QStringList mama = code.split(";");
    for(int i=0;i<mama.size();i++)
        mama[i]+=";";
    ui->Tab1TextEdit->setText(getAmountOfVariables(mama) + '\n' +getVarChanges(list));
    ui->Tab2TextEdit->setText(getClasses(list));
    ui->Tab3TextEdit->setText(getFuncs(list)+'\n'+getLocalVars(list));
    QString Tab4 = getOverloadFuncs(list) + "--------------------------------" + getDepth(code);
    ui->Tab4TextEdit->setText(Tab4);
    ui->Tab5TextEdit->setText(getErrors(list));
}

QString MainWindow::getAmountOfVariables(QStringList& list)
{
    std::vector <std::pair<String,int>> vars;
    String ans;
    std::regex varInit("(\\bconst bool\\b|\\bconst int\\b|\\bconst double\\b|\\bconst unsigned int\\b|\\bconst unsigned double\\b|\\bunsigned double\\b|"
                       "\\bint\\b|\\buint\\b|\\bunsigned int\\b|\\bdouble\\b|\\blong\\b|\\bsize_t\\b|\\bfloat\\b|\\bbool\\b|\\bshort\\b|\\blong long\\b|\\bvoid\\b|\\blong double\\b)"
                       "\\s*(([\\w_]+)\\s*(=)?\\s*(([0-9]]*)|[\\w_+-\\.]*)\\s*((,\\s*)|(;)))+");
    std::regex varInitString("(\\bstring\\b|\\bchar\\b)"
                       "\\s*(([\\w_]+)\\s*(=)?\\s*(([0-9]*)|[\\w_+\\(\\)']*)\\s*((,\\s*)|(;)))+");

    int amount=0;
    //(\\b#define\\b)\s*([\\w_\\s*]+)\\s*([0-9]+) for #defines

    for(int i=0;i<list.size();i++)
    {

    std::cmatch result;
    //std::string code = list[i].toStdString();
    String code = String::fromQString(list[i]);

    //qDebug()<<"trtrtr"<<code.to_QString();
    if(std::regex_search(code.c_str(),result,varInit))
    {
        QString tmp = QString::fromStdString(result[0]);
        qDebug()<<"tmp"+tmp;
        amount=tmp.count(QLatin1Char(','));

        qDebug()<<"---------------";
        qDebug()<<QString::fromStdString(result[1]); //тип переменной
        qDebug()<<QString::fromStdString(result[2]); //имя переменной
        qDebug()<<QString::fromStdString(result[3]); //знак равно
        qDebug()<<QString::fromStdString(result[4]); //значение
        qDebug()<<"---------------";

        if (QString::fromStdString(code.to_std_string()).indexOf("for")!=-1) {}
        else if (QString::fromStdString(code.to_std_string()).indexOf("'('")!=-1) {}
        else if (QString::fromStdString(code.to_std_string()).indexOf("')'")!=-1) {}
        else if(QString::fromStdString(code.to_std_string()).indexOf("(")!=-1) continue;

        QStringList tmpList = tmp.split(",");
        for(int i=1;i<tmpList.size();i++)
        {
            tmpList[i]=QString::fromStdString(result[1]) + " " + tmpList[i];
        }
        for(int i=0;i<tmpList.size();i++)

            qDebug()<<"mama"<<tmpList[i];

            for(int i=0;i<tmpList.size();i++)
            {
                ans += String::fromQString(tmpList[i]);
                ans += "\n";
            }
        //qDebug()<<QString::number(result.size());
        for(int i=0;i<result.size();i++)
        {
            //qDebug()<<QString::number(i)<<" :"<<QString::fromStdString(result[i]);
        }
        for(int i=0;i<tmpList.size();i++)
        vars.push_back(std::make_pair((String::fromStdString(result[1])),0));
    }

    if(std::regex_search(code.c_str(),result,varInitString))
    {
        vars.push_back(std::make_pair((String::fromStdString(result[1])),0));
        ans += String::fromStdString(result[0]);
        ans += "\n";
    }
    }


    std::sort(vars.begin(),vars.begin()+vars.size());
    String type;
    int count=0;
    for(int i=0;i<vars.size();i+=count)
    {
        count=0;
        for(int j=i;j<vars.size();j++)
        {
            if(vars[i].first==vars[j].first)
            {
                count++;
            }
        }
        //vars[i].second=count;
        //qDebug()<<QString::fromStdString(vars[i].first)<<QString::number(count);
        type+= String::fromStdString(std::string("Type : "));
        type+= vars[i].first;
        type+= String::fromStdString(std::string(" ,amount : "));
        type+= String::fromStdString(std::to_string(count));
        type+= String("\n");
    }
    //qDebug()<<QString::fromStdString(ans);
    type+="----------------------------\n";
    type+=ans;
    ans=type;
    return ans.to_QString();
}

QString MainWindow::getClasses(QStringList& list)
{
    String ans;
    std::vector <String> classes;
    std::vector <String> structures;
    size_t classesAmount=0 ,structAmount=0 ,arrAmount=0;
    std::regex regular2 ("(\\bclass\\b|\\bstruct\\b)(\\s*)([\\w_]+)(\\s*[\\w: ,<>]*)(?:\\n|\\{|$)");
    for(int i=0;i<list.size();i++)
    {
        std::cmatch result;
        String code = String::fromQString(list[i]);
        if(std::regex_search(code.c_str(),result,regular2))
        {
            qDebug()<<"dd"<<QString::fromStdString(result[3]);
            if(result[1]=="struct")
            {
                structAmount++;
                structures.push_back(String::fromStdString(result[3]));
            }
            else if(result[1]=="class")
            {
                classesAmount++;
                classes.push_back(String::fromStdString(result[3]));
            }
        }
    }

    QStringList classnames;
    QStringList structnames;

    int initClassAmount=0;
    int initStructAmount=0;
    int initArrAmount=0;

    for(int i=0;i<structures.size();i++)
        structnames.append(structures[i].to_QString());
    for(int i=0;i<classes.size();i++)
        classnames.append(classes[i].to_QString());

    QString structpattern = "\\b(" + structnames.join("|") + ")\\s*[\\w_]+\\s*(\\([\\w,]*\\))*(,)*" ;
    QString classpattern = "\\b(" + classnames.join("|") + ")\\s*[\\w_]+\\s*(\\([\\w,]*\\))*(,)*" ;

    //QString pattern = "\\b(" + structnames.join("|") + ")\\s+\\w+\\s*=\\s*\\{[^{}]*\\}";
    QRegularExpression expr(structpattern);
    QRegularExpression _expr(classpattern);

    QString code = list.join("\n");

    if(!structnames.empty())
    {
    QRegularExpressionMatchIterator it = expr.globalMatch(code);
    while (it.hasNext())
    {
    QRegularExpressionMatch match = it.next();
    int i = code.left(match.capturedStart()).count("\n");
    initStructAmount++;
    initStructAmount+=list[i].count(",");
    }

    }

    if(!classnames.empty())
    {
    QRegularExpressionMatchIterator _it = _expr.globalMatch(code);
    while (_it.hasNext())
    {
    QRegularExpressionMatch match = _it.next();
    int i = code.left(match.capturedStart()).count("\n");
    initClassAmount++;
    initStructAmount+=list[i].count(",");
    }

    }
    QRegularExpression regex("\\b(\\w+)\\s+\\w+\\s*(?:\\[(?:[^\\]]|\\[[^\\]]*\\])*\\]\\s*)+=\\s*\\{(?:[^{}]|\\{(?:[^{}]|\\{[^{}]*\\})*\\})*\\}");

    QRegularExpressionMatchIterator __it = regex.globalMatch(code);
    while (__it.hasNext()) {
    QRegularExpressionMatch match = __it.next();
        initArrAmount++;
    }
    qDebug()<<"struct"<<QString::number(structAmount)<<"class"<<QString::number(classesAmount);

    std::vector <String> arrays;
    std::vector <String> dynamicArrays;

    std::regex regularArr ("(\\bint\\b|\\blong\\b|\\bdouble\\b|\\bshort\\b|\\blong long\\b|\\blong double\\b|\\buint\\b|\\bchar\\b|\\bstring\\b|\\bfloat\\b|\\bbool\\b)"
                           "\\s*([\\w_]+)\\s*(\\[\\w*]){1,}");
    std::regex regularDynamic("(\\bint\\b|\\blong\\b|\\bdouble\\b|\\bshort\\b|\\blong long\\b|\\blong double\\b|\\buint\\b|\\bchar\\b|\\bstring\\b|\\bfloat\\b|\\bbool\\b)"
                              "\\s*(\\*){0,}\\s*(\\*){0,}([\\w_]+)\\s*(=)\\s*(\\*){0,}(\\bnew\\b)\\s*(\\bint\\b|\\blong\\b|\\bdouble\\b)(\\*){0,}\\s*([\\[\\w+]+])+");
    for(int i=0;i<list.size();i++)
    {
        std::cmatch result;
        String code = String::fromQString(list[i]);
        if(std::regex_search(code.c_str(),result,regularArr))
        {
            arrays.push_back(String::fromStdString(result[2]));
            arrAmount++;
        }
    }

    for(int i=0;i<list.size();i++)
    {
        std::cmatch result;
        String code = String::fromQString(list[i]);
        if(std::regex_search(code.c_str(),result,regularDynamic))
        {
            arrAmount++;
            dynamicArrays.push_back(String::fromStdString(result[2]));
        }
    }

    qDebug()<<QString::number(arrAmount);
    //ui->labelTab3->setText(QString::number(arrAmount));
    ans += String("Classes amount : ");
    ans += String::fromQString(QString::number(classesAmount));
    ans += String("\n");
    ans += String("Structures amount : ");
    ans += String::fromQString(QString::number(structAmount));
    ans += String("\n");
    ans += String("Arrays amount : ");
    ans += String::fromQString(QString::number(arrAmount));
    ans += String("\n");
    ans += String("Initialised arrays amount : ");
    ans += String::fromQString(QString::number(initArrAmount));
    ans += String("\n");
    ans += String("Initialised classes amount : ");
    ans += String::fromQString(QString::number(initClassAmount));
    ans += String("\n");
    ans += String("Initialised structures amount : ");
    ans += String::fromQString(QString::number(initStructAmount));
    ans += String("\n");
    return ans.to_QString();
}

QString MainWindow::getFuncs(QStringList& list)
{
    size_t funcAmount = 0;
    size_t row = 1,column = 0;
    functions.clear();
    nameOfFunctions.clear();

    std::regex regularFuncs("(\\bvoid\\b|\\bint\\b|\\blong\\b|\\bdouble\\b|\\bshort\\b|\\blong long\\b|\\blong double\\b|\\buint\\b|char\\*|\\bchar\\b|\\bstring\\b|\\bfloat\\b|\\bbool\\b)"
                            "\\&?\\*?\\s*(([\\:\\<\\>\\w_-]+)(\\()(.*)*(\\)))");
                            //"\\s*(([\\:\\<\\>\\w_-]+)(\\()([\\w_\\-,*\\[\\]&\\s*]+)*(\\)))"); //??
    //std::regex regularFuncs("(int|double|long|size_t|std::string|float|bool|char|char\\*|short|long long|void)""(\\s*\\**\\s*)""([\\w-]+)""(( )*)""(\\()""(( )*(int|double|long|size_t|std::string|float|bool|char|char\\*|short|long long|void)(( )*\\**( )*([\\w-])*)*(,)*)*""(\\))");
    for(int i=0;i<list.size();i++)
    {
        std::cmatch result;
        String code = String::fromQString(list[i]);
        if(std::regex_search(code.c_str(),result,regularFuncs))
        {
            for(int i=0;i<result.size();i++) qDebug()<<result[i];
            column=result.position();
            //QString result3 = QString::fromStdString(result[2]).section("::",1,1);
            //qDebug()<<"mamapapa"<<result3;
            functions.push_back(std::make_pair(String::fromStdString(result[0]),std::make_pair(row,column)));
            funcAmount++;
            nameOfFunctions.push_back(std::make_pair(result[3],std::make_pair(row,column)));
            //qDebug()<<"name of func"<<QString::fromStdString(result[3]);
        }
        row++;
    }

    qDebug()<<"funcAmount:TODAYIAMGAY"<<QString::number(funcAmount);
    String prototypes = "Function prototypes :\n";
    for(int i=0;i<functions.size();i++)
    {
        prototypes+=functions[i].first;
        prototypes+=String("\n");
    }
    return prototypes.to_QString();
}

QString MainWindow::getErrors(QStringList& list)
{
    std::regex if_errors("(\\bif\\b)\\s*\\((\\btrue\\b|\\bfalse\\b|\\d+)\\)\\s*");
    std::regex while_errors("(\\bwhile\\b)\\s*\\((\\btrue\\b|\\bfalse\\b|\\d+)\\)\\s*");
    std::regex const_bool_errors("(\\bconst bool\\b)\\s*[\\w]*\\s*(=)\\s*(\\btrue\\b|\\bfalse\\b);");
    std::regex switch_errors("(\\bswitch\\b)\\s*\\((\\btrue\\b|\\bfalse\\b|\\d+)\\)");
    std::smatch result;

    String ans = String("Logical Errors :\n----------------------------\n");
    QTextCursor cursor(ui->textEdit->document());
    QTextCharFormat format;
    format.setBackground(QColor(255,69,0));

    for (int i = 0; i < ui->textEdit->document()->blockCount(); i++) {
        QTextBlock block = ui->textEdit->document()->findBlockByNumber(i);
        String blockText = String::fromQString(block.text());
        std::string blockString = blockText.to_std_string();

        if (std::regex_search(blockString, result, if_errors)) {
            cursor.setPosition(block.position() + result.position());
            cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, result.length());
            cursor.setCharFormat(format);
            ans+=String::fromStdString(result[0]);
            ans+="\n";
            effect->setColor(Qt::red);
            ui->textEdit->setGraphicsEffect(effect);
        }

        if (std::regex_search(blockString, result, while_errors)) {
            cursor.setPosition(block.position() + result.position());
            cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, result.length());
            cursor.setCharFormat(format);
            ans+=String::fromStdString(result[0]);
            ans+="\n";
            effect->setColor(Qt::red);
            ui->textEdit->setGraphicsEffect(effect);
        }

        if (std::regex_search(blockString, result, const_bool_errors)) {
            cursor.setPosition(block.position() + result.position());
            cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, result.length());
            cursor.setCharFormat(format);
            ans+=String::fromStdString(result[0]);
            ans+="\n";
            effect->setColor(Qt::red);
            ui->textEdit->setGraphicsEffect(effect);
        }

        if (std::regex_search(blockString, result, switch_errors)) {
            cursor.setPosition(block.position() + result.position());
            cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, result.length());
            cursor.setCharFormat(format);
            ans+=String::fromStdString(result[0]);
            ans+="\n";
            effect->setColor(Qt::red);
            ui->textEdit->setGraphicsEffect(effect);
        }
    }

    return ans.to_QString();
}

QString MainWindow::getVarChanges(QStringList& list)
{
    String temp;
    String changes = "----------------------------\nCoordinates of variable changes:";
    std::vector<std::pair<size_t,size_t>> coords;
    //size_t row=0,column=0;

    //std::regex varChanges("[\\};]\\s*(([\\*]*\\s*)?\\w+(\\[\\w+\\])?\\s*?(([+|-|^|*|\\/|&|\\|]?=)|\\++|--))");
    //std::regex varChanges("[\\w]+(([+|-|^|*|\\/|&|\\||%]?=)|\\++|--)");
    std::regex varChanges("((\\++|\\--)|([\\w]+\\s*=?\\s*[\\w]*(\\+|\\-|\\*|\\^|\\||\\/|\\%)=)|([\\w\\[\\]\\*]+\\s*=\\s*[\\d]+))");

//    std::regex varChanges("(^.)\\s*(((\\++)|(\\--))(\\*)?(\\w*)(\\[\\d*\\])?|(\\w*\\s*\\=\\s*"
//                          "(\\++|\\--)?(\\*)?(\\w*)(\\[\\d*\\])?\\s*((\\+|\\-|\\*|\\/|\\^|\\%|\\++|\\--)"
//                          "\\s*((\\*)?(\\w*)(\\[\\d*\\])?)?)?|((\\*)?(\\w*)(\\[\\d*\\])?(\\++|\\--))))\\;");
    std::cmatch result;

    for(int i=0;i<list.size();i++)
    {
    String tmp = String::fromQString(list[i]);

    if(std::regex_search(tmp.c_str(), result, varChanges))
    {
        qDebug()<<"changed";
        qDebug()<<result[0];
        coords.push_back(std::make_pair(i+1,result.position()));
    }
    }

    for(int i=0;i<coords.size();i++)
    {
        changes += String("\nCoordinates : ");
        changes += String::fromQString(QString::number(coords[i].first));
        changes += String(" ,");
        changes += String::fromQString(QString::number(coords[i].second));
    }
    return changes.to_QString();
}

QString MainWindow::getLocalVars(QStringList& code)
{
    std::stack <char> brackets;
    std::vector <String> local;
    std::vector<std::pair<size_t,size_t>> cords;
    std::regex localVars("(\\bint\\b|\\buint\\b|\\bunsigned int\\b|\\bdouble\\b|\\blong\\b|\\bsize_t\\b|\\bfloat\\b|\\bbool\\b|\\bshort\\b|\\blong long\\b|\\bvoid\\b|\\blong double\\b)"
                         "\\s*(([\\w_]+)\\s*(=)?\\s*(([0-9]*)|[\\w_+-]*)\\s*((,\\s*)|(;)))+");
    std::cmatch result;

    int localCount=0;
    String ans;


    for(int i=0;i<code.size();i++)
    {
        String str = String::fromQString(code[i]);
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='{')
            {
                brackets.push('}');
                if(!brackets.empty())
                {
                    if (std::regex_search(str.c_str(),result, localVars))
                    {
                        localCount++;

                        cords.push_back(std::make_pair(i+1,result.position()));
                        qDebug()<<"pos"<<QString::number(result.position());
                    }

                }
            }
            if(str[i]=='}')
            {
                if(!brackets.empty())
                    brackets.pop();
            }
        }

        if(!brackets.empty())
        {
            if (std::regex_search(str.c_str(),result, localVars))
            {
                localCount++;
                cords.push_back(std::make_pair(i+1,result.position()));
            }
        }
    }

    for(int i=0;i<cords.size();i++)
    {
        ans+=String("Coordinates : ");
        ans+=String::fromQString(QString::number(cords[i].first));
        ans+=String(", ");
        ans+=String::fromQString(QString::number(cords[i].second));
        ans+=String("\n");
    }
    String tmp;
    tmp+=String("Amount of local variables : ");
    tmp+=String::fromQString(QString::number(localCount));
    tmp+=String("\n----------------------------\n");
    tmp+=ans;
    ans=tmp;
    return ans.to_QString();
}

int getLine(int position, const QTextDocument* doc) {
    return doc->findBlock(position).blockNumber() + 1;
}

int getColumn(int position, const QTextDocument* doc) {
    QTextBlock block = doc->findBlock(position);
    return position - block.position() + 1;
}

QString MainWindow::getOverloadFuncs(QStringList& code)
{
    QStringList overloadFuncs;
    String ans;
    size_t overloadAmount = 0;
    std::map<std::string,int> itemsCount;

    for(int i=0;i<nameOfFunctions.size();i++)
    {
        std::string item = nameOfFunctions[i].first;
        ++itemsCount[item];
    }

    for(auto item : itemsCount)
    {
        if(item.second>1)
        {
            overloadAmount+=item.second;
            overloadFuncs.push_back(QString::fromStdString(item.first));
        }
    }

    qDebug()<<QString::number(functions.size())<<"functions";

    std::sort(overloadFuncs.begin(),overloadFuncs.begin()+overloadFuncs.size());
    std::sort(nameOfFunctions.begin(),nameOfFunctions.begin()+nameOfFunctions.size());

    ans += String("Amount of overloaded functions : ") ;
    ans += String::fromQString(QString::number(overloadAmount));
    ans += String("\n--------------------------------\n");
    ans += String("Coordinates of overloaded functions:\n");
    for(int i=0;i<overloadFuncs.size();i++)
    {
        for(int j=0;j<nameOfFunctions.size();j++)
        {
            if(overloadFuncs[i]==QString::fromStdString(nameOfFunctions[j].first))
            {
                ans+= String("Coordinates : ");
                ans+= String::fromQString(QString::number(nameOfFunctions[j].second.first));
                ans+= String(", ");
                ans+= String::fromQString(QString::number(nameOfFunctions[j].second.second));
                ans+=String("\n");
            }
        }
    }

    qDebug()<<QString::number(overloadAmount);
    //qDebug()<<ans;
    return ans.to_QString();
}

QString MainWindow::getDepth(QString& list)
{
    int deep = 0;
    int max_depth = 0;
    int row = 0;
    int column = 0;
    QString ans = "\n";

    QTextCursor cursor(ui->textEdit->document());

    for(int i = 0; i < list.size(); i++)
    {
        if(list[i] == '\n')
        {
            row++;
            column = 0;
        }
        if(list[i] == '{')
        {
            for(int j = i; j < list.size(); j++)
            {
                if(list[j] == '{')
                    deep++;
                if(list[j] == '}')
                    deep--;
                if(deep > max_depth) {
                    max_depth = deep;
                    column = j;
                }
                if(deep == 0)
                {
                    ans += "Координаты ветвления " + QString::number(row) + ", " + QString::number(column) + ", глубина ветвления: " + QString::number(max_depth) + '\n';
                    //cursor.setPosition(ui->textEdit->document()->findBlockByNumber(row - 1).position() + column);
                    //ui->textEdit->setTextCursor(cursor);
                    //ui->textEdit->insertPlainText(" max_depth=" + QString::number(max_depth));
                    max_depth = 0;
                    break;
                }
            }
        }
    }
    return ans;
}

void MainWindow::clearAllTabs()
{
    ui->Tab1TextEdit->clear();
    ui->Tab2TextEdit->clear();
    ui->Tab3TextEdit->clear();
    ui->Tab4TextEdit->clear();
    ui->Tab5TextEdit->clear();
}
