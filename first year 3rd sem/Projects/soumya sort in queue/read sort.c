#include "sort header.h"

void readmainqueue(QUEUE *A, int N)
{
    int i;
    DATA readdetail;                   //  details about one person in main queue

    for(i=0;i<N;i++)                     // reading details n times
    {
        printf("\nEnter details (person %d):\nName(without space):  ",1+i);
        scanf("%s",readdetail.name);
        printf("Age:  ");
        scanf("%d",&readdetail.age);
        printf("Gender (F-female || M-male || O-other):  ");
        scanf("%c",&readdetail.gender);
        readdetail.gender=getchar();              // to get character
        enqueue(A,readdetail);
    }
    return;
}
