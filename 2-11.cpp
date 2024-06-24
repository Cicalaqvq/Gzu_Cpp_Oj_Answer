/*​请编写一个类Test，其中包含了多个数据交换函数，名称都为Swap。本题已经给出了main函数的实现，请编写类Test代码并提交。main函数代码如下：
本题主要考查函数调用的多种方式：传值调用、传地址调用、引用调用，请同学通过此程序的运行体会三种函数调用方式的区别。*/
#include <iostream>
#include <iomanip>
#define n 5
using namespace std;
class Test
{
    private:

    public:
    void Swap(int *a,int *b)
    {
        int temp;
        temp=*a;
        *a=*b;
        *b=temp;
    }
    void Swap(int a,int b)
    {
        int temp;
        temp=a;
        a=b;
        b=temp;
    }
    void Swap(float &a,float &b)
    {
        float temp;
        temp=a;
        a=b;
        b=temp;
    }
    void Swap(int *a)
    {
        int max=a[0],maxid=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]>max)
            {
                max=a[i];
                maxid=i;
            }
        }
        if(maxid==n-1)
        {
            for(int i=0;i<n;i++)
            {
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }  
            a[n-1]=max+1;
        }
        else
        {
            int temp[n];
            for(int i=0;i<n;i++) temp[i+1]=a[i];
            temp[0]=max+1;
            for(int i=0;i<n;i++) a[i]=temp[i];
        }
    }
    void Print(int *a)
    {
        for(int i=0;i<n;i++)
        cout<<a[i]<<endl;
    } 
};
int main()
{
	int a, b;
	int c, d;
	float e, f;
	int ints[n];
	Test* o = new Test();
	cin >> a >> b;
	cin >> c >> d;
	cin >> e >> f;
	for (int i = 0; i < n; i++)
	{
		cin >> ints[i];
	}
	o->Swap(a, b);
	o->Swap(&c, &d);
	o->Swap(e, f);
	o->Swap(ints);
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << fixed << setprecision(2) << e << endl;
	cout << fixed << setprecision(2) << f << endl;
	o->Print(ints);

	return 0;
}