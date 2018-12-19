//database.c
//Chris Hopp
//010809627
//Microsoft Visual Studio 2015
//Microsoft Windows 10

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
FILE *fpIn, *fpOut;



typedef struct workers {
	char first[8];
	char initial[2];
	char last[10];
	char street[17];
	char city[12];
	char state[3];
	char zip[6];
	int age[4];
	char sex[2];
	int tenure[4];
	double salary[10];
} Worker;

void strsub(char buf[], char sub[], int start, int end);

int inputData(Worker emp[]);

void displayData(Worker emp[], int size);

void maleWorkers(Worker emp[], int size);

void highestWoman(Worker emp[], int size);

void lowestMan(Worker emp[], int size);

double averageSalary(Worker emp[], int size);

void belowAvgWomen(Worker emp[], int size, double avgSalary);

void ratio(Worker emp[], int size, double avgSalary);

void seniority(Worker emp[], int size);

void raise(Worker emp[], int size);

void zipCode(Worker emp[], int size);

int main(void) {


	if (!(fpOut = fopen("csis.txt", "w"))) {
		printf("csis.txt could not be opened for output.");
		exit(1);
		getchar();
	}


	int size;
	double avgSalary;
	avgSalary = 0.00;

	Worker employees[MAX];


	size = inputData(employees);

	inputData(employees);

	displayData(employees, size);

	maleWorkers(employees, size);

	highestWoman(employees, size);

	lowestMan(employees, size);

	avgSalary = averageSalary(employees, size);

	belowAvgWomen(employees, size, avgSalary);

	ratio(employees, size, avgSalary);

	seniority(employees, size);

	raise(employees, size);

	zipCode(employees, size);

	fclose(fpOut);
	getchar();

	return 0;
}

void strsub(char buf[], char sub[], int start, int end) {
	int i, j;
	for (j = 0, i = start; i <= end; i++, j++) {
		sub[j] = buf[i];
	}
	sub[j] = '\0';
}

int inputData(Worker emp[]) {
	char buf[MAX];
	char temp[MAX];
	int i = 0;

	if (!(fpIn = fopen("payfile.txt", "r"))) {
		printf("payfile.txt could not be opened for input.");
		exit(1);
		getchar();
	}

	while (!feof(fpIn)) {
		fgets(buf, MAX, fpIn);
		strsub(buf, emp[i].first, 0, 6);
		strsub(buf, emp[i].initial, 8, 8);
		strsub(buf, emp[i].last, 10, 18);
		strsub(buf, emp[i].street, 20, 35);
		strsub(buf, emp[i].city, 37, 47);
		strsub(buf, emp[i].state, 49, 50);
		strsub(buf, emp[i].zip, 52, 56);
		strsub(buf, temp, 58, 59);
		*emp[i].age = atoi(temp);
		strsub(buf, emp[i].sex, 61, 61);
		strsub(buf, temp, 63, 63);
		*emp[i].tenure = atoi(temp);
		strsub(buf, temp, 65, 70);
		*emp[i].salary = atof(temp);
		++i;

	}
	fclose(fpIn);
	return i;
}

void displayData(Worker emp[], int size) {
	int i;

	printf("Full Name\t\tStreet\t\tCity\t  State\t    Zip\t     Age   M/F\tTenure\t Salary\n");
	fprintf(fpOut,"Full Name\t\tStreet\t\tCity\t  State\t    Zip\t     Age   M/F\tTenure\t Salary\n");

	for (i = 0; i < size; ++i) {
		printf("%7s %1s %9s %16s %11s %5s %10s %5d %5s %3d Yrs %9.2lf\n", emp[i].first, emp[i].initial,
			emp[i].last, emp[i].street, emp[i].city, emp[i].state, 
			emp[i].zip, *emp[i].age, emp[i].sex, *emp[i].tenure, *emp[i].salary);
		fprintf(fpOut,"%7s %1s %9s %16s %11s %5s %10s %5d %5s %3d Yrs %9.2lf\n", emp[i].first, emp[i].initial,
			emp[i].last, emp[i].street, emp[i].city, emp[i].state,
			emp[i].zip, *emp[i].age, emp[i].sex, *emp[i].tenure, *emp[i].salary);
	
	}
	printf("\n");
	fprintf(fpOut,"\n");
}

void maleWorkers(Worker emp[], int size) {
	int i,j;
	char m[] = "M";

	for (i = 0; i < size; ++i) {
		j = (strcmp(emp[i].sex, m));
		if (j == 0) {
			printf("%s %s\n", emp[i].first, emp[i].last);
			fprintf(fpOut,"%s %s\n", emp[i].first, emp[i].last);
		}
	}
	printf("\n");	
	fprintf(fpOut,"\n");
}

