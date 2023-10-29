#include<stdio.h>
#include<math.h>
int main()
{
    int i,binary,number,reminder;

    printf("enter the number\n");
    scanf("%d",&number);

    i=0;
    binary=0;

    while (number != 0)
    {
        reminder = number%2;
        binary = binary + reminder * pow(10,i) ;
        number = number/2;
        i++ ;


    }

    printf("\nbinary: %d",binary);

}
