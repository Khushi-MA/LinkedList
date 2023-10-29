#include<stdio.h>
int main()
{
    int i;
    float a, b;

    printf("enter initial dimensions of length and breadth\n");
    scanf("%f%f",&a,&b);

    printf("paper sizes as follows:-");
    printf("\nA0: %.1f x %.1f",a,b);

    for(i=1;i<9;++i)
    {
        if(a<b)
        {
            b=b/2;
            printf("\nA%d: %.1f x %.1f",i,a,b);
        }

        else if(b<a)
        {
            a=a/2;
            printf("\nA%d: %.1f x %.1f",i,b,a);
        }

    }
}
