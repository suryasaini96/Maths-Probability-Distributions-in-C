/* Binomial Distribution */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int factorial(int num);
int combination(int n,int r);
double Biprobability(double event,int power);

void main()
{   
  int n,ch,x;
  char ch1='n';
  double *P,p,q,mean,mode,variance,skewness,kurtosis,Finfo;
  system("cls");
  system("COLOR FC");
  printf("Enter the number of trials N: ");
  scanf("%d",&n);
  P = (double *)malloc(n*sizeof(double)); /* Space for probabilities of random variables */
  printf("Probability of success p: ");
  scanf("%lf",&p);
  q=1-p;
  printf("Probability of failure q: %.2lf \n\n",q);
  printf("Menu: \n");
  printf("1) Probablility Mass Function for a variable \n2) Other Statistical Parameters \n   a) Mean \n   b) Mode \n   c) Variance \n   d) Skewness \n   e) Kurtosis \n   f) Fisher Information \n\n");
  do
  {
	  if(ch1=='y'||ch1=='Y')
	  {
		system("cls");
		system("COLOR FC");
		printf("Number of trials N: %d \n",n);
		printf("Probability of success p: %.2lf \n",p);
		printf("Probability of failure q: %.2lf \n\n",q);
		printf("Menu: \n");
		printf("1) Probablility Mass Function for a variable \n2) Other Statistical Parameters \n   a) Mean \n   b) Mode \n   c) Variance \n   d) Skewness \n   e) Kurtosis \n   f) Fisher Information \n\n");	
	  }
	  printf("Choice: ");
	  fflush(stdin);
	  scanf("%d",&ch);
	  switch(ch)
	  { 
			case 1: printf("Enter variable x: ");
					scanf("%d",&x);
					P[x] = combination(n,x)*Biprobability(p,x)*Biprobability(q,n-x);
					printf("P[%d] = %.2lf\n",x,P[x]);
					break;
			case 2: mean=n*p;
					mode=(n+1)*p;
					variance=n*p*q;
					skewness=(1-(2*p))/sqrt(n*p*q);
					kurtosis=(1-(6*p*q))/(n*p*q);
					Finfo=n/(p*q);
					printf("\na) Mean = %.2lf",mean);
					printf("\nb) Mode = %.2lf",mode);
					printf("\nc) Variance = %.2lf",variance);
					printf("\nd) Skewness = %.2lf",skewness);
					printf("\ne) Kurtosis = %.2lf",kurtosis);
					printf("\nf) Fisher Information = %.2lf\n",Finfo);
					break;
			default:printf("\nWrong choice!");
					break;
	  	}
		printf("\nWant to enter again? (y/n) :");
		fflush(stdin);
		scanf("%c",&ch1);	
	}while(ch1=='y'||ch1=='Y');
	free(P);
}

int factorial(int num)
{
	int i=1,fact=1;	
	while(i<=num)
	{
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

double Biprobability(double event,int power)
{
	double prob;
	prob=pow(event,power);
	return prob;
}


