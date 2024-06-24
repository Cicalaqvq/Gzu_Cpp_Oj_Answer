// ​定义一个Tree(树)类,有成员ages(树龄),成员函数grow(int years)对 ages 加上years ,age()显示Tree对象的ages的值。
// 主函数已给出，只需写出Tree类的代码即可，代码中的 类名、方法名、参数名已经指定，请勿修改。
#include <iostream>
using namespace std;
class Tree{
private:
    int ages=0;
public:
    void grow(int years)
    {
        ages+=years;
    }
    int age()
    {
        return ages;
    }
};

int main()
{
    int x;
    Tree tree;
    while(cin>>x)
    {
        if(x==-1)
            break;
        tree.grow(x);
    }
    cout<<tree.age()<<endl;
    return 0;
}