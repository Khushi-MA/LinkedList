#include<stdio.h>

void print_ele(int *p,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",*p);
        p++;
    }
}

void read_ele(int *p,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&*p);
        p++;
    }
}



void add(int *p1,int *p2, int *p3, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        *p3 = *p1 + *p2;
        p1++;
        p2++;
        p3++;

    }
}

int main()
{
    int n, a[10], b[10], c[10], *p1=&a[0], *p2=&b[0], *p3=&c[0];
    scanf("%d",&n);
    read_ele(p1,n);
    read_ele(p2,n);
    printf("\n");
    print_ele(p1,n);
    printf("\n");
    print_ele(p2,n);
    add(p1,p2,p3,n);
    printf("\nSum of the two arrays is\n");
    print_ele(p3,n);
    printf("\n");
}
