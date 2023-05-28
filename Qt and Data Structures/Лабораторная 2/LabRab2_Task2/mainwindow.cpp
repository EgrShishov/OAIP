#include "mainwindow.h"
#include "ui_mainwindow.h"

QString filename;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ui->pushButton->setStyleSheet("* { background-color: rgb(65,105,225) }");
    ui->textEdit->setToolTip("Вы можете ввести ваш текст вручную в это окошко");
}

MainWindow::~MainWindow()
{
    delete ui;
}

struct position
{
  unsigned long long x;
  unsigned long long y;
};

void MainWindow::on_pushButton_clicked() //проверка
{
    QString Text = ui->textEdit->toPlainText();
    QTextCursor cursor = ui->textEdit->textCursor();

    Stack <QChar> stack;

        struct Position
        {
            int x = 0;
            int y = 0;
            int i = 0;
        };

        //Stack<char> stack;
        Stack<Position> pos;
        Position _pos;

        int row = 1, column = 0;

        for(int i=0;i<Text.size();i++)
        {

            cursor.setPosition(i,QTextCursor::MoveAnchor);
            QChar ch = Text[i];
            if(ch=='\n')
            {
             row++;
             column=0;
            } else column++;

            if(Text[i]=='(' || Text[i]=='{' || Text[i]=='[')
            {
                stack.push(Text[i]);
                _pos.x=row;
                _pos.y=column;
                _pos.i=i;
                pos.push(_pos);
                continue;
            }

            if(Text[i]==')' && stack.pop()!='(')
            {
                QString text = "<font color=\"red\"><p>)</p></font>";
                cursor.deleteChar();
                cursor.insertHtml(text);
                ui->textEdit->setTextColor(Qt::black);
                QMessageBox::critical(this,tr("Ошибка"),"Ошибка, не хватает открывающей скобки  '(' в строке с координатами " + QString::number(row) + ", " + QString::number(column));
                return;
            }

            if(Text[i]==']' && stack.pop()!='[')
            {
                QString text = "<font color=\"red\"><p>]</p></font>";
                cursor.deleteChar();
                cursor.insertHtml(text);
                ui->textEdit->setTextColor(Qt::black);
                QMessageBox::critical(this,tr("Ошибка"),"Ошибка, не хватает открывающей скобки  '[' в строке с координатами " + QString::number(row) + ", " + QString::number(column));
                return;
            }

            if(Text[i]=='}' && stack.pop()!='{')
            {
                QString text = "<font color=\"red\"><p>}</p></font>";
                cursor.deleteChar();
                cursor.insertHtml(text);
                ui->textEdit->setTextColor(Qt::black);
                QMessageBox::critical(this,tr("Ошибка"),"Ошибка, не хватает открывающей скобки  '{' в строке с координатами " + QString::number(row) + ", " + QString::number(column));
                return;
            }

            if(Text[i]=='}' || Text[i]==']' || Text[i]==')')
            {
                pos.pop();
            }


}

        if(stack.isEmpty())
        {
            ui->textEdit->setTextColor(Qt::black);
            ui->textEdit->setText(ui->textEdit->toPlainText());
            QMessageBox::information(this,tr("Информация"),"Ошибок не обнаружено!");
            return;
        }
        else
        {
                while(pos.size()!=1)
                {
                    pos.pop();
                    stack.pop();
                }
                _pos = pos.pop();
                QChar ch = stack.pop();
                int x = _pos.x;
                int y = _pos.y;
                int i = _pos.i;

                QString text;
                cursor.setPosition(i,QTextCursor::MoveAnchor);
                if(ch=='(')
                text = "<font color=\"red\"><p>(</p></font color>";
                else if(ch=='[')
                text = "<font color=\"red\"><p>[</p></font color>";
                else if(ch=='{')
                text = "<font color=\"red\"><p>{</p></font color>";

                cursor.deleteChar();
                cursor.insertHtml(text);
                ui->textEdit->setTextColor(Qt::black);
                QMessageBox::critical(this,tr("Ошибка"),"Ошибка, не хватает закрывающей скобки в строке с координатами " + QString::number(x) + ", " + QString::number(y));
                return;
        }

}


void MainWindow::on_action_triggered()
{
    qDebug()<<"aboba";
    filename = QFileDialog::getOpenFileName(this,"Откройте файл","D://","Text File (*.txt);;cpp File(*.cpp)");
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QMessageBox::warning(this,("Ошибка открытия файла"),tr("Файл не удалось открыть"));
    }

    QTextStream text(&file);
    QString info = text.readAll();

    ui->textEdit->setText(info);
}

