// ​定义一个Dog 类,
// 包含了age, weight等属性,以及对这些属性操作的方法：获取年龄->getAge(),获取体重->getWeight(),设置年龄->setAge(int age),设置体重->setWeight(int Weight)，实现这个类。
// 主函数已给出，只需写出Dog类的代码即可，代码中的 类名、方法名、参数名已经指定，请勿修改。
#include <iostream>
using namespace std;
class Dog
{
private:
    int age;
    int weight;
public:
    void setAge(int age)
    {
        this->age=age;
    }
    void setWeight(int weight)
    {
        this->weight=weight;
    }
    int getAge()
    {
        return age;
    }
    int getWeight()
    {
        return weight;
    }
};
// main函数题目没给,下面是我自己写的测试代码:
int main()
{
    int a,b;
    cin>>a>>b;
    Dog d;
    d.setAge(a);
    d.setWeight(b);
    cout<<d.getAge()<<" "<<d.getWeight()<<endl;

}