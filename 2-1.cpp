/*定义一个Worker（职员）类，该类有name（姓名）、position（职位）、salary（月薪）等私有数据成员。该类有两个私有静态数据成员：count用于统计雇员总人数、totalSalary用于计算月应发薪酬总数。
为该类定义构造函数，构造函数要负责对静态数据成员的值进行调整。再定义一个静态函数成员void printSalary ()，该函数用于输出静态数据成员的值。定义你认为必要的其它函数。
main函数已经写好，请根据main函数的内容完成该类的定义。*/
#include <iostream>
using namespace std;
class Worker{
    private:
    string name,position;
    double salary;
    static int count;
    static double totalSalary;
    public:
    Worker(string,string,double);
    static void printSalary();
};
int Worker::count=0;
double Worker::totalSalary=0;
Worker::Worker(string n,string p,double s):name(n),position(p),salary(s)
{
    count++;
    totalSalary=totalSalary+salary;
}
void Worker::printSalary()
{
    cout<<"This company has "<<count<<" workers."<<endl<<"Total salary is "<<totalSalary<<endl<<"Average salary is "<<totalSalary/count<<endl;
}
int main(){
    string name;
    string position;
    double salary;
    cin>>name>>position>>salary;
    Worker w1(name,position,salary);
    cin>>name>>position>>salary;
    Worker w2(name,position,salary);
    cin>>name>>position>>salary;
    Worker w3(name,position,salary);
    cin>>name>>position>>salary;
    Worker w4(name,position,salary);
    cin>>name>>position>>salary;
    Worker w5(name,position,salary);
    Worker::printSalary();
    return 0;

}
/*输入描述
分五行输入五个职员的信息

输出描述
按样例格式输出相关信息*/