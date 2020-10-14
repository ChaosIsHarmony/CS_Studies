/*************************************************
*	All use Scanner instead of Command Line arguments
*
*	Ex 2.1.1
*	Write a static method max3() that takes three int arguments and returns
*	the value of the largest one. Add an overloaded function that does the same thing
*	with three double values.
*	
*	Ex 2.1.2
*	Write a static method odd() that takes three boolean arguments and returns
*	true if an odd number of the argument values are true , and false otherwise.
*	
*	Ex 2.1.3
*	Write a static method majority() that takes three boolean arguments and
*	returns true if at least two of the argument values are true, and false otherwise.
*	Do not use an if statement.
*	
*	Ex 2.1.4
*	Write a static method eq() that takes two int arrays as arguments and returns true
*	if the arrays have the same length and all corresponding pairs of of elements are equal,
*	and false otherwise.
*	
*	Ex 2.1.5
*	Write a static method areTriangular() that takes three double arguments
*	and returns true if they could be the sides of a triangle (none of them is greater
*	than or equal to the sum of the other two).
*	
*	Ex 2.1.6
*	Write a static method sigmoid() that takes a double argument x and returns the double 
*	value obtained from the formula 1 / (1 + e^-x ).
*	
*	Ex 2.1.7
*	Write a static method sqrt() that takes a double argument and returns the
*	square root of that number. Use Newton’s method (see Program 1.3.6) to compute
*	the result.
*	
*	Ex 2.1.9
*	Write a static method lg() that takes a double argument n and returns the
*	base-2 logarithm of n . You may use Java’s Math library.
*	
*	Ex 2.1.10
*	Write a static method lg() that takes an int argument n and returns the
*	largest integer not larger than the base-2 logarithm of n . Do not use the Math library.
* 	
*	Ex 2.1.11
*	Write a static method signum() that takes an int argument n and returns
*	-1 if n is less than 0, 0 if n is equal to 0, and +1 if n is greater than 0.
*
*	Ex 2.1.12
* 	Consider the static method duplicate() below.
*
*		public static String duplicate(String s)
*		{
*			String t = s + s;
*			return t;
*		}
*		
*	What does the following code fragment do?
*		
*		String s = "Hello";
*		s = duplicate(s);
*		String t = "Bye";
*		t = duplicate(duplicate(duplicate(t)));
*		StdOut.println(s + t);
*
*	Ex 2.1.14
*	The following checksum formula is widely used by banks and credit card
*	companies to validate legal account numbers:
*		
*		d_0 + f(d_1 ) + d_2 + f(d_3 ) + d_4 + f(d_5 ) + ... = 0 (mod 10)
*
*	The d_i are the decimal digits of the account number and f(d) is the sum of the
*	decimal digits of 2*d (for example, f(7) = 5 because 2 * 7 = 14 and 1 + 4 = 5). For
*	example, 17,327 is valid because 1 + 5 + 3 + 4 + 7 = 20, which is a multiple of
*	10. Implement the function f and write a program to take a 10-digit integer as a
*	command-line argument and print a valid 11-digit number with the given integer
*	as its first 10 digits and the checksum as the last digit.
*
*	Ex 2.1.16
*	Write a static method scale() that takes a double array as its argument
*	and has the side effect of scaling the array so that each element is between 0 and
*	1 (by subtracting the minimum value from each element and then dividing each
*	element by the difference between the minimum and maximum values). Use the
*	max() method defined in the table in the text, and write and use a matching min()
*	method.
*
*	Ex 2.1.17
*	Write a static method reverse() that takes an array of strings as its argument and 
*	returns a new array with the strings in reverse order. (Do not change the
*	order of the strings in the argument array.) Write a static method reverseInplace()
*	that takes an array of strings as its argument and produces the side effect of reversing 
*	the order of the strings in the argument array.
*
*	Ex 2.1.21
*	Write a static method multiply() that takes two square matrices of the
*	same dimension as arguments and produces their product (another square matrix
*	of that same dimension). Extra credit: Make your program work whenever the
*	number of columns in the first matrix is equal to the number of rows in the second
*	matrix.
*
*	Ex 2.1.22
*	Write a static method any() that takes a boolean array as its argument
*	and returns true if any of the elements in the array is true, and false otherwise.
*	Write a static method all() that takes an array of boolean values as its argument
*	and returns true if all of the elements in the array are true, and false otherwise.
*
*************************************************/
import java.util.Scanner;

public class Ex2_1
{
	static Scanner sc;
	
	public static void main(String[] args)
	{
		sc = new Scanner(System.in);
		
		// ???
		ex_2_1_1();
	}

	private static void ex_2_1_1()
	{

    }
}
