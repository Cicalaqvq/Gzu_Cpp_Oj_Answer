//      定义一个复数类Complex，该类有两个double型的数据成员real和imag（分别代表复数的实部和虚部）。现在要求对Complex类重载“*”和“+”运算符，要求如下：
// （1）将“*”重载为Complex类的非成员函数，其语义是实现两个复数相乘，得到一个新的复数并返回；
// （2）将“+”重载为Complex类的成员函数，其语义是当前复数的实部和虚部分别加上一个同样的double型值，使当前复数的实部和虚部被修改；
// （3）为了方便输出，对Complex类重载“<<”运算符，用于整体输出Complex对象的实部和虚部；
//  （4）为该类定义你认为必要的其他成员；
// 提示：复数c1=x1+y1i和复数c2=x2+y2i的乘积为c1×c2=(x1x2-y1y2)+(x1y2+x2y1)i。
// main函数已经完成，请根据main函数的内容完成该类的设计：
#include <iostream>
using namespace std;
class Complex
{
    double real,imag;
    public:
    Complex(double r,double i):real(r),imag(i){};
    friend Complex operator*(const Complex &c1,const Complex &c2)
    {
        double realret=c1.real*c2.real-c1.imag*c2.imag;
        double imagret=c1.real*c2.imag+c2.real*c1.imag;
        Complex ret(realret,imagret);
        return ret;
    }
    Complex& operator+(double n)
    {
        this->real+=n;
        this->imag+=n;
        return *this;
    }
    friend ostream& operator<<(ostream &out,const Complex& c1)
    {
        out<<c1.real<<"+"<<c1.imag<<"i"<<endl;
        return out;
    }
};
int main(){

	double real1,imag1,real2,imag2;

	cin>>real1>>imag1>>real2>>imag2;

	Complex c1(real1,imag1),c2(real2,imag2);   

	cout<<c1;

	cout<<c2;                   

	Complex c3=c1*c2;                  

	cout<<c3;

	c3+3;

	cout<<c3;

	return 0;


}