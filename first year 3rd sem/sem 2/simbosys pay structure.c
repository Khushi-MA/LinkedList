
#include<stdio.h>
#include<math.h>
#include<string.h>

void increment(double , double);

int main()
{
    char dept;
    double s;
    scanf("%c",&dept);
    getchar();
    scanf("%lf",&s);

    if(s<0)
    {
        printf("Invalid input");
        return 0;
    }

    switch(dept)
    {
        case 'S':
            {
               if(s>=100000 && s<=200000)
                 increment(s,5.0);

               if(s>=70000 && s<100000)
                increment(s,3.0);

               if(s>=40000 && s<70000)
                 increment(s,3.0);

                break;
            }

        case 'A':
            {
                if(s>=80000 && s<=160000)
                    increment(s,4.0);

                if(s>=50000 && s<80000)
                    increment(s,5.0);

                break;
            }

        case 'P':
            {
                if(s>=1000000 && s<=2000000)
                    increment(s,9.0);

                if(s>=60000 && s<1000000)
                    increment(s,7.0);

                if(s>=40000 && s<60000)
                    increment(s,5.0);

                break;
            }

        default: printf("Invalid designation");
                 return 0;
    }
   return 0;
}

void increment( double s, double inc)
{
    long int sf;
    inc=inc*0.01;
    s=s+(s*inc);
    sf=(long int)s;
    printf("%ld",sf);
    return;
}
/*
“SIMBOSYS” is reputed Company in Karnataka which has several departments and around 2,50,000 employees. The company is located in the prime location in the city and has good transportation facility. There are around 4,000 well qualified employees working in the company. Employee has different designations based on experience. The pay structure of the employee is as follows:

image

Apply problem solving framework and UDF to compute the total salary of the employee.

Note: Increment has to be added to the salary.

Input Format

Character representing Designation and Salary

Constraints

Salary>=0

Character for Designation should be S/A/P.

Output Format

Incremeted Salary.

Sample Input 0

S 150000
Sample Output 0

157500
Sample Input 1

D 100000
Sample Output 1

Invalid designation

*/
