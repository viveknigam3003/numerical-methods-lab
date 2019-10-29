#include<stdio.h>
#include <math.h>

//dy/dx = 1 + y^2#define F(x,y)  1 + (y)*(y)

double func(double x, double y)
{
    return -1000*(y-(x+2))+1;
}

void main()
{
    double y0,x0,y1,n,h,f,k1,k2,k3,k4;
    printf("\nEnter the value of x0: ");
    scanf("%lf",&x0);
    printf("\nEnter the value of y0: ");
    scanf("%lf",&y0);
    printf("\nEnter the value of h: ");
    scanf("%lf",&h);
    printf("\nEnter the value of last point: ");
    scanf("%lf",&n);
    for(; x0<n; x0=x0+h)
    {
        f=func(x0,y0);
        k1 = h * f;
        f = func(x0+h/2,y0+k1/2);
        k2 = h * f;
        f = func(x0+h/2,y0+k2/2);
        k3 = h * f;
        f = func(x0+h/2,y0+k2/2);
        k4 = h * f;
        y1 = y0 + ( k1 + 2*k2 + 2*k3 + k4)/6;
        printf("\n\n  k1 = %lf  ",k1);
        printf("\n\n  k2 = %lf ",k2);
        printf("\n\n  k3 = %lf ",k3);
        printf("\n\n  k4 = %lf ",k4);
        printf("\n\n  y(%lf) = %lf ",x0+h,y1);
        y0=y1;
    }
}
