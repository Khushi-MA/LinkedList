#include<stdio.h>

typedef struct complex_numbers
{
    float real,img;
}comp;

void read_comp (comp *A)
{
    printf("\nenter the real part and imaginary part\n");
    scanf("%f%f",&A->real,&A->img);
}

void add_comp(comp *px, comp *py, comp *pz)
{
    pz->real = px->real + py->real;
    pz->img = px->img + py->img;
}

comp add_comp2(comp *px, comp *py, comp *pz)
{
    pz->real = px->real + py->real;
    pz->img = px->img + py->img;
}

void multiply_comp (comp *px, comp *py, comp *pm)
{
    pm->real = ((px->real * py->real)-(px->img * py->img));
    pm->img = ((px->real * py->img)+(py->real * px->img));

}

int main()
{
    comp X,Y,Z,M,*f;

    read_comp(&X);
    read_comp(&Y);
    f=&Z;

    *f=add_comp2(&X,&Y,&Z);

    //add_comp(&X,&Y,&Z);
    printf("\nsum of the complex numbers is %f  %f\n",Z.real , Z.img);

    multiply_comp(&X,&Y,&M);
    printf("\nproduct of the complex numbers is %f  %f\n",M.real , M.img);
}


