/*
Title - Bisection Method
Author - Vivek Nigam (IMH/100006/17)
Lab - Numerical Methods Lab - 1
*/
#include <stdio.h>
#include <stdlib.h>
#define TOL 10e-8

float func (float x)
{
    return (x*x - 10);
}

void bisection(float a, float b)
{
    if (func(a)*func(b) >= 0)
    {
        printf("\nIncorrect choice of a and b\n");
        return;
    }

    float c=a;
    do
    {
        c = (a+b)/2;
        if (func(c)== 0.0)
        {
            break;
        }
        else if (func(a)*func(c)<0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }while ((b-a)/a >= TOL);
    printf("\nRoot = %f\n", c);
}

int main()
{
    float a, b;
    printf("Enter the value of a and b: ");
    scanf("\n%f \n%f", &a, &b);
    bisection(a,b);
    return 0;
}