void highestWoman(Worker emp[], int size) {
	int i, j;
	double salary;
	char* first;
	char* last;
	char f[] = "F";

	salary = 0.00;
	for (i = 0; i < size; ++i) {
		j = (strcmp(emp[i].sex, f));
		if ((j == 0) && (*emp[i].salary >= salary)) {
			salary = *emp[i].salary;
			first = emp[i].first;
			last = emp[i].last;
		}
		
	}
	printf("The highest paid woman is %s %s\n\n", first, last);
	fprintf(fpOut,"The highest paid woman is %s %s\n\n", first, last);
}

void lowestMan(Worker emp[], int size) {
	int i, j;
	double salary;
	char* first;
	char* last;
	char m[] = "M";

	salary = 999999;
	for (i = 0; i < size; ++i) {
		j = (strcmp(emp[i].sex, m));
		if ((j == 0) && (*emp[i].salary <= salary)) {
			salary = *emp[i].salary;
			first = emp[i].first;
			last = emp[i].last;
		}

	}
	printf("The lowest paid man is %s %s\n\n", first, last);
	fprintf(fpOut,"The lowest paid man is %s %s\n\n", first, last);
}

double averageSalary(Worker emp[], int size) {
	int i;
	double salary, avg;

	salary = 0.00;

	for (i = 0; i < size; ++i) {
		salary += *emp[i].salary;
	}

	avg = (salary / (double) size);
	printf("The average salary is $%.2lf\n\n", avg);
	fprintf(fpOut,"The average salary is $%.2lf\n\n", avg);

	return avg;
}

void belowAvgWomen(Worker emp[], int size, double avgSalary) {
	int i, j;
	char f[] = "F";

	printf("Women earning less than average are:\n");
	fprintf(fpOut,"Women earning less than average are:\n");
	for (i = 0; i < size; ++i) {
		j = (strcmp(emp[i].sex, f));
		if ((j == 0) && (*emp[i].salary < avgSalary)) {
			printf("%s %s\n", emp[i].first, emp[i].last);
			fprintf(fpOut,"%s %s\n", emp[i].first, emp[i].last);
		}
	}
	printf("\n");
	fprintf(fpOut,"\n");
}

void ratio(Worker emp[], int size, double avgSalary) {
	int i, j;
	double above, below, ratio;
	char m[] = "M";

	above = 0.0;
	below = 0.0;
	ratio = 0.0;
	for (i = 0; i < size; ++i) {
		j = (strcmp(emp[i].sex, m));
		if ((j == 0) && (*emp[i].salary > avgSalary)) {
			++above;
		}
		if ((j == 0) && (*emp[i].salary < avgSalary)) {
			++below;
		}

	}

	ratio = above / below;

	printf("The ratio of men earning more than average to men earning less than average is %.3lf:1\n\n", ratio);
	fprintf(fpOut,"The ratio of men earning more than average to men earning less than average is %.3lf:1\n\n", ratio);

}

void seniority(Worker emp[], int size) {
	int i;

	for (i = 0; i < size; ++i) {
		if ((*emp[i].salary >= 673.07) &&
			(*emp[i].tenure >= 5) &&
			(*emp[i].age >= 30)) {
			printf("%s %s\n", emp[i].first, emp[i].last);	
			fprintf(fpOut,"%s %s\n", emp[i].first, emp[i].last);
			}
		}
	
	printf("\n");
	fprintf(fpOut,"\n");
}

void raise(Worker emp[], int size) {
	int i;
	double salary;
	
	printf("First   Last\tNew Salary\n");
	fprintf(fpOut, "First   Last\tNew Salary\n");
	for (i = 0; i < size; ++i) {
		if ((*emp[i].salary) < 350.00) {
			salary = *emp[i].salary * 1.10;
			printf("%s %s %.2lf\n", emp[i].first, emp[i].last, salary);
			fprintf(fpOut,"%s %s %.2lf\n", emp[i].first, emp[i].last, salary);
		}
	}
	printf("\n");
	fprintf(fpOut,"\n");
}

void zipCode(Worker emp[], int size) {
	Worker temp[MAX];
	int i, j;

	for (i = 1; i < size; i++)
		for (j = 0; j < size - 1; j++) {
			if (strcmp(emp[j].zip, emp[j + 1].zip) > 0) {
				temp[j] = emp[j];
				emp[j] = emp[j + 1];
				emp[j + 1] = temp[j];
			}
		}
	for (i = 0; i < size; i++) {
		printf("%s %s %s\n", emp[i].first, emp[i].last, emp[i].zip);
		fprintf(fpOut,"%s %s %s\n", emp[i].first, emp[i].last, emp[i].zip);
	}
}