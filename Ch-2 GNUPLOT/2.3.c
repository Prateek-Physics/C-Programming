#include<stdio.h>
#include<math.h>
#define pi 3.14159265

int main()
{FILE*fp=NULL;
  fp=fopen("res1.txt","w");
  float x,x1,a,b,n,z,i,y;
  for(x=-6*pi;x<=6*pi;x+=0.1){
    n=(int)(x/(2*pi));
    x1=x-2*pi*n;
    z=fabs(x1);
    if(z>=0 && z<pi)
      {y=z;}
    else if(z>=pi && z<2*pi)
      {y=2*pi-z;}
    fprintf(fp,"%f \t %f\n",x,y);}}
    
