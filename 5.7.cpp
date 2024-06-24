// 定义一个抽象的顾客类Customer，该类有一个数据成员：points（积分，double型），用于存储顾客的积分。
// 该类还有一个纯虚函数recordPoints（记录积分函数），用于根据顾客每次的购物金额（即该纯虚函数的参数）为顾客增加相应积分，积分计算的规则如下：
// （A）普通顾客，每次购物后积分增加的值为此次购物金额*0.20；
// （B）会员顾客，每次购物后积分增加的值为此次购物金额*0.30；
// （C）VIP会员顾客，每次购物后积分增加的值为会员顾客增加的积分再上浮20%。
// 请根据以上描述完成下面的任务：
// （1）请完成Customer类的定义，包括你认为必要的任何成员函数。
// （2）请为Customer类定义公有派生类OrdinaryCustomer（普通顾客）和MemberCustomer（会员顾客），在这两个类中根据上述规则实现纯虚函数recordPoints；
// （3）请为MemberCustomer类定义公有派生类VIPCustomer（VIP会员顾客），在这个类中根据上述规则覆盖recordPoints函数；
// （4）在主函数中定义Customer类的指针并分别指向不同的派生类对象，调用recordPoints函数增加积分并输出更新后的积分值。
// main函数已经完成，请根据main函数完成类的设计：
#include <iostream>
using namespace std;
class Customer
{
    protected:
    double points;
    public:
    virtual void recordPoints(double money)=0;
    virtual double getPoints()=0;
    Customer(double a):points(a){};    
};
class OrdinaryCustomer:public Customer
{
    public:
    OrdinaryCustomer(double a):Customer(a){};
    void recordPoints(double money)
    {
        this->points+=money*0.2;
    }
    double getPoints()
    {
        return points;
    }
};
class MemberCustomer:public Customer
{
    public:
    MemberCustomer(double a):Customer(a){};
    void recordPoints(double money)
    {
        this->points+=money*0.3;
    }
    double getPoints()
    {
        return points;
    }
};
class VIPCustomer:public MemberCustomer
{
    public:
    VIPCustomer(double a):MemberCustomer(a){};
    void recordPoints(double money)
    {
        this->points+=money*0.3*1.2;
    }
    double getPoints()
    {
        return points;
    }
};
int main(){	
	OrdinaryCustomer oc(0);  
	MemberCustomer mc(0);
	VIPCustomer vc(0);
	Customer *p;  
	double m1,m2,m3;
	cin>>m1>>m2>>m3;
	p=&oc;
	p->recordPoints(m1); 
	cout<<p->getPoints()<<endl;
	p=&mc;
	p->recordPoints(m2);
	cout<<p->getPoints()<<endl;
	p=&vc;
	p->recordPoints(m3);
	cout<<p->getPoints()<<endl;
	return 0;
}