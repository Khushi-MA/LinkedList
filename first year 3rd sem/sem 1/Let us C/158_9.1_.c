#include<stdio.h>


int sum(int *p, int *q, int *r, int *s, int *t)
{
    int add;
    add = *p + *q + *r + *s + *t ;
    return add;
}


int main()
{
    int a,b,c,d,e;
    printf("enter numbers\n");
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);

    int (*s)(int,int,int,int,int);

    s=sum(&a,&b,&c,&d,&e);

    printf("\nthe sum if the entered numbers is %d",s);


}

