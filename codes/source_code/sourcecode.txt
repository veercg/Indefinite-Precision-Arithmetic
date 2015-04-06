#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int Isprime(largeInt ); // return 1 (if prime),else 0

//********(G)***FUNCTIONS FOR FILE OPERATIONS*****************
void fwriteI(largeInt ,FILE *); // FOR WRITING ONE "largeInt" type NO. INTO THE FILE
largeInt freadI(FILE *); // FOR READING ONE "largeInt" 
largeInt increment1(largeInt );
//*******************************************************************************************************************************
//*****(A-1)*****
void readint(largeInt * ls)
{
	char ch;
	int i=0, n;
	ch= getchar();
	if(ch == '-')
		ls->sign = 1;
	else
	{
		ls->sign=0;		
		if(ch >= '0' && ch <='9')
			ls->line[i++] = ch;
		else
		{
			printf("non digit input\n");
			exit (1);
		}
	}

	while((ch=getchar()) != '\n')
	{
		if(ch >= '0' && ch <= '9')
			ls->line[i++] = ch;
		else
		{
			printf("nondigit inpu:\n");
			exit (1);
		}
	}
	ls->len = i;
}
//*****(A-2)*****
void showI(largeInt ls) 
{
	int i=0, j, k;
	k = ls.len;
	if(ls.sign)
		printf("-");
	for(i=0 ; i<k; i++)
		printf("%c",ls.line[i]);

}
//*****(A-3)*****		
void showN(largeNum ls) 
{
	int i=0, j, k;
	k = ls.len;
	if(ls.sign)
		printf("-");
	for(i=0 ; i<k; i++)
		printf("%d",ls.line[i]);

}
//*****(A-4)*****
void showDiv(div_result qr)
{
	if(qr.quot.len==0 && qr.rem.len==0)
	{
		printf("\nQuotient= N.A.");	
		printf("\nRemainder= N.A.");
	}
	else
	{
		printf("\nQuotient=");
		showN(qr.quot);
		printf("\nRemainder=");
		showN(qr.rem);
	}
}


		
//****************************************************************************************************************************
//*****(B-1)*****
void IntToNum(largeInt li, largeNum *ln)
{
	int i, j, k;
	ln->len = li.len;
	ln->sign = li.sign;
	for(i=0; i< li.len; i++)
		ln->line[i] = li.line[i]- '0';
}
//*****(B-2)*****
void NumToInt(largeNum ln,largeInt *li)
{
	int i, j, k;
	li->len = ln.len;
	li->sign = ln.sign;
	for(i=0; i< li->len; i++)
		li->line[i] = ln.line[i] + '0';
}

//****************************************************************************************************************************
//*****(C-1)*****
void shift(largeNum *a,int n)
{
	int i,j;
	if(n>=0) // for +ve n , Right shift occurs,and n zeros are added to the left.
	{
		for(i=1;i<=n;i++)
		{
			j=a->len;
			while(j)
			{
				a->line[j]=a->line[j-1];
				j--;
			}
			a->line[j]=0;
			a->len++;
		}
	}
	else // for -ve n , Left shift occurs
	{
		for(i=1;i<=fabs(n);i++)
		{
			j=0;
			while(j!=a->len-1)
			{
				a->line[j]=a->line[j+1];
				j++;
			}
			a->len--;
		}
	}
	
}
//*****(C-2)*****
void append_n_zeros_right(largeNum * a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{	
		a->line[(a->len)]=0;
		a->len++;
	}
}
//*****(C-3)*****
void remove_one_zero_right(largeNum * a)
{
	if(a->line[(a->len)-1]==0)
		a->len--;
}
//*****(C-4)*****
void rem_all_zeros_from_left(largeNum *a1)
{
	int i,k;
	k=a1->len;
	for(i=0;i<k;i++)
	{
		if(a1->line[0]==0)
			shift(a1,-1);
		else
			break;
	}
}


