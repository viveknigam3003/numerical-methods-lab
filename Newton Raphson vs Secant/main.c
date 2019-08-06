/*
Title - Newton Raphson Vs Secant Method
Author - Vivek Nigam (IMH/100006/17)
Lab - Numerical Methods Lab - 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TOL 10e-4

double func (double x)
{
    return (x*x*x - 2*x*x - 5);
}

double derfunc (double x)
{
    return (3*x*x - 4*x);
}

double newtonraphson (double x1)
{
    double x;
    int itr=1;
    printf("\nInitial Guess: %lf\n", x1);

    printf("\n x \t\t x1 \t\t f'(x) \t\t |x-x1|\n");

    do
    {
        printf("\n %lf \t %lf \t %lf \t %lf\n", x, x1, derfunc(x) ,(x-x1));
        x=x1;
        if (fabs(derfunc(x))>=10e-8 && derfunc(x) != NAN)
        {
            x1 = x - func(x)/derfunc(x);
            itr++;
        }
        else
        {
            printf("Method Fails");
            return 0;
        }
    }while (fabs(x-x1) >= TOL);
    printf("Number of Iterations = %d", itr);
    return x1;
}

double secant (double x1)
{
    return;
}

int main()
{
    printf("\nRoot using NR = %f\n", newtonraphson(100));
    return 0;
}
