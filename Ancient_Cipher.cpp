#include <stdio.h>
#include <string.h>
#include "QuickSort.cpp"

#define maxn 1000
/*
我先前不太明白这个古典密码的破解问题。这次真的给出了我一个解释。太炫酷了
既然字母可以重排，则每个字母的位置并不重要，重要的是每一个字母出现的次数。
这样可以先统计出两个字符串中各个字母出现的次数，得到两个数组cnt1[26], cnt2[26]
通过重排使得映射相同。

在C语言库中有一个
qsort
void qsort(void *base, size_t num, size_t size, int(*comparator)(const void *, const *void) )

指向函数的指针，函数具有形式
int cmp(const void *, const void *);

如果重排之后，排序相同
*/

int main()
{
    char a[maxn], b[maxn];

    int n;
    scanf("%d", &n);
    getchar();

    scanf("%s", a);
    scanf("%s", b);
    int cnt1[maxn];
    int cnt2[maxn];
    
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));

    for(int i=0; i<n; i++){
        cnt1[a[i]-'A']++;
        cnt2[b[i]-'A']++;    
    }
    sort(cnt1, 0, 25);
    sort(cnt2, 0, 25);
    
    int flag=0;
    for(int i=0; i<26; i++){
        if(cnt1[i]!=cnt2[i]){
            printf("No");
            flag = 0;
            break;
        }
    }
    if(!flag)printf("OK");
    return 0;
}