//****************************************************************************************************************************
//*****(D-1-a)*****
int greaterthan(largeInt ia1,largeInt ia2)// returns 1,if ( abs(ia1)>=abs(ia2) ); else 0,if( (abs(ia1)< abs(ia2) ) 
{
	int i;	
	largeNum a1,a2;

	IntToNum(ia1,&a1);
	IntToNum(ia2,&a2);

	rem_all_zeros_from_left(&a1);
	rem_all_zeros_from_left(&a2);

	if(a1.sign==1 && a2.sign==0)
		return 0;
	if(a1.len>a2.len)
		return 1;
	else if(a1.len<a2.len)
		return 0;
	else
	{
		for(i=0;i<a1.len;i++)
		{
			if(a1.line[i]>a2.line[i])
				return 1;
			else if(a1.line[i]<a2.line[i])
				return 0;
			else
				continue;
		}
		return 1;
	}
}
//***********(D-1-b)**************
int Ngreaterthan(largeNum a1,largeNum a2)// returns 1,if ( abs(a1)>=abs(a2) ); else 0,if( (abs(a1)< abs(a2) ) 
{
	int i;	
	rem_all_zeros_from_left(&a1);
	rem_all_zeros_from_left(&a2);
	if(a1.sign==1 && a2.sign==0)
		return 0;
	if(a1.len>a2.len)
		return 1;
	else if(a1.len<a2.len)
		return 0;
	else
	{
		for(i=0;i<a1.len;i++)
		{
			if(a1.line[i]>a2.line[i])
				return 1;
			else if(a1.line[i]<a2.line[i])
				return 0;
			else
				continue;
		}
		return 1;
	}
}

//*****(D-2)*****
int equal_to_zero(largeInt ia1)  // returns 1 ,if a1=0, otherwise returns 0;
{
	int i,chk;
	for(i=0;i<ia1.len;i++)
	{
		if(ia1.line[i]!='0')
		{
			return 0;
			break;
		}
	}
	return 1;
}
//*********(D-2-b)************
int Nequal_to_zero(largeNum a1)  // returns 1 ,if a1=0, otherwise returns 0;
{
	int i,chk;
	for(i=0;i<a1.len;i++)
	{
		if(a1.line[i])
		{
			return 0;
			break;
		}
	}
	return 1;
}		
//*****(D-3)*****		
int chk_equal(largeInt a1,largeInt a2)// returns 1,if equal
{
	int i;
	largeNum temp1,temp2;
	IntToNum(a1,&temp1);
	IntToNum(a2,&temp2);	
	rem_all_zeros_from_left(&temp1);
	rem_all_zeros_from_left(&temp2);
	if( (temp1.sign!=temp2.sign) || (temp1.len!=temp2.len) )
	{
		return 0;
	}
	else
	{
		for(i=0;i<temp1.len;i++)
		{
			if(temp1.line[i]!=temp2.line[i])
			{
				return 0;
				//break;
			}
		}
		return 1;
	}
				
		
}

