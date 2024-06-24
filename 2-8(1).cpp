/*Internet上的主机需要IP地址才能联入网络。在计算机系统内部，IP地址（IPv4）是一个32位的整数。但是为了便于表达，人们将它转换为点分十进制形式。
所谓点分十进制形式，就是将32位整数的四个字节分别转换为一个0~255之间的整数，然后把这四个整数用点连接起来的表示形式。
例如：整数-1455049865（十六进制表示为0xA945B377），其四个字节的十六进制值分别是A9、45、B3和77，对应的十进制值为169、69、179和119，因此对应的点分十进制IP地址为：169.69.179.119。
和IP地址对应的还有一个概念：子网掩码。
子网掩码也是一个32位的整数，这个整数的二进制表示由一串连续的1和一串连续的0组成，子网掩码也可以表示成点分十进制的形式，
例如255.255.255.0（十六进制为0xFFFFFF00），这个子网掩码由24个1和8个0组成。
每个IP地址都有一个对应的子网掩码。
子网掩码为1的位对应在IP地址中为网络ID，子网掩码为0的位对应在IP地址中为主机ID。
如果将IP地址中的主机ID部分清零，则可以得到该主机IP所在的网络的IP地址。例如上面的IP地址169.69.179.119，如果子网掩码为255.255.255.0，则其所在网络的IP地址为169.69.179.0。
请设计一个IP地址类，该类存储一个IP地址及对应的子网掩码信息。通过下面写好的main函数来使用IP地址类。*/
#include <iostream>
#include <math.h>
using namespace std;
string s="0123456789ABCDEF";
class IPAddr
{
    private:
    int ip,id;
    int *r;
    char *c;
    public:
    IPAddr(int p,int d):ip(p),id(d){};
        void showIPInfo()
    {
        int i=0;
        r=new int;
        c=new char;
        if(ip<0)
        {
            ip=-ip;
            ip-=1;
            while(ip!=0)
            {
                r[i++]=ip%2;
                ip/=2;
            }
            for(int j=0;j<i;j++)
            {
                if(r[j]==1) r[j]=0;
                else r[j]=1;
            }
            for(int m=0;m<i;m++)
            {
                ip=ip+pow(2,m)*r[m];
            }   
        }

            while(ip!=0)
            {
                r[i++]=ip%16;
                ip/=16;
            }
        for(int j=0;j<i;j++) cout<<s[r[j]];
        int k=0;
        for(int j=i-1;j>=0;j--)
        {
            c[k++]=s[r[j]];
        }
        for(int i=0;i<k;i++) cout<<c[i];
        cout<<endl;
        int ret[2]={0};
        for(int i=0,j=0,flag=0;i<k;i++,flag++)
        {
            switch (c[i])
            {
            case 'A':
                ret[j++]=10;
                break;
            case 'B':
                ret[j++]=11;
                break;
            case 'C':
                ret[j++]=12;
                break;
            case 'D':
                ret[j++]=13;
            case 'E':
                ret[j++]=14;
            case 'F':
                ret[j++]=15;
            default:
                ret[j++]=c[i]-'0';
                break;
            }
            if(j==2)
            {
                cout<<ret[0]+ret[1]*16<<".";
                j=0;
            }
        }
    }
};
  int main(){
      int n,m;
      cin>>n>>m;
      IPAddr myip(n,m);
      myip.showIPInfo();
      return 0;
   }

/*
输入描述
      输入一个整数n和一个4~30之间的正整数m，使用n来初始化IP地址（IP地址的二进制表示和n一摸一样），使用m来初始化子网掩码，m代表子网掩码中1的个数
输出描述
    分三行分别输出IP地址、子网掩码和网络地址的点分十进制形式
    */