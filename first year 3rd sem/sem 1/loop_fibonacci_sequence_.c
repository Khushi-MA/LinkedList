#include<stdio.h>
int main()
{
    int N,counter,f1,f2,f3;

    printf("enter no., of terms to be generated\n");
    scanf("%d",&N);

    if (N==1)
        printf("sequence:0");

    else if (N==2)
        printf("sequence:0\n1");

    else
    {
        f1=0;
        f2=1;
        counter=0;
        printf("sequence:\n0\n1\n");

        while (counter<=N)
        {
            f3 = f1 + f2 ;
            printf("%d\n",f3);
            f1 =f2 , f2 = f3 ;
            counter++;
        }
        return 0;
        }

}







