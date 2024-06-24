// 定义一个圆形类Circle，该类有三个double型的私有数据成员x，y和radius（分别代表圆心坐标和圆的半径）。现在要求对Circle类重载“+”运算符，要求如下：
// （1）先将“+”重载为Circle类的非成员函数，其语义是实现两个圆的面积求和，返回两个圆的面积之和；
// （2）再将“+”重载为Circle类的成员函数，其语义是当前Circle对象的x、y坐标和radius分别加上一个同样的double型值，使当前Circle对象的圆心坐标和半径被修改；
// （3）为了方便输出，对Circle类重载“<<”运算符，用于整体输出Circle对象的圆心坐标和半径；
// （4）为该类定义你认为必要的其他成员。
// main函数已经完成，请根据main函数的内容完成该类的设计：
#include <iostream>
#define PI 3.14159265
using namespace std;
class Circle
{
    double x,y,radius;
    public:
    Circle(double n1,double n2,double n3):x(n1),y(n2),radius(n3){};
    Circle& operator+(double n)
    {
        x+=n;
        y+=n;
        radius+=n;
        return *this;
    }
    friend double operator+(const Circle& c1,const Circle &c2)
    {
        return (PI*c1.radius*c1.radius+PI*c2.radius*c2.radius);
    }
    friend ostream& operator<<(ostream &output,const Circle &c1)
    {
        output<<"圆心："<<c1.x<<","<<c1.y<<" "<<"半径："<<c1.radius<<endl;
        return output;
    }
    
};
int main(){
	double x,y,r,n;
	cin>>x>>y>>r>>n;
	Circle c1(x,y,r);
	Circle c2=c1;
	c2+n;
	cout<<c1;
	cout<<c2;
	cout<<c1+c2<<endl;
	return 0;


}