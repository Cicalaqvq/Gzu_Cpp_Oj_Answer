// 有一个类A及其公有派生类B、C、D。类A和main函数的代码已经完成，请根据已有的代码给出上述三个派生类的设计。
// （只需要提交这三个类的代码）
// 程序的开头部分如下：
#include <iostream>
using namespace std;
class A{
    int x,y;
public:
    A(int a,int b):x(a),y(b){}
    int getX()const{return x;}
    int getY()const{return y;}
    virtual void doSomething()=0;
};
//答题区：
class B:public A
{
    public:
    B(int a,int b):A(a,b){};
    void doSomething()
    {
        cout<<"x和y的和是"<<getX()+getY()<<endl;
    }
};
class C:public A
{
    public:
    C(int a,int b):A(a,b){};
    void doSomething()
    {
      cout<<"x和y的差是"<<getX()-getY()<<endl;  
    }
};
class D:public A
{
    public:
    D(int a,int b):A(a,b){};
    void doSomething()
    {
        cout<<"x和y的积是"<<getX()*getY()<<endl;
    }
};
// main函数的代码如下：
int main(){
    A *ap;
    B b(1,2);
    C c(3,4);
    D d(5,6);
    ap=&b;
    ap->doSomething();
    ap=&c;
    ap->doSomething();
    ap=&d;
    ap->doSomething();
    return 0;
}