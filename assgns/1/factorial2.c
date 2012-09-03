#include<stdio.h>
int main()
{
	long long int n,fact[100000]={1},i,j,carry,k,l;
	printf("Enter the number\n");
	scanf("%lld",&n);	
	carry=0;
	for(i=1,j=0,l=0;i<=n;i++)
	{
		for(k=0;k<=j;k++)
		{
			l=((fact[k]*i)+carry)/1000000000;
			fact[k]=((fact[k]*i)+carry)%1000000000;
			//printf("%lldf,",fact[k]);			
			carry=l;			
			if(k==j&&carry>0)
			{
				fact[k+1]=carry;
				carry=0;
				k++;
				j++;
			}				

		}
	}
	for(i=j;i>=0;i--)
	{
		if(fact[i]==0)
			printf("00000000");
		printf("%lld",fact[i]);
	}	
}