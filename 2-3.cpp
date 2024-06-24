/*设计一个产品类Product，该类有产品名称、公司名称、产品型号、价格，出厂日期五个数据成员。其中出厂日期是Date类的对象。
main函数的代码已经给出，请根据main函数代码和对应的输出给出Product类和Date类的代码。（需要提交main函数之外的其他代码部分）*/
#include <iostream>
using namespace std;
class Date{
    private:
    int year,month,day;
    public:
    friend class Product;
    Date(int,int,int);
};
class Product{
    private:
    string name,company,type;
    double price;
    Date d;
    public:
    Product(string,string,string,class Date&,double);
    void printInfo();
};
Date::Date(int y,int m,int d):year(y),month(m),day(d){};
Product::Product(string n,string c,string t,class Date &d,double p):name(n),company(c),type(t),d(d),price(p){};
void Product::printInfo()
{
    cout<<name<<" "<<company<<" "<<type<<" "<<price<<endl<<d.year<<"/"<<d.month<<"/"<<d.day<<endl;
}
int main(){
    int year,month,day;
    string name,company,type;
    double price;
    cin>>year>>month>>day;
    Date date(year,month,day);
    cin>>name>>company>>type>>price;
    Product p(name,company,type,date,price);
    p.printInfo();
    return 0;

}
/*
输入：
2021 3 9
s90 volvo b5 32.6
输出：
s90 volvo b5 32.6
2021/3/9
*/