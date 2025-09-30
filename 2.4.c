#include<stdio.h>
#include<math.h>
#define pi 3.14159
int main(){
  float x0,x1,x2,x3,y0,y1,y2,y3,f0,f1,f2,f3,y,m,l=3,theta;
  FILE*fp=NULL;
  fp=fopen("data4.txt","w");
  for (theta=(0); theta<=(2.0*pi); theta=theta+0.001)
    {f0=(3*sqrt(14)/4)*(5/3 *pow(cos(theta), 3.0) -cos(theta));
      f1=(sqrt(42)/8)*(sin(theta)*(5*pow(cos(theta),2.0)-1));
      f2=(sqrt(105)/4)*pow(sin(theta),2.0)*cos(theta);
      f3=(sqrt(70)/8)*(pow(sin(theta),3.0));
      x0=f0*f0*cos(theta); y0=f0*f0*sin(theta);
      x1=f1*f1*cos(theta); y1=f1*f1*sin(theta);
      x2=f2*f2*cos(theta); y2=f2*f2*sin(theta);
      x3=f3*f3*cos(theta); y3=f3*f3*sin(theta);
      
      
      fprintf(fp,"%f %f %f %f %f %f %f %f \n",x0,x1,x2,x3,y0,y1,y2,y3);
}
}
