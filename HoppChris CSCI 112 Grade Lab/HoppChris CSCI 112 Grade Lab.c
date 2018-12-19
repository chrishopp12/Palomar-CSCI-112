//grade.c
//Chris Hopp
//010809627
//Microsoft Visual Studio 2015
//Microsoft Windows 10

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


FILE *fp;
void calculateAverage();

int main(void) {
	int i;

	fp = fopen("csis.txt", "w");

	for (i = 1; i <= 4; ++i) {
		calculateAverage();
	}

	getchar();
	fclose(fp);

	return 0;
}
void calculateAverage () {
	int total = 0,
		num = 0,
		ave = 0,
	grade;

	printf("Enter test grade (or -1 to quit):\n");
	fprintf(fp, "Enter test grade (or -1 to quit):\n");
	scanf("%d", &grade);
	fprintf(fp, "%d\n", grade);

	while (grade != -1) {
		++num;
		total += grade;

		printf("Enter test grade (or -1 to quit):\n");
		fprintf(fp, "Enter test grade (or -1 to quit):\n");
		scanf("%d", &grade);
		fprintf(fp, "%d\n", grade);
		
	}
		printf("Total points recieved is %d for %d tests\n", total, num);
		fprintf(fp,"Total points recieved is %d for %d tests\n", total, num);
		if (num > 0) {
			ave = total / num;
			printf("The test average is %d\n\n", ave);
			fprintf(fp, "The test average is %d\n\n", ave);
		}
		else {
			printf("There is no average\n");
			fprintf(fp, "There is no average\n");
		}
	
	getchar();
}






