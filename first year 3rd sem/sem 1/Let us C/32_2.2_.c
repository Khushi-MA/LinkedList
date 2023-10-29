#include<stdio.h>
int main()
{
    int i,num,rev_num,rem,n,number;
    printf("enter the number to be reversed\n");
    scanf("%d",&num);
    printf("enter the number of digits in the number");
    scanf("%d",&n);
    number = num;

    for(i=0,rem=0,rev_num=0;i<n;i++)
    {
        rem = num%10;
        rev_num = (rev_num*10) + rem;
        num = num/10;
    }

    printf("\n%d\n%d",number,rev_num);
}
