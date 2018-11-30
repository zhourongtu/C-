#include <stdio.h>
#define maxn 100
int canDown(int i, int j);
int canRight(int i, int j);
char crossWords[maxn][maxn];

int main(int argc, char const *argv[])
{
    int r, c;
    scanf("%d%d", &r, &c);
    getchar();

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            scanf("%c", &crossWords[i][j]);
        }
        getchar();
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(canRight( i, j)){
                for(int d=j; d<c; d++){
                    if(crossWords[i][d] == '*')break;
                    printf("%c", crossWords[i][d]);
                }
                printf("\n");
            }
            if(canDown( i, j)){
                for(int d=i; d<r; d++){
                    if(crossWords[d][j] == '*')break;
                    printf("%c", crossWords[d][j]);
                }
                printf("\n");
            }
            
        }
    }

    return 0;
}

int canRight(int i, int j)
{
    if (crossWords[i][j] != '*'){
        if(j==0) return 1;
        else if(crossWords[i][j-1] != '*' ){
            return 0;
        }
        else return 1;
    }
    else return 0;
}


int canDown(int i, int j)
{
    if (crossWords[i][j] != '*'){
        if(i==0) return 1;
        else if(crossWords[i-1][j] != '*'){
            return 0;
        }
        else return 1;
    }
    else return 0;
}