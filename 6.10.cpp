// 定义一个Circle类,有数据成员radius(半径),成员函数getArea(),计算圆的面积,构造一个Circle 的对象。
// ​主函数已给出，只需写出Circle类的代码即可，代码中的 类名、方法名、参数名已经指定，请勿修改。（圆周率算3.14）
#include <iostream>
using namespace std;
// ps:提交的时候请看清题目
#define PI 3.14
class Circle
{
public:
    double radius;
    Circle(double r):radius(r){};
    double getArea()
    {
        return PI*radius*radius;
    }
};
// main函数题目没给,下面是自己写的测试代码:
int main()
{
    int r;
    cin>>r;
    Circle c(r);
    cout<<c.getArea()<<endl;
    return 0;
}