#include "sort header.h"

int main()
{
    int N;
    printf("\nEnter number of people in the main queue:   ");
    scanf("%d",&N);
    QUEUE Q, M, F, S, O;    // Q:main queue...M:male...F:female...S:Senior citizen
    createq(&Q);
    createq(&M);
    createq(&F);
    createq(&S);
    createq(&O);
    readmainqueue(&Q,N);
    sortmainqueue(&Q,&M,&F,&S,&O);
    printf("\n\nSenior citizen:");
    displayq(S);
    printf("\n\nFemale:");
    displayq(F);
    printf("\n\nMale:");
    displayq(M);
    printf("\n\nOther:");
    displayq(O);
    printf("\n\n");
    return 0;
}
