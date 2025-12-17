#include<stdio.h>
#include<math.h>
#define pi 3.14159265

int main()
{ FILE*fp=NULL;
  fp=fopen("res2.txt","w");
  float x,t,k,n,s,acc=0.0001;
  for(x=0.0;x<=5;x+=0.05)
    {k=0;t=1/(4*tgamma(3/2));s=t;
      do{t*=((2*x*x)*(1-k))/((k+2)*(k+1));
	s+=t;
	k+=2;}

      while(fabs(t/s)>acc);
      fprintf(fp,"%f \t %f\n",x,s);
    
  }

}
