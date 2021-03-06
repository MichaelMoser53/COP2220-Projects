// Program:	Project 5
// Author: Michael Moser
// Course: COP2220

// Loads function library
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Constant variables
	#define TAX 0.07
	#define SIZE_ARRAY 8
	#define LENGTH_STRING 20

// Prototypes
void getGreeting (void);
void displayCredits (void);
void displaySelections (char selections[], int widths[], double prices[], char *colors[]);
int getSelectionChoice (char selections[]);
int getLinearFeet (void);
double getSubtotal (int feet, double prices[], int index);
double getTaxAmount (double subtotal);
double getTotal (double subtotal, double taxAmount);
void getGrandTotal (char *selections, int *carpetOrdered);
void getHighest (char selections[], int carpetOrdered[] );
void getLowest (char *selections, int *carpetOrdered );
void displayColors (char *colors);
void getColorSelections (char *colors[], char carpetColors[]);

int main (void)
{   // Declaration of variables/arrays within main function
	char selections[SIZE_ARRAY] = {'A','B', 'C', 'D', 'E', 'F', 'G', 'H' };
	int i, index, feet, grandTotal, max, widths[SIZE_ARRAY] = {6, 6, 12, 12, 12, 12, 12, 12};
	double taxAmount, total, subtotal, prices[SIZE_ARRAY] = {8.1, 4.08, 10.56, 10.68, 9.0, 10.8, 11.16, 17.88};
    int carpetOrdered[SIZE_ARRAY];
	char carpetChoice, rerun;
	char *colors[SIZE_ARRAY] = {"Black ice", "Burgundy", "Heather green", "Leaf green", "Ocean blue", "Sky grey", "Stone beige", "Walnut"};
	char carpetColors[LENGTH_STRING];

    // Calls getGreeting and displaySelections functions to display a screen prompt
	getGreeting ();
	displaySelections(selections, widths, prices, colors);

    // for loop used to fill carpetOrdered array with values using pointer notation
    // do loop used to repeat program based on user input and run proper functions and actions for calculations accordingly
	for (i = 0; i < SIZE_ARRAY; i++)
    {
        *(carpetOrdered+i) = 0;
    }

    do
    {

	index = getSelectionChoice(selections);
	feet = getLinearFeet ();
	getColorSelections(colors, carpetColors);
    subtotal = getSubtotal (feet, prices, index);
    taxAmount = getTaxAmount(subtotal);
    total = getTotal(subtotal, taxAmount);
	printf("Would you like to order more carpet? [y/n]");
    scanf("%c", &rerun);
    printf("\n");
        if (rerun == 'n')
        {

        }

        ++carpetOrdered[index];

    }
    while (rerun == 'y');

    // displays all the carpet ordered by the user using pointer notation
    printf("Ordered carpet:\n");
    for (i = 0; i < SIZE_ARRAY; i++)
    {
        printf("%c = %i times\n", *(selections + i), *(carpetOrdered + i));
    }
    // functions display grand total, max, and least carpet ordered.
    getGrandTotal (selections, carpetOrdered);
    getHighest (selections, carpetOrdered);
    getLowest (selections, carpetOrdered);

	// Calls displayCredits function
	displayCredits ();
	return 0;
}
// Screen prompt with no input or return value
void getGreeting (void)
{
	printf ("Welcome to Michael's Flooring\n\n");
	return ;
}
// Displays screen prompt with no input or return value
void displayCredits (void)
{

	printf ("\nResults provided by Michael\n\n");
	return ;
}
// function that displays carpet and color options using array notation with no return value
void displaySelections (char selections[], int widths[], double prices[], char *colors[])
{
    int i;
    printf("Carpet choices:\n\n");
    for ( i=0; i<SIZE_ARRAY; i++)
    {
        printf("%c      %i ft      $%.2lf\n\n", selections[i], widths[i], prices[i]);
    }
    printf("Color choices:\n\n");
    for ( i=0; i<SIZE_ARRAY; i++)
    {
        printf("%s\n", colors[i]);
    }


    return ;
}
// function that ask for user input of choice and validates selections with return value of index
int getSelectionChoice (char selections[])
{
    int i = 0, index;
    char carpetChoice;
    bool isValid = false;

    while ( isValid == false)
    {
        printf("\nPlease select a carpet choice from A-H: ");
        scanf("\n%c", &carpetChoice);

        for ( i=0; i<SIZE_ARRAY; i++)
        {
            if (toupper(carpetChoice) == selections[i])
            {
                index = i;
                isValid = true;
                break;

            }
        }
        if (isValid == false)
            printf("Please enter valid carpet choice\n");
    }

    return index;
}
// function asking for input of feet and validates input with return value of feet
int getLinearFeet (void)
{
    int feet = -1;

    while (feet < 0)
    {
        printf("Please enter the feet of the room: ");
        scanf("%i", &feet);
        while( getchar()!= '\n' );
    }

    return feet;
}
// function that calculates subtotal and returns that value to the user
double getSubtotal (int feet, double prices[], int index)
{
    double subtotal;
    subtotal = feet * prices[index];
    printf("\nSubtotal: $%.2lf\n", subtotal);

    return subtotal;
}
// function that calculates taxAmount and returns the value to user
double getTaxAmount (double subtotal)
{
    double taxAmount;
    taxAmount = subtotal * TAX;
    printf("Tax: $%.2lf\n", taxAmount);

    return taxAmount;
}
// function that calculates total and returns the value to the user
double getTotal (double subtotal, double taxAmount)
{
    double total;
    total = subtotal + taxAmount;
    printf("Total: $%.2lf\n\n", total);

    return total;
}
// function that calculates grnadTotal based on the amount of carpet ordered from user with no return value
void getGrandTotal (char *selections, int *carpetOrdered)
{
    int carpet, grandTotal = 0;
    for (carpet=0; carpet<SIZE_ARRAY; carpet++)
    {
        grandTotal = grandTotal + *(carpetOrdered+carpet);
    }
    printf("\nTotal amount of carpet ordered: %i\n", grandTotal);

    return ;
}
// function calculates highest carpet ordered using for loop within carpetOrdered array, no return value
void getHighest (char selections[], int carpetOrdered[])
{
    int i, maximum, index = 0;
    maximum = carpetOrdered[0];

    for (i = 1; i<SIZE_ARRAY; i++)
    {
        if (carpetOrdered[i] > maximum)
        {
            maximum = carpetOrdered[i];

            index = i;
        }
    }
    printf("\nMax carpet ordered is %c with %i ordered\n\n", selections[index], maximum);

    return ;
}
// function calculates lowest carpet ordered using for loop within carpetOrdered array, no return value
void getLowest (char *selections, int *carpetOrdered)
{
    int i, lowest, index = 0;
    lowest = *carpetOrdered;

    for (i = 1; i<SIZE_ARRAY; i++)
    {
        if (*(carpetOrdered+i) < lowest)
        {
            lowest = *(carpetOrdered+i);

            index = i;
        }
    }
    printf("Lowest carpet ordered is %c with %i ordered\n\n", selections[index], lowest);

    return ;
}
// function that validates color choice regardless of case
// parameters include colors and carpetColors array with no return value
void getColorSelections (char *colors[], char carpetColors[])
{
    int i;
    bool isValid = false;

    do
    {
        printf("Enter a color: ");
        fgets(carpetColors, LENGTH_STRING, stdin);
        carpetColors[strlen(carpetColors) -1] = '\0';

        for (i = 0; i < SIZE_ARRAY; i++)
        {
            if(stricmp(carpetColors, colors[i])==0)
            {
                isValid = true;
                printf("Color selected!\n\n");
                break;
            }
        }

        if(isValid == false)
        {
            printf("Invalid color, please enter another color\n");
        }


    }
    while(isValid == false);

    return ;
}

