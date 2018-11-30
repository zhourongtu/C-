#include<stdio.h>

typedef struct{
    int x;
    int y;
}rectangular;

int main(int argc, char const *argv[])
{
    rectangular a;
    a.x = 5;
    a.y = 6;
    printf("%d%d", a.x, a.y);
    char ch, ch1, ch2;
    scanf("%c", &ch);
    scanf("%c", &ch1);
    printf("%c, %c", ch, ch1);
    return 0;
}
