//stats.c
//Chris Hopp
//010809627
//Microsoft Visual Studio 2015
//Microsoft Windows 10

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

FILE *fp;

void partA(int score[], int count);
void partB(int score[], int count);
void partC(int score[], int count);
void partD(int score[], int count);
void partE(int score[], int count);
void partF(int score[], int count);
void partG(int score[], int count);

int main(void) {
	
fp = fopen("csis.txt", "w");

	int score[] =	{ 90, 85, 100, 50, 50, 85, 60, 70, 55, 55, 80, 95, 70, 60, 95, 80,
				100, 75, 70, 95, 90, 90, 70, 95, 50, 65, 85, 95, 100, 65};
	int count;
	count = 0;
	count = sizeof(score)/4;
		
	partA(score, count);
	partB(score, count);
	partC(score, count);
	partD(score, count);
	partE(score, count);
	partF(score, count);
	partG(score, count);

	getchar();
	fclose(fp);

	return 0;
}



void partA(int score[], int count) {
	int i;
	
	for (i = 0; i < count; i++) {
		printf("%3d ", score[i]);
		fprintf(fp, "%3d ", score[i]);

		if (i % 5 == 4) {
			printf("\n");
			fprintf(fp,"\n");
		}
	}
	printf("\n\n");
	fprintf(fp,"\n\n");
}

	
void partB(int score[], int count) {
	int i, k, temp;

	for (i = 1; i < count; i++) {
		temp = score[i];
		k = i - 1;

		while (k >= 0 && temp < score[k]) {
			score[k + 1] = score[k];
			k -= 1;
		}
		score[k + 1] = temp;
	}

	for (i = 0; i < count; i++){
		printf("%3d ", score[i]);
		fprintf(fp,"%3d ", score[i]);
		if (i % 5 == 4) {
			fprintf(fp, "\n");
			printf("\n");
		}
	}

	printf("\n\n");
	fprintf(fp,"\n\n");

}


void partC(int score[], int count) {
	int i, j, k, temp, frequency, mode;

	printf("score          frequency\n");
	printf("-----          ---------\n");
	fprintf(fp,"score          frequency\n");
	fprintf(fp,"-----          ---------\n");

	for (i = 1; i < count; i++){
		temp = score[i];
		k = i - 1;

		while (k >= 0 && temp > score[k]){
			score[k + 1] = score[k];
			k -= 1;
		}
		score[k + 1] = temp;
	}

	frequency = 1;
	mode = 0;

	for (i = 0; i < count; i++){
		if (score[i] == score[i + 1]) {
			++frequency;
			if (frequency > mode) {
				mode = frequency;
				j = score[i];
			}
		}
		else{
			printf("%3d                %d\n", score[i], frequency);
			fprintf(fp,"%3d                %d\n", score[i], frequency);
			frequency = 1;		
		}
	}
	printf("\n");
	fprintf(fp, "\n");
}


void partD(int score[], int count) {
	int i;
	double pass, fail, passing, failing;

	fail = 0;
	pass = 0;
	passing = 0;
	failing = 0;

	for (i = 0; i < count; i++) {
		if (score[i] >= 60) 
			++pass;
		else 
			++fail;		
	}
	passing = 100 * pass / count;
	failing = 100 * fail / count;
		printf("%.1lf percent of the grades are passing\n", passing);
		printf("%.1lf percent of the grades are failing\n", failing);
		fprintf(fp,"%.1lf percent of the grades are passing\n", passing);
		fprintf(fp,"%.1lf percent of the grades are failing\n", failing);
}


void partE(int score[], int count) {
	int i;
	double sum;
	double mean;
	sum = 0;

	for (i = 0; i < count; i++) {
		sum += score[i];
	}
	mean = sum/count;	
	printf("The mean is %.1lf\n", mean);
	fprintf(fp,"The mean is %.1lf\n", mean);
}


void partF(int score[], int count) {
	int i, j, k, temp, frequency, mode;

	for (i = 1; i < count; i++) {
		temp = score[i];
		k = i - 1;

		while (k >= 0 && temp > score[k]) {
			score[k + 1] = score[k];
			k -= 1;
		}
		score[k + 1] = temp;
	}

	frequency = 1;
	mode = 0;

	for (i = 0; i < count; i++) {
		if (score[i] == score[i + 1]) {
			++frequency;
			if (frequency > mode) {
				mode = frequency;
				j = score[i];
			}
		}
		else {
			frequency = 1;
		}
	}
		printf("The mode is %d\n", j);
		fprintf(fp,"The mode is %d\n", j);
}


void partG (int score [], int count){
	int median = 0;
	int x = 0;
	int y = 0;
	if (count % 2 == 0) {
		 x = score[count / 2];
		 y = score[(count / 2)-1];
		 median = (x + y) / 2;
		printf("The median is %d\n", median);
		fprintf(fp,"The median is %d\n", median);
	}
	else {
		median = score[(count - 1) / 2];
		printf("The median is %d\n", median);
		fprintf("The median is %d\n", median);
	}
	
}