/*
Test Data 1
carpet choice: a
10 feet
black ice
Color selected!
subtotal:81
tax: 5.67
total: 86.67
Would you like to order more carpet [y/n]y

carpet choice: a
20 feet
walnut
Color selected!
subtotal: 162
tax: 11.34
total: 173.34
Would you like to order more carpet [y/n]y

carpet choice: b
10 feet
sky grey
Color Selected!
subtotal: 40.80
tax: 2.86
total: 43.66
Would you like to order more carpet [y/n]y

carpet choice: c
20 feet
leaf green
Color selected!
subtotal: 211.20
tax: 14.78
total: 225.98
Would you like to order more carpet [y/n]y

carpet choice: c
11 feet
ocean blue
Color selected!
subtotal: 116.16
tax: 8.13
total: 124.29
Would you like to order more carpet [y/n]y

carpet choice: c
15 feet
walnut
Color selected!
subtotal: 158.40
tax: 11.09
total: 169.49
Would you like to order more carpet [y/n]y

carpet choice: d
10 feet
sky grey
Color selected!
subtotal: 106.80
tax: 7.48
total: 114.28
Would you like to order more carpet [y/n]y

carpet choice: d
20 feet
heather green
Color selected!
subtotal: 213.60
tax: 14.95
total: 228.55
Would you like to order more carpet [y/n]y

carpet choice: e
10 feet
burgundy
Color selected!
subtotal: 90
tax: 6.30
total: 96.30
Would you like to order more carpet [y/n]y

carpet choice: e
20 feet
walnut
Color selected!
subtotal: 180
tax: 12.60
total: 192.60
Would you like to order more carpet [y/n]y

carpet choice: f
10 feet
ocean blue
Color selected!
subtotal: 108
tax: 7.56
total: 115.56
Would you like to order more carpet [y/n]y

carpet choice: f
20 feet
sky grey
Color selected!
subtotal: 216
tax: 15.12
total: 231.12
Would you like to order more carpet [y/n]y

carpet choice: g
10 feet
walnut
Color selected!
subtotal: 111.60
tax: 7.81
total: 119.41
Would you like to order more carpet [y/n]y

carpet choice: g
20 feet
black ice
Color selected!
subtotal: 223.20
tax: 15.62
total: 238.82
Would you like to order more carpet [y/n]y

carpet choice: h
10 feet
leaf green
Color selected!
subtotal: 178.80
tax: 12.52
total: 191.32
Would you like to order more carpet [y/n]y

carpet choice: h
20 feet
walnut
Color selected!
subtotal: 357.60
tax: 25.03
total: 382.63
Would you like to order more carpet [y/n]n

Ordered carpet:
A=2
B=1
C=3
D=2
E=2
F=2
G=2
H=2
Total amount of carpet: 16
Max: carpet C with 3 ordered
Low: carpet B with 1 ordered

Results provided by Michael

Test Data 2
carpet choice: a
10 feet
black ic
"Please enter another color"
black ice
Color selected!
subtotal:81
tax: 5.67
total: 86.67
Would you like to order more carpet [y/n]n

Ordered carpet:
A=1
B=0
C=0
D=0
E=0
F=0
G=0
H=0
Total amount of carpet: 1
Max: carpet A with 1 ordered
Low: carpet B with 0 ordered

Results provided by Michael

Test Data 3
carpet choice: z
"Please enter valid option"

carpet choice: c
20 feet
walnutt
"Please enter valid color"
walnut
Color selected!
subtotal: 211.20
tax: 14.78
total: 225.98
Would you like to order more carpet [y/n]n

Ordered carpet:
A=0
B=0
C=1
D=0
E=0
F=0
G=0
H=0
Total amount of carpet: 1
Max: carpet C with 1 ordered
Low: carpet A with 0 ordered

Results provided by Michael
*/

