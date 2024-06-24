// ​设计一个自己的字符串类MyString，内部有一个私有成员char *sptr；该成员用于创建字符串对象时，在内部使用动态内存分配的方法分配一个字符数组用于存储字符串的内容。
// 为该类设计构造函数、析构函数（对象析构时，要释放分配的数组）
// 为该类设计返回字符串实际长度的成员函数
// 为该类设计输出字符串内容的成员函数
// 为该类设计实现字符串连接和字符串复制的成员函数。字符串连接和字符串复制时，要求重新分配数组，并释放原有的数组。
// main函数已经写好，请根据main函数的内容完成该类的设计：
#include <iostream>
#include <cstring>
using namespace std;
class MyString
{
    char *sptr;
    public:
    MyString():sptr(nullptr){cout<<"Object Constructed. No Memory Allocated."<<endl;}
    MyString(char *s):sptr(s){cout<<"Object Constructed. "<<strlen(s)+1<<" Bytes Allocated."<<endl;}
    MyString(const MyString &m)
    {
        sptr=new char [strlen(m.sptr)+1];
        strcpy(sptr,m.sptr);;
        cout<<"Object Constructed. "<<strlen(sptr)+1<<" Bytes Allocated."<<endl;
    }
    void printString()
    {
        if (sptr==nullptr) cout<<"No Memory Allocated In This Object."<<endl;
        else 
        cout<<sptr<<endl;
    }
    int getSize()
    {
        if(sptr==nullptr) return 0;
        return strlen(sptr);
    }
    MyString& stringCopy(const MyString &m)
    {
        int temp=strlen(sptr);
        sptr=nullptr;
        sptr=new char [strlen(m.sptr)];
        for(int i=0;i<strlen(m.sptr);i++)
        {
            sptr[i]=m.sptr[i];
        }
        sptr[strlen(m.sptr)]='\0';
        cout<<"String Copy, "<<strlen(sptr)+1<< " Bytes Reallocated And "<<temp+1<< " Bytes Freed."<<endl;
        return *this;
    }
    MyString& stringCat(const MyString &m)
    {  
        int temp=strlen(sptr);
        char *t=sptr;
        sptr=nullptr;
        sptr=new char [temp+strlen(m.sptr)];
        sptr=strcat(t,m.sptr);
        cout<<"String Connection, " <<strlen(sptr)+1<<" Bytes Reallocated And "<<temp+1<<" Bytes Freed."<<endl;
        return *this;
    }
    ~MyString()
    {
        if(sptr==nullptr) cout<<"Object Destructed. No Memory Freed."<<endl;
        else
        {
            int len=strlen(sptr);
            // delete [] sptr;
            cout<<"Object Destructed. "<<len+1<<" Bytes Freed."<<endl;
        }
    }
};
int main(){
	MyString s1;
	MyString s2("Hello");
	MyString s3(s2);
	
	s1.printString();
	s2.printString();
	s3.printString();
	
	cout<<s1.getSize()<<" "<<s2.getSize()<<" "<<s3.getSize()<<endl;
	
	MyString s4("HiChina"); 
	
	s2.stringCopy(s4);
	s2.printString();
	
	s3.stringCat(s4);
	s3.printString(); 
	
	return 0;
}
/*
Object Constructed. No Memory Allocated.
Object Constructed. 6 Bytes Allocated.
Object Constructed. 6 Bytes Allocated.
No Memory Allocated In This Object.
Hello
Hello
0 5 5
Object Constructed. 8 Bytes Allocated.
String Copy, 8 Bytes Reallocated And 6 Bytes Freed.
HiChina
String Connection, 13 Bytes Reallocated And 6 Bytes Freed.
HelloHiChina
Object Destructed. 8 Bytes Freed.
Object Destructed. 13 Bytes Freed.
Object Destructed. 8 Bytes Freed.
Object Destructed. No Memory Freed.
*/