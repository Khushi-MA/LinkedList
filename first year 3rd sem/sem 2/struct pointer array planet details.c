#include<stdio.h>
#include<math.h>
#include<string.h>
#include<strings.h>

/*  EXTRAS
members that can be done
name = name of the planet
ps = position from the sun
moon = moons
ds = distance from sun
temp = temperature on the planet

*/

/*  REQUIRED
name[10] = name
d = diameter
moons = moons for the planet
rt = rotation time in hours
ot = orbit time in years
*/

/*
write a function to display maximum number of moons
*/

typedef struct planets
{
    char name[10];
    double d,rt, ot;
    int moons;
}pnt;

void read (pnt p[8],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nenter: \nname\t");
        scanf("%s",p[i].name);
        printf("diameter\t");
        scanf("%lf",&p[i].d);
        printf("rotation time\t");
        scanf("%lf",&p[i].rt);
        printf("orbit time\t");
        scanf("%lf",&p[i].ot);
        printf("number of moons\t");
        scanf("%d",&p[i].moons);
    }
    return;
}

void display (pnt p[8], int n)
{
    int i;
    printf("\ns.no.\tname\tdiameter\tmoons\trotation_time\torbit_time");
    for (i=0;i<=(n-1);i++)
    {
        printf("\n%d\t%s\t%lf\t%d\t%lf\t%lf",i+1,p[i].name,p[i].d,p[i].moons,p[i].rt,p[i].ot);
    }
    return;
}

pnt max_moon (pnt p[8],int n)
{
    int i, max, pos;
    for(max = p[0].moons, i=1; i<n;i++)
    {
        if(max<p[i].moons)
        {
            max = p[i].moons;
            pos = i;
        }
    }
    return p[pos];
}

double average_diameter (pnt p[8], int n)
{
    int i;
    double sum,avg;
    for (i=0,sum=0;i<n;i++)
    {
        sum = sum+(p[i].d);
    }
    avg = sum/n;
    return avg;
}

void copy(pnt sp[8], pnt p[8], int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        strcpy(sp[i].name,p[i].name);
        sp[i].d=p[i].d;
        sp[i].moons=p[i].moons;
        sp[i].rt=p[i].rt;
        sp[i].ot=p[i].ot;
    }
}



void search (pnt p[8] ,int n, char unknown[10])
{
    int i=0,a;
    for(i=0;i<n;i++)
    {
        a=strcmp(p[i].name,unknown);      //if strcomp gives 0 (zero), they match

        if(a==0)
            printf("\nsearch found");

        else
        printf("\nsearch NOT found");
    }
}


void sort (pnt sp[8], int n)
{
    int i,j,t;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(sp[i].moons>sp[i+1].moons)
            {
                t=sp[i].moons;
                sp[i].moons=sp[i+1].moons;
                sp[i+1].moons=sp[i].moons;
            }
        }
    }
    return;
}

int main()
{
    pnt p[8],mm,unsort[8],sp[8];
    char unknown[10];
    int n;
    double a_d;

    printf("enter number of planets\t");
    scanf("%d",&n);

    printf("\nenter planet information");

    read(p,n);
    display(p,n);

    mm = max_moon(p,n);
    printf("\n\n%d",mm.moons);
    printf("\nname\tdiameter\tmoons\trotation_time\torbit_time");
    printf("\n%s\t%lf\t%d\t%lf\t%lf",mm.name,mm.d,mm.moons,mm.rt,mm.ot);

    a_d=average_diameter(p,n);
    printf("\n\naverage diameter is %lf",a_d);
    printf("\nenter the planet you want to check for existance");

    scanf("%s",unknown);
    //search(p,n,unknown);

    copy(sp,p,n);
    sort(sp,n);
    printf("\nsorted array w.r.t. to number of moons");
    display(sp,n);

    return 0;
}
// kaveri
/*
void search (pnt p[8] ,int n, char unknown[10])
{
    int i=0,a;
    for(i=0;i<n;i++)
    {
        a=strcmp(p[i].name,unknown);      //if strcomp gives 0 (zero), they match

        if(a==0)
        {
             printf("search found");
            printf("\n%s\t%lf\t%d\t%lf\t%lf",p[i].name,p[i].d,p[i].moons,p[i].rt,p[i].ot);
        }


        else
        printf("search NOT found");
    }
}
*/

