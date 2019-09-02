/*
Title - Fixed Point Iteration-1
Author - Vivek Nigam (IMH/100006/17)
Lab - Numerical Methods Lab - 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func1 (double x)
{
    return ((20*x+21/(x*x))/21);
}

double func2 (double x)
{
    return (x-(x*x*x-21)/(3*x*x));
}

double func3 (double x)
{
    return (x-(pow(x,4)-21*x)/(x*x-21));
}

double func4 (double x)
{
    return (sqrt(21/x));
}

int main()
{
    int iter=4, i;
    float x,x0,x1,xn;
    printf("\nEnter Initial Guess:");
    scanf("%f", &x);
    x0=x;
    float a[4];

    printf("\nUsing Function 1:-");
    for (i=1; i<=iter; i++)
    {
        x1=func1(x);
        printf("\nAfter %d iteration: %f", i, x1);
        xn=x;
        x=x1;
        a[0]=fabs(xn-x1);
    }
    printf("\n|x-x1| = %f\n", a[0]);
    x1=0;x=x0;

    printf("\nUsing Function 2:-");
    for (i=1; i<=iter; i++)
    {
        x1=func2(x);
        printf("\nAfter %d iteration: %f", i, x1);
        xn=x;
        x=x1;
        a[1]=fabs(xn-x1);
    }
    printf("\n|x-x1| = %f\n", a[1]);
    x1=0;x=x0;

    printf("\nUsing Function 3:-");
    for (i=1; i<=iter; i++)
    {
        x1=func3(x);
        printf("\nAfter %d iteration: %f", i, x1);
        xn=x;
        x=x1;
        a[2]=fabs(xn-x1);
    }
    printf("\n|x-x1| = %f\n", a[2]);
    x1=0;x=x0;

    printf("\nUsing Function 4:-");
    for (i=1; i<=iter; i++)
    {
        x1=func4(x);
        printf("\nAfter %d iteration: %f", i, x1);
        xn=x;
        x=x1;
        a[3]=fabs(xn-x1);
    }
    printf("\n|x-x1| = %f\n", a[3]);
    x1=0;x=x0;

    printf("\nReport:\n");
    for (i = 0; i<4; i++)
    {
        printf("Error Using func %d = %f\n", (i+1), a[i]);
    }
    
    return 0;
}

