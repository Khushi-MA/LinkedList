
#include<stdio.h>
int main()
{
    float R, G, B, W, C, Y, M, K;

    printf("enter the values of RGB");
    scanf("%f%f%f",&R,&G,&B);


    if(R==0 && G==0 && B==0)
    {
        W=0;
        C=0;
        M=0;
        Y=0;
        K=1;

    }

   else
   {
        if(R>G && R>B)
        W= R/255;

        else if(G>R && G>B)
        W= G/255;

        else
        W=B/255;

        C= (W-(R/255))/W;
        M= (W-(G/255))/W;
        Y= (W-(B/255))/W;
        K= 1-W;
   }


    printf("\nW %.1f\nC %.1f\nY %.1f\nM %.1f\nK %.1f\n",W,C,M,Y,K);


}
