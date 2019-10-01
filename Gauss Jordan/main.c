#include<stdio.h>
#include<math.h>

#define N 4

void backSub (double mat[N][N+1])
{
    int i;
    float x[N];
    for(i=1;i<=N;i++)
	{
        x[i] = mat[i][N+1]/mat[i][i];
	}

	/* Displaying Solution */
	printf("\nSolution:\n");
	for(i=1;i<=N;i++)
	{
	 	printf("x[%d] = %0.3f\n",i, x[i]);
	}
	return(0);
}

int gaussJordan(double mat[N][N+1])
{
		 float ratio;
		 int i,j,k,n;

 for(i=1;i<=N;i++)
 {
    if(mat[i][i] == 0.0)
    {
        printf("Mathematical Error!");
        exit(0);
    }

 for(j=1;j<=N;j++)
 {
	if(i!=j)
	{
        ratio = mat[j][i]/mat[i][i];
        for(k=1;k<=n+1;k++)
        {
            mat[j][k] = mat[j][k] - ratio*mat[i][k];
        }
    }
  }

  backSub(mat);
}
}

int main ()
{
    double mat[N][N+1] = {{1.19, 2.11,-100.0, 1.0, 1.12},
                          {14.2, -0.122, 12.2, -1, 3.44},
                          {0.0, 100, 99.9, 1, 2.15},
                          {15.3,0.11,-13.1,-1,4.16}
                         };

    gaussJordan(mat);

    return 0;
}

