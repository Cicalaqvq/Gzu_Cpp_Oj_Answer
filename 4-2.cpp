/*定义一个点类Point，该类有两个int型的私有数据成员x，y（分别代表x坐标与y坐标）。现在要求对Circle类重载“+”运算符，要求如下：
（1）先将“+”重载为Point类的非成员函数，其语义是求两个点之间的直线距离；
（2）再将“+”重载为Point类的成员函数，其语义是当前Point对象的x和y坐标分别加上一个同样的int型值，使当前的点坐标被修改
（例如点[3,5] + 3的结果是得到点[6,8]）；
（3）为了方便输出，对Point类重载“<<”运算符，用于输出Point对象的坐标；
（4）为该类定义你认为必要的其他成员；
（5）在主函数中对以上重载后的运算符函数进行测试。*/
#include <iostream>
#include <math.h>
using namespace std;
class Point
{
    int x,y;
    public:
    Point(int a=0,int b=0):x(a),y(b){};
    friend ostream &operator<<(ostream &output,const Point &p)
    {
        output<<"["<<p.x<<","<<p.y<<"]";
        return output;
    }
   
    friend double operator+(Point p1,Point p2)
    {
        double d1=sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
        return d1;
    }
    Point operator+(int a)
    {
        Point p;
        p.x=this->x+a;
        p.y=this->y+a;
       return p;
    } 
};
int main(){
    int x,y;
    cin>>x>>y;
    Point p1(x,y);
    cin>>x>>y;
    Point p2(x,y);
    cout<<"Distance between p1"<<p1<<" and p2"<<p2<<" is "<<p1+p2<<endl;
    cout<<p1+3<<" "<<p2+5<<endl;
    return 0;
}