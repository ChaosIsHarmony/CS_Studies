/*************************************************
*	All use Scanner instead of Command Line arguments
*
*	Ex 1.5.1
*	Write a program that reads in integers (as many as the user enters) from
*	standard input and prints the maximum and minimum values.
*
*	Ex 1.5.2
*	Modify your program from the previous exercise to insist that the integers
*	must be positive (by prompting the user to enter positive integers whenever the
*	value entered is not positive).
*
*	Ex 1.5.3
*	Write a program that takes an integer command-line argument n, reads n
*	floating-point numbers from standard input, and prints their mean (average value)
*	and sample standard deviation (square root of the sum of the squares of their differences
*	from the average, divided by n-1).
*
*	Ex 1.5.4
*	Extend your program from the previous exercise to create a filter that reads n
*	floating-point numbers from standard input, and prints those that are further than
*	1.5 standard deviations from the mean.
*	
*	Ex 1.5.5
*	
*	Ex 1.5.6
*	
*	Ex 1.5.7
*	
*	Ex 1.5.10
*	
*	Ex 1.5.11
*	
*	Ex 1.5.14
*	
*
*************************************************/
import java.util.Scanner;

public class Ex1_5
{
	static Scanner sc;
	
	public static void main(String[] args)
	{
		sc = new Scanner(System.in);
		
		// Min-max
		//ex_1_5_1();
		
		// Min-max (positive only)
		//ex_1_5_2();
		
		// Mean and sample standard deviation & Filtering outliers
		ex_1_5_3n4();
	}

	private static void ex_1_5_1()
	{
		int max = Integer.MIN_VALUE;
		int min = Integer.MAX_VALUE;
		System.out.println("Sentinel value = 0");
		int num = sc.nextInt();
		while (num != 0)
		{
			max = (num > max) ? num : max;
			min = (num < min) ? num : min;
			num = sc.nextInt();
		}
		
		System.out.println("Max = " + max);
		System.out.println("Min = " + min);
    }
	
	private static void ex_1_5_2()
	{
		// Input
		int max = Integer.MIN_VALUE;
		int min = Integer.MAX_VALUE;
		System.out.println("Sentinel value = 0");
		while (true)
		{
			int num = sc.nextInt();
			if (num > 0)		{ max = (num > max) ? num : max; min = (num < min) ? num : min; }
			else if (num < 0)	{ System.out.println("Positive numbers only, Bobo."); }
			else				{ break; }		
		}
		
		// Output
		System.out.println("Max = " + max);
		System.out.println("Min = " + min);
    }
	
	private static void ex_1_5_3n4()
	{
		// Input
		int n = sc.nextInt();
		double[] nums = new double[n];
		double sum = 0;
		for (int i = 0; i < n; i++)
		{
			nums[i] = sc.nextDouble();
			sum += nums[i];
		}
		
		// Arithmetic mean
		double mean = sum/(double) n;
		System.out.println("Arithmetic mean = " + mean);
		
		// Sample standard deviation
		double variance = 0;
		for (int i = 0; i < n; i++)
			if (nums[i] > 0)	variance += Math.pow((nums[i]-mean),2);
		double std_dev = Math.sqrt(variance/(n-1));

		System.out.println("Sample standard deviation = " + std_dev);

		// Print outliers
		double z_score;
		for (int i = 0; i < n; i++)
		{
			z_score = (nums[i]-mean)/std_dev;
			if (Math.abs(z_score) >= 1.5)	System.out.println(nums[i]);
		}
	}
}