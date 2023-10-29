#include<stdio.h>
#include<string.h>

typedef struct
{
    char name[15];
    int moons;
}PLANET;

void read(PLANET *ptr, int n)
{
     int i;
     for(i=0;i<n;i++)
     {
     printf("enter name: = ");
     scanf("%s",ptr->name);
     scanf("%d",&ptr->moons);
     ptr++;
    }
return;
}

void display(PLANET *ptr, int n)
{
     int i;
     for(i=0;i<n;i++)
     {
     printf("name = ");
     printf("%s\n",ptr->name);
     printf("moons = %d\n",ptr->moons);
     ptr++;
    }
return;
}
PLANET find_max(PLANET *ptr, int n)
{
    int i, m = ptr->moons;
    PLANET temp;
    for(i=0;i<n;i++){
    if(ptr->moons > m)
        {
            m = ptr->moons;
            temp = *ptr;
         //   temp.moons = ptr->moons;
          //  strcpy(temp.name, ptr->name);
        }
        ptr++;
    }
    //printf("\n\nMax moons =\n %s   %d",temp.name, temp.moons);
return temp;
}

int main()
{
    PLANET p[8], *ptr =&p[0], t;
    int n=4;
    read(ptr,n);
    display(ptr,n);
    t =  find_max(ptr,n);
    printf("\n MAX MOONS  =  %s    %d", t.name, t.moons);
}


