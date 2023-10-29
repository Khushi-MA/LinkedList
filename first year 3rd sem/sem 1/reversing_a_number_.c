/*Design an algorithm that accepts a positive integer
and reverses the order of its digits
*/

#include<stdio.h>
int main()
{
    int d_reverse,N,reminder;
    printf("enter the number to be reversed\n");
    scanf("%d",&N);
    d_reverse = 0;


    while (N>0)
    {
        reminder = N % 10;
        d_reverse = (d_reverse * 10) + reminder;
        N = N/10 ;

    }

    printf("\nreversed number = %d\n",d_reverse);


    printf("is it palindromic number?\n");


    if (N = d_reverse)
    {
        printf("yes\n");
    }

    else
    {
        printf("no\n");
    }



    return 0;






}

