#include "model.h"

int priortyMatrix[7][7] =
{
    {1, 1, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0, 2, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 2}
};//+, -, *, /, (, ), #

Model::Model()
{
}

void Model::add2nd(double nd)
{
    OPND * ndnode = new OPND;
    ndnode->nd = nd;
    ndnode->next = NULL;
    if(this->opnd == NULL)
        this->opnd = ndnode;
    else
    {
        OPND * p = this->opnd;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ndnode;
    }
}

void Model::add2tr(int tr)
{
    OPTR * trnode = new OPTR;
    trnode->tr = tr;
    trnode->next = NULL;
    if(this->optr == NULL)
        this->optr = trnode;
    else
    {
        OPTR * p = this->optr;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = trnode;
    }
}

double Model::getnd()
{
    if(this->opnd == NULL)
        return 0;
    OPND * p = this->opnd;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p->nd;
}

int Model::gettr()
{
    if(this->optr == NULL)
        return 0;
    OPTR * p = this->optr;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p->tr;
}

void Model::delnd()
{
    if(this->opnd == NULL)
        return;
    OPND * p = this->opnd;
    if(p->next == NULL)
    {
        delete p;
        this->opnd = NULL;
        return;
    }
    OPND * prep = p;
    while (p->next != NULL)
    {
        prep = p;
        p = p->next;
    }
    prep->next = NULL;
    delete p;
}

void Model::deltr()
{
    if(this->optr == NULL)
        return;
    OPTR * p = this->optr;
    if(p->next == NULL)
    {
        delete p;
        this->optr = NULL;
        return;
    }
    OPTR * prep = p;
    while (p->next != NULL)
    {
        prep = p;
        p = p->next;
    }
    prep->next = NULL;
    delete p;
}

QString Model::calculate(QString str)
{
    this->opnd = NULL;
    this->optr = NULL;
    str = str + '#';
    int i = 0;
    this->add2tr(7);
    QChar currentChar = str[0];
    for(; currentChar != '#'; i++)
    {
        currentChar = str[i];
        if(currentChar.isNumber())
        {
            int numberStartIndex = i;
            int count = 1;
            while(str[i + 1].isNumber())
            {
                count++;
                i++;
            }
            if(str[i + 1] == '.')
            {
                i++;
                count++;
                while(str[i + 1].isNumber())
                {
                    count++;
                    i++;
                }
            }
            add2nd(str.mid(numberStartIndex, count).toDouble());
        }
        else
        {
            int priority = 0;
            switch (currentChar.toLatin1()) {
            case '+':
                priority = 1;
                break;
            case '-':
                priority = 2;
                break;
            case '*':
                priority = 3;
                break;
            case '/':
                priority = 4;
                break;
            case '(':
                priority = 5;
                break;
            case ')':
                priority = 6;
                break;
            case '#':
                priority = 7;
                break;
            }

            while(true)
            {
                if(priortyMatrix[this->gettr() - 1][priority - 1] == 0)
                {
                    this->add2tr(priority);
                    break;
                }
                else if(priortyMatrix[this->gettr() - 1][priority - 1] == 2)
                {
                    this->deltr();
                    break;
                }
                else
                {
                    double number2 = this->getnd();
                    this->delnd();
                    double number1 = this->getnd();
                    this->delnd();
                    switch (this->gettr()) {
                    case 1:
                        this->add2nd(number1 + number2);
                        break;
                    case 2:
                        this->add2nd(number1 - number2);
                        break;
                    case 3:
                        this->add2nd(number1 * number2);
                        break;
                    case 4:
                        if(number2 > -0.000000000000000001 && number2 < 0.000000000000000001)
                            return "ERROR";
                        this->add2nd(number1 / number2);
                        break;
                    }
                    this->deltr();
                }
            }
        }
    }
    QString result = QString::number(this->getnd());
    this->delnd();
    return result;
}

