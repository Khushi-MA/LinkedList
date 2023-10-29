#include "crush header.h"

int main()
{
    int N;
    scanf("%d",&N);
    if(N<2)
    {
        printf("Invalid input");
        return 0;
    }

    STK S,A;
    initstack(&S);
    initstack(&A);
    int data,i;
    for(i=0;i<N;i++)
    {
        scanf("%d",&data);
        push(&S,data);
    }
    for(i=0;i<N;i++)
    {
        push(&A,pop(&S));
    }
    crushgame(&A,&S,N);
    return 0;
}

