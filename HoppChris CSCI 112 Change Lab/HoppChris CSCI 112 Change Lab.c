//change.c
//Chris Hopp
//010809627
//Microsoft Visual Studio 2015
//Microsoft Windows 10

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



FILE *fp;

int main(void) {


	int twenty, twenties, ten, tens, five, fives, one, ones, quarter, quarters,
		dime, dimes, nickel, nickels, penny, pennies, change, cost, tendered;

	cost = 2117;
	tendered = 10000;
	twenty = 2000;
	ten = 1000;
	five = 500;
	one = 100;
	quarter = 25;
	dime = 10;
	nickel = 05;
	penny = 01;
	
	fp = fopen("csis.txt", "w");
	
	change = tendered - cost;
	twenties = change / twenty;
	change = change % twenty;
	tens = change / ten;
	change = change % ten;
	fives = change / five;
	change = change % five;
	ones = change / one;
	change = change % one;
	quarters = change / quarter;
	change = change % quarter;
	dimes = change / dime;
	change = change % dime;
	nickels = change / nickel;
	change = change % nickel;
	pennies = change / penny;
	

	

	printf("The change is %d Twenties, %d Tens, %d Fives, %d Ones, %d Quarters, %d Dimes, %d Nickels, and %d Pennies."
		,twenties, tens, fives, ones, quarters, dimes, nickels, pennies);
	fprintf(fp,"The change is %d Twenties, %d Tens, %d Fives, %d Ones, %d Quarters, %d Dimes, %d Nickels, and %d Pennies."
		, twenties, tens, fives, ones, quarters, dimes, nickels, pennies);
	
	

fclose(fp);
	

	getchar();
	

	return 0;
}