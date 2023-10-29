#include<stdio.h>
int main()
{
    int N;
    int i=0;

    printf("enter N");
    scanf("%d",&N);

    while (i<=N)
    {
        if (i%2==0)
            printf("i=%d\n",i);
            i++;

    }
    return 0;
}
