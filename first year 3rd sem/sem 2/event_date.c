#include<stdio.h>
#include<string.h>

typedef struct date
{
    int dd,mm,yy;
}Date;

typedef struct event
{
    char name[50];
    struct date event_date;
}Event;

void read_event(Event *p, int n)
{
     printf("\nenter Events:");
    for(int i = 0; i<n; i++, p++)
    {
        // printf("name:\n");
        scanf("%s",p->name);

        // printf("\nenter day: ");
        scanf("%d",&p->event_date.dd);

        // printf("enter month: ");
        scanf("%d",&p->event_date.mm);

        // printf("enter year: ");
        scanf("%d",&p->event_date.yy);
    }
}

void display_event (Event *p, int n)
{
    printf("Events are:\nName\tDate\tMonth\tYear");

    for(int i=0; i<n; i++, p++)
    {
        printf("\n%s\t%d\t%d\t%d", p->name, p->event_date.dd, p->event_date.mm, p->event_date.yy);
    }
}

int main()
{
    Event elist[50];

    read_event(elist, 10);
    display_event(elist, 10);

    printf("%s", elist[0].name);

    return 0;
}
