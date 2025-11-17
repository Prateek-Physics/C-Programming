#include<stdio.h>
#include<math.h>
#define pi 3.14159265

float A;
float f(float x){
  return 1/sqrt((1-pow(sin(A/2.0),2)*(pow(sin(x),2))));} // THis is correct formula

  int main() {
    FILE*fp=NULL;
    fp=fopen("res2.txt","w");
    float f(float x);
    float t,T,i,s=0,n=10,a=0,b=pi/2.0,h,y,w;
    h=(b-a)/n;
     
    for(A=0.1;A<3;A+=0.1){ // Trapezoidal method
      for(i=1;i<=n-1;i++){ 
	s+=f(a+i*h);
      }
      T=2*pi*(1+(A/4.0)*(A/4.0));
      t=(h/2.0)*(f(a)+f(b)+2*s);
      w=(fabs((4*t-T)/(4*t)))*100;
      fprintf(fp,"%f \t %f \t %f \t %f\n",A,4*t,T,w);
      s=0; }
  }
