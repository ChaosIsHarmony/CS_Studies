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
*	Write a program that reads in a sequence of integers and prints both the
*	integer that appears in a longest consecutive run and the length of that run. For
*	example, if the input is 1 2 2 1 5 1 1 7 7 7 7 1 1, then your program should
*	print Longest run: 4 consecutive 7s.
*	<add 2 simplifying assumptions: 1.) range [0-9]; 2.) -1 is terminal sentinel value>
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
		// ex_1_5_3n4();

		// Longest run
		ex_1_5_5();
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

	/*
	 * Simplifying assumptions:
	 * 		1.) integers are 0-9
	 *		2.) -1 is the terminating sentinel value
	 *
	 * Could use a priority queue to solve without those assumptions
	 */
	private static void ex_1_5_5()
	{
		// pq_version(); return;

		// Other Version
		if (!sc.hasNext())	{ System.out.println("No Input."); return; }
		
		// Initialize
		int[] records = new int[10];
		int next, prev = -1, curr_run = 0;

		while ((next = sc.nextInt()) >= 0)
		{
			if (next == prev)	{ curr_run++; records[prev] = (curr_run > records[prev]) ? curr_run : records[prev];}
			else 				{ curr_run = 1; }
			
			prev = next;
		}

		// Find largest
		int largest = 0, run_len = 0;
		for (int i = 0; i < records.length; i++)
			if (records[i] > records[largest])	largest = i;
		run_len = records[largest];

		System.out.println(run_len + " consecutive " + largest + "s");
	}

	private static void pq_version()
	{
		MaxPQ pq = new MaxPQ();
		int num = sc.nextInt();
		int next = num;
		int run = 0;
		while(sc.hasNext())
		{
			next = sc.nextInt();
			if (next == num) 	{ run++; }
			else 				{ pq.add(new int[]{num, run}); num = next; run = 1; }  
		}
	}

	// Only keep top three?
	private class MaxPQ
	{
		private Node max;

		private class Node { Node left, right; int[] num_n_run; }

		public MaxPQ() {}

		public void add(int[] num_n_run) {}
		public int[] getMax() { return max.num_n_run; }
		
		private void sink() {}
		private void swim() {}
	}
}