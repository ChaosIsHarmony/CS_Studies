/*************************************************
*	All use Scanner instead of Command Line arguments
*
*	Ex 1.3.1
*	Three inputs, print equal if all three are equal, not equal otherwise
*
*	Ex 1.3.2
*	Properly handled Quadratic formula
*
*	Ex 1.3.3
*	What (if anything) is wrong with each of the following statements?
*	a. if (a > b) then c = 0;		['then' keyword non-existent]
*	b. if a > b { c = 0; }			[no parethenses for if statement]
*	c. if (a > b) c = 0;			[fine]
*	d. if (a > b) c = 0 else b = 0;	[missing semicolon]
*
*	Ex 1.3.4
*	Testing range for doubles
*
*	Ex 1.3.5
*	Loaded die program 3/8 prob for 6, 1/8 for each 1-5
*
*	Ex 1.3.7
*	Suppose that i and j are both of type int. What is the value of j after each
*	of the following statements is executed?
*	a. for (i = 0, j = 0; i < 10; i++) j += i;		[j is 45]
*	b. for (i = 0, j = 1; i < 10; i++) j += j;		[j is 1024]
*	c. for (j = 0; j < 10; j++) j += j;				[j is 15]
*	d. for (i = 0, j = 0; i < 10; i++) j += j++;	[j is 0]
*
*	Ex 1.3.9
*	Write a program that, using one for loop and one if statement, prints the
*	integers from 1,000 to 2,000 with five integers per line. Hint: Use the % operation.
*	
*	Ex 1.3.10
*	Write a program that takes an integer command-line argument n, uses
*	Math.random() to print n uniform random values between 0 and 1, and then
*	prints their average value.
*
*	Ex 1.3.13
*	What are the values of m and n after executing the following code?
*
*	int n = 123456789;
*	int m = 0;
*	while (n != 0)
*	{
*		m = (10 * m) + (n % 10);
*		n = n / 10;
*	}
*
*	[m is 987654321 & n is 0]
*	
*	Ex 1.3.16
*	Write a program that takes an integer command-line argument n and
*	prints all the positive powers of 2 less than or equal to n. Make
*	sure that your program works properly for all values of n.
*
*************************************************/
import java.util.Scanner;

public class Ex1_3
{
	static Scanner sc;
	
	public static void main(String[] args)
	{
		sc = new Scanner(System.in);
		
		// Three inputs equivalent
		//ex_1_3_1();
		
		// Quadratic roots
		//ex_1_3_2();
		
		// Testing range for doubles
		//ex_1_3_4();
		
		// Loaded die
		//ex_1_3_5();
		
		// Ints from 1000-2000 @ 5/line
		//ex_1_3_9();
		
		// n uniform random values and their average
		//ex_1_3_10();
		
		// Powers of 2
		//ex_1_3_16();
	}

	private static void ex_1_3_1()
	{
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		
		if (a==b && b==c)	System.out.println("equal");
		else				System.out.println("not equal");
	}
	
	private static void ex_1_3_2()
	{
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		
		double[] roots = quad_roots(a,b,c);
		
		if (roots[0] != roots[1])	System.out.println("Roots are: " + roots[0] + " & " + roots[1]);
		else						System.out.println("Roots is: " + roots[0]);
	}
	
	private static double[] quad_roots(int a, int b, int c)
	{
		if (a == 0)		{System.out.println("Division by 0"); return new double[]{-1}; }
		
		int discr = b*b - 4*a*c;
		if (discr < 0)	{System.out.println("Non-real roots"); return new double[]{-1}; }
		
		return new double[]{(-b+Math.sqrt(discr))/(2*a), (-b-Math.sqrt(discr))/(2*a)};
	}
	
	private static void ex_1_3_4()
	{
		double a = sc.nextDouble();
		double b = sc.nextDouble();
		
		if ((a > 0 && a < 1) && (b > 0 && b < 1))	System.out.println(true);
		else										System.out.println(false);
	}
	
	private static void ex_1_3_5()
	{
		double chance = Math.random();
		
		System.out.println(chance);
		
		if (chance < (3.0/8))		System.out.println("6");
		else if (chance < (4.0/8))	System.out.println("5");
		else if (chance < (5.0/8))	System.out.println("4");
		else if (chance < (6.0/8))	System.out.println("3");
		else if (chance < (7.0/8))	System.out.println("2");
		else 						System.out.println("1");
	}
	
	private static void ex_1_3_9()
	{
		for (int i = 1000; i < 2001; i++)
		{
			if (i%5==0)	System.out.println();
			System.out.print(i + " ");
		}
	}
	
	private static void ex_1_3_10()
	{
		int n = sc.nextInt();
		double sum = 0.0;
		
		for (int i = 0; i < n; i++)
		{
			double new_rand = Math.random();
			System.out.println((i+1) + ".) " + new_rand);
			sum += new_rand;
		}
		
		System.out.println("Average: " + (sum/n));
	}
	
	private static void ex_1_3_16()
	{
		int n = sc.nextInt();

		if (n == 0)		{ System.out.println(1); }
		else if (n > 0)	{ int ans = 1; while(--n+1>0) System.out.println(ans*=2); }
		else			{ double ans = 1; while(++n-1<0) System.out.println(ans/=2); }
	}
}



