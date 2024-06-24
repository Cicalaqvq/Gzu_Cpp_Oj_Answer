// 有一个类Base及其公有派生类Derived1、Derived2、Derived3。类Base和main函数的代码已经完成，请根据已有的代码给出上述三个派生类的设计。（只需要提交这三个类的代码）
// 程序的开头部分如下：
#include <iostream>
using namespace std;
class Base{
    int x,y;
public:
    Base(int a,int b):x(a),y(b){}
    int getX()const{return x;}
    int getY()const{return y;}
    virtual void calculate()=0;
};
//答题区:
class Derived1:public Base
{
    int z;
    public:
    Derived1(int a,int b,int c):Base(a,b),z(c){};
    void calculate()
    {
        int x=getX();
        int y=getY();
        cout<<"三个数的和是"<<x+y+z<<endl;
    }
};
class Derived2:public Base
{
    int z;
    public:
    Derived2(int a,int b,int c):Base(a,b),z(c){};
    void calculate()
    {
        int x=getX();
        int y=getY();
        cout<<"三个数的积是"<<x*y*z<<endl;
    }
};
class Derived3:public Base
{
    int z;
    public:
    Derived3(int a,int b,int c):Base(a,b),z(c){};
    void calculate()
    {
        int x=getX();
        int y=getY();
        cout<<"前两个数的和与第三个数的积是"<<(x+y)*z<<endl;
    }
};
// main函数的代码如下：
int main(){
    Base *p;
    Derived1 o1(1,2,3);
    Derived2 o2(4,5,6);
    Derived3 o3(7,8,9);
    p=&o1;
    p->calculate();
    p=&o2;
    p->calculate();
    p=&o3;
    p->calculate();
    return 0;
}

