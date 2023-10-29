#include<stdio.h>
typedef struct complex_number
{
  float real,imaginary;
}COMP1;c1;



int main()
{
        struct complex_number c1;
        printf("\nenter real and imaginary value\n");
        scanf("%f",&c1.real);
        scanf("%f",&c1.imaginary);
        printf("%f\n",c1.real);
        printf("%f",c1.imaginary);
}



