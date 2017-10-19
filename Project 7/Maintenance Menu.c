// Michael Moser
// COP 2220
// Project 7
// 04/20/2016

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "laminate.h"

// function uses switch statement for choices in the maintenance menu for each option
// no return value and orders array and pointer for variable count used as parameters
void maintMenu (laminate_t orders[], int *count)
{

bool maintQuit = false;


    do
    {
    int maintChoice = 0;
    maintChoice = getMaintMenuChoice();

    switch(maintChoice)
    {
    case 1:
        addLaminateInformation(orders, count);

        break;

    case 2:
        modifyLaminate(orders, *count);

        break;

    case 3:
        deleteLaminate(orders, count);

        break;

    case 4:
        saveChanges(orders, *count);

        break;

    case 9:
        maintQuit = true;

        break;


    }

    } while(maintQuit == false);

}

// function used to display and get the user input for the maintenance menu
// return value for maintChoice to be used in switch statement and no parameters
int getMaintMenuChoice(void)
{
int maintChoice;

printf("\n*** Maintenance Menu ***\n");
    printf("1.) Add Laminate Information\n"
           "2.) Modify Laminate Information\n"
           "3.) Delete Laminate Information\n"
           "4.) Save Laminate Information\n"
           "9.) Exit\n");

    printf("\nMenu Choice: ");
    scanf("%i", &maintChoice);

    return maintChoice;
}

// function allows user to add information to structure orders array with prompts for each variable
// no return value, orders array and pointer to count as parameters
void addLaminateInformation (laminate_t orders[], int *count)
{
    int userThickness;
    double userWidth, userLength, userPrice;

    printf("Enter new color: ");
    fflush(stdin);
    fgets(orders[*count].color, LEN_DATA, stdin);
    orders[*count].color[strlen(orders[*count].color) - 1] = '\0';

    printf("Enter color's Thickness: ");
    scanf("%i", &userThickness);
    orders[*count].thickness = userThickness;

    printf("Enter color's Width: ");
    scanf("%lf", &userWidth);
    orders[*count].width = userWidth;

    printf("Enter color's Length: ");
    scanf("%lf", &userLength);
    orders[*count].length = userLength;

    printf("Enter color's Price: ");
    scanf("%lf", &userPrice);
    orders[*count].price = userPrice;

    (*count)++;


    return;
}

// function lets user select options to change of a already existing laminate and it's information
// no return value, orders array and count used as parameters
void modifyLaminate(laminate_t orders[], int count)
{

    int selection, userThickness, selectedLaminateIndex;
    double userWidth, userLength, userPrice;

    selectedLaminateIndex = selectLaminates(orders, count);

    printf("1.) Change Color\n"
           "2.) Change Thickness\n"
           "3.) Change Width\n"
           "4.) Change Length\n"
           "5.) Change Price\n"
           "Selection: ");
           scanf("\n%i", &selection);

    switch(selection)
    {

       case 1:
            printf("Enter a new color: ");
            fflush(stdin);
            fgets(orders[selectedLaminateIndex - 1].color, LEN_DATA, stdin);
            orders[selectedLaminateIndex - 1].color[strlen(orders[selectedLaminateIndex - 1].color) - 1] = '\0';
            break;
       case 2:
            printf("Enter new Thickness: ");
            scanf("%i", &userThickness);
            orders[selectedLaminateIndex - 1].thickness = userThickness;
            break;
        case 3:
            printf("Enter new width: ");
            scanf("%lf", &userWidth);
            orders[selectedLaminateIndex - 1].width = userWidth;
            break;
        case 4:
            printf("Enter new Length: ");
            scanf("%lf", &userLength);
            orders[selectedLaminateIndex - 1].length = userLength;
            break;
        case 5:
            printf("Enter new Price: ");
            scanf("%lf", &userPrice);
            orders[selectedLaminateIndex - 1].price = userPrice;
            break;

    }



}

// function lets user delete already existing laminate information
// no return value, orders array and pointer to count used as parameters
void deleteLaminate(laminate_t orders[],int *count)
{
    int choice = selectLaminates(orders, *count) - 1;

    while(choice < *count)
    {
        strcpy(orders[choice].color, orders[choice + 1].color);
        orders[choice].thickness = orders[choice + 1].thickness;
        orders[choice].width = orders[choice + 1].width;
        orders[choice].length = orders[choice + 1].length;
        orders[choice].price = orders[choice + 1].price;
        choice ++;
    }


    (*count)--;




}

// function lets the user save modified information to original .txt file based on changes they made
// no return value, orders array and count as parameters
void saveChanges( laminate_t orders[], int count)
{
    int index = 0;

    FILE * fptr;
    fptr = fopen ( "PergoLaminate.txt", "w");

    while( index < count)
    {
        fprintf(fptr, "%s", orders[index].color);
        fprintf(fptr, "%|");
        fprintf(fptr, "%i", orders[index].thickness);
        fprintf(fptr, "%|");
        fprintf(fptr, "%.2lf", orders[index].width);
        fprintf(fptr, "%|");
        fprintf(fptr, "%.2lf", orders[index].length);
        fprintf(fptr, "%|");
        fprintf(fptr, "%.2lf\n", orders[index].price);

        index++;
    }
    printf("File has been saved!\n\n");
    fclose( fptr );

    return;
}

// function that is used to display all laminates in the orders array and ask the user for input of the laminate to be selected
// function is returning choice variable, orders array and count as parameters
int selectLaminates(laminate_t orders[], int count)
{
    int choice, i = 0;
    while(i < count)
    {
    printf("%i.) %s - %imm/%.2lfin/%.2lfin/$%.2lf\n\n", i+1, orders[i].color, orders[i].thickness,
           orders[i].width, orders[i].length, orders[i].price);
    i++;
    }


        printf("Please select laminate (1-%i)", i);
        scanf("\n%i", &choice);


    return choice;

}
