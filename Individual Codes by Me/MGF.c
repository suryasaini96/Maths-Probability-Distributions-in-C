/* Moment generating function program */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dataMean(double SumXF,double SumF);
double dataVariance(double Moment2);
double dataSkewness(double Moment3,double Moment2);
double dataKurtosis(double Moment4,double Moment2);
void checkSkewness(double skewness);
void checkKurtosis(double kurtosis);

void main()
{
	system("cls");
    system("COLOR FC");
	int elements,i,j,r,choice; /* elements are the columns whereas rows = 2 ( for X and F ) */
	double *data[2],mean,variance,skewness,kurtosis,SumF=0,SumXF=0,centralM[4]={0},rawM[4]={0},point;
	printf("Enter number of elements:");
	scanf("%d",&elements);
	printf("\nEnter the random variables and their probabilites: \n");
	for(i=0;i<2;i++) /* Getting variables and their probabilities here */
	{
		data[i]=(double *)malloc(elements*sizeof(double));
		for(j=0;j<elements;j++)
		{
			if(i==0)
			{
				printf("X[%d] = ",j+1);
				scanf("%lf",&data[i][j]);
			}
			if(i==1)
			{
				printf("F[%d] = ",j+1);
				scanf("%lf",&data[i][j]);
				SumF+=data[i][j];
			}
		}
		printf("\n");
	}
	/* Loop for calculating sum used in mean formula */
	for(j=0;j<elements;j++)
	{
		SumXF+= data[0][j]*data[1][j]; /* equivalent to X[i]*F[i] */
	}
	printf("Menu : \n\n1) First 4 Central Moments with other parameters \n2) First 4 Raw Moments about a point \n\nChoice: ");
	scanf("%d",&choice);
	mean = dataMean(SumXF,SumF);
	switch(choice)
	{
		case 1: /* Finding central moment */
				for(r=0;r<4;r++)
				{
					for(j=0;j<elements;j++)
					{
						centralM[r]+= (pow((data[0][j]-mean),r+1)*data[1][j])/SumF;
					}
				}
				break;
		case 2: /* Finding raw moment */
				printf("About point:");
				scanf("%lf",&point);
				for(r=0;r<4;r++)
				{
					for(j=0;j<elements;j++)
					{
						rawM[r]+= (pow((data[0][j]-point),r+1)*data[1][j])/SumF;
					}
				}
				break;
		default: printf("Wrong Choice!");
				 break;
	}
	if(choice==1)
	{
		printf("\nThe central moments are: \n");
		for(r=0;r<4;r++)
		{
			printf("C[%d] = %.4lf \n",r+1,centralM[r]);
		}
		
		printf("\nMean = %lf \n",mean);
		
		variance = dataVariance(centralM[1]);
		printf("Variance = %.4lf \n",variance);
		
		skewness = dataSkewness(centralM[2],centralM[1]);
		printf("Skewness = %.4lf ",skewness);
		checkSkewness(skewness);
		
		kurtosis = dataKurtosis(centralM[3],centralM[1]);
		printf("Kurtosis = %.4lf ",kurtosis);
		checkKurtosis(kurtosis);
	}
	else if(choice==2)
	{
		printf("\nThe raw moments are: \n");
		for(r=0;r<4;r++)
		{
			printf("R[%d] = %.4lf \n",r+1,rawM[r]);
		}
		printf("\nMean = %lf \n",mean);
	}
		
}

double dataMean(double SumXF,double SumF)
{
	double mean;
	mean=SumXF/SumF;
	return mean;
}

double dataVariance(double Moment2)
{
	double variance;
	variance=Moment2;
	return variance;
}

double dataSkewness(double Moment3,double Moment2)
{
	double skewness;
	skewness = pow(Moment3,2)/pow(Moment2,3);
	return skewness;
}

double dataKurtosis(double Moment4,double Moment2)
{
	double kurtosis;
	kurtosis=Moment4/pow(Moment2,2);
	return kurtosis;
}

void checkSkewness(double skewness)
{
	if(skewness>0)
	{
		printf("The curve is positively skewed\n");
	}
	else if(skewness<0)
	{
		printf("The curve is negatively skewed\n");
	}
	else if(skewness==0)
	{
		printf("The curve is symmetric\n");
	}
}

void checkKurtosis(double kurtosis)
{
	if(kurtosis>3)
	{
		printf("The curve is leptokurtic\n");
	}
	else if(kurtosis<3)
	{
		printf("The curve is platykurtic\n");
	}
	else if(kurtosis==3)
	{
		printf("The curve is normal\n");
	}
}
