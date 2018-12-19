//heart.c
//Chris Hopp
//010809627
//Microsoft Visual Studio 2015
//Microsoft Windows 10

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define DAYS_PER_YEAR 365
#define BEATS_PER_MIN 60
#define MIN_PER_DAY 1440


FILE *fp;

int main(void) {
	int years,
		beats;

	fp = fopen("csis.txt", "w");

	years = 50;
	
	beats = years * DAYS_PER_YEAR * MIN_PER_DAY * BEATS_PER_MIN;

	printf("The number of heart beats in %d years is %d  \n",years, beats);
	fprintf(fp, "The number of heart beats in %d years is %d  \n",years, beats);

	

	getchar();
	fclose(fp);

	return 0;
}