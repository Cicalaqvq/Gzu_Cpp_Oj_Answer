/*​有三个基类A、B、C以及它们的派生类D。
请根据下面关于D类的代码和main函数的代码，结合输入输出关系，将A、B、C类的代码补充完整：*/
#include <iostream>
#include <string>
using namespace std;
class A
{
    private:
    int a,b;
    public:
    A(int a,int b):a(a),b(b){};
    int getX()
    {
        return a;
    }
    int getY()
    {
        return b;
    }
};
class B
{
    private:
    int a,b;
    public:
    B(int a,int b):a(a),b(b){};
    int getX()
    {
        return a;
    }
    int getA()
    {
        return b;
    }
};
class C
{
    private:
    int a,b;
    public:
    C(int a,int b):a(a),b(b){};
    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }
};
class D:public A,public B,public C{
	int x,a;
public:
	D(int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8):
		A(a1,a6),B(a2,a5),C(a3,a4),x(a7),a(a8){}
	int getX()const{
		return x;
	}
	int getA()const{
		return a;
	}
};

int main(){
	int a1,a2,a3,a4,a5,a6,a7,a8;
	cin>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8;
	D d(a1,a2,a3,a4,a5,a6,a7,a8);
	cout<<d.getX()<<" "<<d.A::getX()<<" "<<d.B::getX()<<endl;
	cout<<d.getY()<<endl;
	cout<<d.getA()<<" "<<d.B::getA()<<" "<<d.C::getA()<<endl;
	cout<<d.getB()<<endl;
	return 0;
}
/*样例输入
1 2 3 4 5 6 7 8

样例输出
7 1 2
6
8 5 3
4

*/