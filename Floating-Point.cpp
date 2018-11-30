#include <stdio.h>
#include <math.h>

/*
这道题本质上并不是什么难题。
主要是相当于数学上的一个式子的证明。
而这边较为愚蠢，列举所有式子，如果相同。找出那个数。
我们要知道的是关于最大浮点数的表示。
阶码为6，尾数为8的可表达最大的浮点数是0.111111111(2)*2^111111(2) 换算十进制为  0.998046875*2^63

而, 0.998046875*2^63=9.205357638345294*10^18

等价于               m*2^e=a*10^b        其中m为1-pow(2,-i-1)，e为pow(2,j)-1，当i=8,j=6时，m*2^e得到0.998046875*2^63

两边取对数     log10(m)+e*log10(2)=log10(a)+b

当 temp= log10(m)+e*log10(2),     temp=log10(a)+b 也成立, a,b为未知数，因为a<10,所以0<log10(a)<1

b=(int)temp，a=10^(temp-b),a为输入的9.205357638345294，b为18

而思路也仅此而已。

假设阶码数，假设尾数。
取得最后结果与输入值进行比较。如果误差很小也就是相等，则正好。否则就有问题。
*/
#define EPS 1e-5
int main(int argc, char const *argv[])
{
    int m, e;

    double a;
    int b;
    scanf("%lf e %d", &a, &b);
    int B;    
    double A;
    double temp;
    for(int i=1; i<10; i++){
        int flag = 0;
        for(int j=1; j<31; j++){
            temp = log10((1.0 - pow(2.0, -1.0*double(i)))) + (pow(2.0, j)-1)*log10(2.0);
            B = int(temp);
            A = pow(10,temp-b);
            if(abs(A-a) < EPS && B==b){
                flag = 1;            
                m = i;
                e = j;
                break;
                
            }
        }
        if(flag){
            break;
        }
    }
    printf("\n%d and %d", m, e);
    return 0;
}
