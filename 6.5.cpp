// 填写下方空白处代码，通过重载运算符使得Counter类型可以以x为值参与整数加法运算

#include <iostream>
using namespace std;
class Counter
{
public:
    Counter(int d){x=d;}
    int getx() const{return x;}
private:
    int x;
};
//------------------code here----------------------------
int operator+(Counter x,int y)
{
    return x.getx()+y;
}
int operator+(int y,Counter x)
{
    return x.getx()+y;
}
//-------------------------------------------------------------
int main()
{
    int a,y;
    cin>>a>>y;
    Counter x(a);
    cout<<x+y<<' '<<y+x;
}
