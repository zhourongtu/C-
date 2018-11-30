#include <stdio.h>


int f(int n)
{
    return n==0 ? 1:f(n-1)*n;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", f(100000000));
    return 0;
}
