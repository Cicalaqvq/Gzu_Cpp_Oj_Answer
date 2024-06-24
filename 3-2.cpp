/*有两个类A和B和它们的共同子类C。现在A、B和main函数的代码已经完成。请根据已有的代码完成类C的设计。（只需要提交类C的代码）*/
#include <iostream>
using namespace std;
class A{
    int a;
public:
    A(int a):a(a){}
    A(){};
    ~A(){
        cout<<"A Destructed "<<a<<endl;
    }
    void doSomething(){
        cout<<"Hello A"<<endl;
    }
};
class B{
    int b;
public:
    B(int b):b(b){}
    B(){};
    ~B(){
        cout<<"B Destructed "<<b<<endl;
    }
    void doSomething(){
    cout<<"Hello B"<<endl;
    }
};
//不用继承
// class C{
//     private:
//     int c;
//     A *a1,*a2;
//     B *b1,*b2;
//     public:
//     C(int a,int b,int c,int d,int e):c(e)
//     {
//         a1=new A(d);
//         b1=new B(c);
//         b2=new B(b);
//         a2=new A(a);
//     }
//     void doSomething()
//     {
//         a1->doSomething();
//         b1->doSomething();
//         cout<<"Hello C"<<endl;
//     }
//     ~C()
//     {
//         cout<<"C Destructed "<<c<<endl;
//         a1->~A();
//         b1->~B();
//         b2->~B();
//         a2->~A();

//     }
// };
//用继承
class C:public A,public B
{
    private:
    int c;
    public:
    void doSomething()
    {
        A::doSomething();
        B::doSomething();
        cout<<"Hello C"<<endl;
    }
    C(int a,int b,int c):A(a),B(b),c(c){};
    C(int a,int b,int c ,int a_val,int b_val):A(a),B(b){
        C(a_val,b_val,c);
    };
    ~C(){cout<<"C Destructed "<<c<<endl;};

};
int main(){
    C cc(1,2,3,4,5);
    cc.doSomething();
    return 0;
}
/*输出描述
Hello A
Hello B
Hello C
C Destructed 5
A Destructed 4
B Destructed 3
B Destructed 2
A Destructed 1
*/