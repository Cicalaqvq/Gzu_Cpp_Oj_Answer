// ​已知有Grandson类和main函数如下：
#include <iostream>
#include <string>
using namespace std;
class Father
{
    private:
    string name;
    public:
    Father(string n):name(n){};
    Father(){};
    void printFatherName()
    {
        cout<<name<<endl;
    }
};
class Son1:virtual public Father
{
    private:
    string name1,name2;
    public:
    Son1(string n1,string n2):name1(n1),name2(n2){};
    void printSonName()
    {
        cout<<name1<<endl<<name2<<endl;
    }
};
class Son2:virtual public Father
{
    private:
    string name1,name3;
    public:
    Son2(string n1,string n3):name1(n1),name3(n3){};
    void printSonName()
    {
        cout<<name1<<endl<<name3<<endl;
    }
};
class Grandson:public Son1,public Son2{
	string grandsonName;
public:
	Grandson(string name1,string name2,string name3,string name4):
		Father(name1),Son1(name1,name2),Son2(name1,name3),grandsonName(name4){}
	void printGrandsonName(){
		cout<<grandsonName<<endl;
	}
};

int main(){
	string n1,n2,n3,n4;
	cin>>n1>>n2>>n3>>n4;
	Grandson gson(n1,n2,n3,n4);
	gson.printFatherName();
	cout<<endl;
	gson.Son1::printSonName();
	cout<<endl;
	gson.Son2::printSonName();
	cout<<endl;
	gson.printGrandsonName();
	return 0;
}

// 请根据输入输出关系将Grandson类的直接基类和间接基类的定义补充完整。你需要提交除了Grandson类和main函数之外的其他代码
/*样例输入
Tom Mike Nick Joe
样例输出
Tom

Tom
Mike

Tom
Nick

Joe
*/