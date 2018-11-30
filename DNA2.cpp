#include <stdio.h>
#include <string.h>

#define maxn 1000

int dictionary(char a[], char b[])
{
    int m;
    m = strlen(a);
    for(int i=0; i<m; i++){
        if(a[i] < b[i])return 1;
        else if(a[i] > b[i])return 0;
    }
    return 0;
}

int hamming(char a[], char b[])
{
    int m = strlen(a);
    int count = 0;
    for(int i=0; i<m; i++){
        if(a[i] == b[i])count++;
    }
    return count;
}

char DNA[maxn][maxn];
int main()
{


    int m, n;
    scanf("%d%d", &m, &n);
    getchar();

    for(int i=0; i<m; i++){
        scanf("%s", DNA[i]);
    }

    int count[maxn];
    int min = maxn;
    memset(count, 0, sizeof(count));
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            count[i] += hamming(DNA[i], DNA[j]);
        }
        if(count[i] < min){
            min = count[i];
        }
    }

    int flag = 0;
    int minItem=0;
    for(int i=0; i<m; i++){
        if(count[i] == min){
            if(!flag){
                minItem = i;
            }
            else{
                if(dictionary(DNA[i], DNA[minItem])){
                    minItem = i;
                }
            }
        }
    }


    printf("%s\n", DNA[minItem]);
    return 0;


}