#include<stdio.h>
#include<stdlib.h>

void main()
{
    int *p;
    printf("\nthe vale (1)=\t%d",&p);
    p=(int*)malloc(sizeof(int));
    printf("\nthe value (2)=\t%d",p);
    printf("\nenter the value\n");
    scanf("%d",p);
    printf("the value (3)=\t%d",p);
    printf("\nthe value (4)=\t%d\n",*p);
}


