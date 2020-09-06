/**
 * MazeLoader.java
 *
 * Loads a generated maze
 *
 * @EC
 * @09-2020
 * For AP CS A
 */
package utils;
 
import java.util.Scanner;
import java.io.File;

public class MazeLoader
{
	private Scanner sc;
	
	public MazeLoader(String filename)
	{
		String filepath = new File("").getAbsolutePath()+filename;
		try { 
			sc = new Scanner(new File(filepath));
			while(sc.hasNext())
			{
				// TODO change to return a copy of the maze
				System.out.println(sc.nextLine());
			}
		} catch (Exception e) { System.out.println(filepath + " not found"); }
	}
}