#include <iostream>

using namespace std;

class Expression
{
public:
    virtual ~Expression(){}
    virtual double evaluate() const = 0;
private:
};

class Number : public Expression
{
public:
    Number(double value)
        : value(value)
    {

    }

    double evaluate() const
    {
        return this->value;
    }

private:
    double value;
};

class BinaryOperation : public Expression
{
public:
    double evaluate() const
    {
        if(this->operand=='+')
        {
            return this->left->evaluate()+this->right->evaluate();
        }
        else if (this->operand=='-')
        {
            return this->left->evaluate()-this->right->evaluate();
        }
        else if(this->operand=='*')
        {
            return this->left->evaluate()*this->right->evaluate();
        }
        else if(this->operand=='/' && this->right->evaluate()!=0)
        {
            return this->left->evaluate()/this->right->evaluate();
        }
        else
        {
           return -1;
        }
    }

    BinaryOperation(Expression* left,char operand,Expression* right)
        : left(left),operand(operand),right(right)
    {

    }

    ~BinaryOperation()
    {
        delete this->left;
        delete this->right;
    }

private:
    Expression* left;
    Expression* right;
    char operand;
};


bool check_equals(Expression const* left, Expression const* right)
{
    return (*(void**)left) == (*(void**)right); //????
}

int main()
{
    Expression* sube = new BinaryOperation(new BinaryOperation(new Number(4.5),'*',new Number(5)),'*',new Number(5));    //Expression* expr=new BinaryOperation((new Number(3.3244),'+',new Number(4.5)),'*',new Number(5.22));
    Expression* del=new BinaryOperation(new Number(7.777),'/',((new Number(3.3244),'+',new Number(4.5)),'*',new Number(5.22)));
    Expression* minus=new BinaryOperation(new Number(2.28),'-',(new Number(7.777),'/',((new Number(3.3244),'+',new Number(4.5)),'*',new Number(5.22))));
    Expression* num=new Number(4141);
    cout<<sube->evaluate()<<endl;
    check_equals(sube,del)? cout<<"true\n" : cout<<"false\n";
    check_equals(sube,num)? cout<<"true\n" : cout<<"false\n";
    delete num;
    delete sube;
    return 0;
}
