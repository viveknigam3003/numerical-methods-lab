/*
Title - Regula Falsi
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

void regulafalsi(float a, float b)
{
    if (func(a)*func(b) >= 0)
    {
        printf("\nIncorrect choice of a and b\n");
        return;
    }

    float c=a;
    do
    {
        c = (b*func(a)-a*func(b))/(func(a)-func(b));
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
    }while (abs(func(c))<= TOL);
    printf("\nRoot = %f\n", c);
}

int main()
{
    float a, b;
    a=3.0; b=4.0;
    regulafalsi(a,b);
    return 0;
}