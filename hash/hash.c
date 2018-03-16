/*************************************************************************
	> File Name: hash.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 10时48分41秒
 ************************************************************************/
// 构建哈希函数 除留余数法
// 解决哈希冲突 开放地址法

#include<stdio.h>
#define N 5

int hash(int n)
{
    return n%N;
}
int Solve(int num, int a[])
{
    int key = hash(num);
    while(a[key] != -1)
    {
        key = hash(key+1);
    }
    a[key] = num;
}


int Find(int a[])
{
    int num = 0;
    printf("\n请输入要查询的数字:\n");
    scanf("%d", &num);
    int key = hash(num);
    int len = N;

    while(a[key] != num && len > 0)
    {
        key = hash(key+1);
        len--;
    }
    return 0==len? -1:key;

}
int main()
{
    int a[N];
    int num = 0;

    for(int i = 0; i < N; i++)
    {
        a[i] = -1;
    }

    printf("请输入%d个数字:\n", N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        Solve(num, a);
    }

    printf("存储结果:\n");
    for(int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }

    int find = Find(a);
    if(find == -1)
    {
        printf("not find\n");
    }
    else
    {
        printf("a[%d] = %d\n", find, a[find]);
    }
    return 0;
}
