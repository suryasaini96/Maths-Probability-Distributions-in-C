/* Program for finding median and mode of N integers */

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i,j;
	int n,max=0,k=0,c=1;
	double *N,*ascN,temp,median,mode,Mode[20];
	printf("Enter the number of trails N: "); /* N Data Points */
    scanf("%d", &n);
    N=(double *)malloc(n*sizeof(double));  /* Space for N data points */
    printf("Enter the data points:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &N[i]);
    }
	ascN=(double *)malloc(n*sizeof(double)); 
	for(i=0;i<n;i++) /*Assigning the Ascending order array of data poins same as the array of entered data points first */
	{
		ascN[i]=N[i];
	}
	for(i=0;i<n;i++) /* Arranging data points in Ascending order for median */
	{
		for(j=i+1;j<n;j++)
		{
			if(ascN[i]>ascN[j])
			{
			temp=ascN[i];
			ascN[i]=ascN[j];
			ascN[j]=temp;
			}
		}
	}
	/* Median */
	if(n%2==0) /*Using formula for median if even number of terms are there*/
		median=(double)(ascN[n/2]+ascN[(n-1)/2])/2;
	else /* formula for odd number of terms */
		median=(double)ascN[(n-1)/2];
	printf("Median = %.0lf",median);
	
	/* Mode */
	for(i=0;i<n-1;i++)
	{
		mode=0;
		for(j=i+1;j<n;j++)
		{
			if(ascN[i]==ascN[j])
			{
			mode++;
    		}
		}
		if((mode>max)&&(mode!=0))
		{
			k=0;
			max=mode;
			Mode[k]=ascN[i];
			k++;
		}
		else if(mode==max)
		{
			Mode[k]=ascN[i];
			k++;
		}
	}
	for(i=0;i<n;i++)
	{
		if(ascN[i]==Mode[i])
		c++;
	}
	if(c==n)
		printf("\nThere is no mode");
	else
	{
		printf("\nMode = ");
		for(i=0;i<k;i++)
		printf("%.0lf",Mode[i]);
	}
 }
