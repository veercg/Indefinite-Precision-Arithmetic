#ifndef __LARGEINT_H
#define __LARGEINT_H
#include <math.h>
#define SIZE 100

typedef struct lt
{
	int len;
	int sign;
	char line[SIZE];
} largeInt;	
typedef struct ln
{
	int len;
	int sign;
	int line[SIZE];
} largeNum;
typedef struct divd
{
	largeNum quot;
	largeNum rem;
}div_result;

FILE *fp;

// *****(A)***BASIC INPUT/OUTPUT FUNCTIONS**(A)********
void readint(largeInt *); //TO READ INPUT FROM THE USER AND STORING THE NO. AS 'largeInt' type
void showI(largeInt); // FOR OUTPUTTING 'largeInt' TYPE NO.S
void showN(largeNum); // FOR OUTPUTTING 'largeNum' TYPE NO.S
void showDiv(div_result ); //FOR OUTPUTTING DIVISION RESULT (QUOTIENT AND REMAINDER)



//******(B)***FUNCTIONS FOR CONVERTING ONE TYPE TO ANOTHER**(B)**********
void IntToNum(largeInt, largeNum*); //FOR CONVERTING 'largeInt' TYPE TO 'largeNum' TYPE NO.
void NumToInt( largeNum ,largeInt *);//FOR CONVERTING 'largeNum' TYPE TO 'largeInt' TYPE NO.



//******(C)***FUNCTIONS FOR DOING SPECIFIC (NOT-ARITHMETIC) OPERATIONS**(C)*********
//void init(largeNum *, int);
void shift(largeNum *,int);// FOR RIGHT AND LEFT SHIFT OPERATIONS(for +ve n , Right shift occurs,and n zeros are added to the left. & for -ve n , Left shift occurs)
void append_n_zeros_right(largeNum *,int); //FOR APPENDING n ZEROS TO THE RIGHT AND INCREASING ITS LENGTH OBVIOUSLY
void remove_one_zero_right(largeNum * );  // FOR REMOVING ONE ZERO FROM RIGHT OF THE NO.
void rem_all_zeros_from_left(largeNum *); // FOR REMOVING ALL ZEROS FROM LEFT



//***********(D)***FUNCTIONS FOR LOGICAL OPERATIONS***********************
int greaterthan(largeInt,largeInt);//FOR COMPARISON BETWEEN TWO 'largeInt' type no.s
int Ngreaterthan(largeNum,largeNum);// FOR COMPARISON BETWEEN TWO 'largeNum' type no.s And returns 1(if abs(1st parameter) >= abs(2nd parameter),otherwise 						returns 0
int equal_to_zero(largeInt);// FOR CHECKING IF EQUAL TO ZERO OR NOT [returns 1 ,if a1=0, otherwise returns 0;]
int Nequal_to_zero(largeNum);

int chk_equal(largeInt ,largeInt ); // For checking if both the arguements are equal or not.. 


//*******(E)***ADDITIONAL FUNCTIONS REQUIRED FOR ARITHMETIC OPERATIONS**********
largeNum add_pos(largeNum , largeNum );// FOR ADDING ONLY TWO  POSITIVE INTEGERS
largeNum add_n_times(largeNum ,int);  //  For ADDING 1st ARGUMENT n(2ND ARGUMENT) TIMES..
div_result divs(largeNum, largeNum);  // REQUIRED FOR "divl() function" 


//*******(F)***FUNCTIONS FOR ARITHMETIC OPERATIONS******************* 
largeInt absl(largeInt);// FOR ABSOLUTE VALUE 
largeNum Nabsl(largeNum);

largeInt subl(largeInt , largeInt );// SUBSTRACTION
largeNum Nsubl(largeNum, largeNum);

largeInt addl(largeInt, largeInt);// ADDITION
largeInt multl(largeInt, largeInt);// MULTIPLICATION
div_result divl(largeInt, largeInt);// DIVISION OPERATION
largeInt modl(largeInt, largeInt);// MODULOUS OPERATION


//********(G)***FUNCTIONS FOR FILE OPERATIONS*****************
void fwriteI(largeInt ,FILE *); // FOR WRITING ONE "largeInt" type NO. INTO THE FILE
largeInt freadI(FILE *); // FOR READING ONE "largeInt" 
largeInt increment1(largeInt );
#endif
