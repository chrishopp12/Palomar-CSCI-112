//check.c
//Chris Hopp
//010809627
//Microsoft Visual Studio 2015
//Microsoft Windows 10

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

FILE *fpIn, *fpOut;

void outputHeaders();
void initialBalance(double amount, double *balance, double *service, double *openbalance);
void deposit(double amount, double *balance, double *service, int *numDeposit, double *amtDeposit);
void check(double amount, double *balance, double *service, int *numCheck, double *amtCheck);
void outputSummary(int numDeposit, double amtDeposit, int numCheck, double amtCheck, double openBalance,
	double service, double closeBalance);

int main(void) {


	char code;
	double amount, service, balance;
	double amtCheck, amtDeposit, openBalance, closeBalance;
	int numCheck, numDeposit;

	
	if (!(fpIn = fopen("account.txt", "r"))) {
		printf("account.txt could not be opened for input.");
		exit(1);
		getchar();
	}

	
	if (!(fpOut = fopen("csis.txt", "w"))) {
		printf("csis.txt could not be opened for output.");
		exit(1);
	}

	amount = 0.0;
	service = 0.0;
	amtCheck = 0.0;
	amtDeposit = 0.0;
	openBalance = 0.0;
	closeBalance = 0.0;
	numCheck = 0;
	numDeposit = 0;

	outputHeaders();

	while (!feof(fpIn)) {
		fscanf(fpIn, "%c %lf\n", &code, &amount);

		if (code == 'I') {
			initialBalance(amount, &balance, &service, &openBalance);
		}
		else if (code == 'D') {
			deposit(amount, &balance, &service, &numDeposit, &amtDeposit);
		}
		else {
			check(amount, &balance, &service, &numCheck, &amtCheck);
			}
		}

		closeBalance = balance - service;
		outputSummary(numDeposit, amtDeposit, numCheck, amtCheck, openBalance, service, closeBalance);


		getchar();
		fclose(fpIn);
		fclose(fpOut);
		return 0;
	}

void outputHeaders() {

	printf("Transaction\t\tDeposit\t\tCheck\t\tBalance\n");
	printf("------------\t\t-------\t\t-----\t\t--------\n");

	fprintf(fpOut, "Transaction\t\tDeposit\t\tCheck\t\tBalance\n");
	fprintf(fpOut, "------------\t\t-------\t\t-----\t\t--------\n");

}

void initialBalance(double amount, double *balance, double *service, double *openBalance) {
	*service += 3.00;
	*balance = amount;
	*openBalance = amount;

	printf("Initial Balance%48.2lf\n", *balance);
	fprintf(fpOut, "Initial Balance%48.2lf\n", *balance);
		
}
	
void deposit(double amount, double *balance, double *service, int *numDeposit, double *amtDeposit) {
	++*numDeposit;
	*amtDeposit += amount;
	*balance += amount;
	if (*balance < amount) {
		*service += 5.00;
	}
	*service += .03;
	printf("Deposit%24.2lf%32.2lf\n", amount, *balance);
	fprintf(fpOut, "Deposit%24.2lf%32.2lf\n", amount, *balance);

}

void check(double amount, double *balance, double *service, int *numCheck, double *amtCheck) {
	++*numCheck;
	*amtCheck += amount;
	*balance -= amount;
	*service += .06;

	printf("Check%41.2lf%17.2lf\n", amount, *balance);
	fprintf(fpOut, "Check%41.2lf%17.2lf\n", amount, *balance);

}

void outputSummary(int numDeposit, double amtDeposit, int numCheck, double amtCheck, double openBalance,
	double service, double closeBalance) {

	printf("\n...\n");
	printf("Total number deposits:%8d\n", numDeposit);
	printf("Total amount deposits:%8.2lf\n\n", amtDeposit);
	printf("  Total number checks:%8d\n", numCheck);
	printf("  Total amount checks:%8.2lf\n\n", amtCheck);
	printf(" Total service charge:%8.2lf\n\n", service);
	printf("      Opening balance:%8.2lf\n", openBalance);
	printf("      Closing balance:%8.2lf\n\n", closeBalance);

	fprintf(fpOut, "\n...\n");
	fprintf(fpOut, "Total number deposits:%8d\n", numDeposit);
	fprintf(fpOut, "Total amount deposits:%8.2lf\n\n", amtDeposit);
	fprintf(fpOut, "  Total number checks:%8d\n", numCheck);
	fprintf(fpOut, "  Total amount checks:%8.2lf\n\n", amtCheck);
	fprintf(fpOut, " Total service charge:%8.2lf\n\n", service);
	fprintf(fpOut, "      Opening balance:%8.2lf\n", openBalance);
	fprintf(fpOut, "      Closing balance:%8.2lf\n\n", closeBalance);

	getchar();



}


