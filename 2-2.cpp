/*设计一个图书类Book，该类有书名、作者、isbn、价格，出版日期五个数据成员。其中出版日期是Date类的对象。
main函数的代码已经给出，请根据main函数代码和对应的输出给出Book类和Date类的代码。（需要提交main函数之外的其他代码部分）*/
#include <iostream>
using namespace std;
class Date{
    private:
    int year,month,day;
    public:
    Date(int,int,int);
    Date(){};
    friend class Book;
};
class Book{
    private:
    string name,author,isbn;
    double price;
    Date d;
    int y,m,a;
    public:
    Book(string,string,string,class Date &,double);
    void printInfo();
};
Date::Date(int y,int m,int d):year(y),month(m),day(d){};
Book::Book(string n,string a,string i,class Date &d,double p):name(n),author(a),isbn(i),price(p){
    y=d.year;
    m=d.month;
    a=d.day;
};
void Book::printInfo()
{
    cout<<name<<" "<<author<<" "<<isbn<<" "<<price<<endl<<y<<"/"<<m<<"/"<<a<<endl;
}
int main(){
    int year,month,day;
    string name,author,isbn;
    double price;
    cin>>year>>month>>day;
    Date date(year,month,day);
    cin>>name>>author>>isbn>>price;
    Book b(name,author,isbn,date,price);
    b.printInfo();
    return 0;

}
/*输入：
2018 8 1
C++Programming Mike 12345 35.0
输出：
C++Programming Mike 12345 35
2018/8/1*/