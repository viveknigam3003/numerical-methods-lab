#include<stdio.h>

float newton(float x[],float y[], float a, int n)
{
	float D[n][n];
	int i,j,k;
	
	//defining first column of D to be y or f(x)
	for(i=0;i<n;i++)
		D[i][0] = y[i];
		
	//defining the rest of the array D
	//note that we start with both i & j = 1
	for(i=1;i<n;i++)
	{
		for(j=1;j<=i;j++)
		{
			D[i][j] =( D[i][j-1]- D[i-1][j-1] )/( x[i] - x[i-j] );
		}
	}
	
	//Now the diagonal of D holds the values of the coefficient 
	for(i=0;i<n;i++)
		printf("\n%dth coefficient is : %f",i,D[i][i]);
		
	float sum, prod;
	
	//Creating newton's polynomials
	for(i=0;i<n;i++)
	{
		sum=D[0][0];		
		for(j=1;j<i;j++)
		{
			prod = 1;
			for(k=0;k<j;k++)
			{
				prod*=(a-x[k]);
			}
			sum+=D[j][j]*prod;
			
		}
		
		printf("\nValue of f(%f) from polynomial %d is : %f",a,i,sum);
	}
}

int main()
{
	//defining array size
    int n = 7;
    
    float x[n]={1.7, 1.8, 1.9, 2.0, 2.1, 2.2, 2.3};
    float y[n]={5.474, 6.050, 6.686, 7.8166, 9.025, 9.974};
    
    float x1 = 1.85;
    float x2 = 2.25;
    newton(x,y,x1,n);
    newton(x,y,x2,n);   
}