//****************************************************************************************************************************
//*****(E-1)*****
largeNum add_pos(largeNum a1, largeNum a2) // For adding two +ve numbers only
{
	int carry_o,carry_n=0,i,d,k;
	largeNum result;
	if(a1.len<a2.len)
	{
		d=a2.len-a1.len;
		shift(&a1,d);
	}
	else
	{
		d=a1.len-a2.len;
		shift(&a2,d);
	}
	shift(&a1,1);
	shift(&a2,1);
	
	k=a1.len-1;	
	for(i=k;i>=0;i--)
	{
		carry_o=carry_n;
		result.line[i]=(a1.line[i]+a2.line[i]+carry_o)%10;
		carry_n=(a1.line[i]+a2.line[i]+carry_o)/10;
	}
	result.sign=0;
	result.len=a1.len;
	if(result.line[0]==0)
		shift(&result,-1);
	return(result);
	
}
//*****(E-2)*****	
largeNum add_n_times(largeNum a,int n)	// For adding +ve largeNum 'a' ,n times
{
	largeNum result=a;
	int i;	
	for(i=1;i<n;i++)
	{
		result=add_pos(result,a);
	}
	return result;
}
//*****(E-3)*****
div_result divs(largeNum dividend,largeNum divisor)  //  Required for DIVISION
{
	largeNum zero,one,dividendN,divisorN;
	int k,count=0,i,p,r,q[SIZE];
	div_result result;
	zero.sign=0;                            //initialize largeNum zero=0 and one=1
	zero.len=1;
	zero.line[0]=0;
	one.sign=0;
	one.len=1;
	one.line[0]=1;
	//result.quot=zero;

	if(Ngreaterthan(dividend,divisor)==0)    //stopping condition for recursive call to divs
	{
			//div_result dv;
			result.quot=zero;
			result.rem=dividend;
			return(result);
	}
	else
	{
		while(Ngreaterthan(dividend,divisor)==1)  //add zeroes to divisor until it is greater than dividend
		{
			append_n_zeros_right(&divisor,1);
			count++;                       //keeps track how many zeroes are appended at right of divisor
		}
		remove_one_zero_right(&divisor);
		count--;
		for(i=0;i<count+1;i++)
		{
			k=0;		
			while(1)
			{
				if(Ngreaterthan(dividend,divisor)==0)
					break;				
				dividend=Nsubl(dividend,divisor);
				k++;
			}
			q[i]=k;
			remove_one_zero_right(&divisor);
		}
		result.quot.len=count+1;
		for(i=0;i<result.quot.len;i++)
			result.quot.line[i]=q[i];
		result.quot.sign=0;
		result.rem=dividend;
		return(result);
	}
}


//****************************************************************************************************************************
//*****(F-1)
largeInt absl(largeInt a1) // For finding absolute value of a number
{
	if(a1.sign==1)
		a1.sign=0;
	return a1;
}
largeNum Nabsl(largeNum a1) // For finding absolute value of a number
{
	if(a1.sign==1)
		a1.sign=0;
	return a1;
}
//*****(F-2)
largeInt subl(largeInt ia1, largeInt ia2) // For substracting any +ve/-ve numbers
{
	int i,k,d;
	largeNum result,a1,a2;
	largeInt iresult;
	if(equal_to_zero(ia1) && equal_to_zero(ia2))
	{
		iresult.sign=0;
		iresult.len=1;
		iresult.line[0]='0';
		return(iresult);	
	}
	else
	{
		IntToNum(ia1,&a1);
		IntToNum(ia2,&a2);
		if(a1.sign==1 && a2.sign==0)
		{
			result=add_pos(a1,a2);
			result.sign=1;
			NumToInt(result,&iresult);
			return(iresult);
		}
		else if(a1.sign==0 && a2.sign==1)
		{
			result=add_pos(a1,a2);
			result.sign=0;
			NumToInt(result,&iresult);
			return(iresult);
		}
		else 
		{
				if(greaterthan(ia1,ia2)==1)		
		   		{		
			
					d=a1.len-a2.len;
					shift(&a2,d);
					k=a1.len-1;
					for(i=k;i>=0;i--)
					{
						if(a1.line[i]<a2.line[i])
						{
							result.line[i]=(a1.line[i]+10)-a2.line[i];
							a2.line[i-1]++;
						}
						else
						{
							result.line[i]=a1.line[i]-a2.line[i];
						}
					}
				
					result.len=a1.len;
					if(a1.sign==0&&a2.sign==0)
						result.sign=0;
					else
						result.sign=1;
					rem_all_zeros_from_left(&result);
					NumToInt(result,&iresult);
					if(equal_to_zero(iresult))
					{
						iresult.sign=0;
						iresult.len=1;
						iresult.line[0]='0';
					} 
					return(iresult);
				}
				else
				{
					d=a2.len-a1.len;
					shift(&a1,d);
					k=a2.len-1;
					for(i=k;i>=0;i--)
					{
						if(a2.line[i]<a1.line[i])
						{
							result.line[i]=(a2.line[i]+10)-a1.line[i];
							a1.line[i-1]++;
						}
						else
						{
							result.line[i]=a2.line[i]-a1.line[i];
						}
					}
					result.len=a2.len;
					if(a1.sign==0&&a2.sign==0)
						result.sign=1;
					else
						result.sign=0;
					rem_all_zeros_from_left(&result);
					NumToInt(result,&iresult);
					if(equal_to_zero(iresult))
					{
						iresult.sign=0;
						iresult.len=1;
						iresult.line[0]='0';
					} 
					return(iresult);
				}
		 	
		}
	}
}
largeNum Nsubl(largeNum a1, largeNum a2) // For substracting any +ve/-ve numbers
{
	int i,k,d;
	largeNum result;
	if(Nequal_to_zero(a1) && Nequal_to_zero(a2))
	{
		result.sign=0;
		result.len=1;
		result.line[0]=0;
		return(result);	
	}
	else
	{
		if(a1.sign==1 && a2.sign==0)
		{
			result=add_pos(a1,a2);
			result.sign=1;
			return(result);
		}
		else if(a1.sign==0 && a2.sign==1)
		{
			result=add_pos(a1,a2);
			result.sign=0;
			return(result);
		}
		else 
		{
				if(Ngreaterthan(a1,a2)==1)		
		   		{		
			
					d=a1.len-a2.len;
					shift(&a2,d);
					k=a1.len-1;
					for(i=k;i>=0;i--)
					{
						if(a1.line[i]<a2.line[i])
						{
							result.line[i]=(a1.line[i]+10)-a2.line[i];
							a2.line[i-1]++;
						}
						else
						{
							result.line[i]=a1.line[i]-a2.line[i];
						}
					}
				
					result.len=a1.len;
					if(a1.sign==0&&a2.sign==0)
						result.sign=0;
					else
						result.sign=1;
					return(result);
				}
				else
				{
					d=a2.len-a1.len;
					shift(&a1,d);
					k=a2.len-1;
					for(i=k;i>=0;i--)
					{
						if(a2.line[i]<a1.line[i])
						{
							result.line[i]=(a2.line[i]+10)-a1.line[i];
							a1.line[i-1]++;
						}
						else
						{
							result.line[i]=a2.line[i]-a1.line[i];
						}
					}
					result.len=a2.len;
					if(a1.sign==0&&a2.sign==0)
						result.sign=1;
					else
						result.sign=0;
					return(result);
				}
		 	
		}
	}
}

