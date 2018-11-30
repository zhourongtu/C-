#include <stdio.h>

#define maxn 1000

int main(int argc, char const *argv[])
{
    int n;
    int ans;
    char str[maxn];
    scanf("%d", &n);

    scanf("%s", str);
    ans = 0;
    for(int i=1; i<n; i++){
        for(int j=0; j<n; ){
            if(str[(i+j)%n] == str[(ans+j)%n]){
                j++;
            }
            else{
                if(str[(i+j)%n] < str[(ans+j)%n])
                    ans = i;
                break;
            }
            
        }
    }
    for(int i=0; i<n; i++){
        printf("%c", str[(ans+i)%n]);
    }
    return 0;
}
