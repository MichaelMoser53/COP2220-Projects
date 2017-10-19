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

// Main function that opens .txt file in order to use information for other functions
// function with switch statement to cycle through options of the main menu based on user input
// bool variable used to stop switch statement and validate the input of the user
int main (void)
{

    int index = 0, elements = 10, count, choice, colorIndex;
    bool quit = false;
    laminate_t orders[SIZE_ARRAY] = {{ 0 }};
    double priceSearch;


    displayWelcome();
    count = openFile(orders);

// "for" loops used to run each function multiple times and display all information in .txt file
// switch case used to run appropriate functions based on user input and using boolean variable to exit loop.

    do
    {
    choice = getMainMenuChoice();
    switch(choice)
    {
    case 1:

        printf("*** Color / Thickness / Width / Length / Price ***\n\n");
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
            colorIndex = getColorSelections(&orders[index], elements);
            break;
        }

        break;

    case 3:
        printf("Please enter a price to search: ");
        scanf("%lf", &priceSearch);
        printf("\n");
        displayPrices(orders, priceSearch, count);

        break;

    case 4:
        printf("\n");
        for ( index = 0; index < count; index++)
        {
            displayColorOptions(&orders[index]);
        }

        for ( index = 0; index < count; index++)
        {
            colorIndex = getColorSelections(&orders[index], elements);
            break;
        }

        getOrders(orders, colorIndex);

        break;

    case 5:
        qsort( (void *)orders, count, sizeof(laminate_t), sortColor );

        printf("\nColors: A-Z\n\n");
        for ( index = 0; index < count; index++)
        {
            displayColorOptions(&orders[index]);
        }
        printf("\n");

        break;

    case 6:
        qsort( (void *)orders, count, sizeof(laminate_t), sortPrice );

        printf("\nPrices: LOW to HIGH\n\n");
        for ( index = 0; index < count; index++)
        {
            printf("$%.2lf\n", orders[index].price);
        }
        printf("\n");

        break;

    case 7:
        maintMenu(orders, &count);

        break;


    case 9:
        displayResults();
        quit = true;
        break;

    }

    } while(quit == false);
return 0;
}

/*
Sample run 1

Menu choice: 1
display all laminates

Menu choice: 2
search color: verm
*displays vermont maple information*

Menu choice: 3
search price: 2.49
*displays colors*
Coffee Handscraped Hickory
Highland Hickory
Southern Grey Oak
Haley Oak
Natural Ridge Hickory

Menu choice: 4
Enter color: vermont
length: 10
width: 15
subtotal: $388.5
tax: $27.20
total: $415.70

Menu choice: 5
*displays colors in alphabetical order*

Menu choice: 6
*displays prices from lowest to highest*

Menu choice: 1
*displays laminate information in order of prices*

Menu choice: 9
Exits program
__________________________________________
Sample run 2
Menu choice: 2
color search: oak
Riverbend Oak
Homestead Oak
Southern Gray Oak
Haley Oak
Sedona Oak

Menu choice: 7
*displays maintenance menu*

Maint menu choice: 1
Enter new color: gun metal grey
Enter thickness: 5
Enter width: 10
Enter length: 15
Enter Price: 2.50

Maint menu choice: 2
select laminate 12
change price(option 5)
Enter new price: 2.28

Maint menu choice: 9
*goes back to main menu*

Menu choice: 1
*displays all laminates with added grey laminate and price*

Menu choice: 2
search color: grey
*shows southern grey oak since file has not been saved to*

Menu choice: 9
Exits program
_______________________________________________________
Sample run 3

Menu choice: 7
*displays maint menu*

Maint menu: 1
black
10
10
10
3.50

maint menu: 3
*displays all laminates*
delete?: 1

Maint menu: 4
Saved to .txt file

maint menu: 9
exits maint menu

Main menu: 1
*shows all laminates with riverbend oak gone and black as last laminate*

Main menu choice: 9
Exits program
*/

