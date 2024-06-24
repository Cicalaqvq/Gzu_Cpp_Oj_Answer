/*������������Cube����������Cuboid��������Sphere��Բ׶����Cone����Ҫ�ĳ�Ա��������������Ҫ�洢�߳���Ϣ����������Ҫ�洢�������Ϣ��������Ҫ�洢�뾶��Ϣ��Բ׶����Ҫ�洢����뾶�͸���Ϣ��
�ٶ���һ��������Ĺ�����Volume�������ж���汾�����غ���calVolume���Էֱ������������塢�����塢�����Բ׶�����������main�����Ѿ���ɣ������main�����������������������Ķ��塣
�ڳ����У���ʹ�������Բ���ʶ��岢ʹ�ø�Բ���ʽ��м��㣺
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