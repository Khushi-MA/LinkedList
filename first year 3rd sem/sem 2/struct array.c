#include<stdio.h>
#include<math.h>
#include<string.h>
#define size 10


typedef struct identity_players
{
    char name[20];
    float BA;   // BA = batting average
    int ODI;    // ODI = ODI rank
}cp;



void read(cp A[size],int N)
{
    int i,v;
    for(i=0;i<N;i++)
    {
        v=i+1;
        printf("\nenter name, batting average and ODI rank of player %d\n",v);
        scanf("%s%f%d",A[i].name, &A[i].BA, &A[i].ODI);
    }

}

void display (cp A[size],int N)
{
    int i;
    printf("\nname\taverage\trank");
    for(i=0;i<N;i++)
    {
        printf("\n%s\t%.2f\t%d",A[i].name, A[i].BA, A[i].ODI);
    }

}

int main()
{
    cp p[size];
    int N;
    printf("\nenter the number of players\n");
    scanf("%d",&N);
    read(p,N);
    display(p,N);
    return 0;
}




