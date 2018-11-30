#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%.*lf\n",c,1.0*a/b);
    return 0;
}
