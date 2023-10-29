/* A software company has 1000 employs. the company decides to give bonus as per work
experience. calculate the amount of bonus
experience bonus
<=7        10% of basic
8-10       20% of basic
11-15      30% of basic
>=15       40% of basic
else if ladder
*/

#include<stdio.h>
int main()
{
    int years;
    float basic,bonus;
    printf("enter your work experience, basic salary");
    scanf("%d%f",&years,&basic);

    if(years<=7)
    {
        bonus=basic*0.1;
        printf("bonus=%f",bonus);
    }
    else if(years>=8 && years<=10)
    {
        bonus=basic*0.2;
        printf("bonus=%f",bonus);
    }
     else if(years>=11 && years<=15)
    {
        bonus=basic*0.3;
        printf("bonus=%f",bonus);
    }
    else
    {
        bonus=basic*0.4;
        printf("bonus=%f",bonus);
    }
    return 0;

}
