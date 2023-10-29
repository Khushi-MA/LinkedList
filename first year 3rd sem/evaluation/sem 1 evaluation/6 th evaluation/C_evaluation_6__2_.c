#include<stdio.h>
#define r 2


void read_energy(int N, int energy[r][N])
{
    int i,j;

    for(i=0;i<r;i++)
        for(j=0;j<N;j++)
            scanf("%d",&energy[i][j]);
}

void print_energy(int N,int energy[r][N])
{
    int i,j;
    printf("\n");
    printf("\nBob\t");
    for(j=0;j<N;j++)
        {
            printf("%d ",energy[0][j]);
        }

    printf("\nJames\t");
    for(j=0;j<N;j++)
        {
            printf("%d ",energy[1][j]);
        }

    printf("\n");
}

void were_high(int N,int energy[r][N])
{
    int j,bob,james;
    for(bob=0,james=0,j=0;j<N;j++)
    {
        if(energy[0][j] > energy[1][j])
            bob++;

        if(energy[0][j] < energy[1][j])
            james++;
    }

    printf("\nBob: %d\nJames: %d",bob,james);
}

void avg_max_energy(int N,int energy[r][N])
{
    int j;
    float b_avg,j_avg,max_avg,b_sum,j_sum;

    for(j=0,b_sum=0,j_sum=0;j<N;j++)
    {
        b_sum=b_sum + energy[0][j];
        j_sum=j_sum + energy[1][j];
    }

    b_avg=b_sum/N;
    j_avg=j_sum/N;
    printf("\nAverage energy level of Bob: %.1f",b_avg);
    printf("\nAverage energy level of James: %.1f",j_avg);


    printf("\nMaximum average energy level: ");

    if(b_avg > j_avg)
        printf("%.1f",b_avg);

    else
        printf("%.1f",j_avg);

}



int main()
{
    int N;

    printf("No. of matches:\n");
    scanf("%d",&N);

    int energy[r][N];

    read_energy(N,energy);
    print_energy(N,energy);
    were_high(N,energy);
    avg_max_energy(N,energy);
    printf("\n\n");

    return 0;
}



