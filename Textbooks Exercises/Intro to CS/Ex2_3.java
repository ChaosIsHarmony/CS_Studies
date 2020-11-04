/*************************************************
*	All use Scanner instead of Command Line arguments
*
*	Ex 2.3.1
*	What happens if you call factorial() with a negative value of n?
*	With a large value of, say, 35?
*		- if n < 0, then it goes into an inifinite loop and ends in stackoverflow
*		- if n is large, then long overflow; if n > 65, then 0, until it reaches 39525
*
*	Ex 2.3.3
*	Give the sequence of integers printed by a call to ex233(6):
*		public static void ex233(int n)
*		{
*			if (n <= 0) return;
*			StdOut.println(n);
*			ex233(n-2);
*			ex233(n-3);
*			StdOut.println(n);
*		}
*
*	Ex 2.3.4
*
*	Ex 2.3.8
*
*	Ex 2.3.15
*
*	Ex 2.3.17
*
*	Ex 2.3.18
*
*	Ex 2.3.21
*
*
*************************************************/
import java.util.Scanner;

public class Ex2_3
{
	static Scanner sc;
	
	public static void main(String[] args)
	{
		sc = new Scanner(System.in);
		
		// factorial
		//ex_2_3_1();

		// recursion trace
		ex_2_3_3();
	}

	private static void ex_2_3_1()
	{
		// negative
		//System.out.println(factorial(-3));
		// large
		for (int i = 60; i < 1000000000; i++)
			System.out.println(i + ": " + factorial(i));
	}

	public static long factorial(int n)
	{
		if (n == 1)	return 1;
		return n * factorial(n-1);
	}

	public static void ex_2_3_3()
	{
		ex233(6);
	}

	public static void ex233(int n)
	{
		if (n <= 0) return;
		System.out.println(n);
		ex233(n-2);
		ex233(n-3);
		System.out.println(n);
	}

}
