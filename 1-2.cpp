/*​设计一个矩形类Rectangle。其属性为矩形的左下角与右上角两个点的坐标。
main函数已经完成，请根据main函数完成该类的设计：
注意：输入应该保证右上顶点的横坐标大于左下顶点的横坐标且右上顶点的纵坐标大于左下顶点的纵坐标，如果不满足，则将所有坐标设置为0*/
#include <iostream>
using namespace std;
class Rectangle{
    private:
    int top, bottom, left, right;    
    public:
    Rectangle(int,int,int,int);
    void showLeftTop();
    void showRightTop();
    void showLeftBottom();
    void showRightBottom();
    int getHeight();
    int getArea();
    int getWidth();
    int getPerimeter();
};
    Rectangle::Rectangle(int a=0,int b=0,int c=0,int d=0){
       if((b>d)&&(a>c))
     {  top=a;
        right=b;
        bottom=c;
        left=d;
     }
     else{
        top=0;
        right=0;
        bottom=0;
        left=0;
     }
    }
    void Rectangle::showLeftTop(){
        cout<<left<<","<<top<<endl;
    };
    void Rectangle::showRightTop(){
        cout<<right<<","<<top<<endl;
    };
    void Rectangle::showLeftBottom(){
        cout<<left<<","<<bottom<<endl;
    };
    void Rectangle::showRightBottom(){
        cout<<right<<","<<bottom<<endl;
    };
    int Rectangle::getHeight(){
        return top-bottom;
    };
    int Rectangle::getArea(){
        return (right-left)*(top-bottom);
    };
    int Rectangle::getWidth(){
        return right-left;
    };
    int Rectangle::getPerimeter(){
        return ((right-left)+(top-bottom))*2;
    };
int main(){
int top, bottom, left, right;
cin>>top>>right>>bottom>>left;
Rectangle r(top, right, bottom, left); // 5 5 3 3
r. showLeftTop(); //输出左上顶点的坐标
r. showRightTop(); //输出右上顶点的坐标
r. showLeftBottom(); //输出左下顶点的坐标
r. showRightBottom(); //输出右下顶点的坐标
cout<<r. getHeight()<<" "<<r. getWidth()<<endl; //输出高和宽
cout<<r. getArea()<<" "<<r. getPerimeter()<<endl; //输出面积和周长
return 0;
}