/*a black audi Q7 petrol car has fuel tank with capacity of
60L and mileage of 14 Kmpl. How far the car can travel in
Rs.1066.64 worth of petrol

solution:
the capacity is 60L
mileage is 14 kmpl
amount be w= 1066.64 Rs
let us assume the cost per litre for the
petrol same as in our area/city.
therefore, cost per litre is Rs 100.28
let, v= volume of petrol for given amount
d= distance traveled in v litres of petrol
*/

/*program to calculate the distance travelled
in given worth of petrol for above mentioned vehicle*/


#include<stdio.h>
int main()
{

    float w,v,d;
    printf("enter the worth of petrol in the tank, w");
    scanf("%f",&w);
    v=w/100.28;
    d=14*v;
    printf("distance traveled, d=%f",d);
    return 0;

}
