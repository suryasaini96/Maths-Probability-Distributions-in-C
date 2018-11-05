/* Program for poisson's distribution*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double PsnMean(int n,double p);
double PsnVariance(double mean);
double PsnSkewness(double mean);
double PsnKurtosis(double mean);
double PsnMoment3(double mean);
double PsnMoment4(double mean);
int factorial(int num);
double PsnProbability(double mean,int x);

void main()
{
	int n,x;
	float p;
	double *P,mean,variance,moment3,moment4,skewness,kurtosis;
	printf("Enter the number of trials N: ");
	scanf("%d",&n);
	P = (double *)malloc(n*sizeof(double)); /* Space for probabilities of random variables */
	printf("Enter the probability of success:");
	scanf("%f",&p);
	mean = PsnMean(n,p);
	variance = PsnVariance(mean);
	moment3 = PsnMoment3(mean);
	moment4 = PsnMoment4(mean);
	skewness = PsnSkewness(mean);
	kurtosis = PsnKurtosis(mean);
	printf("Enter the random variable:");
	scanf("%d",&x);
	P[x]=PsnProbability(mean,x);
	printf("\nP[%d] = %f",x,P[x]);
	printf("\nMean = %.4lf \nVarience = %.4lf \nU3 = %.4lf \nU4 = %.4lf \nSkewness = %.4lf \nKurtosis = %.4lf \n",mean,variance,moment3,moment4,skewness,kurtosis);
	free(P);
}

int factorial (int num)
{
	int i=1,fact=1;
	while(i<=num)
	{
	fact=fact*i;
	i++;
	}
	return fact;
}

double PsnProbability(double mean,int x)
{
	double calP;
	calP=(exp(-mean)*pow(mean,x))/factorial(x);
	return calP;
}

double PsnMean(int n,double p)
{
	double mean;
	mean=n*p;
	return mean;
}

double PsnMoment3(double mean)
{
	return mean;
}

double PsnMoment4(double mean)
{
	double moment4;
	moment4=mean+(3*mean*mean);
	return moment4;
}

double PsnVariance(double mean)
{
	return mean;
}

double PsnSkewness(double mean)
{
	double skewness;
	skewness=(1/mean);
	return skewness;
}

double PsnKurtosis(double mean)
{
	double kurtosis;
	kurtosis=3+(1/mean);
	return kurtosis;
}


