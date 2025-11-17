#include<stdio.h>
#include<math.h>
#define pi 3.14159265

// Global variables for secant method
float acc = 0.00001;  // Desired accuracy
float x0;          // First initial guess
float x1 ;          // Second initial guess  
float x2, t, f0, f1, i; // Working variables

// Integrand function: f(x,t) = cos(x^1.5 * cos(t)) * sin(t)^3
float f(float x, float t) {          
  return cos(x*cos(t));   // x-->t ,z-->x
}

// Total Integral as function F(x) using Simpson's 1/3 rule
float J(float x) {   
    float i, j;
    float s1 = 0, s2 = 0;  // Simpson's rule sums 
    float a = 0.0;         // Lower limit of integration
    float b =2*pi;          // Upper limit of integration
    float n = 40;           // Number of subintervals (must be even)
    float h = (b - a) / n;  // Step size
    float y;                // Final integral value
  
    
    // Simpson's rule: sum for odd-index terms
    for(i = 1; i < (n / 2.0); i++) {
        s1 += f(x, a + (2 * i - 1) * h);
    }
    
    // Simpson's rule: sum for even-index terms  
    for(j = 1; j <= (n / 2.0 - 1); j++) {
        s2 += f(x, a + 2 * j * h);
    }
    
    y = f(x, a) + f(x, b) + 4 * s1 + 2 * s2;
    return ((y * (h / 3.0))/(2*pi));
}

int main() {
  FILE*fp=NULL;
  fp=fopen("res4.txt","w");
    // Function declarations
    float f(float x, float t);
    float J(float x);
    float l,q;                // used for plotting final function

      // Secant method iteration to find root of F(x)
    
    for(q=1;q<=4;q++){
      printf("Enter x0:");
      scanf("%f",&x0);
       printf("Enter x1:");
      scanf("%f",&x1);
    
    do {
        // Evaluate function at current points
        f0 = J(x0);
        f1 = J(x1);
        
        // Secant formula: x2 = (x0*f1 - x1*f0) / (f1 - f0)
        x2 = (x0 * f1 - x1 * f0) / (f1 - f0);
        
        // Update points for next iteration
        x0 = x1;
        x1 = x2;
        
        // Calculate current error
        t = fabs(f1);
        
    } while(t > acc);  // Continue until desired accuracy is reached
    
    // Print final result
    printf("root = %f, f(x) = %f acc = %f \n\n", x1, f1, acc);}

    


       for(l=0;l<=13;l+=0.1)
	 {fprintf(fp,"%f \t %f\n",l,J(l));}

}
/*Enter x0:2
Enter x1:3
root = 2.456141, f(x) = -0.000000 acc = 0.000010

Enter x0:5
Enter x1:6
root = 5.595403, f(x) = 0.000001 acc = 0.000010

Enter x0:8
Enter x1:9
root = 8.745479, f(x) = 0.000000 acc = 0.000010

Enter x0:11
Enter x1:12
root = 11.896214, f(x) = -0.000000 acc = 0.000010
*/
