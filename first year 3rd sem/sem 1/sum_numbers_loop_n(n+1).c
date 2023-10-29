/* write a program statement thet computes 1+2+3=...+(n-1), where n is data value.
follow the loop body with an if statement that compares this value to (n*(n+1))/2
and displays a message that indicates whether values are same or diff.
what message do you think will be displayed?
*/

#include<stdio.h>
int main()
{
    int N,sum,i;
    printf("enter data value\n");
    scanf("%d",&N);
    sum=0;
    i=1;

    while (i<=N)
    {
        sum=sum+i;
        printf("sum= %d\n",sum);
        i++;

    }



    printf("sum= %d\n",sum);

    if ( sum = (N*N+1)/2 )
    {
        printf("comparing with (N*N+1)/2 ; values are same\n");
    }


    else
    {
        printf("values are different\n");

    }

    return 0;

}






