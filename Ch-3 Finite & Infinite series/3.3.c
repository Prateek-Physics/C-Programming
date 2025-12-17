#include<stdio.h>
#include<math.h>

int main()
{ FILE*fp=NULL;
  fp=fopen("res2.txt","w");
  float x,t,k,n,s,acc=0.01;
  for(x=0.5;x<=10;x+=0.01){
    fprintf(fp,"%f",x);
  for(n=0;n<=3;n++)
    {t=1/tgamma(n+1);s=t;k=0;
      do{ t*=-(x*x)/(4*(k+1)*(n+k+1));// dont forget 1/4 and (x/2)^n factor
	s+=t;
	k+=1;}
      while(fabs(t/s)>acc);// must use fabs
      fprintf(fp,"\t %f",s*(pow(x/2.0,n)));
    } fprintf(fp,"\n");

    }



}
