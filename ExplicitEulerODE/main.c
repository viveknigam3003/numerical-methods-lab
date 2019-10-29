#include<stdio.h>
#include <math.h>

double func(double x, double y)
{
    return -1000*(y-(x+2))+1;
}

double main()
{
  double y1,y2,x1,a,n,h;
  int j;

  printf("\nEnter the value of range: ");
  scanf("%lf %lf",&a,&n);
  printf("\nEnter the value of y1: ");
  scanf("%lf",&y1);
  printf("\n\nEnter the h: ");
  scanf("%lf",&h);
  //printf("\n\n  y1 = %lf ",y1);
  for(x1=a,j=1; x1<=n+h; x1=x1+h,j++)
  {
   y2 = y1 + h * func(x1,y1);
   //yi=yi-1+hf(xi,yi)
   //printf("%lf",y1);
   printf("\n\n  x = %lf => y%d = %lf , y%d = %lf ",x1,j,y1,j+1,y2);
   y1=y2;
  }

}
