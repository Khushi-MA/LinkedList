/*to calculate the total marks and the
percentage obtained in a test. the test has five subjects,
100 marks each, max total marks is 500*/


#include<stdio.h>
int main()
{
    int a,b,c,d,e,m;
    float p;
    printf("enter marks a,b,c,d,e");
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    m=a+b+c+d+e;
    p=m*0.2;
    printf("marks=%d\n",m);
    printf("percentage=%f",p);
    return 0;
}

