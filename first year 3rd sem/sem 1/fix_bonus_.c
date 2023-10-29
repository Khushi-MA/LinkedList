/* The current year and the year in which the employee
joined the organization are entered through the keyboard.
If the number of years for which the employee has served
the organization is greater than 3 then a bonus of Rs. 2500/-
is given to the employee. If the years of service are not
greater than 3, then the program should do nothing. */
/* Explanation:
let jy = joined year
    cy = current year
     w = number of years worked
*/

#include<stdio.h>
int main()
{
    int jy,cy,w;
    printf("enter the year in which the employee joined");
    scanf("%d",&jy);
    printf("enter current year");
    scanf("%d",&cy);
    w=cy-jy;

    if (w>3)
    {
        printf("congratulations, you got a bonus of Rs.2500");
    }
return 0;

}

