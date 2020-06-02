/*************************************************
*
*	Ex 1.2.2
*	theta = args[0]
*	sin(theta)^2+cos(theta)^2 = 1
*
*	Ex 1.2.5
*	XOR
*
*	Ex 1.2.7
*	Auto conversion from int to string for printing
*
*	Ex 1.2.9
*	printing chars
*
*	Ex 1.2.10
*	int overflow
*
*	Ex 1.2.11
*	double
*
*	Ex 1.2.13
*	floating point imprecision
*
*	Ex 1.2.14
*	x = args[1], y = args[2]
*	Write a program that takes two positive integers as command-line
*	arguments and prints true if either evenly divides the other.
*
*	Ex 1.2.15
*	sides[0] = args[3], sides[1] = args[4], sides[2] = args[5], 
*	Write a program that takes three positive integers as command-line
*	arguments and prints false if any one of them is greater than or 
*	equal to the sum of the other two and true otherwise.
*
*	Ex 1.2.16
*	operator precedence
*	unexpected results when using
*		double force = G * mass1 * mass2 / r * r;
*	to calculate force
*
*	Ex 1.2.18
*	Write a program that takes two integer command-line
*	arguments x and y and prints the Euclidean distance
*	from the point (x, y) to the origin (0, 0).
*
*************************************************/


public class Ex1_2
{
	public static void main(String[] args)
	{
		System.out.println("Ex 1.2.2");
		double theta = Double.parseDouble(args[0]);
		System.out.println(Math.sin(theta)*Math.sin(theta)+Math.cos(theta)*Math.cos(theta));
		
		// XOR operator for booleans
		System.out.println("\nEx 1.2.5");
		System.out.println(true ^ true);
		System.out.println(false ^ true);
		System.out.println(true ^ false);
		System.out.println(false ^ false);
		
		//auto conversion from int to String
		System.out.println("\nEx 1.2.7");
		System.out.println(2 + "bc");		//2bc
		System.out.println(2 + 3 + "bc");	//5bc
		System.out.println((2+3) + "bc");	//5bc
		System.out.println("bc" + (2+3));	//bc5
		System.out.println("bc" + 2 + 3);	//bc23
		
		//char
		System.out.println("\nEx 1.2.9");
		System.out.println('b'); 				//b
		System.out.println('b' + 'c');			//197
		System.out.println((char) ('a' + 4));	//e

		//int overflow
		System.out.println("\nEx 1.2.10");
		int i = 2147483647;
		System.out.println(i);		//2147483647
		System.out.println(i+1);	//-2147483648
		System.out.println(2-i);	//-2147483645
		System.out.println(-2-i);	//2147483647
		System.out.println(2*i);	//-2
		System.out.println(4*i);	//-4

		//double
		System.out.println("\nEx 1.2.11");
		double d = 3.14159;
		System.out.println(d);				//3.14159
		System.out.println(d+1);			//4.14159
		System.out.println(8/(int) d);		//2
		System.out.println(8/d);			//2.5464812403910124
		System.out.println((int) (8/d));	//2

		//floating point imprecision
		System.out.println("\nEx 1.2.13");
		System.out.println(Math.sqrt(2) * Math.sqrt(2) == 2);	//false
		
		// input and test
		System.out.println("\nEx 1.2.14");
		int x = Integer.parseInt(args[1]);
		int y = Integer.parseInt(args[2]);
		if ((x%y == 0) || (y%x == 0))
			System.out.println(true);
		
		// input and test
		System.out.println("\nEx 1.2.15");
		int[] sides = {Integer.parseInt(args[3]),
					   Integer.parseInt(args[4]),
					   Integer.parseInt(args[5])};
		boolean is_triangle = true;
		for (int ind = 0; ind < 3; ind++)
			if ((sides[(ind+1)%3]+sides[(ind+2)%3])<sides[ind])
				is_triangle = false;
		System.out.println(is_triangle);
		
		// operator precedence
		System.out.println("\nEx 1.2.16");
		final double G = 9.18;
		double mass1 = 120.1;
		double mass2 = 120.2;
		double r = 10.5;
		System.out.println("wrong: " + (G * mass1 * mass2 / r * r));
		System.out.println("right: " + ((G * mass1 * mass2) / (r * r)));

		// dist from origin
		System.out.println("\nEx 1.2.18");
	}
}

