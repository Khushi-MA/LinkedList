/*to convert miles to kilometres*/

#include<stdio.h>
int main()
{
    float m,k;
    printf("enter distance in miles");
    scanf("%f",&m);
    k=1.60934*m;
    printf("distance=%f",k);
    return 0;
}
