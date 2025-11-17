#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float E=0.0; //global variable
float f(float x)
{ return 1/((x*x)*(sqrt(2*E+2/x-1/(x*x))));}

int main()
  
{
  FILE*fp=NULL;
  fp=fopen("res6.txt","w");
  float f(float x);
  float c,d,z,z1,x[20],w[20],a=0.5,b,s,x_,y;   int n=8,i; //r_0=1 and r_m=b
  #include "gauss.c"

  for(b=a;b<=5;b+=0.01){
  c=0.5*(b+a);  d=0.5*(b-a);
  s=0.0;
  for(i=0;i<=n/2.0-1; i++)
    {z=(c+d*x[i]); z1=c-d*x[i];
      s+=w[i]*(f(z)+f(z1));}
  s*=d;
  x_=b*cos(s);
  y=b*sin(s);
   fprintf(fp,"%f \t %f\n",x_,y);
   //fprintf(fp,"%f \t %f\n",b,s); use comments to get different points to plot
  }
}
  
