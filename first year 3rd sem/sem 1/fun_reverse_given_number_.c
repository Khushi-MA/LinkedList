#include<stdio.h>
#define Pi 3.142

int reverse(int N)
{
    int d_reverse,reminder;
    d_reverse = 0;
    while (N>0)
    {
        reminder = N % 10;
        d_reverse = (d_reverse * 10) + reminder;
        N = N/10 ;

    }
    return d_reverse;
    return 0;
}

int main()
{
    int N,d_reverse;
    printf("enter the number to be reversed\n");
    scanf("%d",&N);

    d_reverse = reverse(N);
    printf("\n\n reversed number is %d",d_reverse);

    return 0;
}



