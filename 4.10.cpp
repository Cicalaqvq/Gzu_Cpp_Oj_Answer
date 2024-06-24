// 定义一个Test类，该类有私有成员x和y
// 为该类设计两个成员函数setXY1和setXY2，其中setXY1返回目的对象的指针，而setXY2返回目的对象的引用
// main函数已经写好，请根据main函数的内容完成该类的设计：
#include <iostream>
using namespace std;
class Test
{
    int x,y;
    public:
    Test(int m,int n):x(m),y(n){};
    Test* setXY1(int m,int n){
        x+=m;
        y+=n;
        return this;
    }
    Test& setXY2(int m,int n){
        x-=m;
        y-=n;
        return *this;
    }
    void showXY()
    {
        cout<<x<<" "<<y<<endl;
    }
};
int main(){
	int x,y;
	cin>>x>>y;
	Test t(x,y);
	t.setXY1(10,10)->showXY();
	t.setXY2(20,20).showXY();
	return 0;
}