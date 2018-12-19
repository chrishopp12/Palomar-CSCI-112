//speed.c
//Chris Hopp
//010809627
//Microsoft Visual Studio 2015
//Microsoft Windows 10


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MET_PER_MILE 1600
#define SEC_PER_HOUR 3600

FILE *fp;

int main(void) {
	double miles,hours,
		mph, mps;

	fp = fopen("csis.txt", "w");

	miles = 425.5;
	hours = 7.5;
	mph = miles/ hours;
	mps = (miles * MET_PER_MILE) / (hours * SEC_PER_HOUR);

	printf("%f mph \n", mph);
	fprintf(fp, "%f mph \n", mph);

	printf("%f mps \n", mps);
	fprintf(fp, "%f mps \n", mps);

	getchar();
	fclose(fp);

	return 0;
}