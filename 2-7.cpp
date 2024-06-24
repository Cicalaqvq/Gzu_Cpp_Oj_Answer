/*定义正方体类Cube、长方体类Cuboid、球体类Sphere和圆锥体类Cone及必要的成员。例如正方体需要存储边长信息、长方体需要存储长宽高信息、球体需要存储半径信息、圆锥体需要存储底面半径和高信息。
再定义一个求面积的工具类Volume，该类有多个版本的重载函数calVolume可以分别用于求正方体、长方体、球体和圆锥体对象的体积。main函数已经完成，请根据main函数的内容完成以上所有类的定义。
在程序中，请使用下面的圆周率定义并使用该圆周率进行计算：
const double PI=3.14159265;*/
#include <iostream>
#define PI 3.14159265
using namespace std;
class Cube
{
    private:
    double length;
    public:
    friend class Volume;
    Cube(double l):length(l){};
};
class Cuboid
{
    private:
    double length,width,height;
    public:
    friend class Volume;
    Cuboid(double l,double w,double h):length(l),width(w),height(h){};
};
class Sphere
{
    private:
    double radius;
    public:
    friend class Volume;
    Sphere(double r):radius(r){};
};
class Cone
{
    private:
    double radius,height;
    public:
    friend class Volume;
    Cone(double r,double h):radius(r),height(h){};
};
class Volume
{
    public:
static double calVolume(class Cube cube)
    {
        return cube.length*cube.length*cube.length;
    }
static double calVolume(class Cuboid cuboid)
    {
        return cuboid.height*cuboid.length*cuboid.width;
    }
static double calVolume(class Sphere sphere)
    {
        return PI*sphere.radius*sphere.radius*sphere.radius*4/3;
    }
static double calVolume(class Cone cone)
    {
        return cone.height*(PI*cone.radius*cone.radius)/3;
    }
};
int main(){
    double length,width,height,radius;
    cin>>length;
    Cube cube(length);
    cin>>length>>width>>height;
    Cuboid cuboid(length,width,height);
    cin>>radius;
    Sphere sphere(radius);
    cin>>radius>>height;
    Cone cone(radius,height);
    cout<<Volume::calVolume(cube)<<endl;
    cout<<Volume::calVolume(cuboid)<<endl;
    cout<<Volume::calVolume(sphere)<<endl;
    cout<<Volume::calVolume(cone)<<endl;
    return 0;

}