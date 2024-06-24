/*现有一个类MyString，其内部包含了字符串成员，请根据main函数代码完成其他部分代码的编写，main函数代码如下：*/
#include <iostream>
using namespace std;
class MyString
{
    private:
    string str;
    public:
    static int cnt;
    MyString(string s):str(s){cnt++;};
static string GetString(class MyString *str)
{
    return str->str;
}
static int GetN()
{
    return cnt;
}
~MyString()
{
    cnt--;
}
};
int MyString::cnt=0;
int main()
{
	MyString* str1 = new MyString("one");
	MyString* str2 = new MyString("two");
	MyString* str3 = new MyString("three");

	cout << "目前对象个数为：" << MyString::GetN() << endl;
	cout << "我是对象：" << MyString::GetString(str1) << endl;
	delete str1;
	cout << "目前对象个数为：" << MyString::GetN() << endl;
	cout << "我是对象：" << MyString::GetString(str2) << endl;
	delete str2;
	cout << "目前对象个数为：" << MyString::GetN() << endl;
	cout << "我是对象：" << MyString::GetString(str3) << endl;
	delete str3;
	cout << "目前对象个数为：" << MyString::GetN() << endl;
	return 0;
}