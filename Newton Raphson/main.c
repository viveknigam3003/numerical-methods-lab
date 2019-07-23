/*
Title - Newton Raphson Method
Author - Vivek Nigam (IMH/100006/17)
Lab - Numerical Methods Lab - 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func (double x)
{
    return (x*x - 10);
}

double derfunc (double x)
{
    return (2*x);
}

int main()
{
    double x,x1,eps;
    x=3.0;
    int itr=1;
    
    do
    {
        x=x1;
        if (fabs(derfunc(x))>=10e-8 && derfunc(x) != NAN)
        {
            printf("Inside if\n");
            x1 = x - func(x)/derfunc(x);
            itr++;
        }
        else
        {
            printf("Method Fails");
            return 0;
        }
    }while (fabs(x-x1) >= eps);
    
    printf("\nRoot = %f\n", x1);
    printf("Number of Iterations = %d", itr);
}