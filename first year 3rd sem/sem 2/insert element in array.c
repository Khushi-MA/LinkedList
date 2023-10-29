
#include<stdio.h>
#include<math.h>
#define size 100


/*
void read_arr (int arr[size], int n)
{
    int i;
    printf("\nenter array elements");

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
}

void print_arr(int arr[size], int n)
{
    int i;
    printf("\narray elements are\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}

void insert_arr(int *p,int n,int x, int pos)
{
    int i,j;
    printf("fun entered");
    for(i=n;i<=pos;i++,p++)
    {
        (p+n)=(p+n-1);
    }
    //p='\0';
}



*/


void read_arr2(int *p, int n)
{
    int i;
    printf("\nenter array elements");

    for(i=0;i<n;i++,p++)
    {
        scanf("%d",p);
    }
}

void print_arr2(int *p, int n)
{
    int i;
    printf("\narray elements are:\n");

    for(i=0;i<n;i++,p++)
        {
            printf("%d\t",*p);
        }
}

void insert_arr2 (int p[size],int n,int pos, int x)
{
    int i;
printf("\n\n%d\n\n",p[n]);

    for(i=n;i<=pos;i++)
    {
        printf("\n\n%d\n\n",p[i+1]);
        p[i]=p[i-1];
    }
    p[pos-1]=x;
    return p;
}




int main()
{
    int arr[size],n,x,pos;

    printf("\nenter the number of elements");
    scanf("%d",&n);

     //using pointers
    read_arr2(arr,n);
    print_arr2(arr,n);

    printf("\nenter the element to be inserted ");
    scanf("%d",&x);
    printf("\nenter the position where it needs to be inserted");
    scanf("%d",&pos);
    insert_arr2(arr,n,pos,x);
    print_arr2(arr,n);


/*
     read_arr(arr,n);
    print_arr(arr,n);

    printf("\nenter the element to be inserted ");
    scanf("%d",&x);
    printf("\nenter the position where it needs to be inserted");
    scanf("%d",&pos);
    insert_arr(arr,n,pos,x);
    print_arr2(arr,n);


*/
}



