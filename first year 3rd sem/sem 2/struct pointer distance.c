
#include<stdio.h>
#include<math.h>



typedef struct points
{
    float x,y;
}pt;

void read_numb (pt *X)
{
    printf("enter the points x and y \n");
    scanf("%f%f",&X->x,&X->y);
}

float find_distance2 (pt *g, pt *h)
{
    float i;
    i=sqrt(((g->x-h->x)*(g->x-h->x)) + ((g->y-h->y)*(g->y-h->y)));
    return i;
}

void find_distance (pt *g, pt *h, float *i)
{
    *i=sqrt(((g->x-h->x)*(g->x-h->x)) + ((g->y-h->y)*(g->y-h->y)));
}

int main()
{
    float d1,d2;
    pt A,B;
    read_numb(&A);
    read_numb(&B);
    find_distance(&A,&B,&d1);
    d2 = find_distance2(&A,&B);

    printf("distance between the points is  %f\n\n",d1);
    printf("distance between the points is  %f\n\n",d2);
}
