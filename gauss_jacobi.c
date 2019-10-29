#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define TOL 10e-3

float f1(float a,float b,float c){
    return ((-a + b - c -2)/4);
}

float f2(float a,float b,float c){
    return ((-a + b + c -1)/4);
}

float f3(float a,float b,float c){
    return ((a + b - c)/5);
}

float f4(float a,float b,float c){
    return ((-a + b - c + 1)/3);
}

float main()
{
	float x[4] = {2,2,2,2};
	float y[4];
    int iter = 16,i = 0;

    do{
        y[0] = f1(x[1],x[2],x[3]);
        y[1] = f2(x[0],x[2],x[3]);
        y[2] = f3(x[0],x[1],x[3]);
        y[3] = f4(x[0],x[1],x[2]);
        i++;
        int j;
        x[0] = y[0];
        x[1] = y[1];
        x[2] = y[2];
        x[3] = y[3];

        printf("\nValues after %d th iteration : %f %f %f %f",i,y[0],y[1],y[2],y[3]);
    }while(i<iter);

    printf("\nNumber of iterations : %i",i);
 }
