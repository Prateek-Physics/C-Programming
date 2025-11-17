#include<stdio.h>
#include<math.h>

// Global variables for secant method
float acc = 0.000001;  // Desired accuracy
float x0 = 2;          // First initial guess
float x1 = 3;          // Second initial guess  
float x2, t, f0, f1, i; // Working variables

// Integrand function: f(x,t) = cos(x^1.5 * cos(t)) * sin(t)^3
float f(float x, float t) {          
    return cos(pow(x, 1.5) * cos(t)) * pow(sin(t), 3); 
}

// Total Integral as function F(x) using Simpson's 1/3 rule
float F(float x) {   
    float i, j;
    float s1 = 0, s2 = 0;  // Simpson's rule sums (MUST initialize to zero!)
    float a = 0.01;         // Lower limit of integration
    float b = 3.14159265;   // Upper limit of integration (π)
    float n = 40;           // Number of subintervals (must be even)
    float h = (b - a) / n;  // Step size
    float y;                // Final integral value
  
    
    // Simpson's rule: sum for odd-index terms
    for(i = 1; i < (n / 2.0); i++) {
        s1 += f(x, a + (2 * i - 1) * h);
    }
    
    // Simpson's rule: 
    for(j = 1; j <= (n / 2.0 - 1); j++) {
        s2 += f(x, a + 2 * j * h);
    }
    
   
    y = f(x, a) + f(x, b) + 4 * s1 + 2 * s2;
    return (y * (h / 3.0));
}

int main() {
  FILE*fp=NULL;
  fp=fopen("res3.txt","w");
    // Function declarations
    float f(float x, float t);
    float F(float x);
    float i;
    float l;                // used for plotting final function

    // Secant method iteration to find root of F(x)
    do {
        // Evaluate function at current points
        f0 = F(x0);
        f1 = F(x1);
        
        // Secant formula: x2 = (x0*f1 - x1*f0) / (f1 - f0)
        x2 = (x0 * f1 - x1 * f0) / (f1 - f0);
        
        // Update points for next iteration
        x0 = x1;
        x1 = x2;
        
        
        t = fabs(f1);
        
    } while(t > acc);  // Continue until desired accuracy is reached
    
    // Print final result
    printf("root = %f, f(x) = %f acc = %f \n\n", x1, f1, acc);

    


// Output:
// root = 2.723044, f(x) = 0.000001 acc = 0.000001

    for(l=0;l<=10;l+=0.1)
      {fprintf(fp,"%f \t %f\n",l,F(l));}

}
