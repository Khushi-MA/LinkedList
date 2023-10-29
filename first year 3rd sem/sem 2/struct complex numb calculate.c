#include<stdio.h>
#include<math.h>

typedef struct complex_num
{
    float a,b;
}com;



void read(com N)
{
    scanf("%f%f",&N.a,&N.b);
}

com add(com n1, com n2)
{
    com sum;
    sum.a=n1.a+n2.a;
    sum.b=n1.b+n2.b;
    return sum;
}

int main()
{
    com n1,n2,sum;

    printf("\nenter the complex numbers A and B\n");
    read(n1);
    read(n2);
    sum = add(n1,n2);
    printf("\nsum of the numbers is %f %f ",sum.a,sum.b);

}


