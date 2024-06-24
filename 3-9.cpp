#include <iostream>
using namespace std;
// 有如下三个类的定义：
class Base1{
	int id;
public:
	Base1(int id):id(id){
		cout<<"Base1 Constructed,ID:"<<id<<endl;
	}
	~Base1(){
		cout<<"Base1 Destructed,ID:"<<id<<endl;
	}
};

class Base2{
	int id;
public:
	Base2(int id):id(id){
		cout<<"Base2 Constructed,ID:"<<id<<endl;
	}
	~Base2(){
		cout<<"Base2 Destructed,ID:"<<id<<endl;
	}
};  

class Base3{
	int id;
public:
	Base3(int id):id(id){
		cout<<"Base3 Constructed,ID:"<<id<<endl;
	}
	~Base3(){
		cout<<"Base3 Destructed,ID:"<<id<<endl;
	}
}; 
class Derived:public Base3,public Base1,public Base2
{
	private:
	int id;
	Base1 *b1;
	Base2 *b2;
	Base3 *b3;
	public:
	Derived(int a3,int a5,int a1,int a4,int a2,int a7,int a6):Base3(a7),Base1(a4),Base2(a2)
	{
		b2=new Base2(a5);
		b1=new Base1(a3);
		b3=new Base3(a1);
		id=a6;
		cout<<"Derived Constructed,ID:"<<id<<endl;
	}
	~Derived()
	{
		cout<<"Derived Destructed,ID:"<<id<<endl;
		delete(b3);
		delete(b1);
		delete(b2);
	}
	
};
// 现在要在这三个类的基础上，定义派生类Derived。
// 请根据main函数的内容，结合输入输出，给出Derived类的完整定义。

int main(){
	int id1,id2,id3,id4,id5,id6,id7;
	cin>>id1>>id2>>id3>>id4>>id5>>id6>>id7;
	Derived d(id1,id2,id3,id4,id5,id6,id7);
	return 0;
}
/*
样例输入
3 5 1 4 2 7 6

样例输出
Base3 Constructed,ID:7
Base1 Constructed,ID:4
Base2 Constructed,ID:2
Base2 Constructed,ID:5
Base1 Constructed,ID:3
Base3 Constructed,ID:1
Derived Constructed,ID:6
Derived Destructed,ID:6
Base3 Destructed,ID:1
Base1 Destructed,ID:3
Base2 Destructed,ID:5
Base2 Destructed,ID:2
Base1 Destructed,ID:4
Base3 Destructed,ID:7

*/