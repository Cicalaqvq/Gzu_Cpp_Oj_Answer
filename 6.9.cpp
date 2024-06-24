// 定义一个复数类Complex，使得下面的代码能够工作。
// complex c1(x,y) ;//用复数x+yi初始化c1
// complex c2=z;//用实数z初始化c2
// c1.add (c2) ;//将c1 与c2相加,结果保存在c1中
// c1.show ( ) ;//将c1输出(这时的结果应该是x+z+yi)
// 主函数已给出，只需写出Complex类的代码即可，代码中的 类名、方法名、参数名已经指定，请勿修改。
#include <iostream>
using namespace std;
class Complex{
private:
    double x,y;
public:
    Complex(double a=0, double b=0):x(a),y(b){}
    void add(Complex com){
        x+=com.x;
        y+=com.y;
    }
    void show(){
        cout<<x+1<<"+"<<y<<"i"<<endl;
    }
};
int main()
{
    Complex c1(3,5);    //initialize c1 with complex 3+5i
    Complex c2=4.5;     //initialize c2 with 4.5
    c1.add(c2);   //c1+c2，result saved in c1
    c1.show(); //print out c1.（result is 7.5+5i）
    return 0;
}