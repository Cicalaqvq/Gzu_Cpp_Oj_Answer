/*有两个类Father和Mother和它们的共同子类Son。现在Father、Mother和main函数的代码已经完成。请根据已有的代码完成类Son的设计。（只需要提交类Son的代码）*/
#include <iostream>
using namespace std;
class Father{
    int a;
public:
    Father(int a):a(a){
        cout<<"Father Constructed "<<a<<endl;
    }
    void doSomething(){
        cout<<"Hello Father"<<endl;
    }
};
class Mother{
    int b;
public:
    Mother(int b):b(b){
        cout<<"Mother Constructed "<<b<<endl;
    }
    void doSomething(){
        cout<<"Hello Mother"<<endl;
    }
};
class Son:public Mother,public Father
{
    private:
    Father *f;
    Mother *m;
    int s;
    public:
    Son(int a1,int a2,int a3,int a4,int a5):Mother(a1),Father(a2),s(a5){ 
        f=new Father(a3);
        m=new Mother(a4);
        cout<<"Son Constructed "<<s<<endl;};
    void doSomething()
    {
        Father::doSomething();
        Mother::doSomething();
        cout<<"Hello Son"<<endl;
    }

};
int main(){
    Son son(1,2,3,4,5);
    son.doSomething();
    return 0;
}
/*输出描述
Mother Constructed 1
Father Constructed 2
Father Constructed 3
Mother Constructed 4
Son Constructed 5
Hello Father
Hello Mother
Hello Son*/