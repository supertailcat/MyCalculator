#ifndef MODEL_H
#define MODEL_H
#include <QString>

using namespace std;
class Model
{
    struct OPND
    {
        double nd;
        OPND * next;
    };

    struct OPTR
    {
        int tr;
        OPTR * next;
    };

public:
    Model();
    QString calculate(QString str);
private:
    OPND * opnd;
    OPTR * optr;
    void add2nd(double nd);
    void add2tr(int tr);
    double getnd();
    int gettr();
    void delnd();
    void deltr();
};

#endif // MODEL_H
