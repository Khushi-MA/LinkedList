#include<stdio.h>
#include<string.h>

typedef struct date
{
    int dd,mm,yy;
}DATE;

void read_date(DATE *p)
{
     printf("\nenter date:");
    printf("\nenter day: ");
    scanf("%d",&p->dd);
    printf("enter month: ");
    scanf("%d",&p->mm);
    printf("enter year: ");
    scanf("%d",&p->yy);
}

void compare (DATE *A, DATE *B)
{
    if(A->dd==B->dd && A->mm==B->mm && A->yy==B->yy)
        printf("\ndates match!!");

    else
        printf("\ndates DON'T match\n");
}

int compare_2(DATE *A, DATE *B)
{
    if(A->dd==B->dd && A->mm==B->mm && A->yy==B->yy)
        return 1;

    else
        return 0;
}

int main()
{
    int i;
    DATE a,b;
    read_date(&a);
    read_date(&b);
    compare(&a,&b);

    //compare type 2

    if(compare_2(&a,&b))
        printf("\ndates match!!");

    else
        printf("\ndates DON'T match\n");
}
