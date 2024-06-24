/*定义四个类A、B、C、D，其中D类中包含A、B、C类的对象成员。main函数已经写好，请根据main函数给出四个类的完整定义。
main函数如下：*/
#include <iostream>
using namespace std;
class A{
    public:
    A(){cout<<"A's constructor is called!"<<endl;}
    ~A(){cout<<"A's destructor is called!"<<endl;}
};
class B{
    public:
    B(){cout<<"B's constructor is called!"<<endl;}
    ~B(){cout<<"B's destructor is called!"<<endl;}
};
class C{
    public:
    C(){cout<<"C's constructor is called!"<<endl;}
    ~C(){cout<<"C's destructor is called!"<<endl;}
};
class D:public B,public C,public A{
    public:
    D(){cout<<"D's constructor is called!"<<endl;};
    ~D(){cout<<"D's destructor is called!"<<endl;};
};
int main(){
	D d;
	return 0;
}
/* 样例输出:
B's constructor is called!
C's constructor is called!
A's constructor is called!
D's constructor is called!
D's destructor is called!
A's destructor is called!
C's destructor is called!
B's destructor is called!*/