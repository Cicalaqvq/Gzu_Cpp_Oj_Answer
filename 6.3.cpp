// 编写类A和类B ，其中A是B的父类型     
// 题目给出了一个数组dataArray，和变量len，最开始len=1，dataArray[1]=new A;    
// 当一个A类型数据被删除的时侯，输出"del A\n"，并在数组末尾++len的位置加入一个新的B类型
// 当一个B类型数据被删除的时侯，输出"del B\n"，并在数组末尾++len的位置加入一个新的A类型   
// (不包含"")
// 接着输入一个数字n，程序将依次删除Data数组中1-n位置的内容
// 在下方空白处实现类A和B
#include<bits/stdc++.h>
using namespace std;
class A;
A *dataArray[1001];
int len=0;
//-------------------code here--------------------
class A
{
    public:
    static int count;
    // A(){cout<<"create A"<<endl;}
    void insert();
    virtual ~A()
    {
       if(count>=2)
       cout<<"del A\n";
       count++;
        insert();  
    }
};
int A::count=0;
class B:public A
{
    ~B(){
        if(count>=2)
            cout<<"del B\n";
        dataArray[++len]=new A;
    }
    public:
    // B(){cout<<"create B"<<endl;}
};
void A::insert()
{
    dataArray[++len]=new B;
}
//----------------------------------------------------
int main()
{
    dataArray[++len]=new A;
    int n;cin>>n;
    for(int i=1;i<=n;i++) delete(dataArray[i]);
}

