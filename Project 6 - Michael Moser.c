// Michael Moser
// COP 2220
// Project 6
// 04/06/2016

// Functions libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// global variables
#define LEN_DATA 80
#define SIZE_ARRAY 30
#define TAX .07

// structure of laminate_t
typedef struct
{
    char color[SIZE_ARRAY];
    int thickness;
    double width, length, price;
} laminate_t;

// Prototypes
void displayWelcome (void);
void displayLaminateMenu (laminate_t *laminatePtr);
int getMainMenuChoice (void);
void displayColorOptions (laminate_t *laminatePtr);
void displayPrices (laminate_t laminates[], double priceSearch, int elements);
int getColorSelections (laminate_t laminates[], char orderColors[], int elements);
void getOrders (laminate_t orders[], int colorIndex);
void displayResults (void);

// Main function that opens .txt file in order to use information for other functions
// function with switch statement to cycle through options of the main menu based on user input
// bool variable used to stop switch statement and validate the input of the user
int main (void)
{
    FILE * fptr;
    char line[LEN_DATA];
    int index = 0, elements = 10, count, choice, colorIndex;
    char * ptr, *startPtr, *endPtr;
    bool quit = false;
    laminate_t orders[SIZE_ARRAY] = {{ 0 }};
    char orderColors[SIZE_ARRAY];
    double priceSearch;


    displayWelcome();
    fptr = fopen ("PergoLaminate.txt", "r");

    if (fptr == NULL)
    {
        printf("Unable to open file for read\n");
    }
    else
    {
        while(index < SIZE_ARRAY && fgets( line, sizeof( line), fptr))
        {
            startPtr = line;
            endPtr = strchr( startPtr, '|');
            strncpy(orders[index].color, startPtr, endPtr - startPtr);


            startPtr = endPtr + 1;
            endPtr = strchr( startPtr, '|');
            orders[index].thickness = atoi(startPtr);

            startPtr = endPtr + 1;
            endPtr = strchr( startPtr, '|');
            orders[index].width = atof(startPtr);

            startPtr = endPtr + 1;
            endPtr = strchr( startPtr, '|');
            orders[index].length = atof(startPtr);

            startPtr = endPtr + 1;
            endPtr = strchr( startPtr, '|');
            orders[index].price = atof(startPtr);


            index++;
        }
        fclose (fptr);

        count = index;

// "for" loops used to run each function multiple times and display all information in .txt file
// switch case used to run appropriate functions based on user input and using boolean variable to exit loop.
    }
    do
    {
    choice = getMainMenuChoice();
    switch(choice)
    {
    case 1:

    printf("*** Color/Thickness/Width/Length/Price ***\n\n");
    for ( index = 0; index < count; index++)
        {
            displayLaminateMenu(&orders[index]);
        }
        break;

    case 2:
        printf("\n");
        for ( index = 0; index < count; index++)
        {
            displayColorOptions(&orders[index]);
        }

        for ( index = 0; index < count; index++)
        {
            colorIndex = getColorSelections(&orders[index], orderColors, elements);
            break;
        }

        break;

    case 3:
        printf("Please enter a price to search: ");
        scanf("%lf", &priceSearch);
        printf("\n");
        displayPrices(orders, priceSearch, elements);

        break;

    case 4:
        printf("\n");
        for ( index = 0; index < count; index++)
        {
            displayColorOptions(&orders[index]);
        }

        for ( index = 0; index < count; index++)
        {
            colorIndex = getColorSelections(&orders[index], orderColors, elements);
            break;
        }

        getOrders(orders, colorIndex);

        break;

    case 5:
        displayResults();
        quit = true;
        break;

    default:
        printf("Please choose a menu option 1-5.\n\n");

    }

    } while(quit == false);
return 0;
}

// screen prompt of welcome message. No return value or parameters.
void displayWelcome (void)
{
    printf("Welcome to Michael Moser's Laminate!\n\n");
    return;
}

// screen prompt to display all laminate information in .txt file using pointer notation
// No return value with a parameter of a pointer towards the structure
void displayLaminateMenu (laminate_t *laminatePtr)
{

    printf("%s - %imm/%.2lfin/%.2lfin/$%.2lf\n\n", laminatePtr->color, laminatePtr->thickness,
           laminatePtr->width, laminatePtr->length, laminatePtr->price);

    return;
}

