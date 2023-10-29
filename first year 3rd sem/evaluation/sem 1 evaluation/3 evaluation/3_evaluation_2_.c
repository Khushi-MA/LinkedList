/*Program to announce the no. of winners*/


#include<stdio.h>

int winner(int N)
{
    int X, w, i;
    float s, rem1,rem2, quot1, quot2;



    w=0;

    printf("participant %d\n",i);

    printf("enter no. of blocks\n");
    scanf("%d",&X);

    printf("enter the sequence of the blocks\n");
    scanf("%f",&s);


    for (i=1;i<=X;rem1 - rem2 == 1 || rem2 - rem1 == -1)
    {
        rem1 = s%10;
        quot1 = s/10;
        rem2 = quot1 % 10 ;
        quot2 = s/10 ;
        s = quot1;
        i++;


    }

    w=w+1;

}


int main()
{
    int N, a, w;

    a=1;
    printf("enter number of participants\n");
    scanf("%d",&N);

    while(a<=N)
    {
        w = winner(N);
        a++;

    }

    printf("number of winners = %d",w);
    return 0;


}

