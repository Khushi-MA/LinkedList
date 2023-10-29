#include<stdio.h>
#define size 50

int main()
{
    int arr[size], N;
    int i,j;

    // number of bank nifties
    printf("enter the number of elements noted");
    scanf("%d",&N);

    // to read the elements of the list
    for(i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }

    //find the bitonic point
    int *p, *q;
    q=&arr[0];

    for(j=1;j<N;j++)
    {
        p=&arr[j];
        if(*q < *p)
        {
            q=p;
        }
    }

    printf("\n\noutput (i.e. bitonic point): %d",*q);
}
