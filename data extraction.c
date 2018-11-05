/* Taking data from a file in the form of two strings and converting them to floating point values.
Data could be an integer,decimal or fractional value */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum numberType{
	integer,decimal,fraction
}type;

double checkAndReturn (char *string);
static int funcCallCounter=0;

void main()
{
	FILE *file=fopen("data.txt","r");
	int Xindex=-1,Findex=-1,i,length;
	double firstNo[20],secondNo[20];
	static char stringOne[100]={0},stringTwo[100]={0},c;
	while(!feof(file)) /*A loop for moving the file pointer and omitting the first line of the data file since it has stray text */ 
	{
		c=fgetc(file);
		if(c=='\n')
			break;
	}
	while(!feof(file))
	{
		
		if(funcCallCounter%2==0) /* If checkAndReturn function is called even number of times then 1 line is read and index is increased */
		{
			Xindex++;
			Findex++;
		}	
		fscanf(file,"%s\t%s",stringOne,stringTwo);
		firstNo[Xindex]=checkAndReturn(stringOne);
		secondNo[Findex]=checkAndReturn(stringTwo);
	}
	fclose(file);
	length=Xindex; /* Xindex = Findex after loop */
	for(i=0;i<length;i++)
	{
		printf("%.4lf\t%.4lf\n",firstNo[i],secondNo[i]);
	}
}

double checkAndReturn(char *string) /* A function which checks the type of value in file and converts it into decimals */
{
	int i=0,num,denom;
	double number;
	char stringNum[20],stringDenom[20];
	while(string[i]!='\0')
	{
		if(string[i]=='.')
		{
			type=decimal;
			break;
		}
		if(string[i]=='/')
		{
			type=fraction;
			break;
		}
		type=integer;
		i++;
	}
	if(type==integer)
	{
		number=atoi(string);
	}
	else if(type==decimal)
	{
		number=atof(string);
	}
	else if (type==fraction)
	{
		int num,denom,k=0;
		while(string[k]!='\0')
		{
			if(string[k]=='/')
			{
				int start1=0, currPos=k, j=k+1, start2=0;
				while(string[start1]!=string[currPos])
				{
					stringNum[start1]=string[start1];
					stringNum[start1+1]='\0';
					start1++;
				}
				while(string[j]!='\0')
				{
					stringDenom[start2]=string[j];
					stringDenom[start2+1]='\0';
					start2++;
					j++;
				}
			}
			k++;
		}
		num=atoi(stringNum);
		denom=atoi(stringDenom);
		number=(double)num/denom;
	}
	funcCallCounter++;
	return number;
}




