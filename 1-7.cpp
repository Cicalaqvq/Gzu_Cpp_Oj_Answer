/*创建一个二维数组类Array2D。该类有私有成员rows，用于表示内部的double型二维数组的行数。
创建二维数组类对象时，需初始化rows，并根据它们的值在内部动态内存分配一个rows行8列的double型二维数组。
该类有返回行数和列数的成员函数；有求全数组平均值的成员函数；有求某一行平均值成员函数；
该类还有求全数组最大值和最小值的成员函数，以及求某一行最大值或最小值的成员函数。
请根据下面的main函数完成该类的设计：*/
#include <iostream>
using namespace std;
class Array2D
{
private:
int rows,columns=8;
double **a;
public:
int getRows();
int getColumns();
double getMaxOfRow(int);
double getMinOfRow(int);
double getAvgOfRow(int);
double getMinOfArray();
double getMaxOfArray();
void setElem(int,int,double);
double getAvgOfArray();
Array2D(int);
~Array2D();
};
Array2D::Array2D(int c):rows(c){
     a=new double *[rows];
     for(int i=0;i<columns;i++)
     {
        a[i]=new double[columns];
     }

};
void Array2D::setElem(int i,int j,double n)
{
a[i][j]=n;
}
int Array2D::getRows()
{
    return rows;
}
int Array2D::getColumns()
{
    return columns;
}
double Array2D::getMaxOfRow(int d)
{
    double flag=a[d][0];

        for(int j=0;j<columns;j++)
        {
            if(a[d][j]>flag)
            {
                flag=a[d][j];
            }
        }

    return flag;
}
double Array2D::getMinOfRow(int d)
{
        double flag=a[d][0];
        for(int j=0;j<columns;j++)
        {
            if(a[d][j]<flag)
            {
                flag=a[d][j];
            }
        }

    return flag;
}
double Array2D::getAvgOfRow(int d)
{
    double sum=0;
    for(int j=0;j<columns;j++)
    {
        sum+=a[d][j];
    }
    return sum/columns;
}
double Array2D::getMaxOfArray()
{
        double flag=a[0][0];
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            if(a[i][j]>flag)
            {
                flag=a[i][j];
            }
        }
    }
    return flag;
}
double Array2D::getMinOfArray()
{
            double flag=a[0][0];
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            if(a[i][j]<flag)
            {
                flag=a[i][j];
            }
        }
    }
    return flag;
}
double Array2D::getAvgOfArray()
{
    double sum=0;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            sum+=a[i][j];
        }
    }
    return sum/(rows*columns);
}
Array2D::~Array2D()
{
    cout<<"释放了一个"<<rows<<"行"<<columns<<"列的数组"<<endl;
}
int main()
{
int r;
double n;
cin>>r;
Array2D arr(r);
int i,j;
for(i=0;i<r;i++)
for(j=0;j<8;j++){
cin>>n;
arr.setElem(i,j,n);
}
cout<<arr.getRows()<<" "<<arr.getColumns()<<endl;
cout<<arr.getMaxOfRow(0)<<" "<<arr.getMinOfRow(0)<<" "<<arr.getAvgOfRow(0)<<endl;
cout<<arr.getMaxOfRow(r-1)<<" "<<arr.getMinOfRow(r-1)<<" "<<arr.getAvgOfRow(r-1)<<endl;
cout<<arr.getMaxOfArray()<<" "<<arr.getMinOfArray()<<" "<<arr.getAvgOfArray()<<endl;
return 0;
}