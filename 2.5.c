#include<stdio.h>
#include<math.h>
int main(){
  float x,y,z,j0,j1,j2,j3,j4,j5;
  FILE *fp=NULL;
  fp=fopen("data2.5.txt","w");
  
 
  for(z=0.1;z<=15;z+=0.001){
      
    j0=sin(z)/z;
    j1=sin(z)/pow(z,2)-cos(z)/z;
    j2=3*j1/z-j0;
    j3=5*j2/z-j1;
    j4=7*j3/z-j2;
    j5=9*j4/z-j3;
    fprintf(fp,"%f\t %f\t %f\t %f\t %f\t %f\t %f\n",z,j0,j1,j2,j3,j4,j5);

  }
  
}
