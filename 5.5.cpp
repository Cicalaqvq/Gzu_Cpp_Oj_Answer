// 有一个类One及其公有派生类Two、Three、Four。类One和main函数的代码已经完成，请根据已有的代码给出上述三个派生类的设计。（只需要提交这三个类的代码）
// 程序的开始部分代码如下：
#include <iostream>
using namespace std;
class One{
    int a,b,c;
public:
    One(int a,int b,int c):a(a),b(b),c(c){}
    int getA()const{return a;}
    int getB()const{return b;}
    int getC()const{return c;}
    virtual void getResult()=0;
};
//答题区
class Two:public One
{
    public:
    Two(int a,int b,int c):One(a,b,c){};
    void getResult()
    {
        cout<<"三个数的和是"<<getA()+getB()+getC()<<endl;
    }
};
class Three:public One
{
    public:
    Three(int a,int b,int c):One(a,b,c){};
    void getResult()
    {
        cout<<"三个数的积是"<<getA()*getB()*getC()<<endl;
    }
};
class Four:public One
{
    public:
    Four(int a,int b,int c):One(a,b,c){};
    void getResult()
    {
        cout<<"前两个数的和与第三个数的积是"<<(getA()+getB())*getC()<<endl;
    }
};
// main函数的代码如下：
int main(){
    One *p;
    Two o1(1,2,3);
    Three o2(4,5,6);
    Four o3(7,8,9);
    p=&o1;
    p->getResult();
    p=&o2;
    p->getResult();
    p=&o3;
    p->getResult();
    return 0;
}

