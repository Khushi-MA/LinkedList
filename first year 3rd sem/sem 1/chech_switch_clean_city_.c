/*Under the "CLEAN CITY" project, Bruhat Bengaluru Mahanagara Palike (BBMP)
would like to collect the garbage from all parts of Bangaluru city.
To manage the garbage better and to ensure cleanliness of the city,
the BBMP will send the garbage collection vehicle every day to collect the garbage.
BBMP charges a minimum amount for the same from the people
as per table shown below.
BBMP planned to collect amount once in a year

type of building            Area of sq. ft          charges in Rs/month

residential building        up to 1000sq. ft        10
(R)                         1001-3000 sq. feet      30
                            above 3000 sq. ft       50

Commercial building         up to 1000sq. ft        100
(C)                         1001-5000 sq. feet      200
                            above 5000 sq. ft       50

hotels,                     up to 10000sq. ft       300
kalyan mantapas, etc.       10001-50000 sq. feet    500
(O)                         above 50000 sq. ft      600

Calculate total amount to be paid by person/businessman.


*/


#include<stdio.h>
int main()
{
    char building;
    float area,c,tc;
    printf("enter type of area R/C/O\n");
    scanf("%c",&building);
    printf("enter the area occupied\n");
    scanf("%f",&area);

    switch(building)
    {
        case'R':
            if (area<=1000)
            {
            tc=10*12;
            printf("total charge for a year=",tc);

            }



            return 0;


    }
}

