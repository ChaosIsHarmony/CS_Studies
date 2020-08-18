/*************************************************
*	All use Scanner instead of Command Line arguments
*
*	Ex 1.4.1
*	Write a program that declares, creates, and initializes an array a[] of length
*   1000 and accesses a[1000] . Does your program compile? What happens when you
*   run it?
*   
*   Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: Index 1000 out of bounds for length 1000
*	at Ex1_4.ex_1_4_1(Ex1_4.java:60)
*   at Ex1_4.main(Ex1_4.java:54)
*
*	Ex 1.4.2
*	Describe and explain what happens when you try to compile a program with
*   the following statement:
*
*       int n = 1000;
*       int[] a = new int[n*n*n*n];
*
*   Exception in thread "main" java.lang.NegativeArraySizeException: -727379968
*	at Ex1_4.ex_1_4_2(Ex1_4.java:76)
*	at Ex1_4.main(Ex1_4.java:64)
*
*	Ex 1.4.3
*	Given two vectors of length n that are represented with one-dimensional
*   arrays, write a code fragment that computes the Euclidean distance between them
*   (the square root of the sums of the squares of the differences between corresponding elements).
*
*	Ex 1.4.4
*	Write a code fragment that reverses the order of the values in a one-dimensional
*   string array. Do not create another array to hold the result. Hint : Use
*   the code in the text for exchanging the values of two elements.
*
*	Ex 1.4.5
*	What is wrong with the following code fragment?
*
*       int[] a;
*       for (int i = 0; i < 10; i++)
*       a[i] = i * i;
*
*   Memory is never declared for array a.
*
*	Ex 1.4.6
*	Write a code fragment that prints the contents of a two-dimensional boolean array,
*   using * to represent true and a space to represent false . Include row and column indices.
*
*	Ex 1.4.7
*   What does the following code fragment print?
*
*       int[] a = new int[10];
*       for (int i = 0; i < 10; i++)
*           a[i] = 9 - i;
*       for (int i = 0; i < 10; i++)
*           a[i] = a[a[i]];
*       for (int i = 0; i < 10; i++)
*           System.out.println(a[i]);
*
*   Halfway through, half of the array has already been overwritten...	
*
*	Ex 1.4.8
*	
*
*	Ex 1.4.9
*	
*
*	Ex 1.4.10
*	
*
*	Ex 1.4.12
*	
*
*	Ex 1.4.14
*	
*
*************************************************/
import java.util.Scanner;

public class Ex1_4
{
	static Scanner sc;
	
	public static void main(String[] args)
	{
		sc = new Scanner(System.in);
		
		// Array index out of bounds error
		//ex_1_4_1();

        // Integer overflow
        //ex_1_4_2();

        // Euclidean distance
        //ex_1_4_3();

        // In-place reversal of array order
        //ex_1_4_4();

        // Print out boolean array
        //ex_1_4_6();

        // Mirror array
        ex_1_4_7();
	}

	private static void ex_1_4_1()
	{
        int[] a = new int[1000];
        a[1000] = 10;
	}

    private static void ex_1_4_2()
    {
        int n = 1000;
        int[] a = new int[n*n*n*n];
    }

    private static void ex_1_4_3()
    {
        int[] n_1 = {sc.nextInt(), sc.nextInt()};
        int[] n_2 = {sc.nextInt(), sc.nextInt()};

        // compute the distance
        int x = Math.abs(n_1[0]-n_2[0]);
        int y = Math.abs(n_1[1]-n_2[1]);

        double dist = Math.sqrt(x*x+y*y);
        
        System.out.println(dist);
    }

    private static void ex_1_4_4()
    {
        int len = sc.nextInt();
        int[] array = new int[len];
        for (int i = 0; i < len; i++)
            array[i] = sc.nextInt();

        for (int ind = 0; ind < len/2; ind++)
        {
            int tmp = array[ind];
            array[ind] = array[len-ind-1];
            array[len-ind-1] = tmp;
        }
        
        for (int i : array)
            System.out.print(i + " ");
    }

    private static void ex_1_4_6()
    {
        boolean[][] array = {{true,false},{false,true}};

        for (int i = 0; i < array.length; i++)
        {
            for (int j = 0; j < array[0].length; j++)
                System.out.print(array[i][j] ? "*" : " ");
            System.out.println();
        }
    }

    private static void ex_1_4_7()
    {
        int[] a = new int[10];
        for (int i = 0; i < 10; i++)
            a[i] = 9 - i;
        for (int i = 0; i < 10; i++)
            a[i] = a[a[i]];
        for (int i = 0; i < 10; i++)
            System.out.println(a[i]);
    }
}