// Chapter 4  Problem 1 part 2, a=-1.5,b=10.Part 1 can be done similarly :)

#include <stdio.h>
#include <math.h>

float f(float x)
{ return (exp(-1.5*x)-10*x*x);
}

float g(float x)
{
  return (-1.5*exp(-1.5*x)-10*2*x);
}


int main()
{
  float x,xm,xl,xr,x1,x2,x3,f1,f2,acc=0.001,z=0,a,b,h,t,w=0,q;
    int n,i;
    float f(float x);
    printf("Enter the minimum value of x:");
    scanf("%f",&a);
    printf("Enter the maximum value of x:");
    scanf("%f",&b);
    for (x=a;x<=b;x=x+0.1)
    {printf("%f \t %f\n",x,f(x));
}

    printf("input no of roots :");
    scanf("%d",&n);
    printf("\n"); 

   
    for (i=1;i<=n;i+=1)
    {
      printf("Note-For Newton Raphson only x2 matters");
        printf("\ninput x1,x2:");
        scanf("%f,%f",&x1,&x2);
	printf("\n");
	
	q=x2;
        
	// Bisection
                
                do
                { 
                    xm=(x1+x2)/2.0;
		    w+=1;
                    
                    if(f(xm)*f(x1)>0)
                    {
                        x1=xm;
                    }
                    if(f(xm)*f(x1)<0)
                    {
                        x2=xm;
                    }
                    
                    z=fabs((x1-x2)/(x1+x2));
                    
                } while(z>acc);

		printf("Using Bisection method !");
                printf("\nroot=%f f(xm)=%f  acc=%f\n",xm,f(xm),acc);
		printf("No of iteration is %f\n\n",w);
		w=0;

		//secant method 
                do
                {
                     f1=f(x1);
                     f2=f(x2);
                     x3=(x1*f2-x2*f1)/(f2-f1);
                     x1=x2;
                     x2=x3;
                     t=fabs(f2);
                     w+=1;
                }while(t>acc);

		printf("Using Secant Method !");
                printf("\nroot=%f f(x2)=%f acc=%f\n",x2,f2,acc);
                printf("No of iterations: %f\n\n",w);

                w=0; // re entering their value since it has changed
		
		
		// Newton-Raphson
		do
                 {
		   f1 = f(q);// we stored initial values of x2 in q to preserve it
                    f2 = g(q);
                    h = -f1/f2;
                    q = q + h;
                	w+=1;
 }

		while(fabs(h/q) > acc);
    
    printf("Using Newton-Raphson \n ");
    printf("Root found at x = %f, f(x) = %f\n", q, f1);
    printf("No of iterations: %f\n\n",w);

    }




        }

/* output 
Enter the minimum value of x:-1
Enter the maximum value of x:1
-1.000000        -5.518311
-0.900000        -4.242574
-0.800000        -3.079882
-0.700000        -2.042348
-0.600000        -1.140396
-0.500000        -0.382999
-0.400000        0.222119
-0.300000        0.668312
-0.200000        0.949859
-0.100000        1.061834
0.000000         1.000000
0.100000         0.760708
0.200000         0.340818
0.300000         -0.262372
0.400000         -1.051189
0.500000         -2.027634
0.600000         -3.193431
0.700000         -4.550064
0.800000         -6.098808
0.900000         -7.840763
input no of roots :2

Note-For Newton Raphson only x2 matters
input x1,x2:-0.5,-0.4

Using Bisection method !
root=-0.439844 f(xm)=-0.000286  acc=0.001000
No of iteration is 7.000000

Using Secant Method !
root=-0.439795 f(x2)=0.000000 acc=0.001000
No of iterations: 2.000000

Using Newton-Raphson
 Root found at x = -0.439795, f(x) = -0.000044
No of iterations: 3.000000

Note-For Newton Raphson only x2 matters
input x1,x2:0.2,0.3

Using Bisection method !
root=0.260547 f(xm)=-0.002345  acc=0.001000
No of iteration is 11.000000

Using Secant Method !
root=0.260170 f(x2)=0.000000 acc=0.001000
No of iterations: 2.000000

Using Newton-Raphson
 Root found at x = 0.260170, f(x) = -0.000041
No of iterations: 3.000000
*/
