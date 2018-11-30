#include <stdio.h>
/*
这是一个例子，说明double数不能随便的使用==
也就是==不太适用于浮点数
*/
int main(int argc, char const *argv[])
{
    for(double i=0.0; i!=10; i+=0.1)
        printf("%llf\n", i);
    return 0;
}