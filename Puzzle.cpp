#include <stdio.h>
#include <string.h>
#define maxn 1000

/*
本次实现了一个推箱子一样的类似的玩意。
A代表箱子向下移动，
B代表箱子向上移动。
L代表箱子向左移动。
R代表箱子向右移动。
*/
char puzzle[maxn][maxn];
void printPuzzle();
int main(int argc, char const *argv[])
{
    memset(puzzle, 0, sizeof(puzzle));
    int n;
    char instruct[maxn];
    scanf("%d", &n);
    getchar();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%c", &puzzle[i][j]);
        }
    }
    getchar();
    
    int x; int y;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(puzzle[i][j] == '0'){
                x = i; y = j;
            }
        }
    }
    
    scanf("%s", instruct);
    int m;
    m = strlen(instruct);
    int flag = 0;
    for(int i=0; i<m; i++){
        switch(instruct[i]){
            case 'A':{
                if(x==0){
                    flag = 1;
                }
                else{
                    puzzle[x][y] = puzzle[x-1][y];
                    puzzle[x-1][y] = '0';
                    x = x-1;
                    y = y;
                }
                printPuzzle();
                break;
            }
            case 'B':{
                if(x==n-1){
                    flag = 1;
                }
                else{
                    puzzle[x][y] = puzzle[x+1][y];
                    puzzle[x+1][y] = '0';
                    x = x+1;
                    y = y;
                }
                printPuzzle();
                break;
            }
            case 'L':{
                if(y==n-1){
                    flag = 1;
                }
                else{
                    puzzle[x][y] = puzzle[x][y+1];
                    puzzle[x][y+1] = '0';
                    x = x;
                    y = y+1;
                }
                printPuzzle();
                break;
            }
            case 'R':{
                if(y==0){
                    flag = 1;
                }
                else{
                    puzzle[x][y] = puzzle[x][y-1];
                    puzzle[x][y-1] = '0';
                    x = x;
                    y = y-1;
                }
                printPuzzle();
                break;
            }

        }
        if(flag){
            break;
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

    /* code */
    return 0;
}

void printPuzzle()
{

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            printf("%c ", puzzle[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}