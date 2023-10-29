#include<stdio.h>
#include<stdio.h>
#define size 100

int main()
{
    int score[size], n, in_score[size],kk,k_score;
    int i,m;

    printf("\n no. of players\n");
    scanf("%d",&n);

    printf("\n enter scores\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&score[i]);
    }

    for(i=0;i<n;i++)
    {
        in_score[i]=score[i];
    }

    int j,k,t;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if (score[j]<score[j+1])
            {
                t=score[j];
                score[j]=score[j+1];
                score[j+1]=t;
            }
        }
    }

    printf("\nenter the k-th value");
    scanf("%d",&kk);
    k_score=score[kk-1];

    printf("\nscore of k-th winner is %d",k_score);

    printf("\ntherefore the k-th winner is\n");

    for(m=0;m<n;m++)
    {
        if(in_score[m]==k_score)
        {
             printf("player %d\n\n",(m+1));
        }

    }

    return 0;

}
