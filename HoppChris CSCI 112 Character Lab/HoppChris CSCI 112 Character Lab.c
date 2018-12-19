//char.c
//Chris Hopp
//010809627
//Microsoft Visual Studio 2015
//Microsoft Windows 10

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



FILE *fp;

int main(void) {


	int a = '\n',
		b = '\t',
		c = '\v',
		d = '\b',
		e = '\r',
		f = '\f',
		g = '\\',
		h = '\'',
		i = '\"',
		j = '\0';


	fp = fopen("csis.txt", "w");

	printf("Char Constant       Description                    Value\n");
	printf("     '\\n'           newline                         %d\n", a);
	printf("     '\\t'           horizontal tab                  %d\n", b);
	printf("     '\\v'           vertical tab                    %d\n", c);
	printf("     '\\b'           backspace                       %d\n", d);
	printf("     '\\r'           carriage return                 %d\n", e);
	printf("     '\\f'           form feed                       %d\n", f);
	printf("     '\\\'            backslash                       %d\n", g);
	printf("     '\\''           single quote (apostrophe)       %d\n", h);
	printf("     '\\\"'           double quote                    %d\n", i);
	printf("     '\\0'           null                            %d\n", j);

	fprintf(fp,"Char Constant       Description                    Value\n");
	fprintf(fp,"     '\\n'           newline                         %d\n", a);
	fprintf(fp,"     '\\t'           horizontal tab                  %d\n", b);
	fprintf(fp,"     '\\v'           vertical tab                    %d\n", c);
	fprintf(fp,"     '\\b'           backspace                       %d\n", d);
	fprintf(fp,"     '\\r'           carriage return                 %d\n", e);
	fprintf(fp,"     '\\f'           form feed                       %d\n", f);
	fprintf(fp,"     '\\\'            backslash                       %d\n", g);
	fprintf(fp,"     '\\''           single quote (apostrophe)       %d\n", h);
	fprintf(fp,"     '\\\"'           double quote                    %d\n", i);
	fprintf(fp,"     '\\0'           null                            %d\n", j);
	

fclose(fp);
	

	getchar();
	

	return 0;
}