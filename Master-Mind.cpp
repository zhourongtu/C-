#include <stdio.h>
#define maxn 1000
int main(int argc, char const *argv[])
{
    int n;
    int a[maxn], b[maxn];
    while((scanf("%d", &n) == 1 && n) ){
        for(int i=0; i<n; i++){
                scanf("%d", &a[i]);
            }
        for(;;){
            int A = 0, B = 0;
            for(int i=0; i<n; i++){
                scanf("%d", &b[i]);
            }
            if(b[0] == 0)break;

            for(int i=0; i<n; i++){
                if(a[i] == b[i])A++;
            }
            for(int d=1; d<=9; d++){
                int c1=0, c2=0;
                for(int i=0; i<n; i++){
                    if(a[i] == d)c1++;
                    if(b[i] == d)c2++;
                }
                if(c1<c2)B+=c1; else B+=c2;
            }
            printf("(%d, %d)\n", A, B-A );
    
        }

    }
    return 0;
}
//先实现上述，然后再给其套上循环。别忘了其本质。
//循环是为了实现其周期。
