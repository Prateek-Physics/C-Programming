#include<stdio.h>
#include<math.h>
#define pi 3.14159265

float f(float x,float t)
{return x-0.8*sin(x)-t;}

float g(float x,float t)
{return 1.0-0.8*cos(x);} // take derivative carefully , missing 1 caused nan in data file

int main()
{ FILE*fp=NULL;
  fp=fopen("res2.txt","w");
  float f(float x,float t);
  float g(float x,float t);
  float x,i,a,f1,f2,x1,x2,x3,t,acc=0.001,r,c,s,x_,y_,h;
  for(t=0.01;t<=2*pi;t+=0.05)
    { x=t;
      do{f1=f(x,t);
	f2=g(x,t);
	h=-f1/f2;
	x+=h; }
      while(fabs(h/x)>acc);
      r=2*(1-0.8*cos(x));
      c=(cos(x)-0.8)/( 1-0.8*cos(x));
      s=sqrt(fabs(1-c*c));
      x_=r*c;
      y_=r*s;
      fprintf(fp,"%f \t %f\n",x_,y_);
      fprintf(fp,"%f \t %f\n",x_,-y_);
    }


}
