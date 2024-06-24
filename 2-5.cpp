/*
定义一个氧化物类Oxide，它包含四个私有数据成员，第一、三个数据成员（按惯例第三个成员必定是氧）都是元素类（Element）对象，第二、四个数据成员是这两个元素的个数。
元素类需要单独定义，包含私有数据成员英文元素符号以及必要的成员函数。
请为Oxide类定义有关成员函数，包括构造函数、打印分子式的函数。
为两个类添加你认为必要的其它成员函数。
在主函数中建立元素类的几个对象（如氢H、碳C、铁Fe、氧O等），再建立Oxide类的几个对象（如H2O水、CO一氧化碳、CO2二氧化碳、SO2二氧化硫、P2O5五氧化二磷、FeO氧化亚铁、Fe3O4四氧化三铁等等）并进行测试。
提示：当元素个数为1时，其分子式不显示个数，例如一氧化碳写作CO而不是C1O1。
main函数已经写好，请根据main函数的内容完成相关类的定义。
*/
#include <iostream>
using namespace std;
class Element{
    private:
    string s;
    public:
    friend class Oxide;
    Element(string);
    Element();
};
class Oxide{
    private:
    Element e1,e2;
    int c1,c2;
    public:
    Oxide(class Element &,int,class Element &,int);
    void printformula();
};
Element::Element(string s):s(s){};
Element::Element():s("O"){};
Oxide::Oxide(class Element &e1,int c1,class Element &e2,int c2):e1(e1),e2(e2),c1(c1),c2(c2){};
void Oxide::printformula()
{
    if(c1==1)
    {
        cout<<e1.s;
        if(c2==1)
        cout<<e2.s;
        else
        cout<<e2.s<<c2;
        cout<<endl;
    }
    else
    {
        cout<<e1.s<<c1;
        if(c2==1)
        cout<<e2.s;
        else
        cout<<e2.s<<c2;
        cout<<endl;
    }
}
int main(){
    string symbol="H";
    Element e1(symbol);
    Element e2;
    Oxide o1(e1,2,e2,1);
    o1.printformula();
    symbol="C";
    Element e3(symbol);
    Oxide o2(e3,1,e2,1);
    o2.printformula();
    symbol="S";
    Element e4(symbol);
    Oxide o3(e4,1,e2,2);
    o3.printformula();
    symbol="Fe";
    Element e5(symbol);
    Oxide o4(e5,3,e2,4);
    o4.printformula();
    symbol="P";
    Element e6(symbol);
    Oxide o5(e6,2,e2,5);
    o5.printformula();
    return 0;
}
/*
样例输出:
H2O
CO
SO2
Fe3O4
P2O5
*/