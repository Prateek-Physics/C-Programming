#include<stdio.h>
#include<math.h>

int main()
{float i,s=1,t,x=1.5; // for x=1.5
  for(i=2;i<20;i++)
    {s+=(1/(pow(x,i)));}
  printf("sum is %f\n",s);

}
// sum is 2.332431
// matches with solution calculated by gp series
