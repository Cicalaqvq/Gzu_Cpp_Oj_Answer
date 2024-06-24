// ​定义一个MyString类，该类的声明如下：
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
class MyString{
	char *ptr;
public:
	int size()const{
		return strlen(ptr);
	}
	MyString(){
		ptr=new char[1];
		ptr[0]='\0';
	}
	MyString(const char *p){
		ptr=new char[strlen(p)+1];
		strcpy(ptr,p);
	}
	MyString(const MyString &str){
		ptr=new char[str.size()+1];
		strcpy(ptr,str.ptr);
	}
	~MyString(){
		delete []ptr;
	}
    friend ostream & operator<<(ostream & out,const MyString &str); 
	friend MyString operator+(const MyString &s1,const MyString &s2); 
	friend int operator==(const MyString &s1,const MyString &s2);
	friend int operator!=(const MyString &s1,const MyString &s2);
	friend int operator<(const MyString &s1,const MyString &s2);
	friend int operator<=(const MyString &s1,const MyString &s2);
	friend int operator>(const MyString &s1,const MyString &s2);
	friend int operator>=(const MyString &s1,const MyString &s2);
	MyString & operator=(const MyString &s);
	MyString & operator+=(const MyString &s);
	char operator[](int i);
}; 
// 对该类重载教材233页表6-1中列出的那些运算符（这些运算符的含义和string类一致）。
// main函数也写好了，请根据上面的类声明部分和main函数的内容，将未实现的运算符函数进行实现。main函数如下：
/*
案例输出
0 0 1 0
0 1
HelloWorld
China China China
HelloWorldChina
anihCdlroWolleH
*/
ostream & operator<<(ostream & out,const MyString &str)
    {
        for(int i=0;i<str.size();i++)
        out<<str.ptr[i];
        return out;
    }
MyString operator+(const MyString &s1,const MyString &s2)
    {
        char *str1=s1.ptr;
        char *str2=s2.ptr;
        const char *str=strcat(str1,str2);
        MyString s(str);
        return s;
    } 
int operator==(const MyString &s1,const MyString &s2)
    {
        if(s1.ptr==s2.ptr) return 1;
        return 0;
    }
int operator!=(const MyString &s1,const MyString &s2)
    {
        if(s1==s2) return 0;
        return 1;
    }
int operator<(const MyString &s1,const MyString &s2)
    {
        if((strcmp(s1.ptr,s2.ptr)<0)) return 1;
        return 0;
    }
int operator<=(const MyString &s1,const MyString &s2)
    {
        
        if((strcmp(s1.ptr,s2.ptr)<=0)) return 1;
        return 0;
    }
int operator>(const MyString &s1,const MyString &s2)
    {
        if((strcmp(s1.ptr,s2.ptr))>0)return 1;
        return 0;
    }
int operator>=(const MyString &s1,const MyString &s2)
    {
        
        if((strcmp(s1.ptr,s2.ptr)>=0)) return 1;
        return 0;
    }
MyString &MyString:: operator=(const MyString &s)
    {
        for(int i=0;i<s.size();i++)
        {
            ptr[i]=s.ptr[i];
        }
        if(this->size()>s.size())
        ptr[s.size()]='\0';
        return *this;
    }
 MyString &MyString:: operator+=(const MyString &s)
    {
         char *s1=this->ptr;
         char *s2=s.ptr;
         char *str=strcat(s1,s2);
         this->ptr=str;
        return *this;
    }
 char MyString:: operator[](int i)
    {
        return ptr[i];
    }
int main(){
	MyString s1("Hello"),s2("World"),s3("China");
	cout<<(s1>s2)<<" "<<(s1>=s2)<<" "<<(s1<=s2)<<" "<<(s2<s3)<<endl;
	cout<<(s1==s2)<<" "<<(s1!=s3)<<endl;
	MyString s4=s1+s2;
	cout<<s4<<endl;
	s1=s2=s3;
	cout<<s1<<" "<<s2<<" "<<s3<<endl;
	s4+=s3;
	cout<<s4<<endl;
	for(int i=s4.size()-1;i>=0;i--)
		cout<<s4[i];
	cout<<endl;
	return 0; 
}