#include<stdio.h>
#include <math.h>

void main()
{
  double y1,y2,x1,a,n,h,l;
  int j;
  //printf("\nEnter the value of range: ");
  //scanf("%lf %lf",&a,&n);
  a = 0; n = 0.01;
  //printf("\nEnter the value of y1: ");
  //scanf("%lf",&y1);
  y1 = 1;
  //printf("\n\nEnter the h: ");
  //scanf("%lf",&h);
  h = 0.01;
  //printf("\n\n  y1 = %.3lf ",y1);
  for(x1=a,j=2; x1<=n+h; x1+=h,j++)
  {
      //this function may not make sense
      // y {i} = y {i-1} + h*Func(x{1},y{i})
      //expand the above formula to find value of y{i}
      //Use that value below :
   y2= (y1 + (h * (1000*x1 + 2001)))/(1 + 1000*h);
   printf("\n\n  x = %lf => y%d = %lf \t %lf \t %lf",x1,j,y2,y1,l);
   y1=y2;
  }
}
