/*设计一个Point类，有两个私有的数据成员x和y，存储横坐标和纵坐标，并为该类定义各种构造函数。
再设计一个三角形类Triangle，该类有3个Point类的私有对象成员，分别代表三角形的三个顶点。为该类定义各种构造函数。将三角形类声明为Point类的友元类，在三角型类中定义一个成员函数double getArea(); ，用来求三角形的面积。
在主函数中创建三角形对象，计算并输出面积。*/
#include <iostream>
using namespace std;
class Point
{
    private:
    double x,y;
    public:
    friend class Triangle; //友元类定义
    Point(double,double);
    Point(){};
};
class Triangle
{
    private:
    double a,b,c,d;
    public:
    Triangle(class Point&,class Point &,class Point &);
    double getArea();
};
Point::Point(double x,double y):x(x),y(y){};
Triangle::Triangle(class Point &a,class Point &b,class Point &c)
{
    this->a=b.y-a.y;
    this->b=c.x-a.x;
    this->c=a.y-c.y;
    this->d=b.x-a.x;
    if(this->a<0) this->a=-this->a;
    if(this->b<0) this->b=-this->b;
    if(this->c<0) this->c=-this->c;
    if(this->d<0) this->d=-this->d;
}
double Triangle::getArea()
{
    return (a*b+c*d)/2;
}

int main(){
	double x,y;
	cin>>x>>y;
	Point a(x,y);
	cin>>x>>y;
	Point b(x,y);
	cin>>x>>y;
	Point c(x,y);
	Triangle t(a,b,c);
	cout<<t.getArea()<<endl;
	return 0;
} 
/*输入描述:
输入三行，每行输入一个点的横坐标、纵坐标
输出描述:
输出三角形的面积*/