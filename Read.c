#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
①复制hello.exe到hello2.exe;
②读取hello2.exe的文件头添加到shell.bin后面生成shelldat.bin, 
③把shelldat.bin添加到hello2.exe末尾; 
④对hello2.exe中除了文件头外的全部内容进行加密(使用逐字节xor 33h); 
⑤修改hello2.exe文件头+6处的重定位项=0;
⑥修改hello2.exe文件头+2及+4处的文件长度信息; 
⑦修改hello2.exe的Δcs:ip;
*/

void Copy(char *a, char *b);
char read(char *a, int Pos);
void AddToEnd(char *dest, char *source);
int getFileSize(char *path)
{
    FILE *pf = fopen(path, "r");
    if(pf == NULL)
    {
        return -1;
    }
    else {
        fseek(pf, 0, SEEK_END);
        int length = ftell(pf);
        printf("length = %d", length);
        return length;
    }
}

/*
好了，我们拥有了一个函数可以返回一个文件的大小。
*/

int main(int argc, char *argv[])
{
/*
解决命令行的输入问题后，我们知道了
文件1，文件2的名字
现在将文件1拷贝到文件2
*/
//    Copy(argv[1], argv[2]);
    int length = (int)(read(argv[1], 8))*256;//文件头的字节数
    printf("%d", length);
}

void Copy(char *a, char *b)
{
    FILE *fp1, *fp2;
    fp1 = fopen(a, "r");
    fp2 = fopen(b, "w");
    char c;
    while((c = fgetc(fp1)) != EOF){
        fputc(c, fp2);
    }
    fclose(fp1);
    fclose(fp2);
}

char read(char *a, int Pos)
{
    FILE *fp = fopen(a, "r");
    int temp;
    fseek(fp, Pos, SEEK_CUR);
    temp = (fgetc(fp));

    fclose(fp);
    return temp;
}