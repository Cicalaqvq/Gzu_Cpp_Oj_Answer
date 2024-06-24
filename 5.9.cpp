// 定义一个抽象的房产类HouseProperty，该类有两个数据成员：area（double型，用于描述房产的面积）和unitPrice（double型，用于描述房产的每平方米单价）。
// 该类还有一个纯虚函数taxCalculation（税费计算函数），用于计算不同房产的税费。
// 假设税费计算的规则如下：
// （A）住宅，90平米（含）以下的，税费为房产总价的1.5%，90平米以上的，税费为房产总价的2.0%；
// （B）别墅，无论面积大小，税费为房产总价的5%加上单独的10万元消费税；
// （C）商铺，30平米（含）以下税费为房产总价的3%，30平米至100平米（含）的税费为房产总价的4%，100平米以上的税费为房产总价的5%。
// 请根据以上描述完成下面的任务：
// （1）请完成HouseProperty类的定义，定义你认为必要的任何成员函数；
// （2）请为HouseProperty类定义公有派生类Residence（住宅）和Shop（商铺），在这两个类中根据上述规则实现纯虚函数taxCalculation；
// （3）请为Residence类定义公有派生类Villa（别墅），在这个类中根据上述规则覆盖taxCalculation函数；
// （4）在主函数中定义HouseProperty的指针并分别指向不同的派生类对象，调用taxCalculation计算不同房产的税费并输出。
// 提示：
// （1）taxCalculation函数的原型可以定义为 double taxCalculation( )；
// （2）HouseProperty类的area成员和unitPrice成员可定义为protected权限也可以定义为private权限；
// （3）数据成员的初始化可以由基类的构造函数来完成，也可由派生类的构造函数来完成。如果由基类构造函数完成，派生类构造函数要为基类构造函数传递参数。
// main函数的内容如下：
#include <iostream>
using namespace std;
class HouseProperty
{
    protected:
    double area,unitPrice;
    public:
    virtual double taxCalculation()=0;
    HouseProperty(double a,double b):area(a),unitPrice(b){};
};
class Residence:public HouseProperty
{
    public:
    Residence(double a,double b):HouseProperty(a,b){};
    double taxCalculation()
    {
        if(area<=90) return unitPrice*area*0.015;
        else return unitPrice*area*0.02;
    }
};
class Villa:public Residence
{
    public:
    Villa(double a,double b):Residence(a,b){};
    double taxCalculation()
    {
        return unitPrice*area*0.05+100000;
    }
};
class Shop:public HouseProperty
{
    public:
    Shop(double a,double b):HouseProperty(a,b){};
    double taxCalculation()
    {
        if(area<=30) return unitPrice*area*0.03;
        else if(area>30&&area<=100) return unitPrice*area*0.04;
        else return unitPrice*area*0.05;
    }
};
int main(){	
	double area;          
	double unitPrice; 
	cin>>area>>unitPrice;
	Residence h1(area,unitPrice);    
	cin>>area>>unitPrice;         
	Shop h2(area,unitPrice);
	cin>>area>>unitPrice; 
	Villa h3(area,unitPrice);
	HouseProperty *p;
	p=&h1;
	cout<<p->taxCalculation()<<endl;
	p=&h2;
	cout<<p->taxCalculation()<<endl;
	p=&h3;
	cout<<p->taxCalculation()<<endl;
	return 0;
}