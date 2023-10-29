#include<stdio.h>



void bubble_sort (int a[100], int n)
{
    int i,j,k,t;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if (a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}

void print_array(int a[100], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}

void read_elements(int a[100], int n )
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d\n",&a[i]);
    }

}

int main()
{
    int a[100];
    int n;
    scanf("%d",&n);
    read_elements(a,n);
    bubble_sort (a,n);
    print_array (a,n);
    return 0;
}
