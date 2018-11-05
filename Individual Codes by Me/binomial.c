/* Binomial Distribution in C */

#include<stdio.h>
#include<math.h>

int factorial (int num)
{
	int i=1;	
	while(i<=num)
	{	
	fact=1;
	fact=fact*i;
	i++;
	}
	return fact;	
}

int combination(int n,int r)
{
	int comb;
	comb=(factorial(n))/(factorial(r)*factorial(n-r));
	return comb;
}

float probability(int event,int power)
{
	float prob;
	prob=pow(event,power);
	return prob;
}

void main()
{
	float p,q;
	printf("Enter the probability of occurence:");
	scanf("%f",&p);
	q=1-p;
	
	




 
