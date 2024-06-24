// 构造一个Matrix类，有一个private的3x3矩阵，
// 和void setMatrix()输入矩阵方法，
// Matrix mutipleMatrix(Matrix b)矩阵乘法方法，void printMatrix()输出矩阵方法。
// ​你只需要写出Matrix类即可，主函数已给出除主函数定义的方法名及参数名外，
// 其余名称或方法可自行添加或修改
#include <iostream>
using namespace std;
class Matrix{
private:
    int m[3][3];

public:
    void setMatrix(){
        for(int i=0;i<3;++i)
        {
            for(int j=0;j<3;j++)
            {
                cin>>m[i][j];
            }
        }
    }
    Matrix mutipleMatrix(Matrix b)
    {
        Matrix ret;
        int k=0;
      for(int i=0;i<3;i++)
      {
        for(int j=0;j<3;j++)
        {
            ret.m[i][j]=m[i][0]*b.m[0][j]+m[i][1]*b.m[1][j]+m[i][2]*b.m[2][j];
        }
      }
      return ret;
    }
    void printMatrix()
    {
       for(int i=0;i<3;i++)
       {
        for(int j=0;j<3;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
       }
    }
};

int main()
{
    Matrix a,b,c;
    a.setMatrix();
    b.setMatrix();
    c=a.mutipleMatrix(b);
    c.printMatrix();
    return 0;
}