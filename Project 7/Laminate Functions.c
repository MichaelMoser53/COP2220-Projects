// Michael Moser
// COP 2220
// Project 7
// 04/20/2016

// Function libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "laminate.h"


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

    printf("%s - %imm / %.3lfin / %.3lfin / $%.2lf\n\n", laminatePtr->color, laminatePtr->thickness,
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
           "5.) Sort Colors\n"
           "6.) Sort Prices\n"
           "7.) Maintenance Menu\n"
           "9.) Exit\n");
    printf("\nMenu Choice: ");
    scanf("%i", &choice);
    if (choice > 9)
    {
        printf("Please enter a valid menu option\n\n");
    }

    return choice;
}

// displays color from structure. no return value with a pointer to laminate_t structure as the parameter
void displayColorOptions (laminate_t *laminatePtr)
{
    printf("%s\n", laminatePtr->color);

    return;
}

// displays all prices from array of laminate structure. no return with the "orders" array, priceSearch, and elements as parameters
void displayPrices (laminate_t orders[], double priceSearch, int elements)
{
    int i;

printf("\t*** Colors in budget ***\n\n");
    for (i = 0; i < elements; i++)
    {
        if(priceSearch >= orders[i].price)
        {
            printf("\t%s - $%.2lf\n\n", orders[i].color, orders[i].price);
        }
    }

    return;
}

// function with variables to calculate order information.
// no return value with the "orders" array and colorIndex as parameters
// "do-while" loop used to validate input from user for length and width
void getOrders (laminate_t orders[], int colorIndex)
{
    double length, width, area;
    double subtotal, total, taxAmount;

    do{
        printf("Enter length: ");
        scanf("%lf", &length);

        if(length <= 0)
        {
            printf("Please enter a positive value for length\n\n");
        }

    }while(length <= 0);

        do{
        printf("Enter width: ");
        scanf("%lf", &width);

        if(width <= 0)
        {
            printf("Please enter a positive value for width\n\n");
        }

    }while(width <= 0);

    area = length * width;
    subtotal = area * orders[colorIndex].price;
    taxAmount = subtotal * TAX;
    total = taxAmount + subtotal;

    printf("\n\nSubtotal: $%.2lf\n", subtotal);
    printf("Tax: $%.2lf\n", taxAmount);
    printf("Total: $%.2lf\n\n", total);

    return;
}

// function that asks for user input for color choice to compare entered string to array in structure for match of the color
// return value for colorIndex, parameters include the structure "laminate_t", orderColors array, and elements.
int getColorSelections (laminate_t laminates[], int elements)
{
    int i, colorIndex;
    bool isValid = false;
    char orderColors[LEN_COLOR];
    char choiceString[SIZE_ARRAY];

    do
    {

        printf("\nEnter a color: ");
        fflush(stdin);
        fgets(orderColors, LEN_COLOR, stdin);
        orderColors[strlen(orderColors) - 1] = '\0';

        printf("\n\t*** Colors available ***\n\n");
        for (i = 0; i < elements; i++)
        {
            strcpy(choiceString, laminates[i].color);

            if(strstr(strupr(choiceString), strupr(orderColors)) != NULL)
            {
                isValid = true;
                colorIndex = i;
                printf("\tColor - %s\n\tThickness - %imm\n\tWidth - %.3lfin\n\tLength - %.3lfin\n\tPrice - $%.2lf\n\n"
                ,laminates[i].color, laminates[i].thickness,laminates[i].width, laminates[i].length, laminates[i].price);
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

// function that compares strings in the structure to sort alphabetically
// function will return the string in order, paramters include pointers of variable x and y
int sortColor( const void *x, const void *y)
{
    /* Note 8 */
    return ( strcmp( ((laminate_t * )x)->color, ((laminate_t * )y)->color ));
}

// function will sort prices in structure from lowest to highest
// return values are -1, 1, and 0, paramters include pointers of variable x and y
int sortPrice( const void *x, const void *y)
{
    /* Note 7 */
    if ( ((laminate_t * )x)->price < ( (laminate_t * )y)->price )
        return -1;
    else if ( ((laminate_t *)x)->price > ((laminate_t *)y)-> price )
        return 1;
    else
        return 0;
}

// screen prompt for results message with no parameters or return value
void displayResults (void)
{
    printf("\nResults provided by Michael Moser's Laminate!\n\n");
    printf("Thank you for shopping!\n");

    return;
}

// function that allows the "PergoLaminate.txt" file to be read and used within the program
// function will return variable count, parameters include the structure orders array
int openFile(laminate_t orders[])
{
    FILE * fptr;
    char line[LEN_DATA];
    int index = 0, count;
    char *startPtr, *endPtr;

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
            endPtr = strchr( startPtr, '\n');
            orders[index].price = atof(startPtr);


            index++;
        }
        fclose (fptr);

        count = index;
    }
    return count;
}

