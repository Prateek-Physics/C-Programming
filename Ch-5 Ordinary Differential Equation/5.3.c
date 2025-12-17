#include<stdio.h>
#include<math.h>
#define pi 3.14159265
#define f1(t,x,y) (0.25*(x)-0.01*(x)*(y)) // must use paramthesis here or
#define f2(t,x,y) (-1.0*(y)+0.01*(x)*(y))// WRONG results will appear
int main()
{
    float h=0.01,x,y,t,k1,k2,k3,k4,m1,m2,m3,m4,y1,y2,y3,y4;
    FILE*fp=NULL;
    fp=fopen("res3.txt","w");
    t=0.0;x=100.0; y=5.0;
    do
    {
    k1=h*f1(t,x,y);
    m1=h*f2(t,x,y);
    k2=h*f1(t+h/2.0,x+k1/2.0,y+m1/2.0);
    m2=h*f2(t+h/2.0,x+k1/2.0,y+m1/2.0);
    k3=h*f1(t+h/2.0,x+k2/2.0,y+m2/2.0);
    m3=h*f2(t+h/2.0,x+k2/2.0,y+m2/2.0);
    k4=h*f1(t+h,x+k3,y+m3);
    m4=h*f2(t+h,x+k3,y+m3);
    x=x+(1/6.0)*(k1+2.0*(k2+k3)+k4);
    y=y+(m1+2.0*(m2+m3)+m4)/6.0;
    t=t+h;
    //r=cos(x);
    fprintf(fp,"%f \t %f\n",x,y);
    }
    while(t<=20);
}
