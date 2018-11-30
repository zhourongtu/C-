#include <stdio.h>

int main(int argc, char const *argv[])
{
    int flag = 0;
    int c;
    while( (c = getchar()) != EOF){
        if(c == '"' && flag == 0){
            printf("``");
            flag = 1;
        }
        else if(c == '"' && flag == 1){
            flag = 0;
            printf("''");
        }
        else{
            printf("%c", c);
        }
    }
    return 0;
}

// #include <stdio.h>

// int main()
// {
//     int c, q = 1;
//     while((c = getchar()) != EOF){
//         if(c=='"'){
//             printf("%s", q? "``": "''"); q=!q;
//         }
//         else printf("%c", c);
        
//     }
//     return 0;

// }