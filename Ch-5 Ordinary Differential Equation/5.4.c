#include<stdio.h>
#include<math.h>
#define pi 3.14159265
#define f1(x,y,z) ((z))
#define f2(x,y,z) ((f4(x)-(z)-4*(x)*(y)))

float f4(float x){
    float i,t,sum=0;
    for(i=0;i<=10;i++)
    {
    t*=-(x*x)/((2*i+3)*(2*i+2));
    sum+=t;
    return sum;
    }
}

int main()
{
    float f4(float x);
    float h=0.01,x,y,z,k1,k2,k3,k4,m1,m2,m3,m4,r;
    FILE*fp=NULL;
    fp=fopen("res4.txt","w");
    x=0.0;y=0.0; z=1.0;
    do
    {
    k1=h*f1(x,y,z);
    m1=h*f2(x,y,z);
    k2=h*f1(x+h/2.0,y+k1/2.0,z+m1/2.0);
    m2=h*f2(x+h/2.0,y+k1/2.0,z+m1/2.0);
    k3=h*f1(x+h/2.0,y+k2/2.0,z+m2/2.0);
    m3=h*f2(x+h/2.0,y+k2/2.0,z+m2/2.0);
    k4=h*f1(x+h/2.0,y+k3,z+m3);
    m4=h*f2(x+h/2.0,y+k3,z+m3);
    y=y+(1/6.0)*(k1+2.0*(k2+k3)+k4);
    z=z+(m1+2.0*(m2+m3)+m4)/6.0;
    x=x+h;
    //r=cos(x);
    fprintf(fp,"%f \t %f\n",x,y);
    }
    while(x<=1);
    return 0;
}
