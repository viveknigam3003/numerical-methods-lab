#include <stdio.h>
#include <stdlib.h>

float y(float x)
{
    return 1/(1+x*x);
}

float trapezoidal(float a, float b, float n)
{
    int i;
    float h = (b-a)/n;
    float s = y(a)+y(b);

    for(i = 1; i < n; i++)
        s += 2*y(a+i*h);

    return (h/2)*s;
}

int main()
{
    float x0 = 0;
    float xn = 1;

    int n = 6;
    printf ("*** Value of pi ***\n");
    float trap = trapezoidal(x0, xn, 6);
    printf("\n1. Using trapezoidal rule (n=6)=> %6.4f\n", 4*trapezoidal(x0, xn, 6));
    printf("1. Using trapezoidal rule (n=10)=> %6.4f\n", 4*trapezoidal(x0, xn, 10));
    printf("1. Using trapezoidal rule (n=20)=> %6.4f\n", 4*trapezoidal(x0, xn, 20));


    return 0;
}
