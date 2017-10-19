// Program:	Project 3
// Author:		Michael Moser
// Course:		COP2220

// Loads function library
#include <stdio.h>
#include <stdlib.h>

// Constant variables
	#define TAX 0.07

// Prototypes
void getGreeting (void);
void displayCredits (void);
void displaySelections (char selections[8], int widths[8], double prices[8]);
char getSelectionChoice (void);
int getLinearFeet (void);

int main (void)
{
	// #define TAX 0.07
	// Calls getGreeting function
	getGreeting ();
	char selection, selections[8] = {'A','B', 'C', 'D', 'E', 'F', 'G', 'H' };
	int feet, widths[8] = {6, 6, 12, 12, 12, 12, 12, 12};
	double prices[8] = {8.1, 4.08, 10.56, 10.68, 9.0, 10.8, 11.16, 17.88};
	displaySelections(selections,widths,prices);
	selection=getSelectionChoice();
	feet=getLinearFeet ();
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

void displaySelections (char selections[8], int widths[8], double prices[8])
{
    int i;
    for ( i=0; i<8; i++)
    {
        printf("%c      %i ft      $%.2lf\n\n", selections[i], widths[i], prices[i]);
    }


}

void displayCredits (void)
{
	// Displays screen prompt with no input or return value
	printf ("\nResults provided by Michael\n\n");
	return ;
}

char getSelectionChoice (void)
{
    char selection;
    printf("Please select a carpet choice from A-H: ");
    scanf("%c", &selection);

    return selection;
}

int getLinearFeet (void)
{
    int feet;
    printf("Please eneter the feet of the room: ");
    scanf("%i", &feet);

    return feet;
}
