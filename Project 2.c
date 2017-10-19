// Program:	Project 2
// Author:		Michael Moser
// Course:		COP2220

// Loads function library
#include <stdio.h>

// Main function contains the information to call other functions
int main (void)
{
	// Calls getGreeting function
	getGreeting ();
	// Calls getArea function
	getArea ();
	// Calls getTileAmount function
	getTileAmount ();
	// Calls getSubtotal function
	getSubtotal ();
	// Calls getTaxValue function
	getTaxValue ();
	// Calls getTotal function
	getTotal ();
	// Calls displayCredits function
	displayCredits ();
	return 0;
}

void getGreeting (void)
{
	// Screen prompt with no input or return value
	printf ("Welcome to Michael's Flooring\n\n");
	return ;
}
// Function that takes user input and assigns to variables
int getArea (length, width, area)
{
	// Ask for user input and assigns inputs to variable for calculation
	printf("Enter length of room: ");
	scanf("%i", &length);
	printf("Enter width of room: ");
	scanf("%i", &width);
	area = length * width;
	printf("%i sq.ft is the area of the room.\n\n", area);
	return area;
}
// Calculate tileAmount variable
int getTileAmount ()
{
	// Displays the number of tiles needed to user using constant variable
	int area;
	double tileAmount;
	#define oneTile 1.5
	tileAmount = area / oneTile;
	printf("%i / %.2lf = %.2lf Tiles needed.\n\n", area, oneTile, tileAmount);
	return tileAmount;
}
// Calculate subtotal variable
int getSubtotal ()
{
	// Displays subtotal of all tiles needed using constant variable
	double subtotal, tileAmount;
	#define tileCost 0.78
	subtotal = tileAmount * tileCost;
	printf("$%.2lf is the cost of the tiles.\n\n", subtotal);
	return subtotal;
}
// Calculate taxValue variable
int getTaxValue ()
{
	// Displays the amount of tax for purchase using constant variable
	double taxValue, subtotal;
	#define tax 0.07
	taxValue = tax * subtotal;
	printf("$%.2lf is the tax for purchase.\n\n", taxValue);
	return taxValue;
}
// Calculate total variable
int getTotal ()
{
	// Displays the total of purchase by adding subtotal and taxValue variables
	double total, taxValue, subtotal;
	total = taxValue + subtotal;
	printf("$%.2lf is the total of purchase.\n\n", total);
	return total;
}

void displayCredits (void)
{
	// Displays screen prompt with no input or return value
	printf ("Results provided by Michael\n\n");
	return ;
}

/*
Test data #1
length: 20
width: 15
area: 300 sq.ft
tiles needed: 200
Cost of tiles: $156.00
Tax: $14.00
Total: $214.00
_____________________________
Test data #2
length: 17
width: 19
area: 323 sq.ft
tiles needed: 215.33
cost of tiles: $167.96
tax: $15.07
total: 230.41
_____________________________
Test data #3
length: 30
width: 24
area: 720 sq.ft
tiles needed: 480
cost of tiles: $374.40
tax: $33.60
total: $513.60
____________________________________________
Output #1
Welcome to Michael's Flooring

Enter length of room: 20
Enter width of room: 15
300 sq.ft is the area of the room.

300 / 1.50 = 200.00 Tiles needed.

$156.00 is the cost of the tiles.

$14.00 is the tax for purchase.

$214.00 is the total of purchase.

Results provided by Michael


Process returned 0 (0x0)   execution time : 7.249 s
Press any key to continue.
_______________________________________________
Output #2
Welcome to Michael's Flooring

Enter length of room: 17
Enter width of room: 19
323 sq.ft is the area of the room.

323 / 1.50 = 215.33 Tiles needed.

$167.96 is the cost of the tiles.

$15.07 is the tax for purchase.

$230.41 is the total of purchase.

Results provided by Michael


Process returned 0 (0x0)   execution time : 5.858 s
Press any key to continue.
________________________________________________
Output #3
Welcome to Michael's Flooring

Enter length of room: 30
Enter width of room: 24
720 sq.ft is the area of the room.

720 / 1.50 = 480.00 Tiles needed.

$374.40 is the cost of the tiles.

$33.60 is the tax for purchase.

$513.60 is the total of purchase.

Results provided by Michael


Process returned 0 (0x0)   execution time : 5.825 s
Press any key to continue.
*/
