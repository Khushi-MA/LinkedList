 #include<stdio.h>
 int main()
 {
     int m,n,rem;

     printf("enter the number GCD required\n");
     scanf("%d \n%d",&m,&n);

     while (n!=0)
     {
         rem = m%n;
         m=n;
         n=rem;

     }

     printf("GCD = %d",m);

     return 0;

 }


