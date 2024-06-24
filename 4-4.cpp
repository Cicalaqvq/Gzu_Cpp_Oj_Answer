// 定义一个MyArray类，内部有私有成员int size和int *ptr。
// 创建该类对象时，在构造函数中用new动态内存分配一个长度为size的一维整型数组并用ptr成员存储该数组的首地址。析构函数要释放动态数组。
// 为该类重载以下运算符：
// （1）下标运算符[ ]，利用该下标运算符实现对数组元素的读写访问
// （2）赋值运算符，实现MyArray对象之间正确的深层赋值。
// （3）+运算符，实现两个MyArray对象的数组的对应元素相加，返回一个新的MyArray对象，该对象的数组中存储了之前两个数组对应元素相加的结果。
// （4）-运算符，实现两个MyArray对象的数组的对应元素相减，返回一个新的MyArray对象，该对象的数组中存储了之前两个数组对应元素相减的结果。
// （5）*运算符，将两个MyArray对象的数组视作向量，该运算符用于求向量内积
// （6）<<运算符，实现使用cout输出对象的数组的内容
// 此外，该类的复制构造函数要正确实现深层复制
// main函数已经写好，请根据main函数的内容完成该类的设计：
#include <iostream>
using namespace std;
class MyArray
{
    int size;
    int *ptr;
    public:
    MyArray(int a):size(a){ptr=new int [size];};
	MyArray(){};
	// 此外，该类的复制构造函数要正确实现深层复制
	MyArray(const MyArray &m)
	{
		size=m.size;
		ptr=new int [size];
		for(int i=0;i<m.size;i++) ptr[i]=m.ptr[i];
	}
	// 析构函数要释放动态数组。
    ~MyArray(){delete[] ptr;};
	// （1）下标运算符[ ]，利用该下标运算符实现对数组元素的读写访问
    int& operator [](int i)
    {
        return ptr[i];
    }
	// （2）赋值运算符，实现MyArray对象之间正确的深层赋值。
	MyArray& operator=(const MyArray &m1)
	{
		size=m1.size;
		ptr=new int [size];
		for(int i=0;i<m1.size;i++) ptr[i]=m1.ptr[i];
		return *this;
	}
	// （3）+运算符，实现两个MyArray对象的数组的对应元素相加，返回一个新的MyArray对象，该对象的数组中存储了之前两个数组对应元素相加的结果。
	friend MyArray operator+(const MyArray &m1,const MyArray &m2)
	{
		MyArray m3(m1.size);
		for(int i=0;i<m1.size;i++)
		{
			m3.ptr[i]=m1.ptr[i]+m2.ptr[i];
		}
		return m3;
	}
	// （4）-运算符，实现两个MyArray对象的数组的对应元素相减，返回一个新的MyArray对象，该对象的数组中存储了之前两个数组对应元素相减的结果。
	friend MyArray operator-(const MyArray &m1,const MyArray &m2)
	{
		MyArray m3(m1.size);
		for(int i=0;i<m1.size;i++)
		{
			m3.ptr[i]=m1.ptr[i]-m2.ptr[i];
		}
		return m3;
	}
	// （5）*运算符，将两个MyArray对象的数组视作向量，该运算符用于求向量内积
	friend int operator *(const MyArray &m1,const MyArray &m2)
	{
		int sum=0;
		for(int i=0;i<m1.size;i++)
		{
				sum+=m1.ptr[i]*m2.ptr[i];
		}
		return sum;
	}
	// （6）<<运算符，实现使用cout输出对象的数组的内容
	friend ostream& operator<<(ostream &output,const MyArray &m)
	{
		for(int i=0;i<m.size;i++)
		{
		output<<m.ptr[i];
		if(i!=m.size-1) output<<",";
		}
		output<<endl;
		return output;
	}
	int getSize()
	{
		return size;
	}
};
int main(){
	int n;
	cin>>n;
	MyArray arr1(n);
	for(int i=0;i<arr1.getSize();i++)
		cin>>arr1[i];
	cout<<arr1;
	MyArray arr2(arr1);
	for(int i=0;i<arr2.getSize();i++)
		arr2[i]+=1;
	cout<<arr2;
	MyArray arr3,arr4;
	arr3=arr2+arr1;
	cout<<arr3;
	arr4=arr2-arr1;
	cout<<arr4;
	cout<<arr1*arr2<<endl;
	return 0;
}