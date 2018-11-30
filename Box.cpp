#include <stdio.h>

typedef struct{
    int x;
    int y;
}rectangular;

int main(int argc, char const *argv[])
{
    rectangular Box[6];
    for(int i=0; i<6; i++){
        scanf("%d%d", &Box[i].x, &Box[i].y);
    }

    /*排序*/
    rectangular temp;
    for(int i=0; i<6; i++){
        for(int j=i+1; j<6; j++){
            if(Box[i].x < Box[j].x){
                temp = Box[i];
                Box[i] = Box[j];
                Box[j] = temp;
            }
        }
    }

    int flag = 1;
    /*判断0 1是否相等 2 3是否相等 4 5是否相等*/
    for(int i=0; i<6; i+=2){
        if(Box[i].x != Box[i+1].x || Box[i].y != Box[i].y){
            flag = 0;
            break;
        }
    }
    /*判断0 2 4 是否可以构成一个立方体
    判断方法是依次等价
    0的x等于2的y，2的x 等于4的y 4的x=0的y
    或者0的x = 4的y，2的x等于0的y，4的x = 2的y*/
    flag = 0;
    if(Box[0].x == Box[2].y && Box[2].x == Box[4].y && Box[4].x == Box[0].y){
        flag = 1;
    }
    else if(Box[0].x == Box[4].y && Box[2].x == Box[0].y && Box[4].x == Box[0].y){
        flag = 1;
    }
    if(flag){
        printf("OK");
    }
    else{
        printf("No");
    }
}
