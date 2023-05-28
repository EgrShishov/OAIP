#include "reversepolishnotation.h"

bool divisionByZero = false;
ReversePolishNotation::ReversePolishNotation()
{

}

ReversePolishNotation::ReversePolishNotation(const QString input)
{
  expression=input;
}

bool ReversePolishNotation::isOperand(QChar ch)
{
    bool is = false;
    if(ch>='a' && ch<='e')
        is=true;
    return is;
}

bool ReversePolishNotation::isOperation(QChar ch)
{
    bool is = false;
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
        is = true;
    return is;
}

int ReversePolishNotation::priority(QChar ch)
{
   if(ch=='(') return 1;
   else if(ch=='+' || ch=='-') return 2;
   else if(ch=='*' || ch=='/') return 3;
}

bool ReversePolishNotation::checkEnt(QString input)
{

        int count = 0;
        int opCount=0,operCount=0;
        //if(input[0]=='-' && input.size()==2) return false;
        if (input.size() > 255) return true;
        for (int i = 0; i < input.size(); ++i) {
            if(input[i].isDigit()) return true;
            if(input[i]=='/' || input[i]=='*' || input[i]=='+' || input[i]=='-')
                operCount++;
            if(input[i]<='e' && input[i]>='a') opCount++;

            if (i + 1 != input.size() && input[i].isLetter() && input[i + 1].isLetter()){
                return true;
            }
            if (i + 1 != input.size() && isOperation(input[i]) && isOperation(input[i + 1]) && (input[i + 1] == ')' && input[i + 1] != ')')){
                return true;
            }
            if (input[i] == '(') ++count;
            if (input[i] == ')') --count;
            if (input[i].isLetter() && !isOperand(input[i])) return true;
            if (count < 0) return true;
        }
        if (count != 0) return true;
        if(opCount-operCount!=1) return true;
        return false;
}

QString ReversePolishNotation::convertionToRPN()
{
   QString ans="";
   QString expr=expression;
   qDebug()<<checkEnt(expr);
   qDebug()<<expr;
   Stack <QChar> aboba;

   for(int i=0;expr[i]!='\n';i++)
   {
     QChar ch = expr[i];
     //qDebug()<<ch;
     if(isOperand(ch))
     {
         ans+=ch;
     }
     if(ch=='(')
         aboba.push(ch);
     if(ch==')')
     {
        while(aboba.top()!='(')
        {
            ans+=aboba.top();
            aboba.pop();
        }
        aboba.pop();
     }

     if(isOperation(ch))
     {
         if(aboba.isEmpty() || priority(aboba.top())<priority(ch))
             aboba.push(ch);
         else
         {
             while(!aboba.isEmpty() && (priority(aboba.top())>=priority(ch)))
             {
                 ans+=aboba.top();
                 aboba.pop();
             }
             aboba.push(ch);
         }
     }

   }

   while(!aboba.isEmpty())
   {
       ans+=aboba.top();
       aboba.pop();
   }
   //ans+=aboba.top();
   //aboba.pop();
   //qDebug()<<ans;
   return ans;
}


double ReversePolishNotation::calculation(QString expression,double a,double b,double c,double d,double e)
{
    Stack <double> aboba;
    double leftOp=0,rightOp=0;
    double ans=0;
    QChar ch,ch1,ch2;
    double arr[5] = {a,b,c,d,e};
    qDebug()<<a<<b<<c<<d<<e;
    QChar xyz[5] = {'a','b','c','d','e'};
   for(int i=0;i<expression.size();i++)
   {
       //qDebug()<<expression[i];
       ch=expression[i];
       if(isOperand(ch))
       {
           for(int i=0;i<5;i++)
           {
               if(ch==xyz[i])
               {
               aboba.push(arr[i]);
               break;
               }
           }
       }
       else
       {
           if(isOperation(ch))
           {
           leftOp=aboba.top();
           aboba.pop();
           rightOp=aboba.top();
           aboba.pop();
           //qDebug()<<leftOp;
           //qDebug()<<rightOp;

           if(ch=='+')
           {
               aboba.push(leftOp+rightOp);
           }
           else if(ch=='-')
           {
               aboba.push(rightOp-leftOp);
           }
           else if(ch=='*')
           {
               aboba.push(leftOp*rightOp);
           }
           else if (ch=='/')
           {
               if(leftOp!=0)
                aboba.push(rightOp/leftOp);
               else
               {
                   divisionByZero=true;
                   break;
               }
           }

        }
       }

    }

   ans = aboba.pop();
   return ans;
}
