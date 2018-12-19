//penny.c
//Chris Hopp
//010809627
//Microsoft Visual Studio 2015
//Microsoft Windows 10

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

FILE *fp;

void header();
void footer();
void calcBalance(double, double, double);


int main(void) {

	fp = fopen("csis.txt", "w");

	double end;
	double balance;
	double deposit;
	int day;

	printf("Enter desired ending balance:");
	fprintf(fp, "Enter desired ending balance:");
	scanf("%lf", &end);
	fprintf(fp, "%lf\n", end);

	printf("Enter starting balance:");
	fprintf(fp, "Enter starting balance:");
	scanf("%lf", &balance);
	fprintf(fp, "%lf\n", balance);

	deposit = .01;

	header();
	calcBalance(balance, deposit, end);

	getchar();
	getchar();
	fclose(fp);
	return 0;
}

void header() {

	printf("\nDAY\t     DEPOSIT\t\tBALANCE\n---\t     -------\t\t-------\n");
	fprintf(fp, "\nDAY\t     DEPOSIT\t\tBALANCE\n---\t     -------\t\t-------\n");
}

void footer() {
	
	printf("...\t\t ...\t\t  ...\n\n");
	fprintf(fp, "...\t\t ...\t\t  ...\n\n");
}

void calcBalance(double balance, double deposit, double end) {

	int day;
	day = 0;

	while (balance <= end) {
		day++;
		balance += deposit;
		printf("%3d%17.2lf%17.2lf \n", day, deposit, balance);
		fprintf(fp, "%3d%17.2lf%17.2lf \n", day, deposit, balance);
		deposit = deposit * 2;

	}
	
	footer();

	printf("It took %d days to accumulate at least $%.2lf\n", day, end);
	fprintf(fp, "It took %d days to accumulate at least $%.2lf\n", day, end);

}