#include<stdio.h>
#include<math.h>
#include<string.h>
typedef struct point
{
    float x,y;
}pt;


int quadrant(pt u)
{
    if(u.x==0 && u.y==0)
        return 0;

    else if(u.x>0 && u.y>0)
        return 1;

    else if(u.x<0  && u.y>0)
        return 2;

    else if(u.x<0  && u.y<0)
        return 3;

    else if(u.x>0  && u.y<0)
        return 4;

    else if(u.y==0)
        return 5;

    else if(u.x==0)
        return 6;
}


void ifcase (int v)
{
    switch (v)
    {
        case 0:
            printf("\n point is on origin");
            break;

        case 5:
            printf("\n point lies on x - axis ");
            break;

        case 6:
            printf("\n point lies on y - axis ");
            break;

        default:
            printf("\npoint lies in %d quadrant",v);
            break;
    }

}

float dist (pt A, pt B)
{
    float d;
    d= sqrt(((A.x-B.x)*(A.x-B.x))+((A.y-B.y)*(A.y-B.y)));
    return d;
}

int main()
{
    pt A, B;
    int qa,qb;
    float distance;

    printf("\nEnter the x and y co-ordinates of A and B\n");
    scanf("%f%f%f%f",&A.x,&A.y,&B.x,&B.y);


    printf("\nA:");
    qa=quadrant(A);
    ifcase(qa);
    printf("\nB:");
    qb=quadrant(B);
    ifcase(qb);
    distance=dist(A,B);
    printf("\n\ndistance between the two points A and B is %.2f\n\n",distance);

}

