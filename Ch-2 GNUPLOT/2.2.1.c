#include<stdio.h>
#include<math.h>
#define pi 3.14159
int main()
{FILE*fp=NULL;
  fp=fopen("data5.txt","w");
  float A=1,x,theta,delta=pi/4,n,y;
  for(n=2;n<=3;n+=0.5){
    for(theta=0;theta<=4*pi;theta+=0.001){
      x=sin(theta);
      y=A*sin(n*theta+delta);
      fprintf(fp,"%f\t %f\t %3.1f\n" ,x,y,n);

    }
    fprintf(fp, "\n");
  }  
}
