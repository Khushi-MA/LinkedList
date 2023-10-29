#include "crush header.h"

void crushgame(STK *A, STK *S, int N)
{
    int i;
    push(S,pop(A));
    for(i=0;A->top!=-1;i++)
    {
        if(peek(*S)!=peek(*A))
            push(S,pop(A));

        else
        {
            pop(S);
            pop(A);
        }
    }
    if(isempty(*S))
        printf("Proceed to next level");

    else
        display(*S,N);
    return ;
}
