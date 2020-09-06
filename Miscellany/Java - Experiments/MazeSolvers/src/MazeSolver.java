/**
 * MazeSolver.java
 *
 * Uses either DFS or BFS to solve mazes
 * Takes one command line argument:
 *		ml = maze filepath to load
 * Or generates an r x c maze with ~x spaces cleared
 *
 * Use: java MazeSolver "\mazes\maze_20x20.txt"
 * @EC
 * @09-2020
 * For AP CS A
 */
import algos.*;
import utils.*;
 
public class MazeSolver
{
	public static void main(String[] args)
	{
		// load or generate map
		if (args[0].contains(".txt"))	{ MazeLoader ml = new MazeLoader(args[0]); }
		else							{ MazeGenerator mg = new MazeGenerator(args); }
		
		// run algo for path
		
		// display
	}
}