// function that displays the main menu choices and asks user for input for choice variable
// no parameters with a return of the choice variable back to the main function to use in the switch statement
int getMainMenuChoice (void)
{
    int choice;
    printf("*** Main Menu ***\n");
    printf("1.) Display all laminates\n"
           "2.) Search by color\n"
           "3.) Search by price\n"
           "4.) Place an order\n"
           "5.) Exit program\n");
    printf("\nMenu Choice: ");
    scanf("%i", &choice);

    return choice;
}

// displays all colors from file. no return value with a pointer to laminate_t structure as the parameter
void displayColorOptions (laminate_t *laminatePtr)
{
    printf("%s\n", laminatePtr->color);

    return;
}

// displays all prices from file. no return with the "orders" array, priceSearch, and elements as parameters
void displayPrices (laminate_t orders[], double priceSearch, int elements)
{
    int i;

    for (i = 0; i < elements; i++)
        {
            if(priceSearch >= orders[i].price)
            {
                printf("%s\n\n", orders[i].color);
            }
        }

    return;
}

// function with variables to calculate order information.
// no return value with the "orders" array and colorIndex as parameters
// "do-while" loop used to validate input from user for length and width
void getOrders (laminate_t orders[], int colorIndex)
{
    int length, width, area;
    double subtotal, total, taxAmount, price;

    do{
        printf("Enter length: ");
        scanf("%i", &length);

        if(length > 0)
        {
            break;
        }
        else
        {
            printf("Please enter a positive value\n");
        }

    }while(length < 0);

        do{
        printf("Enter width: ");
        scanf("%i", &width);

        if(width>0)
        {
            break;
        }
        else
        {
            printf("Please enter a positive value\n");
        }

    }while(width < 0);

    area = length * width;
    subtotal = area * orders[colorIndex].price;
    taxAmount = subtotal * TAX;
    total = taxAmount + subtotal;

    printf("Subtotal: $%.2lf\n", subtotal);
    printf("Tax: $%.2lf\n", taxAmount);
    printf("Total: $%.2lf\n\n", total);

    return;
}

// function that asks for user input for color choice to compare entered string to array in structure for match of the color
// return value for colorIndex, parameters include the structure "laminate_t", orderColors array, and elements.
int getColorSelections (laminate_t laminates[], char orderColors[], int elements)
{
    int i, colorIndex;
    bool isValid = false;

    do
    {

        printf("\nEnter a color: ");
        fflush(stdin);
        fgets(orderColors, SIZE_ARRAY, stdin);
        orderColors[strlen(orderColors) -1] = '\0';

        for (i = 0; i < elements; i++)
        {
            if(stricmp(orderColors, laminates[i].color)==0)
            {
                isValid = true;
                colorIndex = i;
                printf("Color available!\n\n");
                printf("Thickness - %imm\nWidth - %.3lfin\nLength - %.3lfin\nPrice - $%.2lf\n\n", laminates[i].thickness,
                laminates[i].width, laminates[i].length, laminates[i].price);
                break;
            }
        }

        if(isValid == false)
        {
            printf("Color not in stock, please select another\n");
        }


    }
    while(isValid == false);

    return colorIndex;
}
// screen prompt for results message with no parameters or return value
void displayResults (void)
{
    printf("\nResults provided by Michael Moser's Laminate!\n\n");
    printf("Thank you for shopping!\n");

    return;
}

/*
Sample run
Menu Choice 1
*Display laminate information*

Menu choice 2
*Display all colors*
Enter a color - vermont maple
*displays laminate information*

Menu choice 3
Enter a price to search: 3.00
*displays all laminates under that price*

Menu choice 4
*Displays all colors*
Enter a color - haley oak
*Displays laminate information*
Length: 10
Width: 5

Subtotal:$114.50
Tax:$8.02
Total:$122.52

Menu choice 5
*display results message*
"Thank you for shopping!"
*/

