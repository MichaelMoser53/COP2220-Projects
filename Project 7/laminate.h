// Michael Moser
// COP 2220
// Project 7
// 04/20/2016

#ifndef LAMINATE_H_INCLUDED
#define LAMINATE_H_INCLUDED

#define LEN_DATA 80
#define SIZE_ARRAY 30
#define TAX .07
#define LEN_COLOR 30

// structure of laminate_t
typedef struct
{
    char color[LEN_COLOR];
    int thickness;
    double width, length, price;
} laminate_t;


// Prototypes
void displayWelcome (void);
void displayLaminateMenu (laminate_t *laminatePtr);
int getMainMenuChoice (void);
void displayColorOptions (laminate_t *laminatePtr);
void displayPrices (laminate_t laminates[], double priceSearch, int elements);
int getColorSelections (laminate_t laminates[], int elements);
void getOrders (laminate_t orders[], int colorIndex);
int sortColor( const void *x, const void *y);
int sortPrice( const void *x, const void *y);
void displayResults (void);
int openFile(laminate_t orders[]);
int getMaintMenuChoice(void);
void maintMenu (laminate_t orders[], int *count);
void addLaminateInformation (laminate_t orders[], int *count);
void saveChanges( laminate_t orders[], int count);
int selectLaminates(laminate_t orders[], int count);
void deleteLaminate(laminate_t orders[], int *count);
void modifyLaminate(laminate_t orders[], int count);



#endif // LAMINATE_H_INCLUDED
