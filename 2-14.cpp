/*要求定义一类A，其有私有成员name(string类型)及其他成员。请完成类A的定义，使得类A只能被实例化为唯一的一个对象。*/
#include <iostream>
#include <string>
using namespace std;
class A
{
    private:
    A(string n):name(n){};
    string name;
    public:
    ~A(){};
    static class A *GetObject(string n)
    {
        static A *a=new A(n);
        return a;
    }
    void Print()
    {
        cout<<name<<endl;
    }
};
int main() {
	string name1,name2;
	cin >> name1;
	cin >> name2;
	A* o1 = A::GetObject(name1);
	o1->Print();
	A* o2 = A::GetObject(name2);
	o2->Print();
	if (o1 == o2)
	{
		cout << "o1与o2指向的是同一个对象！" << endl;
	}
	delete o1;
	return 0;
}
/*提示
1.​对象的构建通过构造函数完成，类A只能被实例化为唯一的一个对象，则构造函数不能放置于公有段。
2.类A必须提供一个唯一的全局访问函数供外界获得唯一的对象，此函数需要定义为类级别的函数。
请思考一个问题：在main函数中“delete o1;”下加“delete o2;”可行吗？为什么？*/