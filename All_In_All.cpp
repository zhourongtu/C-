#include <stdio.h>
#include <string.h>

#define maxn 1000
int main(int argc, char const *argv[])
{
    char s[maxn];
    char t[maxn];

    scanf("%s", s);
    scanf("%s", t);
    
    int n,m;
    n = strlen(s);
    m = strlen(t);
    int j = n-1;
    int flag = 0;
    for(int i=m-1; i>=0; i--){
        if(t[i] == s[j])j--;
        if(j<0){
            flag = 1;
            break;
        }
    }
    if(flag)printf("Is true");
    else printf("Not True");
    return 0;
}
