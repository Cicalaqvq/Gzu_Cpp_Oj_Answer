// 定义一个抽象的饮料类Drinks，该类有一个数据成员brand（品牌），一个纯虚函数composition（成分），用于打印输出饮料的各种成分的含量。
// （1）请完成Drinks类的定义，定义你认为必要的任何成员；
// （2）请为Drinks类定义公有派生类Liquor（含酒精饮料）和Softdrinks（不含酒精饮料），Liquor类有alcoholicity（酒精含量）数据成员，Softdrinks类有sugarcontent（含糖量）数据成员。在这两个类中根据上述规则实现纯虚函数composition；
// （3）请为Softdrinks类定义公有派生类Milktea（奶茶）和Fruitjuice（果汁），它们分别有milkcontent（牛奶含量）和juicecontent（果汁含量）数据成员。在这两个类中根据上述规则覆盖函数composition；
// （4）在主函数中定义Drinks的指针并分别指向不同的派生类对象，调用composition输出不同饮料的成分含量。
// main函数已经写好，请根据main函数的内容完成上述所有类的设计。
#include <iostream>
using namespace std;
class Drinks
{
    protected:
    string brand;
    public:
    Drinks(string b):brand(b){};
    virtual void composition()=0;
    string getBrand(){
        return this->brand;
    }
};
class Liquor:public Drinks
{
    double alcoholicity;
    public:
    Liquor(string s,double a):Drinks(s),alcoholicity(a){};
    void composition()
    {
        cout<<"酒精含量:"<<alcoholicity*100<<"%\n";
    }
};
class Softdrinks:public Drinks
{
    protected:
    double sugarcontent;
    public:
    Softdrinks(string s,double u):Drinks(s),sugarcontent(u){};
    void composition()
    {
        cout<<"含糖量:每100ml"<<sugarcontent<<"克"<<endl;
    }
};
class Milktea:public Softdrinks
{
    double milkcontent;
    public:
    Milktea(string s,double a,double b):Softdrinks(s,a),milkcontent(b){};
    void composition()
    {
        cout<<"含糖量:每100ml"<<sugarcontent<<"克"<<endl;
        cout<<"牛奶含量:"<<milkcontent*100<<"%\n";
    }
};
class Fruitjuice:public Softdrinks
{
    double juicecontent;
    public:
    Fruitjuice(string s,double a,double b):Softdrinks(s,a),juicecontent(b){};
    void composition()
    {
        cout<<"含糖量:每100ml"<<sugarcontent<<"克"<<endl;
        cout<<"果汁含量:"<<juicecontent*100<<"%\n";
    }
};
int main(){
    Drinks *pd;
    Liquor liquor("乐堡啤酒",0.045);
    Softdrinks softdrinks("可口可乐",5.3);
    Milktea milktea("阿萨姆奶茶",6.7,0.1);
    Fruitjuice fruitjuice("汇源果汁",3.2,0.3);
    pd=&liquor;
    cout<<pd->getBrand()<<endl;
    pd->composition();
    pd=&softdrinks;
    cout<<pd->getBrand()<<endl;
    pd->composition();
    pd=&milktea;
    cout<<pd->getBrand()<<endl;
    pd->composition();
    pd=&fruitjuice;
    cout<<pd->getBrand()<<endl;
    pd->composition();
    return 0;

}

