#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TOL 10e-5

double func (double x)
{
    return (2+5/(x*x));
}

int main()
{
    int i=1;
    float x,x1,xn;
    printf("\nEnter Initial Guess:");
    scanf("%f", &x);

    do
    {
        x1=func(x);
        printf("\nAfter %d iteration: %f", i, x1);
        xn=x;
        x=x1;
        i++;
    }while(fabs(xn-x1) >= TOL);

    printf("\n\nRoot = %f\n", x1);
    printf("\nNumber of Iterations = %d", i-1);
    return 0;
}