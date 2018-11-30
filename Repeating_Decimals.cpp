#include <stdio.h>
#include<string.h>

#define maxn 1000

/*
一、如何取得小数
a = a%b * 10
d = a/b得到小数点后一位
*/


/*
解决周期串的问题
输入一个串，输出其最小周期的大小
一、输入一个串
二、其周期可能是1~m（串长）
三、对一个长度，来判断是否是周期
*/

/*
改进一下，从0开始
在判断循环周期的时候，先去掉前面的0。从0以后开始判断是否循环
，加入，找出0的个数，加上去
*/

int period(int str[])
{   
    int flag = 0;
    int count=0;/*记录0的个数*/
    for(int i=0; i<maxn; i++){
        if(str[i] == 0){
            count++;
        }
        else break;
    }
    for(int i=1; i<=maxn; i++){
        flag = 0;
        for(int j=0; (j+count) < maxn; j++){
            if(str[(j+i)%i + count] != str[j + count]){
                flag = 1;break;
            }
        }
        if(flag==0){
            return i;
        }
    }
}

int main()
{
    int a; int b;
    char str[maxn];
    scanf("%d%d", &a, &b);
    int d;
    a = a%b * 10;
    int res[maxn];
    memset(res, 0, sizeof(res));

    for(int i=0; i<maxn; i++){
        d = a/b;
        a = a%b * 10;
        res[i] = d;
    }

    int n;
    n = period(res);


    printf("0.");
    int temp=0;
    while(res[temp]==0){
        printf("%d", res[temp]);
        temp++;
    }
    int flag=0;
    for(int i=temp; i<temp+n; i++){
        if(!flag){
            printf("(");
            flag = 1;
        }
        printf("%d", res[i]);
    }
    printf(")");

    
    return 0;
}

