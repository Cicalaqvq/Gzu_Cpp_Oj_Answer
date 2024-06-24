/*
定义一个Course（课程）类，该类有cid（课程编号）、name（课程名称）、credits（学分）、year（开设学年：第一、第二或第三）等私有数据成员。
该类还有三个私有静态数据成员count1、count2和count3分别用于统计第一、第二和第三学年的总学分。为该类定义构造函数，构造函数要负责对静态数据成员的值进行调整。
再定义一个静态函数成员 void printCount()，该函数用于输出静态数据成员的值。
在主函数中创建若干个课程对象，然后调用printCount输出第一、第二和第三学年的总学分。main函数已经写好，请根据main函数的内容完成Course类的设计。main函数如下：
*/
#include <iostream>
using namespace std;
class Course{
    private:
    string cid,name;
    double credits;
    int year;
    static double count1,count2,count3;
    public:
    Course(string,string,double,int);
    static void printCount();
};
double Course::count1=0;
double Course::count2=0;
double Course::count3=0;
Course::Course(string c,string n,double cr,int y):cid(c),name(n),credits(cr),year(y){
    if(y==1) count1=count1+credits;
    else if(y==2) count2=count2+credits;
    else if(y==3) count3=count3+credits;
}
void Course::printCount()
{
    cout<<count1<<" "<<count2<<" "<<count3<<endl;
}
int main(){
    string cid;
    string name;
    double credits;
    int year;
    cin>>cid>>name>>credits>>year;
    Course c1(cid,name,credits,year);
    cin>>cid>>name>>credits>>year;
    Course c2(cid,name,credits,year);
    cin>>cid>>name>>credits>>year;
    Course c3(cid,name,credits,year);
    cin>>cid>>name>>credits>>year;
    Course c4(cid,name,credits,year);
    cin>>cid>>name>>credits>>year;
    Course c5(cid,name,credits,year);
    Course::printCount();
    return 0;
}
