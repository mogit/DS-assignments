/****************************************************************************************************
 * Authors : Ayush Mittal (11183) , Mohit Sharma (11434)*********************************************
 **												   **
 **  What this program does : This program takes as input the two numbers n,m and output fn mod m  **
 **  where fn is the nth fibonacci number. It also inputs from the user the method that he wants   **
 **  to use for calculating the output and provides three choices to choose from i.e. iterative,   ** 
 **  recursive and matrix method.							           **
					
 **  It is important to note that recursive algorithm starts to die out around n=50 whereas        **
 **  iterative one works well for n upto 9 to 10 digits. The third method works for n having upto  **
 **  15 digits. Here working well implies giving output within few seconds.			   **
 ****************************************************************************************************/


#include<stdio.h>


//   This is the function for recursive algorithm.
long long int fib_rec(long long int n,long long int m)
{

	// Defining the base case for the recursion.
        if(n==0)
                return(0);
        else
        if(n==1)
                return(1);


        else
        {
                long long int fn_1=fib_rec(n-1,m);	// Recursively calculating the answer
                long long int fn_2=fib_rec(n-2,m);
               
		// Calculating mod m at each step so that large value of fibonacci number does'nt create problems. 
		if(fn_1+fn_2>=m)
                        return((fn_1+fn_2)%m);
                else
                        return(fn_1+fn_2);
        }
}

//   This is the function for iterative algorithm.
long long int fib_ite(long long int n, long long int m)
{
	long long int i,fn_1mod_m=0,fn_mod_m=1,temp;
	for(i=2;i<=n;i++)
	{
		temp=fn_mod_m;
		fn_mod_m=fn_mod_m+fn_1mod_m;
		fn_1mod_m=temp;

		// Calculating mod m at each step so that large value of fibonacci number does'nt create problems.
		if(fn_mod_m>=m)
		{
			fn_mod_m=fn_mod_m%m;
		}
	}
	return(fn_mod_m);
}

//    This is the code for matrix multiplication.
long long int *mat_mult(long long int *a,long long int *b,long long int m)
{
	long long int a_mult_b[4];

	// Simply calculating the multiplication of the two given matrices as the size of the matrices is already known.
        a_mult_b[0]=a[0]*b[0]+a[1]*b[2];
        a_mult_b[1]=a[0]*b[1]+a[1]*b[3];
        a_mult_b[2]=a[2]*b[0]+a[3]*b[2];
        a_mult_b[3]=a[2]*b[1]+a[3]*b[3];
        int i;

	// Taking mod m at every step so that large value of fibonacci doesnt creates any problem.
        for(i=0;i<4;i++)
        {
                if(a_mult_b[i]>=m)
                        a_mult_b[i]=a_mult_b[i]%m;
        }
        return(a_mult_b); 
}


//    This function calculates the required matrix for getting the output.
long long int *fib_mat_power(long long int n,long long int m)
{
	int i;
	long long int a[4]={1,1,1,0};
	if(n==1)
		return(a);
	if(n%2==0)					//Case when n is even.
	{
		long long int *b,c[4];			//b and c are used to store the matrices obtained after recursion or multiplication.
		b=fib_mat_power(n/2,m);			//Recursive call
		for(i=0;i<4;i++)			//This for loop is just used to properly keep the track of the matrix.
			c[i]=b[i];
		b=mat_mult(c,c,m);			//Squaring recursively obtained matrix to get the resultant matrix.
		for(i=0;i<4;i++)			//This for loop is just used to properly keep the track of the matrix.
			c[i]=b[i];
		return(c);				//Return the resultant matrix.
	}
	if(n%2!=0)					//Case when n is odd.
	{
		long long int *b,*c,d[4],e[4];		//b,c,d and e are used to store and properly keep the track of matrices 
							//obtained after recursion and multiplication.
		b=fib_mat_power(n/2,m);			//Recursive call.
		for(i=0;i<4;i++)
			d[i]=b[i];
		c=fib_mat_power(n/2+1,m);		//Recursive call.
		for(i=0;i<4;i++)
			e[i]=c[i];
		b=mat_mult(d,e,m);			//Multiplying two matrices obtained after recursive calls.
		for(i=0;i<4;i++)
			d[i]=b[i];
		return(d);				//Return the result.
	}
}
//    Here is the main function.
int main()
{

	long long int m,n,a,*b;
	int i;

	while(1)
	
	{

		// GUIDING MENU to help the user.
		printf("********** Fibonacci number mod n **********\n");
		printf("This program calculates the mod of nth fibonacci \nnumber with m for given m and n using different algorithms.\n");
		printf("GUIDING MENU:\n");
		printf("1) Enter 1 for using recursive algorithm\n");
		printf("2) Enter 2 for using iterative algorithm\n");
		printf("3) Enter 3 for using the matrix based algorithm\n");
		printf("4) Enter 0 to exit\n");
		scanf("%d",&i);
		
		//Exit condition.
		if(i==0)
                	return(0);		
		else 
		//Error check.
		if(i!=1&&i!=2&&i!=3)
		{
                        printf("ERROR : Please enter the options as shown in guiding menu only\n");
                        continue;
                }

		//Take the input.
		printf("Enter the two numbers first the one that for fibonacci number second to take mod from\n");
		scanf("%lld%lld",&n,&m);

		if(i==1)
			a=fib_rec(n,m);
		else
		if(i==2)
			a=fib_ite(n,m);
		else
		if(i==3)
		{
			b=fib_mat_power(n-1,m);
			if(n==2&&m==1)
				a=0;
			else
				a=b[0];

		}
	
		printf("The output is %lld\n",a);


	}
}
