#include<stdio.h>
#define rate 120
int main()
{
    int ne, i,hw;
    printf("enter number of employs\n");
    scanf("%d",&ne);

    for(i=0;i<ne;i++)
    {
        printf("\nenter no. of hours worked\n");
        scanf("%d",&hw);
        if(hw>=40)
        printf("overtime pay is %d\n",(hw-40)*rate);

        else
        printf("\nno overtime pay\n ");

    }


}
