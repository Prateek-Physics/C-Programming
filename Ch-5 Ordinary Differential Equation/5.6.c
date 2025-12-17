/* solving x_(n+1)=alpha x_n - alpha x_n^2 */

#include<stdio.h>
#include<math.h>

int main()
{
    float a,x;
    int i;
    FILE *fp=NULL;
    //FILE *fp1=NULL;
    
    fp=fopen("res.txt","w");
    //fp1=fopen("res2.txt","w");
    x=0.9;
    
    for (a=0.01; a<=4.0; a+=0.05)
    {
        x=0.9;
        i=0;
        do{
            x=a*x - a*x*x;
            //fprintf(fp1,"%f\t %f\n",x,a);
            i++;
            if (i>10000)
            {
                fprintf(fp,"%f \t %f \t %d\n",x,a,i);
            }
        } while(i<=10100);
    }
    
    fclose(fp);
    //fclose(fp1);
    return 0;
}
