/*
this code checks the number of apples and oranges that fell in the house
input:
length of the house
distance of the apple tree from the house
distance of the orange tree from the house

fruit falls distance d from tree. d is:
+ve = +ve  x axis
-ve = -ve  x axis

to count (output): number of apples and oranges that fall in the house
*/

#include<stdio.h>

int main()
{

    int d, as, st, tb, sb, A=0, O=0,i;
    printf("\nenter the distance between s and t (length of house)\t");
    scanf("%d",&st);
    printf("\nenter the distance between:\napple tree and house\t");
    scanf("%d",&as);
    printf("orange tree and house\t");
    scanf("%d",&tb);
    printf("\nenter the distance d for apples\n");

    for(i=0;i<4;i++)
    {
        scanf("%d",&d);
        if(d>as && d<(as+st))
           A++;
    }

    printf("\nenter teh distance d for oranges\n");
    for(i=0;i<4;i++)
    {
        scanf("%d",&d);
        d=-d;
        if(d>tb && d<(st+tb))
            O++;
    }
    printf("\n\nthe number of fruits that fall in the house:\nApples: %d\nOranges: %d\n\n",A,O);
}
