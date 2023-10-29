#include<stdio.h>
#define SIZE 50

void display_prime(int a[SIZE],int n)
{
    int p,i;
    for(i=0;i<n;i++)
    {
        p=is_prime(a[i]);
        if (p==1)
        {
            printf("%d",a[i]);
        }
        return;

    }
}

int is_prime(int n)
{

    int j;
    for (j=0;j<sqrt(n);j++)
    {
        if(n%j==0)
            return 0;

        else
            return 1;
    }

}

void read_num(int a[SIZE],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

}

int main()
{
    int a[SIZE],n;
    // enter the number of array box to be used
    //or number of prime numbers
    scanf("%d",&n);
    read_num(a,n);
    display_prime(a,n);
    return 0;
}
