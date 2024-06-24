// 定义一个4位二进制非负整数类Binary，它有4个取值为0或1的数据成员分别表示各位上的数字。
// （1）为Binary类重载成员双目运算符“+”，实现二进制整数加法，要考虑进位，高位溢出作截断处理。（例如：1000 + 1000 = 0000）
// （2）为Binary类重载运算符“<<”，用于输出4位二进制数字。
// （3）定义一个检查数字合法性的成员函数check()，当检查到某一位上的数字不是0或1时函数返回-1，否则返回这个数的十进制非负整数值。
// （4）为Binary类定义构造函数和你认为必要的其它成员。
// （5）在主函数中对以上函数和运算符进行测试。main函数已经写好，请根据main函数完成该类的设计。
#include <iostream>
#include <math.h>
using namespace std;
class Binary
{
    int num1,num2,num3,num4;
    public:
    Binary(int a=0,int b=0,int c=0,int d=0):num4(a),num3(b),num2(c),num1(d){};
    int check()
    {
        if(num1!=0&&num1!=1) return -1;
        if(num2!=0&&num2!=1) return -1;
        if(num3!=0&&num3!=1) return -1;
        if(num4!=0&&num4!=1) return -1;
        return pow(2,3)*num1+pow(2,2)*num2+pow(2,1)*num3+num4;
    }
    friend ostream &operator<<(ostream &output, Binary &b)
    {
        output<<b.num1<<b.num2<<b.num3<<b.num4;
        return output;
    }
    Binary *operator+(Binary b)
    {
        int num1=0,num2=0,num3=0,num4=0;
        num4=b.num4+this->num4;
        if(num4>=2) num3+=1;
        num4%=2;
        num3+=b.num3+this->num3;
        if(num3>=2) num2+=1;
        num3%=2;
        num2+=b.num2+this->num2;
        if(num2>=2) num1+=1;
        num2%=2;
        num1+=b.num1+this->num1;
        num1%=2;
        this->num1=num1;
        this->num2=num2;
        this->num3=num3;
        this->num4=num4;
        return this;
    }
};
int main(){
    Binary b1(1,0,0,1),b2(1,0,1,0),b3(1,2,3,4);
    cout<<b1.check()<<" "<<b2.check()<<" "<<b3.check()<<endl;
    cout<<b1<<" "<<b2<<endl;
    b1+b2;
    cout<<b1<<endl;
    Binary b4(1,1,1,1);
    b4+b2;
    cout<<b4<<endl;
    return 0;
}