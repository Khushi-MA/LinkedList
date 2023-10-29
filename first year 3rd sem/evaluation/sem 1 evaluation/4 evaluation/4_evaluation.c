#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void read_vote(int A[100000], int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
        if(A[i]<1 || A[i]>N)
        {
            break;
        }
    }
}
void check_vote(int A[100000], int N)
{
    int i,j;

    for(i=0;i<N;i++)
    {
        for(j=i+1;j<N;j++)
        {
            if (A[i]==A[j])
            {
                printf("%d ",A[i]);
            }
        }
    }
}
int main()
{
    int N;
    int A[100000];
    scanf("%d",&N);

    if(N<1 || N>100000)
    {
        printf("Invalid");
    }
    else
    {
        read_vote(A,N);
        check_vote(A,N);
    }

    return 0;
}
