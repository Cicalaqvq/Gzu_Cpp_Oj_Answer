// 有如下三个类的定义：
#include <iostream>
#include <string>
using namespace std;
class GrandFather{
	string name;
public:
	GrandFather(string name):name(name){
		cout<<"GrandFather Constructed,Name:"<<name<<endl;
	}
	~GrandFather(){
		cout<<"GrandFather Destructed,Name:"<<name<<endl;
	}
};

class Father:public GrandFather{
	string name;
public:
	Father(string name1,string name2):name(name1),GrandFather(name2){
		cout<<"Father Constructed,Name:"<<name<<endl;
	}
	~Father(){
		cout<<"Father Destructed,Name:"<<name<<endl;
	}
};

class Mother{
	string name;
public:
	Mother(string name):name(name){
		cout<<"Mother Constructed,Name:"<<name<<endl;
	}
	~Mother(){
		cout<<"Mother Destructed,Name:"<<name<<endl;
	}
};
class Son:public Mother,public Father
{
    private:
    string name;
    public:
    Son(string n1,string n2,string n3,string n4):Mother(n3),Father(n4,n2),name(n1){cout<<"Son Constructed,Name:"<<name<<endl;};
    ~Son(){
		cout<<"Son Destructed,Name:"<<name<<endl;
    };
};
// 现在在它们的基础上，定义派生类Son。
// 请根据main函数的内容，结合输入输出，对Son类进行设计：
                                     // n1    n2        n3       n4
int main(){                          //Son  Grandfather Mother      Father
	string name1,name2,name3,name4;  //Mike  Marry         Tom       Harry
	cin>>name1>>name2>>name3>>name4; 
	Son son(name1,name2,name3,name4);
	return 0;
}
/*
样例输入
Mike Marry Tom Harry

样例输出
Mother Constructed,Name:Tom
GrandFather Constructed,Name:Marry
Father Constructed,Name:Harry
Son Constructed,Name:Mike
Son Destructed,Name:Mike
Father Destructed,Name:Harry
GrandFather Destructed,Name:Marry
Mother Destructed,Name:Tom

*/