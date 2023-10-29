/*an auto charges Rs. Fd for the first s..km and
Rs. Fs/km after travelling s. calculate the total
fees to cover a distance of T..km.
(FS be the total fees after covering first s..km ,
 FT be the total fees charged to travel T..km.*/

#include<stdio.h>
int main()
{
    float d,Fd,s,Fs,FS,T,FT;
    printf("enter total distance between the points,\ndistance for which charge is fixed,\n");
    printf("enter fees for fix distance,\nenter fees per km after fix distance\n");
    scanf("%f%f%f%f",&T,&d,&Fd,&Fs);
    s=T-d;
    FS=s*Fs;
    FT=Fd+FS;
    printf("fees paid after fixed distance=%f\n",FS);
    printf("total fees paid=%f\n",FT);

    return 0;


}
