#include<stdio.h>
#include<math.h>
#include<string.h>

typedef struct alien
{
    int h,m;
}time;

time blast(time l, time t, time d)
{

    d.h = t.h + l.h;
    d.m = t.m + l.m;

    if(d.m>=60)
    {
        d.m = d.m - 60;
        d.h++;
    }

    if (d.h>=24)
    {
        d.h = d.h - 24;
    }

    return d;
}

int main()
{
     time l, t, d;

     printf("\nenter the time of launch (hour and minute)\n");
     scanf("%d%d",&l.h,&l.m);
     printf("\nenter the time of travel (hour and minute)\n");
     scanf("%d%d",&t.h,&t.m);

     d=blast(l,t,d);
     printf("the time of destruction is %d %d\n",d.h,d.m);
}

