#include <stdio.h>
#include <string.h>

#define maxn 1000
char s1[maxn], s2[maxn];

int left, chance;
int win, lose;
int main()
{
    int rnd;
    while(scanf("%d%s%s", &n, s1, s2) == 3 && rnd != -1){
        printf("Round %d", rnd);
        win = lose = 0;
        left = strlen(s1);
        chance = 7;
        for(int i=0; i<strlen(s2); i++){
            guess(s2[i]);
            if(win || lose)break;
        }
        if(win)printf("You win\n");
        else if(lose)printf("You lose!\n");
        else printf("You chickend out.\n");
    }
    return 0;

}

void guess(char ch){
    int bad = 1;
    for(int i=0; i<strlen(s1); i++){
        if(s[i] == ch){
            left--; s[i]=' '; bad = 0;
        }
    }
    if(bad) --chance;
    if(!chance)lose = 1;
    if(!left)win = 1;

}