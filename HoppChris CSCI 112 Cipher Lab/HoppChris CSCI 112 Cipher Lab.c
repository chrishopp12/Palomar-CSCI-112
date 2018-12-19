//cipher.c
//Chris Hopp
//010809627
//Microsoft Visual Studio 2015
//Microsoft Windows 10


#define _CRT_SECURE_NO_WARNINGS
#define MAX 500

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

FILE *fpIn, *fpOut;

int processFile(char[]);
void cipher(int shift, int size, char []);
void outputCode(int size, char[]);


int main(void) {
	int shift = 13;
	char congress[MAX];
	int size;

	if (!(fpOut = fopen("csis.txt", "w"))) {
		printf("csis.txt could not be opened for output.");
		getchar();
		exit(1);
	}

	size = processFile(congress);

	cipher(shift, size, congress);

	outputCode(size, congress);

	getchar();

	fclose(fpOut);
	return 0;
}


int processFile(char congress[]) {
	char c[MAX];
	int i, j;

	if (!(fpIn = fopen("congress.txt", "r"))) {
		printf("congress.txt could not be opened for input.");
		getchar();
		exit(1);
	}

	while (!feof(fpIn)) {
		fgets(c, MAX, fpIn);
	}

	printf("%s\n\n", c);
	fprintf(fpOut,"%s\n\n", c);

	_strupr(c);

	for (i = 0, j = 0; i < MAX; ++i) {
		if (c[i] >= 'A' && c[i] <= 'Z') {
			congress[j] = c[i];
			++j;
		}
		if (c[i] == '\0') {
			congress[j] = '\0';
		}
	}

	printf("%s\n\n", congress);
	fprintf(fpOut,"%s\n\n", congress);

	fclose(fpIn);
	return (j);

}

void cipher(int shift,int size, char congress[]) {
	int i;
	char temp;

	for (i = 0; i < size;++i) {
		temp = congress[i];
		if ((temp + shift) > 'Z') {
			congress[i] = (temp - (26 - shift));
		}
		else {
			congress[i] = (temp + shift);
		}
	}
	printf ("%s\n\n", congress);
	fprintf(fpOut,"%s\n\n", congress);

}

void outputCode(int size, char congress[]) {
	int i;

	for (i = 0; i <= size; i++) {
		printf("%c", congress[i]);
		fprintf(fpOut,"%c", congress[i]);

		if (i % 5 == 4) {
			printf("  ");
			fprintf(fpOut,"  ");
		}
		if (i % 50 == 49) {
			printf("\n");
			fprintf(fpOut,"\n");
		}	
	}
}