//*****(F-3)*****	
largeInt addl(largeInt ia1,largeInt ia2) // ADDITION
{
	largeInt iresult,ik1,ik2;
	largeNum result,a1,a2;	
	if(equal_to_zero(ia1) && equal_to_zero(ia2))
	{
		iresult.sign=0;
		iresult.len=1;
		iresult.line[0]='0';
		return(iresult);	
	}
	else
	{
		
		if( (ia1.sign==0 && ia2.sign==1) || (ia1.sign==1 && ia2.sign==0) )
		{
			ik1=absl(ia1);
			ik2=absl(ia2);
			iresult=subl(ik1,ik2);
			if(greaterthan(ik1,ik2)==1)
			{
			
				iresult.sign=ia1.sign;
			}
			else
			{
			
				iresult.sign=ia2.sign;
			}
		}
		else if(ia1.sign==1 && ia2.sign==1)
		{
			IntToNum(ia1,&a1);
			IntToNum(ia2,&a2);
			result=add_pos(a1,a2);
			NumToInt(result,&iresult);
			iresult.sign=1;
		}
		else
		{
			IntToNum(ia1,&a1);
			IntToNum(ia2,&a2);
			result=add_pos(a1,a2);
			NumToInt(result,&iresult);
		}
		if(equal_to_zero(iresult))
		{
			iresult.sign=0;
			iresult.len=1;
			iresult.line[0]='0';
		} 
		return iresult;
	}
}
		
