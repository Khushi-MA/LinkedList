#include<stdio.h>


int main()
{
    int i, a, b;
    printf("number of rows and columns");
    scanf("%d%d",&a,&b);

    int matrix[a][b];

    read_ele(a,b,matrix[a][b]);
    display_ele(a,b,matrix[a][b]);
    sort(a,b,matrix[a][b]);
    display_ele(a,b,matrix[a][b]);


}

void read_ele ( int a, int b, int matrix[a][b])
{
    int i, j;
    printf("enter elements row wise");
    for(i=0;i<a;i++)
    {
        for (j=0;j<b;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
}

void display_ele(int a, int b, int matrix[a][b])
{
    int i,j;
    printf("\n");
    for(i=0;i<a;i++)
    {
        printf("\n");
        for(j=0;j<b;j++)
        {
            printf("%d\t",matrix[i][j]);
        }
    }

}

void sort( int a, int b, int matrix[a][b])
{
    int i,j,t,temp;
   /* for(i=0;i<(a*b*2);i++)
    {
        for(j=0;j<a;j++)
        {
            for(k=0;k<b-1;k++)
            {
                if(matrix[i][j]>matrix[i][j+1])
                {
                    t=matrix[i][j];
                    matrix[i][j]=matrix[i][j+1];
                    matrix[i][j+1]=t;
                }
            }
        }
    }
    */

fd     int i,j,t,temp;
    for(t = 0 ; t<50 ; t++ )
    {for (i =0 ; i < a ; i++)
    {
        for(  j = 0; j < 5-1 ; j++)
        {
            if (arr[i][j] > matrix[i][j+1])
            {
                temp = [i][j];
                matrix[i][j] = [i][j+1];
                [i][j+1] = temp;
            }
        }

        //checking for

}
