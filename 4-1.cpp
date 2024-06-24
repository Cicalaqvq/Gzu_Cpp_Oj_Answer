//  设计一个矩阵类，当创建矩阵类的对象时，根据提供的行数和列数信息，内部可以通过动态内存分配的机制创建一个任意大小的二维数组用来存储矩阵的数据。
// 相应的，对象析构时应该释放动态分配的数组。对Matrix类重载以下运算符：
// （1）将下标运算符[]重载为矩阵类的成员函数，实现用对象名加两个下标的形式能够直接访问二维数组元素的效果；
// （2）重载“<<”运算符，实现矩阵的输出功能；
// （3）重载“+”运算符（重载为非成员的形式），实现矩阵加法；
// （4）重载“*”运算符（重载为非成员的形式），实现矩阵乘法；
// main函数已经写好，请根据main函数的内容完成该类的设计。
#include <iostream>
using namespace std;
class Matrix
{
    private:
    int rows,columns;
    int **array;
    public:
    Matrix(int ,int);
    int getRows();
    int getColumns();
    friend Matrix operator+(const Matrix &m,const Matrix &n)
    {
        Matrix ret(m.rows,m.columns);
        for(int i=0;i<m.rows;i++)
        {
            for(int j=0;j<n.columns;j++)
            {
                ret.array[i][j]=m.array[i][j]+n.array[i][j];
            }
        }
        return ret;
    }
    friend Matrix operator*(const Matrix &m,const Matrix &n)
    {
        Matrix ret(m.rows,n.columns);
        for(int i=0;i<m.rows;i++)
        {
            for(int j=0;j<n.columns;j++)
            {
                ret.array[i][j]=0;
            }
        }
        int sum[m.rows*n.columns]={0};
        int tempr=0,tempc=0,flag=0;
        while(tempr<m.rows)
        {
            for(int j=0;j<m.columns;j++)
            {
                sum[flag]+=m.array[tempr][j]*n.array[j][tempc];
            }
            tempc++;
            flag++;
            if(tempc==n.columns) //第一行乘以第x列遍历完
                {
                    tempc=0;
                    tempr++;
                }
        }
        int k=0;
        for(int i=0;i<m.rows;i++)
        {
            for(int j=0;j<n.columns;j++)
            {
                ret.array[i][j]=sum[k++];
            }
        }
        return ret;
    }
    friend ostream &operator <<(ostream &output, const Matrix &m )
    {
        for(int i=0;i<m.rows;i++)
        {
            for(int j=0;j<m.columns;j++)
            {
                output<<m.array[i][j]<<" ";
            }
            output<<endl;
        }
        return output;
    }
    
    int * operator[](int i)
    {
        return array[i];
    }
};
Matrix::Matrix(int a,int b):rows(a),columns(b)
{
    array=new int * [rows];
    for(int i=0;i<rows;i++)
    {
        array[i]=new int[columns];
    }
}
int Matrix::getRows() {return rows;}
int Matrix::getColumns() {return columns;}
int main(){
    int a,b;
    cin>>a>>b;
    Matrix m1(a,b),m2(a,b),m3(b,a);
    int i,j;
    for(i=0;i<m1.getRows();i++)
        for(j=0;j<m1.getColumns();j++)
            cin>>m1[i][j];
    for(i=0;i<m2.getRows();i++)
        for(j=0;j<m2.getColumns();j++)
            cin>>m2[i][j];

    for(i=0;i<m3.getRows();i++)
        for(j=0;j<m3.getColumns();j++)
            cin>>m3[i][j];  
    cout<<"Matrix M1:"<<endl;
    cout<<m1;
    cout<<"Matrix M2:"<<endl;
    cout<<m2;
    cout<<"Matrix M3:"<<endl;
    cout<<m3;
    cout<<"Result of Matrix Addition:"<<endl;
    cout<<m1+m2;
    cout<<"Result of Matrix Multiplication:"<<endl;
    cout<<m1*m3;
    return 0;

}