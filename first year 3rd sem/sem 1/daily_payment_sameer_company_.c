/* Sameer has bearing manufacturing company in hubballi.
He has a total of 150 full time employees working in the company.
Recently , Sameer got a big consignment of manufacturing bearings.
Now the consignment has to be completed within a week,
Sameer felt he can't manage his work with his full time employees.
He decided to hire a few part timers on daily payment basis.
He decided to pay them the following chart.


No. of             minimum hours of      payment per    additional allowance
days of work        work per day         hour in Rs        per day in Rs

1-3                                         250                100
4-6                       6                 350                150
7-9                                         450                250

Apply problem solving framework to calculate the total payment
that an employee gets.
*/

/*
Explanation:



*/

#include<stdio.h>
int main()
{
    int D,H,S;
    printf("enter number of days of work");
    scanf("%d",&D);
    printf("hours worked per day being more than 6 hours");
    scanf("%d",&H);


    if (D>=1 && D<=3)
    {
        S=(250*H+100)*D;
        printf("salary=%d",S);
    }

    else if (D>=4 && D<=6)
    {
        S=((250*H+100)*3)+((350*H+150)*(D-3));
        printf("salary=%d",S);
    }

    else if (D>=7 && D<=9)
    {
        S=((250*H+100)*3)+((350*H+150)*3)+((450*H+250)*(D-6));
        printf("salary=%d",S);
    }

    return 0;


}



