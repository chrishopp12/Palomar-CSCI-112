//BMI.c
//Chris Hopp
//010809627
//Microsoft Visual Studio 2015
//Microsoft Windows 10

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


FILE *fp;
void calc_BMI();

int main(void) {
	int i;
	fp = fopen("csis.txt", "w");
	for (i = 1; i <= 4; ++i) {
		calc_BMI();
	}
	
	getchar();
	fclose(fp);

	return 0;
}
void calc_BMI () {
	double wgt, hgt;
	double bmi;

	printf("Enter height in inches:\n");
	fprintf(fp, "Enter height in inches:\n");
	scanf("%lf", &hgt);
	fprintf(fp, "%lf\n", hgt);

	printf("Enter weight in pounds:\n");
	fprintf(fp, "Enter weight in pounds:\n");
	scanf("%lf", &wgt);
	fprintf(fp, "%lf\n", wgt);
	bmi = (wgt * 703) / (hgt * hgt);
	printf("BMI is %.1lf\n", bmi);
	fprintf(fp,"BMI is %.1lf\n", bmi);

	if (bmi < 18.5) {
		printf("Underweight\n\n");
		fprintf(fp,"Underweight\n\n");
	}
	if (bmi >= 18.5 && bmi < 25.0) {
		printf("Normal\n\n");
		fprintf(fp,"Normal\n\n");
	}
	if (bmi >= 25.0 && bmi < 30.0) {
		printf("Overweight\n\n");
		fprintf(fp, "Overweight\n\n");
	}
	if (bmi >= 30.0) {
		printf("Obese\n\n");
		fprintf(fp,"Obese\n\n");
	}
	getchar();
}






