// 某景区有三条不同的游览线路，票价分别是A线路80元、B线路100元、C线路120元。景区对不同类型的游客实行如下的优惠政策：
// 18周岁以上（含18周岁）~ 65周岁以下（不含65周岁）的游客购买全价票。
// 65周岁以上（含65周岁）的老年游客和12周岁以下（不含12周岁）的儿童免票游览。
// 12周岁以上（含12周岁）~18周岁以下（不含18周岁）的未成年游客购买半价票。
// 根据以上需求，定义一个抽象的游客类Visitor，该类有私有数据成员：姓名name和游览线路line。该类还有一个计算购票费用的纯虚函数cost()。
// 请根据以上描述完成下面的任务：
// 请完成Visitor类的定义，定义你认为必要的任何成员函数；
// 请为Visitor类定义三个公有派生类：FullFare（全价票游客）、HalfFare（半价票游客）和FreeFare（免票游客），在这三个类中根据上述政策分别实现纯虚函数cost；
// 定义一个函数getVisitorPtr，该函数根据游客年龄的不同创建不同类别的游客对象并返回游客对象的指针（Visitor *）。根据游客对象的指针调用cost函数计算购票费用并输出
// main函数已经写好，请根据main函数的内容完成上述所有类的定义。
#include <iostream>
#include <string>
using namespace std;
class Visitor
{
    protected:
    int age;
    string name,line;
    public:
    Visitor(int a,string l):age(a),line(l){};
    virtual int cost()=0;
    Visitor *getVisitorPtr(int a,string l);
};
class FullFare:public Visitor
{
    public:
    FullFare(int a,string l):Visitor(a,l){};
    int cost()
    {
        if(line=="A") return 80;
        else if(line=="B") return 100;
        else return 120;
    } 
};

class FreeFare:public Visitor
{
    public:
    FreeFare(int a,string l):Visitor(a,l){};
    int cost()
    {
        return 0;
    }
};
class HalfFare:public Visitor
{
    public:
    HalfFare(int a,string l):Visitor(a,l){};
    int cost()
    {
        if(line=="A") return 40;
        else if(line=="B") return 50;
        else return 120;
    }
};
Visitor* getVisitorPtr(int a,string l)
{
    {
        if(a<12||a>=65)
        {
            return new FreeFare(a,l);
        }
        else if(a>=12&&a<18)
        {
            return new HalfFare(a,l);
        }
        else{
            return new FullFare(a,l);
        }
    }
}
int main(){
    int age;
    string line;
    Visitor *vp;
    age=43,line="A";
    vp=getVisitorPtr(age,line);
    cout<<vp->cost()<<endl;
    delete vp;
    age=14,line="B";
    vp=getVisitorPtr(age,line);
    cout<<vp->cost()<<endl;
    delete vp;
    age=67,line="C";
    vp=getVisitorPtr(age,line);
    cout<<vp->cost()<<endl;
    delete vp;
    return 0;
}

