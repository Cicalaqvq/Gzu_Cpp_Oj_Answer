/*​请定义一个时钟类Clock，其封装了有三个私有数据成员：hour，minute，second及其他相关函数，本题已经完成了main函数的代码编写，并完成其他相关代码的编写并提交。*/
#include <iostream>
using namespace std;
class Clock
{
    private:
    int hour,minute,second;
    public:
    Clock(){hour=0;minute=0;second=0;}
    Clock(int h,int m=30,int s=40):hour(h),minute(m),second(s){};
    void Display()
    {
        cout<<hour<<":"<<minute<<":"<<second<<endl;
    }
    void SetValue(int value)
    {
        hour=value;
        minute=30;
        second=40;
    }
};
int main()
{
	Clock o1(14);
	Clock o2(15, 40);
	Clock o3(15, 40, 59);
	Clock o4;
	o1.Display();
	o2.Display();
	o3.Display();
	o4.Display();
	o4.SetValue(23);
	o4.Display();

	return 0;
}
/*
14:30:40
15:40:40
15:40:59
0:0:0
23:30:40
*/