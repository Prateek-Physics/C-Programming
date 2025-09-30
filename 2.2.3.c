#include<stdio.h>
#include<math.h>
#define pi 3.14159
int main()
{FILE*fp=NULL;
  fp=fopen("data7.txt","w");
  float A=1,x,theta,delta,n=2,y;
  for(delta=pi/4; delta<3.15; delta*=2){
    for(theta=0;theta<=4*pi;theta+=0.001){
      x=sin(theta);
      y=A*sin(n*theta+delta);
      fprintf(fp,"%f\t %f\t %3.1f\n" ,x,y,delta);

    }
    fprintf(fp, "\n");
  }  
}
