#include<stdio.h>
#include<math.h>
#define ESP 0.0001
#define X1(x2,x3,x4) ((-2 - x2 + x3 - x4)/4)
#define X2(x1,x3,x4) ((-1 - x1 + x3 + x4)/4)
#define X3(x1,x2,x4) ((x1 + x2 - x4)/5)
#define X4(x1,x2,x3) ((1 - x1 + x2 - x3)/3)


void main()
{
  double x1=0,x2=0,x3=0,x4=0,y1,y2,y3,y4,m,n,p,o;
  int i=0;

  printf("\n   x1\t\t   x2\t\t    x3\t\t   x4\n");
  printf("\n%f\t%f\t%f\t%f",x1,x2,x3,x4);
  do
  {
   m=x1;
   x1=X1(x2,x3,x4);
   n=x2;
   x2=X2(x1,x3,x4);
   o=x3;
   x3=X3(x1,x2,x4);
   p=x4;
   x4=X4(x1,x2,x3);
   printf("\n%f\t%f\t%f\t%f",x1,x2,x3,x4);
   if(fabs(m-x1)<ESP && fabs(n-x2)<ESP && fabs(o-x3)<ESP && fabs(p-x4)<ESP )
   {
     printf("\n\nx1 = %.3lf",x1);
     printf("\n\nx2 = %.3lf",x2);
     printf("\n\nx3 = %.3lf",x3);
     printf("\n\nx4 = %.3lf",x4);
     i = 1;
   }

  }while(i != 1);
}
