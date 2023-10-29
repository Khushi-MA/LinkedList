#include<stdio.h>
#include<math.h>

int main()
{
    printf("enter the numebr to get compliment:\n");
    int num;
    scanf("%d", num);
    num = bitwiseComplement(num);
    printf("compliment : %d",num);
    return 0;
}
    int bitwiseComplement(int n) {
        
        int binary=0;
        do{
            int digit = n%2;
            binary = binary*10 + digit;
            n = n/2;
        }while(n!=1);
        return binary;
    }
