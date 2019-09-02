/*
Title - Newton Raphson vs Secant
Author - Hemabh Ravee (IMH/10042/17)
Lab - Numerical Methods Lab - 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TOL 10e-4

double func1 (double x)
{
    return (pow(x,3) - 2*pow(x,2) - 5);
}

double derfunc1 (double x)
{
    return (3*pow(x,2) - 4*x);
}

double func2 (double x)
{
	return(pow(x,3) + 4.001*pow(x,2) + 4.002*x + 1.101);
}

double derfunc2 (double x)
{
	return(3*pow(x,2) + 8.002*x + 4.002);
}

double func3 (double x)
{
	return(pow(x,5) - pow(x,4) + 2*pow(x,3) - 3*pow(x,2) + x -4); 
}

double derfunc3 (double x)
{
	return(5*pow(x,4) - 4*pow(x,3) + 6*pow(x,2) + 1);
}
double newt(double a, double (*f)(double), double (*g)(double))
{
	double b;
	int i=0;
	do{
		i++;
	    b = a - f(a)/g(a);
	    if(func(b)==0)
	    {
	        printf("\nAfter %d iterations, Root = %lf",b);
	        return 0;
	    }
	    printf("\nAfter %d iterations, Value = %lf",i,b);
	    a=b;	    
	}while(func(b)>TOL);
}

int main()
{
    printf("Enter initial guess \n");
    double a;
    scanf("%lf",&a);
    newt(a, func2, derfunc2);
}