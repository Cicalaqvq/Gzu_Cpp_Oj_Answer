/*定义一个Date类，该类有year、month和day三个私有成员，用于存储日期的年、月和日信息。
为该类定义默认构造函数、带参的构造函数、复制构造函数和读写数据成员的函数setDate和showDate。
其中，setDate用于设置年月日信息，showDate用于输出日期信息。
在主函数中用不同的构造函数创建Date对象并进行测试。*/
#include <iostream>
using namespace std;
class Date
{
    private:
    int year,month,day;
    int *ptr;
    public:
    Date(const Date &obj); //拷贝构造函数
    Date(int,int,int); //带参构造函数
    Date();//默认构造函数
    void setDate(int,int,int);
    void showDate();
};
void Date:: setDate(int y,int m,int d)
    {
        year=y;
        month=m;
        day=d;
    }
void Date:: showDate()
    {
        cout<<year<<"/"<<month<<"/"<<day<<endl;
    }
Date::Date(){year=2021;month=4;day=16;}
Date::Date(int y,int m,int d):year(y),month(m),day(d){}
Date::Date(const Date &obj):year(obj.year),month(obj.month),day(obj.day){}

int main(){
	Date d1;
	d1.showDate();
	Date d2(2021,3,13);
	d2.showDate();
	d2.setDate(2021,5,1);
	d2.showDate();
	Date d3(d1);
	d3.showDate();
	return 0;
}
