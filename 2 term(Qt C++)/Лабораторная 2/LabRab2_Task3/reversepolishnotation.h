#ifndef REVERSEPOLISHNOTATION_H
#define REVERSEPOLISHNOTATION_H
#include <QString>
#include <iostream>
#include <QMessageBox>
#include <QDebug>
#include "stack.h"
class ReversePolishNotation
{
public:
    ReversePolishNotation();
    ReversePolishNotation(const QString input);

    bool isOperation(QChar ch);
    bool isOperand(QChar ch);
    int priority(QChar ch);
    QString convertionToRPN();
    double calculation(QString expression,double a,double b,double c,double d,double e);
    bool checkEnt(QString line);

private:
QString expression;
};

#endif // REVERSEPOLISHNOTATION_H
