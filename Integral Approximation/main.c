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

float simpson38(float a, float b, int n )
{
    float h = (b - a)/n;
    float s = y(a) + y(b);

    int i;
    for (i = 1 ; i < n; i++)
    {
        if (i % 3 == 0)
            s += 2 * y(a + i*h);
        else
            s+= 3 * y(a + i*h);
    }
    return (3*h/8) * s;
}

int main()
{
    float x0 = 0;
    float xn = 1;

    printf ("*** Value of pi ***\n");

    printf("\n1. Using trapezoidal rule (n=6)=> %6.4f\t(err = %6.4f)\n", 4*trapezoidal(x0, xn, 6), 4*(atan(1)-trapezoidal(x0, xn, 6)));
    printf("1. Using trapezoidal rule (n=10)=> %6.4f\t(err = %6.4f)\n", 4*trapezoidal(x0, xn, 10), 4*(atan(1)-trapezoidal(x0, xn, 10)));
    printf("1. Using trapezoidal rule (n=20)=> %6.4f\t(err = %6.4f)\n", 4*trapezoidal(x0, xn, 20), 4*(atan(1)-trapezoidal(x0, xn, 20)));

    printf("\n2. Using simpson 1/3rd rule (n=6)=> %6.4f\t(err = %6.4f)\n", 4*simpson13(x0, xn, 6), fabs(4*(atan(1)-simpson13(x0, xn, 6))));
    printf("2. Using simpson 1/3rd rule (n=10)=> %6.4f\t(err = %6.4f)\n", 4*simpson13(x0, xn, 10), fabs(4*(atan(1)-simpson13(x0, xn, 10))));
    printf("2. Using simpson 1/3rd rule (n=20)=> %6.4f\t(err = %6.4f)\n", 4*simpson13(x0, xn, 20), fabs(4*(atan(1)-simpson13(x0, xn, 20))));

    printf("\n3. Using simpson 3/8th rule (n=6)=> %6.4f\t(err = %6.4f)\n", 4*simpson38(x0, xn, 6), 4*(atan(1)-simpson38(x0, xn, 6)));
    printf("3. Using simpson 3/8th rule (n=10)=> %6.4f\t(err = %6.4f)\n", 4*simpson38(x0, xn, 10), 4*(atan(1)-simpson38(x0, xn, 10)));
    printf("3. Using simpson 3/8th rule (n=20)=> %6.4f\t(err = %6.4f)\n", 4*simpson38(x0, xn, 20), 4*(atan(1)-simpson38(x0, xn, 20)));

    return 0;
}
