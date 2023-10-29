#include "sort header.h"

void sortmainqueue(QUEUE *A, QUEUE *M, QUEUE *F, QUEUE *S,QUEUE *O)
{
    DATA person;
    int unknown=0;
    while(A->rear!=-1)
    {
        person=dequeue(A);

        if(person.age <=0)
            unknown++;

        else if (person.age < 60)
        {
            switch(person.gender)
            {
                case 'M':
                case 'm': enqueue(M,person);
                break;

                case 'F':
                case 'f': enqueue(F,person);
                break;

                case 'O':
                case 'o': enqueue(O,person);

                default: unknown++;
                    break;
            }
        }

        else
            enqueue(S,person);

    }
    printf("\n\n%d member's age or gender (F, M, or O) entered incorrect\n",unknown);
    return;
}
