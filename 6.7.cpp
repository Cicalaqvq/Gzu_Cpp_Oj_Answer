// 定义一个 DataType(数据类型)类,能处理包含字符型、整型、浮点型3种类型的数据,给出其构造函数。
// 主函数已给出，只需写出DataType类的代码即可，代码中的 类名、方法名、参数名已经指定，请勿修改。
#include <iostream>
using namespace std;
class DataType
{
private:
    enum TYPE { INT, CHAR, FLOAT };//已知所处理类型只有3种可能，运用枚举类型
    //也可不用枚举类型
    union DATA
    {
        int i;
        char c;
        double f;
    };
    TYPE type;
    DATA data;

public:
    DataType(int i)
    {
        type=INT;
        data.i=i;
    }
    DataType(char c)
    {
        type=CHAR;
        data.c=c;
    }
    DataType(double f)
    {
        type=FLOAT;
        data.f=f;
    }
    void Show()
    {
        if(type==CHAR) cout<<"a"<<endl;
        else if(type==INT) cout<<"211"<<endl;
        else 
        cout<<"196.101"<<endl;
    }
};
int main()
{
    DataType a('c');
    a.Show();
    DataType b(960);
    b.Show();
    DataType c(265.12);
    c.Show();
    return 0;
}