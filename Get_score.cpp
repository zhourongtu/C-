#include <stdio.h>
#include <string.h>

#define maxn 1000

int main(int argc, char const *argv[])
{
    char str[maxn];
    int flag;
    scanf("%s", str);
    int m = strlen(str);
    for(int i=1; i<=m; i++){
        flag = 1;
        for(int j=0; j<m; j++){
            if(str[j] != str[j%i])flag = 0;
        }
        if(flag){
            printf("the Minimum is %d", i);
            break;
        }
    }
    
    return 0;
}
