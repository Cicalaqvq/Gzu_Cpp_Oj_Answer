/*​现需要对输入的两个int类型数据、float类型数据、string类型数据进行大小比较并返回较大的一个。
本题已经完成了main函数的编写，请根据main函数代码编写其他部分的代码并提交。main函数的代码编写如下*/
#include <iostream>
#include <string>
using namespace std;
class Test
{
    private:

    public:
    int GetMax(int a,int b)
    {
        return a>b?:a,b;
    }
    float GetMax(float a,float b)
    {
        return a>b?:a,b;
    }
    string GetMax(string a,string b)
    {
        if (a.compare(b)) return b;
        return a;
    }
};
int main()
{
	int a, b;
	float f1, f2;
	string str1, str2;
	Test s;

	cin >> a >> b;
	cin >> f1 >> f2;
	cin.get();
	getline(cin, str1);
	getline(cin, str2);

	cout << "两个int数中较大的为：" << s.GetMax(a, b) << endl;
	cout << "两个float数中较大的为：" << s.GetMax(f1, f2) << endl;
	cout << "两个string中较大的为：" << s.GetMax(str1, str2) << endl;
}