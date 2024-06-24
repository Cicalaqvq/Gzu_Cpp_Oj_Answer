/* 定义一个圆形类Cirlce和矩形类Rectangle，定义必要的成员
再定义一个求面积的工具类Area，该类有两个重载函数calArea可以分别用于求圆形对象的面积和矩形对象的面积
main函数已经完成，请根据main函数的内容完成以上三个类的定义：*/
#include <iostream>
#define PI 3.14159265
using namespace std;
class Circle{
public:
int r;
Circle(double);
};
class Rectangle{
public:
int a,b;
Rectangle(double,double);
};
class Area{
private:
Rectangle r;
Circle c;
public:
static double calArea(class Rectangle r)
{
    return r.a*r.b;
}
static double calArea(class Circle c)
{
    return c.r*c.r*PI;
}
};
Circle::Circle(double a):r(a){};
Rectangle::Rectangle(double a,double b):a(a),b(b){};
int main(){
    double r,h,w;
     cin>>r>>h>>w;
    const Circle c1(r);
     Circle c2(r+2);
    const Rectangle r1(h,w);
    Rectangle r2(h+2,w+2);
    //为什么要用static??
    //因为这是静态成员函数，使用时无需创建类的对象。。
     cout<<Area::calArea(c1)<<endl;
     cout<<Area::calArea(c2)<<endl;
     cout<<Area::calArea(r1)<<endl;
     cout<<Area::calArea(r2)<<endl;
     return 0;
}