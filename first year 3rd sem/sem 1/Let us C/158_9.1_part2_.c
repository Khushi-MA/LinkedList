#include<stdio.h>

void cal(int *p, float *q, float *r)
{
    int a,b,c,d,e;
    printf("\nenter the numbers");
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);

    *p=a+b+c+d+e;

    *q= (*p)/4.0;

    *r= a+1;

}

int main()
{
    int sum;
    float stdev, avg;

    void (*c)(int,float,float);

    cal(&sum,&avg, &stdev);
    printf("\n%d\n%.4f\n%.4f\n",sum,avg,stdev);
    return 0;
}