/*
Sample run 1
Welcome to Michael's Flooring

Carpet choices:

A      6 ft      $8.10

B      6 ft      $4.08

C      12 ft      $10.56

D      12 ft      $10.68

E      12 ft      $9.00

F      12 ft      $10.80

G      12 ft      $11.16

H      12 ft      $17.88

Color choices:

Black ice
Burgundy
Heather green
Leaf green
Ocean blue
Sky grey
Stone beige
Walnut

Please select a carpet choice from A-H: a
Please enter the feet of the room: 10
Enter a color: black ice
Color selected!


Subtotal: $81.00
Tax: $5.67
Total: $86.67

Would you like to order more carpet? [y/n]y


Please select a carpet choice from A-H: a
Please enter the feet of the room: 20
Enter a color: walnut
Color selected!


Subtotal: $162.00
Tax: $11.34
Total: $173.34

Would you like to order more carpet? [y/n]y


Please select a carpet choice from A-H: b
Please enter the feet of the room: 10
Enter a color: sky grey
Color selected!


Subtotal: $40.80
Tax: $2.86
Total: $43.66

Would you like to order more carpet? [y/n]y


Please select a carpet choice from A-H: c
Please enter the feet of the room: 20
Enter a color: leaf green
Color selected!


Subtotal: $211.20
Tax: $14.78
Total: $225.98

Would you like to order more carpet? [y/n]y


Please select a carpet choice from A-H: c
Please enter the feet of the room: 11
Enter a color: ocean blue
Color selected!


Subtotal: $116.16
Tax: $8.13
Total: $124.29

Would you like to order more carpet? [y/n]y


Please select a carpet choice from A-H: c
Please enter the feet of the room: 15
Enter a color: walnut
Color selected!


Subtotal: $158.40
Tax: $11.09
Total: $169.49

Would you like to order more carpet? [y/n]y


Please select a carpet choice from A-H: d
Please enter the feet of the room: 10
Enter a color: sky grey
Color selected!


Subtotal: $106.80
Tax: $7.48
Total: $114.28

Would you like to order more carpet? [y/n]y


Please select a carpet choice from A-H: d
Please enter the feet of the room: 20
Enter a color: heather green
Color selected!


Subtotal: $213.60
Tax: $14.95
Total: $228.55

Would you like to order more carpet? [y/n]y


Please select a carpet choice from A-H: e
Please enter the feet of the room: 10
Enter a color: burgundy
Color selected!


Subtotal: $90.00
Tax: $6.30
Total: $96.30

Would you like to order more carpet? [y/n]y


Please select a carpet choice from A-H: e
Please enter the feet of the room: 20
Enter a color: walnut
Color selected!


Subtotal: $180.00
Tax: $12.60
Total: $192.60

Would you like to order more carpet? [y/n]y


Please select a carpet choice from A-H: f
Please enter the feet of the room: 10
Enter a color: ocean blue
Color selected!


Subtotal: $108.00
Tax: $7.56
Total: $115.56

Would you like to order more carpet? [y/n]y


Please select a carpet choice from A-H: f
Please enter the feet of the room: 20
Enter a color: sky grey
Color selected!


Subtotal: $216.00
Tax: $15.12
Total: $231.12

Would you like to order more carpet? [y/n]y


Please select a carpet choice from A-H: g
Please enter the feet of the room: 10
Enter a color: walnut
Color selected!


Subtotal: $111.60
Tax: $7.81
Total: $119.41

Would you like to order more carpet? [y/n]y


Please select a carpet choice from A-H: g
Please enter the feet of the room: 20
Enter a color: black ice
Color selected!


Subtotal: $223.20
Tax: $15.62
Total: $238.82

Would you like to order more carpet? [y/n]y


Please select a carpet choice from A-H: h
Please enter the feet of the room: 10
Enter a color: leaf green
Color selected!


Subtotal: $178.80
Tax: $12.52
Total: $191.32

Would you like to order more carpet? [y/n]y


Please select a carpet choice from A-H: h
Please enter the feet of the room: 20
Enter a color: walnut
Color selected!


Subtotal: $357.60
Tax: $25.03
Total: $382.63

Would you like to order more carpet? [y/n]n

Ordered carpet:
A = 2 times
B = 1 times
C = 3 times
D = 2 times
E = 2 times
F = 2 times
G = 2 times
H = 2 times

Total amount of carpet ordered: 16

Max carpet ordered is C with 3 ordered

Lowest carpet ordered is B with 1 ordered


Results provided by Michael


Process returned 0 (0x0)   execution time : 501.424 s
Press any key to continue.


Sample run 2
Welcome to Michael's Flooring

Carpet choices:

A      6 ft      $8.10

B      6 ft      $4.08

C      12 ft      $10.56

D      12 ft      $10.68

E      12 ft      $9.00

F      12 ft      $10.80

G      12 ft      $11.16

H      12 ft      $17.88

Color choices:

Black ice
Burgundy
Heather green
Leaf green
Ocean blue
Sky grey
Stone beige
Walnut

Please select a carpet choice from A-H: a
Please enter the feet of the room: 10
Enter a color: black ic
Invalid color, please enter another color
Enter a color: black ice
Color selected!


Subtotal: $81.00
Tax: $5.67
Total: $86.67

Would you like to order more carpet? [y/n]n

Ordered carpet:
A = 1 times
B = 0 times
C = 0 times
D = 0 times
E = 0 times
F = 0 times
G = 0 times
H = 0 times

Total amount of carpet ordered: 1

Max carpet ordered is A with 1 ordered

Lowest carpet ordered is B with 0 ordered


Results provided by Michael


Process returned 0 (0x0)   execution time : 36.090 s
Press any key to continue.


Sample run 3
Welcome to Michael's Flooring

Carpet choices:

A      6 ft      $8.10

B      6 ft      $4.08

C      12 ft      $10.56

D      12 ft      $10.68

E      12 ft      $9.00

F      12 ft      $10.80

G      12 ft      $11.16

H      12 ft      $17.88

Color choices:

Black ice
Burgundy
Heather green
Leaf green
Ocean blue
Sky grey
Stone beige
Walnut

Please select a carpet choice from A-H: z
Please enter valid carpet choice

Please select a carpet choice from A-H: c
Please enter the feet of the room: 20
Enter a color: walnutt
Invalid color, please enter another color
Enter a color: walnut
Color selected!


Subtotal: $211.20
Tax: $14.78
Total: $225.98

Would you like to order more carpet? [y/n]n

Ordered carpet:
A = 0 times
B = 0 times
C = 1 times
D = 0 times
E = 0 times
F = 0 times
G = 0 times
H = 0 times

Total amount of carpet ordered: 1

Max carpet ordered is C with 1 ordered

Lowest carpet ordered is A with 0 ordered


Results provided by Michael


Process returned 0 (0x0)   execution time : 57.196 s
Press any key to continue.

*/
