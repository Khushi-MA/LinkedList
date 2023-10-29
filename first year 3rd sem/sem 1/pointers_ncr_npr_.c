#include<stdio.h>

int fact(int n)
{
    int i,p=1;

    for(i=n;i>=1;i--)
        p=p*i;

    return p;
}

void NCR_NPR(int n, int r, int *ncr, int *npr)
{

    *ncr=fact(n)/(fact(n-r)*fact(r));
    *npr=fact(n)/fact(n-r);
    return;
}

int main()
{
    int n,r,ncr,npr;
    scanf("%d%d",&n,&r);
    NCR_NPR(n,r,&ncr,&npr);
    printf("NCR = %d\nNPR = %d",ncr,npr);
    return 0;
}


