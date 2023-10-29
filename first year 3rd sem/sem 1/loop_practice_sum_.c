#include<stdio.h>
int main()
{
    int N,sum;
    int i=1; sum=0;
    printf("enter N");
    scanf("%d",&N);


    while (i<=N)
    {
        sum=sum+i;
        printf("\ni=%d\n",i);
        printf("sum=%d \n",sum);
        i=i+1;      /*  or i++  */

    }


    return 0;
}

