#include<stdio.h>

void read(int a[100], int N)
{
    int i;
    for (i=0;i<N;i++)
    {
        scanf("%d",(a+i));
    }
}

void sort (int a[100], int N)
{
    int i, j, t;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N-1-i;j++)
        {
            if(( a+j)<(a+j+1))
            {
                t=*(a+j);
                *(a+j)=*(a+j+1);
                *(a+j+1)=t;
            }
        }
    }
    for(i=0;i<N;i++)
    {
        printf("%d",*(a+i));
    }

}

int main()
{
    int a[100],N,k;
    printf("\nenter the N value\n");
    scanf("%d",&N);
    read(a,N);
    sort(a,N);
    printf("\nenter the k-th value\n");
    scanf("%d",&k);
    printf("k-th winner = %d",a[k]);
}
