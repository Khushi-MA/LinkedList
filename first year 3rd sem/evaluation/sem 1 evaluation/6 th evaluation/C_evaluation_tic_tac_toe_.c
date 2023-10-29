#include<stdio.h>

int main()
{
    int t[3][3];

    read_turn(t);
    print_turn(t);
    winner(t);
}

void read_turn (int t[3][3])
{
    int i,j;

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;)
        {
            scanf("%d",&t[i][j]);
            if( t[i][j]==1 || t[i][j]==0 )
                j++;
        }
    }
}

void print_turn (int t[3][3])
{
    int i,j;

    for(i=0;i<3;i++)
    {
        printf("\n");
        for(j=0;j<3;j++)
            printf("%d",t[i][j]);
    }
}

void winner (int t[3][3])
{
    int i;


    for(i=0;i<3;i++)
    {

        for(j=0;j<3;j++)
        {
            row_sum
        }
    }

}
