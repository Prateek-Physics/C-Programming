#include<stdio.h>
#include<math.h>
#define pi 3.14159265

int main()
{ FILE*fp=NULL;
  fp=fopen("res2.txt","w");
  float x,t,k,n,s,acc=0.0001;
  for(x=0.0;x<=1;x+=0.05)
    {k=0;t=x;s=t;
      do{t*=-(pi*pi*pow(x,4))/((4*k+5));
	s+=t;
	k+=1;}

      while(fabs(t/s)>acc);
      fprintf(fp,"%f \t %f\n",x,s*cos(x*x*pi/2.0));
    
  }


}
