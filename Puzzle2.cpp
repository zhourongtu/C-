#include <stdio.h>
#include <string.h>
#define maxn 1000
char puzzle[maxn][maxn];


int main(int argc, char const *argv[])
{
    memset(puzzle, 0, sizeof(puzzle));
    int n;
    scanf("%d", &n);
    getchar();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%c", &puzzle[i][j]);
        }
    }
    getchar();
    int x; int y;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(puzzle[i][j] == '0'){
                x = i;
                y = j;
            }


    char instruction[maxn];
    scanf("%s", instruction);
    int m;
    m = strlen(instruction);
    int flag = 0;
    for(int i=0; i<m; i++){
        switch(instruction[i]){
            case 'A':{//上字母移动，相当于0上移
                if(x==0)flag = 1;
                else{
                    puzzle[x][y] = puzzle[x-1][y];
                    puzzle[x-1][y] = '0';
                    x--;
                }
                break;
            }
            case 'B':{//下字母移动
                if(x==n-1)flag = 1;
                else{
                    puzzle[x][y] = puzzle[x+1][y];
                    puzzle[x+1][y] = '0';
                    x++;
                }
                break;
            }
            case 'C':{//左字母移动
                if(y==0)flag = 1;
                else{
                    puzzle[x][y] = puzzle[x][y-1];
                    puzzle[x][y-1] = '0';
                    y--;
                }
                break;
            }
            case 'D':{
                if(y==n-1)flag = 1;
                else{
                    puzzle[x][y] = puzzle[x][y+1];
                    puzzle[x][y+1] = '0';
                    y++;
                }
                break;
            }
            if(flag) break;
        }
    }

    
    if(flag){
        printf("the instruction is wrong");
    }   
    else{
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                printf("%c ", puzzle[i][j]);
            }
            printf("\n");
        }
    } 

    return 0;
}
