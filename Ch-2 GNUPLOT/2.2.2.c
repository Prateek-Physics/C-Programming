#include<stdio.h>
#include<math.h>
#define pi 3.14159
int main()
{FILE*fp=NULL;
  fp=fopen("data6.txt","w");
  float A,x,theta,delta=pi/4,n=2,y;
  for(A=0.5;A<=2;A+=0.5){
    for(theta=0;theta<=4*pi;theta+=0.001){
      x=sin(theta);
      y=A*sin(n*theta+delta);
      fprintf(fp,"%f\t %f\t %3.1f\n" ,x,y,A);

    }
    fprintf(fp, "\n");
  }  
}
