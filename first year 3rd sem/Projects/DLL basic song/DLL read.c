#include "DLL menu.h"

void readsong(SONG *s)
{
    printf("\nname of the song\t");
    scanf("%s",s->name);
    printf("singer\t");
    scanf("%s",s->singer);
    printf("date\t ");
    scanf("%d",&s->date.d);
    printf("month\t ");
    scanf("%d",&s->date.m);
    printf("year\t ");
    scanf("%d",&s->date.y);
    return;
}

NODE getnode()
{
    NODE p;
    p=(NODE)malloc(sizeof(struct node));
    return p;
}
