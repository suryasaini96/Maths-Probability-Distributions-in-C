/* Program for poisson's distribution*/

#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>

double *P,mean;

int factorial(int num);
double probability(int x);

void main()
{
	int i,n,x;
	float p;
	double U2,U3,U4,B1,B2;
	printf("Enter the trials:");
	scanf("%d",&n);
	P = (double *)malloc(n*sizeof(double)); //declaring space for probabilities of random variables
	printf("Enter the probability of success:");
	scanf("%f",&p);
	mean=n*p; //Calculated mean
	U2=mean;
	U3=mean;
	U4=mean+(3*mean*mean);
	B1=(1/mean);
	B2=3+(1/mean);
	printf("Enter the random variable:");
	scanf("%d",&x);
	P[x]=probability(x);
	printf("\nP(%d)=%f",x,P[x]);
	printf("\nMean = %lf \nVarience = %lf \nU3 = %lf \nU4 = %lf \nB1 = %lf \nB2 = %lf",mean,U2,U3,U4,B1,B2);
	free(P);
	getch();
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

double probability(int x)
{
	double calP;
	calP=(exp(-mean)*pow(mean,x))/factorial(x);
	return calP;
}


