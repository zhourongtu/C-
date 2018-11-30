#include <stdio.h>
#include <math.h>
int isDaffodil(int n)
{
    int A,B,C;
    A = n/100;
    B = n/10%10;
    C = n%10;
    if(pow(A,3)+pow(B,3)+pow(C,3) == n)
        return 1;
    return 0;

}
int main()
{
    int i;
    for(i=100; i<=999; i++){
        if(isDaffodil(i)){
            printf("%d\n", i);
        }
    }
}
