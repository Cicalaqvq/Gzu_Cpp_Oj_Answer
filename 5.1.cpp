// 定义一个抽象的三维立体形状类Shape3D，该类有一个数据成员shapeName（形状名称），一个纯虚函数calVolume（计算体积），用于计算三维立体形状的体积。
// （1）请完成Shape3D类的定义，定义你认为必要的任何成员；
// （2）请为Shape3D类定义公有派生类Cube（正方体类）、Cuboid（长方体类），Sphere（球体类）和Cone（圆锥体类）。
// Cube类有side（边长）数据成员；Cuboid类有length、width和height数据成员（分别代表长、宽、高）；
// Sphere类有radius（半径）数据成员；Cone类有radius和height数据成员（分别代表底面半径和高）。在这些派生类中分别实现纯虚函数calVolume。
// （3）在主函数中定义Shape3D的指针并分别指向不同的派生类对象，调用calVolume计算不同三维立体形状的体积。
// main函数已经完成，请根据main函数的内容完成以上所有类的定义。在程序中，请使用下面的圆周率定义并使用该圆周率进行计算：
#include <iostream>
#include <string>
using namespace std;
const double PI=3.14159265;
class Shape3D
{
    protected:
    string shapeName;
    public:
    virtual double calVolume()=0;
    virtual string getName()=0;
};
//正方体类
class Cube:public Shape3D
{
    double side;
    public:
    Cube(string str,double s):side(s){
        shapeName=str;
    }
    string getName()
    {
        return shapeName;
    }
    double calVolume()
    {
        return side*side*side;
    }
};
//长方体类
class Cuboid:public Shape3D
{
    double length,width,height;
    public:
    Cuboid(string s,double l,double w,double h):length(l),width(w),height(h){
        shapeName=s;
    }
    string getName()
    {
        return shapeName;
    }
    double calVolume()
    {
        return length*width*height;
    }
};
//球体类
class Sphere:public Shape3D
{
    double radius;
    public:
    Sphere(string s,double r):radius(r)
    {
        shapeName=s;
    }
    string getName()
    {
        return shapeName;
    }
    double calVolume()
    {
         return 4*PI*radius*radius*radius/3;
    }
};
//圆锥体类
class Cone:public Shape3D
{
    double radius,height;
    public:
    Cone(string s,double r,double h):radius(r),height(h)
    {
        shapeName=s;
    }
    double calVolume()
    {
        return PI*radius*radius*height/3;
    }
    string getName()
    {
        return shapeName;
    }
};


int main(){
double length,width,height,radius;
Shape3D *sp;
cin>>length;
Cube cube("Cube",length);
cin>>length>>width>>height;
Cuboid cuboid("Cuboid",length,width,height);
cin>>radius;
Sphere sphere("Sphere",radius);
cin>>radius>>height;
Cone cone("Cone",radius,height);
sp=&cube;
cout<<sp->getName()<<":"<<sp->calVolume()<<endl;
sp=&cuboid;
cout<<sp->getName()<<":"<<sp->calVolume()<<endl;
sp=&sphere;
cout<<sp->getName()<<":"<<sp->calVolume()<<endl;
sp=&cone;
cout<<sp->getName()<<":"<<sp->calVolume()<<endl;

return 0;

}