#include <stdio.h>
#include <string.h>
#define maxn 100005

int ans[maxn];
int generate(int n)
{
    int result, current_digit;
    result = n;
    while(n>0){
        current_digit = n%10;
        result += current_digit;
        n = n/10;
    }
    return result;
}
int main()
{
    memset(ans, 0, sizeof(ans));
    int temp;
    for(int i=1;  i<=100000; i++){
        temp = generate(i);
        if(ans[temp]==0 || ans[temp]>i)ans[temp] = i;
    }
    int predict;
    while(scanf("%d", &predict) == 1 && predict != 0){
        printf("%d", ans[predict]);
    }
}

//最后添加循环