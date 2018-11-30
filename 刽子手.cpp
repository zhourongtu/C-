#include <stdio.h>
#include <string.h>
/*
一、猜测导致什么结果？
对：计算机画一笔，去掉字符-->如果全猜出来用left表示，胜利
错：机会减少，如果机会=0，则失败
所以很清晰了
*/
#define maxn 1000
int left, chance;
int win; int lose;
char s1[maxn];
char s2[maxn];
void guess(char a);
int main(int argc, char const *argv[])
{
    int rnd;
    while(scanf("%d%s%s", &rnd, s1, s2)==3 && rnd!=-1){
        left = strlen(s1);
        win = 0;
        lose = 0;
        chance = 7;
        for(int i=0; i<strlen(s2); i++){
            guess(s2[i]);
        }
        if(chance == 0)lose = 1;
        if(left == 0)win = 1;
        if(win){
            printf("You win!");
        }
        else{
            printf("You lose!");
        }

    }
    
    return 0;
}

void guess(char a)
{
    int flag = 0;
    for(int i=0; i<strlen(s1); i++){
        if(s1[i] == a){
            flag = 1;
            s1[i] = ' ';
            left--;
        }
    }
    if(!flag){
        chance--;
    }
    if(left==0)win=1;
    if(chance==0)lose = 1;
}
