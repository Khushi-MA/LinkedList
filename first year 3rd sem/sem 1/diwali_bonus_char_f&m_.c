/* A company decides to give bonus to all the employs on diwali.
A 5% bonus on salary is given to the male emplooys and 10% to the female workers.
Write a program to enter the salary and gender of employs.
If the salary is less than Rs. 10,000, then the employ gets an extra 2% bonus on salary.
Write a program to calculate the bonus that has to be given to the employee
and display the salary that the employ will get.
female = F
male = M*/

#include<stdio.h>
int main()
{
    char f,m,gender;
    float salary;

    printf("enter the gender of the employ, female-f or male-m");
    gender=getchar();
    scanf("%c",&gender);                            /* printf("enter gender of the employ");
                                                        gender=to upper(gender); if it is in capital or
                                                        gender=getchar();
                                                        scanf("%c",&gender);
                                                        */

    printf("enter the salary of the employ");
    scanf("%f",&salary);

    if (gender=='m')
    {
        printf("you get a bonus of 5 percent\n");
        salary=1.05*salary;
        printf("salary=%f\n",salary);
    }

    else if (gender=='f')
    {
        printf("you get a bonus of 10 percent\n");
        salary=1.1*salary;
        printf("salary=%f\n",salary);
    }

    if (salary<10000)
    {
        printf("salary is less, you get an extra bonus of 2 percent\n");
        salary=1.02*salary;
        printf("current salary=%f",salary);

    }

    else
    {
        printf("current salary=%f",salary);
    }


    return 0;

}



