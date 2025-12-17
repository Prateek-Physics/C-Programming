#include<stdio.h>
#include<math.h>

float f(float x,float y){
  return x+y;}

  int main(){
 float y,x=0,i,k1,k2,k3,k4,n,h=0.005,xf,xi,j,w;
 float f(float x,float y);
 FILE*fp1=NULL;
 FILE*fp2=NULL;
 FILE*fp3=NULL;
 fp1=fopen("res1.txt","w");
 fp2=fopen("res2.txt","w");
 fp3=fopen("res3.txt","w");
 xi=0.0;y=1.0;
 xf=5.0;

 do{ y=y+h*(x+y);// Euler method
   x=x+h;
   fprintf(fp1,"%f  \t   %f\n",x,y);

 }
 while(x<xf);

 n=(xf-xi)/h;//Runge Kutta
 x=xi;y=1; 

 for(i=1;i<=n;i++)
   
   {k1=h*f(x,y);
    k2=h*f(x+h/2.0,y+k1/2.0);
    k3=h*f(x+h/2.0,y+k2/2.0);
    k4=h*f(x+h,y+k3);
    y+=(k1+2*k2+2*k3+k4)/6.0;x+=h;
    fprintf(fp2,"%f \t  %f\n",x,y);


   }
 // analytical solution 
 for(j=0.0;j<=5.0;j+=0.01)
   {
     w=-j-1+2*exp(j);
     fprintf(fp3,"%f \t  %f\n",j,w);


  }
  }
