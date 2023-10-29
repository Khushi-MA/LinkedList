#include<stdio.h>
#include<math.h>
#include<string.h>

typedef struct alien
{
    int h,m;
}time;

time blast(time *l, time *t, time *d)
{

    d->h = t->h + l->h;
    d->m = t->m + l->m;

    if((d->m)>=60)
    {
        d->m = d->m - 60;
        d->h++;
    }

    if ((d->h)>=24)
    {
        d->h = d->h - 24;
    }

    return;
}

int main()
{
     time l, t, d,*ptl,*ptt,*ptd;
     ptl=&l;
     ptt=&t;
     ptd=&d;

     printf("\nenter the time of launch (hour and minute)\n");
     scanf("%d%d",&ptl->h,&ptl->m);
     printf("\nenter the time of travel (hour and minute)\n");
     scanf("%d%d",&ptt->h,&ptt->m);

     d=blast(ptl,ptt,ptd);
     printf("the time of destruction is %d %d\n",ptd->h,ptd->m);
}


