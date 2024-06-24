#include <iostream>
#include <string>
/*定义一个Test类，该类有两个重载的成员函数DataLength，一个接收int型的参数，另一个接收string型的参数
第一个DataLength函数用于计算一个整型值的位数并返回
第二个DataLength函数用于计算string变量字符串的实际长度并返回
main函数已经写好，请根据下面的main函数完成该类的设计：*/
using namespace std;
class Test{
    private:
    public:
    int DataLength(int);
    int DataLength(string);
};
int Test::DataLength(int a)
{
    int cnt=0;
    while(a)
    {
        a=a/10;
        cnt++;
    }
    return cnt;
}
int Test::DataLength(string s)
{
    return s.size();
}
int main(){
int a;
string s;
getline(cin,s);
cin>>a;
Test t;
cout<<t. DataLength(s)<<endl;
cout<<t. DataLength(a)<<endl;
return 0;
}