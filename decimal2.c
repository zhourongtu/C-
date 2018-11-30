#include <stdio.h>
#include <stdlib.h>
//最大的精度
#define MAX_LENGTH 120
 
//计算商
int GetFactor(int a, int b)
{
    return a / b;
}
 
//计算余数
int GetRemainder(int a, int b)
{
    return a - (a/b * b);
}
 
//是否整除
bool IsAliquot(int a, int b)
{
    bool ret = false;
    if(a%b == 0)
    {
        ret = true;
    }
    return ret;
}
 
//模拟竖式计算
void Division(int a, int b, int precision, int ans[MAX_LENGTH])
{
    if(precision > MAX_LENGTH)
    {
        return;
    }
    int i=0;
    for(i=0; i<MAX_LENGTH; i++)
    {
        ans[i] = 0;
    }
     
    int calA = a, calB = b;
    ans[0] = GetFactor(calA, calB);
     
    //模拟竖式计算
    for(i=1; i<=precision; i++)
    {
        if(IsAliquot(calA, calB) == true)//已经整除，不需要再继续进行下去
        {
            break;
        }
        calA = GetRemainder(calA, calB);
        calA *= 10;
        ans[i] = GetFactor(calA, calB);
    }
}
 
int main()
{
    int ans[MAX_LENGTH] = {0};
    int a = 20;
    int b = 3;
    int c = 20;
 
    if (c > MAX_LENGTH)
    {
        return 1;
    }
 
    //计算
    Division(a, b, c, ans);
     
    printf("%d / %d , the answer is:(precision:%d)\n",a, b, c);
    printf("%d . ",ans[0]);
     
    int i = 0;
    for(i=1; i<=c ; i++)
    {
        printf("%d",ans[i]);
        if(i%10==0)
        {
            printf("  ");
        }
    }
    printf("\n");
 
    printf("Calculation finished!\n");
    return 0;
}