/* "Mahatma Gandhi National Rural Employment Act" or MINREGA
is an Indian labour law and social security measure that
aims to gurantee the 'right to work'. It aims to enhance
livelihood security in rural areas by providing atleast 100 days
of wage employment in a financial year to every household whose
adult member volunteer to do unskilled manual work.
The daily wage table of the MINREGA is as shown below.

Worker                   Hours of work       Wage in Rs per hour
Male worker              1-6                 50
Female worker            1-6                 40
Male worker              7-10                80 after 6 hours
Female worker            7-10                60 after 6 hours
Male/Female worker       excess of 10        150

Apply problem solving framework to calculate the total wage
a worker will get that day

explanation:
f = female
m = male
H = hours of work
Wage = W

*/



#include<stdio.h>
int main()
{
    char f,m,gender;
    int H,W;
    printf("enter the gender of the labourer f or m");
    gender=getchar();
    scanf("%c",&gender);
    printf("enter the hours worked in a day");
    scanf("%d",&H);

/*
for male worker
Hours of work       Wage in Rs per hour
1-6                 50
7-10                80 after 6 hours
excess of 10        150
*/

    if (gender=='m')
    {
        if (H>=1 && H<=6)
        {
            W=50*H;
            printf("wage=%d",W);
        }

        else if (H>=7 && H<=10)
        {
            W=300+80*(H-6);
            printf("wage=%d",W);
        }

        else if (H>=11 && H<=24)
        {
            W=620+150*(H-10);
            printf("wage=%d",W);
        }

    }

/*
for female worker
Hours of work       Wage in Rs per hour
1-6                 40
7-10                60 after 6 hours
excess of 10        150
*/

    else if (gender=='f')
    {
        if (H>=1 && H<=6)
        {
            W=40*H;
            printf("wage=%d",W);
        }

        else if (H>=7 && H<=10)
        {
            W=240+60*(H-6);
            printf("wage=%d",W);
        }

        else if (H>=11 && H<=24)
        {
            W=480+150*(H-10);
            printf("wage=%d",W);
        }
    }

    return 0;


}

