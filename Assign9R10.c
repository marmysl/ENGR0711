/* HW 9
 * R10: Elizabeth Mountz, Maria Mysliwiec, Sead Niksic
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	
	// Ask the user to enter a file and check if it exists
	FILE *user_file;
	char fname[200];
	double data1 [200],data2[200],sum1=0,sum2=0,mean1,mean2;
	double stdv_numerator1=0,variance1,stdv1, stdv_numerator2=0, variance2, stdv2;
	int f_end=1,count1=0,count2=0;
	
	do {
		printf("Enter a filename: ");
		scanf("%s",fname);
		user_file = fopen(fname,"r");
	} while (user_file == NULL);
		
	// Reads the data into a two dimensional array
	while (1) {
		f_end= fscanf(user_file,"%lf" "%lf",&data1[count1],&data2[count2]);
		if (f_end == EOF) {break;}
		
		sum1+=data1[count1];
		count1++;
		
		sum2+=data2[count2];
		count2++;
	}
	
	// Find the mean and standard deviation of both data sets
	mean1= sum1/count1;
	mean2=sum2/count2;
	printf("\nThe average of numbers in column 1 is %lf",mean1);
	printf("\nThe average of numbers in column 2 is %lf",mean2);
	
	for (int i = 0; i < count1; i++) {
			stdv_numerator1 = stdv_numerator1 + pow((data1[i] - mean1), 2);
		}
		
	variance1  = stdv_numerator1/(count1 - 1); // Calculate variance and take square root for standard deviation. 
	stdv1= sqrt(variance1);
	printf("\nThe standard deviation of the values in column 1 is: %lf",stdv1);
		
	for (int i = 0; i < count2; i++) {
			stdv_numerator2 = stdv_numerator2 + pow((data2[i] - mean2), 2);
		}
		
	variance2  = stdv_numerator2/(count2 - 1); // Calculate variance and take square root for standard deviation. 
	stdv2= sqrt(variance2);
	printf("\nThe standard deviation of the values in column 2 is: %lf",stdv2);
		
	// Display to file "results.dat"

	FILE *fp;
	fp = fopen("results.dat","w"); //created file 
	
	fprintf(fp,"The average of numbers in column 1 is %lf",mean1);
	fprintf(fp,"\nThe average of numbers in column 2 is %lf",mean2);
	fprintf(fp,"\nThe standard deviation of the values in column 1 is: %lf",stdv1);
	fprintf(fp,"\nThe standard deviation of the values in column 2 is: %lf",stdv2);
	
	fclose(fp);
	
	// Min and max of both
	
	double min1=data1[0], min2=data2[0];
	
    for (int i=1; i < count1; i++)
        if ( data1[i] < min1 ) {
             min1 = data1[i] ;
		 }
             
    for (int i=1; i < count2; i++)
        if ( data2[i] < min2 ) {
             min2 = data2[i] ;
		 }
	
	double max1=data1[0], max2=data2[0];
	
    for (int i=1; i < count1; i++)
        if ( data1[i] > max1 ) {
             max1 = data1[i] ;
		 }
             
    for (int i=1; i < count2; i++)
        if ( data2[i] > max2 ) {
             max2 = data2[i] ;
		 }
	
	// Display and append resulting min and max values to file
	printf("\n\nThe minimum value in column 1 is %lf",min1);
	printf("\nThe maximum value in column 1 is %lf",max1);
	printf("\nThe minimum value in column 2 is %lf",min2);
	printf("\nThe maximum value in column 2 is %lf",max2);
	
	fp = fopen("results.dat", "a");
	fprintf(fp,"\n\nThe minimum value in column 1 is %lf",min1);
	fprintf(fp,"\nThe maximum value in column 1 is %lf",max1);
	fprintf(fp,"\nThe minimum value in column 2 is %lf",min2);
	fprintf(fp,"\nThe maximum value in column 2 is %lf",max2);
	
	// Find year corresponding to min and max of both and display results to screen
	int minyear1, minyear2, maxyear1, maxyear2;
	
	for (int i=0; i < count1; i++)
		if (min1 == data1[i]) {
			minyear1=i+1949;		
		} 
	
	for (int i=0; i < count1; i++)	
		if (max1==data1[i]) {
			maxyear1=i+1949;
		}
	
	for (int i=0; i < count2; i++)
		if (min2 == data2[i]) {
			minyear2=i+1949;		
		} 
		
	for (int i=0; i < count2; i++)
		if (max2==data2[i]) {
			maxyear2=i+1949;
		}
	
	printf("\n\nThe year corresponding to the minimum value in column 1 is %d",minyear1);
	printf("\nThe year corresponding to the maximum value in column 1 is %d",maxyear1);
	printf("\nThe year corresponding to the minimum value in column 2 is %d",minyear2);
	printf("\nThe year corresponding to the maximum value in column 2 is %d",maxyear2);
	
	// Append resulting min and max values to file
	fp = fopen("results.dat", "a");
	fprintf(fp,"\n\nThe year corresponding to the minimum value in column 1 is %d",minyear1);
	fprintf(fp,"\nThe year corresponding to the maximum value in column 1 is %d",maxyear1);
	fprintf(fp,"\nThe year corresponding to the minimum value in column 2 is %d",minyear2);
	fprintf(fp,"\nThe year corresponding to the maximum value in column 2 is %d",maxyear2);
		
	// 1 dimensional array containing difference for each year
	double differences[200];
	
	for (int i=0; i < count1 && i < count2; i++) {
		differences[i]= data1[i] - data2[i];
	}
	
	// max and min differences between the two years
	double mindiff=differences[0], maxdiff=differences[0];
	
    for (int i=1; i < count1 && i < count2; i++)
        if ( differences[i] < mindiff ) {
             mindiff = differences[i] ;
		 }
             
    for (int i=1; i < count2 && i < count1; i++)
        if ( differences[i] > maxdiff ) {
             maxdiff = differences[i] ;
		 }
	
	// Display and append to  file
	printf("\n\nThe minimum difference between consumption values is %lf",mindiff);
	printf("\nThe maximum difference between consumption values is %lf",maxdiff);
	
	fp = fopen("results.dat", "a");
	fprintf(fp,"\n\nThe minimum difference between consumption values is %lf",mindiff);
	fprintf(fp,"\nThe maximum difference between consumption values is %lf",maxdiff);

	// Find year corresponding to min and max difference
	int mindiffyr, maxdiffyr;
	
	for (int i=0; i < count1 && i < count2; i++)
		if (mindiff == differences[i]) {
			mindiffyr=i+1949;		
		} 
	
	for (int i=0; i < count1 && i < count2; i++)	
		if (maxdiff==differences[i]) {
			maxdiffyr=i+1949;
		}
	
	// Display corresponding year and add to file
	printf("\n\nThe year corresponding to the minimum difference is %d",mindiffyr);
	printf("\nThe year corresponding to the maximum difference is %d",maxdiffyr);
	
	fp = fopen("results.dat", "a");
	fprintf(fp,"\n\nThe year corresponding to the minimum difference is %d",mindiffyr);
	fprintf(fp,"\nThe year corresponding to the maximum difference is %d",maxdiffyr);
	
	return 0;
	fclose(fp);
}

