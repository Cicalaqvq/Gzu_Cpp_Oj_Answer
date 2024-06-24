/*设计一个员工类Employee，该类有姓名、部门、工号、工资，入职日期五个数据成员。其中入职日期是Date类的对象。
main函数的代码已经给出，请根据main函数代码和对应的输出给出Employee类和Date类的代码。（需要提交main函数之外的其他代码部分）
main函数的代码如下：*/
#include <iostream>
using namespace std;
class Date{
    private:
    int year,month,day;
    public:
    friend class Employee;
    Date(int,int,int);
};
class Employee{
    private:
    Date date;
    string name,department,id;
    double salary;
    public:
    Employee(string,string,string,class Date&,double);
    void printInfo();
};
Date::Date(int y,int m,int d):year(y),month(m),day(d){};
Employee::Employee(string n,string d,string i,class Date &date,double s):name(n),department(d),id(i),date(date),salary(s){};
void Employee::printInfo()
{
    cout<<name<<" "<<department<<" "<<id<<" "<<salary<<endl<<date.year<<"/"<<date.month<<"/"<<date.day<<endl;
}
int main(){
    int year,month,day;
    string name,department,id;
    double salary;
    cin>>year>>month>>day;
    Date date(year,month,day);
    cin>>name>>department>>id>>salary;
    Employee e(name,department,id,date,salary);
    e.printInfo();
    return 0;
}
/*
输入：
2020 5 1
lucy it 1001 3500
输出：
lucy it 1001 3500
2020/5/1
*/