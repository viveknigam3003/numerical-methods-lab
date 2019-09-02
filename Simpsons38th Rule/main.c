#include <stdio.h>
#include <stdlib.h>
#define TOL 10e-5

float y(float x)
{
    return 1/(1+x*x);
}

float simpson38(float a, float b, int n ) 
{ 
	int i;
    float value; 
    float h = (b - a) / n; 
    float s = y(a) + y(b);
  
    // Calculates value till integral limit 
    for (i = 1 ; i < n ; i++) 
    { 
        if (i % 3 == 0) 
            s += 2 * y(a + i * h); 
        else
            s += 3 * y(a + i * h); 
    } 
    return ( 3 * h / 8 ) * s ; 
}   

int main()
{
    float x0 = 0;
    float xn = 1;

    float ans,err;
    int n=2;
    do
    {
        ans = simpson38(x0,xn,n);
        err = fabs(atan(1)-ans);
        n++;
    }while (err > TOL/2);

    printf("*** Simpson's 3/8th Rule ***\n\n");
    printf("Intervals = %d\n", n);
    printf("Answer of Integral = %6.4f\n", ans);
}
