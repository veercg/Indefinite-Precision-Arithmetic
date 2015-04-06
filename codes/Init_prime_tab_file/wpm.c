//**************** USE THIS PROGRAM TO INITIALISE PRIME_TAB.txt FILE**************************
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int i;
	char c1='2',c2='3',nl='\n';
	FILE *fp1=fopen("prime_tab.txt","a");
	putc(c1,fp1);
	putc(nl,fp1);
	putc(c2,fp1);
	putc(nl,fp1);
	fclose(fp1);
	return 0;
}
	
	
	
