#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Largeint.h>
int main(void)
{
	largeInt l1, l2,sum,diff,product;
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
	
	x=Isprime(l1);// CHECKING PRIME OR NOT !!
	if(x==1)
		printf("\nPRIME");
	else
		printf("\nNOT PRIME\n");
	
	
	return 0;
}	

