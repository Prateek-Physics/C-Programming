#include<stdio.h> //sin(x) series
#include<math.h>
#define pi 3.14159265

int main()
{ FILE*fp=NULL;
  fp=fopen("res2.txt","w");
  float x,y,t,s,k,acc=0.00001;

  for(x=0;x<=(2*pi);x+=0.01)
    {s=x;t=x;k=1;
      do{t*=(-x*x)/((2*k)*(2*k+1));
	s+=t;
	k+=1; 
      }
      while(fabs(t/s)>acc);
      fprintf(fp,"%f \t %f\n",x,s);
    }


}
