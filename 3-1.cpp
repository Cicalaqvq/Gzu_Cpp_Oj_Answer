/*有两个类Base1和Base2和它们的共同子类Derived。现在Base1、Base2和main函数的代码已经完成。请根据已有的代码完成类Derived的设计。（只需要提交类Derived的代码）*/
#include <iostream>
using namespace std;

class Base1{
    int a;
public:
    Base1(int a):a(a){
        cout<<"Base1 Constructed "<<a<<endl;
    }
    void doSomething(){
        cout<<"Hi Base1"<<endl;
    }

};

class Base2{
    int b;
public:
    Base2(int b):b(b){
        cout<<"Base2 Constructed "<<b<<endl;
    }
    void doSomething(){
        cout<<"Hi Base2"<<endl;
    }
};
class Derived
{
    private:
    int d;
    Base1 b1,*b2;
    Base2 b3,*b4;
    public:
    Derived(int a,int b,int c,int d,int e):b1(d),b3(a)
    {
        b2=new Base1(c);
        b4=new Base2(b);
        this->d=e;
        cout<<"Derived Constructed "<<this->d<<endl;
    }
    void doSomething()
    {
        b1.doSomething();
        b3.doSomething();
        cout<<"Hi Derived"<<endl;
    }
};
int main(){
    Derived derived(1,2,3,4,5);
    derived.doSomething();
    return 0;

}
/*输出描述
Base1 Constructed 4
Base2 Constructed 1
Base1 Constructed 3
Base2 Constructed 2
Derived Constructed 5
Hi Base1
Hi Base2
Hi Derived*/