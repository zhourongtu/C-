#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    for(int a = 1; a <= 9; a++){
        for(int b=0; b<=9; b++){
            int n = 1*1100+b*11;
            int m = floor(sqrt(n)+0.5);
            if(m*m == n) printf("%d\n", n);
            
        }

    }
    return 0;
}