//*****(F-4)*****
largeInt multl(largeInt ia1,largeInt ia2)// For multiplying any +ve/-ve numbers
{
	largeInt iresult;
	largeNum multiplicand,multiplier,result,temp,a1,a2;
	int k,i,j,n;
	if(equal_to_zero(ia1) || equal_to_zero(ia2))
	{
		iresult.sign=0;
		iresult.len=1;
		iresult.line[0]='0';
		return(iresult);	
	}
	else
	{
		IntToNum(ia1,&a1);
		IntToNum(ia2,&a2);
		if(Ngreaterthan(a1,a2)==1)
		{
			multiplicand=a1;
			multiplier=a2;
		}
		else
		{
			multiplicand=a2;
			multiplier=a1;
		}
		k=multiplier.len-1;
		for(i=k;i>=0;i--)
		{
			n=multiplier.line[i];
			if(i==k)            // multiplication for the left most term of multiplier
			{
				result=add_n_times(multiplicand,n);
			}
			else
			{
				temp=add_n_times(multiplicand,n);
				temp.len+=(k-i);  //decides number of zeroes to be appended
				for(j=1;j<=k-i;j++)
		    			temp.line[(temp.len)-j]=0;
	  	        	result=add_pos(result,temp);
			}
		}
		if((multiplicand.sign==0 && multiplier.sign==1) || (multiplicand.sign==1 && multiplier.sign==0))
			result.sign=1;
		else
			result.sign=0;
		NumToInt(result,&iresult);
		return iresult;
	}
}

//*****(F-4)*****
div_result divl(largeInt idividend,largeInt idivisor)  // DIVISION
{
	largeNum zero,one,dividend,divisor,dividendN,divisorN;	
	div_result result;
	int p,r;
	zero.sign=0;                            //initialize largeNum zero=0 and one=1
	zero.len=1;
	zero.line[0]=0;
	IntToNum(idividend,&dividend);
	IntToNum(idivisor,&divisor);
	if(Nequal_to_zero(divisor))
	{
		printf("\nERROR :: DIVIDE BY ZERO");
		return;
	}
	else if(Nequal_to_zero(dividend)==1)
	{
		result.quot=zero;
		result.rem=zero;
		return(result);
	}
	else
	{
		r=(dividend.sign==0)?0:1;
		p=(dividend.sign==divisor.sign)?0:1; 
		dividendN=Nabsl(dividend);                 //convert dividend and divider to positive
		divisorN=Nabsl(divisor);
		result=divs(dividendN,divisorN);
		result.quot.sign=p;
		result.rem.sign=r;
		if(Nequal_to_zero(result.rem)==1)
		{
			result.rem.len=1;
		}
		else
			rem_all_zeros_from_left(&(result.rem)); 
		return result;
	}
}
//*****(F-5)*****
largeInt modl(largeInt dividend,largeInt divisor) // MODULO OPEARATION
{
	largeInt irem;
	NumToInt(divl(dividend,divisor).rem,&irem);
	return(irem);
}
//*****************************************************************************************
//**********(G-1)*********************
void fwriteI(largeInt li,FILE *fp1)
{
	int i;	
	fp1=fopen("prime_tab.txt","a");
	if(fp1==NULL)
	{
		printf("\nCannot open file\n");
		return;
	}
	else
	{
		for(i=0;i<li.len;i++)		
			putc(li.line[i],fp1);		
		putc('\n',fp1);
	}
	fclose(fp1);
}
//**********(G-2)*********************
largeInt freadI(FILE *fp2) // reading largeint type no. from file and returning.
{
	int i=0;
	char ch;
	largeInt li;
	while(ch=getc(fp2))
	{	
		if(ch=='\n' || ch==EOF)
			break;	
		li.line[i++]=ch;
	}
	li.sign=0;
	li.len=i;
	return li;
	
}
//**********(G-3)*********************
largeInt increment1(largeInt li)// increment1 the largeInt type No. by one.
{
	largeInt one;
	one.sign=0;
	one.len=1;
	one.line[0]='1';
	li=addl(li,one);
	return(li);
}
//**********(G-4)*********************
largeInt add_primes(largeInt min,largeInt max) //store all prime no.s ranging (>min && <=max) and return last prime no. added to the file
{
	//largeNum nmin,nmax,ntemp,nptemp;
	largeInt itemp,iptemp,irem,lprime,zero;
	div_result temp_result;
	fp=fopen("prime_tab.txt","r+");
	zero.sign=0;
	zero.len=1;
	zero.line[0]='0';

	lprime=zero;
	
	iptemp=increment1(min);
	
	printf("\n");
	while(greaterthan(max,iptemp)==1)
	{
		rewind(fp);
		itemp=freadI(fp);
		
		while(!feof(fp))
		{
			temp_result=divl(iptemp,itemp);
			if(Nequal_to_zero(temp_result.rem)==1)
			{
				break;
			}
			itemp=freadI(fp);
			if(feof(fp)==1)
			{
				fwriteI(iptemp,fp);
				lprime=iptemp;
			}
		}
		iptemp=increment1(iptemp);
	}
	return(lprime);
	
}
//**********(G-5)*********************
int Isprime(largeInt li) // return 1 (if prime),else 0
{
	largeInt temp,temp1,temp_f;	
	int i;	
	
	if(li.sign==1)
	{
		return 0;
	}
	else
	{
		fp=fopen("prime_tab.txt","r+");
		if(fp==NULL)
		{
			printf("\nCannot open file\n");
			return;
		}
		else
		{
			temp=freadI(fp);
			while(feof(fp)==0)
			{
				
				
				temp_f=temp;
				if(chk_equal(temp_f,li)==1)
				{
					return 1;
				}
				if(greaterthan(li,temp_f)==0)
				{
					return 0;
				}
				temp=freadI(fp);	
			}
			temp1=add_primes(temp_f,li);// returns last prime no. which it added to the file prime_tab.txt
			if(chk_equal(temp1,li)==1)
				return 1;
			else
				return 0;
		}
	}
}

