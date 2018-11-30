#include <stdio.h>
#include <string.h>

#define maxn 1000
/*
思路。
输入三组数据，
回合数
单词
字母集


判断函数
	单个字母判断
	如果相等就成为空。
	如果left = 0则win
	如果chance = 0则lose.

*/
void guess(char ch);
char computer[maxn];
char input[maxn];
int win, lose;
int left, chance;
int main(int argc, char const *argv[])
{
    int rnd;

    while(scanf("%d%s%s", rnd, computer, input) == 3 && rnd!=-1){
        win = 0;lose = 0;
        left = strlen(computer);
        chance = 7;
        for(int i; i<strlen(input); i++){
            guess(input[i]);
            if(win || lose)break;
        }
        if(win){
            printf("You win！\n");
        }
        else printf("You Lose!\n");
    }
     
    return 0;
}

void guess(char ch)
{
    int bad = 1;
    for(int i; i<strlen(computer); i++)
        if(computer[i] == ch){ left--; computer[i] = ' '; bad = 0;}
    if(bad)chance--;
    if(!chance)lose = 1;
    if(!left)win = 1;
    
}

