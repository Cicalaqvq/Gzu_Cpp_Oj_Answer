// 根据main函数的内容倒推所涉及的几个类之间的关系，并完成这些的类的设计：
#include <iostream>
using namespace std;
class Base1
{
    public:
    void doSomething()
    {
        cout<<"Hello Base1"<<endl;
    }
};
class Base2:virtual public Base1
{
    public:
    void doSomething()
    {
        cout<<"Hello Base2"<<endl;
    }
}; 
class Derived1:virtual public Base1,public Base2
{
    public:
    void doSomething()
    {
        Base1::doSomething();
        Base2::doSomething();
        cout<<"Hi Derived1"<<endl;
    }
};
class Derived2:public Base1
{
    public:
    void doSomething()
    {
        Base1::doSomething();
        cout<<"Hi Derived2"<<endl;
    }
};
int main(){
	Base1 b1;
	Base2 b2;
	Derived1 d1;
	Derived2 d2;
	Base1 *bp;
	bp=&b2;
	bp->doSomething();  //(1)
	cout<<endl;
	
	bp=&d1;
	bp->doSomething();  //(2)
	cout<<endl;
	
	bp=&d2;
	bp->doSomething();   //(3)
	cout<<endl;
	
	Base2 &br=d1;
	br.doSomething();   //(4)
	cout<<endl;
	
	d1.doSomething();   //(5)
	cout<<endl;
	
	d2.doSomething();   //(6)
	return 0;
}
/*样例输出
Hello Base1

Hello Base1

Hello Base1

Hello Base2

Hello Base1
Hello Base2
Hi Derived1

Hello Base1
Hi Derived2

*/