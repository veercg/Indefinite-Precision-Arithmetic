#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Largeint.h>
int main(void)
{
	largeInt l1, l2,l3,sum,diff,product;
	div_result divi;
	int x;
	
	printf("Enter 1st number:");
	readint(&l1);
	printf("Enter 2nd number:");
	readint(&l2);

	printf("\nThe 1st number is :\n");
	showI(l1);
	printf("\n");
	printf("\nThe 2nd number is :\n");
	showI(l2);
	printf("\n");
	
	sum=addl(l1,l2); // Addition..
	printf("\n\nSum=");
	showI(sum);
	
	diff=subl(l1,l2);//SUBSTRACTION
	printf("\n\nDifference=");
	showI(diff);
	
	product=multl(l1,l2);//MULTIPLICATION
	printf("\n\nproduct=");
	showI(product);
	
	printf("\n\n");

	divi=divl(l1,l2);//DIVISION
	showDiv(divi);
	
	printf("\nmodulus of 1st and 2nd number:");
	showI(modl(l1,l2));
	
	printf("\nEnter a number to check prime or not:");
	readint(&l3);
	x=Isprime(l3);// CHECKING PRIME OR NOT !!
	showI(l3);	
	if(x==1)
		printf(" is PRIME\n");
	else
		printf(" is NOT PRIME\n");
	
	
	return 0;
}	

