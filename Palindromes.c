#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* msg[] = {"not a palindrome", "a regular palindrome", 
                    "a mirrored string", "a mirrored palindrome"};
//p用于判断是否回文，m用于判断是否镜像文。
//均不是为0，是回文不是镜像文则1,
//是镜像文不是回文则2
//是镜像文又是回文则3
//p+m*2
char r(char ch){
    if(isalpha(ch)) return rev[ch-'A'];
    return rev[ch-'0' + 25];
}
int main(int argc, char const *argv[])
{
    char s[30];
    int n;
    int p, m;
    int i;

    while(scanf("%s", s) == 1){
        n = strlen(s);
        p = 1; m = 1;
        for(i=0; i<(n+1)/2; i++){
            if(s[i] != s[n-1-i]) p = 0;//判断回文
            if(r(s[i]) != s[n-1-i]) m = 0;//判断镜像文
        }
        printf("%s\n", msg[p+2*m]);
    }
    return 0;
}
