#include<stdio.h>
#include<math.h>
#define pi 3.14159265

int main()
{ FILE*fp=NULL;
  fp=fopen("res2.txt","w");
  float x,t,k,n,s,acc=0.0001;
  for(x=-10.0;x<=2.0;x+=0.05)
    {k=1;t=(x*x*x)/6.0;s=t;
      do{t*=((x*x*x))/((3*k+2)*(3*k+3));
	s+=t;
	k+=1;}

      while(fabs(t/s)>acc);
      fprintf(fp,"%f \t %f\n",x,(1+s)*0.35503);// R=x^3/(3k+3*(3k+2))
    
  }

}