/*
Sample report 1
Welcome to Michael Moser's Laminate!

*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Exit program

Menu Choice: 1
*** Color/Thickness/Width/Length/Price ***

Riverbend Oak - 10mm/7.50in/47.25in/$2.59

Coffee Handscraped Hickory - 10mm/5.25in/47.25in/$2.49

Highland Hickory - 10mm/4.88in/47.88in/$2.49

Homestead Oak - 10mm/7.50in/47.25in/$2.59

Southern Grey Oak - 10mm/6.13in/47.25in/$2.49

Haley Oak - 8mm/7.50in/47.25in/$2.29

Coffee Handscraped Hickory - 12mm/5.25in/47.25in/$2.69

Sedona Oak - 10mm/7.63in/47.63in/$2.59

Peruvian Mahogany - 10mm/4.88in/47.88in/$2.59

Vermont Maple - 10mm/4.88in/47.88in/$2.59

Natural Ridge Hickory - 10mm/7.63in/47.63in/$2.46

*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Exit program

Menu Choice: 2

Riverbend Oak
Coffee Handscraped Hickory
Highland Hickory
Homestead Oak
Southern Grey Oak
Haley Oak
Coffee Handscraped Hickory
Sedona Oak
Peruvian Mahogany
Vermont Maple
Natural Ridge Hickory

Enter a color: vermont maple
Color available!

Thickness - 10mm
Width - 4.875in
Length - 47.875in
Price - $2.59

*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Exit program

Menu Choice: 3
Please enter a price to search: 3.00

Riverbend Oak

Coffee Handscraped Hickory

Highland Hickory

Homestead Oak

Southern Grey Oak

Haley Oak

Coffee Handscraped Hickory

Sedona Oak

Peruvian Mahogany

Vermont Maple

*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Exit program

Menu Choice: 4

Riverbend Oak
Coffee Handscraped Hickory
Highland Hickory
Homestead Oak
Southern Grey Oak
Haley Oak
Coffee Handscraped Hickory
Sedona Oak
Peruvian Mahogany
Vermont Maple
Natural Ridge Hickory

Enter a color: haley oak
Color available!

Thickness - 8mm
Width - 7.500in
Length - 47.250in
Price - $2.29

Enter length: 10
Enter width: 5
Subtotal: $114.50
Tax: $8.02
Total: $122.52

*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Exit program

Menu Choice: 5

Results provided by Michael Moser's Laminate!

Thank you for shopping!

Process returned 0 (0x0)   execution time : 42.639 s
Press any key to continue.

Sample report 2
Welcome to Michael Moser's Laminate!

*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Exit program

Menu Choice: 1
*** Color/Thickness/Width/Length/Price ***

Riverbend Oak - 10mm/7.50in/47.25in/$2.59

Coffee Handscraped Hickory - 10mm/5.25in/47.25in/$2.49

Highland Hickory - 10mm/4.88in/47.88in/$2.49

Homestead Oak - 10mm/7.50in/47.25in/$2.59

Southern Grey Oak - 10mm/6.13in/47.25in/$2.49

Haley Oak - 8mm/7.50in/47.25in/$2.29

Coffee Handscraped Hickory - 12mm/5.25in/47.25in/$2.69

Sedona Oak - 10mm/7.63in/47.63in/$2.59

Peruvian Mahogany - 10mm/4.88in/47.88in/$2.59

Vermont Maple - 10mm/4.88in/47.88in/$2.59

Natural Ridge Hickory - 10mm/7.63in/47.63in/$2.46

*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Exit program

Menu Choice: 2

Riverbend Oak
Coffee Handscraped Hickory
Highland Hickory
Homestead Oak
Southern Grey Oak
Haley Oak
Coffee Handscraped Hickory
Sedona Oak
Peruvian Mahogany
Vermont Maple
Natural Ridge Hickory

Enter a color: sedona oak
Color available!

Thickness - 10mm
Width - 7.625in
Length - 47.625in
Price - $2.59

*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Exit program

Menu Choice: 3
Please enter a price to search: 2.49

Coffee Handscraped Hickory

Highland Hickory

Southern Grey Oak

Haley Oak

*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Exit program

Menu Choice: 4

Riverbend Oak
Coffee Handscraped Hickory
Highland Hickory
Homestead Oak
Southern Grey Oak
Haley Oak
Coffee Handscraped Hickory
Sedona Oak
Peruvian Mahogany
Vermont Maple
Natural Ridge Hickory

Enter a color: highland hickory
Color available!

Thickness - 10mm
Width - 4.875in
Length - 47.875in
Price - $2.49

Enter length: 20
Enter width: 10
Subtotal: $498.00
Tax: $34.86
Total: $532.86

*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Exit program

Menu Choice: 5

Results provided by Michael Moser's Laminate!

Thank you for shopping!

Process returned 0 (0x0)   execution time : 87.270 s
Press any key to continue.
*/
