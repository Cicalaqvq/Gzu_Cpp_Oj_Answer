// ​请编写一个抽象类Shape，在此基础上派生出类Rectangle和类Circle，二者都有计算对象面积的函数getArea()和计算对象周长的函数getPerim()      
// 为了避免精度问题，这里取圆周率 π=3
#include<bits/stdc++.h>
using namespace std;
//------------------------------code here----------------------------
#define PI 3
class Shape
{
    public:
    virtual int getArea()
    {
        return 0;
    }
    virtual int getPerim()
    {
        return 0;
    }
};
class Rectangle:public Shape
{
    int x,y;
    public:
    Rectangle(int a,int b):x(a),y(b){};
    int getArea()
    {
        return x*y;
    }
    int getPerim()
    {
        return 2*(x+y);
    }
};
class Circle:public Shape
{
    int r;
    public:
    Circle(int a):r(a){};
    int getArea()
    {
        return PI*r*r;
    }
    int getPerim()
    {
        return 2*PI*r;
    }
};

//-----------------------------------------------------------------------
int main()
{
    int x,y,r;
    cin>>x>>y>>r;
    Shape *shape=new Rectangle(x,y);
    cout<<shape->getArea()<<'-'<<shape->getPerim()<<"  ";
    shape=new Circle(r);
    cout<<shape->getArea()<<'-'<<shape->getPerim()<<"  ";
}
