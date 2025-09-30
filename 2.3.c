#include<stdio.h>
#include<math.h>
#define pi 3.14159
int main(){
  float x,y,z,x1; int n;
  FILE*fp=NULL;
  fp=fopen("data8.txt","w");
  for (x=-(6*pi); x<=(6.0*pi); x=x+0.001)
    {n=(int)(x/(2.0*pi));
      x1=x-2.0*pi*n;
      z=fabs(x1);
      if(z>=0 && z<pi)
      {y=x;}
      if(z>=pi && z<2*pi)
	{y=2*pi-x;}
      fprintf(fp,"%f \t %f\n",x,y);
}
}
