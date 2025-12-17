#include<stdio.h>
#include<math.h>

float f(float x)
{return sin(x)/x;}
float g(float x)
{return sin(x)/(x*x)-cos(x)/x;}

int main()
{FILE*fp=NULL;
  fp=fopen("res2.txt","w");
  float j0,j1,j2,z,n;
  for(z=0.3;z<=5;z+=0.01)
    {j0=f(z);
      j1=g(z);
      fprintf(fp,"%f \t %f \t %f",z,j0,j1);
     
      for(n=1;n<=4;n++)
	{
	 j2=(2*n+1)*(j1/z)-j0;
	 j0=j1; j1=j2;
	 fprintf(fp,"\t %f",j2);}
      fprintf(fp,"\n");

    }
 
    }
/*GNUPLOT commands are given below
gnuplot> plot "res2.txt" using 1:2 with linespoints title "j0",\
>"res2.txt" using 1:3 with linespoints title "j1",\
>"res2.txt" using 1:4 with linespoints title "j2",\
>"res2.txt" using 1:5 with linespoints title "j3",\
>"res2.txt" using 1:6 with linespoints title "j4",\
>"res2.txt" using 1:7 with linespoints title "j5",
*/
