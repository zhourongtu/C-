#include <stdio.h>

#define maxn 100
char crossWords[maxn][maxn];
int main()
{
    int i, j;
    int r, c;
    scanf("%d%d", &r, &c);
    getchar();
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            scanf("%c", &crossWords[i][j]);
        }
        getchar();
    }

    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            if(crossWords[i][j] != '*'){
                if(j==0 || crossWords[i][j-1] == '*'){
                    for(int d=j; d<c; d++){
                       if(crossWords[i][d] == '*')break;
                       printf("%c", crossWords[i][d]);
                    }
                    printf("\n");
                }
                if(i==0 || crossWords[i-1][j] == '*'){
                    for(int d=i; d<r; d++){
                        if(crossWords[d][j] == '*')break;
                        printf("%c", crossWords[d][j]);
                    }
                    printf("\n");
                }
            }
        }
    
    }
}