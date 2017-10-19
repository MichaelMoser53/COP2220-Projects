// Program:	Project 1
// Author:		Michael Moser
// Course:		COP2220

#include <stdio.h>                             // Loads function library

int main (void)                                     // Begins function to display startup messages
                                                    // and ask for user input
{
	printf ("Welcome to Michael's Flooring\n");
	displayCredits ();
	int floorType;
	printf("Enter floor type to order: ");
	scanf("%s", floorType);
	printf("%s has been ordered!\n", floorType);    // Displays order message based on user input
                                                    // with return 0 ending the code.
	return 0;
}

void displayCredits (void)                          // Seperate function to display message at start of code.
{
	printf ("Results provided by Michael\n\n");
	return ;
}

/*
Run 1
Welcome to Michael's Flooring
Results provided by Michael

Enter floor type to order: Wood
Wood has been ordered!

Process returned 0 (0x0)   execution time : 1.576 s
Press any key to continue.
__________________________________________________________
Run 2
Welcome to Michael's Flooring
Results provided by Michael

Enter floor type to order: Carpet
Carpet has been ordered!

Process returned 0 (0x0)   execution time : 6.226 s
Press any key to continue.
__________________________________________________________
Run 3
Welcome to Michael's Flooring
Results provided by Michael

Enter floor type to order: Tile
Tile has been ordered!

Process returned 0 (0x0)   execution time : 8.207 s
Press any key to continue.
*/
