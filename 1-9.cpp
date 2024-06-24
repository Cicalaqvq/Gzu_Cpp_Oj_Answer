/*​本题和“求面积函数重载”一题的需求类似，main函数不变，而且程序中的Cirlce类和Rectangle类已经替你实现好了。这两个类删除了复制构造函数。
你只需要实现Area类即可。原来的Area类的实现现在还可以通过测试吗？如果不行，该怎样修改？*/
#include <iostream>
#define PI 3.14159265
using namespace std;
//Circle类的定义如下：
class Circle{
	double radius;
public:
	Circle(double r):radius(r){}
	double getRadius() const{
		return radius;
	}
	Circle(Circle &r)=delete;    //删除复制构造函数
	Circle(const Circle &r)=delete;  //删除复制构造函数
};
//Rectangle类的实现如下：
class Rectangle{
	double height,width;
public:
	Rectangle(double h,double w):height(h),width(w){}
	double getHeight()const{
		return height;
	}
	double getWidth()const{
		return width;
	}
	Rectangle(Rectangle &r)=delete;   //删除复制构造函数
	Rectangle(const Rectangle &r)=delete;   //删除复制构造函数
};
class Area{
    public:
static double calArea (const class Circle &c)
    {
        int r=c.getRadius();
        return PI*r*r;
    }
static double calArea(const class Rectangle &r)
{
    double h=r.getHeight();
    double w=r.getWidth();
    return h*w;
}
};
int main()
{
    double r,h,w;
     cin>>r>>h>>w;
    const Circle c1(r);
     Circle c2(r+2);
    const Rectangle r1(h,w);
    Rectangle r2(h+2,w+2);
     cout<<Area::calArea(c1)<<endl;
     cout<<Area::calArea(c2)<<endl;
     cout<<Area::calArea(r1)<<endl;
     cout<<Area::calArea(r2)<<endl;
}