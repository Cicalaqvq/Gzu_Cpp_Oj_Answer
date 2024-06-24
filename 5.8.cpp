// 某自助餐厅提供A、B、C三种套餐服务，原价分别为100元，120元和150元。对于不同顾客有不同的优惠规则如下：
// （A）成年男顾客，所有套餐均不打折，此外收取套餐原价15%的服务费；
// （B）成年女顾客，所有套餐打9折，此外收取套餐原价15%的服务费；
// （C）老年人顾客，所有套餐打8.5折，此外收取套餐原价10%的服务费；
// （D）未成年人顾客，所有套餐打7折，不收取服务费。
// 根据以上需求，定义一个抽象的顾客类Customer，该类有一个数据成员：gender（string类型），用于描述顾客的性别。该类还有一个纯虚函数calculateCost（计算用餐费用函数），用于根据顾客选择的套餐，计算其应该支付的用餐费用并返回。
// 请根据以上描述完成下面的任务：
// （1）请完成Customer类的定义，定义你认为必要的任何成员函数；
// （2）请为Customer类定义三个公有派生类：AdultCustomer（成年顾客）、ElderlyCustomer（老年人顾客）和UnderAgeCustomer（未成年人顾客），在这三个类中根据上述规则分别实现纯虚函数calculateCost；
// （3）在主函数中定义Customer类的指针并分别指向不同的派生类对象，调用calculateCost函数计算用餐费用并输出。
// 提示：
// （1）calculateCost函数的原型可以定义为 double calculateCost(char set)；根据参数set判断用户选择的套餐。
// （2）Customer类的gender成员可定义为protected权限也可以定义为private权限。
// （3）gender成员的初始化可以由基类的构造函数来完成，也可由派生类的构造函数来完成。如果由基类构造函数完成，派生类构造函数要为基类构造函数传递参数。
// main函数已经完成，请根据main函数完成类的设计：
#include <iostream>
using namespace std;
class Customer
{
    protected:
    string gender;
    public:
    Customer(string s):gender(s){};
    virtual double calculateCost(char set)=0;
};
class AdultCustomer:public Customer
{
    public:
    AdultCustomer(string s):Customer(s){};
    double calculateCost(char set)
    {
        int flag=0;
        if(gender=="male") flag=1;
        switch (set)
        {
        case 'A':
        if(flag==1) return 100+100*0.15;
        return 100*0.9+100*0.15;
            break;
        case 'B':
        if(flag==1) return 120+120*0.15;
        return 120*0.9+120*0.15;
        case 'C':
        if(flag==1) return 150+150*0.15;
        return 150*0.9+150*0.15;
        }
    }
};
class ElderlyCustomer:public Customer
{
    public:
    ElderlyCustomer(string s):Customer(s){};   
    double calculateCost(char set)
    {
        switch (set)
        {
        case 'A':
        return 100*0.85+100*0.1;
        case 'B':
        return 120*0.85+120*0.1;
        default:
        return 150*0.85+150*0.1;
        }
    }
};
class UnderAgeCustomer:public Customer
{
    public:
    UnderAgeCustomer(string s):Customer(s){};
     double calculateCost(char set)
     {
         switch (set)
        {
        case 'A':
        return 100*0.7;
        case 'B':
        return 120*0.7;
        default:
        return 150*0.7;
        }
     }
};
int main(){ 
	AdultCustomer c1("male");            
	AdultCustomer c2("female");  
	ElderlyCustomer c3("male");
	UnderAgeCustomer c4("female");
	Customer *p;
	char set1,set2,set3,set4;
	cin>>set1>>set2>>set3>>set4;
	p=&c1;
	cout<<p->calculateCost(set1)<<endl;
	p=&c2;
	cout<<p->calculateCost(set2)<<endl;
	p=&c3;
	cout<<p->calculateCost(set3)<<endl;
	p=&c4;
	cout<<p->calculateCost(set4)<<endl;
	return 0;
}