#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
int main()
{ 
  int n,ch,x,N[100],sum=0,B[100],sum1=0,v,i;
  double n2;
  double A[10][5] = {{1.00,6.34,12.71,31.82,63.66},
  	{0.816,2.92,4.3,6.96,9.92},
  	{0.765,2.35,3.18,4.54,5.84},
  	{0.741,2.13,2.78,3.75,4.60},
  	{0.727,2.02,2.57,3.36,4.03},
	{0.718,1.94,2.45,3.14,3.71},
	{0.711,1.90,2.36,3.00,3.50},
	{0.706,1.86,2.31,2.90,3.36},
	{0.703,1.83,2.26,2.82,3.25},
	{0.700,1.81,2.23,2.76,3.17}};
  char ch1='n';
  double *P,p,q,mean,mode,variance,skewness,kurtosis,Finfo,z,e,e1,d,stdDeviation,mean1,t,tv,tv1;
  system("cls");
  system("COLOR FC");
  printf("Enter the number of trials N: ");
  scanf("%d",&n);
  P = (double *)malloc(n*sizeof(double)); /* Space for probabilities of random variables */
  printf("Probability of success p: ");
  scanf("%lf",&p);
  q=1-p;
  printf("Probability of failure q: %.5lf \n\n",q);
  printf("Menu: \n");
  printf("1) Test of Significance for large Samples\n2) Test of Significance for Means of two large Samples\n3) Test of Significance of a Sample Mean\n");
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
		printf("1) Test of Significance for large Samples(z)\n");
		printf("2) Test of Significance for Means of two large Samples\n");
		printf("3) Test of Significance of a Sample Mean\n");
	  }
	  printf("\nChoice: ");
	  fflush(stdin);
	  scanf("%d",&ch);
	  switch(ch)
	  {
			case 1:printf("Enter variable x: ");
				   scanf("%d",&x);
				   z=(x-(n*p))/sqrt(n*p*q); //standard normal variate
				   printf("\nStandard normal variate = %.5lf",z);
				   if(z<1.96)
				   printf("\n\nThe difference between the observes and expected number of successes is\n not significant.");
				   if(z>1.96&&z<2.58)
				   printf("\n\nThe difference is significant at 5%% level of significance.");
				   if(z>2.58)
				   printf("\n\nThe difference is significant at 1%% level of significance.");
				   break;
			case 2:printf("Enter the number of trials for second sample N2: ");
				   scanf("%lf",&n2);
				   e=(sqrt((n+n2)*p*q))*(sqrt((1/n)+(1/n2)));
				   z=(n*p)-(n2*p)/e;
				   printf("\nStandard normal variate = %.5lf\n",z);
				   if(z>1.96&&z<3)
				   printf("\n\nThe difference is significant at 5%% level of significance.");
				   if(z>3)
				   printf("\n\nIt is Highly probable that either the samples have not been drawn from the\n same population or the sampling is not simple.");
				   d=(n*p)-(n2*p);
				   e1=sqrt(((n*p*q)/n)+((n2*p*q)/n2));	
				   if(d>(10*e1))
				   printf("\n\nIt is Highly significant.");
				   break;
			case 3:printf("Enter the sample elements: \n");
				   for(i=0;i<n;i++)
				   {
				   	scanf("%d",&N[i]);
				   	sum=sum+N[i];
				   }
				   mean=sum/n;
				   printf("\nMean: %.5lf\n",mean);
				   for(i=0;i<n;i++)
				   {
				   	 B[i]=N[i]-mean;
				   	 sum1+=i*i;
				   }
				   stdDeviation=sum1/(n-1);
				   printf("\nEnter the assumed mean of the normal population: ");
				   scanf("%.5lf",&mean1);
				   t=((mean-mean1)*sqrt(n))/(sqrt(stdDeviation));
				   printf("\nThe statistic t is: %.5lf",t);
				   v=n-1;
				   tv=A[v][2];
				   tv1=A[v][4];
				   if(t>tv)
				   printf("\n\nThe difference between mean and mean1 is said to be significant at 5% level of significance.");
				   if(t>tv1)
				   printf("\n\nThe difference is significant at 1% level of significance.");
				   if(t<tv)
				   printf("\n\nThe data is said to be consistent with the hypothesis that mean1\n is the mean of the population.");
				   break;
			default:printf("\nWrong choice!");;
				   break;
	  }printf("\nWant to enter again? (y/n) :");
		fflush(stdin);
		scanf("%c",&ch1);	
	}while(ch1=='y'||ch1=='Y');
	free(P);
getch();
}
