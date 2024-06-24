/*定义一个学生类Student，该类有姓名、学号、年龄、专业等私有成员。除此之外，该类还有一个静态数据成员NUM。为该类定义必要的成员函数，包括构造函数和其他函数。
构造函数要负责对学生的姓名、年龄和专业进行初始化，而学号则需要在NUM的基础上进行自动编号。第一个学生的学号是20200001，第二个学生的学号是20200002，依次类推。
在main函数中创建学生对象并输出相关信息。*/
#include <iostream>
using namespace std;
class Student{
private:
int age,id;
string name,subject;
static int nextid; //静态成员
public:
Student(string,string,int);
Student(const Student &obj);//拷贝构造函数
void showInfo()
{
    cout<<name<<" "<<id<<" "<<subject<<" "<<age<<endl;
}
};
int Student::nextid=20200001;//静态成员不能在类里面赋值
Student::Student(string n="Mike",string s="Math",int a=18):name(n),age(a),subject(s){
    id=nextid++;
};
Student::Student(const Student &obj):name(obj.name),age(obj.age),subject(obj.subject)
{
    id=nextid++;
}

int main(){
	Student s1;
	s1.showInfo();
	Student s2("Tom","Computer",19);
	s2.showInfo();
	Student s3(s1);
	s3.showInfo();
    s2.showInfo();
	return 0;
} 
