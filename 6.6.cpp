// 给出Counter类的定义，通过重载(++,--)运算符实现自增和自减操作(前置后置两种都要实现)，使程序输出ACCEPT
// 代码主体部分已经预先写好，你只需要提交空白处内容

#include<bits/stdc++.h>
using namespace std;
class Counter
{
public:
    Counter(){x=0;}
    int getx() const{return x;}
    //----------------------------code-----------------------------------------
 Counter operator++()
{
    ++x;
    return *this;
}
//后置加int区分
 Counter operator++(int)
 {
    Counter temp;
    temp.x=x;
    ++x;
    return temp;
 }
 Counter operator--()
{
    --x;
    return *this;
}
//后置加int区分
 Counter operator--(int)
 {
    Counter temp;
    temp.x=x;
    --x;
    return temp;
 }
    //----------------------------------------------------------------------------
private:
    int x;
};
vector<int> ans;
Counter a;
int x,y;
int main()
{
    srand(time(0));
    y=x=rand();
    while(x--)a++;
    if(a.getx()!=y)ans.push_back(1);
    if((++a).getx()!=++y)ans.push_back(2);
    if((--a).getx()!=--y)ans.push_back(3);
    if((a++).getx()!=y++)ans.push_back(4);
    if((a--).getx()!=y--)ans.push_back(5);
    if(a.getx()!=y)ans.push_back(6);
    if(ans.size()==0)cout<<"ACCEPT";
    else for(auto u:ans)cout<<"wrong answer on test "<<u<<endl;
}