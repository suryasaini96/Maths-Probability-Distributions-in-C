/* C program to input real numbers and find the mean, variance and standard deviation */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double RealMean(double sum,int n);
double RealVariance(double sumForVariance,int n);
double RealStdDeviation(double variance);

void main()
{
    int i,n;
	double *N,mean,variance,stdDeviation,sumForMean=0,sumForVariance = 0;
    printf("Enter the number of trails N: "); //N data points
    scanf("%d", &n);
    N=(double *)malloc(n*sizeof(double)); 
    printf("Enter the data points:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &N[i]);
        sumForMean+= N[i]; //Sum of entered elements for calculating mean later
    }
   	mean = RealMean(sumForMean,n);
    for (i = 0; i < n; i++) /* Separate loop for computing variance  and standard deviation  */
    {
        sumForVariance+= pow((N[i] - mean), 2);
    }
    variance = RealVariance(sumForVariance,n);
    stdDeviation = RealStdDeviation(variance);
    
    printf("\nAverage of data points = %.2lf\n", mean);
    printf("Variance = %.2lf\n", variance);
    printf("Standard Deviation = %.2lf\n", stdDeviation);
    free(N);
}

double RealMean(double sumForMean,int n)
{
	double mean;
	mean=sumForMean/n;
	return mean;
}

double RealVariance(double sumForVariance,int n)
{
	double variance;
	variance=sumForVariance/n;
	return variance;
}

double RealStdDeviation(double variance)
{
	double stdDeviation;
	stdDeviation=sqrt(variance);
	return stdDeviation;
}
