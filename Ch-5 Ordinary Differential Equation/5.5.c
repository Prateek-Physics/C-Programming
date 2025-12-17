#include<stdio.h>
#include<math.h>
#define f1(t,x,y,z) (-10.0*((x)-(y))) //Every variable must be inside brackets
#define f2(t,x,y,z) ((a)*(x)-(x)*(z)-(y))//OR you will get x,y,z valies as -nan
#define f3(t,x,y,z) ((x)*(y)-(8.0/3.0)*(z))

int main() {
  float h=0.01,k1,k2,k3,k4,m1,m2,m3,m4,l1,l2,l3,l4,x,y,z,t,a=200.0;
  FILE*fp=NULL;
  fp=fopen("lorenz_3d.dat","w");

  t=0.0; x=1; y=2; z=1;
  
  do{
    
    k1=h*f1(t,x,y,z);
    m1=h*f2(t,x,y,z);
    l1=h*f3(t,x,y,z);

    k2=h*f1(t+h/2.0,x+k1/2.0,y+m1/2.0,z+l1/2.0);
    m2=h*f2(t+h/2.0,x+k1/2.0,y+m1/2.0,z+l1/2.0);
    l2=h*f3(t+h/2.0,x+k1/2.0,y+m1/2.0,z+l1/2.0);

    k3=h*f1(t+h/2.0,x+k2/2.0,y+m2/2.0,z+l2/2.0);
    m3=h*f2(t+h/2.0,x+k2/2.0,y+m2/2.0,z+l2/2.0);
    l3=h*f3(t+h/2.0,x+k2/2.0,y+m2/2.0,z+l2/2.0);

    k4=h*f1(t+h,x+k3,y+m3,z+l3);
    m4=h*f2(t+h,x+k3,y+m3,z+l3);
    l4=h*f3(t+h,x+k3,y+m3,z+l3);

    t+=h;
    x+=(1/6.0)*(k1+2*k2+2*k3+k4);
    y+=(1/6.0)*(m1+2*m2+2*m3+m4);
    z+=(1/6.0)*(l1+2*l2+2*l3+l4);
    
    // Output all three coordinates (X, Y, Z) for 3D plotting
    fprintf(fp,"%f \t %f \t %f\n",x,y,z);
  }
  while(t<=20);

  fclose(fp);
  printf("Data written to lorenz_3d.dat\n");
  return 0;
}

/* GNUPLOT CODES

gnuplot> set title "Lorenz Attractor"
gnuplot> set xlabel "x"
gnuplot> set ylabel "y"
gnuplot> set zlabel "z"
gnuplot> set grid
gnuplot> set view 60,30,1,1
gnuplot> splot "lorenz_3d.dat" using 1:2:3 with linespoints lw 0.5 lc palette


*/


