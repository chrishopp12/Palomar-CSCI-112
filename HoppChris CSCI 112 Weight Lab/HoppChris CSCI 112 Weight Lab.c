//weight.c
//Chris Hopp
//010809627
//Microsoft Visual Studio 2015
//Microsoft Windows 10

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MERCURY 37.8
#define VENUS 90.7
#define MARS 37.7
#define JUPITER 236.0
#define SATURN 91.6
#define URANUS 88.9
#define NEPTUNE 112.0



FILE *fp;

int main(void) {
	int pounds;
	double	mer, ven, mar, jup, sat, ura, nep;

	fp = fopen("csis.txt", "w");

	pounds = 200;
	
	mer = pounds * MERCURY/ 100;
	ven = pounds * VENUS / 100;
	mar = pounds * MARS / 100;
	jup = pounds * JUPITER / 100;
	sat = pounds * SATURN / 100;
	ura = pounds * URANUS / 100;
	nep = pounds * NEPTUNE / 100;

	printf("Mercury: %5.1f  \n",mer);
	fprintf(fp, "Mercury: %5.1f  \n",mer);
	printf("  Venus: %5.1f \n", ven);
	fprintf(fp, "  Venus: %5.1f  \n", ven);
	printf("   Mars: %5.1f \n", mar);
	fprintf(fp, "   Mars: %5.1f  \n", mar);
	printf("Jupiter: %5.1f \n", jup);
	fprintf(fp, "Jupiter: %5.1f  \n", jup);
	printf(" Saturn: %5.1f \n", sat);
	fprintf(fp, " Saturn: %5.1f  \n", sat);
	printf(" Uranus: %5.1f \n", ura);
	fprintf(fp, " Uranus: %5.1f  \n", ura);
	printf("Neptune: %5.1f \n", nep);
	fprintf(fp, "Neptune: %5.1f  \n", nep);

fclose(fp);
	

	getchar();
	

	return 0;
}