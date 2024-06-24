/*请定义一个类Test，其拥有一个私有数据成员str(string类型)，和其他对字符串进行简单操作的行为。请根据如下main函数的代码完成类Test的定义。
*/
#include <iostream>
#include <string>
using namespace std;
class Test
{
    private:
    string str;
    public:
    void SetStr(string s)
    {
        str=s;
    }
    string GetStr()
    {
        return str;
    }
    int GetLength()
    {
        return str.size();
    }
    void Reverse()
    {
        for(int i=str.size()-1;i>=0;i--)
        {
            cout<<str[i];
        }
        cout<<endl;
    }

};
int main()
{
	string str;
	//输入一个字符串
	getline(cin, str);
	//实例化对象
	Test* s = new Test();
	//设置对象中的数据成员值
	s->SetStr(str);
	cout << "您输入的字符串是：" << s->GetStr() << endl;
	cout << "字符串长度为：" << s->GetLength() << endl;
	//将字符串颠倒输出
	cout << "将字符串倒序输出：";
	s->Reverse();
	//释放对象空间
	delete s;
	
	return 0;
}