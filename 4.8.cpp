// 设计一个Time类，有hour、minute、second等私有数据成员。 对该类重载+、-和<<运算符。
// +运算符函数要实现Time对象和一个正整数n的相加，n理解为秒数，该运算符函数返回当前时间加n秒之后的Time对象。（加之后的时间可能跨到后一天）
// -运算符函数重载的第一个版本要实现Time对象和一个正整数n的相减，n理解为秒数，该运算符函数返回当前时间减n秒之后的Time对象。（减之后的时间可能回到前一天）
// -运算符函数重载的第二个版本要实现两个Time对象相减（假设两个时间是同一天之内的），该运算符函数返回两个时间相差的秒数。
// <<运算符函数重载的目的是为了直接使用cout来输出时间信息。
// main函数已经写好，请根据main函数的内容完成该类的设计：
#include <iostream>
using namespace std;
class Time
{
    int hour,mintute,second;
    public:
    Time(int h,int m,int s):hour(h),mintute(m),second(s){};
    Time& operator+(int n)
    {

        second+=n;
        while(second>60||mintute>60||hour>60)
     {   if(second>60)
        {
            mintute++;
            second-=60;
        }
        if(mintute>60)
        {
            hour++;
            mintute-=60;
        }
        if(hour>24)
        {
            hour-=24;
        }
     }
        return *this;
    }
    Time& operator-(int n)
    {
        if(n>60)
        {
            if(n<3600)
            {
                int tempmin=n/60,tempsec=n%60;
                mintute-=tempmin;
                second-=tempsec;
            }
            else
            {
                int temphour=n/3600;
                n%=3600;
                int tempmin=n/60,tempsec=n%60;
                hour-=temphour;
                mintute-=tempmin;
                second-=tempsec;
            }
        }
        else second-=n;
        if(second<0)
        {
            second+=60;
            mintute--;
        }
        if(mintute<0)
        {
            hour--;
            mintute+=60;
        }
        if(hour<0)
        hour+=24;
        return *this;
    }
    friend int operator-(const Time& t1,const Time& t2)
    {
        int sec=t1.second-t2.second;
        int min=t1.mintute-t2.mintute;
        int h=t1.hour-t2.hour;
        return (sec+min*60+h*3600);
    }
    friend ostream& operator <<(ostream &out,const Time & t)
    {
        out<<t.hour<<":"<<t.mintute<<":"<<t.second<<endl;
        return out;    
    }
};
int main(){
	int s;
	cin>>s;
	Time t1(13,30,20);
	t1=t1-s;
	cout<<t1;
	Time t2(21,10,33);
	t2=t2+s;
	cout<<t2;
	cout<<t1-t2<<endl;
	return 0; 	
}