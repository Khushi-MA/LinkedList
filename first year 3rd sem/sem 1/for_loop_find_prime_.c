
#include<stdio.h>
#include<math.h>

int main()
{
    int i,number,status = 0;

    printf("Enter the number\n");
    scanf("%d",&number);

    for(i = 2; i<=sqrt(number);i++)
    {
        if(number%i == 0)
            {
            status = 1;
            break;
            }
    }

    if(status == 1)
	printf("It is not a prime number\n");
    else
	printf("It is a prime number\n");
    return 0;

}
