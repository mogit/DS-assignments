/***********************************************************************************************
 ** Authors: Ayush Mittal (11183), Mohit Sharma (11434)                                       **
 **                                                                                           **
 ** What this code does : This program takes a number n as input from the user and outputs n  **
 ** factorial.                                                                                **
 ** The value of n should be less than 1000. However code can be modified and can also be run **
 ** for larger values of n user just only need to the increse the size of the arrays used to  **
 ** be able to do so.                                                                         **
 ***********************************************************************************************/


#include<stdio.h>
#include<string.h>

int length;	// Global variable used to store the value of the length of the factorial calculated at each step.

// This function is used to multiply to numbers one given as char array other as normal int and returns int * to int array storing the result.
long long int * multiply(char * a, int b)
{
	char num[10000];
	int i,j,k;
	long long int fact[10000];		//Stores the factorial at any given stage.
	i=0;
	
	// Converting integer number to the string form.
	while(b!=0)
	{
		num[i]=b%10+'0';
		b=b/10;
		i++;		
	}
	num[i]='\0';
	long long int carry=0; 			//Stores carry at a particular stage.


	// This for loop multiplies the two numbers the previous factorial and the next number.
	for(i=0;i<=strlen(a)+strlen(num)-2;i++)
	{
		fact[i]=carry;			//make ith entry of factorial equal to carry
		for(j=0;j<=i;j++)
		{
			int k=i-j;
			if(k<strlen(num)&&j<strlen(a))
			{
				fact[i]+=((a[j]-'0')*(num[k]-'0'));
			}
		}
		carry=fact[i]/10;		// Calculate the carry.
		fact[i]=fact[i]%10;
	}

	// Encorporating final carry in to the factorial.
	if(carry>0)
	{
		while(carry!=0)
		{
			fact[i]=carry%10;
			carry=carry/10;
			i++;
		}
	}
	length = i;  // The final number of digits in the factorial.
	return(fact);// fact stores number in reverse form		
}

int main()
{
	char fact[100000]={'1','\0'};	//Initialize factorial to one
	int n,i,j;			//n stores the number and i,j are the index variables.
	long long int *c;		// To store the output from the multiplication function.
	printf("Enter the numbers\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		c=multiply(fact,i);	// Calling the multiplication function.
		for(j=0;j<length;j++)
		{
			fact[j]=c[j]+'0';
		}
		fact[j]='\0';
	}
	// Printing the result.
	for(i=strlen(fact)-1;i>=0;i--)
		printf("%c",fact[i]);	
}
