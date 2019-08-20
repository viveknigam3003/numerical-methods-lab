/*
Title - Lagrange Polynomial
Author - Vivek Nigam (IMH/100006/17)
Lab - Numerical Methods Lab - 4
*/

#include<stdio.h>
int main()
{
    //a is the value of x to calculate.
    float a=10,s=1,t=1,k=0;
    int n,i,j,d=1;

    //enter table here
    float x[5]={5,7,11,13,17};
    float y[5]={150,392,1452,2366,5202};

    //calculating P(x)
    for(i=0; i<5; i++)
    {
        s=1;
        t=1;
        for(j=0; j<5; j++)
        {
            if(j!=i)
            {
                s=s*(a-x[j]);
                t=t*(x[i]-x[j]);
            }
        }
        k=k+((s/t)*y[i]);
    }
    printf("\nWhen x=%f, y= %f\n",a,k);
    return 0;
}
