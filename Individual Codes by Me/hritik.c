#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	double  a,b,m1r;
	float m2r,m3r,m4r,m4r1,m4r2,m3,m4;
	long int n;
	int ch;
	float m2,sd,be1,be2,msk,mkur,med;   /* m1r,m2r,.. & m1,m2,.. are raw & central
					     moments resp. of order 1,2,& upto 4 */
					 /* msk & mkur are measure of skewness(gamma1)
					    & kurtosis(gamma2) resp. */
	
	printf("Enter number of trials N: ");
	scanf("%d",&n);
	printf("Probability of success p: ");
	scanf("%lf",&p);
	q=1-p;
	printf("Probability of failure q: %.2lf",q);
	label:
	printf("MENU OPTIONS FOR SHOWING BEHAVIOR OF DISTRIBUTION ARE: \n");
	printf("1.MEAN OF DISCRETE PROB. DIST.\n 2.VARIANCE OF DISCRETE DIST.\n");
	printf("3.Measure of SKEWNESS \n 4.Measure of KURTOSIS");
	printf("\n Enter your choice:\n");
	scanf("%d",&ch);
	switch(ch)
	 {
	  case 1:printf("Mean of discrete distribution for a performed experiment is:\n");
		  m1r=(n*a)*(pow((a+b),(n-1))); /*1st order raw moment after diff^n of 'b' w.r.t 't'at t=0 */
		  printf("%lf\n",m1r);
	   break;
	  case 2:printf("\nThe Variance of discrete distribution is:\n");
	         m2r=(n*a*b)+(pow(n,2))*(pow(a,2));
	         
	         /*2nd order raw after 2nd order diff^n of 'b' w.r.t at t=0 */
		  m2=m2r-(pow(m1r,2));
		 printf("%f\n",m2);
		 printf("\n The Standard deviation of discrete distribution:\n");
		 sd=sqrt(m2);
		 printf("%f",sd);
	    break;
	   case 3:printf("Measure of skewness describing symmetricity of curve:\n");
		  m3r=( (n*a*b) * (b-a) ) + ( (3)*(pow(n,2))*(pow(a,2))*(b) ) + ( (pow(n,3))*(pow(a,3)) ); /*3rd order raw moment after 3rd order diff^n of 'b' w.r.t at t=0 */
		  m3=m3r- (3*m2r*m1r) + (2*(pow(m1r,3)));
		  be1=(pow(m3,2))/(pow(m2,3));
		  printf("%f\n",be1);
		  msk=sqrt(be1);
		  printf("%f\n",msk);
		  if(msk==0)
		  {
		   printf("\nTHE CURVE IS SYMMETRICALLY DISTRIBUTED(No Skewness)");
		   med=m1r;
		   printf("%f\n",med);  /*When no skewness,mean=median=mode */
		  }
		  else if(msk>0)
		  {
		    printf("\nThe curve is positively skewed");
		  }
		  else if(msk<0)
		  {
		   printf("\nThe curve is negatively skewed");
		  }
	      break;
	     case 4:printf("\nThe Measure of kurtosis describing peakedness of curve is:");
		    m4r1=(n*a*b) + ( (n)*(pow(a,2))*(pow(b,2)) ) * ((7*n)-6);
	
		    m4r2=(2*(pow(n,2))*(pow(a,3))*b) * ((3*n)-2) + (pow(n,4))*(pow(a,4));
		    m4r=m4r1+m4r2;
		    /*4th order raw moment */
		   m4=m4r - (4*m3r*m1r) +( (6*m2r)*(pow(m1r,2)) ) - ( 3*(pow(m1r,4)) );
		   be2=(m4)/(pow(m2,2));
		   printf("%f\n",be2);
		   mkur=be2-3;
		   printf("%f\n",mkur);
		   if(mkur==0)
		   {
		    printf("\nThe curve is normal(i.e peak is 3 units approx.) ");
		   }
		   else if(mkur<0)
		   {
		    printf("\n The curve is platykurtic curve(i.e peak is less than 3 units)");
		   }
		   else if(mkur>0)
		   {
		    printf("\nThe curve is lyptokurtic curve(i.e peak is greater than 3 units)");
		   }
	     break;
	  default: printf("WRONG CHOICE");
		       exit(0);
	     break;
	       }goto label;
	  getch();
  }
