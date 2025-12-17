#include<stdio.h>
#include<math.h>

float f(float x)
{
  float i=1,t=1,s=1,acc=0.000001;  
    
  do {t*=-(x*x)/(4*i*i);
    s+=t;
    i+=1;  }

  while (fabs(t)> acc);
  return s;

    }
int main()
{
  float y=2.5,x1,x2,x3,xm,acc=0.000001,z,i; int n;
  float f(float x);

  for(i=0; i<=10; i+=0.5){
    printf("Value of function at %f is %f\n",i,f(i)); }

    printf("Enter number of roots:");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
      {
	printf("Enter x1,x2:");
	scanf("%f, %f",&x1,&x2); 

	do {xm=(x1+x2)/2.0;
	  if( f(x1)*f(xm)<0)// no ; needed 
	    {x2=xm;}
	  if(f(x1)*f(xm)>0) // no ;
	    { x1=xm;}
	  // else {printf("Something is Wrong :(");
	  // break;}
	  z=fabs((x1-x2)/(x1+x2));}
	
	  while(z>acc);
	  printf("Root = %f  f(x)=%f acc=%f\n",xm,f(xm),acc);

	}

      }
/* Output-
  Value of function at 0.000000 is 1.000000
Value of function at 0.500000 is 0.938470
Value of function at 1.000000 is 0.765198
Value of function at 1.500000 is 0.511828
Value of function at 2.000000 is 0.223891
Value of function at 2.500000 is -0.048384
Value of function at 3.000000 is -0.260052
Value of function at 3.500000 is -0.380128
Value of function at 4.000000 is -0.397150
Value of function at 4.500000 is -0.320543
Value of function at 5.000000 is -0.177597
Value of function at 5.500000 is -0.006844
Value of function at 6.000000 is 0.150645
Value of function at 6.500000 is 0.260095
Value of function at 7.000000 is 0.300079
Value of function at 7.500000 is 0.266340
Value of function at 8.000000 is 0.171649
Value of function at 8.500000 is 0.041943
Value of function at 9.000000 is -0.090342
Value of function at 9.500000 is -0.193925
Value of function at 10.000000 is -0.245948
Enter number of roots:3
Enter x1,x2:2,2.5
Root = 2.404827  f(x)=-0.000001 acc=0.000001
Enter x1,x2:5.5,6
Root = 5.520073  f(x)=-0.000002 acc=0.000001
Enter x1,x2:8.5,9
Root = 8.653732  f(x)=0.000004 acc=0.000001
  */

     
