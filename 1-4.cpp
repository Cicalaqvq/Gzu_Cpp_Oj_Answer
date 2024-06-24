/*设计一个Point类，有两个私有的数据成员x和y，存储横坐标和纵坐标，并为该类定义各种构造函数。
再设计一个Circle类，该类有私有成员Point center; 代表圆心，以及私有数据成员double radius; 代表半径。
为该类设计求面积和半径的成员函数。圆周率数据使用3.14159265。
再为该类设计一个判断某点是否在圆内部的成员函数（如果点在圆周上则不算在圆内部）。
请根据下面的main函数完成类的设计：*/
#include <iostream>
#include <math.h>
#define PI 3.14159265
using namespace std;
class Point
{
    private:
    double x,y;
    public:
    Point(double,double);
    Point(){};
    double Getx();
    double Gety();
};
class Circle
{
    private:
    double radius,x,y;
    Point center;
    public:
    Circle(double,double,double);
    double getArea();
    double getPerimeter();
    int isInTheCircle(Point p);
};
Point::Point(double x,double y):x(x),y(y){};
double Point::Getx()
{
    return x;
}
double Point::Gety()
{
    return y;
}
Circle::Circle(double x,double y,double r):x(x),y(y),radius(r){};
double Circle::getArea()
{
    return radius*radius*PI;
}
double Circle::getPerimeter()
{
    return 2*PI*radius;
}
int Circle::isInTheCircle(Point p)
{
    double xp=p.Getx(),yp=p.Gety();
    if (sqrt((x-xp)*(x-xp)+(y-yp)*(y-yp))>radius)
    return 0;
    else
    return 1;
}
int main(){
	double x,y,radius;
	cin>>x>>y;
	cin>>radius;
	Circle c(x,y,radius);
	cin>>x>>y;
	Point p(x,y);
	cout<<c.getArea()<<endl;
	cout<<c.getPerimeter()<<endl;
	if(c.isInTheCircle(p))
		cout<<"该点在圆内部！"<<endl;
	else
		cout<<"该点不在圆内部！"<<endl;	
	return 0; 
}
/*
输入描述:
第一行输入圆心坐标
第二行输入圆的半径
第三行输入某个点的坐标
输出描述:
第一行输出圆的面积
第二行输出圆的周长
第三行输出某个点是否在圆内部*/