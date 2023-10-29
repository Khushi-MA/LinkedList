#include<stdio.h>
#define size 50

void see_candles (int o, int candles[size])
{
    int i;
    printf("\nenter the height of candles");
    for(i=0;i<o;i++)
    {
        scanf("%d",&candles[i]);
    }
}

void display_height(int o,int candles[size])
{
    int i;
    for(i=0;i<o;i++)
    {
        printf("%d\t",candles[i]);
    }
}

int tall_candle(int o, int candles[size])
{
    int i,max;
    for(i=0,max=candles[0];i<o;i++)
    {
        if(candles[i]>max)
            max=candles[i];
    }
    return max;
}

int num_tall (int tall,int o,int candles[size] )
{
    int i,n;
    for(i=0,n=0;i<o;i++)
    {
        if(candles[i]==tall)
            n++;
    }
    return n;
}

int main()
{
    int o,tall, tall_ones;

    printf("\nenter the age of bro\n");
    scanf("%d",&o);

    int candles[size];

    see_candles(o,candles);
    display_height(o,candles);
    tall = tall_candle(o,candles);
    printf("\n maximum  is  %d",tall);
    tall_ones = num_tall(tall,o,candles);
    printf("\nnumber = %d",tall_ones);


}

