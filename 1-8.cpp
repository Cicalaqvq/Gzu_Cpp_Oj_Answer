/*​定义测试类Test，该类有私有数据成员int x；
程序的main函数已经写好了，请根据main函数的情况，给出Test类的完整定义。
main函数如下：*/
#include <iostream>
using namespace std;
class Test
{
    private:
    int x;
    public:
    void printInfo()const;
    void printInfo();
    Test(int);
    void setX(int);
};
Test::Test(int x):x(x){};
void Test::printInfo()const
{
    cout<<x<<endl;
}
void Test::printInfo()
{
    cout<<2*x<<endl;
}
void Test::setX(int n)
{
    x=n;
}
int main(){
	int n;
	cin>>n; 
	Test t1(n);
	t1.printInfo(); 
	const Test t2(n);
	t2.printInfo(); 
	t1.setX(n+5);
	t1.printInfo(); 
	const Test &t3=t1;
	t3.printInfo(); 
	return 0;
}