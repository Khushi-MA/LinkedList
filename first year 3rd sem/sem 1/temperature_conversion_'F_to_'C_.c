/*program to convert degree Fahrenheit
to degree Celsius
solution: formula for conversion
F=(9/5)*C+32
*/

#include<stdio.h>
int main()
{
    float F,C;
    printf("enter the temp in fahrenheit, F");
    scanf("%f",&F);
    C=(F-32)*5/9;
    printf("temperature in degree celsius=%f",C);
    return 0;

}

