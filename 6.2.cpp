// 实现一个抽象基类Clock，由此派生出类ClockA和ClockB，其中A包含hour，minute，second变量表示时间，而B使用quarter(=15min)和second来表示，输入了n个ClockA类型的对象，
// m个ClockB类型的对象，它们被统一存放在一个*Clock类型的数组里，
// 现在想要对这个数组按照其中存储的时间长短，由短到长进行排序(排序部分已给出，需要在外部实现cmp函数，如果a的时间比b少，则返回true)，排序后输出，输出函数已给出，完善剩余内容  
#include<bits/stdc++.h>
using namespace std;
class Clock;
bool cmp(Clock *a,Clock *b);
//------------------------------------------code here------------------------------------------------
class Clock
{
    public:
    virtual void print()=0;
    virtual int geth()
    {
        return 0;
    }
    virtual int getm()
    {
        return 0;
    }
    virtual int gets()
    {
        return 0;
    }
    virtual int gets1()
    {
        return 0;
    }
    virtual int getq()
    {
        return 0;
    }
};
class ClockA:public Clock
{
    int hour,minute,second;
    public:
    ClockA(int a,int b,int c):hour(a),minute(b),second(c){};
    int geth() {return hour;}
    int getm() {return minute;}
    int gets() {return second;}
    void print();
};
class ClockB:public Clock
{
    int quarter,second;
    public:
    int getq() {return quarter;}
    int gets1() {return second;}
    void print();
    ClockB(int a,int b):quarter(a),second(b){};
};
bool cmp(Clock *a,Clock *b)
{
    int hour=a->geth(),hour1=b->geth();
    int minute=a->getm()+a->getq()*15,minute1=b->getm()+b->getq()*15;
    int second=a->gets()+a->gets1(),second1=b->gets()+b->gets1();
    if(minute>=60)
    {
        int temp=minute;
        minute%=60;
        hour+=temp/60;
    }
    if(minute1>=60)
    {
        int temp=minute1;
        minute1%=60;
        hour1+=temp/60;
    }
    if(hour<hour1) return true;
    else if(hour==hour1)
    {
        if(minute<minute1) return true;
        else if(minute1==minute)
        {
            if(second<second1) return true;
        }
    }
    return false;
}
//--------------------------------------------------------------------------------------------------------
void ClockA::print(){cout<<hour<<':'<<minute<<':'<<second<<'\n';}
void ClockB::print(){cout<<quarter<<':'<<second<<'\n';}
int main()
{
    vector<Clock*> v;
    int n,m,a,b,c;
    Clock* tim;
    cin>>n>>m;
    while(n--)
    {
        cin>>a>>b>>c;
        tim=new ClockA(a,b,c);//abc代表时分秒
        v.push_back(tim);
    }
    while(m--)
    {
        cin>>a>>b;
        tim=new ClockB(a,b);//a,b代表 刻，秒
        v.push_back(tim);
    }
    sort(v.begin(),v.end(),cmp);
    for(auto x:v)x->print();
}