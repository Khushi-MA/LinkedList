/* 8.
Suppose you are a biologist studying the growth rate of fruit flies. The  if  statement
  if (pop_today > pop_yesterday)
 {              growth = pop_today - pop_yesterday;
             growth_pct = 100.0 * growth / pop_yesterday;
             printf("The growth percentage is %.2f\n", growth_pct);
  }
computes the population growth from yesterday to today as a percentage
of  yesterday’s population. The compound statement after the condition
executes only when today’s population is larger than yesterday’s. The first
assignment computes the increase in the fruit fly population, and the second
assignment converts it to a percentage of the original population, which is displayed.
*/

#include<stdio.h>
int main()
{
    float pop_today,pop_yesterday,growth_pct,growth;
      printf("enter yesterdays population and today's population");
      scanf("%f%f",&pop_yesterday,&pop_today);
      if (pop_today > pop_yesterday);

      {
        growth = pop_today - pop_yesterday;
        growth_pct = 100.0 * growth / pop_yesterday;
        printf("The growth percentage is %.2f\n", growth_pct);
      }
return 0;

}
