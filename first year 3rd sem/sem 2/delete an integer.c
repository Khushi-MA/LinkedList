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


int delete_arr(int arr[size],int n,int a)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        if(arr[i]==a)
        {
            for(j=i;j<n;j++)
            {
                arr[j]=arr[j+1];
            }
        }
    }
    arr[n-1]='\0';
    return(arr);
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
    printf("\nenter array elements");

    for(i=0;i<n;i++,p++)
        {
            printf("%d\t",*p);
        }
}

void delete_arr2(int *p,int n,int a)
{
    int i,j;
    printf("fun entered");
    for(i=0;i<n;i++,p++)
    {
        if(*p==a)
        {
            for(j=i;j<n;j++,p++)
            {
                p=p+1;
            }
        }
    }
    //p='\0';
}


int main()
{
    int arr[size],n,del;

    printf("\nenter the number of elements");
    scanf("%d",&n);

     //using pointers
    read_arr2(arr,n);
    print_arr2(arr,n);

    printf("\nenter the element to be deleted ");
    scanf("%d",&del);
    delete_arr2(arr,n,del);
    print_arr2(arr,n-1);

/*
     read_arr(arr,n);
    print_arr(arr,n);

    printf("\nenter the element to be deleted ");
    scanf("%d",&del);
    arr[size] = delete_arr(arr,n,del);
    print_arr(arr,n-1);


*/
}


