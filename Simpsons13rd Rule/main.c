#include <stdio.h>
#include <stdlib.h>
#define TOL 10e-5

float y(float x)
{
    return 1/(1+x*x);
}

float simpson13(float a, float b, float n)
{
    int i;

    float h=(b-a)/n;
	float s=y(a)+y(b);

    for(i=1; i<n ;i++)
    {
        if(i%2!=0)   //odd
            s+=4*y(a + i*h);
        else 	     //even
            s+=2*y(a + i*h);
    }
    return (s*h/3);
}

int main()
{
    float x0 = 0;
    float xn = 1;

    float ans,err;
    int n=2;
    do
    {
        ans = simpson13(x0,xn,n);
        err = fabs(atan(1)-ans);
        n++;
    }while (err > TOL/2);

    printf("*** Simpson's 1/3rd Rule ***\n\n");
    printf("Intervals = %d\n", n);
    printf("Answer of Integral = %6.4f\n", ans);
}
