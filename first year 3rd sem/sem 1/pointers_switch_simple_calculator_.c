#include<stdio.h>

void calculate(int n1, int n2, int *add, int *sub, int *mul,int *div)
{
    int subt;
    *add=n1+n2;

    subt=n1-n2;
    if(subt>=0)
        *sub=subt;
    else
    *sub=-subt;

    *mul=(n1*n2);

    *div=n1/n2;

}


int main()
{
    int n1,n2,t,add,sub,mul,div;
    printf("enter the two numbers");
    scanf("%d%d",&n1,&n2);
    calculate(n1,n2,&add,&sub,&mul,&div);
    printf("to do:\n1.Add\n2.subtract\n3.divide\n4.multiply\nEnter your function number: ");
    scanf("%d",&t);
    switch(t)
    {
        case 1:
        printf("\n%d",add);
        break;

        case 2:
        printf("\n%d",sub);
        break;

        case 3:
        printf("\n%d",mul);
        break;

        case 4:
        printf("\n%d",div);
        break;

    }





}
