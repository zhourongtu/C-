#include <stdio.h>

#define maxn 1000
/*
这个难度也不是很大。调试的时候逻辑顺序弄错了。害的多花了时间。
*/

/*
思考思路打一下。
输入n1，n2
存储数组a1，a2
来一个startPos =0
循环0-n2-1，以a2为基准
如果judge(数组1，n1， 数组2， n2， startPos)则{
    num = startPos + n1;
    break
}
一个judge怎么写。
先是单个
if(array1[i] + array2[i+startPos] > 3){
    flag = 0;
}再添加循环。注意：此处要循环条件 是&&，要么第一个数组到结束，要么第二个


*/
int judge(int array1[], int n1, int array2[], int n2, int startPos)
{
    int flag =1;
    for(int i=0; (startPos+i)<n2 && i<n1; i++){
        if(array1[i] + array2[startPos + i] > 3){
            flag = 0;
            break;
        }
    }
    if(flag){
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int n1, n2;
    int array1[maxn], array2[maxn];
    scanf("%d%d", &n1, &n2);

    for(int i=0; i<n1; i++){
        scanf("%d", &array1[i]);
    }
    for(int i=0; i<n2; i++){
        scanf("%d", &array2[i]);
    }
    int startPos = 0;
    int num = maxn;
    for(; startPos<n2-1; startPos++){
        if(judge(array1, n1, array2, n2, startPos)){
            num = startPos + n1;
            if(num < n2)num = n2;/*假如比n2还要小的话，则直接n2*/
            break;
        }
    }

    printf("The min is %d",num);
    return 0;
}
