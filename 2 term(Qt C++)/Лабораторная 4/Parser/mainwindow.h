#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include "stringdll.h"
#include <QString>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <regex>
#include <QTextCursor>
#include <QTextDocument>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>
#include <QTextBlock>
#include <QStack>
#include <QTextCharFormat>
#include <QTextEdit>
#include <QGraphicsDropShadowEffect>

struct Block {
    int depth;
    int startLine;
    int endLine;
};
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_triggered();

    void on_pushButton_clicked();

private:
    QString getAmountOfVariables(QStringList& data);

    QString getClasses(QStringList& data);

    QString getFuncs(QStringList& data);

    QString getErrors(QStringList& data);

    QString getVarChanges(QStringList& list);

    QString getLocalVars(QStringList& data);

    QString getOverloadFuncs(QStringList& data);

    QString getDepth(QString& list);

    void clearAllTabs();

private:
    Ui::MainWindow *ui;
    std::vector<std::pair<String,std::pair<size_t,size_t>>> functions;
    std::vector<std::pair<std::string,std::pair<size_t,size_t>>> nameOfFunctions;

    //std::vector<std::string> functions;
    QString filename;
    QTextDocument* doc;
    QGraphicsDropShadowEffect* effect;
};
#endif // MAINWINDOW_H