/*
Sample reports 1
Welcome to Michael Moser's Laminate!

*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Sort Colors
6.) Sort Prices
7.) Maintenance Menu
9.) Exit

Menu Choice: 1
*** Color / Thickness / Width / Length / Price ***

Riverbend Oak - 10mm / 7.500in / 47.250in / $2.59

Coffee Handscraped Hickory - 10mm / 5.250in / 47.250in / $2.49

Highland Hickory - 10mm / 4.875in / 47.875in / $2.49

Homestead Oak - 10mm / 7.500in / 47.250in / $2.59

Southern Grey Oak - 10mm / 6.125in / 47.250in / $2.49

Haley Oak - 8mm / 7.500in / 47.250in / $2.29

Coffee Handscraped Hickory - 12mm / 5.250in / 47.250in / $2.69

Sedona Oak - 10mm / 7.625in / 47.625in / $2.59

Peruvian Mahogany - 10mm / 4.875in / 47.875in / $2.59

Vermont Maple - 10mm / 4.875in / 47.875in / $2.59

Natural Ridge Hickory - 10mm / 7.625in / 47.625in / $2.46

*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Sort Colors
6.) Sort Prices
7.) Maintenance Menu
9.) Exit

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

Enter a color: verm

        *** Colors available ***

        Color - Vermont Maple
        Thickness - 10mm
        Width - 4.875in
        Length - 47.875in
        Price - $2.59

*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Sort Colors
6.) Sort Prices
7.) Maintenance Menu
9.) Exit

Menu Choice: 3
Please enter a price to search: 2.49

        *** Colors in budget ***

        Coffee Handscraped Hickory - $2.49

        Highland Hickory - $2.49

        Southern Grey Oak - $2.49

        Haley Oak - $2.29

        Natural Ridge Hickory - $2.46

*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Sort Colors
6.) Sort Prices
7.) Maintenance Menu
9.) Exit

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

Enter a color: vermont

        *** Colors available ***

        Color - Vermont Maple
        Thickness - 10mm
        Width - 4.875in
        Length - 47.875in
        Price - $2.59

Enter length: 10
Enter width: 15


Subtotal: $388.50
Tax: $27.20
Total: $415.69

*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Sort Colors
6.) Sort Prices
7.) Maintenance Menu
9.) Exit

Menu Choice: 5

Colors: A-Z

Coffee Handscraped Hickory
Coffee Handscraped Hickory
Haley Oak
Highland Hickory
Homestead Oak
Natural Ridge Hickory
Peruvian Mahogany
Riverbend Oak
Sedona Oak
Southern Grey Oak
Vermont Maple

*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Sort Colors
6.) Sort Prices
7.) Maintenance Menu
9.) Exit

Menu Choice: 6

Prices: LOW to HIGH

$2.29
$2.46
$2.49
$2.49
$2.49
$2.59
$2.59
$2.59
$2.59
$2.59
$2.69

*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Sort Colors
6.) Sort Prices
7.) Maintenance Menu
9.) Exit

Menu Choice: 1
*** Color / Thickness / Width / Length / Price ***

Haley Oak - 8mm / 7.500in / 47.250in / $2.29

Natural Ridge Hickory - 10mm / 7.625in / 47.625in / $2.46

Southern Grey Oak - 10mm / 6.125in / 47.250in / $2.49

Highland Hickory - 10mm / 4.875in / 47.875in / $2.49

Coffee Handscraped Hickory - 10mm / 5.250in / 47.250in / $2.49

Peruvian Mahogany - 10mm / 4.875in / 47.875in / $2.59

Riverbend Oak - 10mm / 7.500in / 47.250in / $2.59

Sedona Oak - 10mm / 7.625in / 47.625in / $2.59

Vermont Maple - 10mm / 4.875in / 47.875in / $2.59

Homestead Oak - 10mm / 7.500in / 47.250in / $2.59

Coffee Handscraped Hickory - 12mm / 5.250in / 47.250in / $2.69

*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Sort Colors
6.) Sort Prices
7.) Maintenance Menu
9.) Exit

Menu Choice: 9

Results provided by Michael Moser's Laminate!

Thank you for shopping!

Process returned 0 (0x0)   execution time : 415.715 s
Press any key to continue.
____________________________________________
Sample reports 2
Welcome to Michael Moser's Laminate!

*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Sort Colors
6.) Sort Prices
7.) Maintenance Menu
9.) Exit

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

Enter a color: oak

        *** Colors available ***

        Color - Riverbend Oak
        Thickness - 10mm
        Width - 7.500in
        Length - 47.250in
        Price - $2.59

        Color - Homestead Oak
        Thickness - 10mm
        Width - 7.500in
        Length - 47.250in
        Price - $2.59

        Color - Southern Grey Oak
        Thickness - 10mm
        Width - 6.125in
        Length - 47.250in
        Price - $2.49

        Color - Haley Oak
        Thickness - 8mm
        Width - 7.500in
        Length - 47.250in
        Price - $2.29

        Color - Sedona Oak
        Thickness - 10mm
        Width - 7.625in
        Length - 47.625in
        Price - $2.59

*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Sort Colors
6.) Sort Prices
7.) Maintenance Menu
9.) Exit

Menu Choice: 7

*** Maintenance Menu ***
1.) Add Laminate Information
2.) Modify Laminate Information
3.) Delete Laminate Information
4.) Save Laminate Information
9.) Exit

Menu Choice: 1
Enter new color: gun metal grey
Enter color's Thickness: 5
Enter color's Width: 10
Enter color's Length: 15
Enter color's Price: 2.50

*** Maintenance Menu ***
1.) Add Laminate Information
2.) Modify Laminate Information
3.) Delete Laminate Information
4.) Save Laminate Information
9.) Exit

Menu Choice: 2
1.) Riverbend Oak - 10mm/7.50in/47.25in/$2.59

2.) Coffee Handscraped Hickory - 10mm/5.25in/47.25in/$2.49

3.) Highland Hickory - 10mm/4.88in/47.88in/$2.49

4.) Homestead Oak - 10mm/7.50in/47.25in/$2.59

5.) Southern Grey Oak - 10mm/6.13in/47.25in/$2.49

6.) Haley Oak - 8mm/7.50in/47.25in/$2.29

7.) Coffee Handscraped Hickory - 12mm/5.25in/47.25in/$2.69

8.) Sedona Oak - 10mm/7.63in/47.63in/$2.59

9.) Peruvian Mahogany - 10mm/4.88in/47.88in/$2.59

10.) Vermont Maple - 10mm/4.88in/47.88in/$2.59

11.) Natural Ridge Hickory - 10mm/7.63in/47.63in/$2.46

12.) gun metal grey - 5mm/10.00in/15.00in/$2.50

Please select laminate (1-12)12
1.) Change Color
2.) Change Thickness
3.) Change Width
4.) Change Length
5.) Change Price
Selection: 5
Enter new Price: 2.28

*** Maintenance Menu ***
1.) Add Laminate Information
2.) Modify Laminate Information
3.) Delete Laminate Information
4.) Save Laminate Information
9.) Exit

Menu Choice: 9
*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Sort Colors
6.) Sort Prices
7.) Maintenance Menu
9.) Exit

Menu Choice: 1
*** Color / Thickness / Width / Length / Price ***

Riverbend Oak - 10mm / 7.500in / 47.250in / $2.59

Coffee Handscraped Hickory - 10mm / 5.250in / 47.250in / $2.49

Highland Hickory - 10mm / 4.875in / 47.875in / $2.49

Homestead Oak - 10mm / 7.500in / 47.250in / $2.59

Southern Grey Oak - 10mm / 6.125in / 47.250in / $2.49

Haley Oak - 8mm / 7.500in / 47.250in / $2.29

Coffee Handscraped Hickory - 12mm / 5.250in / 47.250in / $2.69

Sedona Oak - 10mm / 7.625in / 47.625in / $2.59

Peruvian Mahogany - 10mm / 4.875in / 47.875in / $2.59

Vermont Maple - 10mm / 4.875in / 47.875in / $2.59

Natural Ridge Hickory - 10mm / 7.625in / 47.625in / $2.46

gun metal grey - 5mm / 10.000in / 15.000in / $2.28

*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Sort Colors
6.) Sort Prices
7.) Maintenance Menu
9.) Exit

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
gun metal grey

Enter a color: grey

        *** Colors available ***

        Color - Southern Grey Oak
        Thickness - 10mm
        Width - 6.125in
        Length - 47.250in
        Price - $2.49

*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Sort Colors
6.) Sort Prices
7.) Maintenance Menu
9.) Exit

Menu Choice: 9

Results provided by Michael Moser's Laminate!

Thank you for shopping!

Process returned 0 (0x0)   execution time : 371.309 s
Press any key to continue.
_________________________________________________________
Sample reports 3

Welcome to Michael Moser's Laminate!

*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Sort Colors
6.) Sort Prices
7.) Maintenance Menu
9.) Exit

Menu Choice: 7

*** Maintenance Menu ***
1.) Add Laminate Information
2.) Modify Laminate Information
3.) Delete Laminate Information
4.) Save Laminate Information
9.) Exit

Menu Choice: 1
Enter new color: black
Enter color's Thickness: 10
Enter color's Width: 10
Enter color's Length: 10
Enter color's Price: 3.50

*** Maintenance Menu ***
1.) Add Laminate Information
2.) Modify Laminate Information
3.) Delete Laminate Information
4.) Save Laminate Information
9.) Exit

Menu Choice: 3
1.) Riverbend Oak - 10mm/7.50in/47.25in/$2.59

2.) Coffee Handscraped Hickory - 10mm/5.25in/47.25in/$2.49

3.) Highland Hickory - 10mm/4.88in/47.88in/$2.49

4.) Homestead Oak - 10mm/7.50in/47.25in/$2.59

5.) Southern Grey Oak - 10mm/6.13in/47.25in/$2.49

6.) Haley Oak - 8mm/7.50in/47.25in/$2.29

7.) Coffee Handscraped Hickory - 12mm/5.25in/47.25in/$2.69

8.) Sedona Oak - 10mm/7.63in/47.63in/$2.59

9.) Peruvian Mahogany - 10mm/4.88in/47.88in/$2.59

10.) Vermont Maple - 10mm/4.88in/47.88in/$2.59

11.) Natural Ridge Hickory - 10mm/7.63in/47.63in/$2.46

12.) black - 10mm/10.00in/10.00in/$3.50

Please select laminate (1-12)1

*** Maintenance Menu ***
1.) Add Laminate Information
2.) Modify Laminate Information
3.) Delete Laminate Information
4.) Save Laminate Information
9.) Exit

Menu Choice: 4
File has been saved!


*** Maintenance Menu ***
1.) Add Laminate Information
2.) Modify Laminate Information
3.) Delete Laminate Information
4.) Save Laminate Information
9.) Exit

Menu Choice: 9
*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Sort Colors
6.) Sort Prices
7.) Maintenance Menu
9.) Exit

Menu Choice: 1
*** Color / Thickness / Width / Length / Price ***

Coffee Handscraped Hickory - 10mm / 5.250in / 47.250in / $2.49

Highland Hickory - 10mm / 4.875in / 47.875in / $2.49

Homestead Oak - 10mm / 7.500in / 47.250in / $2.59

Southern Grey Oak - 10mm / 6.125in / 47.250in / $2.49

Haley Oak - 8mm / 7.500in / 47.250in / $2.29

Coffee Handscraped Hickory - 12mm / 5.250in / 47.250in / $2.69

Sedona Oak - 10mm / 7.625in / 47.625in / $2.59

Peruvian Mahogany - 10mm / 4.875in / 47.875in / $2.59

Vermont Maple - 10mm / 4.875in / 47.875in / $2.59

Natural Ridge Hickory - 10mm / 7.625in / 47.625in / $2.46

black - 10mm / 10.000in / 10.000in / $3.50

*** Main Menu ***
1.) Display all laminates
2.) Search by color
3.) Search by price
4.) Place an order
5.) Sort Colors
6.) Sort Prices
7.) Maintenance Menu
9.) Exit

Menu Choice: 9

Results provided by Michael Moser's Laminate!

Thank you for shopping!

Process returned 0 (0x0)   execution time : 194.021 s
Press any key to continue.

*/