int main(void)
{
	largeInt l1, l2,l3,sum,diff,product;
	largeNum n1, n2,sumn;
	div_result divi;
	int x,prime_n1,prime_n2;
	printf("Enter 1st number:");
	readint(&l1);
	
	printf("\n");
	printf("Enter 2nd number:");
	readint(&l2);
	printf("\nThe 1st number is :\n");
	showI(l1);
	printf("\nThe 2nd number is :\n");
	showI(l2);
	printf("\n");
	
//	printf("chk_equal=%d",chk_equal(l1,l2));
//	printf("\n");

	
//	showI(increment1(l1));
	
//	fwriteI(l3);

//	printf("\nequal zero: %d",equal_to_zero(n1));

//	shift(&n1,3);
//	showN(n1);
//	shift(&n1,-2);
//	showN(n1); 

//	printf("\nAfter removing all zeroes from left;"); 	
//	rem_all_zeros_from_left(&n1);
//	showN(n1);	
	
//	x=equal_to_zero(l1);
//	printf("\n Value of x: %d\n",x);

//	x=greaterthan(l1,l2);
//	printf("\n Value of x: %d\n",x);
	
	sum=addl(l1,l2); // Addition..
	printf("\n\nSum=");
	showI(sum);
	
//	sumn=add_n_times(n1,2);
//	printf("\nSUM_N=");
//	showN(sumn);
	
	diff=subl(l1,l2);
	printf("\n\nDifference=");
	showI(diff);
	
	product=multl(l1,l2);
	printf("\n\nproduct=");
	showI(product);
	
	printf("\n\n");

//	append_n_zeros_right(&n1,2);
//	showN(n1);
//	remove_one_zero_right(&n1);
//	printf("\n");
//	showN(n1);

	divi=divl(l1,l2);
	showDiv(divi);
	
	printf("\nmodulus of 1st and 2nd number:");
	showI(modl(l1,l2));
	
	x=Isprime(l1);
	if(x==1)
		printf("\nPRIME");
	else
		printf("\nNOT PRIME\n");
	
	return 0;
}	







